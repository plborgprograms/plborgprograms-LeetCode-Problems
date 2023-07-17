//https://leetcode.com/problems/design-add-and-search-words-data-structure/submissions/
class WordDictionary {
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
    char endChar = '%';

    WordDictionary() {
        root = new TreeNode(' ');
    }
    
    void addWord(string word) {
        insert(word);
    }

     bool search(string word) {
         return innerSearch(word, root);
     }

    
    bool innerSearch(string word, TreeNode* current) {
        //O(N^2)

        //search the Trie as usual; in cases of '.', search all possible child entries
        for(int w = 0; w < word.length(); w++)
        {
            if(word[w] == '.')
            {

                if(current->children.empty())
                {
                    return false;
                }
                else
                {
                    //string remainingWord = word.substr(w+1,word.length()-(w+1));
                    for(auto it=current->children.begin(); it!=current->children.end(); it++) 
                    {                        
                        if(it->first != endChar)
                        {
                            //bool result = innerSearch(remainingWord,current->children[it->first]);
                            bool result = innerSearch(word.substr(w+1,word.length()-(w+1)),current->children[it->first]);
                            if(result)
                            {
                                return true;
                            }
                        }
                    }
                    return false;
                }
            }
            else
            {
                if( current->children.find(word[w]) == current->children.end() )
                {
                    return false;
                }
                current = current->children[word[w]];
            }
        }

       return current->children.find(endChar) != current->children.end();
    }


    /*void printSubTree(TreeNode * current, string indentation)
    {
        for(auto it=current->children.begin(); it!=current->children.end(); it++) 
        {    
            if(it->second != nullptr)
            {
                cout << indentation << it->first << endl;
                printSubTree(it->second, indentation + " ");
            }
            else
            {
                cout << indentation << it->first << "null" << endl;
            }
        }
    }*/
    
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

        //cout << "printing:" << endl;
        //printSubTree(root, "");
    }
    
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */