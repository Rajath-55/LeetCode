class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string>res;
        map<string,int>l1,l2;
        for(int i=0; i<list1.size(); ++i) l1[list1[i]]=i;
        for(int i=0; i<list2.size(); ++i) l2[list2[i]]=i;
        int minIdxSum = INT_MAX;
        for(auto x : l1){
            if(l2.find(x.first)!=l2.end()){
                cout<<x.first<<" ";
                int idx = l2[x.first];
                int tempSum = idx + x.second;
                if(minIdxSum == tempSum){
                    res.push_back(x.first);
                }else if(minIdxSum > tempSum){
                    minIdxSum = tempSum;
                    res.clear();
                    res.push_back(x.first);
                }
            }
        }
        return res;

    }
};