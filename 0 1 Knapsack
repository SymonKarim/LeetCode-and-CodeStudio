#include <bits/stdc++.h> 

int solve(vector<int>& weight, vector<int>& value, int index, int capacity,
 vector<vector<int>>&dp){
	 if(index ==0){
		 if(capacity-weight[0]>=0)  return value[0]; 
		 else return 0;
	 }
	 if(dp[index][capacity]!=-1) return dp[index][capacity];
	 int a=0,b=0;
	 if(weight[index]<=capacity)
	    a = value[index]+ solve(weight,value,index-1, capacity-weight[index],dp);
	    
	 b = 0+solve(weight,value,index-1, capacity,dp);
	return dp[index][capacity] = max(a,b);
	 
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n+5, vector<int>(maxWeight+5,-1));
	int ans = solve(weight,value,n-1,maxWeight,dp);
	return ans;
}
