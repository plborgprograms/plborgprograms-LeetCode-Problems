//https://leetcode.com/problems/word-ladder/submissions/
class Solution {
public:

    struct Node
    {
        string word;
        vector<string> closeWords;
        int stepsFromStart = 0;
    };

    //vector<string> words;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        //O(n*wordLength)
		//iterate over the vector replacing each char with a '*'
		//as a wild card. this is used to build relations between
		//words. the beginNode is added to the queue. Iterate
		//over the related words using a breadth first search
		//if that wildcard list has already been examined, skip it
		//using a hashmap to check. Keep a running total of the 
		//number of steps from start using stepsFromStart.
		//contact plborgprograms@gmail.com for more questions.
		
		
        //compare if words are one off from each other
        //build a graph of words relating to one another
        wordList.emplace_back(beginWord);
        unordered_map<string, vector<Node*> > relatedWords;

        Node * beginNode = new Node();
        beginNode->word = beginWord;
        for(int l = 0; l < beginWord.length(); l++)
        {
            string wildWord = beginWord.substr(0,l) +'*' + beginWord.substr(l+1, beginWord.length());
            relatedWords[wildWord].emplace_back(beginNode);
            beginNode->closeWords.emplace_back(wildWord);
        }

		//this is O(n*wordLength)
        for(int i = 0; i < wordList.size(); i++)
        {
            Node * newNode = new Node();
            newNode->word = wordList[i];
            for(int l = 0; l < wordList[i].length(); l++)
            {
                string wildWord = wordList[i].substr(0,l) +'*' +wordList[i].substr(l+1, wordList[i].length());
                relatedWords[wildWord].emplace_back(newNode);
                newNode->closeWords.emplace_back(wildWord);
            }

        }


        //do an end to end traversal of words, keeping a hashmap of visited nodes
        unordered_map<string, bool> added;
        vector<Node*> bfsNodeQueue;
        bfsNodeQueue.emplace_back(beginNode);

        //this is O(n) considering any list cannot be run more than once due to the added statement
        while(bfsNodeQueue.size() > 0)
        {
            Node *currentNode = bfsNodeQueue[0];
            bfsNodeQueue.erase(bfsNodeQueue.begin());
            for(int i = 0; i < currentNode->closeWords.size(); i++)
            {
                if(!added[currentNode->closeWords[i]])
                {
                    for(int r = 0; r < relatedWords[currentNode->closeWords[i]].size(); r++)
                    {
                        if(relatedWords[currentNode->closeWords[i]][r]->word == endWord)
                        {
                            return currentNode->stepsFromStart+1;
                        }
                        else if(!added[ relatedWords[currentNode->closeWords[i]][r]->word ])
                        {
                            relatedWords[currentNode->closeWords[i]][r]->stepsFromStart = currentNode->stepsFromStart+1;
                            bfsNodeQueue.emplace_back( relatedWords[currentNode->closeWords[i]][r] );
                            added[relatedWords[currentNode->closeWords[i]][r]->word] = true;
                        }
                    }
                }
                added[currentNode->closeWords[i]] = true;
            }
        }

        //none found
        return 0;
    }

    /*bool wordsAreClose(string word1, string word2)
    {

    }*/

};