#include<bits/stdc++.h>
using namespace std;

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int findFirstOcc(vector<int> &arr, int target) {
    int n = arr.size(), low = 0, high = n - 1,idx = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            idx = mid;
            high = mid - 1;
        } else if(arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return idx;
}

int findLastOcc(vector<int> &arr, int target) {
    int n = arr.size(), low = 0, high = n - 1,idx = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            idx = mid;
            low = mid + 1;
        } else if(arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return idx;
}

//Optimal -> O(LOGN) + O(LOGN)
//[4, 4, 8, 8, 8, 15, 16, 23, 23, 42], t = 8
int findOccOfTarget(vector<int> &arr, int target) {
    int firstOccIdx = findFirstOcc(arr, target);
    int lastOccIdx = findLastOcc(arr, target);
    // cout << "First -> " << firstOccIdx << " lastOccIdx -> " << lastOccIdx << endl;
    if(firstOccIdx == -1) return 0;
    int n = arr.size();
    if(lastOccIdx != n) {
        return lastOccIdx - firstOccIdx + 1;
    } 
    return lastOccIdx - firstOccIdx;
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
    cout << findOccOfTarget(arr, target);
	return 0;
}