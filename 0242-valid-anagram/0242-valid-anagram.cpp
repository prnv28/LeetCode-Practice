class Solution {
public:
    bool isAnagram(string s, string t) {
        // transform(s.begin(),s.end(),s.begin(),::tolower);
        // transform(t.begin(),t.end(),t.begin(),::tolower);
        if(s.size()!=t.size()) return false;
        map<int,pair<int,int>> mp;
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