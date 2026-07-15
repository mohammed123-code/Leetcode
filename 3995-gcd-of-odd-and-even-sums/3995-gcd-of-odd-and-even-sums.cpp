class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum=-1;
        int evenSum=0;

        int odd=0;
        int even=0;
        for(int i=0;i<n;i++){
            oddSum+=2;
            odd+=oddSum;

            evenSum+=2;
            even+=evenSum;
        }

        return gcd(odd, even);
    }
};