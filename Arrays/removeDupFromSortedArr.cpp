#include<bits/stdc++.h>
using namespace std;


void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    for(int j = 1; j < n; j++) {
        if(arr[j] != arr[i]) {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}


int main() {
    run();
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << removeDuplicates(arr) << endl;
    return 0;
}