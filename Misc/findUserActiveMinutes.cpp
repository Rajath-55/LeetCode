class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>>times;
        unordered_map<int,int>user_minutes;
       
        vector<int>ans(k, 0);
        
        for(auto x : logs){
            int id = x[0], minute = x[1];
            
            if(times[id].find(minute) == times[id].end()){
                user_minutes[id]++;
                times[id].insert(minute);
            }
        }
        for(auto x : user_minutes){
            ans[x.second - 1]++;
        }
        return ans;
        
    }
};

/* better solutiion without maps and sets"
*/
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(), logs.end());
        vector<int> ans(k,0);
        int index = 0;
        while(index < logs.size()){
            int tempIndex = index+1;
            int uam = 1;
            while(tempIndex < logs.size() and logs[index][0] == logs[tempIndex][0]){
                if(logs[tempIndex][1] != logs[tempIndex-1][1]) uam++;
                tempIndex++;
            }
            ans[uam-1]++;
            index = tempIndex;
        }
        return ans;
    }
};