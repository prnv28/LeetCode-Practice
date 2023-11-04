class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;
        for(auto a : strs){
            string key = getKey(a);
            mp[key].push_back(a);
        }

        for(auto itr = mp.begin();itr!=mp.end();itr++){
            result.push_back(itr->second);
        }   
        return result;
    }

    string getKey(string s){
        vector<int> count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        string key = "";
        for(int i=0;i<26;i++){
            key+=to_string(count[i])+"#";
        }
        return key;
    }
};