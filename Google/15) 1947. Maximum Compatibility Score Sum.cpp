class Solution {
public:
    int ans = 0;
    bool visited[10]={0};
    int dp[100][100]={0};
    int checkScore(vector<int> &s,vector<int> &m){
        int cnt=0;
        for(int k=0;k<s.size();k++){
            if(s[k]==m[k])cnt++;
        }
        return cnt;
    }
    void dfs(vector<vector<int>> &m,vector<vector<int>> &s,int idx,int score){
        if(idx==s.size()){
            ans=max(ans,score);
            return;
        }
        for(int i=0;i<m.size();i++){
            if(visited[i]) continue;
            visited[i]=1;
            int n = dp[idx][i];
            dfs(m,s,idx+1,score+n);
            visited[i]=0;
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& m) {
        for(int i=0;i<s.size();i++){
            for(int j=0;j<m.size();j++){
                dp[i][j]=checkScore(s[i],m[j]);
            }
        }
        dfs(m,s,0,0);
        return ans;
    }
};
