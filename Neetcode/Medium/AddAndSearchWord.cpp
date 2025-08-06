/*
Notes - 
 "" (false)
b 
a
d 
(true)
*/
#include <unordered_map>
#include <string>

using namespace std;

class WordDictionary {
public:
     class TrieNode {
     public:
        bool endOfWord;
        unordered_map<char, TrieNode*> children;
        TrieNode(bool endOfWord) : endOfWord{endOfWord} {            
        }

        ~TrieNode() {
            for (auto& node : children)
                delete node.second;
        }
    };

    WordDictionary() : root{new TrieNode(false)} {
    }
    
    void addWord(string word) {    
        TrieNode *node = root;
        for (int i=0; i < word.size(); i++) {
            if (node->children.find(word[i]) == node->children.end())
                node->children[word[i]] = new TrieNode(false);
            node = node->children[word[i]];
        }    
        node->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, root);
    }

    ~WordDictionary() {
        delete root;
    }

private: 
    bool dfs (string word, TrieNode *curr) {

        for (int i=0; i < word.size(); i++) {
            if (word[i] == '.') {
                bool result = false;
                for (auto &next : curr->children) {
                    result = result | dfs(word.substr(i + 1), next.second);
                }

                return result;                
            }

            if (curr->children.find(word[i]) == curr->children.end())
                return false;
            curr = curr->children[word[i]];
        }

        return curr->endOfWord;
    }

    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */