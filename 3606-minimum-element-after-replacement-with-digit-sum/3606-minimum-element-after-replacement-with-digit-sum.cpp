class Solution {
public:
    int func(int a){
        int sum=0;
        while(a!=0){
            int rem=a%10;
            sum+=rem;
            a=a/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int n=nums.size();

        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(func(nums[i])<mini){
                mini=func(nums[i]);
            }
        }
        return mini;
    }
};