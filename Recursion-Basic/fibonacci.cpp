#include<bits/stdc++.h>
using namespace std;


void run() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// 0 1 1 2 3 5 
// void printFibonacciIterative(int n) {
// 	int secondPrev = 0, prev = 1;
// 	if(n == 0 || n == 1) {
// 		cout << n << endl;
// 		return;
// 	}
// 	cout << secondPrev << endl;
// 	cout << prev << endl;
// 	for(int i = 1; i < n; i++) {
// 		int curr = prev + secondPrev;
// 		secondPrev  = prev;
// 		prev = curr;
// 		cout << curr << endl;
// 	}
// }



void printFibonacci(int n) {	
	


}




//0 1 1 2 3 5 8 12  
int main() {
	run();
	int n;
	cin >> n;
	// printFibonacciIterative(n);
	printFibonacci(n);
	return 0;
}