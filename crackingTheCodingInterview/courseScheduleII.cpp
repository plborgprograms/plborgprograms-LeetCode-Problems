//https://leetcode.com/problems/course-schedule-ii/submissions/
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& P) {
        vector<vector<int>> prereq(N);
        vector<int> result, courses(N);
        
        //courses is initialized with the count of prereqs for it and then set to -1, when it's checked
        for(auto& entry : P)
        {
            prereq[entry[1]].push_back(entry[0]),
            courses[entry[0]]++;
        }
        
        function<void(int)> dfs = [&](int index) 
        {
            result.push_back(index);                      // take cur course & push it into ordering
            courses[index] = -1;                         // and mark it as visited
            for(auto nextCourse : prereq[index])
            {
                if(--courses[nextCourse] == 0)     // if there's a next course having 0 prequisite remaining,
                {
                    dfs(nextCourse);                // then we can take it
                }
            }
        };
        
        
        for(int i = 0; i < N; i++)
        {
            if(courses[i] == 0)                    // we can start with courses having no prequisites
            {
                dfs(i);
            }
        }
        
        //if the result contains all the courses, return it
        if(size(result) == N)
        {
            return result;
        }
        
        return {};
    }
};