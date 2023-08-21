#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

 
 void printLevel(TreeNode* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << root->data << endl;
    }else if(level > 1){
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
 }

 int height(TreeNode* root){
    if(root == NULL){return 0;}
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        if(lheight > rheight){
            return(lheight + 1);
        }else{
            return (rheight+1);
        }
    }
 }

 void levelOrder(TreeNode* root){
    int h = height(root);
    for(int i = 1; i <= h;i++){
        printLevel(root,i);
    }
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


    
    levelOrder(t1);
    // vector<vector<int>> v = levelorderQ(t1);
    // for(int i =  0; i < v.size();i++){
    //     int set = v[i].size();
    //     for(int j = 0; j < set;j++){

    //     cout << v[i][j] << endl;
    //     }
    // }

    return 0;
}