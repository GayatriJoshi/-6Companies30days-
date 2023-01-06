#include<bits/stdc++.h>
class Solution {
public:
    void helper(int i,int k,int n,int sum,vector<int> &subSet,vector<vector<int>> &ans)
    {
        if(sum>n) return;
        if(k<0) return;
        if(sum==n){
            if(k==0){
                ans.push_back(subSet);
            }
            return;
        }
        
        if(i==10) return;
        
        sum+=i;
        subSet.push_back(i);
        helper(i+1,k-1,n,sum,subSet,ans);
        
        //backtracking
        sum-=i;
        subSet.pop_back();
        helper(i+1,k,n,sum,subSet,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subSet;
        int sum=0;
        helper(1,k,n,sum,subSet,ans);
        return ans;
    }
};
