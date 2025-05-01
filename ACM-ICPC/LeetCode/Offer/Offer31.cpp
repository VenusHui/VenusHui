// 剑指 Offer II 031. 最近最少使用缓存
class LRUCache {
private:
  struct DLinkedNode {
    int key;
    int value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value)
        : key(_key), value(_value), prev(nullptr), next(nullptr) {}
  };
  void removeNode(DLinkedNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  void addToHead(DLinkedNode *node) {
    node->next = head->next;
    node->prev = head;
    head->next = node;
    node->next->prev = node;
  }
  int size;
  int capacity;
  DLinkedNode *head;
  DLinkedNode *tail;
  unordered_map<int, DLinkedNode *> mp;

public:
  LRUCache(int capacity) {
    size = 0;
    this->capacity = capacity;
    head = new DLinkedNode();
    tail = new DLinkedNode();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (!mp.count(key))
      return -1;
    DLinkedNode *node = mp[key];
    removeNode(node);
    addToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    if (!mp.count(key)) {
      DLinkedNode *node = new DLinkedNode(key, value);
      mp[key] = node;
      addToHead(node);
      size++;
      if (size > capacity) {
        DLinkedNode *reNode = tail->prev;
        mp.erase(reNode->key);
        removeNode(reNode);
        delete reNode;
        size--;
      }
    } else {
      DLinkedNode *node = mp[key];
      node->value = value;
      removeNode(node);
      addToHead(node);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */