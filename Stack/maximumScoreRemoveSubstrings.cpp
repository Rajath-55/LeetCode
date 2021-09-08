class Solution {
public:
    
    int remove(string &s, char c1, char c2){
        stack<char>st;
        int ans = 0;
        for(auto x : s){
            if(st.size() > 0 and st.top() == c1 and x == c2){
                st.pop();
                ans ++;
            }else{
                st.push(x);
            }
        }
        s = "";
        while(not st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        return ans;
    }
    int maximumGain(string s, int x, int y) {
       
        int ab = 0, ba = 0;
        if(x > y){
            ab += remove(s, 'a', 'b');
            ba += remove(s, 'b', 'a');
        }else{
            ba += remove(s, 'b', 'a');
            ab += remove(s, 'a', 'b');
        }
        return ab*x + ba*y;
    }
};

/*
Greedily remove the larger of the two, x or y
*/
