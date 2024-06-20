## 题目分析及算法思想

本题是一道数学中经典的数独问题，给定一个大小为 `9 * 9` 的二维数组 `board` 让我们将其中没有填充数字的地方填充 `1 ~ 9` 的数字，保证每一行、每一列、每一个九宫格中没有重复的数字。

求解思路：

我们从二维数组的 `(0, 0)` 位置开始依次枚举每一个空白的格子在可以填入的数字，递归地向后寻找，如果此时发生冲突就向前回退，直到填到最后一个格子没有发生冲突时数独求解成功。

具体我们可以用 `bool` 型的两个二维数组和一个三维数组来记录当前每一行每一列以及每一个九宫格中 `1 ~ 9` 的数字有没有使用过：

```cpp
// row、col、sec分别表示每一行、每一列、每个九宫格中 1~9 的数字有没有被使用过
vector<vector<bool>> row(size, vector<bool>(size, false));
vector<vector<bool>> col(size, vector<bool>(size, false));
vector<vector<vector<bool>>> sec(3, vector<vector<bool>>(3, vector<bool>(size, false)));
```

然后对当前格子分别填入1 ~ 9中满足条件的数字，并递归下一个位置，核心代码如下：

```cpp
for (int i = 0; i < 9; i++) {
    // 若该数字在row、col、sec数组中都没有被使用过，则说明可以填
    if (!row[r][i] && !col[c][i] && !sec[r / 3][c / 3][i]) {
    // 填入数字并更新相应的row、col、sec数组
        board[r][c] = static_cast<char>('1' + i);
        row[r][i] = true;
        col[c][i] = true;
        sec[r / 3][c / 3][i] = true;

        if (dfs(r, c + 1)) {
            // 递归地求解下一个位置，如果下一个位置（从最后一个位置回溯
            // 上来）求解成功，说明本次填入的数可以作为可行解，返回true
            return true;
        }
        else {
            // 若下一个位置求解不成功，则说明本次填入不可行，将本次的填入操作回退
            board[r][c] = ' ';
            row[r][i] = false;
            col[c][i] = false;
            sec[r / 3][c / 3][i] = false;
        }
        // 去找下一个数尝试填入
    }
}
```

## 复杂度分析

#### 时间复杂度

由于本题的输入规模一定，考虑最坏的情况：需要对 $9 \times 9 = 81$ 个格子都遍历填入 $1 - 9$ 的数字，共有 $9 ^ {81}$ 中情况，时间复杂度为 $O(9 ^ {81}) = O(1)$

#### 空间复杂度

由于只用了三个常量大小的数组，空间复杂度为 $O(2 \times 9 \times 9 + 3 \times 3 \times 9) = O(1)$

### 运行截图

![ScreenShot](./Resources/ScreenShot.png)
