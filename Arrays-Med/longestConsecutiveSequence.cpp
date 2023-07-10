#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// [1,2,3,4,100,200]
int longestConsecutive(vector<int>& arr) { 
   int n = arr.size();
   sort(arr.begin(), arr.end());
   int value = arr[0], cnt = 1, ans = 0;

   for(int  i = 1; i < n; i++) {
      if(arr[i] == value + 1) {
         value++;
         cnt++;
      } else {
         value = arr[i];
         ans = max(ans, cnt);
         cnt = 1;
      }
   }
   ans = max(ans, cnt);
   return ans;

}


int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	} 
   cout << "Length of longestConsecutiveSeq is -> " << longestConsecutive(arr);
	return 0;
}