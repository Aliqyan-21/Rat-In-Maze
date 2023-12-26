#include <iostream>
#include <vector>
using namespace std;

inline bool isSafe(int n, int x, int y, vector<vector<int>> mat, vector<vector<int>> visited){
  // three conditions we have check for
  // 1. inside the matrix
  // 2. should not be already visited
  // 3. input matrix == 1, i.e. not be blocked
  return ((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y] == 0) && (mat[x][y] == 1)) ? true : false;
}

void findPath(int n, vector<vector<int>> mat, int x, int y, vector<vector<int>> visited, string path, vector<string> &ans){
  // base case
  if(x == n-1 && y == n-1){
    ans.push_back(path);
    return;
  }

  visited[x][y] = 1;

  // 4 choices we have D, L, R, U

  // down
  int newx = x+1;
  int newy = y;
  if(isSafe(n, newx, newy, mat, visited)){
    path.push_back('D');
    findPath(n, mat, newx, newy, visited, path, ans);
    path.pop_back();
  }

  // left
  newx = x;
  newy = y-1;
  if(isSafe(n, newx, newy, mat, visited)){
    path.push_back('L');
    findPath(n, mat, newx, newy, visited, path, ans);
    path.pop_back();
  }

  // right
  newx = x;
  newy = y+1;
  if(isSafe(n, newx, newy, mat, visited)){
    path.push_back('R');
    findPath(n, mat, newx, newy, visited, path, ans);
    path.pop_back();
  }

  // up
  newx = x-1;
  newy = y;
  if(isSafe(n, newx, newy, mat, visited)){
    path.push_back('U');
    findPath(n, mat, newx, newy, visited, path, ans);
    path.pop_back();
  }

  visited[x][y] == 0; 
}

int main(){
  int n=4;
  vector<vector<int>> mat = {
    {1,0,0,0},
    {1,1,0,1},
    {1,1,0,0},
    {0,1,1,1}
  };
  // vector<vector<int>> mat = {
  //   {1,0,1,1,1},
  //   {1,1,1,0,1},
  //   {1,0,0,1,1},
  //   {1,0,0,1,0},
  //   {1,0,0,1,1}
  // };

  int x = 0;
  int y = 0;

  vector<vector<int>> visited(n, vector<int>(n, 0));
  string path;
  vector<string> ans;

  findPath(n, mat, x, y, visited, path, ans);

  for(string i : ans){
    cout << i << endl;
  }

  return 0;
}
