class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> vec{0};
        
        DFS(result, graph, vec, 0);
        
        return result;
    }
    
    void DFS(vector<vector<int>>& result, vector<vector<int>>& graph, vector<int>& vec, int index){
        if (index == graph.size()-1){
            result.push_back(vec);
            return;
        }
        
        for (int i = 0; i < graph[index].size(); i++){
            vec.push_back(graph[index][i]);
            DFS(result, graph, vec, graph[index][i]);
            vec.pop_back();
        }
    }
    
};