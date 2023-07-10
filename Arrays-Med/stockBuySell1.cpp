#include<bits/stdc++.h>
using namespace std;

void run() {
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

//TC -> O(N^2)
//Brute force approach -> Try buying at each day and selling at the profit gaining future day
int bestTimeToBuyAndSellStock1(vector<int> &prices) {
	int n = prices.size(), profit = 0;
	for(int i = 0; i < n - 1; i++) {
		int buy = prices[i];
		for(int j = i + 1; j  < n; j++) {
			if(prices[j] > buy) {
				profit = max(profit, prices[j] - buy);
			}
		}
	}
	return profit;
}


//Optimal -> 
int bestTimeToBuyAndSellStock1Fast(vector<int> &prices) {
	int n = prices.size(), profit = 0, minVal = INT_MAX;
	for(int i = 0; i < n; i++) {
		minVal = min(minVal, prices[i]);
		profit = max(profit, prices[i] - minVal);
	}
	return profit;
}

int main() {
	run();
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Total Profit -> " << bestTimeToBuyAndSellStock1(arr) << "\n";
	return 0;
}