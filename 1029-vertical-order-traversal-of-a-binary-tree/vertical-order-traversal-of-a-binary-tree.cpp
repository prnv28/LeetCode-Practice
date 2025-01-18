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
        vector<vector<int>> result;

        map<int,map<int,multiset<int>>> mp;

        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            int size = q.size();

            while(size--){
                TreeNode* node = q.front().first;
                int level = q.front().second.first;
                int depth = q.front().second.second;
                mp[level][depth].insert(node->val);
                q.pop();

                if(node->left){
                    q.push({node->left,{level-1,depth+1}});
                }
                if(node->right){
                    q.push({node->right,{level+1,depth+1}});
                }
            }
        }

        for(auto itr : mp){
            vector<int> col;
            for(auto it : itr.second){
                col.insert(col.end(),it.second.begin(),it.second.end());
            }
            result.push_back(col);
            col.clear();
        }
         return result;
    }
};