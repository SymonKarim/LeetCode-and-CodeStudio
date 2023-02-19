class Solution {
public:
    void solve(vector<int>& candidates, int const target,  vector<vector<int>>&v,int index,vector<int>&temp){
        if(target == 0){
            v.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }
        if(index >=candidates.size()) return;
        solve(candidates, target, v,index+1,temp);
        temp.push_back(candidates[index]);
        solve(candidates, target-candidates[index], v,index, temp);
        temp.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>temp;
        solve(candidates, target, v,0,temp);
        return v;
    }
};
