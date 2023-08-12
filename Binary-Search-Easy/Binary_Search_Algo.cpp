#include<bits/stdc++.h>
using namespace std;


//Implement Binary Search -> 
// https://leetcode.com/problems/binary-search/

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


int search(vector<int>& arr, int target) {
	int low = 0, high = arr.size() - 1;
	while(low <= high) {
		int mid = (low + (high - low) / 2);
		if(arr[mid] == target) {
			return mid;
		} else if(arr[mid] > target) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	//Target not present
	return -1;
}


int main() {
	run();
	int n,target;
	cin >> n >> target;
	vector<int>arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << (search(arr, target) >= 0 ?  "Found" :"Not Found");
	return 0;
}