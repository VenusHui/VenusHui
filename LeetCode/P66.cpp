// 66. 加一
// 模拟
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int size = digits.size();
        digits.at(size - 1)++;
        int i = size - 1;
        while (digits.at(i) == 10)
        {
            digits.at(i) = 0;
            i--;
            if (i < 0)
            {
                digits.insert(digits.begin(), 1);
                break;
            }
            else
            {
                digits.at(i)++;
            }
        }
        return digits;
    }
};