class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int i=0,j=numbers.size()-1;
        while(i<j){
            while(numbers[i]+numbers[j]>target) j--;
            if(numbers[i]+numbers[j]==target) return {i+1,j+1};
            else i++;
        }
        return {};
    }
};