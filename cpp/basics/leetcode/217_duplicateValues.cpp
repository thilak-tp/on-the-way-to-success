#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

// Brute Force - O(N*N) Solution
// Comparing all the numbers with all the numbers
bool duplicateValue1( vector<int> &nums) {
  for(int i=0; i<nums.size(); i++){
    for( int j=i+1; j<nums.size(); j++)
    {
      if(nums[i] == nums[j])
        return true;
    }
  }
  return false;
}

// Better Solution - O(N*LogN) 
// We sort the array onces and compare adjacent elements
bool duplicateValue2( vector<int> &nums ){
  std::sort(nums.begin(), nums.end());
  for(int i=1; i<nums.size(); i++)
    if(nums[i] == nums[i-1])
      return true;  
   return false;
}


// Optimal Solution - O(N)
// We populate the elements into an unordered set 
// Compare the sizes of the input array and the set
// If the size match, no duplicates else there are duplicates
bool duplicateValue3( vector<int> &nums) {
  std::unordered_set<int> st;
  for(int num: nums)
    st.insert(num);
  if(nums.size() == st.size())
    return false;
  return true;
}

int main() {
 
  // Toggle to change the inputs from duplicates to non-duplicates
  bool duplicateFlag = false; 
  vector<int> input = duplicateFlag?vector<int>{1,2,2,3,4,5,5,6,7,8}:vector<int>{1,2,3,4,5,6,7,8};

  if(duplicateValue3(input))
    cout<<"There exists duplicates";
  else 
    cout<<"There are no duplicates";

  return 0;
}
