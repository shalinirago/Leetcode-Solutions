class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        
        for (int i = 0; i < costs.size(); i++){
            int diff = costs[i][0] - costs[i][1];
            pq.push({diff, i});
        }
        int result = 0;
        
        for (int i = 0; i < costs.size()/2; i++){
            result += costs[pq.top().second][1];
            pq.pop();
        }
        
        for (int i = costs.size()/2; i < costs.size(); i++){
            result += costs[pq.top().second][0];
            pq.pop();
        }
        
        return result;
    }
};