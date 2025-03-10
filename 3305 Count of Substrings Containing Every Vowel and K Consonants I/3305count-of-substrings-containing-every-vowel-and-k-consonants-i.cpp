class Solution {
public:
    int countOfSubstrings(string word, int k){
        int count=0;
        for(int x=0;x<word.size();x++){
            int a=0,e=0,i=0,o=0,u=0,con=0;
            for(int j=x;j<word.size();j++){
                if(word[j]=='a')
                    a++;
                else if(word[j]=='e')
                    e++;
                else if(word[j]=='i')
                    i++;
                else if(word[j]=='o')
                    o++;
                else if(word[j]=='u')
                    u++;
                else
                    con++;
                if(a>0 && e>0 && i>0 && o>0 && u>0 && con==k)
                    count++;
            }
        }
        return count;
    }
};