class Solution {
public:
    
    string intToRoman(int num) {
        map<int,string> mp = {{1,"I"},
                              {4, "IV"},
                              {5,"V"},
                              {9,"IX"},
                              {10,"X"},
                              {40,"XL"},
                              {50,"L"},
                              {90,"XC"},
                              {100,"C"},
                              {400,"CD"},
                              {500,"D"},
                              {900,"CM"},
                              {1000,"M"}};

        vector<int> divisor = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int temp = num;
        string ans = "";
        for(int i=0;i<divisor.size();i++){
            while(temp>=divisor[i]){
                ans +=mp[divisor[i]];
                temp -=divisor[i];
            }
        }
        return ans;
    }
};