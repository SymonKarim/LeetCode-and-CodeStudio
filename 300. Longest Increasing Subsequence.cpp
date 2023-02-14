
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
    int solveTabular(vector<int>& nums){
        int n = nums.size(),mx = 1;
        vector<int>dp(n+1,0);

         for(int i=0;i<n;i++){
             dp[i] =1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
                mx = max(dp[i],mx);
            }
         }
         return mx;
    }
    int lengthOfLIS(vector<int>& nums) {
     //   vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1,-1));
      //  return solve(nums, nums.size(), 0,-1,dp);
       return solveTabular(nums);
    }
};
