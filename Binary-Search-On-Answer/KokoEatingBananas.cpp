
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/koko-eating-bananas//

void run(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

bool checkForSpeed(vector<int> &piles, int k, int hours) {
    long long n = piles.size(), hoursRequiredForSpeedK = 0;
    for(int i = 0; i < n; i++) {
        if(piles[i] <= k) {
            hoursRequiredForSpeedK++;
        } else {
            hoursRequiredForSpeedK += (piles[i] / k) + (piles[i] % k != 0);
        }
    }
    if(hoursRequiredForSpeedK > hours) return false;
    return true;
}


//O(Log(max_element in piles) * piles.length()) 
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size(), low = 1, high = *max_element(piles.begin(), piles.end()), ans = 0;        
    while(low <= high) {
        int mid = low + (high - low) / 2;
        //Check whether speed of eating "mid" no of bananas is enough for koko for an hour
        if(checkForSpeed(piles, mid, h)) {
            //koko will be able to eat "mid" bananas within k hours 
            //this could be a possible answer so store it 
            //We need min value of k so decreasee 
            ans = mid;
            high = mid - 1;
        } else {
            //need to increase the no of bananas eaten as she wasn't able to finish within k hours
            low = mid + 1;
        }
    }
    return ans;
}


int main() {
	run();
	int n;
	cin >> n;
	vector<int>piles(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> piles[i];
	}
	cout << "Min Value of Bananas that Koko Should eat inorder to escape safely withing h hours eating all bananas is -> " + minEatingSpeed(n);
	return 0;
}
