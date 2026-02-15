class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=preorder.size();
        if(n==0)return false;
        
        int k = 1;

        for(int i=0;i<preorder.size();i++){
            if(preorder[i]==',')
                continue;
            k--;
            if(k<0)
                return false;

            if(preorder[i]!='#'){
                while(i<n && preorder[i]!=','){
                    i++;
                }
                k +=2;
            }
                
            
        }
        if(k==0)
            return true;
        return false;
    }
};