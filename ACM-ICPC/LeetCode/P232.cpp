// 232. 用栈实现队列
class MyQueue {
private:
  stack<int> stk_left, stk_right;

public:
  MyQueue() {}

  void push(int x) { stk_right.push(x); }

  int pop() {
    int ans = peek();
    stk_left.pop();
    return ans;
  }

  int peek() {
    if (stk_left.empty()) {
      while (!stk_right.empty()) {
        stk_left.push(stk_right.top());
        stk_right.pop();
      }
    }
    return stk_left.top();
  }

  bool empty() { return stk_left.empty() && stk_right.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */