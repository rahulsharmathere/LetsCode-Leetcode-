class Solution {
public:
    int longestConsecutive(vector<int>& a) {
    int n=a.size();
    if(n==0)return 0;
    if(n==1)return 1;
    sort(a.begin(),a.end());
    int maxLen=1;
    int Len=1;
    for(int i=0;i<n-1;i++){
        if(a[i+1]==a[i]+1){
            Len++;
        }
        else if(a[i+1]==a[i]){
            continue;
        }
        else{
            Len=1;
        }
        maxLen=max(maxLen,Len);
    }
    return maxLen;
    }
};