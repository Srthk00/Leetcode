class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        s=s.substr(i);
        n=s.size();
        i=n-1;
        while(i>=0 && s[i]==' '){
            i--;
        }
        s=s.substr(0,i+1);
        while(i>=0 && s[i]!=' '){
            i--;
        }
        int start=i+1;
        while(i>=0){
            while(i>=0 && s[i]==' '){
                i--;
            }
            int last=i;
            while(i>=0 && s[i]!=' '){
                i--;
            }
            int begin=i+1;
            s+=" "+s.substr(begin,last-begin+1);
        }
        return s.substr(start);
    }
};