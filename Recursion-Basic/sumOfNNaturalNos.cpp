#include<bits/stdc++.h>
using namespace std;

void run() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//Parameterized Way
void sumOfNNaturalNumbers(int n, int &sum) {
	if(n == 0) return;
	sum += n;	
	sumOfNNaturalNumbers(n - 1, sum);	
}


//Functional Way
int sumOfNNaturalNumbersFunctional(int n) {
	if(n == 0) return 0;
	return n + sumOfNNaturalNumbersFunctional(n - 1);
}


int main() {
	run();
	int n;
	cin >> n;
	int sum = 0;
	// sumOfNNaturalNumbers(n, sum);
	sum = sumOfNNaturalNumbersFunctional(n);
	cout << "Sum is " << sum << endl;
	return 0;
}