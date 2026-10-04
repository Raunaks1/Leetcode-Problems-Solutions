class Solution {
public:
    bool checkValidString(string s) {
        int a = 0, b = 0;
        for(char i:s){
            if(i == '('){
                a++;
                b++;
            } 
            else if(i == ')'){
                a = max(0,a - 1);
                b--;
            } 
            else{
                a = max(0,a - 1);
                b++;
            }
            if(b < 0) 
                return false;
        }
        return a == 0;
    }
};