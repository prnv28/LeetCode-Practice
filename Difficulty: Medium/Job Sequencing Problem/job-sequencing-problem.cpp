class Solution {
  public:
    struct Job 
    { 
        int id;	 // Job Id 
        int dead; // Deadline of job 
        int profit; // Profit if job is over before or on deadline 
    };
    class Cmp{
        public:
        bool operator()(Job a,Job b){
            return a.profit<b.profit;
        }
    };
     vector<int> JobScheduling(Job arr[], int n) 
    { 
        priority_queue<Job, vector<Job>,Cmp> q;
        
        for(int i=0;i<n;i++){
            q.push(arr[i]);
        }
        
        
        int jobs[n+1];
        for(int i=0;i<n+1;i++){
            jobs[i] = -1;
        }
        int count = 0;
        int profit = 0;
        while(!q.empty()){
            Job temp = q.top();
            int i = temp.dead;
            while(i>0){
                if(jobs[i]!=-1){
                    i--;
                }else{
                    jobs[i]=temp.id;
                    profit += temp.profit;
                    count++;
                    break;
                }
            }
        
            q.pop();
        }
        
        return {count,profit};
    } 
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        struct Job arr[n];
        for(int i=0;i<n;i++){
            arr[i].id = i+1;
            arr[i].dead = deadline[i];
            arr[i].profit = profit[i];
        }
        return JobScheduling(arr,n);
        
    }
};