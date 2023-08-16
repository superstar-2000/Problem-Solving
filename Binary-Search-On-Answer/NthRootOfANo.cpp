#include<bits/stdc++.h>
using namespace std;

//Given a number m and n find nth root of m of the number 
// ex -> m = 9, n = 3 -> op = 3 
   // -> m = 9, n = 4  -> op = -1(doesnt exist)

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//returns -1 -> If the (mid)^n > m(handled in binary search function)
//else returns ans; 
int midToN(int mid, int n, int m) {
	long long ans = 1;
	
	for(int i = 1; i <= n; i++) {
		ans = ans * mid;
		if(ans > m) return -1;
	}

	return (int)ans;
}


// m to the power (1 / n) -> nth root of m
// int findNthRootBrute(int m, int n) {
// 	for(int i = 1; i <= m; ++i) {
// 		int iToN = f(i, n, m);
// 		if(iToN == m) {
// 			return i;
// 		} else if(iToN > m) {
// 			break;
// 		}
// 	}
// }



// Time Complexity ->  O(Log(m) * n)
// -> you can do this in O(Log(m) * (Log(n))) -> Binary Exponentiation
int findNthRootFast(int m, int n) {
	int low = 1, high = m;
	while(low <= high) {
		int mid = low + (high - low) / 2; 
		int midToN = f(mid, n, m)
		if(midToN == m) {
			return mid;
		} else if(midToN == -1) {
			//-1 -> indicates that its greater tham m
			high = mid - 1;
		} else if(midToN < m) {
			low = mid + 1;
		}
	}
	return -1;
}



int main() {
	run();
	int n;
	cin >> n;
	cout << findNthRoot(n);
	return 0;
}