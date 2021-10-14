// 8种排序算法
#include <iostream>
#include <ctime>
using namespace std;

const int N = 1e5;

class SortFunctions
{
private:
    int *num;
    clock start, finish;
    double duration;
public:
    SortFunctions();
    ~SortFunctions();
    void bubbleSort();
    void selectSort();
    void insertSort();
    void shellSort();
    void quickSort();
    void heapSort();
};

SortFunctions::SortFunctions()
{
    srand((unsigned)time(0));
    duration = 0;
    num = new int[N];
    cout << "**             排序算法比较            **" << endl;
    cout << "=========================================" << endl;
    cout << "**            1 --- 冒泡排序           **" << endl;
    cout << "**            2 --- 选择排序           **" << endl;
    cout << "**            3 --- 直接插入排序       **" << endl;
    cout << "**            4 --- 希尔排序           **" << endl;
    cout << "**            5 --- 快速排序           **" << endl;
    cout << "**            6 --- 堆排序             **" << endl;
    cout << "**            7 --- 归并排序           **" << endl;
    cout << "**            8 --- 基数排序           **" << endl;
    cout << "**            9 --- 退出程序           **" << endl;
    cout << "=========================================" << endl;
}

SortFunctions::~SortFunctions()
{
    delete[] num;
}

void bubbleSort()
{
    for (int i = 0; i < N; i++)
    {
        num[i] = rand();
    }
    start = clock();
    int tmp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
        }
    }
    finish = clock;
}

int main()
{
    SortFunctions solution;
    bool loop = true;
    char oper;
    while (loop)
    {
        
    }

    return 0;
}