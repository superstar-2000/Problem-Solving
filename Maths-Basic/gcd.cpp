#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-greatest-common-divisor-of-array/

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//Brute Force Approach
int GCD1(int a, int b) {
	int gcd = 1;
	if(a == 0) return b;
	if(b == 0) return a;
	for(int i = 2; i <=  min(a, b); ++i) {
		if(a % i == 0 && b % i == 0) gcd = i;
	}
	return gcd;
}

//6 -> 1, 2, 3, 6 
//12 -> 1, 2, 3, 4, 6, 12
// gcd(a,b) = gcd(a - b, b)
//better -> gcd(a, b) = gcd(a % b, b )
int GCD2(int a, int b) {
	if(a == 0) return b;
	return GCD2(a % b, a);
}


int GCD2Iterative(int a, int b) {
	while(a > 0 && b > 0) {
		if(a > b) a = a % b;
		else b = b % a;
	}
	if(a == 0) return b;
	if(b == 0) return a;
}


int main() {
	run();
	int n;
	cin >> n;
	vector<int>arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int mn = *min_element(arr.begin(), arr.end());
	int mx = *max_element(arr.begin(), arr.end());
	cout << "GCD FOR 2 numbers are a -> " << GCD1(mn, mx) << endl;
	cout << "GCD FOR 2 numbers are b -> " << GCD2(mn, mx) << endl;
	cout << "GCD FOR 2 numbers are b -> " << GCD2Iterative(mn, mx) << endl;
	return 0;
}