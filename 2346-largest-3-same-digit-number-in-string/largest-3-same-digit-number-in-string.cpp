class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_map<int,string> mp = {{-1,""},
                                        {0,"000"},
                                        {1,"111"},
                                        {2,"222"},
                                        {3,"333"},
                                        {4,"444"},
                                        {5,"555"},
                                        {6,"666"},
                                        {7,"777"},
                                        {8,"888"},
                                        {9,"999"}};
        for(int i=9;i>=-1;i--)
            if (num.find(mp[i]) != string::npos) return mp[i];
        

        return mp[-1];
    }
};