class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n=right+1;
        vector<bool> check(n,true);
        check[0]=check[1]=false;
        for(int i=2;i*i<n;i++){
            if(check[i]){
                for(int j=i*i;j<n;j+=i){
                    check[j]=false;
                }
            }
        }
        vector<int> pr;
        for(int i=left;i<=right;i++){
            if(check[i]){
                pr.push_back(i);
            }
        }
        vector<int> result(2,-1);
        if(pr.size()<2){
            return result;
        }
        int min=INT_MAX;
        for(int i=1;i<pr.size();i++){
            if(pr[i]-pr[i-1]<min){
                min=pr[i]-pr[i-1];
                result[0]=pr[i-1];
                result[1]=pr[i];
            }
        }
        return result;
    }
};