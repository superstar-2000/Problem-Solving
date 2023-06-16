#include<bits/stdc++.h>
using namespace std;


void run() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// [7,3,9,10,1,4]  -> [1,3,4,7,9,10]

void selectionSort(vector<int> &arr) {
	int n = arr.size();
	for(int i = 0; i < n; i++) {
		int idxOfMinValue = i, minVal = arr[i];
		for(int j = i; j < n; j++) {
			if(arr[j] < minVal) {
				minVal = arr[j];
				idxOfMinValue = j;
			}
		}
		swap(arr[i], arr[idxOfMinValue]);
	}
}



int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	selectionSort(arr);
	for(auto ele : arr) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}