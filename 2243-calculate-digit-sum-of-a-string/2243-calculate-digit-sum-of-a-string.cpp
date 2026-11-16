class Solution {
public:
    string digitSum(string s, int k) {
       while(s.size() > k){
          vector<int> v;
          int x = k;
          int str = 0;
          for(int i = 0; i<s.size(); i++){
            str += (s[i] - '0');
            x--;
            if(x == 0){
               v.push_back(str);
               str = 0;
               x = k;
            }
         }
         if(str != 0) v.push_back(str);
         else{
            if((int)s.size()%k != 0) v.push_back(0); 
         }
           string ans;
         for(int i = 0; i<v.size(); i++){
            ans += to_string(v[i]);
         }
          s = ans;
       }
        return s;
    }
};