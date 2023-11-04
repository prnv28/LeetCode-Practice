class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a'].first++;
            mp[t[i]-'a'].second++;
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second.first!=itr->second.second) return false;
        }
        return true;
    }
};