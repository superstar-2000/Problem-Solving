#include<bits/stdc++.h>
using namespace std;

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//Parameterized Way
void findFactorial(int n, int &fact) {
	if(n == 0) return;
	fact *= n;
	findFactorial(n - 1, fact);
}

//Functional Way
int findFactorialFunctional(int n) {
	if(n == 0) return 1;
	return n * findFactorialFunctional(n - 1);
}

int main() {
	run();
	int n;
	cin >> n;
	int fact = 1;
	// findFactorial(n, fact);
	fact = findFactorialFunctional(n);
	cout << "Factorial is -> " << fact << endl;
	return 0;
}