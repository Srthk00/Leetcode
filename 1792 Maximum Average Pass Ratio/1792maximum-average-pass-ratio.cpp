class Solution {
public:
    typedef pair<double,pair<int,int>> P;
    struct Comparator{
        bool operator()(P &a,P &b){
            return a.first<b.first;
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<P,vector<P>,Comparator> pq;

        for(auto &it:classes){
            pq.push({(double)(it[0]+1)/(it[1]+1)-(double)(it[0])/(it[1]),{it[0],it[1]}});
        }
        while(extraStudents-->0){
            P temp=pq.top();
            pq.pop();
            int nu=temp.second.first;
            int de=temp.second.second;
            nu+=1;
            de+=1;
            double newr=(double)(nu+1)/(de+1)-(double)nu/de;
            pq.push({newr,{nu,de}});
        }
        double result=0.00;
        while(!pq.empty()){
            result+=(double)pq.top().second.first/pq.top().second.second;
            pq.pop();
        }
        return (double)result/classes.size();
    }
};