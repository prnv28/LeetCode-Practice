class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    string defangIPaddr(string address) {
        string result="";
        for(char c : address){
            if(c=='.') result+="[.]";
            else result+=c;
        }
        return result;
    }
};