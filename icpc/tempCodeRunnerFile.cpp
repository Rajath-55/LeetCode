#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int finish, dist, tigac, bolspeed;
    cin >> finish >> dist >> tigac >> bolspeed;
    float timetiger, timebolt;
    int totaldistance = finish + dist;
    timetiger = ((float)(2*totaldistance)/tigac);
    timetiger = sqrt(timetiger);
    timebolt = (float)finish/bolspeed;
    cout<<(timetiger >=timebolt ? "Tiger\n" : "Bolt\n");
    
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}