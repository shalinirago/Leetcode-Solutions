class Solution {
public:
    int maxDepth(string s) {
        stack<pair<char, int>> st;
        int level = 0;
        
        if (s.empty()){
            return level;
        }
        
        for (int i = 0; i < s.size(); i++){
            char ch = s[i];
            
            if (ch == '('){
                if (st.empty()){
                    st.push({ch, 1});    
                }else{
                    pair<char, int> top = st.top();
                    st.push({ch, top.second+1});

                }                
            }
            else if (ch == ')'){
                st.pop();
            }
            else{
                continue;
            }
            
            if (!st.empty()){
                pair<char, int> top = st.top();
                level = max(level, top.second);
            }
        }
        
        return level;
    }
};