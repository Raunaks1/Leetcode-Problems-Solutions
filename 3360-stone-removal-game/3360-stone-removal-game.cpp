class Solution {
public:
    bool canAliceWin(int n) {
        int start = 10;
        if(n<10){
            return false;
        }
        bool alice = true;
        int turn = 0;
        while(n-start>=0){
            if(turn%2 == 0){
                alice = true;
            }
            else{
                alice = false;
            }
            n -= start;
            start--;
            turn++;
        }

        return alice;
        
    }
};