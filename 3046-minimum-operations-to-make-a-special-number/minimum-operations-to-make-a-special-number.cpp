class Solution {
public:
    int minimumOperations(string num) {
        int n=num.size();
        int foundZero=0;
        int foundFive=0;

        for(int i=n-1;i>=0;i--){
            if(foundZero && num[i]=='0')return n-i-2;
            if(foundZero && num[i]=='5')return n-i-2;
            if(foundFive && num[i]=='2')return n-i-2;
            if(foundFive && num[i]=='7')return n-i-2;
            if(num[i]=='0')foundZero=1;
            if(num[i]=='5')foundFive=1;
        }

        if(foundZero)return n-1;
        return n;
        
    }
};