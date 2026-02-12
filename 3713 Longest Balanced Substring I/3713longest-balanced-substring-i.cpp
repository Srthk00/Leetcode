class Solution {
public:
    int longestBalanced(string s) {
        int result=0;
        int i=0;
        while(i<s.size()){
            vector<int> freq(26,0);
            int j=i;
            while(j<s.size()){
                freq[s[j]-'a']++;
                int temp=-1;bool flag=true;
                for(int k=0;k<26;k++){
                    if(freq[k]!=0 && temp==-1){temp=freq[k];}
                    else if(freq[k]==0 || freq[k]==temp){continue;}
                    else{flag=false;break;}
                }
                if(flag){result=max(result,j-i+1);}
                j++;
            }
            i++;
        }
        return result;
    }
};