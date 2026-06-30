class Node{
public:
    Node*arr[26];
    bool flag;
    
    Node(){
        for(int i=0;i<26;i++){
            arr[i]=NULL;
        }
        flag=false;
    }

    bool checkKey(char ch){
        if(arr[ch-'a']!=NULL)return true;
        return false;
    }

    void insert(char ch,Node* newNode){
        arr[ch-'a']=newNode;
    }
    
    Node* getNode(char ch){
        return arr[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node;
    }
    
    void insert(string word) {
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(!node->checkKey(ch)){
                Node* newNode=new Node;
                node->insert(ch,newNode);
            }
            node=node->getNode(ch);
        }
        node->setEnd();

    }
    
    bool search(string word) {
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(!node->checkKey(ch)){
                return false;
            }
            node=node->getNode(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(!node->checkKey(ch)){
                return false;
            }
            node=node->getNode(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */