class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<int> >mp;
      for(int i=0;i<strs.size();i++){
          string s = strs[i];
          sort(s.begin(), s.end());
          mp[s].push_back(i);
      }
      vector<vector<string>>ans;
      for(auto i:mp){
          vector<string>sv;
          for(int j:i.second) sv.push_back(strs[j]);
          ans.push_back(sv);
      }
    
      return ans;
    }
};
