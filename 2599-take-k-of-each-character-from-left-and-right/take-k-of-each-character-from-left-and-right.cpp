class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        vector<int>v(3,0);
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        if(v[0]<k || v[1]<k || v[2]<k)return -1;

        int maxA=v[0]-k;
        int maxB=v[1]-k;
        int maxC=v[2]-k;

        v[0]=0;v[1]=0;v[2]=0;
        int l=0;
        int r=0;
        int maxLen=-1;
        while(r<n){
            v[s[r]-'a']++;
            while(v[0]>maxA || v[1]>maxB || v[2]>maxC){
                v[s[l]-'a']--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return n-maxLen;
    }
};