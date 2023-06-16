#include<bits/stdc++.h>
using namespace std;

void run() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//1 2 3 4 -> 4 / 2 -> 2
//1 2 3   -> 3 / 2 -> 1
void reverseVector(vector<int> &arr, int idx) {
	if(idx >= (arr.size() / 2)) {
		return;
	}
	int otherPairIdx = arr.size() - idx - 1;
	swap(arr[idx], arr[otherPairIdx]);
	reverseVector(arr, idx + 1);
}

int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Vector before reversing" << endl;
	for(auto ele : arr) cout << ele << " ";
	cout << endl;
	reverseVector(arr, 0);
	cout << "Vector after reversing" << endl;
	for(auto ele : arr) cout << ele << " ";
	return 0;
}