// https://leetcode.com/problems/implement-trie-prefix-tree/submissions/


#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

class Trie {
    struct Trienode{
        char val;
        int count;
        int endsHere;
        Trienode *child[26];
    };
    Trienode *root;
    
    Trienode *getNode(int index){
        Trienode *newnode = new Trienode;
        newnode->val = 'a'+index;
        newnode->count = newnode->endsHere = 0;
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        IOS
        // root value = '/' (I dont the ascii value of '/'. So this is a hack :p)
        root = getNode('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trienode *curr = root;
        int index;
        for(int i = 0; word[i] != '\0'; i++) {
            index = word[i]-'a';
            if(curr->child[index] == NULL) {
                curr->child[index] = getNode(index);
            }
            curr->child[index]->count +=1;
            curr = curr->child[index];
        }
        curr->endsHere +=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trienode *curr = root;
        int index;
        for(int i=0; word[i] != '\0'; i++) {
            index = word[i]-'a';
            if(curr->child[index] == NULL) {
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode *curr = root;
        int index;
        for(int i = 0; prefix[i] != '\0'; i++) {
            index = prefix[i] - 'a';
            if(curr->child[index] == NULL){
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */












#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

class Trie {
    struct Trienode{
        char val;
        int count;
        int endsHere;
        Trienode *child[26];
        
        Trienode(int index) {
            val = 'a'+index;
            count = endsHere = 0;
            for(int i=0;i<26;++i)
                child[i] = NULL;
        }
    };
    
    Trienode *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        IOS
        // root value = '/' (I dont the ascii value of '/'. So this is a hack :p)
        root = new Trienode('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trienode *curr = root;
        int index;
        for(int i = 0; word[i] != '\0'; i++) {
            index = word[i]-'a';
            if(curr->child[index] == NULL) {
                curr->child[index] = new Trienode(index);
            }
            curr->child[index]->count +=1;
            curr = curr->child[index];
        }
        curr->endsHere +=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trienode *curr = root;
        int index;
        for(int i=0; word[i] != '\0'; i++) {
            index = word[i]-'a';
            if(curr->child[index] == NULL) {
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode *curr = root;
        int index;
        for(int i = 0; prefix[i] != '\0'; i++) {
            index = prefix[i] - 'a';
            if(curr->child[index] == NULL){
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
