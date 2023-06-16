#include<bits/stdc++.h>
using namespace std;

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//TC -> O(N^3)
int longestSubArrWithSumKBrute(vector<int> &arr, int k) {
	int n = arr.size(), longestLength = 0;	
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int sum = 0;
			for(int k = i; k <= j; k++) {
				sum += arr[k];
			}
			if(sum == k) {
				longestLength = max(longestLength, j - i + 1);
			}
		}
	}
	return longestLength;
} 

int longestSubArrWithSumKBetter(vector<int> &arr, int k) {
	int n = arr.size(), longestLength = 0;	
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += arr[j];//running sum for subarr i...j
			if(sum == k) {
				longestLength = max(longestLength, j - i + 1);
			}
		}
	}
	return longestLength;
} 

// [1,7,3,5,8,9,2]
int longestSubArrWithSumKOptimal(vector<int> &arr, int k) {
	int n = arr.size(), mx = 0;
	int i = 0, j = 0, sum = 0;

	while(j < n) {


		while(j < n && sum <= k) {
			sum += arr[j];
			if(sum == k) mx = max(mx, j - i + 1);
			j++;
		}
		
		while(i < j && sum > k) {
			sum -= arr[i];
			i++;
		}

		i--;
		if(sum == k) {
			mx = max(mx, j - i + 1);
		}


	}

	return mx;
} 	



int main() {
	run();
	int n, k;
	cin >> n >> k;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	// cout << longestSubArrWithSumKBrute(arr, k);
	// cout << longestSubArrWithSumKBetter(arr, k);
	cout << longestSubArrWithSumKOptimal(arr, k);
	return 0;
}