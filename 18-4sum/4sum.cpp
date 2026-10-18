class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
         sort(a.begin(), a.end());
        int n = a.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            
            if(i>0 && a[i]==a[i-1])continue;
            for(int j=i+1;j<n-2;j++){
                
                if(j>i+1 && a[j]==a[j-1])continue;
                int l = j + 1, r = n - 1;

                while (l < r) {
                    long long s = 1LL*a[i] + a[j] + a[l] + a[r];

                    if (s == target) {
                        ans.push_back({a[i], a[j], a[l], a[r]});
                        l++; r--;

                        while (l < r && a[l] == a[l-1]) l++;
                        while (l < r && a[r] == a[r+1]) r--;
                    }
                    else if (s < target) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};