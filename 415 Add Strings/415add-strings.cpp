class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1=="0"){return num2;}
        string result="";
        int carry=0,i=num1.size()-1,j=num2.size()-1;
        while(i>=0 && j>=0){
            int temp=(num1[i--]-'0')+(num2[j--]-'0')+carry;
            carry=temp/10;
            temp%=10;
            result=to_string(temp)+result;
        }
        while(i>=0){
            int temp=(num1[i--]-'0')+carry;
            carry=temp/10;
            temp%=10;
            result=to_string(temp)+result;
        }
        while(j>=0){
            int temp=(num2[j--]-'0')+carry;
            carry=temp/10;
            temp%=10;
            result=to_string(temp)+result;
        }
        if(carry){
            result=to_string(carry)+result;
        }
        return result;
    }
};