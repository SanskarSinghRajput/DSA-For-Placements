// Check Valid Parenthesis 

class Solution {
  public:
    // Optimized Approach
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            //if opening bracket, stack push
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
              st.push(s[i]);
            //if close bracket, stacktop check and pop
            else{
                //for closing bracket
                if(!st.empty() && ( (st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']') ) )
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
           return true;
        else
           return false;
    }
};

bool isValidParenthesis(string expression){
  	 stack<char> s;
     for(int i=0; i<expression.length(); i++) { 
         char ch = expression[i]; 
         //if opening bracket, stack push
         //if close bracket, stacktop check and pop
         if(ch == '(' || ch == '{' || ch == '['){
             s.push(ch);
         }
         else{
             //for closing bracket
             if(!s.empty()) {
                  char top = s.top();
                  if((ch == ')' && top == '(') || ( ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                      s.pop();
                  }
                 else{
                     return false;
                 }
             }
             else{
                 return false;
             } 
         }  
     }
    
    if(s.empty())
        return true;
    else
        return false;
}