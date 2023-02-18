class Solution {
public:
    void solve(string digits,vector<string>& v,  unordered_set<string>&st, int index,string temp){
              if(index==-1) {
                  st.insert(temp);
                  return;
              } 
              int dig = digits[index]-'0';
              for(auto i:v[dig]){
                  solve(digits,v,st,index-1,i+temp);
              }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>vecString;
        unordered_set<string>st;
        if(!digits.size()) return vecString;
        vector<string>v = {
            "", "","abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"
            
        };
        solve(digits,v,st,digits.size()-1,"");
         for (auto itr = st.begin(); itr != st.end(); itr++){
             vecString.push_back(*itr);
         }
         return vecString;
    }
};
