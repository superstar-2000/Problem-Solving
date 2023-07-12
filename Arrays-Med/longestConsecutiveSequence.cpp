#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

// [1,2,3,4,100,200]
//TC -> O(NLOGN), SC -> O(1)
int longestConsecutive(vector<int>& arr) { 
   int n = arr.size();
   sort(arr.begin(), arr.end());
   int value = arr[0], cnt = 1, ans = 0;
   for(int i = 1; i < n; i++) {
      if(arr[i] == arr[i - 1]) continue;
      if(arr[i] == value + 1) {
         value++;
         cnt++;
      } else {
         value = arr[i];
         ans = max(ans, cnt);
         cnt = 1;
      }
   }
   return ans;
}

//Most Optimal
//At max 2N iterations -> case -> [1,2,3,4,5,6] in set lets say its
// stored -> [6,5,4,3,2,1] (Think :)) 
//TC -> Unordered_Set -> O(N^2) worst case -> Total = O(N) + O(N)
//SC -> O(N)
int longestConsecutiveFast(vector<int>& arr) { 
   int n = arr.size(), ans = 0;
   unordered_set<int>st;
   for(auto it : arr) st.insert(it);
   for(int ele : st) {
      //As ele will not be the starting point as we have smaller ele
      // in the set 
      if(st.find(ele - 1) != st.end()) continue;
      int cnt = 0;
      int val = ele;
      while(st.find(val) != st.end()) {
         cnt++;
         val++;
      }
      ans = max(ans, cnt);
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
   cout << "Length of longestConsecutiveSeq is -> " << longestConsecutive(arr);
	return 0;
}