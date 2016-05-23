
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

const int MAX_CHARS = 26;

class TrieTree {
public:
    TrieTree():root(new TrieNode()){ }
    ~TrieTree() { freeTree(root); }
    
    void put(string &s) {
        TrieNode* node = root;
        for (int i=0; i<s.size(); i++){
            if ((*node)[s[i]] == NULL){
                (*node)[s[i]] = new TrieNode();
            }
            node = (*node)[s[i]];
        }
        node->isWord = true;
    }
    bool search(string &s){
        return get(s, this->root);
    }

private:

    bool get(string &s, TrieNode* root, int idx=0){
        TrieNode* node = root;
        for (int i=idx; i<s.size(); i++){
            if (s[i]!='.'){
                node = (*node)[s[i]];
                if (node == NULL) return false;
            }else{
                for (int j=0; j<MAX_CHARS; j++) {
                    TrieNode *p = (*node)[j];
                    if (p == NULL ) {
                        continue;//try next
                    }
                    // p!=NULL
                    if (i<s.size()-1) {
                        if (this->get(s, p, i+1)) {
                            return true;
                        }
                        continue; //try next
                    }
                    // p!=NULL && i == s.size()-1
                    if (p->isWord) {
                        return true;
                    }
                }
                return false;
            }
        }
        return node->isWord; 
    }
    
private:
    void freeTree(TrieNode* root){
        for(int i=0; i<MAX_CHARS; i++){
            if ((*root)[i]!=NULL){
                freeTree((*root)[i]);
            }
        }
        delete root;
    }
    TrieNode *root;
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        tree.put(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return tree.search(word);
    }
private:
    TrieTree tree;
};


int main()
{
    WordDictionary wd;
    wd.addWord("a");
    cout << wd.search("a.") <<endl;;
    cout << wd.search(".a") << endl;;
    wd.addWord("bad");
    cout << wd.search("bad") <<endl;;
    cout << wd.search("b..") <<endl;;
    return 0;
}



