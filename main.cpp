#include <iostream>
#include <vector>
#include "pathFinder.h"
using namespace std;

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
