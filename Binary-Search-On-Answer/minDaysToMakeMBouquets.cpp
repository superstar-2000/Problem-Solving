
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

bool canBouquetsBeMade(vector<int> &arr, int m,int k, int day) {
    int n = arr.size(), totalPossibleBouquets = 0,cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] <= day) {
            cnt++;
        } 
        if(cnt >= k) {
            totalPossibleBouquets++;
            cnt = 0;
        }
        if(arr[i] > day) {
            cnt = 0;
        }
    }
    
    if(totalPossibleBouquets >= m) return true;
    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size(),low = 1, high = *max_element(bloomDay.begin(),
    bloomDay.end()), ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canBouquetsBeMade(bloomDay, m, k, mid)) {
            ans = mid;
            cout << ans << endl;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
	run();
	int m,k,n;
	cin >> n >> m >> k;
    vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
        cub >> arr[i];
    }
    cout << minDays(arr, m, k);
	return 0;
}
