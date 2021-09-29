// 表达式计算
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template<class T>
class MyStackNode
{
private:
    T data;
    MyStackNode *next;

public:
    MyStackNode();
    MyStackNode(T elem, MyStackNode *next);
    ~MyStackNode();
    MyStackNode *getNext() { return next; }
    char getData() { return data; }
};

template <class T>
MyStackNode<T>::MyStackNode()
{
    next = nullptr;
}

template <class T>
MyStackNode<T>::MyStackNode(T elem, MyStackNode *next)
{
    this->data = elem;
    this->next = next;
}

template <class T>
MyStackNode<T>::~MyStackNode()
{
}

template<class T>
class MyStack
{
private:
    MyStackNode<T>* topPtr; // 栈顶指针
    int size;        // 元素个数
public:
    MyStack();
    ~MyStack();
    bool push(T elem);
    bool pop();
    template<T> T top();
};

template <class T> MyStack<T>::MyStack()
{
    topPtr = new MyStackNode<T>();
    size = 0;
}

template <class T> MyStack<T>::~MyStack()
{
}

template<class T> bool MyStack<T>::push(T elem)
{
    MyStackNode<T>* p = new MyStackNode(elem, topPtr);
    topPtr = p;
    size++;
    return true;
}

template<class T> bool MyStack<class T>::pop()
{
    if (topPtr == nullptr)
    {
        return false;
    }
    MyStackNode<class T>* p = topPtr;
    topPtr = p->getNext();
    delete p;
    size--;
    return true;
}

template<class T> T MyStack<T>::top()
{
    return topPtr->getData();
}

class BiTreeNode
{
private:
    string data;
    BiTreeNode *left;
    BiTreeNode *right;

public:
    BiTreeNode();
    BiTreeNode(string data, BiTreeNode *left, BiTreeNode *right);
    ~BiTreeNode();
    string getData() { return data; }
    BiTreeNode *getLeft() { return left; }
    BiTreeNode *getRight() { return right; }
};

BiTreeNode::BiTreeNode()
{
}

BiTreeNode::BiTreeNode(string data, BiTreeNode *left, BiTreeNode *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

BiTreeNode::~BiTreeNode()
{
}

class ExpressionConvert
{
private:
    int sBit;
    double temp;
    string expression;

public:
    ExpressionConvert();
    ~ExpressionConvert();
    void digitConvert(char ch);
    bool initTree(int start, int end);
    void preOrderTranvers();
    void inOrderTranvers();
    void postOrderTranvers();
};

ExpressionConvert::ExpressionConvert()
{
    temp = 0;
    sBit = 0;
    cout << "请输入表达式：";
    cin >> expression;
    for (unsigned i = 0; i < expression.size(); i++)
    {
        if (expression.at(i) >= '0' && expression.at(i) <= '9' || expression.at(i) == '.')
        {
            digitConvert(expression.at(i));
        }
        else
        {
            temp = 0;
            sBit = 0;
        }
    }
}

void ExpressionConvert::digitConvert(char ch)
{
    if (ch == '.')
    {
        sBit = 1;
    }
    if (sBit == 0)
    {
        temp = temp * 10 + (ch - '0');
    }
    else
    {
        temp += (ch - '0') / pow(0.1, sBit);
        sBit++;
    }
}

ExpressionConvert::~ExpressionConvert()
{
}

bool ExpressionConvert::initTree(int start, int end)
{
    BiTreeNode *temp;
    if (start == end)
    {
        temp = new BiTreeNode;
    }
    return true;
}

int main()
{
    return 0;
}