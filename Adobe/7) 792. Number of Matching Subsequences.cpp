class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
      int ans = 0;
      vector<vector<pair<int,int>>> bucket(26);

      for(int i=0;i<words.size();i++)
       bucket[words[i][0] - 'a'].emplace_back(i,0);
      for(const char c:s)
      {
          vector<pair<int,int>> prevBucket;
          swap(prevBucket,bucket[c - 'a']);
          for(auto& [i,j]:prevBucket)
           if(++j == words[i].length())
            ++ans;
           else
            bucket[words[i][j] - 'a'].emplace_back(i,j);
      }
      return ans;
    }
};
