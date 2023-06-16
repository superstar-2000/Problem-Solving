#include<bits/stdc++.h>
using namespace std;


void run() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

void bubbleSortRecursive(vector<int> &arr, int idx)	 {
	if(idx >= arr.size()) return;
	for(int i = 0; i < arr.size() - idx - 1; i++) {
		if(arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
		}
	}
	bubbleSortRecursive(arr, idx + 1);
}
	

int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int idx = 0;
	bubbleSortRecursive(arr, idx);
	for(auto ele : arr) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}