// 146. LRU 缓存
struct DLinkedNode {
  int key;
  int value;
  DLinkedNode *prev;
  DLinkedNode *next;
  DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
  DLinkedNode(int _key, int _value)
      : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
  DLinkedNode *head;
  DLinkedNode *tail;
  unordered_map<int, DLinkedNode *> mp;
  int size;
  int capacity;
  void removeNode(DLinkedNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  void addToHead(DLinkedNode *node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }
  DLinkedNode *removeTail() {
    DLinkedNode *node = tail->prev;
    removeNode(node);
    return node;
  }

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
        DLinkedNode *reNode = removeTail();
        mp.erase(reNode->key);
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