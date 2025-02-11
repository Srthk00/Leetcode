class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i=0;
        int m=s.size(),n=part.size();
        while(i<m){
            if(s.substr(i,n)==part){
                s.erase(i,n);
                m=s.size();
                i=0;
            }
            else
                i++;
        }
        return s;
    }
};