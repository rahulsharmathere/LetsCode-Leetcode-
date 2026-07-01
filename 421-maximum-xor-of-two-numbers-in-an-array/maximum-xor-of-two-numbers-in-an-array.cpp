class Node{
public:
    Node* arr[2];

    Node(){
        arr[0]=arr[1]=NULL;
    }

    bool checkKey(int bit){
        return arr[bit]!=NULL;
    }

    void insert(int bit,Node* newNode){
        arr[bit]=newNode;
    }

    Node* getNode(int bit){
        return arr[bit];
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node* node=root;

        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;

            if(!node->checkKey(bit)){
                node->insert(bit,new Node());
            }

            node=node->getNode(bit);
        }
    }

    int getMaxXor(int num){
        Node* node=root;
        int ans=0;

        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;

            if(node->checkKey(1-bit)){
                ans|=(1<<i);
                node=node->getNode(1-bit);
            }
            else{
                node=node->getNode(bit);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie* trie=new Trie();

        for(int num:nums){
            trie->insert(num);
        }

        int ans=0;

        for(int num:nums){
            ans=max(ans,trie->getMaxXor(num));
        }

        return ans;
    }
};