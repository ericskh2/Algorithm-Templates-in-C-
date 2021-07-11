class Trie {
public:
    struct Node{
        Node* children[26];
        bool end;
        Node(){
            for(int i = 0;i<26;i++){
                children[i] = nullptr;
            }    
            end = false;
        }
    };

    Node* trie;
    
    Trie() {
        trie = new Node;        
    }
    
    void insert(string word) {
        Node* trie = this->trie;
        for(auto c:word){
            int a = c-'a'; 
            if(trie->children[a]==nullptr){
                trie->children[a] = new Node;
            }        
            trie = trie->children[a];
        }       
        trie->end = true;
    }
    
    bool search(string word) {
        Node* trie = this->trie;
        for(auto c:word){
            if(trie==nullptr) return false;
            int a = c-'a';
            trie = trie->children[a];
        }
        return trie!=nullptr && trie->end;
    }
    
    bool startsWith(string prefix) {
        Node* trie = this->trie;
        for(auto c:prefix){
            if(trie==nullptr) return false;
            int a = c-'a';
            trie = trie->children[a];
        }
        return trie!=nullptr;        
    }
};

/**
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
