class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count=0;
        int arr1[256]={0},arr2[256]={0};
        for(int i=0;i<s1.size();i++){
            arr1[s1[i]]++;
            arr2[s2[i]]++;
            if(s1[i]!=s2[i]){
                count++;
            }
            if(count>2)
                return false;
        }
        for(int i=0;i<256;i++){
            if(arr1[i]!=arr2[i])
                return false;
        }
        return true;
    }
};