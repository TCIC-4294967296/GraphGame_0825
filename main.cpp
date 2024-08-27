#include"stdc++.h"
#include"DSU.h"
#include"delay.h"
using namespace std;

int siz;
vector<vector<int>> gra;

void buildgraph(){
	DSU ltk(siz);
	int cnt=0;
	while(cnt<siz-1){
		int u=rand()%siz,v=rand()%siz;
		if(!ltk.same(u,v)&&u!=v&&(u!=0||v!=siz-1)&&(u!=siz-1||v!=0)){
			gra[u].push_back(v);
			gra[v].push_back(u);
			ltk.merge(u,v);
			cnt++;
		}
	}
	int cnt2=rand()%31;
	while(cnt2){
		int u=rand()%siz,v=rand()%siz;
		if(u!=v&&(u!=0||v!=siz-1)&&(u!=siz-1||v!=0)){
			gra[u].push_back(v);
			cnt2--;
		}
	}
	for(int i=0;i<siz;i++){
		sort(gra[i].begin(),gra[i].end());
		int len=unique(gra[i].begin(),gra[i].end())-gra[i].begin();
		gra[i].resize(len);
	}
}



void title(){
	printf("Graph Game\n");
	printf("Made by TCIC_4294967296, Open source using Apache License.\n");
	printf("Introduction to Apache License: https://www.runoob.com/w3cnote/open-source-license.html\n");
}

void initialtext(){
	printf("\n");
	printf("There are %d cities and some streets. \n",siz);
	printf("Mario is in City #0. he wants to get to City #%d. \n",siz-1);
	printf("Both 2 players can alternately control Mario to go to a city connected to the current city random number of times.\n");
	printf("Whoever brings Mario to City #%d in the end wins. \n",siz-1);
}

void showstreet(){
	printf("\n");
	printf("Information of cities traffic:\n");
	for(int i=0;i<siz;i++){
		printf("Cities connected to City #%d: ",i);
		int j=0;
		for(int nd:gra[i]){
			if(j) printf(", ");
			printf("#%d",nd);
			j++;
		}
		printf("\n");
	}
}

void game(){
	printf("\n");
	int city=0,player=1;
	while(city!=siz-1){
		int cishu_var=rand(),cishu;
		if(cishu_var<RAND_MAX*0.8) cishu=1;
		else if(cishu_var<RAND_MAX*0.99) cishu=2;
		else cishu=3; 
		printf("Player %d can select %d times.\n",player,cishu);
		while(cishu--){
			printf("Mario is in City #%d.\n",city);
			printf("Please Player %d select the city to go and enter the number: ",player);
			bool can=0;
			int nxt;
			while(!can){
				scanf("%d",&nxt);
				for(int nd:gra[city]){
					if(nd==nxt) can=1;
				}
				if(!can) printf("City #%d isn't connected to City #%d. Please select again: ",nxt,city);
			}
			printf("Mario is going to City #%d...\n",nxt);
			printf("\n");
			delay(1000);
			city=nxt;
			if(city==siz-1){
				printf("Mario arrived in City #%d! \n",siz-1);
				printf("Player %d wins! \n",player);
				goto ENDGAME;
			}
		}
		player=3-player;
	}
	ENDGAME:return;
}

int main(int argc, char** argv) {
	srand(time(0));
	siz=rand()%7+12;
	gra.resize(siz);
	buildgraph();
	title();
	printf("PRESS ANY KEY TO CONTINUE..."),getchar();
	initialtext();
	printf("PRESS ANY KEY TO CONTINUE..."),getchar();
	showstreet();
	printf("PRESS ANY KEY TO CONTINUE..."),getchar();
	game();
	while(1);
}
