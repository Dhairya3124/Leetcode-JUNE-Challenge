class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        
        for(int i=0;i<flights.size();i++)
            mat[flights[i][0]][flights[i][1]]=flights[i][2];
        
         vector<vector<int>> dp(n,vector<int>(K+2,-1));
         rec(src,dst,n,K+1,dp,mat);   
      
         return dp[src][K+1];
    }
    
    int rec(int src,int dest,int n,int stop,vector<vector<int>> &dp,vector<vector<int>> &mat){
        int minDist=INT_MAX;
        int gotP=0;
        int cost;
        
        if(src==dest)
            return 0;
        if(stop==0)
            return -1;
        
        for(int i=0;i<n;i++){
            if(mat[src][i]!=0){
                if(dp[i][stop-1]==-1){
                    cost = rec(i,dest,n,(stop-1),dp,mat);
                    if(cost!=-1){
                        minDist=min(minDist,mat[src][i]+cost);
                        gotP=1;
                    }    
                }
                else{
                    minDist = min(minDist,mat[src][i]+dp[i][stop-1]);
                    gotP=1;
                }
            }
        }
        
        if(gotP)
        {
            dp[src][stop]=minDist;
            return dp[src][stop];
        }
        return -1;
    }
};
