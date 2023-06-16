#include<bits/stdc++.h>
using namespace std;



void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// [1,3,12,0,0]
// [1,2,3,4,1,0]
    
// [0,1,0,3,12]
// [1,2,3,4,0,1]

void moveZeros(vector<int> &arr) {
    int n = arr.size();
    int i = 0, j = 1;

    while(j < n && i < n) {

        //Move left pointer until we get a zero val 
        while(i < n && arr[i] != 0) i++;

        //Move right pointer until we get a non-zero val
        while(j < n && arr[j] == 0) j++;

        if(j <= i) {
            j = i + 1;
        } else {
            //j > i
            swap(arr[i], arr[j]);
            i++;j++;
        }

    }
}

int main() {
    run();
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    moveZeros(arr);
    for(auto ele :  arr) cout << ele << " ";
    cout << endl;
    return 0;
}