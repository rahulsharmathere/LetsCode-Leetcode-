class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.size();
        string maxi="";        
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                string s=number.substr(0,i)+number.substr(i+1);
                if(s>maxi)maxi=s;

            }
        }
        
        return maxi;
    }
};