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
        long max_width = 0;
        while(!q.empty()){
            int n = q.size();
            long start = q.front().second;
            max_width = max(max_width,q.back().second - start +1);
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                long index = it.second-start;
                if(node->left) q.push({node->left,2*index+1});
                if(node->right) q.push({node->right,2*index+2});
            }
        }
        return (int) (max_width);
    }
};