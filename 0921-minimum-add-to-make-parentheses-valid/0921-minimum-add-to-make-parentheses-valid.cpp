class Solution {
public:
    int minAddToMakeValid(string s) {
        int level = 0;
        int neg = 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                level ++;
            }else {
                level --;
                if(level < 0){
                    neg ++;
                    level = 0;
                }
            }
        }

        return neg + level;
    }
};