class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n,-1);
        vector<int> rightMax(n,-1);
        int maxil = height[0];
        int maxir = height[n-1];
        leftMax[0] = maxil;
        rightMax[n-1] = maxir;
        for(int i=1;i<n;i++){
            maxil = max(maxil,height[i]);
            maxir = max(maxir,height[n-i-1]);
            leftMax[i] = maxil;
            rightMax[n-i-1] = maxir;
        }
        int total = 0;
        for(int i=0;i<n;i++){
            int thresold = min(leftMax[i],rightMax[i]);
            if(thresold>height[i]){
                total += thresold - height[i];
            }
        }
        return total;
    }
};