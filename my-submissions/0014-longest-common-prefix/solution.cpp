class Node {
public:
    unordered_map<char, Node *> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node *root;
public: 
    Trie() {
        root = new Node();
    }

    void insert(string key) {
        Node *temp = root;
        for(int i = 0; i < key.size(); i++) {
            if(temp -> children.count(key[i]) == 0) {
                temp -> children[key[i]] = new Node();
            }
            temp = temp -> children[key[i]];
        }
        temp -> endOfWord = true;
    }

    string findLCP() {
        string ans = "";
        Node *curr = root;
        
        while(curr -> children.size() == 1 && !curr -> endOfWord) {
            // return the iterator of the first entry in map
            auto it = curr -> children.begin();     

            ans.push_back(it -> first);     // character at it
            curr = it -> second;            // next node pointer
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(int i = 0; i < strs.size(); i++) {
            trie.insert(strs[i]);
        }
        return trie.findLCP();
    }
};
