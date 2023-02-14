class Solution {
public:
    int solve(vector<int>&nums,int n, int index, int prev,vector<vector<int>>&dp){
        if(index == n ) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int x = 0 , y = 0;
        if(prev==-1 or nums[index]>nums[prev]){
            x = 1 + solve(nums, n, index+1, index,dp);
        }
        y = solve(nums, n, index+1, prev,dp);
        return dp[index][prev+1] = max(x,y);

    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1,-1));
        return solve(nums, nums.size(), 0,-1,dp);
    }
};
