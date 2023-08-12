#include<bits/stdc++.h>
using namespace std;

// 900

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// 1 -> 0
// 2 -> 1
// 3 -> 2
// 4 -> 2
// 1 2 3 4 
   // 0 1 2 2
int BS(int low, int high, int mx, int x,int y) {

	int ans = -1;
	while(low <= high) {
		int mid = (low + (high - low) / 2);
		int val = (mid * x) / 2;
		if(val == mx) {
			ans = mid;
			high = mid - 1;
		} else if(val > mx) {
			mx = val;
			ans = mid;
			low = mid + 1;
		} else if(val == mx) {
			ans = mid;
			high = mid - 1;
		}
	}
	if(mx == 0) return 0;
	return ans;

}

// 1 2 3 4 
int sumOfSavedMoney(int n,int x,int y, int arr[]) {

	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += arr[i] - BS(1, arr[i], INT_MIN,x, y);
	}

	return ans;

}



int main() {
	run();
	int n;
	cin >> n;
	int x,y;
	cin >> x >> y;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << sumOfSavedMoney(n, x, y, arr);
	return 0;
}