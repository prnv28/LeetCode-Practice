class Solution {
public:
    static 

    class Compare {
        public:
        bool operator()(pair<int,int>& a, pair<int,int>& b){
            return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num : nums) mp[num]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;

        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(pq.size()<k){
                pq.push(*itr);
            }else if(pq.size()==k && (pq.top().second < itr->second)){
                pq.pop();
                pq.push(*itr);
            }
        }

        vector<int> result;
        result.reserve(k);
        while(!pq.empty()){
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};