class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , vector<int>> m;
        unordered_map<int,int> freq;

        for(int i = 0 ; i < n ; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > 1) continue;
            for(int j = 1 ; j <= sqrt(nums[i]) ; j++){
                if(nums[i]%j == 0){
                    m[nums[i]].push_back(j);
                    if(nums[i]/j != j) m[nums[i]].push_back(nums[i]/j);
                }
            }
        }

        int ans = 0;
        for(auto &i : m){
            if(i.second.size() == 4){
                int temp = 0;
                for(int j = 0 ; j < i.second.size() ; j++){
                    temp+=i.second[j];
                }
                // temp+=i.first;
                ans+= freq[i.first]*temp;
            }
        }

        return ans;
    }
};