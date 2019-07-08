//带rank
const int MAXV = 10;
int p[MAXV];
int rank[MAXV];

//默认一开始所有点都是独立的
void init(int v) {
	for (int i = 0; i <= v; i++){
		p[i] = i;
		rank[MAXV] = 0;
	}
}

int root(int x) {
	if (p[x] == x) return x;
	return p[x] = root(p[x]); //路径压缩，当前节点的根一定是父节点的根
}

bool same(int x, int y) {
	return root(x) == root(y);
}

bool unite(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	//深的树作为父节点
	if(rank[x]>rank[y]){
		p[y] = x;
	}else if(rank[x] < rank[y]){
		p[x] = y;
	}else{
		//深度一样随便选
		p[y] = x;
		rank[x]++;
	}
	return true;
}