#include<bits/stdc++.h>
using namespace std;

// Search in a Rotated Sorted Array - 1 (Arr can contain duplicates)
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//Optimal -> TC -> O(N / 2)(Worst case) 
//SC -> O(1)
int searchInRotatedSortedArrayWithDuplicates(vector<int>& arr, int target) {
    int n = arr.size(), low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + (high - low) / 2);
        if(arr[mid] == target) return mid;

        //Just add a case
        if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        if(arr[low] <= arr[mid]) {
            //left portion is sorted so add condition for left part
            if(target >= arr[low] && target <= arr[mid]) {
                high = mid - 1;
            } else low = mid + 1;
        } else {
            //right portion is sorted so add condition for right part
            if(target >= arr[mid] && target <= arr[high]) {
                low = mid + 1;
            } else high = mid - 1;
        }
    }
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
    sort(arr.begin(), arr.end());
    searchInRotatedSortedArray(arr, target);
	return 0;
}