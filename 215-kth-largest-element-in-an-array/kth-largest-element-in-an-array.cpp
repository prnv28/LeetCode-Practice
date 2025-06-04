class Solution {
public:
    class Compare {
    public:
        bool operator()(int a, int b){
            return a>=b;
        }
    };
    static 
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,Compare> pq;
        for(int i=0;i<nums.size();i++){
            int size = pq.size();
            if(size<k){
                pq.push(nums[i]);
            }else{
                if(pq.top()<nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            
        }
        return pq.top();
    }
};