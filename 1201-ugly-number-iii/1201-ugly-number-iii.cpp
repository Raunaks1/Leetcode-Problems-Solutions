class Solution {
public:
    int nthUglyNumber(int n, int a1, int b1, int c1) {
        long long a=a1;
        long long b=b1;
        long long c=c1;
        long long l=min(a,min(b,c));
        long long r=l*n;
        long long ab=__gcd(a,b);
        long long bc=__gcd(b,c);
        long long ca=__gcd(c,a);
        long long abc=__gcd(ab,bc);
        while(l<r){
            long long mid=(l+r)/2;
            long long count=0;
            count+=mid/a;
            count+=mid/b;
            count+=mid/c;
            count-=mid/((a*b)/ab);
            count-=mid/((b*c)/bc);
            count-=mid/((c*a)/ca);
            count+=mid/(((((c*a*b)/ab)/ca)/bc)*abc);
            if(count<n){
                l=mid+1;
            }
            else {
                r=mid;
            }
        }
        return r;
    }
};