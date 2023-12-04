class Solution {
public:
    string largestGoodInteger(string num) {
        char c1 = num[0],c2 = num[1];
        int i=2;
        int maxi = INT_MIN;
        while(i<num.size()){
            char c3 = num[i];
            if(c1==c2 and c1==c3){
                int sum = (int)(c1-'0') *100 + (int)(c2-'0') *10 + (int)(c3-'0');
                maxi = max(maxi,sum); 
            }
            c1 = c2;
            c2 = c3;
            i++;
        }
        if(maxi==0) return "000";
        return maxi == INT_MIN?"":to_string(maxi);
    }
};