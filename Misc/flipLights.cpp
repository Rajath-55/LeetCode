class Solution {
public:
    int flipLights(int n, int m) {
        if(n==0||m==0) return 1;
        else if(n==1)return 2;
        else if(n==2) return m==1?3:4;
        else if(m==1) return 4;
        else return m==2?7:8;     
    }
};
