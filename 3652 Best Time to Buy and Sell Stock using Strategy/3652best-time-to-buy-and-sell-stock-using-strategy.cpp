class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long> profitprefix(n);
        vector<long long> priceprefix(n);
        profitprefix[0]=prices[0]*strategy[0];
        priceprefix[0]=prices[0];
        for(int i=1;i<n;i++){
            profitprefix[i]=profitprefix[i-1]+(strategy[i]*prices[i]);
            priceprefix[i]=priceprefix[i-1]+prices[i];
        }
        int i=0,j=k-1;
        long long result=profitprefix[n-1];
        while(j<n){
            long long left=0;
            if(i!=0){
                left=profitprefix[i-1];
            }
            long long right=profitprefix[n-1]-profitprefix[j];
            long long mid=priceprefix[j]-priceprefix[i+(k/2)-1];
            i++;j++;
            result=max(result,left+mid+right);
        }
        return result;
    }
};