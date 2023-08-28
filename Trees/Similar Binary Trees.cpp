#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

bool SimilarTree(TreeNode* root, TreeNode* node){
    if(root==NULL || node==NULL){
        return(root == node);
    }

    return (root->data == node->data) && SimilarTree(root->left,node->left) && SimilarTree(root->right,node->right);
}

int main(){
    TreeNode* t1 = new TreeNode();
    TreeNode* t2 = new TreeNode();
    TreeNode* t3 = new TreeNode();
    TreeNode* t4 = new TreeNode();
    TreeNode* t5 = new TreeNode();
    TreeNode* t6 = new TreeNode();

    TreeNode* s1 = new TreeNode();
    TreeNode* s2 = new TreeNode();
    TreeNode* s3 = new TreeNode();
    TreeNode* s4 = new TreeNode();
    TreeNode* s5 = new TreeNode();
    TreeNode* s6 = new TreeNode();


    t1->data = 5;
    t2->data = 3;
    t3->data = 8;
    t4->data = 1;
    t5->data = 4;
    t6->data = 7;

    s1->data = 5;
    s2->data = 3;
    s3->data = 8;
    s4->data = 1;
    s5->data = 4;
    s6->data = 7;

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = NULL;

    s1->left = s2;
    s1->right = s3;
    s2->left = s4;
    s2->right = s5;
    s3->left = s6;
    s3->right = NULL;

    cout << SimilarTree(t1,s1)<< endl;        // Output: 1

return 0;
}