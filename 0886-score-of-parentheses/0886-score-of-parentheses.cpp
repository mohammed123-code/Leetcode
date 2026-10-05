class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int> st;
        st.push(0);



        for (char ch : s) {
            if(ch=='(') {
                st.push(0);
            }else{
                int a=st.top();
                st.pop();

                if(a==0) {
                    int b=st.top();
                    st.pop();
                    st.push(b+1);
                }else{
                    int b=st.top();
                    st.pop();
                    st.push(b+2*a);
                }
            }
        }




        return st.top();
    }
};