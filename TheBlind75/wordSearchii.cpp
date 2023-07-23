// https://leetcode.com/problems/word-search-ii/
class Solution {
    struct TrieNode {
        TrieNode *children[26];
        string word;

        TrieNode() : word("") {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        //O(m*n*w)
        //build a trie of the words you're searching for 
        TrieNode *root = buildTrie(words);
        vector<string> result;

        //search the board for the trie words
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (int j = 0; j < words.size(); j++) {
            string word = words[j];
            TrieNode *curr = root;
            for (int i = 0; i < word.length(); i++) {
                //if this char doesn't exist at this level in the trie, add it
                char c = word[i] - 'a';
                if (curr->children[c] == nullptr) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }

            //set the leaf node's word to the whole word
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result) {
        char c = board[i][j];

        //if the current char has already been used or it's not found at this level of the trie, return
        if (c == '#' || !p->children[c - 'a']) return;
        p = p->children[c - 'a'];

        //if the current node of the trie is a completed word,
        //add the word to the result and remove that word from the trie 
        if (p->word.size() > 0) {
            result.push_back(p->word);
            p->word = "";
        }

        //mark the current char as used
        board[i][j] = '#';

        //recur
        if (i > 0) dfs(board, i - 1, j, p, result);
        if (j > 0) dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);

        //unmark the current node as it is not being used
        board[i][j] = c;
    }
};