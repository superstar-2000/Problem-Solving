#include<bits/stdc++.h>
using namespace std;

// Search in a Rotated Sorted Array - 1 (Arr can contain duplicates)
// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
       // 0 1 2 3 4 5 6 7 8
// C1 -> [1,1,2,2,3,4,4,5,5] --> e o e o ans o e o e 
// Logic ->  Check for e o pattern for elimination
// [even, odd] -> (ele lies on right) -> ELIMINATE LEFT PART 
// [odd, even] -> (ele lies on left) -> ELIMINATE RIGHT PART 
int singleElementInSortedArr(vector<int> &arr, int target) {
    int n = arr.size(), low = 0, high = n - 2;
    if(n == 1) return arr[0];
    //Check for 1st and last ele as u dont have to cover many edge 
    //cases in actual algorithm
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n - 1] != arr[n - 2]) return arr[n - 1];

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid];
        }

        //even odd case (eliminate left half)
        if((mid % 2 != 0 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && 
            arr[mid] == arr[mid + 1])) {
            low = mid + 1;
        }  else {
            high = mid - 1;
        }   
        //Easy way to write the same 
         // if(arr[mid] == arr[mid - 1]) {
    //         if(mid % 2 == 0) {
    //             high = mid - 1;
    //         } else {
    //             low = mid + 1;
    //         }

    //     } else if(arr[mid] == arr[mid + 1]) {
    //         if(mid % 2 == 0) {
    //             low = mid + 1;
    //         } else {
    //             high = mid - 1;
    //         }
    //     }
    }
    return 0;

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
    cout << singleElementInSortedArr(arr, target);
	return 0;
}