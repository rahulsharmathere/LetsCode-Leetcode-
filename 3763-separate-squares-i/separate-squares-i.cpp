class Solution {
public:

    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        double total=0;
        double s=0;
        double e=2e9;
        for(int i=0;i<n;i++){
            double y=squares[i][1];
            double l=squares[i][2];
            total+=l*l;
            s=min(s,y);
            e=max(e,y+l);
        }
        double target=total/2.0;
        
        for(int j=0;j<100;j++){
            double mid=s-(s-e)/2;
            double currArea=0;
            for(int i=0;i<n;i++){
                double y=squares[i][1];
                double l=squares[i][2];
                double h=max(0.0,min(l,mid-y));
                currArea+=h*l;
            }
            if(currArea < target){
                s=mid;
            }
            else{
                e=mid;
            }
        }

        return e;

    }
};