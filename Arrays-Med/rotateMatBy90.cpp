#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

void rotateBy90(vector<vector<int>>& matrix) {
   int rows = matrix.size(), cols = matrix[0].size();

   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
            if(i == j) break;
            swap(matrix[i][j], matrix[j][i]);
      }
   }

   for(int i = 0; i < rows; i++) {
      reverse(matrix[i].begin(), matrix[i].end());
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
   
   rotateBy90(arr);
	return 0;
}