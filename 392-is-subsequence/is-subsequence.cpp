class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.length()==0 && s.length()==0) return true;
        int i=0;
        for(int j=0;j<t.size();j++){
            if(s[i]==t[j]) i++;
            if(i==s.length())   return true;
        }

        return false;
    }
};