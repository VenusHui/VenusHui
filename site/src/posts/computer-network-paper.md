---
title: Ad-hoc On-Demand Distance Vector Routing
date: 2022-11-14
tags: [network, paper-reading]
series: paper-reading
summary: 同济大学软件学院2022-2023秋计算机网络实验论文阅读
lang: zh
---

> 论文：Charles E. Perkins, Elizabeth M. Royer. _Ad-hoc On-Demand Distance Vector Routing_（WMCSA '99）。
> 本文为个人论文阅读笔记，内容为原文的整理与个人理解，非全文翻译；规范化的 RFC 版本见 [RFC 3561](https://datatracker.ietf.org/doc/html/rfc3561)。

## 介绍

### 背景

小型设备特别是笔记本电脑的蓬勃发展以及设备使用自带电池的特性使得无限的便携性需求激增

事实上这种可以随时设置的ad-hoc network最早可以追溯到DARPA时期，后来有了免许可的无线通信设备，对于ad-hoc network的研究就迫在眉睫。互联网工程任务组IETF也成立了Manet工作组在尽量不使用移动ip及其前身的情况家为ad-hoc network开发一个解决方案框架。

DSDV`Destination-Sequenced Distance Vector`算法作为DVR`Distance Vector Routing`算法的变种用于解决这一问题，但这是一个暴力方法，正确性依靠将连接信息定期广告和全球播报，而频繁的进行上述平方级复杂度的操作限制了使用DSDV的ad-hoc网络的规模；此外，DSDV需要每个节点维护网络中与其他所有节点的完整路由列表，虽然这种方式能够降低获取到数据包的延迟，但这显然超出了大多数单一节点的需求。

首先为了降低系统复杂度，路由必须是按需创建的，并且必须限制用于获取路由的时间避免临时节点的用户传输信息前经历不可接受的长时间等待，同时也要最大限度减少广播和建设新路由的传输延迟，AODV应运而生。

## 协议细节

- 基本原则：按需获取路由

  对于不在有效路径上的节点，并不维护其路由信息，也不参与定期的路由表交换，一个节点只有需要与另一个节点通信，或是作为两个节点的中转站时才去维护其他节点的信息。

- 通过`hello message`的本地广播等技术来使移动节点了解邻域的其他节点

  - 只在必要的时候广播discovery packets
  - 区分邻域检测和一般的拓扑结构维护
  - 只向那些需要本地连接改变信息的邻域节点传递该信息

- AODV与DSR同样使用路由发现机制`route discovery mechanism`

  RREQ`Route Request packet`寻找路由，RREP`Route Reply packet`建立路径，不同的是：AODV依靠在中间节点动态地建立路由表项，而不是源路由，这样显著减少了传输过程中每个数据包所携带的路由信息；同时为了保证路由信息为最新，每一个ad-hoc节点维护一个单调增长的序列号计数器作为目的地序列号。这样降低了控制和数据传输的网络负载，对网络结构变化的反应迅速，并且确保没有环路。

### 路径发现`Path Discovery`

每个节点都维护着两个独立的计数器：节点序列号`sequence number`以及广播ID`broadcast_id`源节点需要与另一个节点通信时，由于源节点没有目标节点的路由信息，所以需要通过向其相邻节点广播一个RREQ包来启动路径发现程序，该RREQ包含以下字段：

```text
< source_addr, source_sequence#, broadcast_id, dest_addr, dest_sequence#, hop_cnt >
```

其中每一对`source_addr, broadcast_id`确定唯一确定一个RREQ，每当源节点发出新的RREQ时，`broadcast_id`自增。每个节点在接收到RREQ时，如果能发出相应的RREP满足该RREQ则路径发现过程结束，否则将该RREQ增加`hop_cnt`跳数后将其广播到自己的邻域节点，同时跟踪后续信息以设置前向路径和反向路径，若某一节点收到了具有相同`source_addr, broadcast_id`的RREQ，则将其丢弃。

#### 反向路径设置

RREQ中`source_sequence#`以及`dest_sequence#`两个序列号维护了源路由信息的失效时间以及源节点已知的最后一个目的地节点的反向路径的失效时间。当RREQ从源节点到达其他节点时，会自动建立从该节点返回源节点的方向路径信息存入路由表，这些信息需要存在足够长的时间以便源节点最终能收到回复。

#### 前进路径设置

当RREQ到达一个拥有目标节点路由的节点，该节点首先检查RREQ是否时通过双向连接收到的：即通过比较自己路由条目中目标节点序列号以及RREQ中携带的目标节点序列号，确定该路由是否是最新的：

- 如果RREQ中目的地序列号大于该节点记录的序列号，则该节点不得使用其记录的目标节点路由来响应RREQ，需要 重新广这一条RREQ。

- 若RREQ中目的地序列号小于等于该节点记录的序列号，并且该RREQ之前没有被处理过，那么该节点则会向其收到RREQ的节点方向单独传播一个RREP，该RREP需要包含以下字段：

```text
< source_addr, dest_addr, dest_sequence#, hop_cnt, lifetime >
```

该RREP通过之前RREQ设置的反向路径回到源节点，并在途中更新所有中间节点对源节点和目标节点的路由信息，记录目标节点最新的`dest_sequence#`。其他被RREQ设置了反向路径的节点会在`ACTIVE_ROUTE_TIMEOUT`即3000毫秒后删除之前设置的反向路径。

若一个节点收到了多个RREP，只有当后来收到的RREP比前一个RREP的`dest_sequence#`更大，或者`dest_sequence#`相同但`hop_cnt`更小的时候，该节点会重新传播这个后来收到的RREP。这样不仅减少了向源节点传播RREP的数量，同时也确保了最新和最快速的路由信息。源节点在收到第一个RREP之后就可以进行数据传输，如果后续收到了更好的RREP就可以随时更新路由信息。

### 路由表管理

除了`source_sequence#`以及`dest_sequence#`两个序列号之外，路由表中其他信息被称作软状态`soft state`

- 路由请求过期计时器 `route request expiration timer` ：用于删除不在RREP路径上节点的反向路径信息

每个路由表条目包含的信息：

- 目的地 `Destination`
- 下一跳的地址 `Next Hop`
- 跳数 `Number of hops`
- 目的地序列号 `Sequence Number of the destination`
- 该路线活跃的邻域节点 `Active neighbors of the route`
- 路由表项的过期时间 `expiration time for the route entry`
