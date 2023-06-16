#include<bits/stdc++.h>
using namespace std;

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

void printNTo1(int n) {
	if(n == 0) return;
	cout << n << endl;
	printNTo1(n - 1);
}

int main() {
	run();
	int n;
	cin >> n;
	printNTo1(n);
	return 0;
}