class Solution {
public:
    int brokenCalc(int x, int y) {
        if(x >= y) return x-y;
        if(y&1) return 1 + brokenCalc(x,y+1);
        return 1 + brokenCalc(x, y/2);
    }
};
