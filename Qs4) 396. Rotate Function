class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f0=0;
        int sum=0;
        int ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
           sum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            f0+= i*nums[i];
        }
        ans=f0;
        for(int i=n-1;i>=0;i--)
        {
           f0+= sum - n*nums[i];
           ans=max(f0,ans);
        }
        return ans;
    }
};
