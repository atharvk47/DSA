#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

int maxi = 0;

int Diameter(TreeNode* root,int &maxi){
    if(root ==  NULL)return 0;

    int lh = Diameter(root->left,maxi);
    int rh = Diameter(root->right,maxi);
    
    maxi = max(maxi,lh+rh);

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

    int val = Diameter(t1,maxi);
    cout << maxi << endl;
    cout << val << endl;
    

return 0;
}