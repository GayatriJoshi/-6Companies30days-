class Solution {
public:
    bool canKPartitionPossiblerec(vector<int> &nums,int subsetSum[],bool taken[],int subset,int k,int n,int curIdx,int limitIdx)
    {
        if(subsetSum[curIdx]==subset)
        {
            if(curIdx == k-2)
              return true;
            return canKPartitionPossiblerec(nums,subsetSum,taken,subset,k,n,curIdx+1,n-1);
        }
        for(int i=limitIdx;i>=0;i--)
        {
            if(taken[i]) continue;
            int tmp = subsetSum[curIdx]+nums[i];

            if(tmp<=subset)
            {
                taken[i]=true;
                subsetSum[curIdx]+=nums[i];
                bool nxt = canKPartitionPossiblerec(nums,subsetSum,taken,subset,k,n,curIdx,i-1);

                taken[i]=false;
                subsetSum[curIdx] -= nums[i];
                if(nxt) return true;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1) return true;
        if(n<k) return false;

        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%k!=0) return false;

        int subset = sum/k;
        int subsetSum[k];
        bool taken[n];

        for(int i=0;i<k;i++)
         subsetSum[i]=0;
        for(int i=0;i<n;i++)
          taken[i]=false;
        
        subsetSum[0]=nums[n-1];
        taken[n-1]=true;

        return canKPartitionPossiblerec(nums,subsetSum,taken,subset,k,n,0,n-1);
    }
};
