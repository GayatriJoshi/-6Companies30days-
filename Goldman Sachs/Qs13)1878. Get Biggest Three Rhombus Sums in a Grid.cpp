class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& A) {
         int M = A.size(), N = A[0].size(), dirs[4][2] = { {1,1},{1,-1},{-1,-1},{-1,1} };
        set<int> s;
        for (int len = 1; len * 2 - 1 <= min(M, N); ++len) {
            for (int i = 0; i + 2 * len - 2 < M; ++i) {
                for (int j = len - 1; j <= N - len; ++j) {
                    int x = i, y = j, sum = len == 1 ? A[x][y] : 0;
                    for (auto &[dx, dy] : dirs) {
                        for (int k = 0; k < len - 1; ++k) {
                            sum += A[x += dx][y += dy];
                        }
                    }
                    s.insert(sum);
                    if (s.size() > 3) s.erase(s.begin());
                }
            }
        }
        return vector<int>(rbegin(s), rend(s));
    }
};
