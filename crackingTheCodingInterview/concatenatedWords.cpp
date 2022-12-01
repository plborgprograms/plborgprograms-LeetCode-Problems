//https://leetcode.com/problems/concatenated-words/submissions/
class TrieNode
{
public:
    const static char BEGC = '`', ENDC = '{';
    TrieNode * m_children[27] = {nullptr};
    TrieNode(char c = BEGC)
    {
    }
    inline const TrieNode * operator[](char c) const
    {
        return m_children[c - 'a'];
    }
    inline TrieNode *& operator[](char c)
    {
        return m_children[c - 'a'];
    }
    virtual ~TrieNode ()
    {
        for (auto ptr : m_children)
            delete ptr;
    }
};

class Trie
{
public:
    TrieNode* root;
    const static char BEGC = TrieNode::BEGC, ENDC = TrieNode::ENDC;
    virtual ~Trie()
    {
        delete root;
    }
    Trie()
    {
        root = new TrieNode();
    }
    void insert(const string & word)
    {
        TrieNode *cur_node_ptr = root;
        for (const auto c : word)
        {
            TrieNode &cur_node = *cur_node_ptr;
            if (cur_node[c] == nullptr)
                cur_node[c] = new TrieNode(c);
            cur_node_ptr = cur_node[c];
        }
        TrieNode &cur_node = *cur_node_ptr;
        if (cur_node[ENDC] == nullptr)
            cur_node[ENDC] = new TrieNode(ENDC);
    }
};

class Solution {
    vector<string> results;
    Trie trie;
    bool isConcatenated(string const & word, int start)
    {
        TrieNode * cur_node_ptr = trie.root;
        for (int i = start; i < word.size(); ++i)
        {
            TrieNode & cur_node = *cur_node_ptr;
            if (cur_node[Trie::ENDC] != nullptr && isConcatenated(word, i))
            {   //if we've hit the end of the word or if the remainder can
                //be found by restarting at the top of the TRIE, return true
                return true;
            }
            cur_node_ptr = cur_node[word[i]];
            if (cur_node_ptr == nullptr)
            {
                return false;
            }
        }
        if ((*cur_node_ptr)[Trie::ENDC] != nullptr)
        {
            return true;
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs){return lhs.size() < rhs.size();});
        for (string word : words)
        {
            if (word.empty())
            {
                continue;
            }
            if (isConcatenated(word, 0))
            {
                results.push_back(word);
            }
            trie.insert(word);
        }
        return results;
    }
};