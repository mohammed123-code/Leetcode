class Solution {
public:
    int reverse(int n){
        int res=0;
        while(n!=0){
            res=res*10 + (n%10);
            n=n/10;
        }
        return res;
    }
    int mirrorDistance(int n) {
        int r=reverse(n);
        return abs(r-n);
    }
};