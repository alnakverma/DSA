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

bool exists(TreeNode* root, TreeNode* target){
    if(root == NULL) return false;
    if(root == target) return true;
    return exists(root->left, target) || exists(root->right, target);
}

TreeNode* lowestCommonAncester(TreeNode* root, TreeNode* p, TreeNode* q){
    // if(p==NULL || q==NULL) return root;
    // if(exists(root->left, p) && exists(root->right, q)) return root;
    // if(exists(root->left, q) && exists(root->right, p)) return root;
    if(exists(root->left, p) && exists(root->left, q)) return lowestCommonAncester(root->left, p, q);
    if(exists(root->right, p) && exists(root->right, q)) return lowestCommonAncester(root->right, p, q);
    return root;
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
    TreeNode* ans = lowestCommonAncester(a,d,f);
    cout<<ans->val;
return 0;
}