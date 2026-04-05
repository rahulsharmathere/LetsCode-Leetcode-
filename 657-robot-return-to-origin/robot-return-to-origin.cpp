class Solution {
public:
    bool judgeCircle(string moves) {
        int l=0;
        int r=0;
        int u=0;
        int d=0;
        for(char c:moves){
            if(c=='L')l++;
            if(c=='D')d++;
            if(c=='U')u++;
            if(c=='R')r++;
        }
        return (l==r && d==u);
    }
};