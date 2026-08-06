class Solution {
public:
    int func(int n){
        int prod=1;
        while(n!=0){
            int rem=n%10;
            prod*=rem;
            n/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        // if(n<t)
        // return t;
        if(func(n)%t==0){
            return n;
        }
        
        for(int i=0;i<t;i++){
            if(func(n++)%t==0){
                return n-1;
            }
        }
        // while(1){
        //     if(func(n++)%t==0){
        //         return n-1;
        //     }
        // }
        
        return 0;
    }
};