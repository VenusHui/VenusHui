// 2502. 设计内存分配器
class Allocator {
private:
  int n;
  vector<int> mem;

public:
  Allocator(int n) {
    this->n = n;
    mem = vector<int>(n, -1);
  }

  int allocate(int size, int mID) {
    int len = 0, tmp = 0;
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (mem[i] == -1) {
        tmp++;
      }
      if (tmp >= size || mem[i] != -1 || i == n - 1 && mem[i] == -1) {
        len = max(len, tmp);
        if (len >= size) {
          ans = i - len + 1;
          for (int j = 0; j < size; j++) {
            mem[ans + j] = mID;
          }
          break;
        }
        tmp = 0;
      }
    }
    return ans;
  }

  int free(int mID) {
    int ans = 0;
    for (auto &i : mem) {
      if (i == mID) {
        i = -1;
        ans++;
      }
    }
    return ans;
  }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */