#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define endl "\n"
typedef long long ll;
 
int main(){ 
    ios_base:: sync_with_stdio(false); 
    cin.tie(0);
   
    ll t;
    cin>>t;
    while(t--){
        ll m;
        cin>>m;
        ll lo = 8;
        ll hi = 100000000000000000;
        ll mid,count=0;
        ll ans=-1,k;

        while(lo<hi){
            mid = (lo+hi)/2;

            k=2;
            count=0;
            while(k*k*k <= mid){
                count += mid/(k*k*k); 
                k++;
            }

            if(count==m){
                ans = mid;
            }

            if(count<m)
                lo = mid+1;

            if(count>=m)
                hi = mid;

        }

        cout<<ans<<endl;
    }
}