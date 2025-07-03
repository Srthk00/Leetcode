class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        int len=1;
        while(len<k){
            string temp=word;
            for(int i=0;i<temp.size();i++){
                temp[i]=(temp[i]=='z')?'a':temp[i]+1;
            }
            word=word+temp;
            len+=temp.size();
        }
        return word[k-1];
    }
};