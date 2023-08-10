class Solution {
public:
    
    class cmp{
      public:
      
      bool operator()(pair<int,int> &a, pair<int,int>&b){
          return a.second > b.second;
      }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> ds;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            ds[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        
        for(auto itr = ds.begin();itr!=ds.end();itr++){
            if(pq.size()<k){
                pq.push(*itr);
            }else if(pq.size()==k && (pq.top().second)<(*itr).second){
                pq.pop();
                pq.push(*itr);
            }
        }
        
        for(int i = 0;i<k;i++){
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result; 
    }
};