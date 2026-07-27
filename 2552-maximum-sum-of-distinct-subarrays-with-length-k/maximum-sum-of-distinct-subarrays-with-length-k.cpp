class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        long long maxi=0;
        unordered_map<int,int>freq;
        int duplicate=0;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
            freq[arr[i]]++;
            if(freq[arr[i]]==2){
                duplicate++;
            }
            maxi+=arr[i];
        }
        if(duplicate>0)maxi=0;

        

        int j=k;
        int i=1;
        while(j<n){
            sum-=arr[i-1];
            if(freq[arr[i-1]]==2)
                duplicate--;
            freq[arr[i-1]]--;

            sum+=arr[j];
            freq[arr[j]]++;
            if(freq[arr[j]]==2)
                duplicate++;

            if(duplicate==0){
                maxi=max(maxi,sum);
            }
            i++;
            j++;
        }
        return maxi;
    }
};