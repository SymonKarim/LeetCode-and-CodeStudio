#include <bits/stdc++.h>

int solve(vector<int>&arr, int index,int prev, int n,vector<vector<int>>&dp){
    if(index>=n) return 0;
    if(dp[index][prev+1]!=-1) return dp[index][prev+1];
    int x = 0,y=0;
    if(prev==-1 or (arr[index]< arr[prev])){
        x = 1+solve(arr, index+1, index, n,dp);
    }
    y = solve(arr, index+1, prev, n,dp);
    
    return dp[index][prev+1]=max(x,y);
}
 int solveTabular(vector<int>& nums){
        int n = nums.size(),mx = 1;
        vector<int>dp(n+1,0);

         for(int i=0;i<n;i++){
             dp[i] =1;
            for(int j=0;j<i;j++){
                if(nums[i]<nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
                mx = max(dp[i],mx);
            }
         }
         return mx;
    }
int LDS(vector<int>&arr){
    //  vector<vector<int>>dp(arr.size()+1, vector<int>(arr.size()+1,-1));
    //  return solve(arr,0,-1,arr.size(),dp);
    return solveTabular(arr);
}
