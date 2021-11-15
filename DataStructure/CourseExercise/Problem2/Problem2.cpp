#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template <typename Type>
struct ListNode // 链表结点
{
    Type data;
    ListNode *next;
    ListNode() { this->next = nullptr; }
    ListNode(Type data)
    {
        this->next = nullptr;
        this->data = data;
    }
    ListNode(ListNode<Type> *node)
    {
        this->data = node->data;
        this->next = node->next;
    }
};

template <typename Type>
class CircularList // 循环链表
{
private:
    int listSize;

protected:
    ListNode<Type> *rear;

public:
    CircularList();
    ~CircularList();
    int size() { return listSize; }
    void remove(int index);
};

template <typename Type>
CircularList<Type>::CircularList()
{
    listSize = 0;
    rear = new ListNode<Type>;
    rear->next = rear; // 循环效果
}

template <typename Type>
CircularList<Type>::~CircularList()
{
    ListNode<Type> *prt, *pre = rear;
    while (rear->next != rear)
    {
        prt = pre->next;
        pre->next = prt->next;
        delete prt;
    }
    delete rear;
}

template <typename Type>
void CircularList<Type>::remove(int index)
{
    ListNode<Type>* prt = this->rear, *pre = nullptr;
    for (int i = 0; i < index; i++)
    {
        pre = prt;
        prt = prt->next;
    }
    pre->next = prt->next;
    delete prt;
    prt = pre->next;
}

class JosephusSolution : CircularList<int> // 约瑟夫生死环，继承自循环链表
{
private:
    int total, start, death, remain; // 总人数，起始序号，死亡数字，剩余人数

public:
    JosephusSolution();
    ~JosephusSolution();
    void print()
    {
        ListNode<int> *tmp = rear->next;
        while (tmp != rear)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
    bool Input(int &data, const string cueStr);
    void JosephusSimulate();
};

JosephusSolution::JosephusSolution()
{
    cout << "现有N个人围成一圈，从第S人开始依次报数，报M的人出局，再由下一个人报数，如此循环，直到最后剩下K个人为止" << endl;
    if (Input(total, "生死游戏的总人数") && Input(start, "游戏开始的位置") && Input(death, "死亡数字") && Input(remain, "剩余的生者人数"))
    {
        rear->data = 1;
        ListNode<int> *prt, *pre = rear; // 当前结点及记录了上一次插入的结点
        for (int i = 2; i <= total; i++)
        {
            prt = new ListNode<int>(i);
            pre->next = prt;
            prt->next = rear;
            pre = prt;
        }
    }
}

JosephusSolution::~JosephusSolution()
{
}

bool JosephusSolution::Input(int &data, const string cueStr)
{
    cout << "请输入" << cueStr << "：";
    cin >> data;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(65536, '\n');
        cout << "输入数据不合法，请检查后重新输入" << endl;
        return false;
    }
    return true;
}

void JosephusSolution::JosephusSimulate()
{
    ListNode<int> *prt = rear, *pre = nullptr;
    for (int i = 1; i < start; i++)
    {
        prt = rear->next;
    }
    int loop = total - remain;
    for (int i = 1; i <= loop; i++)
    {
        for (int j = 1; j < death; j++)
        {
            pre = prt;
            prt = prt->next;
        }
        pre->next = prt->next;
        cout << "第" << i << "个死者的位置是：" << prt->data << endl;
        delete prt;
        prt = pre->next;
    }
    cout << "最后剩下：" << remain << "人" << endl;
    cout << "剩余的生者位置为：" << endl;
    prt = rear;
    for (int i = 0; i < remain; i++)
    {
        cout << setw(5) << setfill(' ') << prt->data;
        prt = prt->next;
    }
    cout << endl;
}
int main()
{
    JosephusSolution testInstance;
    testInstance.JosephusSimulate();
    return 0;
}