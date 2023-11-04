#include <stdio.h>//Erdinç KURTARAN   - 
#include <stdlib.h>//Tolgahan ÖZDEMÝR - 
#include <time.h>
#include <conio.h>
	
int  matris[10][10]={0},can=3,rasti,rastj,h=4,t,rasta,rastb,c=4,d[5],d2[5],i,j,x=2,y=4,sayac=0;//Global Degisken Atamalari
void fonk(int matris[][10],int r[],int d[],int d2[],int can){
	system("cls");
	printf("                                                TREASURE HUNTER\n");
	for(i=0;i<10;i++)//main matrisi yazdirma 
	{
		for(j=0;j<10;j++)
		{
			if(matris[i][j]==3)
				printf(" 3  ");		
			else
				printf(" 0  ");				
		}
			printf("\n\n");
	}
	for(i=0;i<5;i++)//elmas oyuncu arasi mesafe
	{
		if(matris[d[i]][d2[i]]==0)
			printf(" %d. Diamond Found\n",i+1);
		else
			printf(" %d. Diamond Distance = %d\n",i+1,r[i]);
	}
	printf(" Your Remaining Life: %d",can);
}
void trya()//muhafiza yakalanma fonksiyonu
{
	can--,x=2,y=4;	
	matris[2][4]=3;
	printf("\n You've Been Caught By the Guard\n");
	sleep(1);
	system("cls");
}
int main() {
	system("color B");//(aqua)
	srand(time(NULL));
	while(h!=-1)//elmas atamalari
		{
		rasti=rand()%10;
		rastj=rand()%10;
		matris[2][4]=3;
			if(matris[rasti][rastj]!=2 & matris[rasti][rastj]!=3 & matris[rasti][rastj]!=1)
				{		
					matris[rasti][rastj]=1;
					d[h]=rasti; 	d2[h]=rastj;	h--;	
				}	
		}
	while(c!=-1)//muhafiz atamasi
	{
		rasta=rand()%10;
		rastb=rand()%10;
		if(matris[rasta][rastb]!=3 & matris[rasta][rastb]!=1 & rasta==d[c]-1 & rastb==d2[c]-1 & matris[rasta][rastb]!=2)	
			{matris[rasta][rastb]=2;		c--;}
		if(matris[rasta][rastb]!=3 & matris[rasta][rastb]!=1 & rasta==d[c]-1 & rastb==d2[c] & matris[rasta][rastb]!=2)	
			{matris[rasta][rastb]=2;		c--;}
		if(matris[rasta][rastb]!=3 & matris[rasta][rastb]!=1 & rasta==d[c]-1 & rastb==d2[c]+1 & matris[rasta][rastb]!=2)	
			{matris[rasta][rastb]=2;		c--;}
		if(matris[rasta][rastb]!=3 & matris[rasta][rastb]!=1 & rasta==d[c] & rastb==d2[c]-1 & matris[rasta][rastb]!=2)	
			{matris[rasta][rastb]=2;		c--;}
		if(matris[rasta][rastb]!=3 & matris[rasta][rastb]!=1 & rasta==d[c]+1 & rastb==d2[c]-1 & matris[rasta][rastb]!=2)	
			{matris[rasta][rastb]=2;		c--;}
		if(matris[rasta][rastb]!=3 & matris[rasta][rastb]!=1 & rasta==d[c]+1 & rastb==d2[c] & matris[rasta][rastb]!=2)	
			{matris[rasta][rastb]=2;		c--;}
		if(matris[rasta][rastb]!=3 & matris[rasta][rastb]!=1 & rasta==d[c]+1 & rastb==d2[c]+1 & matris[rasta][rastb]!=2)	
			{matris[rasta][rastb]=2;		c--;}
		if(matris[rasta][rastb]!=3 & matris[rasta][rastb]!=1 & rasta==d[c] & rastb==d2[c]+1 & matris[rasta][rastb]!=2)	
			{matris[rasta][rastb]=2; 		c--;}
		}	
	int r[5]={abs(x-d[0])+abs(y-d2[0]),abs(x-d[1])+abs(y-d2[1]),abs(x-d[2])+abs(y-d2[2]),abs(x-d[3])+abs(y-d2[3]),abs(x-d[4])+abs(y-d2[4])} ;
	fonk(matris,r,d,d2,can);
	while(can!=0){//hareket 
	
		char tuslar;
		tuslar = getche();
		switch(tuslar)
		{
			case 'w':if(x==0) {continue;} //'w'
			if(matris[x][y]!=2 && matris[x-1][y]!=2) {matris[x][y]=0; matris[x-1][y]=3;}	x--;
			if(matris[x][y]==2) {matris[x+1][y]=0; trya();}		break;
			
			case 's':if(x==9) {continue;}//'s'
			if(matris[x][y]!=2 && matris[x+1][y]!=2) {matris[x][y]=0; matris[x+1][y]=3;}	x++;
			if(matris[x][y]==2) { matris[x-1][y]=0; trya();}	break;
			
			case 'a':if(y==0) {continue;}//'a'
			if(matris[x][y]!=2 && matris[x][y-1]!=2){ matris[x][y]=0; matris[x][y-1]=3;}	y--;
			if(matris[x][y]==2) { matris[x][y+1]=0; trya();}	break;
			
			case 'd':if(y==9) {continue;}//'d'
			if(matris[x][y]!=2 && matris[x][y+1]!=2){ matris[x][y]=0; matris[x][y+1]=3;}	y++;
			if(matris[x][y]==2) { matris[x][y-1]=0; trya();}	break;
			
			default:printf("\n Incorrect Command"); sleep(1);	break;
			
		}//mutlak konum noktalari
		int	u1=abs(x-d[0])+abs(y-d2[0]),u2=abs(x-d[1])+abs(y-d2[1]),u3=abs(x-d[2])+abs(y-d2[2]),u4=abs(x-d[3])+abs(y-d2[3]),u5=abs(x-d[4])+abs(y-d2[4]);
		int pl[5]={u1,u2,u3,u4,u5};
		fonk(matris,pl,d,d2,can);
	
		if(matris[d[0]][d2[0]]==0 & matris[d[1]][d2[1]]==0 & matris[d[2]][d2[2]]==0 & matris[d[3]][d2[3]]==0 & matris[d[4]][d2[4]]==0){
			printf("\n WIN");//kazandi
			system("color 2"); break;//(green)	
			}	
		}		
		printf("\n GAME OVER");//kaybetti
		system("color 4");//(red)
	return 0;
}
