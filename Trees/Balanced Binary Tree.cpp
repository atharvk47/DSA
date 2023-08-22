#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};


int height(TreeNode* root){
    if(root ==  NULL)return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1+max(lh,rh);
}


bool checkBBT(TreeNode* root){
    if(root == NULL){
        return true;                   // It takes O(n^2) to execute.
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)> 1) return false;

    bool lhs = checkBBT(root->left);
    bool rhs = checkBBT(root->right);

    if(!lhs || !rhs) return false;

    return true;
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