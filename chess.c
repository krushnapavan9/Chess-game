#include<stdio.h>
//to clear the screen
void clearscreen(){}
void move(int x1,int y1,int x2,int y2,int p1[16][3],int p2[16][3],int a[8][8]){}
//to initialize the chess board
//keeps the position of the coins - a
//
void inita(int a[8][8],int p1[16][3],int p2[16][3]){
    int i,j;
    int p1_i=0,p2_i=0;
    for(i=0;i<8;i++){
      for(j=0;j<8;j++){
        a[i][j]=' ';
        if(j==0 || j==7){
            if(i==0){
                a[i][j]='e';
                p1[p1_i][0]=i;
                p1[p1_i][1]=j;
                p1[p1_i][2]='e';
                p1_i+=1;
            }
            if(i==7){
               a[i][j]='e';
               p2[p1_i][0]=i;
                p2[p1_i][1]=j;
                p2[p1_i][2]='e';
                p2_i+=1;
            }
        }
        if(j==1 || j==6){
            if(i==0){
                a[i][j]='c';
                p1[p1_i][0]=i;
                p1[p1_i][1]=j;
                p1[p1_i][2]='c';
                p1_i+=1;

            }
            if(i==7){
                a[i][j]='c';
                p2[p1_i][0]=i;
                p2[p1_i][1]=j;
                p2[p1_i][2]='c';
                p2_i+=1;

            }
        }
        if(j==2 || j==5){
            if(i==0){
                a[i][j]='h';
                p1[p1_i][0]=i;
                p1[p1_i][1]=j;
                p1[p1_i][2]='h';
                p1_i+=1;

            }
            if(i==7){
                a[i][j]='h';
                p2[p1_i][0]=i;
                p2[p1_i][1]=j;
                p2[p1_i][2]='h';
                p2_i+=1;

            }
        }
        if(j==3){
            if(i==0){
                a[i][j]='k';
                p1[p1_i][0]=i;
                p1[p1_i][1]=j;
                p1[p1_i][2]='k';
                p1_i+=1;

            }
            if(i==7){
                a[i][j]='k';
                p2[p1_i][0]=i;
                p2[p1_i][1]=j;
                p2[p1_i][2]='k';
                p2_i+=1;

            }
        }
        if(j==4){
            if(i==0){
                a[i][j]='q';
                p1[p1_i][0]=i;
                p1[p1_i][1]=j;
                p1[p1_i][2]='q';
                p1_i+=1;

            }
            if(i==7){
                a[i][j]='q';
                p2[p1_i][0]=i;
                p2[p1_i][1]=j;
                p2[p1_i][2]='q';
                p2_i+=1;

            }
        }
        if(i==1){
            a[i][j]='p';
            p1[p1_i][0]=i;
            p1[p1_i][1]=j;
            p1[p1_i][2]='p';
            p1_i+=1;
        }
        if(i==6){
            a[i][j]='p';
            p1[p1_i][0]=i;
            p1[p1_i][1]=j;
            p1[p1_i][2]='p';
            p1_i+=1;

        }
      }
    }

    for(i=0;i<16;i++){
        printf("%d %d %d",p1[i][0],p1[i][1],p2[i][2]);
    }
}

void printboard(int a[8][8]){
	int i,j;
	for(i=0;i<8;i++) printf("  %d  ",i);
	printf("\n");
	printf("-----------------------------------\n");
	for(i=0;i<8;i++){
        printf("%d ",i);
        for(j=0;j<8;j++){
            printf("| %c ",a[i][j]);
        }
        printf("|\n---------------------------------------");
        printf("\n");
	}
}

int exits(int x,int y,int p[16][3]){
    int i;
    for(i=0;i<16;i++){
        if(p[i][0]==x && p[i][1]==y && p[i][2]!=0 )
            return 1;
    }
    return 0;
}
int valid(int x1,int y1,int x2,int y2,int p1[16][3],int p2[16][3],int p){
    int i;
    if(p==1){
            if(!exits(x1,y1,p1))
                return 0;
            if(exits(x2,y2,p1))
                return 0;
//            switch(p1[x1][x2][3]){
//                case 'p':
//                    if(!( ( x2==x1+1 && y2==y1 && !exits(x2,y2,p2)) ||(x2==x1+1 && y2==y1+1 && exits(x2,y2,p2)) ))
//                        return 0;
//                    return 1;
//                case 'e':
//                    if( (x1==x2) ){
//                        if(  )//---------------------------------------
//                    }
//
//            }
    }

}

int main() {
    int a[8][8],x1,y1,x2,y2,p=0;
    int p1[16][3];
    int p2[16][3];
    inita(a,p1,p2);
    int gameover=0;
    while(!gameover){
            printboard(a);
            printf("enter the values \"form : to\" player 1 : ");
            while(1){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(!valid(x1,y1,x2,y2,p1,p2,1))
                break;
            }
            move(x1,y1,x2,y2,p1,p2,a);
            printf("enter the values \"form : to\" player 2 : ");
            while(1){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(!valid(x1,y1,x2,y2,p2,p2,2))
                break;
            }
            move(x1,y1,x2,y2,p1,p2,a);

    }

}
