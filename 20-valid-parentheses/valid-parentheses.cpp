class Solution {
public:
    bool isValid(string s) {
        stack<char> st1;
        if(s.size()%2!=0){
            return false;
        }
        else{
            for(int i=0;i<s.size();i++){
                if(s[i]=='{'||s[i]=='['||s[i]=='('){
                    st1.push(s[i]);
                }
                else {
                    if(st1.empty()){
                        return false; // Stack is empty, so no matching opening bracket
                    }
                    // Check if the top element of the stack matches the current closing bracket
                    if(s[i]=='}' && st1.top()!='{'){
                        return false;
                    }
                    else if(s[i]==']' && st1.top()!='['){
                        return false;
                    }
                    else if(s[i]==')' && st1.top()!='('){
                        return false;
                    }
                    st1.pop(); // Remove the matching opening bracket from the stack
                }
            }
            return st1.empty(); // Check if the stack is empty after processing all characters
        }
    }
};
