class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.size();
        int ind=-1;
        int cnt=0;
        for(auto it:number)if(it==digit)cnt++;

        for(int i=0;i<n;i++){
            if(number[i]==digit){
                cnt--;
                if(number[i+1]>digit || cnt==0){
                    ind=i;
                    break;
                }
            }
        }
        return number.substr(0,ind)+number.substr(ind+1,n-ind-1);
        
    }
};