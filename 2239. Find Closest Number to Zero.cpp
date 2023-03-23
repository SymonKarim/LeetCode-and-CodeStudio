class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
       
        for(auto i:nums){
            pq.push({abs(i), i});
        }
        int x = pq.top().first,y=pq.top().second; 
        pq.pop();
        while(x==pq.top().first and pq.size()){
            y = max(y, pq.top().second);
            pq.pop();
        }
        return y;
    }
};
