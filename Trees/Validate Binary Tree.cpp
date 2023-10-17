class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parents(n, -1);
        
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                if(parents[leftChild[i]] == -1)
                    parents[leftChild[i]] = i; // Assign parent
                else return false; // Duplicate parent, not a valid binary tree
            }
            if(rightChild[i] != -1){
                if(parents[rightChild[i]] == -1)
                    parents[rightChild[i]] = i; // Assign parent
                else return false; // Duplicate parent, not a valid binary tree
            }
        }

        int root = -1;
        for(int i = 0;i < n; i++){
            if(parents[i] == -1){
                if(root == -1) root = i; // Assign root
                else return false; // Multiple roots, not a valid binary tree
            }
        }
        if(root == -1) return false; // No root found, not a valid binary tree

        unordered_set<int> visited;
        queue<int> toVisit;
        toVisit.push(root);
        while(!toVisit.empty()){
            int node = toVisit.front();
            toVisit.pop();
            if(visited.find(node) != visited.end()) 
                return false; // Cycle detected, not a valid binary tree
            visited.insert(node);
            if(rightChild[node] != -1) toVisit.push(rightChild[node]);
            if(leftChild[node] != -1) toVisit.push(leftChild[node]);
        }

        return visited.size() == n;
    }
};