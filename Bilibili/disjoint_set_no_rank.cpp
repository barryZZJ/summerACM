//不带rank
const int MAXN = 10;
int p[MAXN];

//默认一开始所有点都是独立的
void init(int n) {
	for (int i = 0; i < n; i++){
		p[i] = i;
	}
}

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]); //路径压缩，当前节点的根一定是父节点的根
}

bool same(int x, int y) {
	return find(x) == find(y);
}

bool unite(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return false;
	p[x] = y;
	return true;
}