class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string evens1,evens2,odds1,odds2;
        int n=s1.size();
        int i=0;
        while(i<n){
            evens1+=s1[i];
            evens2+=s2[i];
            odds1+=s1[i+1];
            odds2+=s2[i+1];
            i+=2;
        }
        sort(evens1.begin(),evens1.end());
        sort(evens2.begin(),evens2.end());
        sort(odds1.begin(),odds1.end());
        sort(odds2.begin(),odds2.end());
        return evens1==evens2 && odds1==odds2;
    }
};