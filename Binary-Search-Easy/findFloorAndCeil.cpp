#include<bits/stdc++.h>
using namespace std;

//Floor -> Greatest val <= target 
// ex ->  target = 0
// arr -> 1 2 4 5 6 9, t = 5 -> floor = 5
// arr -> 1 2 4 6 9 , t = 5-> floor = 4
// arr -> 1 2 3 4 5, t = 0 -> floor = -1


//Ceil -> Smallest val >= target (Lower Bound)
//ex -> 
// arr -> 1 2 4 5 6 9, t = 5 -> ceil = 5
// arr -> 1 2 4 6 9 , t = 5-> ceil = 6
// arr -> 1 2 3 4 5, t = 6 -> ceil = -1


void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int findFloor(vector<int> &arr, int target) {
	int low = 0, high = arr.size() - 1, floor = -1;

	while(low <= high) {
		int mid = (low + (high - low) / 2);
		if(arr[mid] == target) return mid;
		if(arr[mid] < target) {
			floor = mid;
			low = mid + 1;
		} else if(arr[mid] > target) {
			high = mid - 1;
		}
	}
	return floor;
}

int findCeil(vector<int> &arr, int target) {
	int low = 0, high = arr.size() - 1, Ceil = -1;
	while(low <= high) {
		int mid = (low + (high - low) / 2);
		if(arr[mid] == target) return mid;
		if(arr[mid] < target) {
			low = mid + 1;
		} else if(arr[mid] > target) {
			Ceil = mid;
			high = mid - 1;
		}
	}
	return Ceil;
}


int main() {
	run();
	int n,target;
	cin >> n >> target;
	vector<int>arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Floor for -> " << target << " is at idx-> " << findFloor(arr, target);
	cout << "Ceil for -> "  << target << " is at idx-> " << findCeil(arr, target);
	return 0;
}