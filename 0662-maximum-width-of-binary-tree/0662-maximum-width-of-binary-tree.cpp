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
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        long long int ans=0;
        while(!q.empty()){
            long long int n = q.size();
            long long int mini=0;
            long long int maxi=0;
            long long int curMin = q.front().second;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front().first;
                long long int ind = q.front().second-curMin;
                if(i==0) mini = ind;
                if(i==n-1) maxi = ind;
                q.pop();
                if(temp->left) q.push({temp->left,(2*ind)+1});
                if(temp->right) q.push({temp->right,(2*ind)+2});
            }
            ans = max(ans,maxi-mini+1);
        }
        return (int)ans;
    }
};