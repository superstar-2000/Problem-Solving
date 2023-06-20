#include<bits/stdc++.h>
using namespace std;

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


//TC -> O(N * N), SC -> O(1)
vector<int> twoSumBrute(vector<int> &arr, int target) {
	int n = arr.size();
	vector<int>ans;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(arr[i] + arr[j] == target) {
				ans.push_back(i);
				ans.push_back(j);
				break;
			}
		}
	}
	return ans;
}


//TC -> O(N * 1) -> UNORDERED (N2 IN WORST CASE THOUGH)
//   -> O(N * LOGN) -> MAP
//SC -> O(N) 
vector<int> twoSumOptimal(vector<int> &arr, int target) {
	int n = arr.size();
	unordered_map<int, int> mp;
	vector<int>ans;
	for(int i = 0; i < n; i++) {
		if(mp.find(target - arr[i]) != mp.end()) {
			ans.push_back(mp[target - arr[i]]);
			ans.push_back(i);
		}
		mp[arr[i]] = i;
	}	
	return ans;
}


//TC -> O(N * LOGN) + O(N) ->
vector<int> twoSumBetter(vector<int> &arr, int target) {
	vector<pair<int, int>> vpp;
	int n = arr.size();
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		vpp.push_back({arr[i], i});
	}

	sort(vpp.begin(), vpp.end());
	int i = 0, j = n - 1;

	while(i < j) {
		int sum = vpp[i].first + vpp[j].first;

		if(sum == target) {
			ans.push_back(vpp[i].second);
			ans.push_back(vpp[j].second);
			break;
		} else if(sum > target) {
			j--;
		} else i++;
	}
	return ans;
}


int main() {
	run();
	int n, target;
	cin >> n >> target;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> ans = twoSum(arr, target);

	cout << "Indexs -> " << " i -> " << ans[0] << " j -> " << ans[1] << endl; 
	return 0;
}