// 307. 区域和检索 - 数组可修改
// 线段树，下标从0开始
class NumArray {
private:
  int size;
  vector<int> tree;
  inline void biuldtree(int k, int l, int r, vector<int> &nums) {
    if (l == r) {
      tree[k] = nums[l];
      return;
    }
    int m = (l + r) >> 1;
    biuldtree(k + k + 1, l, m, nums);
    biuldtree(k + k + 2, m + 1, r, nums);
    tree[k] = tree[k + k + 1] + tree[k + k + 2];
  }

  inline void add(int k, int l, int r, int x, int y) {
    if (l == r) {
      tree[k] = y;
      return;
    }
    int m = (l + r) >> 1;
    if (x <= m) {
      add(k + k + 1, l, m, x, y);
    } else {
      add(k + k + 2, m + 1, r, x, y);
    }
    tree[k] = tree[k + k + 1] + tree[k + k + 2];
  }

  inline int calc(int k, int l, int r, int s, int t) {
    if (l == s && r == t) {
      return tree[k];
    }
    int m = (l + r) >> 1;
    if (m >= t) {
      return calc(k + k + 1, l, m, s, t);
    } else {
      if (m < s) {
        return calc(k + k + 2, m + 1, r, s, t);
      } else {
        return calc(k + k + 1, l, m, s, m) +
               calc(k + k + 2, m + 1, r, m + 1, t);
      }
    }
  }

public:
  NumArray(vector<int> &nums) {
    size = nums.size();
    for (int i = 0; i < 4 * size + 1; i++) {
      tree.push_back(0);
    }
    biuldtree(0, 0, size - 1, nums);
  }

  void update(int index, int val) {
    add(0, 0, size - 1, index, val);
    return;
  }

  int sumRange(int left, int right) {
    return calc(0, 0, size - 1, left, right);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */