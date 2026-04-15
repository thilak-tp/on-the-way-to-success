#include<iostream>
#include<vector>
using namespace std;

// Optimal Solution - O(M*N)
// We shrink the matrix from each side after we take the elements out

vector<int> spiralMatrix( vector<vector<int>> &matrix) {
  vector<int> result;
  int m = matrix.size();
  int n = matrix[0].size();
  int top = 0, bottom = m-1;
  int left = 0, right = n-1;

  while( top <= bottom && left <= right) {
    // Traverse from left to right
    for(int j=left; j<=right; j++) {
      result.push_back(matrix[top][j]);
    }
    top++;
    
    // Traverse from top to bottom 
    for(int i=top; i<=bottom; i++) {
      result.push_back(matrix[i][right]);
    }
    right--;
    // Traverse from right to left
    for(int j=right; j>=left; j--) {
      result.push_back(matrix[bottom][j]);
    }
    bottom--;
    //Traverse from bottom to top
    for( int i=bottom; i>=top ; i--) {
      result.push_back(matrix[i][left]);
    }
    left++;
    
  }
  return result;
}

int main() {
  
  vector<vector<int>> input = {{1,2,3},{4,5,6},{7,8,9}};
  vector<int> result = spiralMatrix(input);
  cout<<"The result is :"<<endl;
  for(int num: result)
    cout<<num<<"->"; 


  return 0;
}
