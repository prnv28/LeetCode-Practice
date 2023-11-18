class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    string defangIPaddr(string address) {
        string res;
        for(auto i : address){
            if(i == '.')
                res += "[.]";
            else 
                res += i;
        }
        return res;
    }
};