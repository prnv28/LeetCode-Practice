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
    void algo(TreeNode* root,int level, int depth,map<int,map<int,multiset<int>>>& mp){
        if(!root) return;
        mp[level][depth].insert(root->val);
        algo(root->left,level-1,depth+1,mp);
        algo(root->right,level+1,depth+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        map<int,map<int,multiset<int>>> mp;
        algo(root,0,0,mp);
        for(auto itr : mp){
            vector<int> col;
            for(auto it : itr.second){
                col.insert(col.end(),it.second.begin(),it.second.end());
            }
            result.push_back(col);
        }
        return result;
    }
};