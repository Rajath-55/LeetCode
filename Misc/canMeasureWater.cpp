class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(targetCapacity > jug1Capacity + jug2Capacity) return false;
        if(targetCapacity == jug1Capacity + jug2Capacity) return true;
        
        return targetCapacity%(__gcd(jug1Capacity, jug2Capacity)) == 0;
    }
};
