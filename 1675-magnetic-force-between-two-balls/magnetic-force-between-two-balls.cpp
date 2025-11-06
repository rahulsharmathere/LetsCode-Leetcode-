class Solution {
public:
    bool isPossible(int dist,vector<int>&position,int totalBalls){
        int n=position.size();
        int lastPos=position[0];
        int cntBalls=1;
        for(int i=1;i<n;i++){
            int d=position[i]-lastPos;
            if(d>=dist){
                lastPos=position[i];
                cntBalls++;
            }
            if(cntBalls>=totalBalls)return true;
           
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        //force = |x-y|
        sort(position.begin(),position.end());
        int n=position.size();
        int s=1;
        int e=(position[n-1]-position[0]) / (m-1);
        int ans=1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(mid,position,m)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
        
    }
};