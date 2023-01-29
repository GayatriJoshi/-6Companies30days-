class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& e, int t) {
        vector<vector<int>> dp(n,vector<int>(n,1e7));
        for(int i=0;i<e.size();i++)
        {
            int u = e[i][0];
            int v = e[i][1];
            int w = e[i][2];
            dp[u][v]=w;
            dp[v][u]=w;
        }
        int ret=0;
        int cnt=INT_MAX;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j) continue;
                    if(dp[i][j]>dp[i][k] + dp[k][j])
                    {
                        dp[j][i]=dp[i][j]=(dp[i][k]+dp[k][j]);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<n;j++)
            {
                temp+=(dp[i][j]<=t);
            }
            if(temp<=cnt)
            {
                cnt=temp;
                ret=i;
            }
        }
        return ret;
    }
};
