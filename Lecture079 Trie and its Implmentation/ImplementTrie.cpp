/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        // constructor
        TrieNode(char ch){
            this->data = ch;
            this->isTerminal = false;
            for(int i=0; i<26; i++){
               this->children[i] = NULL;
            }
        }
};

 

class Trie {
    // creation of root node
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
    // Initialization of root node
      root = new TrieNode('\0');
    }

    // function to insert node into the tries

    void insertUtil(TrieNode* &root, string word) {
       if(word.length() == 0) {
         root->isTerminal = true;
         return;
       }
       // Assumption : Word will be in CAPS

       int index = word[0] - 'a';
       TrieNode* child;
       
       if(root->children[index] != NULL) {
          // Character Present
          child = root->children[index];
       } 
       else {
          // Character Absent
          child = new TrieNode(word[0]);
          root->children[index] = child;
       }

       // Recursive calls
       insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }

    // function to search in tries
    bool searchUtil(TrieNode* root, string word) {
       // Base case
       if(word.length() == 0) {
          return root->isTerminal;
       }

       // Finding index through mapping
       int index = word[0] - 'a';
       TrieNode* child;

       if(root->children[index] != NULL) {
         // Present
         child = root->children[index];
       }
       else {
         // Absent
         return false;
       }   

       // Recursive calls
       return searchUtil(child, word.substr(1));
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root, word);
    }

    // function to search the prefix present or not in tries
    bool prefixUtil(TrieNode* root, string word) {

       // Base case
       if(word.length() == 0){
          return true;
       }

       // Finding index through mapping
       int index = word[0] - 'a';
       TrieNode* child;

       if(root->children[index] != NULL){
          // Present
          child = root->children[index];
       } 
       else{
          // Absent
          return false;
       }

       // Recursive calls
       return prefixUtil(child, word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */

    bool startsWith(string prefix) {
       return prefixUtil(root, prefix);
    }

};

