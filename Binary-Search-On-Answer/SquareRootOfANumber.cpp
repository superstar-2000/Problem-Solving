#include<bits/stdc++.h>
using namespace std;

//Given a number n find sqrt of the number 
// ex -> 25 -> op = 5 
   // -> 7  -> op = 2
void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// TC -> O(LOGN), SC -> O(1)
int findSqrt(int n) {
	int low = 1, high = n, ans = -1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if((mid * mid) > n) {
			high = mid - 1;
		} else {
			ans = mid;
			low = mid + 1;
		}
	}
	return ans;
}


int main() {
	run();
	int n;
	cin >> n;
	cout << findSqrt(n);
	return 0;
}