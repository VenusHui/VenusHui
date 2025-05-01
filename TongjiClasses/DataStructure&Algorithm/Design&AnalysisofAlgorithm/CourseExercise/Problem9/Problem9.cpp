#include <functional>
#include <iostream>
using namespace std;

template <typename Type> struct BiTreeNode {
  Type val;
  BiTreeNode *left;
  BiTreeNode *right;
  BiTreeNode() : left(nullptr), right(nullptr) {}
  BiTreeNode(Type x) : val(x), left(nullptr), right(nullptr) {}
  BiTreeNode(Type x, BiTreeNode *left, BiTreeNode *right)
      : val(x), left(left), right(right) {}
  ostream &operator<<(ostream &out) {
    out << this->val;
    return out;
  }
};

template <typename Type> class BiTree {
protected:
  BiTreeNode<Type> *root; // 根结点

public:
  BiTree();
  ~BiTree();

  // 递归方式实现的前序、中序、后序遍历，func为遍历时对于当前节点进行的操作
  void preOrderTranvers(BiTreeNode<Type> *curNode,
                        function<void(BiTreeNode<Type> *)> func);
  void inOrderTranvers(BiTreeNode<Type> *curNode,
                       function<void(BiTreeNode<Type> *)> func);
  void postOrderTranvers(BiTreeNode<Type> *curNode,
                         function<void(BiTreeNode<Type> *)> func);
};

template <typename Type> BiTree<Type>::BiTree() { root = nullptr; }

template <typename Type> BiTree<Type>::~BiTree() {}

template <typename Type>
void BiTree<Type>::preOrderTranvers(BiTreeNode<Type> *curNode,
                                    function<void(BiTreeNode<Type> *)> func) {
  if (curNode == nullptr) {
    return;
  }
  func(curNode);
  preOrderTranvers(curNode->left, func);
  preOrderTranvers(curNode->right, func);
}

template <typename Type>
void BiTree<Type>::inOrderTranvers(BiTreeNode<Type> *curNode,
                                   function<void(BiTreeNode<Type> *)> func) {
  if (curNode == nullptr) {
    return;
  }
  inOrderTranvers(curNode->left, func);
  func(curNode);
  inOrderTranvers(curNode->right, func);
}

template <typename Type>
void BiTree<Type>::postOrderTranvers(BiTreeNode<Type> *curNode,
                                     function<void(BiTreeNode<Type> *)> func) {
  if (curNode == nullptr) {
    return;
  }
  postOrderTranvers(curNode->left, func);
  postOrderTranvers(curNode->right, func);
  func(curNode);
}

class BiSortTree : BiTree<int> {
private:
  char oper;       // 用户的操作类型
  int temp;        // 每次操作的中间数据
  bool repeatFlag; // 二叉排序树中是否有带操作数据的标志
  function<void(BiTreeNode<int> *)> output;        // 格式化输出函数
  void find(BiTreeNode<int> *curNode, int key);    // 查询操作
  void insert(BiTreeNode<int> *&curNode, int key); // 插入操作

public:
  // 构造和析构函数
  BiSortTree();
  ~BiSortTree();

  // 获取用户操作
  bool setOper();
  char getOper() { return oper; }

  // 获取用户输入的数据
  bool getElem(string cue);

  // 建立二叉排序树
  void createTree();

  // 输出二叉排序树
  void outputTree();

  // 向二叉排序树中插入数据
  void insertElem();

  // 二叉排序树的查询操作
  void findElem();
};

BiSortTree::BiSortTree() {
  oper = 0;
  temp = 0;
  repeatFlag = false;
  cout << "**              二叉排序树             **" << endl;
  cout << "=========================================" << endl;
  cout << "**        1 --- 建立二叉排序树         **" << endl;
  cout << "**        2 --- 插入元素               **" << endl;
  cout << "**        3 --- 查询元素               **" << endl;
  cout << "**        4 --- 退出程序               **" << endl;
  cout << "=========================================" << endl;
}

BiSortTree::~BiSortTree() {}

bool BiSortTree::setOper() {
  cout << "Please Input Operation Code:";
  while (cin >> oper) {
    if (oper >= '1' && oper <= '4') {
      return true;
    }
    cout << "Operation code error, Please Check Operation Code:";
    cin.clear();
    cin.ignore(65536, '\n');
  }
  return false;
}

bool BiSortTree::getElem(string cue) {
  cout << cue;
  cin >> temp;
  if (cin.fail()) {
    cin.clear();
    cin.ignore(65536, '\n');
    return false;
  }
  return true;
}

void BiSortTree::createTree() {
  cout << "Please input key to create Bsort_Tree:" << endl;
  while (getElem("")) {
    insert(root, temp);
  }
  outputTree();
}

void BiSortTree::outputTree() {
  output = [&](BiTreeNode<int> *curNode) { cout << curNode->val << "->"; };
  cout << "Bsort_Tree is:" << endl;
  inOrderTranvers(root, output);
  cout << endl;
}

void BiSortTree::insert(BiTreeNode<int> *&curNode, int key) {
  if (curNode == nullptr) {
    curNode = new BiTreeNode<int>(key);
    return;
  } else if (curNode->val == key) {
    repeatFlag = true;
    cout << "The input key<" << key << "> is have in!" << endl;
    return;
  } else if (curNode->val > key) {
    insert(curNode->left, key);
  } else if (curNode->val < key) {
    insert(curNode->right, key);
  }
  return;
}

void BiSortTree::insertElem() {
  repeatFlag = false;
  insert(root, temp);
  if (!repeatFlag) {
    cout << "Insert success!" << endl;
    outputTree();
  } else {
    cout << "Insert Error!" << endl;
  }
}

void BiSortTree::find(BiTreeNode<int> *curNode, int key) {
  if (curNode == nullptr) {
    return;
  } else if (curNode->val == key) {
    repeatFlag = true;
    return;
  } else if (curNode->val > key) {
    find(curNode->left, key);
  } else if (curNode->val < key) {
    find(curNode->right, key);
  }
}

void BiSortTree::findElem() {
  repeatFlag = false;
  find(root, temp);
  if (repeatFlag) {
    cout << "Search success!" << endl;
  } else {
    cout << temp << "not exist!" << endl;
  }
}

int main() {
  BiSortTree testInstance;
  bool loop = true;
  while (loop && testInstance.setOper()) {
    switch (testInstance.getOper()) {
    case '1':
      testInstance.createTree();
      break;
    case '2':
      if (testInstance.getElem("Please input key which inserted: ")) {
        testInstance.insertElem();
      }
      break;
    case '3':
      if (testInstance.getElem("Please input key which searched: ")) {
        testInstance.findElem();
      }
      break;
    case '4':
      loop = false;
      break;
    default:
      cout << "Operation Error!" << endl;
      break;
    }
  }
  return 0;
}