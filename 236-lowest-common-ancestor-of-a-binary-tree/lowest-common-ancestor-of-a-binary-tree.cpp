/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* algo(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q) return root;
        
        TreeNode* left = algo(root->left,p,q);
        TreeNode* right = algo(root->right,p,q);
        if(!left) return right;
        else if(!right) return left;
        else return root;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return algo(root, p, q);
    }
};