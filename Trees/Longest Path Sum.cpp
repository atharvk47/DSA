#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Longest Path Sum is nothing but the path containing the maximum sum of the values of the nodes along with it.

int maxi = INT_MIN;       // Done to ensure the minimum possible value of maxi

int LongestPathSum(TreeNode* root,int &maxi){
    if(root == NULL)return 0;
     
    int leftSum = max(0,LongestPathSum(root->left,maxi));      //maximum function is added to avoid negative node value cases
    int rightSum = max(0,LongestPathSum(root->right,maxi));

    maxi = max(maxi,leftSum + rightSum + root->data );

    return root->data + max(leftSum, rightSum);


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

    int val = LongestPathSum(t1,maxi);
    cout << maxi << endl;
    cout << val << endl;
    

return 0;
}