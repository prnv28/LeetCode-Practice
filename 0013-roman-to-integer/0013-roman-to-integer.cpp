class Solution {
public:
    int romanToInt(string s) {
        vector<int> divisor = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string>  roman= {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        unordered_map<string,int> mp;
        for(int i =0;i<divisor.size();i++){
            mp[roman[i]] = divisor[i];
        }

        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size() && mp.find(s.substr(i,2))!=mp.end()){
                ans += mp[s.substr(i,2)];
                i++;
            }else{
                ans += mp[s.substr(i,1)];
            }
        }
        return ans;
    }
};