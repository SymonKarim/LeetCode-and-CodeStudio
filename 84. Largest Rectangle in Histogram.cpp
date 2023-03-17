class Solution {
    private:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans(n);
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
   vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans(n);
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
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n),prev(n);
        next = nextSmallerElement(heights, n);
        prev = prevSmallerElement(heights, n);
       int mx = INT_MIN;
       for(int i=0;i<heights.size();i++){
          int left = heights[i];
           if(next[i]==-1) {
               next[i] = heights.size();
           } 
           int right = next[i]-prev[i]-1;
           int ans = left*right;
           mx = max(mx, ans);
       }
       return mx;
    }
};
