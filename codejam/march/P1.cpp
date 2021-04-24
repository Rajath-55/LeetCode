/* Author : Rajath V 
   Challenge : COdeJam
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

//Template functions

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

vector<ll> inp(ll n)
{
    vector<ll> a;
    for (int i = 0; i < n; ++i)
    {
        ll inp;
        cin >> inp;
        a.push_back(inp);
    }
    return a;
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

ll revsort(vector<ll> &a){
    ll count = 0;
    for(ll i=0; i<a.size()-1;++i){
        ll idx = i;
        for(ll j=i;j<a.size();++j){
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
  ll n;
  cin>>n;
  vector<ll>a = inp(n);
  ll ans = revsort(a);
  cout<<"Case #"<<t<<": "<<ans<<endl;
}

/*

5 4 3 2 1 
mini = 2
1 2 3 4 5







*/

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

