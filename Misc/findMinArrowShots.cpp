class Solution {
public:
    static bool customCompare(const vector<int> &x, const vector<int> &y){
        return x[1] < y[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() <=1) return 1;
        sort(points.begin(), points.end(), customCompare);
        vector<vector<int>>selected;
        selected.push_back(points[0]);
        for(int i = 1; i< points.size(); ++i){
            if(points[i][0] > selected[selected.size()-1][1])
                selected.push_back(points[i]);
        }
        
        cout<<selected.size()<<"\n";
        return selected.size();
    }
};
