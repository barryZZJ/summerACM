#include <iostream>
#include <algorithm>

using namespace std;

//理论上来说就是记录搜索结果的搜索
//d[i][j]表示前i个物品剩余空间为j时的最大总价值
//1.不能放入：没有足够的空间给第i件物品，即j<w[i]，那么空间没有变化，价值也没有变化，d[i][j] = d[i-1][j];
//2.能放入但不想放入：和不能放入其实是一样的，动机不同但结果相同，d[i][j] = d[i-1][j]
//3.想放入：必须要给这件物品留足够的空间才能放入，只有在d[i-1][j-w[i]]的基础上才能保证有空间放入，放入后空间变化了，价值也变化了，所以d[i][j] = d[i-1][j-w[i]] + v[i]
//但是想不想放入呢？（2，3）如果放入之后结果更好那我肯定放，如果还不如不放呢那我肯定不想放。怎么确定哪个选项更好呢，就比较2和3等式右边的值，哪个大哪个就更好。并且用d[i][j]记录下来。

//优化：
//d[i][..]只与d[i-1][..]有关，所以可以滚动数组节省空间
//给一维数组开W(总重量)的空间，外层i从0~n循环，内层j从W到0循环（一定要倒着，原因如下：
//假设i-1层数据已经存好了，现在处理第i层，
//能放入的时候，d[j]=max(d[j],d[j-w[i]]+v[i])
//其中，d[j]=d[j]相当于数据没变，d[j-w[i]]是读取比j小的位置的内容，我们让j倒着循环，每个位置都是以比它小的位置做参考，不会丢失当前需要的信息。而覆盖的位置也是对于这一层i后面更小的j不会参考的信息，属于旧数据，可以覆盖掉。
//最终结果就是，只用新数据覆盖数据
//因此，最终公式就是，不能放入的时候，d[j]=d[j]不变；能放入的时候，d[j] = max(d[j],d[j-w[i]]+v[i])。
//可以简化成：for(j=W; j>=w[i]; j--) if (d[j-w[i]]+v[i] > d[j]) d[j-w[i]]+v[i];

// 另外
// 如果并没有要求必须把背包装满，而是只希望价格尽量大，初始化时应该 将F[0..V ]全部设为0。
// 如果要求恰好装满背包，那么在初始化时除了F[0]为0，其 它F[1..V ]均设为−∞，这样就可以保证最终得到的F[V]是一种恰好装满背包的最优解。 
// 可以这样理解：初始化的F数组事实上就是在没有任何物品可以放入背包时的合法状态。
// 如果背包并非必须被装满，那么任何容量的背包都有一个合法解“什么都不装”，这个解的价值为0，所以初始时状态的值也就全部为0了。
// 如果要求背包恰好装满，那么此时只有容量为0的背包可以在什么也不装且价值为0的情况下被“恰好装满”，
// 其它容量的背包均没有合法的解，属于未定义的状态，应该被赋值为-∞了。
const int MAXN = 105;
int d[MAXN][MAXN];
int f[MAXN];//滚动数组
int W, v[MAXN], w[MAXN], n;

void normalDP(){
	for(int i=1; i<=n; i++){
		for(int j=0; j<=W; j++){
			if(j<w[i]) d[i][j] = d[i-1][j];
			else d[i][j] = max(d[i-1][j], d[i-1][j-w[i]] + v[i]);
		}
	}
	cout<<d[n][W];
}

//滚动数组
void betterDP(){
	for(int i=1; i<=n; i++){
		for(int j=W; j>=w[i]; j--){
			f[j] = max(f[j], f[j-w[i]] + v[i]);
		}
	}
	cout<<f[W];
}

int main(){
	

	return 0;
}