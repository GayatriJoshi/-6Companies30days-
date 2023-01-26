class Solution {
public:
    int magicalString(int n) {
        string magicString = "122";
        int index=2;
        while(magicString.size() < n)
        {
            int repeat = magicString[index]-'0';
            char nextChar = magicString.back() ^ 3;
            magicString+=string(repeat,nextChar);
            index++;
        }
        return count(magicString.begin(),magicString.begin()+n,'1');
    }
};
