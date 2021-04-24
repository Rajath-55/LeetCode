/* Author : Rajath V 
   Challenge : COdeJam
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n';
int mod = 1000000007;
const long long mxN = 1e18;
const int INF = 10000000000000000LL;

void outp(vector<int> a)
{
    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

int revsort(vector<int> a){
    int count = 0;
    for(int i=0; i<a.size()-1;++i){
        int idx = i;
        for(int j=i;j<a.size();++j){
            if(a[j] < a[idx]){
                idx = j;
            }
        }
        count+= idx - i + 1;
        reverse(a.begin()+i, a.begin()+idx+1);
        // outp(a);
        // cout<<count<<endl;

    }
    return count;
}


void solve(int t)
{
  int n,c;
  cin>>n>>c;
  
 
          
      

  return;
  
}

int main()
{
    fastio();

    int t;
    cin >> t;
    int k = t;
    
    while (t > 0)
    {
        int s = k - t + 1;
        solve(s);
        t--;
    }
}


