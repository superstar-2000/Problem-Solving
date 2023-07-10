#include<bits/stdc++.h>
using namespace std;

void run() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

void merge(vector<int> &arr, int low, int mid, int high) {
	vector<int> temp;
	int left = low;
	int right = mid + 1;

	while(left <= mid && right <= high) {
		if(arr[left] <= arr[right]) {
			temp.push_back(arr[left++]);
		} else {
			temp.push_back(arr[right++]);
		}
	}

	while(left <= mid) {
		temp.push_back(arr[left++]);
	}

	while(right <= high) {
		temp.push_back(arr[right++]);
	}

	//Put the sorted elements(from temp) back to the original array	
	for(int i = low; i <= high; i++) {
		arr[i] = temp[i - low]; 
	}

	// or another way->
	// int k = 0;
	// for(int i = low; i <= high; i++) {
	// 	arr[i] = temp[k++];
	// }

}

//STABLE ALGO -> Maintains the relative order of ele
//TC -> Best - O(N x Log2(n)), Avg - O(N x Log2(n)), Worst - O(N x Log2(n))
//SC -> O(N)
void mergeSort(vector<int> &arr, int low, int high) {
	if(low >= high) return;
	int mid = (low + high) / 2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid + 1, high);
	cout << "Low -> " << low << "Mid -> " << mid << "High -> " << high << endl;	
	merge(arr, low, mid, high);
}

int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int low = 0, high = n - 1;
	mergeSort(arr, low, high);//DIVIDE AND MERGE
	for(auto ele : arr) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}