class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        stack<char>st;
        for(int i = 0; i < num.size(); ++i){
            while(not st.empty() and k > 0 and num[i] < st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k--){
            if(not st.empty()) st.pop();
        }
        while(not st.empty()){
            res = st.top() + res;
            st.pop();
        }
        if(res == "") return "0";
        int i;
        for( i = 0; i < res.size(); ++i) if(res[i] != '0') break;
        return res.substr(i) == "" ? "0" : res.substr(i);
        
    }
};
/*
Simple approach
every time there is a peak from the msb, remove that element.
this peak nonsense can be taken care of easily using a sstack
1432219

stack = []

i = 0
stack = 1

i = 1
stack = 1 4

i=2
3 < st.top() and so pop the top as long as k>0
stack = 1 
add 3:
stack = 1 3

i = 3
2 < st.top() and so pop the top as k = 2 and push 2(s[i])
stack = 1 2

i = 4
stack = 1 2 2

i = 5:
1 < st.top() and k == 1 so pop the top element and push 1
stack = 1 2 1

since k == 0simply keep pushing
1 2 1 9
add into string and return


*/
