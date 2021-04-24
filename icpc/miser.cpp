/* Author : Rajath V 
   Challenge : ICPC
*/
 
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long ll;
typedef long int l;
#define endl '\n';
ll mod = 1000000007;
const long long mxN = 1e18;
const ll INF = 10000000000000000LL;
 
template <typename T>
bool isEqual(std::vector<T> const &v1, std::vector<T> const &v2)
{
    return (v1.size() == v2.size() &&
            std::equal(v1.begin(), v1.end(), v2.begin()));
}
 
bool prime_check(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
vector<ll> sieve(ll n)
{
    vector<ll> primes, is_prime(n + 1, 1);
    for (ll i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (ll j = i + i; j <= n; j += i)
                is_prime[j] = 0;
    for (ll i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
    return primes;
}
 
vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        elems.push_back(item);
 
    return elems;
}
 
ll power(ll x, unsigned long long y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
void outp(vector<ll> a)
{
    for (auto x : a)
        cout << x << " ";
    cout << endl;
}
 

ll sum(vector<ll> a)
{
    ll s = 0;
    for (auto x : a)
        s += x;
    return s;
}
 
inline ll ceiling(ll n, ll x)
{
    return (n % x ? n / x + 1 : n / x);
}
 

 
void solve()
{
    string s;
    cin>>s;
    int low = 10000000000000000;
    for(int i=0;i<s.size(); ++i){
        string res = s;
        int n;
        if(i+1 < s.size()){
            res = res.substr(0,i) + res.substr(i+1, s.size() - i - 1);
        }else{
            res = res.substr(0,i);
        }
        stringstream stream(res);
        stream>>n;
        if(n < low){
            low = n;
        }
    }
    cout<<low<<endl;

 
}
//18109

// 1234888
//12345679
//1877777
 
int main()
{
    fastio();
    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }
    // solve();
 
    return 0;
}
