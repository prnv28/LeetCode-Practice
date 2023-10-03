class Solution {
public:
    string reverseWords(string s) {
        string ans, temp;

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                temp+=s[i];
            }else{
                if(temp.size()){
                    for(int j=temp.size()-1;j>=0;j--){
                        ans+=temp[j];
                    }
                    ans+=' ';
                    temp.clear();
                }
            }
        }

        for(int i=temp.size()-1;i>=0;i--){
            ans+=temp[i];
        }
        if(ans[ans.size()-1]==' '){
            ans.erase(ans.size()-1,1);
        }

        return ans;
    }
};