class Solution {
public:

    bool isOpenChar(char ch){
        return (ch=='(' || ch=='{' || ch=='[');
    }

    bool isCloseChar(char ch){
        return (ch==')' || ch=='}' || ch==']');
    }

    char getOpenChar(char ch){
        if(ch==')') return '(';
        else if(ch=='}') return '{';
        else return '[';
    }
    bool isValid(string s) {
        stack<char> ds;

        for(char ch : s){
            if((ch=='(' || ch=='{' || ch=='[')){
                ds.push(ch);
            }else if((ch==')' || ch=='}' || ch==']') && !ds.empty() && ds.top()==getOpenChar(ch)){
                ds.pop();
            }else{
                return false;
            }
        }

        return ds.empty();
    }
};