class Solution {
public:

    void func(int index, string digits, string keypad[], string res, vector<string>& ans) {
        if(index == digits.size()){
            if(!res.empty()){
                ans.push_back(res);
            }
            return;
        }

        int n = digits[index] - '0';
        string s1 = keypad[n];
        for(int i = 0; i < s1.size(); i++){
            func(index + 1, digits, keypad, res + s1[i], ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string keypad[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        func(0, digits, keypad, "", ans);
        return ans;
    }
};
