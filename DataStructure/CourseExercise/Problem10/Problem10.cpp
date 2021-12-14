// 8种排序算法
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <functional>
using namespace std;

const int FunctionNum = 8; // 8种排序方式

class SortFunctions
{
private:
    int* num, nNum;        // 待排序数组及其规模
    clock_t start, finish; // 排序的起止时间
    double duration;       // 共计用时
    int compCount;         // 排序所用的操作次数
    char oper;             // 用户选择的操作
    string* sortNames;     // 排序名称集合

public:
    SortFunctions();
    ~SortFunctions();

    // 获取用户选择的排序方式
    bool setOper();

    int getArrSize() { return nNum; }
    char getOper() { return oper; }
    double getDurTime() { return (static_cast<double>(finish) - static_cast<double>(start)) / CLOCKS_PER_SEC; }

    // 重置随机数
    void Reset();

    void swap(int& a, int& b);

    // 冒泡排序
    void BubbleSort();

    // 选择排序
    void SelectSort();

    // 插入排序
    void InsertSort();

    // 希尔排序
    void ShellSort();

    // 快速排序
    void QuickSort(int low, int high);

    // 堆排序
    void HeapSort(int n);

    // 归并排序
    void MergeSort(const int low, const int high);

    // 基数排序
    void RadixSort();

    // 输出排序的详细信息
    void PrintDetail();
};

SortFunctions::SortFunctions()
{
    oper = 0;
    srand((unsigned)time(0));
    start = finish = clock();
    duration = 0;
    compCount = 0;
    cout << "请输入要生成随机数的个数：";
    cin >> nNum;
    num = new int[nNum];
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
    sortNames = new string[FunctionNum + 1]{ "", "冒泡", "选择", "直接插入", "希尔", "快速", "堆", "归并", "基数" };
}

SortFunctions::~SortFunctions()
{
    delete[] num;
}

bool SortFunctions::setOper()
{
    cout << "请选择排序算法：";
    while (cin >> oper)
    {
        if (oper >= '0' && oper <= '9')
        {
            return true;
        }
    }
    return false;
}

void SortFunctions::Reset()
{
    compCount = 0;
    for (int i = 0; i < nNum; i++)
    {
        num[i] = rand() % nNum;
    }
    start = clock();
}

void SortFunctions::swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
    compCount++;
}

void SortFunctions::BubbleSort()
{
    for (int i = 0; i < nNum; i++)
    {
        bool flag = true;
        for (int j = 0; j < nNum - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                swap(num[j], num[j + 1]);
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

void SortFunctions::SelectSort()
{
    for (int i = 0; i < nNum - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < nNum; j++)
        {
            if (num[j] < num[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap(num[i], num[min]);
        }
    }
}

void SortFunctions::InsertSort()
{
    int tmp;
    for (int i = 1; i < nNum; i++)
    {
        tmp = num[i];
        int j = i;
        while (j > 0 && tmp < num[j - 1])
        {
            num[j] = num[j - 1];
            j--;
            compCount++;
        }
        if (j != i)
        {
            num[j] = tmp;
        }
    }
}

void SortFunctions::ShellSort()
{
    for (int gap = nNum / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < nNum; i++)
        {
            int tmp = num[i], j;
            for (j = i; j >= gap && num[j - gap] > tmp; j -= gap)
            {
                num[j] = num[j - gap];
                compCount++;
            }
            num[j - gap] = tmp;
        }
    }
}

void SortFunctions::QuickSort(int low, int high)
{
    function<int(int, int)> partition = [&](int begin, int end)
    {
        int pivot = num[end];
        int i = begin - 1;
        for (int j = begin; j <= end - 1; j++)
        {
            if (num[j] < pivot)
            {
                i++;
                swap(num[i], num[j]);
            }
        }
        swap(num[i + 1], num[end]);
        return i + 1;
    };
    if (low < high)
    {
        int pi = partition(low, high);
        this->QuickSort(low, pi - 1);
        this->QuickSort(pi + 1, high);
    }
}

void SortFunctions::HeapSort(int n)
{
    function<void(int, int)> heapify = [&](int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && num[left] > num[largest])
        {
            largest = left;
        }
        if (right < n && num[right] > num[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(num[i], num[largest]);
            heapify(n, largest);
        }
    };
    for (int i = nNum / 2 - 1; i >= 0; i--)
    {
        heapify(n, i);
    }
    for (int i = nNum - 1; i > 0; i--)
    {
        swap(num[0], num[i]);
        heapify(i, 0);
    }
}

void SortFunctions::MergeSort(const int low, const int high)
{
    function<void(const int, const int, const int)> Merge = [&](const int left, const int mid, const int right)
    {
        const int subArrayOne = mid - left + 1;
        const int subArrayTwo = right - mid;
        int* leftArray = new int[subArrayOne],
            * rightArray = new int[subArrayTwo];
        for (int i = 0; i < subArrayOne; i++)
            leftArray[i] = num[left + i];
        for (int j = 0; j < subArrayTwo; j++)
            rightArray[j] = num[mid + 1 + j];

        int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
        {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
            {
                num[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                num[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
            compCount++;
        }
        while (indexOfSubArrayOne < subArrayOne)
        {
            num[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
        while (indexOfSubArrayTwo < subArrayTwo)
        {
            num[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    };
    if (low >= high)
    {
        return;
    }
    const int midNum = low + (high - low) / 2;
    MergeSort(low, midNum);
    MergeSort(midNum + 1, high);
    Merge(low, midNum, high);
}

void SortFunctions::RadixSort()
{
    int mx = num[0];
    for (int i = 1; i < nNum; i++)
    {
        if (num[i] > mx)
        {
            mx = num[i];
        }
    }
    function<void(int)> CountSort = [&](int exp)
    {
        int* output = new int[nNum];
        int i, count[10] = { 0 };
        for (i = 0; i < nNum; i++)
        {
            count[(num[i] / exp) % 10]++;
        }
        for (i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        for (i = nNum - 1; i >= 0; i--)
        {
            output[count[(num[i] / exp) % 10] - 1] = num[i];
            count[(num[i] / exp) % 10]--;
        }
        for (i = 0; i < nNum; i++)
        {
            num[i] = output[i];
        }
        delete[] output;
    };
    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        CountSort(exp);
    }
}

void SortFunctions::PrintDetail()
{
    finish = clock();
    cout << sortNames[oper - '0'] << "排序所用时间" << setprecision(6) << (static_cast<double>(finish) - static_cast<double>(start)) / CLOCKS_PER_SEC << " s" << endl;
    cout << sortNames[oper - '0'] << "排序交换次数" << compCount << endl
        << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    SortFunctions testInstance;
    bool loop = true;
    while (loop && testInstance.setOper())
    {
        testInstance.Reset();
        switch (testInstance.getOper())
        {
            case '1':
                testInstance.BubbleSort();
                break;
            case '2':
                testInstance.SelectSort();
                break;
            case '3':
                testInstance.InsertSort();
                break;
            case '4':
                testInstance.ShellSort();
                break;
            case '5':
                testInstance.QuickSort(0, testInstance.getArrSize() - 1);
                break;
            case '6':
                testInstance.HeapSort(testInstance.getArrSize() - 1);
                break;
            case '7':
                testInstance.MergeSort(0, testInstance.getArrSize() - 1);
                break;
            case '8':
                testInstance.RadixSort();
                break;
            case '9':
                loop = false;
                break;
            default:
                break;
        }
        if (loop)
        {
            testInstance.PrintDetail();
        }
    }
    return 0;
}
