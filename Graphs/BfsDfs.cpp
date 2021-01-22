class Solution
{
public:
    void bfsprint(vector<vector<int>> v, int sv)
    {
        int n = v.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(sv);
        visited[sv] = true;
        while (!q.empty())
        {
            int cv = q.front();
            q.pop();
            cout << cv << endl;
            for (int i = 0; i < n; ++i)
            {
                if (v[cv][i] && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    void dfsprint(vector<vector<int>> v, int sv, vector<bool> &visited)
    {
        cout << sv << endl;
        visited[sv] = true;
        int n = v.size();
        for (int i = 0; i < n; ++i)
        {
            if (v[sv][i] && visited[i] == false)
            {
                dfsprint(v, i, visited);
            }
        }
    }
};