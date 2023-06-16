#include<bits/stdc++.h>
using namespace std;


void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//Brute -> TC - O(N)
void printDivisors(int n) {
	for(int i = 1; i <= n; i++) {
		if(n % i == 0) cout << i << "\n";
	}
}

//Most Optimal
// TC - O(sqrt(N))
void printDivisorsFast(int n) {
	//same as i <= sqrt(n) -> after squaring both sides
	for(int i = 1; i * i <= n; i++) {
		int divisorPairSecondHalf = (n / i);
		int divisorPairFirstHalf = i;
		//Print the value in the first half
		if(n % divisorPairFirstHalf == 0) {
			cout << i << endl;
		}
		if(divisorPairSecondHalf != i && n % divisorPairSecondHalf == 0) {
			cout << divisorPairSecondHalf << endl;
		} 
	}
}

int main() {
	run();
	int n;
	cin >> n;
	printDivisorsFast(n);
	return 0;
}