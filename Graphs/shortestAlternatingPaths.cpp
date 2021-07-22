class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        bool visited[n][2];
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++)
                visited[i][j]=false;
        
        vector<vector<int>>red(n);
        vector<vector<int>>blue(n);
        
        for(int i=0;i<red_edges.size();i++){
            int start = red_edges[i][0];
            int end = red_edges[i][1];
            red[start].push_back(end);
        }
        
        
        for(int i=0;i<blue_edges.size();i++){
            int start = blue_edges[i][0];
            int end = blue_edges[i][1];
            blue[start].push_back(end);
        }
        
        visited[0][0]=true;
        visited[0][1]=true;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        q.push({0,{0,1}});
        
        vector<vector<int>>result(n,vector<int>(2,0));
        result[0][0]=0;
        result[0][1]=0;
        
        for(int i=1;i<n;i++){
            result[i][0]=INT_MAX;
            result[i][1]=INT_MAX;

        }
        
        
        while(!q.empty()){
            pair<int,pair<int,int>> temp = q.top();
            q.pop();
            
            int cost = temp.first;
            int currentNode = temp.second.first;
            int color = temp.second.second;
            
            
            if(color==0){
                for(int i=0;i<blue[currentNode].size();i++){
                    int newNode = blue[currentNode][i];
                    int newCost = cost+1;
                    if(result[newNode][1] > newCost){
                        result[newNode][1]=newCost;
                        q.push({newCost,{newNode,1}});
                    }
                }
            }else{
                for(int i=0;i<red[currentNode].size();i++){
                    int newNode = red[currentNode][i];
                    int newCost = cost+1;
                    if(result[newNode][0] > newCost){
                        result[newNode][0]=newCost;
                        q.push({newCost,{newNode,0}});
                    }
                }
            }
            
        }
        
        vector<int>answer(n);
        
        for(int i=0;i<n;i++){
            answer[i]=min(result[i][0],result[i][1]);
            if(answer[i]==INT_MAX){
                answer[i]=-1;
            }
        }
        
        
        return answer;
    }
};
/*
I shall run dijkstras
with shortest distances maintained in two separate arrays
colors red and blue
0 = red
1 = blue

priority queue gonna be having distance, color,


*/
