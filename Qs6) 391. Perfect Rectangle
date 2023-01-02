class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string,int> m;
        string corner[4];
        for(auto a:rectangles)
        {
            for(int i=0;i<4;i++)
            {
                corner[i]=to_string(a[i/2*2])+","+to_string(a[(i%2)*2 +1]);
                if(m[corner[i]] & int(pow(2,i))) return false;
                else{
                    m[corner[i]] |= int(pow(2,i));
                }
            }
        }
        int corners=0;
        for(auto i=m.begin();i!=m.end();i++)
        {
            int val=i->second;
            if(!(val & (val-1)) && (++corners > 4)) return false;
            if((val & (val-1)) && !(val==3 || val==12 || val==10 || val==5 || val==15)) return false;
        }
        return true;
    }
};
