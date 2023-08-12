#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//Most Optimal
vector<int> findMajorityElement2(vector<int> &arr) {
   vector<int> res;
   int n = arr.size(), cnt1 = 0, cnt2 = 0, ele1 = INT_MIN,ele2 = INT_MIN;
   for(int i = 0; i < n; i++) {
      if(cnt1 == 0 && ele2 != arr[i]) {
         ele1 = arr[i];
         cnt1 = 1;
      } else if(cnt2 == 0 && ele1 != arr[i]) {
         ele2 = arr[i];
         cnt2 = 1;
      } else if(ele1 == arr[i]) {
         cnt1++;
      } else if(ele2 == arr[i]) {
         cnt2++;
      } else {
         cnt1--;cnt2--;
      }
   }
   cnt1 = 0, cnt2 = 0;
   for(int i = 0; i < n; i++) {
      if(ele1 == arr[i]) cnt1++;
      if(ele2 == arr[i]) cnt2++;
   }
   if(cnt1 > (n / 3)) {
      res.push_back(ele1);
   }
   if(cnt2 > (n / 3)) {
      res.push_back(ele2);
   }
   return res;
}  

int main() {
	run();
	int n;
   cin >> n;
   vector<int> arr(n, 0);
   for(int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   findMajorityElement2(arr);
 	return 0;
}