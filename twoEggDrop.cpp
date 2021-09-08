//valid for n floors and k eggs


class Solution {
public:
    
    vector<vector<int>>dp;
    
    
    //being vegetarian dealing with eggs is difficult....    ;)
    int recurs(int n,int egg)
    {
  
        if(n<=0)
            return 0;
        if(n<=2)  //base case
            return n;
        
        if(egg==1)
            return n;//if only one egg left we need to test for each floor


        if(dp[n][egg]!=-1)
            return dp[n][egg];
        
        int res=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            int a=max(recurs(i-1,egg-1),recurs(n-i,egg));//max since -> worse case that can occur while choosing f=i 
            res=min(res,a);
        }
        return dp[n][egg]=res+1;// 1 since egg is dropped for this n for a trial
    }
    
    int twoEggDrop(int n) {
        dp.resize(n+1,vector<int>(4,-1));
        return recurs(n,2);
    }
};

/*
dp[i][j] - floor i and egg break 0, 1, 2



*/
