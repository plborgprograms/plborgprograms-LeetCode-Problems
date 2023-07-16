//https://leetcode.com/problems/implement-trie-prefix-tree/submissions/
class Trie {
public:
    class TreeNode
    {
        public:
        char character;
        unordered_map<char, TreeNode*> children;
        TreeNode(char c)
        {
            character = c;
        }
    };

    TreeNode * root;
    char endChar = '\n';
    Trie() {
        root = new TreeNode(' ');
    }
    
    void insert(string word) 
    {
		//O(N)
        TreeNode * current = root;
        for(int w = 0; w < word.length(); w++)
        {
            if(current->children[word[w]] == nullptr)
            {
                current->children[word[w]] = new TreeNode(word[w]);
            }
            current = current->children[word[w]];
        }
        if(current->children[endChar] == nullptr)
        {
            current->children[endChar] = new TreeNode(endChar);
        }
    }
    
    bool search(string word) 
	{
		//O(N)
        TreeNode * current = root;
        for(int w = 0; w < word.length(); w++)
        {
            if(current->children[word[w]] == nullptr)
            {
                return false;
            }
            current = current->children[word[w]];
        }
        //return true;
        return current->children[endChar] != nullptr ;
    }
    
    bool startsWith(string prefix) 
	{
		//O(N)
        TreeNode * current = root;
        for(int w = 0; w < prefix.length(); w++)
        {
            if(current->children[prefix[w]] == nullptr)
            {
                return false;
            }
            current = current->children[prefix[w]];
        }
        return true;
        //return current->children[endChar] != nullptr ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */