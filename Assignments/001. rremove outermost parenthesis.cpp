class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        bool check = false;
        int size = s.size();
        string res = "";
        for(int i=0;i<size;i++){
            if(s[i] == "("){
                if(check){
                    count++;
                    res = res + s[i];
                }
                else{
                    check = true;
                }
            }
            else{
                if(count > 0){
                    count--;
                    res = res = s[i];
                }
                else{
                    check = false;
                }
            }

        }
        return res;
    }
};


//1021.