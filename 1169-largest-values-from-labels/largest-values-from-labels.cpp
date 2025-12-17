class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n=values.size();
        vector<pair<int,int>>item;
        for(int i=0;i<n;i++){
            item.push_back({values[i],labels[i]});
        }
        sort(item.begin(),item.end(),greater<>());
        map<int,int>cnt;
        int used=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(used>=numWanted)break;
            if(cnt[item[i].second]<useLimit){
                used++;
                sum+=item[i].first;
                cnt[item[i].second]++;
            }
        }
        return sum;
    }
};