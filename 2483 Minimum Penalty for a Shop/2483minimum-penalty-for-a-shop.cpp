class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> open(n+1,0),close(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){close[i]++;}
            close[i]+=close[i+1];
        }
        for(int i=1;i<=n;i++){
            if(customers[i-1]=='N'){open[i]++;}
            open[i]+=open[i-1];
        }
        int minp=INT_MAX,mini=0;
        for(int i=0;i<=n;i++){
            int penalty=close[i]+open[i];
            if(penalty<minp){mini=i;minp=penalty;}
        }
        return mini;
    }
};