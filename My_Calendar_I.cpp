class MyCalendar {
public:
    MyCalendar() {
              
    }
    vector<pair<int,int>> m;
    bool book(int start, int end) {
        for(auto var:m){
            if(var.first<end && start<var.second){
                return false;
            }
        }
        m.push_back({start,end});
        return true;
    }
};