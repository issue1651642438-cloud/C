#include<stdio.h>
int main()
{
    //freopen("returnMatrix.txt","r",stdin);
    int row,col;
    scanf("%d%d",&row,&col);
    int mat[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        }
    }

    int top=0,bot=row-1,lef=0,rig=col-1;
    while(top<=bot&&lef<=rig){
        for(int j=lef;j<=rig;j++){
            printf("%d\n",mat[top][j]);
        }
        top++;

        for(int i=top;i<=bot;i++){
            printf("%d\n",mat[i][rig]);
        }
        rig--;

        if(top<=bot){
            for(int j=rig;j>=lef;j--){
                printf("%d\n",mat[bot][j]);
            }
            bot--;
        }

        if(lef<=rig){
            for(int i=bot;i>=top;i--){
                printf("%d\n",mat[i][lef]);
            }
            lef++;
        }
    }

    return 0;
}