#include"header.h"
#define ALPHABET_SIZE 26

int code(char ch) {
    return int(ch);
};

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

class Trie {
    TrieNode* root;
    Trie() {
        root = new TrieNode;
        root->isLeaf = false;

    };
    void Search(string);
    bool Add(string);
    bool Remove(string);
    void Populate(vector<vector<cycle> >);
};

void Trie::Search(string word) {
    TrieNode* pt;
    pt = root;
    string::iterator it;
    bool found = true;
    for (it=word.begin(); it<word.end(); it++) {
        int index = code(*it);
        if ((pt->children)[index] == NULL) {
            found = false;
            break;
        }
        else
            pt = (pt->children)[index];
    }
}

void Trie::Populate(vector<vector<cycle> > cycles) {
    // will use add to populate trie by adding each string.
}
