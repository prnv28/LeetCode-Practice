class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int maxi = 1;
        for(int it : s){
            if(s.find(it-1)==s.end()){
                int x = it;
                int cnt = 1;
                while(s.find(x+1)!=s.end()){
                    x++;
                    cnt++;
                }
                maxi = max(maxi,cnt);
            }
            
        }
        return maxi;
    }
};