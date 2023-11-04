class Solution {
public:
    bool isAnagram(string s, string t) {
        // transform(s.begin(),s.end(),s.begin(),::tolower);
        // transform(t.begin(),t.end(),t.begin(),::tolower);
        if(s.size()!=t.size()) return false;
        unordered_map<char,pair<int,int>> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].first++;
            mp[t[i]].second++;
        }

        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second.first!=itr->second.second) return false;
        }
        return true;
    }
};