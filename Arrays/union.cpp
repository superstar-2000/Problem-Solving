#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int findUnion(vector<int> &arr1,vector<int> &arr2) {
    int n = arr1.size(), m = arr2.size();
    vector<int>Union;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            Union.push_back(arr1[i++]);
        } else if(arr2[j] < arr1[i]) {
            Union.push_back(arr2[j++]);
        } else {
            Union.push_back(arr1[i++]);
        }
        while(i < n && arr1[i] == Union.back()) i++;
        while(j < m && arr2[j] == Union.back()) j++;
    }

    while(i < n) {
        if(Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }

    while(j < m) {
        if(Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }

    return Union.size();
}


//Works if you only want the count of union elements
int findUnionWithoutExtraUnionArray(vector<int> &arr1, vector<int> &arr2) {
    int i = 0, j = 0;
    int lastEle = 0;//maintain last ele instead of entire array
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
           lastEle = arr1[i++];
        //   Union.push_back(arr1[i++]);
        } else if(arr2[j] < arr1[i]) {
            lastEle = arr2[j++];
            // Union.push_back(arr2[j++]);
        } else {
            lastEle = arr1[i++];
            // Union.push_back(arr1[i++]);
        }
        // while(i < n && arr1[i] == Union.back()) i++;
        // while(j < m && arr2[j] == Union.back()) j++;
        while(i < n && arr1[i] == lastEle) i++;
        while(j < m && arr2[j] == lastEle) j++;
        ans++;
    }

    while(i < n) {
        if(lastEle != arr1[i]) {
            lastEle = arr1[i];
            ans++;
        }
        // if(Union.back() != arr1[i])
        //     Union.push_back(arr1[i]);
        i++;
    }

    while(j < m) {
        if(lastEle != arr2[j]) {
            lastEle = arr2[j];
            ans++;
        }
        // if(Union.back() != arr2[j])
        //     Union.push_back(arr2[j]);
        j++;
    }

    // return Union.size();
    return ans;
}


int main() {
    run();
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr1(n1, 0), arr2(n2, 0);

    for(int i = 0; i < n1; ++i) {
        cin >> arr1[i];
    }

    for(int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    int unionCount1 = findUnion(arr1, arr2);
    int unionCount2 = findUnionWithoutExtraUnionArray(arr1, arr2);
    cout << "unionCount -> " << unionCount << endl;
    return 0;
}