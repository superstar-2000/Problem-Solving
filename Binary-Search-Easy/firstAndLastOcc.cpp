#include<bits/stdc++.h>
using namespace std;

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(2, -1);
        if(n == 0) return {-1, -1};
        auto firstOcc = lower_bound(nums.begin(), nums.end(), target);
        if(firstOcc == nums.end()) res[0] = -1;
        else if(target == nums[firstOcc - nums.begin()]) res[0] = firstOcc - nums.begin();
        auto lastOcc = upper_bound(nums.begin(), nums.end(), target);
        if(lastOcc - nums.begin() == 0 || (lastOcc == nums.end() && nums[n - 1] != target)) {
            res[1] = -1;
        } else if(target == nums[(lastOcc - nums.begin()) - 1]){
            res[1] = (lastOcc - nums.begin()) - 1;
        }   
        return res;
}


int main() {
	run();
	int n,target;
	cin >> n >> target;
	vector<int>arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}	
	vector<int> res = searchRange(arr , target);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}