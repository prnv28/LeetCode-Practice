class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0;
        int cows = 0;
        map<char,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                if(mp.find(secret[i])==mp.end()){
                    mp[secret[i]] = {1,0};
                }else{
                    mp[secret[i]].first++;
                }

                if(mp.find(guess[i])==mp.end()){
                    mp[guess[i]] = {0,1};
                }else{
                    mp[guess[i]].second++;
                }
            }
        }
        for(auto it : mp){
            cows += min(it.second.first,it.second.second);
        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};