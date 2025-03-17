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

bool issametree(TreeNode* a, TreeNode*p){
    if(a == NULL && p == NULL) return true;
    if(a == NULL || p == NULL) return false;

    if(a->val != p->val) return false;
    if(issametree(a->left, p->left) == false) return false;
    if(issametree(a->right, p->right) == false) return false;
    return true;
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

    TreeNode* p = new TreeNode(1);
    TreeNode* q = new TreeNode(2);
    TreeNode* r = new TreeNode(3);
    TreeNode* s = new TreeNode(4);
    TreeNode* t = new TreeNode(5);
    TreeNode* u = new TreeNode(6);
    TreeNode* v = new TreeNode(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e; 
    c->left = f;
    c->right = g;

    p->left = q;
    p->right = r;
    q->left = s;
    q->right = t; 
    r->left = u;
    r->right = v;
    
    displayTree(a);
    cout<<endl;
    displayTree(p);
    cout<<endl;

    cout<<issametree(a,p);
return 0;
}