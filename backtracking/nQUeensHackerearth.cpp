#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>board;
vector<vector<int>>ans;
unordered_set<int>col, diag1,diag2;

void backtrack(int row, int n, bool &isPossible){
	if(row == n){
		isPossible = true;
		ans = board;
		return;
	}
	for(int c = 0; c < n; ++c){
		if(col.count(c) or diag1.count(row + c) or diag2.count(row - c)) continue;
		board[row][c] = 1;
		col.insert(c);
		diag1.insert(row + c);
		diag2.insert(row - c);

		backtrack(row + 1, n, isPossible);
		board[row][c] = 0;
		diag1.erase(row + c);
		diag2.erase(row - c);
		col.erase(c);
	}
}
int main(){
	int n;
	cin>>n;
	board.resize(n, vector<int>(n, 0));
	bool isPossible = false;
	backtrack(0, n, isPossible);
	if(isPossible){
		cout<<"YES\n";
		for(auto x : ans){
			for(auto y : x) cout<<y<<" ";
			cout<<"\n";
		}
		return 0;
	}


}

