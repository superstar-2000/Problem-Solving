#include<bits/stdc++.h>
using namespace std;


void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//KADANE'S ALGORITHM -> 

int maximumSubarraySumOptimal(vector<int> &arr) {
 	int mx = arr[0], sum = arr[0];
   int n = arr.size();

   for(int i = 1; i < n; i++) {
      if(sum < 0) sum = 0;
      sum += arr[i];
      mx = max(mx, sum);  
   }
   return mx;
}

long long maximumSubarraySumOptimalEasier(vector<int> &arr) {
 	long long maxi = LONG_MIN; // maximum sum
   long long sum = 0;
   int n = arr.size();
   for (int i = 0; i < n; i++) {
      sum += arr[i];
      if (sum > maxi) {
         maxi = sum;
      }
      // If sum < 0: discard the sum calculated
      if (sum < 0) {
         sum = 0;
      }
   }
    // To consider the sum of the empty subarray
    // uncomment the following check:
    //if (maxi < 0) maxi = 0;
    return maxi;
}


int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << maximumSubarraySumOptimal(arr);
	return 0;
}