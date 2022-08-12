
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(n == 0 || n == 1){
            return false;
        }
        bool attendance = true;
        for(int i = 0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    attendance = false;
                    break;
                }
            }
             else if(s[i] == ']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    attendance = false;
                    break;
                }
            }
             else if(s[i] == '}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    attendance = false;
                    break;
                }
            }
            else{
                attendance = false;
                break;
            }
        }
        if(!st.empty()){
            attendance = false;
        }
        return attendance;
    }
};