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
int levels(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void helper(TreeNode* root, int &maxdia){
    if(root == NULL) return;
    maxdia = max(maxdia, levels(root->left) + levels(root->right));
    helper(root->left, maxdia);
    helper(root->right, maxdia);
}

int diameter(TreeNode* root){
    int maxdia = 0;
    helper(root, maxdia);
    return maxdia;
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
    cout<<diameter(a);    

return 0;
}