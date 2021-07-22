class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int>mp;
        for(auto x : matrix){
            string temp = "";
            for(int i = 0; i < x.size(); ++i){
                if(x[i] == x[0]) temp+="T";
                else temp+="F";
            }
            mp[temp]++;
        }
        int maxi = 0;
        for(auto x : mp) maxi = max(maxi, x.second);
        return maxi;
    }
};
/*
The main idea is to find the "pattern" of each row.
"Pattern" here is defined by whether each element in the
row is same as the first element or not.
Then we return the frequency of the most frequent pattern.

e.g. for the matrix -
[[0,0,0],
[0,0,1],
[1,1,0]]

pattern will be -
[[T,T,T],
[T,T,F],
[T,T,F]]

here, the pattern "TTF" appears 2 times(highest)
so, 2 is the answer

Why does this method work?
In the rows having the same pattern,
we can either flip all the columns having 'F', or 'T',
and all individual rows will become equal.

e.g. in the above example,
2nd and 3rd rows have pattern "TTF"
let us flip the column having "F"
so 2nd row becomes 0, 0, 0, and
so 3rd row becomes 1, 1, 1




*/
