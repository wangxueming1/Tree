# Tree
树的创建和遍历方式（递归和非递归）

#include <iostream>

using namespace std;

//定义树节点
typedef struct TreeNode {
  char val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

void CreateTree(TreeNode*& Node);
void  pre_order(const TreeNode *Node);
void  in_order(const TreeNode *Node);
void  post_order(const TreeNode *Node);

int main()
{
    TreeNode *node;
    CreateTree(node);
    cout << "先序：";
    pre_order(node);
    cout << endl << "中序：";
    in_order(node);
    cout << endl << "后序：";
    post_order(node);
    return 0;
}

//创建树，采用先序递归的方式
/*          1
          /  \
        2     3
       / \   / \
      4   5 6   7*/
void CreateTree(TreeNode*& Node) { //这里是引用了一个指针变量
    char data;
    cin >> data;
    if(data == '#') Node == nullptr; //#代表没有节点为空
    else {
        Node = new TreeNode(data); //创建根节点
        //创建子节点
        CreateTree(Node->left);
        CreateTree(Node->right);
    }
}

//前序遍历树
//访问根节点->先序遍历左子树->先序遍历右子树
void  pre_order(const TreeNode *Node) {
    if(Node) {
        cout << Node->val << " ";
        pre_order(Node->left);
        pre_order(Node->right);
    }
}

//中序遍历树
//中序遍历左子树->访问根节点->中序遍历右子树
void in_order(const TreeNode *Node) {
    if(Node) {
        in_order(Node->left);
        cout << Node->val << " ";
        in_order(Node->right);
    }
}

//后序遍历树
//后序遍历左子树->后序遍历右子树->访问根节点
void post_order(const TreeNode* Node) {
    if(Node) {
        post_order(Node->left);
        post_order(Node->right);
        cout << Node->val << " ";
    }
}

//二叉树的非递归遍历，也就是使用栈来操作树

