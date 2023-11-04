class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string key = strs[i];
            sort(key.begin(),key.end());
            mp[key].emplace_back(move(strs[i]));
        }

        for(auto itr = mp.begin();itr!=mp.end();itr++){
            result.push_back(itr->second);
        }   
        return result;
    }
};