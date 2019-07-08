//不带rank结构体

const int MAXV = 10;

struct Disset {

	int p[MAXV];
	//默认一开始所有点都是独立的
	void init(int v) {
		for (int i = 0; i <= v; i++) {
			p[i] = i;
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
		p[x] = y;
		return true;
	}

};