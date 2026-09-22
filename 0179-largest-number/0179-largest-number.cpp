class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //herw we use custom sort
        vector<string>s;
        for(int i:nums)
        s.push_back(to_string(i));

        sort(s.begin(), s.end(), [](string a, string b){
            return a+b>b+a;
        });

        if(s[0]=="0"){
            return "0";
        }
        string res="";

        for(string str : s){
            res+=str;
        }
        return res;
    }
};