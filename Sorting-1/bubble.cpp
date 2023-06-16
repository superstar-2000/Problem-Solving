#include<bits/stdc++.h>
using namespace std;


void run() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//TC -> Best Case - O(N), Avg Case - O(N^2), Worst Case - O(N^2)
//Stable Algorithm -> relative order of elements is maintained
void bubbleSort(vector<int> &arr) {
	int n = arr.size();
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}

}


void bubbleSortFast(vector<int> &arr) {
	int n = arr.size();
	for(int i = 0; i < n; i++) {
		bool isNotSwapped = true;
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				isNotSwapped = false;
				swap(arr[j], arr[j + 1]);
			}
		}
		if(isNotSwapped) return;
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
	bubbleSortFast(arr);
	for(auto ele : arr) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}