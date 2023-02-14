class Solution {
public:
    int n = 200,m=200;
    int solve(vector<vector<int>>& grid, int i, int j,vector<vector<int>>&dp){
     if(i==0 and j==0) return grid[0][0];
     if(i<0 or j<0) return 1e6;
    if(dp[i][j] !=-1) return dp[i][j];

      int  x = min(solve(grid, i-1,j,dp),solve(grid, i,j-1,dp))+grid[i][j];
    
      return dp[i][j] =  x;
    }
    int minPathSum(vector<vector<int>>& grid) {
     n = grid.size(), m = grid[0].size();  
     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
     return solve(grid, n-1,m-1,dp);
    }
};
