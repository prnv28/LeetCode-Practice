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
    void algo(TreeNode* root, vector<int>& result){
        if(root==NULL) return;
        algo(root->left,result);
        result.push_back(root->val);
        algo(root->right,result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        algo(root,result);
        return result;
    }
};