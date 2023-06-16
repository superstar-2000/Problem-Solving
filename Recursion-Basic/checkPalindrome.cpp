#include<bits/stdc++.h>
using namespace std;

void run() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//Functional Way
bool checkPalindrome(string s, int idx) {
	if(idx >= s.length() / 2) return true;
	int secondIndex = s.length() - idx - 1;
	if(s[idx] != s[secondIndex]) return false;
	return checkPalindrome(s, idx + 1);
}


int main() {
	run();
	string s;
	cin >> s;
	int idx = 0;
	if(checkPalindrome(s, idx)) {
		cout << "isPalindrome" << endl;
	} else cout << "Not a Palindrome" << endl;
	return 0;
}