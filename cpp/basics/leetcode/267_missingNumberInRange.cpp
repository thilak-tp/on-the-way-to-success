#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;


// BruteForce - NLogN Solution
// Sorting and then checking adjacent elements
int missingNumber1( vector<int> &nums) {
  // Sorting is O(NLogN) Complex
  std::sort(nums.begin(), nums.end());
  int n = nums.size();

  // Check if 0 is missing
    if(nums[0] != 0) return 0;

  // This loop is O(N)
  for(int i=1; i<n; i++) {
    if(!(nums[i] == nums[i-1]+1))
      return nums[i-1]+1;
  }
  return n;
}

// Optimal Solution - O(N)
// Using the sum formula
int missingNumber2( vector<int> &nums) {
  int n = nums.size();
  int actualSum = (n*(n+1))/2;
  int arrSum = 0;  
  
  for(int num: nums)
    arrSum += num;
  
  return (actualSum - arrSum);  
}

// Optimal Solution 2 - O(N)
// Using XOR of all indices, elements and n
int missingNumber3( vector<int> &nums) {
  int xorIndices = 0;
  int xorNumbers = 0;
  for( int i=0; i<nums.size(); i++) {
    xorIndices ^= i;
    xorNumbers ^= nums[i];
  }
  return xorIndices^xorNumbers^nums.size();
}

int main() {
  
  vector<int> input ={0,2,1,3,4};
  int ret = missingNumber3(input);
  cout<<"The missing number is "<<ret;
  return 0;
}
