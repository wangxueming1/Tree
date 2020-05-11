#include <iostream>

using namespace std;

//�������ڵ�
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
    cout << "����";
    pre_order(node);
    cout << endl << "����";
    in_order(node);
    cout << endl << "����";
    post_order(node);
    return 0;
}

//����������������ݹ�ķ�ʽ
/*          1
          /  \
        2     3
       / \   / \
      4   5 6   7*/
void CreateTree(TreeNode*& Node) { //������������һ��ָ�����
    char data;
    cin >> data;
    if(data == '#') Node == nullptr; //#����û�нڵ�Ϊ��
    else {
        Node = new TreeNode(data); //�������ڵ�
        //�����ӽڵ�
        CreateTree(Node->left);
        CreateTree(Node->right);
    }
}

//ǰ�������
//���ʸ��ڵ�->�������������->�������������
void  pre_order(const TreeNode *Node) {
    if(Node) {
        cout << Node->val << " ";
        pre_order(Node->left);
        pre_order(Node->right);
    }
}

//���������
//�������������->���ʸ��ڵ�->�������������
void in_order(const TreeNode *Node) {
    if(Node) {
        in_order(Node->left);
        cout << Node->val << " ";
        in_order(Node->right);
    }
}

//���������
//�������������->�������������->���ʸ��ڵ�
void post_order(const TreeNode* Node) {
    if(Node) {
        post_order(Node->left);
        post_order(Node->right);
        cout << Node->val << " ";
    }
}
