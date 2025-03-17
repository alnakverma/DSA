#include<iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void displayTree(TreeNode* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}

int maxnode(TreeNode* root){
    if(root == NULL) return INT_MIN;
    return max(root->val , max(maxnode(root->left) , maxnode(root->right)));
}

int minnode(TreeNode* root){
    if(root == NULL) return INT_MAX;
    return min(root->val , min(minnode(root->left) , minnode(root->right)));
}

int main()
{
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e; 
    c->left = f;
    c->right = g;

    displayTree(a);
    cout<<endl;
    cout<<maxnode(a)<<endl;
    cout<<minnode<<endl;

return 0;
}