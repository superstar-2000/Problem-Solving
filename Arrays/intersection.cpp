#include<bits/stdc++.h>
using namespace std;



void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}


vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int i = 0, j = 0;
    vector<int> ans;
    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            i++; 
        } else if(arr1[i] > arr2[j]) {
            j++; 
        } else {
            ans.push_back(arr1[i]);
            i++;j++;
            while(i < n1 && arr1[i - 1] == arr1[i]) i++;
            while(j < n2 && arr2[j - 1] == arr2[j]) j++;
        }
    }   

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

    vector<int> intersection = findIntersection(arr1, arr2);
    cout << "Intersection is -> ";
    for(auto it : intersection) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}