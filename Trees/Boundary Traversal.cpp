#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

bool isLeaf(TreeNode* root){
    if(root->left == NULL && root->right == NULL) {return true;}
    else{
    return false;
    }
}

void addLeftBoundary(TreeNode* root,vector<int> &ans){
    TreeNode* cur = root->left;

    while(cur){
        if(!isLeaf(cur)){
            ans.push_back(cur->data);
        }
        if(cur->left){
            cur = cur->left;
        }else{
            cur = cur->right;
        }
    }
}

void addRightBoundary(TreeNode* root, vector<int> &ans){
    TreeNode* cur = root->right;
    vector<int> res;

    while(cur){
        if(!isLeaf(cur)){
            res.push_back(cur->data);
        }
        if(cur->right){
            cur = cur->right;
        }else{
            cur = cur->left;
        }
    }

    for(int i = res.size()-1;i >= 0;i--){
        int val = res[i];
        ans.push_back(val);
    }
}

void addLeaves(TreeNode* root, vector<int> &ans){
    if(isLeaf(root)){
       ans.push_back(root->data);
       return;
    }

    if(root->left) addLeaves(root->left, ans);
    if(root->right) addLeaves(root->right, ans);
}
vector<int> Boundary(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
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


    vector<int> response = Boundary(t1);
    for(int i = 0; i < response.size();i++){
        cout << response[i] << endl;
    }
 return 0;
}