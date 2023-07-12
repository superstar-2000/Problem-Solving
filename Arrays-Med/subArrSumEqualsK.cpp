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
   unordered_map<int, int>mp;
   int n = arr.size(), sum = 0, cnt = 0;
   for(int i =  0; i < n; i++) {
      sum += arr[i];
      if(mp.find(sum - k) != mp.end()) {
         cnt += mp[sum - k];
      }
      if(sum == k) {
         cnt += 1;
      }
      mp[sum]++;
   }  
   return cnt;
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