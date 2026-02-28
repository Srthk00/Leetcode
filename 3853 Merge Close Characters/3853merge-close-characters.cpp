class Solution {
public:
    string mergeCharacters(string s, int k) {
        while(true){
            int n=s.size();
            bool merge=false;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n && j<i+k+1;j++){
                    if(s[i]==s[j]){
                        merge=true;
                        string temp=s.substr(0,j)+s.substr(j+1);
                        s=temp;
                        goto HERE;
                    }
                }
            }
            HERE:
            if(!merge){return s;}
        }
        return s;
    }
};