//不带rank
const int MAXV = 10;
int p[MAXV];

//默认一开始所有点都是独立的
void init(int v) {
	for (int i = 0; i <= v; i++){
		p[i] = i;
	}
}

// int find(int x) {
// 	if (p[x] == x) return x;
// 	return p[x] = find(p[x]); //路径压缩，当前节点的根一定是父节点的根
// }

//非递归，防止爆栈
int find(int x) {
	if (p[x] == x) return x;
	int rootx = p[x];
	while (rootx != p[rootx]) {
		rootx = p[rootx];
	}
	return p[x] = rootx;
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