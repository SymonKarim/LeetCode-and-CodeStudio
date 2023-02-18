class Solution {
public:
 int nn;
   void solve(int open, int close,string temp,unordered_set<string>&st){
       if(!open and !close) {
           st.insert(temp);
           return;
       }
       if(open){
           solve( open-1, close, temp+"(",st);
       }
       if(close>open){
           solve( open, close-1,temp+")",st);
       }
   }
    vector<string> generateParenthesis(int n) {
       nn= 2*n;
       unordered_set<string>st;
       vector<string>v;
       solve( n , n, "",st); 
         for (auto itr = st.begin(); itr != st.end(); itr++)
                   v.push_back(*itr);
         return v;
    }
};
