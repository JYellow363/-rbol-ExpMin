class DijSet{
    private:
        int n;
        int *rank;
        int *parent;

    public:
        DijSet(int n){
            this->n=n;
            rank=new int[n];
            parent=new int[n];
            for(int i=0;i<n;i++){
                rank[i]=0;
                parent[i]=i;
            }
        }
        
        int find(int a){
            if(parent[a]==a) return a;
            else find(parent[a]);
        }
        
        void union_find(int a, int b){
            int x=parent[a];
            int y=parent[b];
            if(x!=y){
                if(rank[x]>rank[y]){
                    parent[y]=x;
                    rank[x]++;
                }
                else{
                     parent[x]=y;
                     rank[y]++;
                }
            }
        }
};
