class Solution {
   private:
    vector<int> nextSmallerElement(vector<int> &ans,vector<int> &arr, int n)
{
    stack<int>stack;
    stack.push(-1);

    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        while( stack.top() != -1 and arr[stack.top()]>=curr){
                stack.pop();
            }
            ans[i] = stack.top();
            stack.push(i);
            
        }
    return ans;
}
   vector<int> prevSmallerElement(vector<int> &ans,vector<int> &arr, int n)
{
    stack<int>stack;
    stack.push(-1);

    for(int i=0;i<n;i++){
        int curr = arr[i];
        while(stack.top()!=-1 and arr[stack.top()]>=curr){
                stack.pop();
            }
            ans[i] = stack.top();
            stack.push(i);         
        }
    return ans;
}
  int solve(vector<int>& nums){
        int n = nums.size();
        vector<int>ans(n);
        vector<int> next(n),prev(n);
        next = nextSmallerElement(ans,nums, n);
        prev = prevSmallerElement(ans,nums, n);
       int mx = INT_MIN;
       for(int i=0;i<nums.size();i++){
          int left = nums[i];
           if(next[i]==-1) {
               next[i] = nums.size();
           } 
           int right = next[i]-prev[i]-1;
           int ans = left*right;
           mx = max(mx, ans);
       }
       return mx;
  }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
       vector<vector<int>>ans(matrix.size(), vector<int>(matrix[0].size(),0));

       for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[0].size();j++){
               if(matrix[i][j]=='1') ans[i][j] = 1;
           }
       }
       int mx = solve(ans[0]);
       for(int i=1;i<matrix.size();i++){
           for(int j=0;j<matrix[0].size();j++){
               if(ans[i][j]>0) ans[i][j] += ans[i-1][j];
               else ans[i][j] = 0;
           }
           mx = max(mx, solve(ans[i]));
       }
       return mx;
    }
    
};
