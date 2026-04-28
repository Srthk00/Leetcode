class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.size() && j<version2.size()){
            int t1=i,t2=j;
            while(t1<version1.size() && version1[t1]!='.'){
                t1++;
            }
            while(t2<version2.size() && version2[t2]!='.'){
                t2++;
            }
            string s1=version1.substr(i,t1-i);
            string s2=version2.substr(j,t2-j);
            int num1=stoi(s1);
            int num2=stoi(s2);
            if(num1<num2){return -1;}
            else if(num1>num2){return 1;}
            i=t1+1;j=t2+1;
        }
        for(int x=i;x<version1.size();x++){
            if(version1[x]!='.'){
                if(version1[x]-'0'>0){return 1;}
            }
        }
        for(int x=j;x<version2.size();x++){
            if(version2[x]!='.'){
                if(version2[x]-'0'>0){return -1;}
            }
        }
        return 0;
    }
};