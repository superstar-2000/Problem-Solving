#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//2 1 5 4 3 0 0 
void nextPermutation(vector<int> &arr) {
	next_permutation(arr.begin(), arr.end());
}


//TC -> O(2N) 
//SC -> O(1)
void nextPermutation(vector<int>& arr) {
  	int n = arr.size();
   int idx1 = -1;

   //Find the breakpoint
   for(int i = n - 1; i > 0; i--) {
      if(arr[i] > arr[i - 1]) {
      	idx1 = i - 1;
         break;
      }
   }

   if(idx1 == -1) {
      reverse(arr.begin(), arr.end());
      return;
   }
   
   //Find a value which is just greater than current pivot (idx1)
   for(int i = n - 1; i > idx1; i--) {
      if(arr[i] > arr[idx1]) {
         swap(arr[idx1], arr[i]);
         break;
      }
   }

   reverse(arr.begin() + idx1 + 1, arr.end());
}


int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	nextPermutation(arr);
	return 0;
}