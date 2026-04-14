#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Brute Force - O(N*N) Solution
// Checking each element
vector<int> twoSum1( vector<int> &nums, int target) {
  for(int i=0; i<nums.size(); i++)
    for(int j=i+1; j<nums.size(); j++) {
      if(nums[i] + nums[j] == target){
        return {i,j};
      }
    }
  return {};
}

// Optimal Solution - Using HashMap - O(N) Solution
vector<int> twoSum2( vector<int> &nums, int target) {
  unordered_map<int, int> mpp;
  for(int i=0; i<nums.size(); i++) {
    int comp = target - nums[i];
    if(mpp.count(comp)) {
       return {mpp[comp], i};
    }
    mpp[nums[i]] = i;
  }
  return {};
}

int main() {
  vector<int> input = {1,2,3,4,5,6};
  int num = 6;
  vector<int> result = twoSum2(input, num);
  cout<<"Result:"<<endl;
  for(int num: result)
    cout<<num<<"->";
  return 0;
}
