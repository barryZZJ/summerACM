#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;


//4x4 5x5 6x6 必然要新箱子
//3x3 4个拼一个，多的要单开箱子
//2x2 能和4x4,3x3的拼，一个4x4能填5个2x2,
//					一个3x3最多能填5个2x2,剩7个1x1
//					两个3x3能填3个2x2,剩6个1x1
//					三个3x3能填1个2x2,剩5个1x1
//9个能填一个6x6
//1x1 剩下1x1的填剩下的位置,1个5x5只能能填11个1x1

int main() {
	int nums[7];
	int tt[] = { 0,5,3,1 };//i个3x3能填tt[i]个2x2

	bool flag;//是不是全0
	while (true) {
		flag = false;
		for (int i = 1;i <= 6;i++) {
			scanf("%d", &nums[i]);
			if (nums[i] != 0) flag = true;
		}
		if (!flag) return 0;


		int ans = nums[4] + nums[5] + nums[6];
		int box3 = ceil(nums[3] / 4.0);//3x3正好拼成的箱子数
		ans += box3;

		//2x2填3x3和4x4
		int fiint2 = nums[4] * 5 + tt[nums[3] % 4];
		fiint2 = min(fiint2, nums[2]);//填4x4的个数
		nums[2] -= fiint2;

		//先填1x1，多出来的和2x2多出来的拼
		int rest = 36 * ans - 36 * nums[6] - 25 * nums[5] - 16 * nums[4] - 9 * nums[3] - 4 * fiint2;//剩余位置
		rest = min(rest, nums[1]);//能使用1*1的最大数量 
		nums[1] -= rest;//使用1*1的方块 
		rest = 4 * nums[2] + nums[1];//看是否有剩余，有的话，单独找个大箱子

		ans += ceil(rest / 36.0);

		printf("%d\n",ans);

	}


	return 0;
}