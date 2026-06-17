class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;


        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }


        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==0){
                maxi=max(maxi,i+1);
            }
            if(mp.find(sum) != mp.end()){
                maxi = max(maxi, i - mp[sum]);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return maxi;
    }
};