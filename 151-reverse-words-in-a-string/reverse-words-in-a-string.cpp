class Solution {
public:
    void print(vector<string>& ds){
        for(auto s : ds){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string reverseWords(string s) {
        vector<string> ds;
        string tmp = "";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                tmp = tmp + s[i];
                if(i==s.size()-1){
                    ds.push_back(tmp);
                }
            }else if(tmp.size()>0 && s[i]==' '){
                ds.push_back(tmp);
                tmp = "";
            }
        }
        reverse(ds.begin(),ds.end());
        string ans = "";
        for(int i=0;i<ds.size();i++){
            ans += ds[i];
            if(i==ds.size()-1){
                return ans;
            }
            ans += " ";
        }
        return ans;
    }
};