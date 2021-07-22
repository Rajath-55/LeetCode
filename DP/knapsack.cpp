#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,W;
  cin>>n>>W;
  vector<int>w, v;

  while(n--){
    int we,va;
    cin>>we>>va;
    w.push_back(we);
    v.push_back(va);
  }
  
  vector<vector<int>>dp(n, vector<int>(W, 0));
  for(int i = 1; i < n ; ++i){
    for(int j = 1; j < W; ++j){
        if(w[i-1] <= j){
          dp[i][j] = max(dp[i][j], dp[i-1][j - w[i-1]] + v[i-1]);
        }
    }
  }
  cout<< dp[n-1][W-1] <<"\n";

}

/*
If i am at a particular index, i either take the value and 
add on a weight, or i don't.
dp[i][j]  = value at index i , and weight j
0 to i-1 answers are there.
j from 0 to w.
dp[i][j] = dp[i-1][j] if we do not choose to take the current element.
if weight is > capacity, then we cannot take it
else we can take 

if( w[i-1] <= j){
  dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]] + val[i-1]);
}
*/
