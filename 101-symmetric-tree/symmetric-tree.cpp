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
    bool algo(TreeNode* hleft, TreeNode* hright){
        if(hleft==NULL || hright==NULL){
            return (hleft==hright);
        }
        return (hleft->val == hright->val) && algo(hleft->right,hright->left) && algo(hleft->left, hright->right);
    }
    bool isSymmetric(TreeNode* root) {
        return algo(root->left,root->right);
    }
};