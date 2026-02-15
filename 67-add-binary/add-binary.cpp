class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();

        int carry=0;
        string s="";

        int i=n-1;
        int j=m-1;
            
        while(i>=0 && j>=0){
            int sum = (a[i] - '0') + (b[j] - '0') + carry;
            s += (sum % 2) + '0';
            carry = sum / 2;
            i--;
            j--;
        }      
        while(i>=0){
            int sum = (a[i] - '0') + carry;
            s += (sum % 2) + '0';
            carry = sum / 2;
            i--;
        }  
        while(j>=0){
            int sum = (b[j] - '0') + carry;
            s += (sum % 2) + '0';
            carry = sum / 2;
            j--;
        }
        if(carry)s+='1';
        reverse(s.begin(),s.end());
        return s;
    }
};