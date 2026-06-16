class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        st.push(num[0]);

        int i = 1;

        while(i < num.size()){

            while((!st.empty()) && k != 0 && st.top() > num[i]){
                st.pop();
                k--;
            }

            st.push(num[i]);

            i++;
        }

        while(k != 0 && !st.empty()){
            st.pop();
            k--;
        }

        string res = "";

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());


        //leading zeros remove
        int j = 0;

        while(j < res.size() && res[j] == '0'){
            j++;
        }

        res = res.substr(j);

        if(res.empty()){
            return "0";
        }

        return res;
    }
};