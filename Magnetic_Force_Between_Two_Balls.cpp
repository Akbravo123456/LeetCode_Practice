class Solution {
public:
    bool isAns(vector<int>& position, int mid, int m) {
        int initial = 1;
        int prev = position[0];
        
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - prev >= mid) { 
                prev = position[i]; 
                initial++; 
                if (initial == m) return true; 
            }
        }
        return initial >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); 
        
        int s = 0; 
        int n = position.size();
        int e = position[n - 1] - position[0];
        int res = 0; 
        
        while (s <= e) {
            int mid = s + (e - s) / 2; 
            
            if (isAns(position, mid, m)) {
                res = mid; 
                s = mid + 1;
            } else {
                e = mid - 1; 
            }
        }
        return res;
    }
};