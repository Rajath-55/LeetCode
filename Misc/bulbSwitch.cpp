class Solution {
public:
    int bulbSwitch(int n) {
        return floor(sqrt(n));
    }
};

/*
Once you start writing the state of each bulb after n rounds you will notice that only the bulbs that are perfect square numbered are in ON state, rest are in OFF (or initial) state
.
This is because the divisors of every integer that is NOT a perfect square comes as a pair.
For example, in case of 6 its divisors are (1,6) and (2,3). In case of 12 the divisors are (1,12), (2,6), (3,4).
Each member of the pair cancels out the toggle made by the other member.

But in case of perfect-square number one of its divisor does not come as a pair. That divisor is the square root of that perfect square number. Thats why a perfect-square number has odd number of divisors. That is why there is no round that can cancel out the toggle made by the "square-root" round. Thats why all the perfect square numbers are in ON state.
*/
