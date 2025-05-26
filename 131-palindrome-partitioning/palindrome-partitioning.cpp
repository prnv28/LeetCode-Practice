class Solution {
public:
    bool isPallindrom(string& s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void partitionHelper(int index, string& s, vector<string>& ds, vector<vector<string>>& result){
        if(index==s.size()){
            result.push_back(ds);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPallindrom(s,index,i)){
                ds.push_back(s.substr(index,i-index+1));
                partitionHelper(i+1,s,ds,result);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<string>> result;
        vector<string> ds;
        partitionHelper(0,s,ds,result);
        return result;   
    }
};