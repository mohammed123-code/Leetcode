class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1){
            return nums[0];
        }
        int count=0;
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
                if(count>maxi){
                    maxi=count;
                }
            }
            else{
                count=0;
            }
        }
        if(maxi==INT_MIN) return 0;
        return maxi;
    }
};