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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<int,map<int,multiset<int>>> mp;
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                int col = it.second.first;
                int row = it.second.second;
                mp[col][row].insert(node->val);
                if(node->left) q.push({node->left,{col-1,row+1}});
                if(node->right) q.push({node->right,{col+1,row+1}});
            }
        }
        for(auto itr : mp){
            vector<int> col;
            for(auto it : itr.second){
                col.insert(col.end(),it.second.begin(),it.second.end());
            }
            ans.push_back(col);
            col.clear();
        }
        return ans;
    }
};