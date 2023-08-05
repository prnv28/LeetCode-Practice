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
        queue<pair<TreeNode*,long>> q;
        q.push({root,0});
        long ans=0,n,left,right,ind;
        TreeNode* temp;
        while(!q.empty()){
            n = q.size();
            left = q.front().second;
            right = q.back().second;
            ans = max(ans,right-left+1);
            for(long i=0;i<n;i++){
                temp = q.front().first;
                ind = q.front().second - left;
                q.pop();
                if(temp->left) q.push({temp->left,(long)(2*ind)+1});
                if(temp->right) q.push({temp->right,(long)(2*ind)+2});
            }
            
        }
        return (int)ans;
    }
};