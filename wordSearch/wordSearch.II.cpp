

const int MAX_CHARS = 26;

class TrieNode {
    public:
        TrieNode(string s):isWord(false), word(s) {
            memset(children, 0, sizeof(children));
        }
        TrieNode* & operator [] (char ch) {
            return children[(ch - 'a') % MAX_CHARS];
        }
        TrieNode* & operator [] (int idx) {
            return children[idx % MAX_CHARS];
        }

    public:
        string word;
        bool isWord;
    private:
        TrieNode* children[MAX_CHARS];
};

class TrieTree {
    public:
        TrieTree():root(new TrieNode("")) { }
        ~TrieTree() { freeTree(root); }
        TrieNode* getRoot() {
            return root;
        }
        void addWord(string& s){
            TrieNode *node = root;
            string t;
            for (int i=0; i<s.size(); i++){
                t += s[i];
                if ( (*node)[s[i]] == NULL ){
                    (*node)[s[i]] = new TrieNode(t);
                }
                node = (*node)[s[i]];
            }
            node->isWord = true;
        }
    private:
        void freeTree(TrieNode* node){
            for(int i=0; i<MAX_CHARS; i++){
                if ((*node)[i]!=NULL){
                    freeTree((*node)[i]);
                }
            }
            delete node;
        }
        TrieNode *root;

};

class Solution {
public:
    void findWords(vector<vector<char>>& board, TrieNode* root, int row, int col, vector<string>& result){
        if (row < 0 || col < 0 || 
                row >= board.size() || 
                col >= board[row].size() ||
                board[row][col] == '\0' ) {
            return;
        }
        
        char ch = board[row][col];
        root = (*root)[ch];
        
        if (root==NULL) return;
        
        if (root->isWord){
            result.push_back(root->word);
            root->isWord = false;
        }
        
        
        board[row][col] = '\0';
        
        findWords(board, root, row, col - 1, result);
        findWords(board, root, row, col + 1, result);
        findWords(board, root, row + 1, col, result);
        findWords(board, root, row - 1, col, result);
        
        board[row][col] = ch;
        
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieTree t;
        for (int i = 0; i<words.size(); i++){
            t.addWord(words[i]);
        }
        
        vector<string> result;
        for (int i = 0; i<board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) { 
                findWords(board, t.getRoot(), i, j, result);
            }
        }
        return result;            
    }

};

