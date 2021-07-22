/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>>res;
        int left = 1, right = 1000;
        while(left <= 1000 and right > 0){
            int ans = customfunction.f(left, right);
            if(ans > z){
                right--;
            }else if(ans < z){
                left++;
            }else{
                res.push_back({left,right});
                left++;
                right--;
            }
            
        }
        return res;
    }
};

/*
2 pointer approach, simple enoug
just check if the value of f is satisfied with these two
then if so add
else if value is > then right-- else left++
this is only because monotonically increasing 
*/
