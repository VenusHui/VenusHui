// 705. 设计哈希集合
class MyHashSet {
private:
  vector<vector<int>> res;
  const int base = 999971;
  int hash(int key) { return key % base; }

public:
  MyHashSet() {
    vector<int> tmp;
    tmp.clear();
    for (int i = 0; i < base; i++)
      res.push_back(tmp);
  }

  void add(int key) {
    int h = hash(key);
    for (auto it = res[h].begin(); it != res[h].end(); it++) {
      if ((*it) == key) {
        return;
      }
    }
    res[h].push_back(key);
  }

  void remove(int key) {
    int h = hash(key);
    for (auto it = res[h].begin(); it != res[h].end(); it++) {
      if ((*it) == key) {
        res[h].erase(it);
        return;
      }
    }
  }

  bool contains(int key) {
    int h = hash(key);
    for (auto it = res[h].begin(); it != res[h].end(); it++) {
      if ((*it) == key) {
        return true;
      }
    }
    return false;
  }
};