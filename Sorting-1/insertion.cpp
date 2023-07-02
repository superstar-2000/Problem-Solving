#include<bits/stdc++.h>
using namespace std;

void run() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//Stable Algorithm -> Maintains the relative order(equal keys(Stability))
// TC -> Best Case - O(N), Avg Case - O(N^2), Worst Case - O(N^2)
void insertionSort(vector<int> &arr) {
	int n = arr.size();
	for(int i = 1; i < n; i++) {
		int j = i;
		while(j > 0 && arr[j - 1] > arr[j]) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
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
	insertionSort(arr);
	for(auto ele : arr) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}