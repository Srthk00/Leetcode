class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){return word;}
        int n=word.size();
        char lar=word[0];
        for(char ch:word){
            if(ch>lar){lar=ch;}
        }
        set<string> result; 
        for(int i=0;i<n;i++){
            if(word[i]==lar){
                int temp=n-numFriends+1;
                int last=(temp>n-1)?n-1:temp;
                result.insert(word.substr(i,temp));
            }
        }
        return *result.rbegin();
    }
};