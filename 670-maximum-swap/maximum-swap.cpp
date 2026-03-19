class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<pair<char,int>>maxi(n,{0,0});
        maxi[n-1]={s[n-1],n-1};
        for(int i=n-2;i>=0;i--){
            if(s[i] <= maxi[i+1].first){
                maxi[i]={maxi[i+1].first,maxi[i+1].second};
            }else{
                maxi[i]={s[i],i};
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!=maxi[i].first){
                swap(s[i],s[maxi[i].second]);
                break;
            }
        }
        int ans=stoi(s);
        return ans;

    }
};