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
    int algo(TreeNode* root, int& maxi){
        if(!root) return 0;
        int left = max(0,algo(root->left,maxi));
        int right = max(0,algo(root->right,maxi));

        maxi = max(maxi,right+left+root->val);
        return max(right,left)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        algo(root,maxi);
        return maxi;
    }
};