#include <iostream>
#include <vector>
#include "pathFinder.h"
using namespace std;

int main(){
  int n=10;
  // vector<vector<int>> mat = {
  //   {1,0,0,0},
  //   {1,1,0,1},
  //   {1,1,0,0},
  //   {0,1,1,1}
  // };
  // vector<vector<int>> mat = {
  //   {1,0,1,1,1},
  //   {1,1,1,0,1},
  //   {1,0,0,1,1},
  //   {1,0,0,1,0},
  //   {1,0,0,1,1}
  // };
  vector<vector<int>> mat = {
    {1,1,1,0,0,0,0,1,1,1},
    {1,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,0},
    {1,0,0,0,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,1,1,1,1,1,1,1,0,1},
    {0,0,1,0,0,0,1,0,0,1},
    {0,0,1,0,0,0,1,0,0,1},
    {0,1,1,1,1,1,1,1,1,1}
  };

  int x = 0;
  int y = 0;

  if(mat[x][y] == 0 && mat[n-1][n-1] == 0) cout << "Rat cannot traverse this maze : Maze invalid!" << endl;

  vector<vector<int>> visited(n, vector<int>(n, 0));
  string path;
  vector<string> ans;

  findPath(n, mat, x, y, visited, path, ans);

  int tmp = ans.size();
  if(tmp>1) cout << "There were " << tmp << " paths that were found :" << endl;
  else cout << "One and only path that is found is: " << endl;
  for(string i : ans){
    int tmp = i.size();
    for(int j=0; j<tmp; j++){
      cout << i[j];
      if(j<tmp-1)
      cout << " -> ";
    }
    cout << endl;
  }

  return 0;
}
