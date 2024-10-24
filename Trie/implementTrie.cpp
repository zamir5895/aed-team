#include <String>

using namespace std;

struct TrieNode {
    TrieNode* childs[26];
    bool word;

    TrieNode(): word(false) {
        for (int i = 0; i < 26; i++){
            childs[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* act = root;
        for(char c : word) {
            int index = c - 'a';
            if (act->childs[index] == nullptr) {
                act -> childs[index] = new TrieNode();
            }
            act = act->childs[index];
        }
        act->word = true;
    }
    
    bool search(string word) {
        TrieNode* act = root;
        for(char c : word) {
            int index = c - 'a';
            if(act->childs[index] == nullptr) {
                return false;
            }
            act = act->childs[index];
        }
        return act->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* act = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(act->childs[index] == nullptr) {
                return false;
            }
            act = act->childs[index];
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