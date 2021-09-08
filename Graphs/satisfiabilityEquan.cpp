class Solution {
public:
    
    vector<int>parent;
    
    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    
    bool set_union(int a, int b){
        int para = find(a);
        int parb = find(b);
        if(para == parb) return true;
        parent[parb] = para;
        return false;
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(100);
        for(int i = 0; i < 100; ++i) parent[i] = i;
        for(auto x : equations){
            string sub = "";
            sub += x[1];
            sub +=x[2];
            if(sub == "=="){
                set_union(x[0] - 'a', x[3] - 'a');
            }else{
                continue;
            }
        }
        for(auto x : equations){
            string sub = "";
            sub += x[1];
            sub +=x[2];
            if(sub == "!="){
                if(find(x[0] - 'a') == find(x[3] - 'a')) return false;
            }else continue;
        }
        return true;
    }
};
/*
!= means an edge
union find on the graph

cycle detection in a graph thats it
*/
