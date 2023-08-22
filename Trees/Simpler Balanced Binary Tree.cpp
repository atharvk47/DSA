#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};


// Balanced Binary Tree is a binary tree which has an absolute difference between the left height and right height of every node
// between 0 and 1.


// The given function is an alternative to the previous function and consumes a time complexity of O(N).
// If a given tree is a balanced binary tree, then the given function will return its height else it will return -1.

int heightCheck(TreeNode* root){  
    if(root == NULL) return 0;

    int lh = heightCheck(root->left);
    int rh = heightCheck(root->right);

    if(lh == -1 &&rh == -1) return -1;
    if(abs(lh-rh)>1) return -1;

    return 1+max(lh,rh);
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

    cout << checkBBT(t1) << endl;

return 0;
}