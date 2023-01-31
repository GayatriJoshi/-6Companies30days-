class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int> dp(B.size()+1,0);
        int res = 0;
        for(int i=0;i<A.size();i++)
         for(int j=B.size()-1;j>=0;j--)
           res = max(res,dp[j+1]=A[i]==B[j]?dp[j]+1:0);
        return res;
    }
};
