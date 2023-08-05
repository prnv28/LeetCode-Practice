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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            long long n = q.size();
            long long left = q.front().second;
            long long right = q.back().second;
            ans = max(ans,right-left+1);
            
            for(long i=0;i<n;i++){
                TreeNode* temp = q.front().first;
                long long ind = q.front().second - left;
                q.pop();
                if(temp->left) q.push({temp->left,(long long)(2*ind)+1});
                if(temp->right) q.push({temp->right,(long long)(2*ind)+2});
            }
            
        }
        return (int)ans;
    }
};