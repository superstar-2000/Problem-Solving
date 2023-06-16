#include<bits/stdc++.h>
using namespace std;


void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// mx = 8, sMax = 1
// mx = 2, sMax = 2
// Cases to take care of
//[2, 2, 2, 2, 2, 2]
//[1, 8, 4, 6, 2, 10]
//[1,1,1,1,4]
//[4,4,4,4,1]
//Optimal -> TC -> O(N), SC -> O(1)
// int findSecondLargest(vector<int> &arr) {
// 	int n = arr.size();
// 	if(n <= 1) return -1;
// 	int largest = max(arr[0], arr[1]);
// 	int secondLargest = min(arr[0], arr[1]);

// 	for(int i = 2; i < n; i++) {
// 	    if(secondLargest == largest) secondLargest = -1;
// 		if(arr[i] > largest) {
// 			secondLargest = largest;
// 			largest = arr[i];
// 		} else if(arr[i] > secondLargest && largest != arr[i]) {
// 			secondLargest = arr[i];
// 		}
// 	}
	
// 	if(largest == secondLargest) return -1;
// 	return secondLargest;
// }

int findSecondLargestEasy(vector<int> &arr) {
	int n = arr.size();
	if(n <= 1) return -1;
	int largest = arr[0], secondLargest = INT_MIN;

	for(int i = 1; i < n; i++) {
		 if(largest == arr[i]) continue;
		 if(arr[i] > largest) {
		 	secondLargest = largest;
		 	largest = arr[i];
		 } else if(arr[i] > secondLargest){
		 	secondLargest = arr[i];
		 } 
	}
	return secondLargest;
}


int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// int secondLargestEle = findSecondLargest(arr);
	int secondLargestEle = findSecondLargestEasy(arr);
	cout << secondLargestEle << endl;

	return 0;
}