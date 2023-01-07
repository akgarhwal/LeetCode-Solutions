/* Question: Implement Trie (Prefix Tree)
 * Lang: cpp
 * Runtime: 160 ms
 * Memory: 33.8 MB
 * Question Url: https://leetcode.com/problems/implement-trie-prefix-tree
 * Submission Url:
 * https://leetcode.com/problems/implement-trie-prefix-tree/submissions/339246191
 */


struct Node{
    bool is_word = false;
    unordered_map<char,Node*> children;
};
class Trie {
    Node* node;
public:
    /** Initialize your data structure here. */
    Trie() {
        node = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = node;
        for(char ch:word){
            if(temp->children.count(ch) > 0 ){
                temp = temp->children[ch];
            }
            else{
                temp->children[ch] = new Node();
                temp = temp->children[ch];
            }
            
        }
        temp->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = node;
        for(char ch:word){
            if(temp->children.count(ch) > 0 ){
                temp = temp->children[ch];
            }
            else{
                return false;
            }
        }
        return temp->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* temp = node;
        for(char ch:prefix){
            if(temp->children.count(ch) > 0 ){
                temp = temp->children[ch];
            }
            else{
                return false;
            }
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