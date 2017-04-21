// Date   : 2016.10.09
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
 * which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to 
 * finish all courses?
 * 
 * For example:
 *      2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
 * So it is possible.
 * 
 *      2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0, 
 * and to take course 0 you should also have finished course 1. So it is impossible.
 * 
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
 * Read more about how a graph is represented.
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 *  - This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, 
 *    no topological ordering exists and therefore it will be impossible to take all courses.
 *
 *  - Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic 
 *    concepts of Topological Sort. (https://class.coursera.org/algo-003/lecture/52)
 *
 *  - Topological sort could also be done via BFS. (http://en.wikipedia.org/wiki/Topological_sorting#Algorithms)
 * 
 *               
 **********************************************************************************/
//每次删除入度为0的点
class Solution {
public:
    vector<int>map[100010];
    bool toposort(vector<int>& indegree) {
        queue<int> q;
        for (int i=0;i<indegree.size();i++) 
            if (indegree[i]==0) q.push(i);
        int sum=0;
        while (!q.empty()) {
            int k=q.front();
            q.pop();
            sum++;
            for (int i=0;i<map[k].size();i++) {
                int temp=map[k][i];
                if (--indegree[temp]==0) q.push(temp);
            }
        }
        return sum==indegree.size();
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
       int n=prerequisites.size();
       vector<int> indegree(numCourses,0);
       for (int i=0;i<n;i++) {
           int u=prerequisites[i].first;
           int v=prerequisites[i].second;
           map[u].push_back(v);
           indegree[v]++;
       }
       return toposort(indegree);
    }
};
