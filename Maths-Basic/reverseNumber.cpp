#include<bits/stdc++.h>
using namespace std;


void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}



//Most optimal in 1 pass 
//TC - O(digits)
//SC - O(1)
int reverseNumber(int n) {
	int reversedNumber = 0;
	while(n) {
		int lastDigit = n % 10;
		reversedNumber = (reversedNumber * 10) + lastDigit;
	}	n /= 10;
	return reversedNumber;
}


int main() {
	run();
	int n;
	cin >> n;
	cout << "ReversedNumber is -> " << reverseNumber(n) << endl;
	return 0;
}