#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>&arr, int n, int K) {
	sort(arr.begin(), arr.end());
   vector<vector<int>>ans;
   set<vector<int>>st;
   vector<int>temp(3);
	for(int i=0;i<arr.size()-2;i++){
		int left = i+1, right = n-1;
		while(left<right){
			if(arr[i] + arr[left]  + arr[right]  == K){
				st.insert({arr[i], arr[left], arr[right]});
				left++,right--;
			}
			else if(arr[i] + arr[left]  +arr[right]  >K){
				right--;
			}else{
				left++;
			}
		}
	} 
	for(auto i:st){
		ans.push_back(i);
	}
		return ans;
	

}
