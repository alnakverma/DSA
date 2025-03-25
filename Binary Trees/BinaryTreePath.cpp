#include<bits/stdc++.h>
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

void path(TreeNode* root, string s, vector<string>& ans){
    if(root == NULL) return;
    string a = to_string(root->val);
    if(root->left == NULL && root->right == NULL){
        s+=a;
        ans.push_back(s);
        return;
    }
    path(root->left,s+a+"->",ans);
    path(root->right,s+a+"->",ans);
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
    vector<string> ans;
    path(a,"",ans);
    for(auto a : ans) cout<<a<<" ";
return 0;
}