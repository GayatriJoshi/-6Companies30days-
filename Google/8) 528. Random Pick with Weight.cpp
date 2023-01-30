class Solution {
public:
    vector<int> w;
    std::discrete_distribution<int> dist;
    std::mt19937 gen;
    Solution(vector<int>& w) {
        this->w=w;
        this->dist = std::discrete_distribution<int>(std::begin(w),std::end(w));
    }
    
    int pickIndex() {
        return dist(gen);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
