// 约瑟夫生者死者游戏
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    // data;
    int data;
    Node *next;

    // operation
    Node();
    Node(const int data) { this->data = data; }
};

class CircularList
{
private:
    Node *start;
    int listSize;

public:
    CircularList(int num);
    ~CircularList();
};

CircularList::CircularList(int num)
{
    start = new Node(1);
    listSize = num;
    Node *p = start;
    for (int i = 2; i <= num; i++)
    {
        Node *temp = new Node(i);
        p->next = temp;
        p = temp;
    }
    p->next = start;
}

CircularList::~CircularList()
{
    Node *p = start->next, *q;
    while (p != start)
    {
        q = p->next;
        delete p;
        p = q;
    }
    delete start;
}

class JosephusSolution
{
private:
    CircularList* clist;
    
public:
    JosephusSolution();
    ~JosephusSolution();
};

JosephusSolution::JosephusSolution(int num)
{
    if (num == 1)
    {
    }
    
}

JosephusSolution::~JosephusSolution()
{
}


bool input(int &data, const string cueStr)
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

int main()
{
    int N, S, M, K; // 分别代表总人数，起始序号，死亡数字，剩余人数
    cout << "现有N个人围成一圈，从第S人开始依次报数，报M的人出局，再由下一个人报数，如此循环，直到最后剩下K个人为止" << endl;
    if (input(N, "生死游戏的总人数") && input(N, "游戏开始的位置") && input(N, "死亡数字") && input(N, "剩余的生者人数"))
    {
        char choose;
        switch (choose)
        {
        case:'1'
            cout << "采用循环链表模拟" << endl;
            JosephusSolution sol(1);
            break;
        case:'2'
            cout << "采用有序集合模拟" << endl;
            JosephusSolution sol(2);
            break;
        case:'3'
            cout << "采用递推公式计算" << endl;
            JosephusSolution sol(3);
            break;
        default:
            break;
        }
    }

    return 0;
}