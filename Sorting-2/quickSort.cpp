#include<bits/stdc++.h>
using namespace std;

//The Idea -> 
  // [Ele less than / equal to pivot] pivot [Ele greater than pivot]


//partition Algorithm -> 
// 1)Take two pointers one on low and other on high (i and j)
// 2)Move I / Left till you find an ele that is greater than pivot (as it will
// go to the right portion of eventually after swapping)
// 3)Move J / Right till you find an ele that is smaller than pivot (as it will
// go to the right portion of eventually after swapping)
// 4)Swap those arr[i] and arr[j] if they haven't crossed each other
// 5)At the end when both of them have crossed each other right pointer
// (that points to the smallest element) has to be swapped with pivot 
// 6) Return the pivot Index (right index) 

void run() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


int findPivot(vector<int> &arr, int low, int high) {

	int pivot = arr[low];

	int left = low, right = high;

	while(left <= right) {

		//move left until you have an ele which is > than pivot
		while(left <= right && arr[left] <= pivot) {
			left++;
		}

		//move right pointer until you havw an ele which is < than pivot
		while(left <= right && arr[right] >= pivot) {
			right--;
		}

		if(left <= right) {
			swap(arr[left], arr[right]);
		}
	}

	swap(arr[right], arr[low]);
	//right is where the pivot is placed now after swapping
	return right;
}


//UNSTABLE ALGO -> Does not maintain the relative order of ele
// BEST CASE -> O(N x Log2(n)), AVG CASE -> O(N x Log2(n))
// WORST CASE -> O(N^2)
//SC -> O(1) (no external space as merge sort) -> only recursion stack space
void quickSort(vector<int> &arr, int low, int high) {
	if(low >= high) return;
	int pivotIndex = findPivot(arr, low, high);
	quickSort(arr, low, pivotIndex - 1);
	quickSort(arr, pivotIndex + 1, high);
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
	quickSort(arr, low, high);//Divide And Conquer
	for(auto ele : arr) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}