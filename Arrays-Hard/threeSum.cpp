
#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//BRUTE
//Tc -> O(N^3 * (3 * total_triplets * Log(TotalTriplets)))
//Sc -> O(total_triplets)
vector<vector<int>> ThreeSum(vector<int> &nums) {
	int n = nums.size();
	vector<vector<int>> res;
    set<vector<int>>st;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            vector<int> vec(3, 0);
            for(int k = j + 1; k < n; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vec[0] = nums[i];
                    vec[1] = nums[j];
                    vec[2] = nums[k];
                    sort(vec.begin(), vec.end());
                    if(st.find(vec) == st.end()) {
                        st.insert(vec);
                        res.push_back(vec);
                    }
                }     
            }
        }
    }
    return res;
}



//BRUTE
//Tc -> O(N^2 * LOGN)
//Sc -> O(total_triplets)
vector<vector<int>> ThreeSumBetter(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> res;
    set<vector<int>>st;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++) {
        int j = i + 1, k = n - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            } else if(sum > 0) {
                k--;
            } else {
                vector<int> vec(3, 0);
                vec[0] = nums[i];
                vec[1] = nums[j];
                vec[2] = nums[k];
                sort(vec.begin(), vec.end());
                if(st.find(vec) == st.end()) {
                    st.insert(vec);
                    res.push_back(vec);
                }
            }
        }
    }
    return res;
}


//OPTIMAL
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        int j = i + 1, k = n - 1;
        if(i - 1 >= 0) {
            if(nums[i] == nums[i - 1]) continue;
        }
        while(j < k) {
            while(j < k && nums[j - 1] == nums[j]) j++;
            while(k > j && nums[k] == nums[k + 1]) k--;
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            } else if(sum > 0) {
                k--;
            } else {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;k--;
            }
        }
    }
    return ans;
}

int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// 3SumBetter(arr);
    vector<int> a2{1,2,3,4,10};
    cout << *lower_bound(a2.begin(), a2.end(), 5);
	return 0;
}