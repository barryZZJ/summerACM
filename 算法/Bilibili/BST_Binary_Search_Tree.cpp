#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

//https://blog.csdn.net/zhouzejun1/article/details/95116453
//1. 查找某个数是否在集合中：从根出发，比当前结点小就找左儿子，否则找右儿子。
//2. 插入：查找应该放的位置，直到这个位置是空的，放入。
//删除：
//谁来填这个点的位置呢？
//1. 首先，新值应该还要维持与父节点的大小关系，所以只能从父节点的单侧子树~（即图中红框）~中找，
//2. 然后看红框内这棵子树，新的根要满足比左边的都大比右边的都小，所以应该要么左子树中最大的~（橙色圈，也即中序遍历中10的前继结点）~要么找右子树中最小的~（蓝色圈，也即中序遍历中10的后继结点)~（满足比左边的都大，比有右边的都小，而且更贴近被删除的值）作为新的根，让父节点指向新的子根。（如果父节点不存在，即被删除的就是总根，那么让新的根作为总根）
//3. 所以如果两个子树都存在，就随便搜其中一个（或者取两者中更靠近被删除的值的），否则，哪个子树存在就搜哪个子树，否则，没有孩子，直接删。
//最大值：一直找右儿子直到没有右儿子；最小值：一直找左儿子直到没有左儿子
struct Node {
	int val;
	Node *lch, *rch;
};

struct Tree {
	Node *root;
	Tree() { this->root = nullptr;}

	//循环写法
	void insert(int x) {
		//打包成节点
		Node *node = new Node;
		node->val = x;
		node->lch = nullptr;
		node->rch = nullptr;
		//找x的位置
		if (root == nullptr) {
			root = node;
			return;
		}

		Node *parx = root;
		while (parx) {
			if (x < parx->val) {
				if(parx->lch) parx = parx->lch;
				else {
					parx->lch = node;
					break;
				}
			}
			else {
				if(parx->rch) parx = parx->rch;
				else {
					parx->rch = node;
					break;
				}
			}
		}
		
		return;
	}

	bool find(int x) {
		if (this->root == nullptr) return false;
		Node *tmp = this->root;
		while (tmp) {
			if (x < tmp->val) tmp = tmp->lch;
			else if(x > tmp->val)tmp = tmp->rch;
			else return true;
		}
		return false;
	}
	
	//调用的时候一定要保证x存在，否则会出问题
	//返回的是删完pos之后新的根
	Node *remove(Node *pos, int x) {
		//以被删点的前继结点优先交换
		//先找x对应的pos
		if (pos == nullptr) return nullptr; //没找到x
		else {
			if (x < pos->val) pos->lch = remove(pos->lch, x);
			else if (x > pos->val) pos->rch = remove(pos->rch, x);
			else {
				//pos就是x的位置
				
				if (pos->lch) {
					//有左子树
					//优先找左子树中最大的点（一直找右儿子直到没有右儿子）
					
					Node *maxpar = pos->lch;//max的父亲
					
					//注意是提前搜索两层，终止的时候找到的是max的父节点
					while (maxpar->rch->rch) {
						maxpar = maxpar->rch;
					}
					Node *max = maxpar->rch;
					
					//把max放上去之前，maxpar继承max的遗产
					//max一定没有右儿子
					//如果max有左儿子，给maxpar，否则max什么都不剩，maxpar置null
					maxpar->rch = max->lch;

					//把max放上去
					max->lch = pos->lch;
					max->rch = pos->rch;
					
					delete pos;

					return max;//新的根就是max
				}
				else if(pos->rch) {
					//没有就找右子树的最小点

					Node *minpar = pos->rch;//min的父亲

					//注意是提前搜索两层，终止的时候找到的是min的父节点
					while (minpar->lch->lch) {
						minpar = minpar->lch;
					}
					Node *min = minpar->lch;

					//把min放上去之前，minpar继承min的遗产
					//min一定没有左儿子
					//如果min有右儿子，给minpar，否则min什么都不剩，minpar置null
					minpar->lch = min->rch;

					//把min放上去
					min->lch = pos->lch;
					min->rch = pos->rch;

					delete pos;

					return min;//新的根就是min
				}
				else {
					//pos即没有左子树也没有右子树，直接删就好
					delete pos;
					return nullptr;
				}
			}
			//x在搜下一层，本层根不变
			return pos;
		}
		
	}

	//遍历，前序中序后序
	void preOrder(Node *pos) {
		//根-左树-右树
		if (!pos) return;
		cout << pos->val << " ";
		preOrder(pos->lch);
		preOrder(pos->rch);
	}
	void inOrder(Node *pos) {
		//左树-根-右树
		if (!pos) return;
		inOrder(pos->lch);
		cout << pos->val << " ";
		inOrder(pos->rch);
	}
	void postOrder(Node *pos) {
		//左树-右树-根
		if (!pos) return;
		postOrder(pos->lch);
		postOrder(pos->rch);
		cout << pos->val << " ";
	}
	//求最值
	//最大值：一直找右儿子直到没有右儿子；最小值：一直找左儿子直到没有左儿子
	int maxVal(Node *pos) {
		if (pos->rch) return maxVal(pos->rch);
		return pos->val;
	}
	int minVal(Node *pos) {
		if (pos->lch) return minVal(pos->lch);
		return pos->val;
	}

	//递归写法
	//pos是子树的根，返回插入完x之后这个子树的新根
	//默认x与已有值不重复
	Node* insert_rec(Node *pos, int x) {
		//找x的位置
		if (pos == nullptr) {
			//子根没东西，可以放
			//打包成节点
			Node *node = new Node;
			node->val = x;
			node->lch = nullptr;
			node->rch = nullptr;
			if (!this->root)  this->root = node;
			return node;
		}
		else {
			//子根已经有了，找它的左右方向，该子树的根不变
			if (x < pos->val) pos->lch = insert_rec(pos->lch, x);
			else pos->rch = insert_rec(pos->rch, x);
			return pos;
		}
	}
	//递归写法
	//p=pos，从p开始找
	bool find_rec(Node *p, int x) {
		if (p == nullptr) return false;
		if (x < p->val) {
			return find_rec(p->lch, x);
		}
		else if (x > p->val) {
			return find_rec(p -> rch, x);
		}
		else return true;
	}

};

int main() {
	Tree tree;
	int arr[] = { 6,3,10,2,5,8,15,7,9,12,16 };
	for (int i = 0;i < 11;i++) tree.insert(arr[i]);//tree.insert_rec(tree.root, arr[i]); 
	cout << "normal finding 6: " << (tree.find(6) ? "found!" : "not found!") << endl;
	cout << "normal finding 20: " << (tree.find(20) ? "found!" : "not found!") << endl;
	cout << "recrrence finding 6: " << (tree.find_rec(tree.root,6)? "found!" : "not found!") << endl;
	cout << "recrrence finding 20: " << (tree.find_rec(tree.root,20)? "found!" : "not found!") << endl;
	cout << "Pre Order: "; tree.preOrder(tree.root); cout << endl;
	cout << "In Order: "; tree.inOrder(tree.root); cout << endl;
	cout << "Post Order: "; tree.postOrder(tree.root); cout << endl;
	cout << "min: " << tree.minVal(tree.root) << endl;
	cout << "max: " << tree.maxVal(tree.root) << endl;
	cout << "removing 10. " << endl;  tree.remove(tree.root, 10);
	cout << "Pre Order: "; tree.preOrder(tree.root); cout << endl;
	cout << "In Order: "; tree.inOrder(tree.root); cout << endl;
	cout << "Post Order: "; tree.postOrder(tree.root); cout << endl;
	return 0;
}