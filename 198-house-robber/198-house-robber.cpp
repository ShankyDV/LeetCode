// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp{n-1};
//         dp[0] = nums[0];
//         dp[1] = max(dp[0],nums[1]);
//         for(int i =2;i<n-1; i++){
//             int pick = nums[i] + dp[i-2];
//             int Notpick = 0 + dp[i-1];
//             dp[i] = max(pick,Notpick);
//         } 
//         return dp[n-1];
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size());
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};