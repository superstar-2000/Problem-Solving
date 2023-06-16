#include<bits/stdc++.h>
using namespace std;


void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


void print1ToN(int n) {
	if(n == 0) return;
	print1ToN(n - 1);
	cout << n << endl;
}


int main() {
	run();
	int n;
	cin >> n;
	print1ToN(n);
	return 0;
}