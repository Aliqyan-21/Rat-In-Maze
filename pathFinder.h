#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

int i = 1;
inline bool isSafe(int n, int x, int y, vector<vector<int>> mat, vector<vector<int>> visited){
  // three conditions we have check for
  // 1. inside the matrix
  // 2. should not be already visited
  // 3. input matrix == 1, i.e. not be blocked
  return ((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y] == 0) && (mat[x][y] == 1)) ? true : false;
}

void findPath(int n, vector<vector<int>> mat, int x, int y, vector<vector<int>> visited, string path, vector<string> &ans){
  sleep(1);
  system("clear");
  for(auto i : visited){
    for(int j : i){
      // usleep(50);
      cout << j << " ";
    }
    cout << endl;
  }

  // base case
  if(x == n-1 && y == n-1){
    cout << i << " Path Found!" << endl;
    i++;
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
    //backtracking
    path.pop_back();
  }

  // left
  newx = x;
  newy = y-1;
  if(isSafe(n, newx, newy, mat, visited)){
    path.push_back('L');
    findPath(n, mat, newx, newy, visited, path, ans);
    //backtracking
    path.pop_back();
  }

  // right
  newx = x;
  newy = y+1;
  if(isSafe(n, newx, newy, mat, visited)){
    path.push_back('R');
    findPath(n, mat, newx, newy, visited, path, ans);
    //backtracking
    path.pop_back();
  }

  // up
  newx = x-1;
  newy = y;
  if(isSafe(n, newx, newy, mat, visited)){
    path.push_back('U');
    findPath(n, mat, newx, newy, visited, path, ans);
    //backtracking
    path.pop_back();
  }

  visited[x][y] == 0; 
}

#endif
