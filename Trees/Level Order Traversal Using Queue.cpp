#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

vector<vector<int>> levelOrderUsingQueue(TreeNode* root){
    vector<vector<int>> ans;
    if(root == NULL)return ans;
    queue<TreeNode*> q;

    q.push(root);
    while(!q.empty()){
        int queueSize = q.size();
        vector<int> temp;
        for(int i = 0; i <queueSize;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            temp.push_back(node->data);
        }
        ans.push_back(temp);
    }

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


    vector<vector<int>> v = levelOrderUsingQueue(t1);
    for(int i =  0; i < v.size();i++){
        int set = v[i].size();
        for(int j = 0; j < set;j++){

        cout << v[i][j] << endl;
        }
    }

    return 0;
}