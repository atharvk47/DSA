#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function which returns the height of the binary tree

int height(TreeNode* root){
    if(root == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1+max(lh,rh);
}

int main(){
    TreeNode* t1 = new TreeNode();
    TreeNode* t2 = new TreeNode();
    TreeNode* t3 = new TreeNode();
    TreeNode* t4 = new TreeNode();
    TreeNode* t5 = new TreeNode();
    TreeNode* t6 = new TreeNode();

    t1->data = 5;
    t2->data = 3;
    t3->data = 8;
    t4->data = 1;
    t5->data = 4;
    t6->data = 7;

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = NULL;



    return 0;
}