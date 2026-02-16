class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        reverse(deck.begin(),deck.end());
        vector<int>ans;

        deque<int>q;
        for(auto it:deck){
            if(q.empty()){
                q.push_front(it);
                continue;
            }
            int num=q.back();
            q.pop_back();
            q.push_front(num);
            q.push_front(it);
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
    }
};