// 2288. 价格减免
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string ans;
        int size = sentence.size(), tmp = 0;
        function<void(int, int)> calc = [&] (int l, int r) {
            if (l == r) {
                ans += sentence[l];
                return;
            }
            bool flag = true;
            if (sentence[l] != '$') {
                flag = false;
            }
            for (int i = l + 1; i <= r; i++) {
                if (!(sentence[i] >= '0' && sentence[i] <= '9')) {
                    flag = false;
                }               
            }
            if (flag) {            
                double price = 0, dotpos = 0.1;
                bool dot = false;
                for (int i = l + 1; i <= r; i++) {
                    if (sentence[i] == '.') {
                        dot = true;
                        continue;
                    }
                    if (!dot) {
                        price = price * 10 + (sentence[i] - '0');
                    }
                    else {
                        price = price + dotpos * (sentence[i] - '0');
                        dotpos /= 10;
                    }
                }
                price = price * (100 - discount) / 100;
                price = price + 0.005;
                ans += '$';
                string ss = to_string(price);
                for (int i = 0; i < ss.size(); i++) {
                    ans += ss[i];
                    if (ss[i] == '.') {
                        for (int j = i + 1; j < i + 3; j++) {
                            ans += ss[j];
                        }
                        break;
                    }
                }
            }
            else {
                for (int i = l; i <= r; i++) {
                    ans += sentence[i];
                }
            }
        };
        for (int i = 0; i < size; i++) {
            if (sentence[i] == ' ') {
                calc(tmp, i - 1);
                tmp = i + 1;
                ans += " ";
            }
            else if (i == size - 1) {
                calc(tmp, i);
            }
        }
        return ans;
    }
};