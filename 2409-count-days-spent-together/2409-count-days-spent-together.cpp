class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aam = 0, aad = 0; 
        int alm = 0, ald = 0;  
        int bam = 0, bad = 0;  
        int blm = 0, bld = 0;  

        string s = "";

        for(auto x : arriveAlice){
            if(x != '-') s += x;
            else {
                aam = stoi(s);
                s = "";
            }
        }
        aad = stoi(s);

        s = "";
        for(auto x : leaveAlice){
            if(x != '-') s += x;
            else {
                alm = stoi(s);
                s = "";
            }
        }
        ald = stoi(s);

        s = "";
        for(auto x : arriveBob){
            if(x != '-') s += x;
            else {
                bam = stoi(s);
                s = "";
            }
        }
        bad = stoi(s);

        s = "";
        for(auto x : leaveBob){
            if(x != '-') s += x;
            else {
                blm = stoi(s);
                s = "";
            }
        }
        bld = stoi(s);

        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        int aliceStart = aad;
        for(int i = 1; i < aam; i++)
            aliceStart += days[i - 1];

        int aliceEnd = ald;
        for(int i = 1; i < alm; i++)
            aliceEnd += days[i - 1];

        int bobStart = bad;
        for(int i = 1; i < bam; i++)
            bobStart += days[i - 1];

        int bobEnd = bld;
        for(int i = 1; i < blm; i++)
            bobEnd += days[i - 1];

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        if(start > end)
            return 0;

        return end - start + 1;
    }
};