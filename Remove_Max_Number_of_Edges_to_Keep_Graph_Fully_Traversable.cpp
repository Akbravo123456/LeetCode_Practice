class UnionF{
    vector<int> component;
    int distinctcomponents;
public:
UnionF(int n){
    distinctcomponents=n;
    for(int i=0;i<=n;i++){
        component.push_back(i);
    }
}

bool unite(int a,int b){
    if(find(a) == find(b)){
        return false;
    }
    component[find(a)]=b;
    distinctcomponents--;
    return true;
}

int find(int a){
    if(component[a]!=a){
        component[a]=find(component[a]);
    }
    return component[a];
}

bool united(){
    return distinctcomponents == 1;
}
};

class Solution{
    public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[] (vector<int> &a,vector<int> &b) {return a[0]>b[0];});
        int edgesAdded=0;
        UnionF bob(n),alice(n);
        for(auto &edge:edges){
            int type=edge[0],one=edge[1],two=edge[2];
            switch(type){
                case 3:
                edgesAdded +=(bob.unite(one,two) | alice.unite(one,two));
                break;
                case 2:
                edgesAdded +=bob.unite(one,two);
                break;
                case 1:
                edgesAdded +=alice.unite(one,two);
                break;
            }
        }
        return (bob.united() && alice.united())?(edges.size()-edgesAdded):-1;
    }
};