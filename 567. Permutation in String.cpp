class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>needs,window;
        for(char c = 'a'; c<='z';c++){
            needs[c]=0;
            window[c]=0;
        }
        for(auto i:s1) needs[i]++;
        int right = 0 , left =0 , match =0,pz= s1.size(),sz = s2.size();
       for(int i=0;i<sz;i++){
           if(i<=pz-1) window[s2[i]]++;
           else{
               window[s2[i]]++;
               window[s2[i-pz]]--;
           }
           if(needs==window) return true;
       }

        return false;
    }
};
