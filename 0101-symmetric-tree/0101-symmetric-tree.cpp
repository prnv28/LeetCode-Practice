/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isPallindrom(vector<int> &temp){
        int n = temp.size();
        for(int i=0;i<n/2;i++){
            if(temp[i]!=temp[n-i-1]){
                return false;
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    temp.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }else{
                    temp.push_back(INT_MAX);
                }
            }
            if(!isPallindrom(temp)) return false;
        }
        return true;
    }
};