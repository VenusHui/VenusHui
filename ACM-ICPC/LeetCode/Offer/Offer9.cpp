// 剑指 Offer 09. 用两个栈实现队列
class CQueue {
private:
  stack<int> left, right;

public:
  CQueue() {}

  void appendTail(int value) { right.push(value); }

  int deleteHead() {
    if (left.empty()) {
      while (!right.empty()) {
        int tmp = right.top();
        right.pop();
        left.push(tmp);
      }
    }
    if (!left.empty()) {
      int ans = left.top();
      left.pop();
      return ans;
    }
    return -1;
  }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */