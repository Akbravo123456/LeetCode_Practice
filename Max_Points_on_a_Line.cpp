class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if (n<3)
            return n;
        
        int maxPoints=2;
        
        for (int i=0; i<n;i++) {
            unordered_map<string, int> slopeCount;
            int samePoint=1;
            int vertical=0;
            int localMax=1;
            
            for (int j=i+1;j<n;j++) {
                if (points[i][0] == points[j][0]) {
                    if (points[i][1] == points[j][1]) {
                        samePoint++;
                    } else {
                        vertical++;
                    }
                } else {
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];
                    int gcd = __gcd(dx, dy);
                    string slope = to_string(dy / gcd) + "/" + to_string(dx / gcd);
                    slopeCount[slope]++;
                    localMax=max(localMax,slopeCount[slope]);
                }
            }
            localMax=max(localMax, vertical)+samePoint;
            maxPoints=max(maxPoints, localMax);
        }
        return maxPoints;
    }
};
