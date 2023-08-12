#include<bits/stdc++.h>
using namespace std;


void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//TC -> O(N) + O(N), SC -> O(1)
void findMajorityElementOptimal(vector<int> &arr) {
	int majorityElement = 0, cnt = 0,n = arr.size();
	for(int i = 0; i < n; i++) {
		if(cnt == 0) {
			majorityElement = arr[i];
			cnt = 1;
		} else if(majorityElement == arr[i]) {
			 cnt++;
		} else cnt--;
	}
	cnt = 0;
	//Clarify this que -> Not to be done if the array has the majority ele
	for(int i = 0; i < n; i++) {
		if(arr[i] == ele) cnt++;
		if(cnt > (n / 2)) return ele;
	}
	//majority ele doesnt exist
	return -1;
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