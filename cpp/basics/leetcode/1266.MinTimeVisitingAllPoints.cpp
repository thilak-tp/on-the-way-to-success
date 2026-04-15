#include<iostream>
#include<vector>


using namespace std;

// Optimal Solution : O(N) Solution
int minTimeVisitingAllPoints( vector<vector<int>> &points) {
  int resultTime = 0;
  int n = points.size();
  
  for(int i=1; i<n; i++) {
    int dx = abs(points[i][0] - points[i-1][0]);
    int dy = abs(points[i][1] - points[i-1][1]);
    resultTime += max(dx, dy);
  }
  return resultTime;
}

int main() {
  vector<vector<int>> input ={{1,1},{3,4},{-1,0}};
  int ret = minTimeVisitingAllPoints(input);
  cout<<"The minimum time taken is "<<ret;
  return 0;
}
