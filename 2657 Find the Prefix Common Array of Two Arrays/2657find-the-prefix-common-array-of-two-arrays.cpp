class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> freq(n+1,0),result(n,0);
        for(int i=0;i<n;i++){
            freq[A[i]]++;freq[B[i]]++;
            for(int j=0;j<=n;j++){
                if(freq[j]==2){
                    result[i]++;
                }
            }
        }
        return result;
    }
};