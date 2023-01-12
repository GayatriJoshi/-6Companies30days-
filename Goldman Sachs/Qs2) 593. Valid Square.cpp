class Solution {
public:
    bool help(vector<int> a,vector<int> b,unordered_set<int> &n)
    {
        if(a[0]==b[0] && a[1]==b[1]) return false;
        int dx=a[0]-b[0];
        int dy=a[1]-b[1];

        int dist=dx*dx+dy*dy;
        n.insert(dist);
        return true;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> n;
        if(!help(p1,p2,n) || !help(p1,p3,n) || !help(p1,p4,n) || !help(p2,p3,n) || !help(p2,p4,n) || !help(p3,p4,n)) return false;
        return n.size()==2?true:false;
    }
    
};
