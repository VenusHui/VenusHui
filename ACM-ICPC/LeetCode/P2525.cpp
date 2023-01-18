// 2525. 根据规则将箱子分类
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bflag = false, hflag = false;
        if (length >= 1e4 || width >= 1e4 || height >= 1e4 || 1LL * length * width * height >= 1e9) {
            bflag = true;
        }
        if (mass >= 100) {
            hflag = true;
        }
        if (bflag && hflag) {
            return "Both";
        }
        else if (!bflag && !hflag) {
            return "Neither";
        }
        else if (bflag && !hflag) {
            return "Bulky";
        }
        else {
            return "Heavy";
        }
    }
};