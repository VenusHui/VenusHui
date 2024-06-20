#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
typedef long long ll;
#define endl '\n'
using namespace std;

// 输入处理
void getInput(string input, vector<int> &coins, int &amount)
{
    int size = input.size();
    string coinsInput;  // 最终coins的数据部分
    string amountInput; // 最终amount的数据部分
    int i;              // 用于遍历整个inputs
    bool read = false;  // 用于记录是否应该进行读取

    // 处理coins
    for (i = 0; i < size; i++) {
        if (input.at(i) == ']') // 在']'处结束，并且if语句的顺序不可调换
            break;
        if (read)
            coinsInput += input.at(i);
        if (input.at(i) == '[') // 从'['开始向coins的数据部分添加数据
            read = true;
    }

    // 处理amount
    read = false;
    for (; i < size; i++) {
        if (read)
            amountInput += input.at(i);
        if (input.at(i) == '=') // 从'='开始向amount的数据部分添加数据
            read = true;
    }
    stringstream ss;
    ss.str(coinsInput); // 创建coins的数据流
    string item;
    char delim = ',';
    try {
        while (getline(ss, item, delim)) { // 每隔一个delim','进行一次处理
            coins.push_back(stoi(item)); // 将string转换为int存入coins
        }
        amount = stoi(amountInput);
    }
    catch (std::invalid_argument &) { // 捕获stoi的非法转换异常
        cout << "Invalid argument" << endl;
    }
    catch (std::out_of_range &) { // 捕获stoi的越界转换异常
        cout << "Out of range" << endl;
    }
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        if (line.empty()) // 检测到空行说明测试样例结束
            break;
        int amount;
        vector<int> coins;
        getInput(line, coins, amount); // 获取输入
        
        // 初始化 dp 数组，由于要求最小的硬币数量，所以初始化为 amount + 1
        vector<int> dp(amount + 1);    
        for (int i = 1; i <= amount; i++)
            dp[i] = amount + 1;
        int size = coins.size();
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < size; j++) {
                if (coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1); // 状态转移，具体转移方式参照文档
            }
        }
        if (dp[amount] > amount) // 若数组值仍为初始值，说明并没有方案能恰好得到 amount 的面值
            cout << "-1" << endl;
        else
            cout << dp[amount] << endl;
    }

    return 0;
}