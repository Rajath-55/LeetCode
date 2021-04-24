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
ll count(string s, ll x, ll y){
    ll res = 0;
    for(int i=0;i<s.length()-1;++i){
        if(s[i]=='J' && s[i+1]=='C') res+=y;
        if(s[i]=='C' && s[i+1]=='J') res+=x;
    }
    return res;
}

void solve(int t)
{
    
    ll x, y;
    string s;
    cin>>x>>y>>s;
    
    ll ans = 0;
    if (s.size() == 1)
    {
        cout << "Case #" << t << ": " << 0 << endl;
        return;
    }
    if (s.size() == 2)
    {
        ans = count(s, x, y);
        cout << "Case #" << t << ": " << ans << endl;
        return;
    }
   
    for(int i=0;i<s.size();i++){
        if(i==0){
            if(s[i]=='?'){
                int idx = i;
                while(s[idx]=='?' && idx <= s.size()) idx++;
                if(idx > s.size()-1){
                    break;
                }
                if(s[idx] == 'J'){
                    for(int j=i;j<idx;++j) s[i]='J';
                }
                if(s[idx] == 'C'){
                    for(int j=i;j<idx;++j) s[i]='C';
                }
            
            }
        }else{
            
            if(s[i]=='?'){
                int idx = i;
                while(s[idx]=='?' && idx <= s.size()) {idx++;}
                if(idx > s.size()-1){ break;}
                if(s[idx] == 'J' && s[i-1] =='J'){
                    for(int j=i;j<idx;++j) s[i]='J';
                }
                if(s[idx] == 'C' && s[i-1]=='C'){
                    for(int j=i;j<idx;++j) s[i]='C';
                }
                if((s[i-1]=='J' && s[idx]=='C') || (s[i-1]=='C' && s[idx]=='J')){
                    for(int j=i;j<idx;++j) s[i]= 'C';
                }
            
            }

        }
        
    }
    // cout<<s<<endl;
    ans+=count(s,x,y);

    
    cout << "Case #" << t << ": " << ans << endl;
}

/*

JC????CJ
x = 5 y = 2

JC??C?CJ

J?C => C-> X, J -> X
C?J => C->Y, J -> Y
C?? => C-> 0, J -> Y
J?? => C -> X, J -> 0
??C

????JC
????CJ
JJJJJC
J????CC
JJJJJCC 1 jc
JCCCCCC 1 jc




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

