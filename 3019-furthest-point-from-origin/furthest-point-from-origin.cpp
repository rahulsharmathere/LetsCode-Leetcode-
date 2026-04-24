class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int r=0;
        int l=0;
        int u=0;
        for(char c:moves){
            if(c=='R')r++;
            if(c=='L')l++;
            if(c=='_')u++;
        }
        int net=abs(l-r);
        return (u+net);
    }
};