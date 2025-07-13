class Solution {
public:
    bool dfs(int course , vector<vector<int>>& graph, vector<bool> &visited, vector<bool>& resStack, stack<int>& st)
    {
        visited[course]=true;
        resStack[course]=true;
         for(int neighbour: graph[course])
         {
            if(!visited[neighbour])
            {
                if(!dfs(neighbour,graph,visited,resStack,st)) return false;
            }
            else if(resStack[neighbour]) return false;
         }

         resStack[course]=false;
         st.push(course);
         return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     vector<vector<int>> graph(numCourses);
     vector<bool> visited(numCourses,false);
     vector<bool> resStack(numCourses,false);
     stack<int> st;

     for(auto prereq: prerequisites)
     {
        graph[prereq[1]].push_back(prereq[0]);
     }

     for(int course=0;course<numCourses;course++)
     {
        if(!visited[course])
        {
            if(!dfs(course,graph,visited,resStack,st)) return {};
        }
     }

     vector<int> result;
     while(!st.empty())
     {
        result.push_back(st.top());
        st.pop();
     }

     return result;
    }
};