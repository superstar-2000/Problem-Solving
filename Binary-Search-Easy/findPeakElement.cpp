#include<bits/stdc++.h>
using namespace std;

// Find peak element (prev ele < ele > next ele) 
//https://leetcode.com/problems/find-peak-element/description/

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//understand using graph very intuitive
//Return idx of peak elements (note that there could be mult peak elements)
// (return an idx of any of them)
//Logic -> Draw graph and analyse as its easy(CONSIDER WE ONLY HAVE 1 PEAK)
//There can be 3 cases ->
// 1)mid lies on peak element -> return it 
// 2) mid lies on left half (increasing slope(curr ele > ele[curr_idx - 1]) (go to right)) -> ELiminate left half
// 3) mid lies on right half(decreasing slope(curr ele < ele[curr_idx - 1]))) (go to left) -> ELiminate right half
 
//FOR MULTPLE PEAKS SAME LOGIC JUST TAKE CARE OF THE VALLEY -> PREV_ELE > (CURR ELE) < NEXT_ELE 
 int findPeakElement(vector<int>& arr) {
    int n = arr.size(), low = 1, high = n - 2;
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n - 1] > arr[n - 2]) return n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
        if(arr[mid - 1] < arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

int main() {
	run();
	int n,target;
	cin >> n >> target;
	vector<int>arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
    sort(arr.begin(), arr.end());
    cout << findPeakElement(arr);
	return 0;
}