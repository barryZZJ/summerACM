#include <iostream>
#include <stdio.h>
using namespace std;

const int n=10, m=12;
char field[n][m+1]={
	"w........ww.",
	".www.....www",
	"....ww...ww.",
	".........ww.",
	".........w..",
	"..w......w..",
	".w.w.....ww.",
	"w.w.w.....w.",
	".w.w......w.",
	".w.w......w."
};

void show(){
	for (int i=0; i<n; i++){
		cout<<field[i]<<endl;
	}
	cout<<endl;
}

void dfs(int x,int y){
	field[x][y] = '.';
	show();
	int nx,ny;
	for(int dx=-1; dx<=1; dx++){
		for(int dy=-1; dy<=1; dy++){
			nx=x+dx; ny=y+dy;
			if(0<=nx && nx <n &&
			   0<=ny && ny <m &&
			   field[nx][ny] == 'w')
				dfs(nx,ny);
		}
	}
}

int main(){
	int x=0,y=0;
	int ans=0;
	for(int x =0; x<n; x++){
		for(int y=0;y<m; y++){
			if(field[x][y] == 'w'){
				dfs(x,y);
				ans++;
			}
		}
	}
	cout<<ans;

	return 0;

	
}