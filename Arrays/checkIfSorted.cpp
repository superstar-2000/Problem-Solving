#include<bits/stdc++.h>
using namespace std;


void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//[1,2,3,4,5]
//[5,4,3,2,1]
//[2,2,2,2,2]
//Returns true if it is sorted in ascending or descending order
bool checkIfSorted(vector<int> &arr) {
	int n = arr.size();
	bool isAsc = false, isDes = false;
	for(int i = 0; i < n - 1; i++) {
		if(arr[i] == arr[i + 1]) continue;
		if(arr[i] < arr[i + 1]) {
			if(isDes) return false;
			isAsc = true;
		} else if(arr[i] > arr[i + 1]){
			if(isAsc) return false;
			isDes = true;
		}

	}
	return true;
}


int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << checkIfSorted(arr);
	return 0;
}