class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,j=0;
        int n=chars.size();
        while(i<n && j<n){
            char temp=chars[i];
            int count=0;
            while(i<n && chars[i]==temp){
                i++;count++;
            }
            chars[j]=temp;
            j++;
            if(count>1){
                string num=to_string(count);
                for(char ch:num){
                    chars[j]=ch;
                    j++;
                }
            }
        }
        return j;
    }
};