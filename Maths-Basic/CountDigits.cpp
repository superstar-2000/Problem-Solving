#include<bits/stdc++.h>
using namespace std;


void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//TC -> O(No Of Digits in n) 
//SC -> O(1)
int countDigits1(int n) {
	int digits = 0;
	while(n) {
		int lastDigit = n % 10;
		n /= 10;
		digits++;
	}
	return digits;
}

// TC - O(1)
// SC - O(1)
int countDigits2(int n) {
	string s = to_string(n);
	return s.length();
}


int countDigits3(int n) {
	int digits = floor(log10(n)) + 1;
	return digits;
}


int main() {
	run();
	int n;
	cin >> n;
	cout << "Total Digits are -> " << countDigits1(n) << endl;
	cout << "Total Digits are -> " << countDigits2(n) << endl; 
	cout << "Total Digits are -> " << countDigits3(n) << endl; 
	return 0;
}