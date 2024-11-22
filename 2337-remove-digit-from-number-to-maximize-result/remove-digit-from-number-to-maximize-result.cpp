class Solution {
public:
    string removeDigit(string number, char digit) {
        int to_remove = -1;
        for(int i=0;i<number.size();i++){
            if(number[i]==digit){
               to_remove = i;
               if(i+1 < number.size() && number[i+1]>digit){
                    break;
               }
            }
        }

        return number.erase(to_remove,1);
    }
};