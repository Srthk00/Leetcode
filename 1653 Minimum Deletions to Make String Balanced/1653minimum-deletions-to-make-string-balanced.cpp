class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> aafter(n,0),bbefore(n,0);
        if(s[n-1]=='a'){aafter[n-1]=1;}
        for(int i=n-2;i>=0;i--){
            aafter[i]=aafter[i+1]+(s[i]=='a'?1:0);
        }
        if(s[0]=='b'){bbefore[0]=1;}
        for(int i=1;i<n;i++){
            bbefore[i]=bbefore[i-1]+(s[i]=='b'?1:0);
        }
        int result=INT_MAX;
        for(int i=0;i<n;i++){
            result=min(result,aafter[i]+bbefore[i]-1);
        }
        return result;
    }
};