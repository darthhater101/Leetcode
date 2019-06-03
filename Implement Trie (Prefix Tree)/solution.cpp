/*
Implement a trie with insert, search, and startsWith methods.

------------------------------
Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
------------------------------
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

Result: Runtime: 64 ms, faster than 96.13% of C++ online submissions for Implement Trie (Prefix Tree).
        Memory Usage: 45 MB, less than 36.88% of C++ online submissions for Implement Trie (Prefix Tree).
*/

class Trie {
private:
    Trie* character[26]= {};
    bool isLeaf = false;

public:
    
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        
        for(char x : word) {
            x -= 'a';
            if(curr->character[x] == nullptr) {
                curr->character[x] = new Trie();
            }
            
            curr = curr->character[x];
        }
        
        curr->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      //  if(this == nullptr) return false;
        
        Trie* curr = this;
        
        for(char x : word) {
             x -= 'a';
            curr = curr->character[x];
            
            if(curr == nullptr) return false;
        }
        
        return curr->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       // if(this == nullptr) return false;
        
        Trie* curr = this;
        
        for(char x : prefix) {
             x -= 'a';
            curr = curr->character[x];
            
            if(curr == nullptr) return false;
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
