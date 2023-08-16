
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

bool isValidDivisor(vector<int> &arr, int threshold, int divisor) {
    int n = arr.size(), sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i] / divisor + (arr[i] % divisor != 0);
    }
    if(sum <= threshold) return true;
    return false;
}


int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size(), low = 1, high = *max_element(nums.begin(), 
    nums.end()), ans = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isValidDivisor(nums, threshold, mid)) {
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
