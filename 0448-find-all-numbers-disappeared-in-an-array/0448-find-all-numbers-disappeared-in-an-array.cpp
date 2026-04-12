class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int index=0; //correct Index
        while(i<n){
            index=nums[i]-1;
            if(nums[i]!=nums[index]){
                swap(nums[i],nums[index]);
            }
            else{
                i++;
            }
        }


        vector<int>res;
        for(int i=1;i<=n;i++){
            if(i!=nums[i-1]){
                res.push_back(i);
            }
        }
        return res;
    }
};