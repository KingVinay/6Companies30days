#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWordEnd;

    TrieNode() : children(26, nullptr), isWordEnd(false) {
    }

    void insert(const string& word) {
        TrieNode* current = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                
                current->children[index] = new TrieNode;
            }
            current = current->children[index]; 
        }
        current->isWordEnd = true;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary():root(new TrieNode()) {
        
    }
    
    void addWord(string word) {
        root->insert(word);
    }
    
    bool search(string word) {
        return dfsSearch(word, 0, root);
    }

private:
    bool dfsSearch(const string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isWordEnd;
        }

        char ch = word[index];
        if (ch != '.') {
            
            TrieNode* child = node->children[ch - 'a']; 
            if (child && dfsSearch(word, index + 1, child)) {
                return true;
            }
        } else {
            for (TrieNode* child : node->children) {
                if (child && dfsSearch(word, index + 1, child)) {
                    
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main()
{
  WordDictionary wordDictionary;
  wordDictionary.addWord("word");
  cout << wordDictionary.search("word") << endl;  // return true
  cout << wordDictionary.search("pattern") << endl;  // return false
  return 0;
}