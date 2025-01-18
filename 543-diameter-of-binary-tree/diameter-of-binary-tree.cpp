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
    int algo(TreeNode* root,int& diameter){
        if(!root) return 0;
        int left = 0, right = 0;
        if(root->left)
            left = 1 + algo(root->left,diameter);
        if(root->right)
            right = 1 + algo(root->right,diameter);
        diameter = max(diameter,left+right);
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        algo(root,diameter);
        return diameter;
    }
};