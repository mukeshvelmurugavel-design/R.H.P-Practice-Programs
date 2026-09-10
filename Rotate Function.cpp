class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        long long val = 0;
        int total = 0;
        for(int i=0; i<n; i++) {
            val += (i*nums[i]);
            total+=nums[i];
        }
        long long ans = val;
        for(int i=n-1; i>0; i--) {
            val =  val- ((n-1)*nums[i])+(total-nums[i]);
            ans = max(ans,val);
        }
        return (int)ans;
    }
};