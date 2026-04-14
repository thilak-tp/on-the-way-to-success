#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// Optimal Solution 1 : TC: O(N) SC: O(N)
// Put the values to a set and try to find the range numbers 
// from 1 to N in the set, the numbers that are not found
// are to be appended into the result array
vector<int> findMissingNumbers1( vector<int> &nums) {
  std::unordered_set<int> st(nums.begin(), nums.end());
  vector<int> result;
  int n = nums.size();
  for(int i=1; i<=n; i++) {
    if(st.find(i) == st.end())
      result.push_back(i);
  }
  return result;
}


// Optimal Solution 2 : TC:O(N) SC: O(N)
// Mark the indexs of visited index by marking the values negative
// Go through the array again and the positive valued element indices+1 would be the
// Missing number, add them to the result and return
vector<int> findMissingNumbers2( vector<int> &nums) {
  vector<int> result;
  // Flipping the sign of the element that that is present to negative
  for(int i=0; i<nums.size(); i++) {
    int index = abs(nums[i]) - 1 ;
   if(nums[index] > 0)
    nums[index] = - nums[index]; 
  }

  // After this, the missing numbers will have a postive sign
  for(int i=0; i<nums.size(); i++)
    if(nums[i]>0)
      result.push_back(i+1);

  return result;
      
}
int main() {
  
  vector<int> input ={0,1,2,3,4,5,7,8,10};
  vector<int> ret = findMissingNumbers2(input);
  cout<<"The missing numbers are "<<endl;
  for(int num: ret)
    cout<<num<<"->";
  return 0;
}
