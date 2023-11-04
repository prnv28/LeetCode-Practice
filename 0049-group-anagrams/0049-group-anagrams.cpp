class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;
        for(auto a : strs){
            string s = a; 
            sort(s.begin(),s.end());
            if(mp.find(s)==mp.end()){
                mp[s]= {a};
            }else{
                mp[s].push_back(a);
            }
        }

        for(auto itr = mp.begin();itr!=mp.end();itr++){
            result.push_back(itr->second);
        }   
        return result;
    }
};