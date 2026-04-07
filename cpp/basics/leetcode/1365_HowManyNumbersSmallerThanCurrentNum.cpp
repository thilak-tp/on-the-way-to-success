#include<iostream>
#include<vector>

using namespace std;

// Brute Forced Solution
vector<int> smalledNumberThanCurrent( vector<int> &nums)  {
  std::vector<int> res;
  for(auto it: nums) {
    int count = 0;
    for(int i=1; i<nums.size(); i++) {
      if(nums[i] < it)
        count++;  
    }
    res.emplace_back(count);
  }
  return res;
  
}

int main() {

  vector<int> input = {6,2,1,4,4,6,7};

  cout<<"Input: ";
  for(auto it: input)
    cout<<it<<"->";
  cout<<endl;

  vector<int> res = smalledNumberThanCurrent(input);
  cout<<"Output: ";
  for(auto it: res)
    std::cout<<it<<"->";
}
