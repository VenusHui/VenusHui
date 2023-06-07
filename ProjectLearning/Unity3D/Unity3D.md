# Unity3D Learning

> Reference: [AcWing Unity3D 应用课](https://www.acwing.com/activity/content/2487/)

## 1. 编辑器

## 2. 组件

##### 组件的 `Update()` 和 `FixUpdate()` 函数

- `Update()` ：两次相邻的执行时间可能是不均匀的，受到函数计算时间的影响，所以一般不用于模拟物理轨迹，可以用来获取用户输入，判断游戏结束等
- `FixUpdate()` ：两次相邻的执行时间是均匀的，一般情况下每秒钟执行 50 次，通常用于模拟物理轨迹

`` `MoveRotation()`