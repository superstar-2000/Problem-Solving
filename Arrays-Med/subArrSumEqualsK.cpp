#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//TC -> O(N*N) (Worst) / O(1) -> Best + Avg -> Unordered Map
//O(NLOGN) -> Ordered Map
//SC -> O(N) 
int subarraySum(vector<int>& arr, int k) {
   unordered_map<int, int> mp;
   int n = nums.size(), sum = 0, ans = 0;
   mp[0] = 1;
   for(int i = 0; i < n; i++) {
      sum += nums[i];
      if(mp.find(sum - k) != mp.end()) {
         ans += mp[sum - k];
      }
      mp[sum]++;
   }   
   return ans;
}


int main() {
	run();
	int n, k;
   cin >> n >> k;
   vector<int> arr(n, 0);
   for(int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   cout << subarraySum(arr, k);
   
   return 0;
}