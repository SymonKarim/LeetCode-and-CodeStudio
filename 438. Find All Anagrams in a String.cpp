class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>needs,windows;
        for(auto i:p) needs[i]++;

        int right = 0 , left = 0 , match =0,sz = s.size(), pz = p.size();
        while(right<sz){
            char ch = s[right];
            if(needs.count(ch)){
                windows[ch]++;
                if(needs[ch]== windows[ch]) match++;
            }
            right++;

            while(match == needs.size()){
                  if(right-left==pz){
                      ans.push_back(left);
                  }
                  char c = s[left];
                  if(needs.count(c)){
                      windows[c]--;
    
                     if(windows[c]<needs[c]) match--;
                  }
                  left++;
            }
        }
        return ans;
    }
};
