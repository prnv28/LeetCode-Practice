class Solution {
public:
    void printV(vector<int>& V){
        for(int v:V){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0;
        int cows = 0;
        // map<char,pair<int,int>> mp;
        vector<int> sec(10,0);
        vector<int> gue(10,0);
         for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                sec[secret[i]-'0']++;
                gue[guess[i]-'0']++;
            }
        }
        // printV(sec);
        // printV(gue);
        // cout<<n<<endl;
        for(int i=0;i<10;i++){
            cows+=min(sec[i],gue[i]);
            // cout<<cows<<" : "<<i<<endl;
        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};