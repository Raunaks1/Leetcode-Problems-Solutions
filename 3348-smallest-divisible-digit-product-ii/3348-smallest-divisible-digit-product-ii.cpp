#include <bits/stdc++.h>
using namespace std;

static const int E2[10]={0,0,1,0,2,0,1,0,3,0};
static const int E3[10]={0,0,0,1,0,0,1,0,0,2};
static const int E5[10]={0,0,0,0,0,1,0,0,0,0};
static const int E7[10]={0,0,0,0,0,0,0,1,0,0};

class Solution {
public:
    int A,B;
    vector<vector<int>> cnt;
    vector<vector<string>> seqs;

    string ins(const string&s, char c){
        string r=s; r.push_back(c); sort(r.begin(), r.end()); return r;
    }

    void buildDP(){
        cnt.assign(A+1, vector<int>(B+1, INT_MAX));
        seqs.assign(A+1, vector<string>(B+1, string()));
        cnt[0][0]=0; seqs[0][0]="";
        int opt[6]={2,3,4,6,8,9};
        for(int i=0;i<=A;i++) for(int j=0;j<=B;j++){
            if(i==0&&j==0) continue;
            for(int k=0;k<6;k++){
                int d=opt[k];
                int pi=max(0,i-E2[d]), pj=max(0,j-E3[d]);
                if(cnt[pi][pj]==INT_MAX) continue;
                int nc=cnt[pi][pj]+1;
                string ns=ins(seqs[pi][pj],'0'+d);
                if(nc<cnt[i][j] || (nc==cnt[i][j] && ns<seqs[i][j])){
                    cnt[i][j]=nc; seqs[i][j]=ns;
                }
            }
        }
    }

    int minNon(int r2,int r3,int r5,int r7){ return r5+r7+cnt[r2][r3]; }

    string build(int len,int r2,int r3,int r5,int r7){
        string meaningful = seqs[r2][r3];
        meaningful.append(r5,'5');
        meaningful.append(r7,'7');
        sort(meaningful.begin(), meaningful.end());
        int ones = len - (int)meaningful.size();
        return string(ones,'1') + meaningful;
    }

    string smallestNumber(string num, long long t) {
        int a=0,b=0,c=0,d=0;
        while(t%2==0){t/=2;a++;}
        while(t%3==0){t/=3;b++;}
        while(t%5==0){t/=5;c++;}
        while(t%7==0){t/=7;d++;}
        if(t!=1) return "-1";
        A=a; B=b;
        buildDP();
        int n=num.size();

        vector<int> p2(n+1,0),p3(n+1,0),p5(n+1,0),p7(n+1,0);
        int firstZero=n;
        for(int i=0;i<n;i++){
            int dg=num[i]-'0';
            p2[i+1]=p2[i]+E2[dg];
            p3[i+1]=p3[i]+E3[dg];
            p5[i+1]=p5[i]+E5[dg];
            p7[i+1]=p7[i]+E7[dg];
            if(dg==0 && firstZero==n) firstZero=i;
        }

        if(firstZero==n){
            if(p2[n]>=a && p3[n]>=b && p5[n]>=c && p7[n]>=d) return num;
        }

        int hi = min(n-1, firstZero);
        for(int i=hi;i>=0;i--){
            int px2=p2[i],px3=p3[i],px5=p5[i],px7=p7[i];
            int cur=num[i]-'0';
            int sufLen=n-1-i;
            for(int dd=cur+1;dd<=9;dd++){
                int r2=max(0,a-px2-E2[dd]);
                int r3=max(0,b-px3-E3[dd]);
                int r5=max(0,c-px5-E5[dd]);
                int r7=max(0,d-px7-E7[dd]);
                if(minNon(r2,r3,r5,r7)<=sufLen){
                    string suf=build(sufLen,r2,r3,r5,r7);
                    return num.substr(0,i) + char('0'+dd) + suf;
                }
            }
        }

        int need = minNon(a,b,c,d);
        int L = max(n+1, need);
        return build(L,a,b,c,d);
    }
};