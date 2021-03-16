class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, result = -1, start_idx = 0;
        
        for (int i = 0; i < gas.size(); i++){
            tank = 0;
            if (tank+gas[i] < cost[i]){
                continue;
            }
            else{
                if (result == -1){
                tank = gas[i];
                start_idx = i;
                
                int idx = start_idx+1;
                if (idx >= gas.size()){
                    idx = 0;
                }

                while (idx < gas.size()){
                    if (idx > 0 && idx == start_idx && tank-cost[idx-1] >= 0)
                    {
                        result = start_idx;
                        break;
                    }

                    if (idx == 0){
                        if (idx == start_idx && tank-cost[cost.size()-1] >= 0){
                            result = start_idx;
                            break;
                        }
                        
                        tank = tank - cost[gas.size()-1];
                        
                    }
                    else{
                        tank = tank - cost[idx-1];
                    }
                    if (tank < 0){
                        break;
                    }
                    
                    tank += gas[idx];
                    idx++;

                    if (idx >= gas.size()){
                        idx = 0;
                    }
                    
                }
                }
            }
        }

        return result;
    }
};