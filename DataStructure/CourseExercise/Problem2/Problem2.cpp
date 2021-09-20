// 约瑟夫生者死者游戏
#include <iostream>
#include <string>
using namespace std;

class ChainNode
{
public:
    // data;
    int data;
    ChainNode *next;

    // operation
    ChainNode();
    ChainNode(const int data) { this->data = data; }
    ChainNode(const int data, ChainNode *next)
    {
        this->data = data;
        this->next = next;
    }
};

class CircularList
{
private:
    ChainNode *firstNode;
    int listSize;

public:
    CircularList(int num);
    ~CircularList();
    int size() { return listSize; }
    ChainNode* getFirstNode() { return firstNode; }
    bool deleteElem();
    bool insertElem();
};

CircularList::CircularList(int num)
{
    firstNode = new ChainNode;
    firstNode->next = firstNode;
    listSize = 0;
    ChainNode *rNode = new ChainNode(*firstNode);
    for (int i = 1; i <= num; i++)
    {
        ChainNode *temp = new ChainNode;
        temp->data = i;
        rNode->next = temp;
        rNode = temp->next;
        listSize++;
    }
    delete rNode;
}

CircularList::~CircularList()
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

void josephus(CircularList &list, int totalNum, int startNum, int deathNum, int surplusNum)
{
    int count = 1;
    while (surplusNum < list.size())
    {
        if (count == deathNum)
        {
            list.deleteElem();
        }
        
        count++;
    }
    return;
}

int main()
{
    int N, S, M, K; // 分别代表总人数，起始序号，死亡数字，剩余人数
    cout << "现有N个人围成一圈，从第S人开始依次报数，报M的人出局，再由下一个人报数，如此循环，直到最后剩下K个人为止" << endl;
    if (input(N, "生死游戏的总人数") && input(S, "游戏开始的位置") && input(M, "死亡数字") && input(K, "剩余的生者人数"))
    {
        CircularList cList(N);
        josephus(cList, N, S, M, K);
    }

    return 0;
}