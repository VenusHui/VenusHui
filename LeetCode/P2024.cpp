// 2024. 考试的最大困扰度
// 滑动窗口
class Solution {
public:
    int calc(string& s, int k, char ch) {
        int size = s.size();
        int ans = 0;
        for (int l = 0, r = 0, sum = 0; r < size; r++) {
            sum += s[r] != ch;
            while (sum > k) {
                sum -= s[l] != ch;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string s, int k) {
        return max(calc(s, k, 'T'), calc(s, k, 'F'));
    }
};

// 动态规划
class Solution {
public:
    int calc(string& s, int k, char ch) {
        int size = s.size();
        if (k >= size) {
            return size;
        }
        int ans = 0, num = 0;
        vector<int> dp;
        for (int i = 0; i < size; i++) {
            if (s[i] == ch) {
                dp.push_back(i);
                num++;
            }
            if (num > k) {
                ans = max(ans, i - dp[num - k - 1]);
            }
            else {
                ans = i + 1;
            }
        }
        return ans;
    }
    int maxConsecutiveAnswers(string s, int k) {
        return max(calc(s, k, 'T'), calc(s, k, 'F'));
    }
};