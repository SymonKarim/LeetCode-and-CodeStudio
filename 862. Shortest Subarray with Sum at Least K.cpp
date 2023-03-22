class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long start = 0 , end = 0 ,  sum = 0, n = nums.size(), maxLength = nums.size()+1;
       deque<pair<long long,long long>>dq;
       for(long long i=0;i<n;i++){
           sum+=(1ll*nums[i]);
           if(sum>=k){
               maxLength = min(maxLength,i+1);
           }
        while(dq.size() and sum-dq.front().first>=k){
             maxLength = min(maxLength,i-dq.front().second);
             dq.pop_front();
        }
        while(dq.size() and dq.back().first>=sum) dq.pop_back();
         dq.push_back({sum,i});

       }
        if(maxLength==n+1) return -1;
        return maxLength;
    }
};
