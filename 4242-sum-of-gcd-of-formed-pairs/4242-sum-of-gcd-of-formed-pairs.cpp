class Solution {
public:
    long long gcdSum(vector<int>& nums){
        int n=nums.size();
        vector<int>prefixGcd(n);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
            }
            prefixGcd[i]=gcd(maxi,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int l=0;
        int r=n-1;
        long long sum=0;
        while(l<r){
            sum+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};