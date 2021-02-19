class Solution
{
public:
    int distance(vector<int> &p1, vector<int> &p2)
    {
        int x1 = p1[0], x2 = p2[0], y1 = p1[1], y2 = p2[1];
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        set<int> distances;
        if ((p1[0] == p2[0] && p1[1] == p2[1]) || (p2[0] == p3[0] && p2[1] == p3[1]) || (p3[0] == p1[0] && p3[1] == p1[1]))
            return false;
        int d1, d2, d3, d4, d5, d6;
        distances.insert(distance(p1, p2));
        distances.insert(distance(p1, p3));
        distances.insert(distance(p1, p4));
        distances.insert(distance(p2, p4));
        distances.insert(distance(p2, p3));
        distances.insert(distance(p3, p4));

        return distances.size() == 2;
    }
};