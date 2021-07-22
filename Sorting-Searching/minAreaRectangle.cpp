class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> A;
        for(int i=0; i<points.size(); i++)
            A[points[i][0]].push_back(points[i][1]);
        map<pair<int, int>, int> last;
        int ans = INT_MAX;
        for(auto it:A)
        {
            vector<int> col = it.second;
            sort(col.begin(), col.end());
            for(int j=0; j<col.size(); j++)
            {
                for(int i=0; i<j; i++)
                {
                    int y1 = col[i];
                    int y2 = col[j];
                    if(last.find({y1, y2})!=last.end())
                    {
                        int area = abs(it.first-last[{y1, y2}])*abs(y2-y1);
                        ans = min(area, ans);
                    }
                    last[{y1, y2}] = it.first;
                }
            }
        }
        return ans<INT_MAX?ans:0;
    }
};
/*

For each X coordinate store all the y coordinates appearing on x=X line. Iterate over all the lines. Form pair of points on those and check on previous line if the the same pair of y coordinates are available on last line, if it is, calculate the area and check the minimum.
This might give a TLE to check the coordinates from all the previous lines, and hence we keep a map 'last' that stores the x coordinate for a given pair of (y1, y2) that were found on previous lines. As we only want to find the minimum area, hence we dont care about the lines having same pair of (y1, y2) before last x line (as obviously there x1-x2 will be larger and result in greater area).

*/
