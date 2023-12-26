#include <iostream>
#include <vector>
using namespace std;

void findPath(int n, vector<vector<int>> mat, int x, int y, vector<vector<int>> visited, string path, vector<string> &ans){

}

int main(){
  int n=5;
  vector<vector<int>> mat = {
    {1,0,1,1,1},
    {1,1,1,0,1},
    {1,0,0,1,1},
    {1,0,0,1,0},
    {1,0,0,1,1}
  };

  int x = 0;
  int y = 0;

  vector<vector<int>> visited(n, vector<int>(n, 0));
  string path;
  vector<string> ans;

  findPath(n, mat, x, y, visited, path, ans);
}
