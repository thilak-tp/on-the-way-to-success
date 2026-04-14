#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

// Brute Forced Solution - O(N*N) Solution
vector<int> smallerNumberThanCurrent1( vector<int> &nums)  {
  // We have to count the smaller elements than the given element for each element in the array.
  vector<int> result;
  for(int i=0; i<nums.size(); i++) {
    int count = 0;
    for(int j=1; j<nums.size(); j++) {
      if(nums[i] > nums[j]) {
        count++;
      }
    }
    result.push_back(count);
  }
  return result;
}

// Better Solution - O(NLOGN) Solution
// Sort and then add first occurence of the element to a map
// for the result find the value for each element in the input array from the map
vector<int> smallerNumberThanCurrent2( vector<int> &nums) {
  vector<int> sortedNums = nums;
  // Sort
  sort(sortedNums.begin(), sortedNums.end());  

  // Note first occurence into a map
  unordered_map<int, int> mpp;
  for(int i=0; i<sortedNums.size(); i++) {
    if(mpp.find(sortedNums[i]) == mpp.end())
      mpp[sortedNums[i]] = i;
  }

  // Build the result array
  vector<int> result; 
  for(int num: nums) {
    result.push_back(mpp[num]);
  }

  return result;
}

// Optimal Solution - O(N) - Counting Sort
// Since the range is from 0 to 100, we can count the occurences

vector<int> smallerNumberThanCurrent3(vector<int> &nums) {
  // To keep track of frequencies of the numbers from 0 to 100
  vector<int> freq(101, 0);
 
  // Store the frequencies of each element in the input array 
  for(int num: nums) {
    freq[num]++;
  }

  // Prefix Sum
  for(int i=1; i<=100; i++) {
    freq[i] += freq[i-1];
  }

  // Build result
  vector<int> result(nums.size());
  for(int i=0; i<nums.size(); i++) {
    if(nums[i] == 0)
      result[i] = 0;
    else {
      result[i] = freq[nums[i] - 1];
    }
  }
  
  return result;
}

int main() {

  vector<int> input = {6,2,1,4,4,6,7};
  int target = 4;
  cout<<"Input: ";
  for(auto it: input)
    cout<<it<<"->";
  cout<<endl;

  vector<int> res = smallerNumberThanCurrent3(input);
  cout<<"Output: ";
  for(int num: res)
    std::cout<<num<<"->";
}
