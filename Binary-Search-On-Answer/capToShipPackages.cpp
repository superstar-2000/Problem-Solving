
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

bool isAValidWeightedConveyerBelt(vector<int> &arr, int conveyerWeight, int days) {
    int n = arr.size(), requiredDays = 0, currWeight = 0;
    for(int i = 0; i < n; i++) {
        currWeight += arr[i];
        if(currWeight > conveyerWeight) {
            requiredDays++;
            currWeight = arr[i];
        }
    }  
    if(currWeight <= conveyerWeight) requiredDays++;
    return (requiredDays <= days);
}


int shipWithinDays(vector<int>& weights, int days) {
   int n = weights.size(), low = *max_element(weights.begin(), weights.end()),
   high = accumulate(weights.begin(), weights.end(), 0), ans = 0;
   while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isAValidWeightedConveyerBelt(weights, mid, days)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
   }
   return ans;
}

int main() {
    run();
    int n,threshold;
    cin >> n >> threshold;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << smallestDivisor(arr, threshold);
    return 0;
}
