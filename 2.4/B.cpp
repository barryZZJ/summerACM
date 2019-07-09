#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

//收N（奇数）头牛，共C头牛，总资金F元，score, aid
//要让收的牛中分数的中位数最大
//钱不够收N头牛输出-1

//按成绩从大到小排序，
//对每一头牛i，从i之前取 (n-1)/2 头总资金more[i]最小的牛，从i之后取 (n-1)/2 头总资金less[i]最小的牛
//最先满足more[i]+aid[i]+less[i]<=F的i就是最优解
//如果到最后都不满足就无解
//为了能保证i之前和之后有(n-1)/2头牛，i∈[1+(n-1)/2 , C-(n-1)/2]

//more[i]和less[i]用大顶堆优先队列维护，堆内是i之前和之后的牛中aid前(n-1)/2小的所有牛，
//堆顶为aid最大的牛，每新来一头牛就和堆顶的牛比较，新牛aid小就入堆，pop堆，否则不管

const int MAXN = 100005;
struct P{
	int score, aid;
}cows[MAXN];

//struct cmpa {
//	bool operator ()(P p1, P p2) {
//		return p1.aid < p2.aid;
//	}
//};

bool cmps(P p1, P p2) {
	return p1.score > p2.score;
}

priority_queue<int> more;
priority_queue<int> few;

int main() {
	int n, c, f;
	cin >> n >> c >> f;
	
	for (int i = 1;i <= c;i++) scanf("%d%d", &cows[i].score, &cows[i].aid);
	
	sort(cows + 1, cows + 1 + c, cmps);
	if (n == 1) {
		for (int i = 1;i <= c;i++) {
			if (cows[i].aid <= f) {
				cout << cows[i].score;
				return 0;
			}
		}
		cout << "-1";
		return 0;
	}

	int s_more[MAXN], s_few[MAXN];//sum，记忆化搜索，
	//s_more正着看把前i个数中总和最小的都记下来
	//s_few 倒着看把后i个数中总和最小的都记下来

	fill(s_more, s_more + 1 + c, 0);
	fill(s_few, s_few + 1 + c, 0);
	int tmore = 0;
	for (int k = 1;k <=c; k++) {
		if (more.size() < (n - 1) / 2) {
			more.push(cows[k].aid);
			tmore += cows[k].aid;
			//s_more[k] = tmore;
		}
		else {
			if (cows[k].aid < more.top()) {
				more.push(cows[k].aid);
				tmore += cows[k].aid;
				tmore -= more.top();
				more.pop();
			}
		}
		s_more[k] = tmore;
	}
	int tfew = 0;

	for (int j = c;j >= 1; j--) {
		if (few.size() < (n - 1) / 2) {
			few.push(cows[j].aid);
			tfew += cows[j].aid;
			//s_few[j] = tfew;
		}
		else {
			if (s_few[j] > 0) continue;

			if (cows[j].aid < few.top()) {
				few.push(cows[j].aid);
				tfew += cows[j].aid;
				tfew -= few.top();
				few.pop();
			}
			s_few[j] = tfew;
		}
	}

	for (int i = 1 + (n - 1) / 2;i <= c - (n - 1) / 2;i++) {
		if (s_more[i-1] + cows[i].aid + s_few[i+1] <= f) {
			cout << cows[i].score;
			return 0;
		}
		
	}
	cout << "-1";
	return 0;


}