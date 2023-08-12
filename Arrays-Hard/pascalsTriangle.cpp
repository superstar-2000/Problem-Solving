#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

}


//Type1 -> 
// Given row and col, find the value at that
// row and col in pascals triangle 
// Formula -> (r - 1)C
//                    (c - 1)

// ->  n C r = (n - r)! / r! x (n - r)!
   // optimization  -> 
   // NCR = 5C3 = 5x4x(3x2x1) / (3x2x1)(2 x 1) -> (5 x 4)
      // -> NCR = nC(n-r) -> 5C3 = 5C2 = (5 x 4) / (2 x 1)
//TC -> O(r), SC -> O(1)
//r = 5, c = 3
// (4 - 1) C (3 - 1) -> (3) C (2)
int pascalsTriangleType1(int r, int  c) {
   long long ans = 1;
   r = r - 1,c = c - 1;
   for(int  i = 0; i < r; i++) {
      ans *= (r - i);
      ans /= (i + 1);
   }
   return ans;
}

//Type2 -> 
//Print any row of the pascals triangle given n
//ex -> N = 5, print -> 1 4 6 4 1
//Refer ss from notes folder
// TC -> O(N),SC -> O(1)
int pascalsTriangleType2(int n) {
   int ans = 1;
   int row = n;
   for(int col = 0; col < n; ++col) {
      if(col == 0 || col == n - 1) {
         cout << 1 << " ";
      } else { 
         ans *= (row - col);
         ans /= col;
         cout << ans << " ";
      }
   }
}



// CHECK STRIVERS VIDEO FOR MOST OPTIMAL

//TC -> O(N^2), SC -> O(1)
void pascalsTriangleType3(int numRows) {
   vector<vector<int>> ans;
   vector<int>first(1, 1);
   ans.push_back(first);
   for(int i = 2; i <= numRows; i++) {
      vector<int>curr(i, 1);
         for(int j = 0; j < ans.back().size() - 1; j++) {
            curr[j + 1] = ans.back()[j] + ans.back()[j + 1];
      }
      ans.push_back(curr);
   }
   //Printing the pascals triangle
   for(auto vec : ans) {
      for(auto ele : vec) {
         cout << ele << " ";
      }
      cout << endl;
   }  
}


int main() {
	run();
	// int numRows;
   // cin >> numRows;
   // pascalsTriangleType3(numRows);
   int n;
   cin >> n;
   pascalsTriangleType2(n);
	return 0;
}