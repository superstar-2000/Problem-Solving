#include<bits/stdc++.h>
using namespace std;

void run() {
	#ifndef ONLINE_JUDGE
   	freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
}


//  0     low - 1   low      mid - 1   mid       high             high + 1      n-1
// [0,0,0, 0      ,  1,1,1,1, 1,      (0,1,2'S UNSORTED)            2,      2,2,2]


// [0.....low - 1] -> 0 (extreme left)
// [low......mid - 1] -> 1
// [high + 1......n - 1] -> 2(extreme right)

// AS PER OBS -> MID - HIGH IS UNSORTED ELSE EVERYTHING FROM (0 -> MID - 1) AND (HIGH + 1 -> N - 1) IS SORTED
void sortColoursOptimal(vector<int> &arr) {
	int n = arr.size();
	int low = 0, high = n - 1, mid = 0;
	//DNF ALGORITHM
	while(mid <= high) {
		if(arr[mid] == 0) {
			swap(arr[mid], arr[low]);
			mid++;low++;
		} else if(arr[mid] == 1) {
			mid++;
		} else {
			swap(arr[mid], arr[high]);
			high--;
		}
	}
}


int main() {
	run();
	int n, target;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sortColours(arr);
	return 0;
}