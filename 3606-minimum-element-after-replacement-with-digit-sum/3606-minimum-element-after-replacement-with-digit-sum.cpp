class Solution {
public:
    int minElement(vector<int>& nums) {
        string number="";
        int n=nums.size();
        for(int i=0;i<n;i++){
            number+=(to_string(nums[i]));
            number+="-";
        }
        

        for(int i=0;i<number.size();i++){
            int mini=0;
            if(number[i]!='-'){}
        }
    }
};