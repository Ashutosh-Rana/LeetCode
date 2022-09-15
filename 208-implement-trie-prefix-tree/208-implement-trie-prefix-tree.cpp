class TrieNode{
public:
    TrieNode *links[26];
    bool is_end_word;
    TrieNode(){
        memset(links, 0, sizeof(links));  //set all links to 0
        is_end_word=false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++){
            if(node->links[word[i]-'a']==NULL){
                node->links[word[i]-'a']=new TrieNode;
            }
            node=node->links[word[i]-'a'];
        }
        node->is_end_word=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++){
            if(node->links[word[i]-'a']==NULL){
                return false;
            }
            node=node->links[word[i]-'a'];
        }
        return node->is_end_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(int i=0;i<prefix.size();i++){
            if(node->links[prefix[i]-'a']==NULL){
                return false;
            }
            node=node->links[prefix[i]-'a'];
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