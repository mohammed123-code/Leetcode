class Solution {
public:
    void func(int index, string digits, vector<string>numpad, string ans, vector<string>&res){
        if(ans.size()==digits.size()){
            if(ans.size()!=0){
                res.push_back(ans);
            }
            return;
        }
        int n=digits[index]-'0';
        string str=numpad[n];
        for(int i=0;i<str.size();i++){
            func(index+1, digits, numpad, ans+str[i], res);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string>numpad={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>res;
        int index=0;
        string ans="";
        func(index, digits, numpad, ans, res);
        return res;
    }
};