#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// Time -  O(Digits) / O(Log(n) -> means no of digits) -> One and the same thing
//Space - O(1)
bool isPalindrome(int n) {
	int temp = n;
	int reversedNumber = 0;
	while(temp) {
		int lastDigit = temp % 10;
		temp /= 10;
		reversedNumber = (reversedNumber * 10) + lastDigit;
	} 
	return reversedNumber == n;
}


int main() {
	run();
	int n;
	cin >> n;
	isPalindrome(n) ? cout << "Palindrome \n" : cout << "Not a Palindrome \n"; 
	return 0;
}