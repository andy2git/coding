/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.empty()) return 0;
        if(points.size() == 1) return 1;
        
        int max = 0;
        map<double, int> h_sp;
        int dup = 0;
        
        
        for(int i = 0; i < points.size(); i++){
            h_sp.clear();
            dup = 0;
            
            for(int j = i+1; j < points.size(); j++){
                if(points[j].x == points[i].x && points[j].y == points[i].y){
                    dup++;
                }else{
                    h_sp[slope(points[i], points[j])]++;
                }
            }
            
            for(auto it = h_sp.begin(); it != h_sp.end(); ++it){
                if(it->second + dup> max) max = it->second + dup;
            }
            if(dup > max) max = dup;
        }
        
        // add itself back
        return max+1;
    }
private:
    double slope(Point &a, Point &b){
        int d_x, d_y;
        d_x = b.x - a.x;
        d_y = b.y - a.y;
        
        
        if(d_x == 0 && d_y != 0) return numeric_limits<double>::infinity();
        else return d_y/(double)d_x;
    }

};
