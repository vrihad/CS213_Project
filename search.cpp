#include"header.h"

int code(char ch) {
    if(ch>='A' && ch<='Z')
        return int(ch-'A');
    else if(ch>='a' && ch<='z')
        return int(ch-'a');
    else
        return -1;
};

void Trie::Add(cycle& object) {
    string brand = object.getBrand();
    string model = object.getModel();
    TrieNode* pt;

    pt = root;
    for (size_t i=0; i<brand.size(); i++) {
        int index = code(brand.at(i));
        if ((pt->children)[index] == NULL)
        {
            (pt->children)[index] = new TrieNode;
            ((pt->children)[index])->isLeaf = false;
            for(int j=0; j<ALPHABET_SIZE; j++)
                (((pt->children)[index])->children)[j] = NULL;
        }
        pt = (pt->children)[index];
    }
    pt->isLeaf = true;
    (pt->List).push_back(&object);

    pt = root;
    for (size_t i=0; i<model.size(); i++) {
        int index = code(model.at(i));
        if ((pt->children)[index] == NULL)
        {
            (pt->children)[index] = new TrieNode;
            ((pt->children)[index])->isLeaf = false;
            for(int j=0; j<ALPHABET_SIZE; j++)
                (((pt->children)[index])->children)[j] = NULL;
        }
        pt = (pt->children)[index];
    }
    pt->isLeaf = true;
    (pt->List).push_back(&object);
}

void Trie::Populate(vector<cycle>& Cycles) {
    for (size_t i=0; i<Cycles.size(); i++)
    {
        cout<<i;
        Add(Cycles.at(i));
    }
}

void Trie::Find(string word,vector<cycle*>& searchList) {
    searchList.clear();
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
    if (found && (pt->isLeaf)==true)
        searchList.insert(searchList.end(),(pt->List).begin(),(pt->List).end());
}
