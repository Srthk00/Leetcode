class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double result=0.0;
        auto dis=[&](vector<int> p1,vector<int> p2){
            double dx=p1[0]-p2[0];
            double dy=p1[1]-p2[1];
            return sqrt(dx*dx+dy*dy);
        };
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    double a=dis(points[i],points[j]);
                    double b=dis(points[j],points[k]);
                    double c=dis(points[k],points[i]);
                    double s=(a+b+c)/2.0;
                    double inside=s*(s-a)*(s-b)*(s-c);
                    if(inside>=0.0){
                        result=max(result,sqrt(inside));
                    }
                }
            }
        }
        return result;
    }
};