#include<bits/stdc++.h>
using namespace std;


void run() {
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

//Hashing
//edge case -> [2, 0, 0, 3], k = 3
// prefixSum = 5
//try to get (prefixSum - k) as left as possible to get max
// len 
//TC -> O(N * LOGN) -> NORMAL MAP(ORDERED)
//   -> O(N * N) -> UNORDERED_MAP
//SC -> O(N)
//MOST OPTIMAL IF ARRAY CONTAINS ALL NEG, POS, 0S
int longestSubArrWithSumKBetter(vector<int> &arr, int k) {
	unordered_map<long long, int> mp;
	int n = arr.size(),ans = 0;
	long long prefixSum = 0;
	for(int i = 0; i < n; i++) {
		prefixSum += arr[i];
		if(prefixSum == k) {
			ans = max(ans, i + 1);
		} else {
			//check whether prefixSum - k exists previously (means currently
			// we have k as the sum off curr sub array)
			int preSum = prefixSum - k;
			if(mp.find(preSum) != mp.end()) {
				ans = max(ans, i - mp[preSum]);
			}
		}
		//REMEMBER TO ADD THIS CHECK (EDGE CASES)
		if(mp.find(prefixSum) == mp.end())
			mp[prefixSum] = i;
	}
	
	return ans;
} 


// [1,7,3,5,8,9,2]
//For negatives in an array you cannot use this solution 
int longestSubArrWithSumKOptimal(vector<int> &arr, int k) {
	int n = arr.size();
	int left = 0, right = -1;
	long long sum = 0;
	int maxLen = 0;
	while(right < n) {
		right++;
		if(right < n) sum += arr[right];
		else break;
		if(sum == k) {
			maxLen = max(maxLen, right - left + 1);
			cout << "Sum == k \n" << "Right -> " << right << " Left -> " << left << endl;
		} else if(sum > k) {
			while(left <= right && sum > k) {
				sum -= arr[left];
				left++;
			}
			if(sum == k) {
				cout << "Sum > k \n" << "Right -> " << right << " Left -> " << left << endl;
				maxLen = max(maxLen, right - left + 1);
			}
		} 
	}
	return maxLen;
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