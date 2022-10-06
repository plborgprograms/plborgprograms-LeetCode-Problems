//https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        
        //set each instance in the vector to its own index
        iota(parent.begin(), parent.end(), 0);
    }
    
    
    int findRootParent(int x)
    {
        //keep moving throughout the tree until you find the one that points to itself: the root
        int current = x;
        while(current != parent[current])
        {
            current = parent[current];
        }
        return current;
    }
    
    void printTrees()
    {
        cout << "\nparent:\n";
        for(int x = 0; x < parent.size(); x++)
        {
            cout << parent[x] << " ";
        }
        
        cout << "\n\nrank:\n";
        for(int x = 0; x < rank.size(); x++)
        {
            cout << rank[x] << " ";
        }
    }
    bool Union(int x, int y)
    {
        //find the top of each tree
        int xp = findRootParent(x);
        int yp = findRootParent(y);
        
        //find if they have a common parent in tree
        if(xp == yp)
        {
            return true;
        }
        else 
        {
            //link the roots of the trees together
            //make the root the one that already has had a tiebreaker
            if(rank[xp] > rank[yp])
            {
                parent[yp] = xp;
            }
            else if (rank[xp] < rank[yp])
            {
                parent[xp] = yp;
            }
            else 
            {
                parent[yp] = xp;
                rank[xp]++;
            }
            return false;
        }
    }
    
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        DSU uf(n);
        for(int i=0; i<edges.size(); i++) 
        {
            uf.Union(edges[i][0], edges[i][1]);
        }
        //uf.printTrees();
        return uf.Union(source, destination);
    }
};