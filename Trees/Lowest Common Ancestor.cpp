#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};


TreeNode* LCA(TreeNode* root, TreeNode* p,TreeNode* q){
    if(root == NULL || root == p || root == q){
        return root;
    }

    TreeNode* LCAleft = LCA(root->left,p,q);
    TreeNode* LCAright = LCA(root->right,p,q);

    if(LCAleft == NULL) {return LCAright;}
    else if(LCAright == NULL) {return LCAleft;}
    else{ return root;}
}
int main(){

    TreeNode* t1 = new TreeNode();
    TreeNode* t2 = new TreeNode();
    TreeNode* t3 = new TreeNode();
    TreeNode* t4 = new TreeNode();
    TreeNode* t5 = new TreeNode();
    TreeNode* t6 = new TreeNode();
    TreeNode* t7 = new TreeNode();


    t1->data = 1;
    t2->data = 2;
    t3->data = 3;
    t4->data = 4;
    t5->data = 5;
    t6->data = 6;
    t6->data = 7;

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;

    cout << LCA(t1,t3,t6)->data << endl;
    return 0;
}