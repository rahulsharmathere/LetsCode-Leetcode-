class TrieNode{
    public:
    vector<TrieNode *>v;
    TrieNode() : v(2,nullptr){}
};
class Solution {
public:
    TrieNode *root = new TrieNode();
    int findMaximumXOR(vector<int>& nums) {
        int maxa = 0;
        for(int i:nums){
            string str = bitset<32>(i).to_string();
            TrieNode* node = root;
            for(char ch:str){
                if(node->v[ch-'0'] == nullptr){
                    node->v[ch-'0'] = new TrieNode();
                }
                node = node->v[ch-'0'];
            }
        }
        for(int i:nums){
            string str = bitset<32>(i).to_string();
            TrieNode* node = root;
            string temp = "";
            for(char ch:str){
                int ele = ch -'0' ^ 1;
                if(node->v[ele] != nullptr){
                    node = node->v[ele];
                    temp += to_string(ele);
                }
                else{
                    node = node->v[ch-'0'];
                    temp += ch;
                }
            }
            maxa = max(maxa,stoi(temp,0,2) ^ i);
        }
        return maxa;
    }
};