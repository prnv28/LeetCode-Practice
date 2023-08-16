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
    bool algo(TreeNode* root1, TreeNode* root2){
        if(root1==NULL || root2==NULL){
            return (root1==root2);
        }

        return ((root1->val==root2->val) && algo(root1->right,root2->left) && algo(root1->left,root2->right));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return algo(root->left,root->right);
    }
};