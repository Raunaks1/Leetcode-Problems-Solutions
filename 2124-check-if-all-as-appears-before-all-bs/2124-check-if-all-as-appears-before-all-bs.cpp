class Solution {
public:
    bool checkString(string s) {
        int cntb = 0;
        int ia = 0;
        int ib = s.size();
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'a'){
                ia = i;
            }
            else if(s[i] == 'b'){
                if(cntb==0){
                    ib = i;
                }
                cntb++;
            }
        }
        if(ia<=ib){
            return true;
        }
        else{
            return false;
        }
    }
};