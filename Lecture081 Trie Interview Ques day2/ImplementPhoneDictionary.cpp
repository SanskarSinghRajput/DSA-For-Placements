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

    void printSugesstions(TrieNode* curr, vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
            return ;
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
            TrieNode* next = curr->children[ch-'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSugesstions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string> > getSuggestions(string str){
        TrieNode* prev = root;
        vector<vector<string> > output;
        string prefix = "";

        for(int i=0; i<str.length(); i++){
            char lastch = str[i];

            prefix.push_back(lastch);

            //check for lastch
            TrieNode* curr = prev->children[lastch - 'a'];

            //if not found
            if(curr == NULL)[
                break;
            ]

            //if found
            vector<string> temp;
            printSugesstions(curr, temp, prefix);
        
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr){
    //creation of trie
    Trie *t = new Trie();

    //insert all contact in trie
    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    //return ans
    return t->getSuggestions(queryStr);
}