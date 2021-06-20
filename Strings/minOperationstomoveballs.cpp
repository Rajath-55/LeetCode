class Solution {
public:
    vector<int> minOperations(string boxes) {
        int lsum = 0;
        int rsum = 0;
        int leftBalls = 0;
        int rightBalls = 0;
        vector<int>res;
        if(boxes[0] == '1') rightBalls++;
        
        for(int i = 1; i < boxes.length(); ++i){
            if(boxes[i] == '1'){
                rightBalls ++;
                rsum+=i;
            }
        }
        
        for(int i = 0; i < boxes.length(); ++i){
            res.push_back(lsum + rsum);
            
            if(boxes[i] == '1'){
                rightBalls--;
                leftBalls++;
            }
            rsum-=rightBalls;
            lsum+=leftBalls;
        }
        return res;
        
        
        
        
    }
};


/*
001011

count_1s for each box : from left and from right;

and add their indices values to a rsum and lsum






*/