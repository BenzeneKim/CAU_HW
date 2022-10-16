#include <stdio.h>
#include <math.h>

#define N 5

int array[N][N];

void SpiralArray(int a[N][N], int n){
    int way=0;
    int x=0;
    int y=0;
    for(int i;i<(int)pow(n,2);i++){
        if(way==0){
            a[x][y]=i+1;
            if(y+2>n || a[x][y+1] != 0){
                way=1;
                x+=1;
            }
            else {
                y+=1;
            }
        }
        else if(way==1){
            a[x][y]=i+1;
            if(x+2>n||a[x+1][y]!=0){
                way=2;
                y-=1;
            }
            else{
                x+=1;
            }
        }
        else if(way==2){
            a[x][y]=i+1;
            if(y+2>n || a[x][y-1] != 0){
                way=3;
                x-=1;
            }
            else {
                y-=1;
            }
        }
        else if(way==3){
            a[x][y]=i+1;
            if(x+2>n||a[x-1][y]!=0){
                way=0;
                y+=1;
            }
            else{
                x-=1;
            }
        }
    }    
}

void PritnArray(int a[N][N], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    SpiralArray(array, N);
    PritnArray(array, N);
}