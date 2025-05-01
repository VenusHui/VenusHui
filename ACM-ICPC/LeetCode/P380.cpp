// 380. O(1) 时间插入、删除和获取随机元素
class RandomizedSet {
private:
  vector<int> nums;
  unordered_map<int, int> indices;

public:
  RandomizedSet() { srand((unsigned)time(NULL)); }

  bool insert(int val) {
    if (indices.count(val)) {
      return false;
    }
    int index = nums.size();
    nums.emplace_back(val);
    indices[val] = index;
    return true;
  }

  bool remove(int val) {
    if (!indices.count(val)) {
      return false;
    }
    int index = indices[val];
    int last = nums.back();
    nums[index] = last;
    indices[last] = index;
    nums.pop_back();
    indices.erase(val);
    return true;
  }

  int getRandom() {
    int randomIndex = rand() % nums.size();
    return nums[randomIndex];
  }
};