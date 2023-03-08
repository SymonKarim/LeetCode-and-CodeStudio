bool isPossible(vector<int> &stalls, int &k,   int &mid){
  int last = stalls[0],cnt = 1;

   for(int i=0;i<stalls.size();i++){
       if(stalls[i]-last>=mid){
           cnt++; 
           if(cnt == k) return true;
           last = stalls[i];
       } 
   }
   return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
     sort(stalls.begin(),stalls.end());
     int s = 0 ,mid, e, mx = -1,ans= -1;

    for(auto i :stalls){
         mx = max(mx, i);
    }
    e= mx;
    mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(stalls, k, mid)){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
