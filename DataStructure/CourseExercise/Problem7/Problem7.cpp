#include <iostream>
#include <string>
#include <cmath>
#include <functional>
using namespace std;

template <typename Type>
struct StackNode
{
    Type val;
    StackNode *next;
    StackNode() : next(nullptr) {}
    StackNode(Type x) : val(x), next(nullptr) {}
    StackNode(StackNode<Type> *rNode) : val(rNode->val), next(rNode->next) {}
};

template <typename Type>
class Stack
{
protected:
    StackNode<Type> *topPtr;

public:
    Stack();
    ~Stack();

    // 判断栈是否已满
    bool empty() { return topPtr == nullptr; }

    // 入栈操作
    void push(Type elem);

    // 出栈操作
    void pop();

    // 获取栈顶
    Type &top();
};

template <typename Type>
Stack<Type>::Stack()
{
    topPtr = nullptr;
}

template <typename Type>
Stack<Type>::~Stack()
{
    StackNode<Type> *tmp = topPtr;
    while (topPtr != nullptr)
    {
        tmp = topPtr->next;
        delete topPtr;
        topPtr = tmp;
    }
}

template <typename Type>
void Stack<Type>::push(Type elem)
{
    StackNode<Type> *newNode = new StackNode<Type>(elem); // 创建新结点
    newNode->next = topPtr;                               // 将新结点链接到栈顶
    topPtr = newNode;                                     // 更新栈顶指针
}

template <typename Type>
void Stack<Type>::pop()
{
    if (empty())
    {
        return;
    }
    StackNode<Type> *tmp = topPtr; // 暂存栈顶指针
    topPtr = topPtr->next;         // 更新栈顶指针
    delete tmp;                    // 根据暂存的指针删除原栈顶元素
}

template <typename Type>
Type &Stack<Type>::top()
{
    if (empty())
    {
        throw "Stack Empty, top() Error";
    }
    return topPtr->val;
}

template <typename Type>
struct BiTreeNode
{
    Type val;
    BiTreeNode *left;
    BiTreeNode *right;
    BiTreeNode() : left(nullptr), right(nullptr) {}
    BiTreeNode(Type x) : val(x), left(nullptr), right(nullptr) {}
    BiTreeNode(Type x, BiTreeNode *left, BiTreeNode *right) : val(x), left(left), right(right) {}
    ostream &operator<<(ostream &out)
    {

        return out;
    }
};

template <typename Type>
class BiTree
{
protected:
    BiTreeNode<Type> *root;

public:
    BiTree();
    ~BiTree();
    void preOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func);
    void inOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func);
    void postOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func);
};

template <typename Type>
BiTree<Type>::BiTree()
{
    root = nullptr;
}

template <typename Type>
BiTree<Type>::~BiTree()
{
}

template <typename Type>
void BiTree<Type>::preOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func)
{
    if (curNode == nullptr)
    {
        return;
    }
    func(curNode);
    preOrderTranvers(curNode->left, func);
    preOrderTranvers(curNode->right, func);
}

template <typename Type>
void BiTree<Type>::inOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func)
{
    if (curNode == nullptr)
    {
        return;
    }
    inOrderTranvers(curNode->left, func);
    func(curNode);
    inOrderTranvers(curNode->right, func);
}

template <typename Type>
void BiTree<Type>::postOrderTranvers(BiTreeNode<Type> *curNode, function<void(BiTreeNode<Type> *)> func)
{
    if (curNode == nullptr)
    {
        return;
    }
    postOrderTranvers(curNode->left, func);
    postOrderTranvers(curNode->right, func);
    func(curNode);
}

class ExpConvert : BiTree<string>
{
private:
    string temp;                                               // 暂存目前正在处理的数据
    string expression;                                         // 表达式
    Stack<BiTreeNode<string> *> dataStack;                     // 辅助数栈
    Stack<string> operatorStack;                               // 辅助符号栈
    function<void(BiTreeNode<string> *)> outputWithBracket;    // 输出函数
    function<void(BiTreeNode<string> *)> outputWithoutBracket; // 输出函数

public:
    ExpConvert();
    ~ExpConvert();
    void createTree();
    void printResult();
};

ExpConvert::ExpConvert()
{
    cout << "请输入表达式：";
    cin >> expression;
    for (unsigned i = 0; i < expression.size(); i++)
    {
        if ((expression.at(i) >= '0' && expression.at(i) <= '9') || expression.at(i) == '.')
        {
            temp += expression.at(i);
        }
        else
        {
            if (!temp.empty())
            {
                if (expression.at(i) == ')')
                {
                    temp += expression.at(i);
                }
                BiTreeNode<string> *tmpNode = new BiTreeNode<string>(temp);
                dataStack.push(tmpNode);
            }
            temp.clear();
            switch (expression.at(i))
            {
            case '+':
            case '-':
                if (operatorStack.empty())
                {
                    operatorStack.push(string(1, expression.at(i)));
                }
                else if (operatorStack.top() == "*" || operatorStack.top() == "/")
                {
                    createTree();
                    operatorStack.push(string(1, expression.at(i)));
                }
                else
                {
                    operatorStack.push(string(1, expression.at(i)));
                }
                break;
            case '*':
            case '/':
                operatorStack.push(string(1, expression.at(i)));
                break;
            case '(':
                operatorStack.push(string(1, expression.at(i)));
                temp += expression.at(i);
                break;
            case ')':
                while (operatorStack.top() != "(")
                {
                    createTree();
                }
                operatorStack.pop();
                break;
            default:
                cout << "Create Tree Error!" << endl;
                exit(0);
            }
        }
    }
    if (!temp.empty())
    {
        BiTreeNode<string> *tmpNode = new BiTreeNode<string>(temp);
        dataStack.push(tmpNode);
    }
    while (!operatorStack.empty())
    {
        createTree();
    }
    root = dataStack.top();
    dataStack.pop();
    outputWithBracket = [&](BiTreeNode<string> *curNode)
    {
        cout << curNode->val << " ";
    };
    outputWithoutBracket = [&](BiTreeNode<string> *curNode)
    {
        for (unsigned int i = 0; i < curNode->val.size(); i++)
        {
            if (curNode->val.at(i) == '(' || curNode->val.at(i) == ')')
            {
                continue;
            }
            cout << curNode->val.at(i);
        }
        cout << " ";
    };
}

ExpConvert::~ExpConvert()
{
}

void ExpConvert::createTree()
{
    try
    {
        BiTreeNode<string> *left = dataStack.top();
        dataStack.pop();
        BiTreeNode<string> *right = dataStack.top();
        dataStack.pop();
        BiTreeNode<string> *curOper = new BiTreeNode<string>(operatorStack.top(), right, left);
        operatorStack.pop();
        dataStack.push(curOper);
    }
    catch (const char *e)
    {
        cout << e << endl;
        exit(0);
    }
}

void ExpConvert::printResult()
{
    cout << "波兰表达式：  ";
    postOrderTranvers(root, outputWithoutBracket);
    cout << endl;
    cout << "中缀表达式：  ";
    inOrderTranvers(root, outputWithBracket);
    cout << endl;
    cout << "逆波兰表达式：";
    preOrderTranvers(root, outputWithoutBracket);
    cout << endl;
}

int main()
{
    ExpConvert testInstance;
    testInstance.printResult();
    return 0;
}
