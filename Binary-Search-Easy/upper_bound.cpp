#include<bits/stdc++.h>
using namespace std;


//Implement Upper Bound in c++ -> 
// The upper_bound() method in C++ is used to return an 
// iterator pointing to the first element in the range
// [first, last) which has a value > target



//IF all elements are < target -> returns an iter to end

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


vector<int>::iterator implementUpperBound(vector<int> &arr, int target) {
	int idx = -1, n = arr.size(), low = 0, high = n - 1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(arr[mid] <= target) {
			low = mid + 1;
		} else if(arr[mid] > target) {
			idx = mid;
			high = mid - 1;
		}
	}
	if(idx == -1) return arr.end();
	return (arr.begin() + idx);
}


int main() {
	run();
	int n,target;
	cin >> n >> target;
	vector<int>arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	vector<int>::iterator iter = implementUpperBound(arr, target);
	if(iter == arr.end()) {
		cout << "All values are less than or some val is equal to target";
	} else {
		cout << "Upper bound is -> " << *iter;
	}
	return 0;
}