class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        bool flag=false;
        int minv=INT_MAX,maxv=INT_MIN;

        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1]) flag=true;
            if(flag) minv=min(minv,nums[i]);
        }
        flag=false;
        for(int i=n-2;i>=0;--i)
        {
            if(nums[i]>nums[i+1]) flag=true;

            if(flag) maxv=max(maxv,nums[i]);
        }
        int l,r;
        for(l=0;l<n;l++)
        {
            if(nums[l]>minv) break;
        }
        for(r=n-1;r>=0;r--)
        {
            if(nums[r]<maxv) break;
        }

        return max(r-l+1,0);
    }
};
