class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dirx = 0, diry = 1;
        
        for(auto c : instructions){
            if(c == 'G'){
                x += dirx;
                y += diry;
            }else if(c == 'L'){
                int temp = diry;
                diry = dirx;
                dirx = -temp;
                
            }else{
                int temp = dirx;
                dirx = diry;
                diry = -temp;
            }
        }
        return (x == 0 and y == 0) or (dirx !=0 or diry != 1);
    }
};
