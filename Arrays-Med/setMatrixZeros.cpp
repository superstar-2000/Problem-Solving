#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//Better Solution
//TC -> O(N * M) + O(N * M)
//SC -> O(N + M)
void setMatrixZeros(vector<vector<int>> &arr) {
   int n = arr.size(), m = arr[0].size();
   vector<int> rows(n, 0), cols(m, 0);

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         if(arr[i][j] == 0) {
            rows[i] = 1;
            cols[j] = 1;
         }
      }
   }

   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; j++) {
         if(rows[i] == 1 || cols[j] == 1) {
            arr[i][j] = 0;
         }
      }
   }

}


void print(vector<vector<int>> &arr) {
   for(auto it : arr) {
      for(auto it2 : it) {
         cout << it2 << " ";
      }
      cout << endl;
   }
}  

// https://leetcode.com/problems/set-matrix-zeroes/solutions/3472518/full-explanation-super-easy-constant-space/
//Best Solution
//TC -> O(N * M) + O(N * M)
//SC -> O(1) 
void setMatrixZerosFast(vector<vector<int>> &arr) {
   int rows = arr.size(), cols = arr[0].size(), col0 = 1;
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
         if(j == 0) {
            if(arr[i][j] == 0) {
               col0 = 0;
               arr[i][0] = 0;
            } 
         } else {
            if(arr[i][j] == 0) {
               arr[i][0] = 0;
               arr[0][j] = 0;
            }
         }
      }
   }
   for(int i = rows - 1; i >= 0; i--) {
      for(int j = cols - 1; j >= 0; j--) {
         //Check for col0 
         if(j == 0) {
            if(col0 == 0) {
               arr[i][j] = 0;
            }
         } else if(arr[i][0] == 0 || arr[0][j] == 0) {
            arr[i][j] = 0;
         }
      }
   }
}


int main() {
	run();
	int n, m;
	cin >> n >> m;
   vector<vector<int>>arr(n, vector<int>(m, 0));
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         cin >> arr[i][j];
      }
   }
   setMatrixZerosFast(arr);
	return 0;
}