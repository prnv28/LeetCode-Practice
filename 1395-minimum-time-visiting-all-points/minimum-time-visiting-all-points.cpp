class Solution {
public:
    int region(int x1,int y1,int x2,int y2){
        if(x2>=x1 && y2>=y1){
            if(x1==x2) return (y2-y1);
            else if(y1==y2) return (x2-x1);
            else{
                float slop = (y2-y1)/((x2-x1)*1.0);
                if(slop<1){
                    return (x2-x1);
                }else{
                    return (y2-y1);
                }
            } 
        }else if(x2>=x1 && y2<y1){
            if(x1==x2) return (y1-y2);
            else{
                float slop = (y2-y1)/((x2-x1)*1.0);
                if(slop<-1){
                    return (y1-y2);
                }else{
                    return (x2-x1);
                }
            }
        }else if(x2<x1 && y2>=y1){
            if(y1==y2) return (x1-x2);
            else{
                float slop = (y2-y1)/((x2-x1)*1.0);
                if(slop<-1){
                    return (y2-y1);
                }else{
                    return (x1-x2);
                }
            }
        }else if(x2<x1 && y2<y1){
            float slop = (y2-y1)/((x2-x1)*1.0);
            if(slop<1){
                return (x1-x2);
            }else{
                return (y1-y2);
            }
        }
        return 0;
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i=1;i<points.size();i++){
            time += region(points[i][0],points[i][1],points[i-1][0],points[i-1][1]);
            
        }
        return time;
    }
};