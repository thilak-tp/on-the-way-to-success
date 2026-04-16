#include<iostream>
#include<climits>
#include<vector>


using namespace std;

// Brute Force Solution - O(N*N)
// iterate through all to get the maxProfit
int maxProfitToBuySellStock1( vector<int> &prices) {
  int maxProfit = 0;
  for(int i=0; i<prices.size(); i++) {
    for(int j=i+1; j<prices.size(); j++) {
      maxProfit = max(maxProfit, prices[j]-prices[i]);
    }
  }
  return maxProfit;
}

// Optimal Solution - O(N)
// Iterate and Store MinPrice and MaxProfits
int maxProfitToBuySellStock2( vector<int> &prices) {
  int minPrice = INT_MAX;
  int maxPro = 0;
  for(int price : prices) {
    minPrice = min(minPrice, price);
    maxPro = max(maxPro, price - minPrice);
  } 
  return maxPro;
}
int main() {
  vector<int> input ={7, 1, 5, 3, 6, 4};
  int ret = maxProfitToBuySellStock2(input);
  cout<<"The maximum profit is "<<ret;
  return 0;
}
