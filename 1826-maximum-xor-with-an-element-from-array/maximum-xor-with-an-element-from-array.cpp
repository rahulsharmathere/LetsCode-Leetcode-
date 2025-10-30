//Optimal Trie
struct Node{
    Node *links[2];

    bool containsKey(int bit){
        return links[bit]!=NULL;
    }

    void put(int bit, Node* node){
        links[bit] = node; 
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    private: Node *root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(int num){
            Node* node = root;
            for(int i=31; i>=0; i--){
                int bit = (num>>i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }

        int getMax(int x){
            Node *node = root;
            int maxi = 0;
            for(int i=31; i>=0; i--){
                int bit = (x>>i) & 1;
                if(node->containsKey(1-bit)){
                    maxi |= 1<<i;
                    node = node->get(1-bit);
                }
                else node = node->get(bit);

            }
            return maxi;
        }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>ans(queries.size());
        vector<pair<pair<int,int>, int>>qu;

        for(int i=0; i<queries.size(); i++){
            qu.push_back({{queries[i][0], queries[i][1]}, i});
        }

        sort(qu.begin(), qu.end(), [](const pair<pair<int,int>, int>&a , const pair<pair<int,int>, int>&b){
            return a.first.second<b.first.second;
        });
        int j = 0;
        bool insert = false;
        for(int i=0; i<qu.size(); i++){
            int x = qu[i].first.first;
            int m = qu[i].first.second;
            int ind = qu[i].second;
            
            while (j < n && nums[j] <= m) {
                trie.insert(nums[j]);
                j++;
            }

            if (j == 0) ans[ind] = -1; // no elements <= m
            else ans[ind] = trie.getMax(x);
        }

        return ans;
    }
};