class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod=1e9+7;
        vector<int> f(n+1,0);
        f[1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+delay;j<=min(n,i+forget-1);j++)
            {
                f[j]=(f[i]+f[j])%mod;
            }
        }
        int res=0;
        for(int i=n-forget+1;i<=n;i++)
        {
            res=(res+f[i])%mod;
        }
        return res;
    }
};
