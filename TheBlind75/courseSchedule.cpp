//https://leetcode.com/problems/course-schedule/submissions/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //declare a graph with all connections
        vector<vector<int>> g = buildGraph(numCourses, prerequisites);

        //declare a series of vectors to keep track of which have been visited
        vector<bool> hasAlreadyBeenViewedInThisCycle(numCourses, false), done(numCourses, false);

        for (int i = 0; i < numCourses; i++) {

            //only run acyclic if you haven't already checked this node
            if (!done[i])
            {
                if(!acyclic(g, hasAlreadyBeenViewedInThisCycle, done, i))
                {
                    return false;
                }
            }
        }
        return true;
    }

private:
    
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        //build a graph and a declare all connections 
        vector<vector<int>> g(numCourses);
        for (auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    
    bool acyclic(vector<vector<int>>& g, vector<bool>& hasAlreadyBeenViewedInThisCycle, vector<bool>& done, int node) 
    {
        //if a node is visted and is seen again, return false, indicating there's a loop
        if (hasAlreadyBeenViewedInThisCycle[node]) {
            return false;
        }

        //if this node has already been checked for loops outside this current section, return true, indicating 'search elsewhere'
        if (done[node]) {
            return true;
        }

        //mark the node as visited
        hasAlreadyBeenViewedInThisCycle[node] = done[node] = true;

        //check all the child courses
        for (int v : g[node]) {
            if (!acyclic(g, hasAlreadyBeenViewedInThisCycle, done, v)) {
                return false;
            }
        }

        //reset the variable related to the loop
        hasAlreadyBeenViewedInThisCycle[node] = false;
        return true;
    }


};