#include<bits/stdc++.h>
using namespace std;


void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


int findSecondSmallest(vector<int> &arr) {
	int n = arr.size();
	if(n <= 1) return -1;
	int smallest = arr[0], secondSmallest = INT_MAX;

	for(int i = 1; i < n; i++) {
		if(arr[i] == smallest) continue;
		if(arr[i] < smallest) {
			secondSmallest = smallest;
			smallest = arr[i];
		} else if(arr[i] < secondSmallest){
			//arr[i] > smallest
			secondSmallest = arr[i];
		}
	}
	
 	return secondSmallest;
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
	int secondSmallestEle = findSecondSmallest(arr);
	cout << secondSmallestEle << endl;

	return 0;
}