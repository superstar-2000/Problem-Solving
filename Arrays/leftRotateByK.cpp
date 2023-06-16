#include<bits/stdc++.h>
using namespace std;

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
// [1,2,3,4,5,6,7], k = 3
//Approach 1 ->
// TC -> O(N - K) + O(K) + O(N)
//SC -> O(N)
int leftRotateByK1(vector<int> &arr, int k) {
    int n = arr.size();

    //K might be greater than size of the array
    k %= n;
    vector<int> temp;

    //Rotate by K
    
    //Put last k elements into array
    for(int i = n - k; i < n; i++) {
        temp.push_back(arr[i]);
    }

    //Put first  n - k elements into the array
    for(int i = 0; i < n - k; i++) {
        temp.push_back(arr[i]);
    }

    //Just print rotated arr temp 
    for(auto ele : temp) {
        cout << ele << " ";
    }
    cout << endl;
}

//Approach2 -> TLE
//TC -> O(K * N)
//SC -> O(1)
int leftRotateByK2(vector<int> &arr, int k) {
    int n = arr.size();

    //K might be greater than size of the array
    k %= n;

    for(int i = 0; i < k; i++) {
        int lastEle = arr[n - 1];
        for(int j = n - 2; j >= 0; j--) {
            arr[j + 1] = arr[j];
        }
        arr[0] = lastEle;
    }   
    
    //Rotated Array is
    for(auto it : arr) {
        cout << it << " ";
    }
    cout << endl;
}

//[4,3,2,1,7,6,5]
//MOST OPTIMAL
//TC -> O(N), SC -> O(1)
int leftRotateByK3(vector<int> &arr, int k) {
    int n = arr.size();
    //K might be greater than size of the array
    k %= n;    
    reverse(arr.begin() + n - k, arr.end());
    reverse(arr.begin(), arr.begin() + n - k);
    reverse(arr.begin(), arr.end()); 
}

int main() {
    run();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
     leftRotateByK2(arr, k);
    return 0;
}