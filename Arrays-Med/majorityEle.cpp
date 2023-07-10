#include<bits/stdc++.h>
using namespace std;


void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//TC -> O(N), SC -> O(1)
void findMajorityElementOptimal(vector<int> &arr) {
	int majorityElement = 0, cnt = 0;
	for(int i = 0; i < n; i++) {
		if(cnt == 0) {
			majorityElement = arr[i];
			cnt = 1;
		} else {
			if(majorityElement == arr[i]) cnt++;
			else cnt--;
		}
	}
	return majorityElement;
}


int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	findMajorityElement(arr);
	return 0;
}