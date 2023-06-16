#include<bits/stdc++.h>
using namespace std;


void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


void printNameNTimes(int n) {
	if(n == 0) return;
	cout << "Atharva" << endl;
	printNameNTimes(n - 1);

}

int main() {
	run();
	int n;
	cin >> n;
	printNameNTimes(n);
	return 0;
}