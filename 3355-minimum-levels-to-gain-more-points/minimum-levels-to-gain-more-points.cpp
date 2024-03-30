class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int total = 0;
        for(int i=0;i<possible.size();i++){
            if(possible[i]==0){
                total+= -1;
                possible[i] = -1;
            } else{
                total+=1;
            }
        }
        
        int points = 0;
        for(int i=0;i<possible.size()-1;i++){
            points+=possible[i];
            if(2*points>total) return i+1;
        }
        
        return -1;
    }
};