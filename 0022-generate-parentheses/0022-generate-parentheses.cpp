class Solution {
public:
    void generateAll(int n,string curr,int open,int close,vector<string>&result){
        if(curr.length()==2*n){
            
            result.push_back(curr); 
            
            return;        
        }
        if(open<n){
            generateAll(n,curr+"(",open+1,close,result);
        }
        if(close<open){
            generateAll(n,curr+")",open,close+1,result);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        generateAll(n,"",0,0,result);
        return result;
    }
};