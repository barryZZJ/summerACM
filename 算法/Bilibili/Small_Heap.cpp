#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
//小顶堆。可以用vector实现。
//求最大的前k个数就可以构造一个k个元素的小顶堆，堆顶是k个大数中最小的，新元素比堆顶大就替换堆顶、排序，否则不管
//父亲的值 < 儿子的值，元素从上到下从左到右紧凑排列（完全二叉树）
//0.heapify:对当前节点不断向下交换直到没有大小颠倒，交换的时候优先选数值小的儿子换
//1.入堆：插在堆的末尾（数组的最后一个），然后不断【向上提升直到没有大小颠倒】对父节点heapify
//2.出堆：出根节点，然后把最后一个节点赋值给根节点。对根节点heapify
//编号从0开始，左儿子编号：i*2+1，右儿子编号：i*2+2，父亲编号：(i-1)/2

struct SmallHeap {

	SmallHeap() { n = 0; }

public:

	bool empty() { return heap.size() == 0; }

	int size() { return heap.size(); }

	int top() { return heap[0]; }

	void push(int x) {
		heap.push_back(x);
		n++;
		int i = n - 1;
		if(n>1)
			heapify(p(i));
	}

	int pop() {
		int res = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		n--;
		heapify(0);

		return res;
	}

private:
	int n;
	vector<int> heap;

	//int lc(int i) { return i * 2 + 1; }
	//int rc(int i) { return i * 2 + 2; }
	int p(int i) { return (i - 1) / 2; }

	// void swap(int &x, int &y) {
	// 	int tmp = x;
	// 	x = y;
	// 	y = tmp;
	// }

	void heapify(int i) {

		if (i >= n) return;

		int lc = i * 2 + 1;
		int rc = i * 2 + 2;
		int mini = i;

		if (lc < n && heap[lc] < heap[mini]) mini = lc;
		if (rc < n && heap[rc] < heap[mini]) mini = rc;

		if (mini != i) {
			swap(heap[mini], heap[i]);
			heapify(mini);
		}
	}

};


int main() {
	SmallHeap sh;
	sh.push(50);
	sh.push(20);
	sh.push(40);
	while (!sh.empty()) { cout << sh.pop() << endl; }
	return 0;
}