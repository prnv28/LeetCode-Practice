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
 int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        if(root->left && root->right) return 1+min(minDepth(root->left),minDepth(root->right));
        else if(root->left) return minDepth(root->left)+1;
        else if(root->right) return minDepth(root->right)+1;
        else return 1;
    }
};