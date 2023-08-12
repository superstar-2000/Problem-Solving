#include<bits/stdc++.h>
using namespace std;

//find min in a rotated sorted array

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// TC -> O(LogN) -> Unique elements (for duplicates there will be change)
int minInARotatedSortedArray(vector<int> &arr, int &target) {
	int n = arr.size(), low = 0, high = n - 1,ans = INT_MAX;

	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(arr[low] <= arr[mid]) {
			//left portion is sorted (min ele is arr[low])
			ans = min(ans, arr[low]);
			low = mid + 1;
		} else {
			//right portion is sorted
			// (min ele is arr[mid] so eleminate the right half)
			ans = min(ans, arr[mid]);
			high = mid - 1;
		}
	}
	return ans;
}

// TC -> O(LogN) -> Duplicate elements 
int minInARotatedSortedArray(vector<int> &arr, int &target) {
	int n = arr.size(), low = 0, high = n - 1,ans = INT_MAX;

	while(low <= high) {
		int mid = low + (high - low) / 2;
		//first 3 checks ensures that all elements are unique(min 3 elements needed)
		if(low != high && high != mid && mid != low && arr[low] == arr[mid] & arr[mid] == arr[high]) {
            low += 1;
            high -= 1;
            continue;
      }
		if(arr[low] <= arr[mid]) {
			//left portion is sorted (min ele is arr[low])
			ans = min(ans, arr[low]);
			low = mid + 1;
		} else {
			//right portion is sorted
			// (min ele is arr[mid] so eleminate the right half)
			ans = min(ans, arr[mid]);
			high = mid - 1;
		}
	}
	return ans;
}


int main() {
	run();
	int n,target;
	cin >> n >> target;
	vector<int>arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cout << minInARotatedSortedArray(arr, target);
	return 0;
}