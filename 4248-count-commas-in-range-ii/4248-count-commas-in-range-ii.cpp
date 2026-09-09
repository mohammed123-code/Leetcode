class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000){
            return 0;
        }


        long long count=0;
        long long m=1000;

        while(m<=n){
            count+=(n-m+1);
            if(m>LLONG_MAX/1000){
                break;
            }
            m*=1000;
        }
        
        return count;

        
    }
};