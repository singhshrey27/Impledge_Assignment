#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
};

class Trie {
    
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    TrieNode* getRoot() {
        return root;
    }
};


bool canBeFormed(const string& word, Trie& trie, bool isOriginalWord = true) {
    if (word.empty()) {
        return false;
    }

    TrieNode* node = trie.getRoot();
    
    for (int i = 0; i < word.length(); ++i) {
        char ch = word[i];
        if (node->children.find(ch) != node->children.end()) {
            node = node->children[ch];
            if (node->isEndOfWord) {
                if (i == word.length() - 1) {
                    if (isOriginalWord) {
                        return false;
                    }
                    return true;
                }
                if (canBeFormed(word.substr(i + 1), trie, false)) {
                    return true;
                }
            }
        }
        else {
            return false;
        }
    }
    return false;
}

vector<string> findLongestAndSecondLongestCompoundWords(vector<string>& words) {
    Trie trie;
    vector<string> result;

    sort(words.begin(), words.end(), [&](const string& a, const string& b) {
        return b.length() < a.length();
    });
    
    for (string& word : words) {
        if (canBeFormed(word, trie)) {
            result.push_back(word);
            return result; 
        }
        trie.insert(word);
    }
   
    return result;
}


void processInputFile(const string& fileName) {
    const auto start = high_resolution_clock::now();

    ifstream inputFile(fileName);
    vector<string> words;
    string word;

    while (getline(inputFile, word)) {
        words.push_back(word);
    }

    inputFile.close();

    vector<string> ans = findLongestAndSecondLongestCompoundWords(words);
    
    int n=ans.size();
    sort(ans.begin(),ans.end());
    
    const auto end = high_resolution_clock::now();
    const auto timeTaken = duration_cast<milliseconds>(end - start).count();
    
    cout << "For " << fileName << ":\n";
   
    cout << "Longest Compounded Word: " << ans[n-1] << '\n';
    cout << "Second Longest Compounded Word: " << ans[n-2] << '\n';
    
    cout << "Time Taken: " << timeTaken << " ms\n";
}

int main() {
    vector<string> inputFiles = {"Input_01.txt", "Input_02.txt"};

    for (const string& inputFile : inputFiles) {
        processInputFile(inputFile);
    }

    return 0;
}
