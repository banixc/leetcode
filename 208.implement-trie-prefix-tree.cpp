// linear loop

struct Node {
    bool is_word;
    vector<Node *> next;
    Node():next(vector<Node *>(26,NULL)), is_word(false) {};
};


class Trie {
public:
    Node* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i = 0;; i ++) {
            char c = word[i] - 'a';
            if(node->next[c] == NULL) {
                node->next[c] = new Node();
            }
            node = node->next[c];
            if (i == word.size()-1){
                node->is_word = true;
                return;
            }
        }        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(word, false);
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
    
    bool search(string& word, bool is_prefix) {
        Node* node = root;
        for(int i = 0; ; i ++) {
            node = node->next[word[i] - 'a'];
            if(node == NULL) {return false;}
            if(i == word.size() - 1) {
                return is_prefix || node->is_word;
            }
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

 // map and recursion, slow;

 struct Node {
    bool is_word;
    map<char, Node*> next;
};


class Trie {
public:
    Node* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i = 0;; i ++) {
            char c = word[i];
            if(node->next.count(c) == 0) {
                node->next[c] = new Node();
            }
            node = node->next[c];
            // cout << "insert " << c << endl;
            if (i == word.size()-1){
                node->is_word = true;
                return;
            }
        }        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(word, 0, root, false);
    }
    
    bool search(string& word, int start, Node* node, bool is_prefix) {
        char c = word[start];
        // cout << "search: " << word << " start: [" << c << "]" << endl; 
        if(node->next.count(c) == 0) {
            return false;
        }
        Node* next_node = node->next[c];
        if(start==word.size()-1) {
            return is_prefix || next_node->is_word;
        } else {
            return search(word, start+1, next_node, is_prefix);
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return search(prefix, 0, root, true);
    }
    
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */