#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
   vector<int> res;
   int rows = matrix.size(), cols = matrix[0].size();
   int startRow = 0, startCol = 0, endRow = rows - 1,endCol = cols - 1;
   while(startRow <= endRow && startCol <= endCol) {
      for(int i = startCol; i <= endCol; i++) {
            res.push_back(matrix[startRow][i]);
      }
      startRow++;
      if(startRow > endRow) break;
      for(int i = startRow; i <= endRow; i++) {
            res.push_back(matrix[i][endCol]);
      }   
      endCol--;
      if(startCol > endCol) break;
      for(int i = endCol; i >= startCol; i--) {
            res.push_back(matrix[endRow][i]);
      }
      endRow--;
      if(startRow > endRow) break;
      for(int i = endRow; i >= startRow; i--) {
            res.push_back(matrix[i][startCol]);
      }
      startCol++;
   }
   return res;
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
   vector<int> result = spiralOrder(arr);
   cout << "Spiral Traversal -> \n";
	for(auto it : result) {
      cout << it << " ";
   }
   return 0;
}