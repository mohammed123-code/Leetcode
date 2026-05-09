class Solution {
public:
    bool isValid(string code) {
        stack<string>st;
        int n=code.size();

        for(int i=0;i<n;){
            if(i>0 && st.empty()){
                return false;
            }

            //here we cheack for cdata(9size)
            if(code.substr(i,9)=="<![CDATA["){
                int j=code.find("]]>",i);
                if(j==string::npos) return false;
                i=j+2;
            }

            //close
            else if(code.substr(i,2)=="</"){
                int j=code.find('>',i);
                if(j==string::npos) return false;

                string name=code.substr(i+2,j-i-2);
                if(st.empty() || st.top()!=name) return false;

                st.pop();
                i=j+1;
            }


            //open
            else if(code[i]=='<'){
                int j=code.find('>',i);
                if(j==string::npos) return false;

                string name=code.substr(i+1,j-i-1);
                if(name.size()<1 || name.size()>9){
                    return false;
                }

                for(char ch : name){
                    if(!isupper(ch)) return false;
                }
                st.push(name);
                i=j+1;
            }



            



            else{
                i++;
            }
        }
        return st.empty();
    }
};