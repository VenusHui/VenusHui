// 762. 二进制表示中质数个计算置位
class Solution {
public:
  int countPrimeSetBits(int left, int right) {
    vector<bool> prime(100, true);
    prime[0] = prime[1] = false;
    for (int i = 2; pow(i, 2) < 100; i++) {
      if (prime[i]) {
        for (int j = pow(i, 2); j <= 100; j += i) {
          prime[j] = false;
        }
      }
    }
    int ans = 0;
    for (int i = left; i <= right; i++) {
      int num = i, n = 0;
      while (num) {
        if (num % 2 == 1) {
          n++;
        }
        num /= 2;
      }
      if (prime[n]) {
        ans++;
      }
    }
    return ans;
  }
};