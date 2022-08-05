class Solution {
public:
    vector<int> dp; //Declaring Globally
    Solution(){
        dp.resize(1001);
        fill(dp.begin(),dp.end(),-1);
    }
    
    
    int combinationSum4(vector<int>& nums, int target,int cursum=0) {
        if(cursum > target) return 0;
        if(cursum == target) return 1;
        if(dp[cursum]!= -1) return dp[cursum];
        int ways = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] + cursum <= target){
                ways += combinationSum4(nums, target, cursum+ nums[i]);
            }
        }
        return dp[cursum] = ways;
    }
};