#include<stdio.h>
#include<string.h>
void add(char *a,char *b){
    int a1[100],b1[100],a2[100],b2[100],c1[100],c2[100];
    for(int i=0;i<100;i++){
        a1[i]=0;b1[i]=0;a2[i]=0;b2[i]=0;c1[i]=0;c2[i]=0;
    }

    int ia1=0,ia2=0,ib1=0,ib2=0;
    while(a[ia1]!='.'){
        a1[ia1]=a[ia1]-'0';
        ia1++;
    }
    while(a[ia1+1+ia2]!='\0'){
        a2[ia2]=a[ia1+1+ia2]-'0';
        ia2++;
    }
    while(b[ib1]!='.'){
        b1[ib1]=b[ib1]-'0';
        ib1++;
    }
    while(b[ib1+1+ib2]!='\0'){
        b2[ib2]=b[ib1+1+ib2]-'0';
        ib2++;
    }
    for(int i=0;i<ia1/2;i++){
        int temp=a1[i];
        a1[i]=a1[ia1-1-i];
        a1[ia1-1-i]=temp;
    }
    for(int i=0;i<ib1/2;i++){
        int temp=b1[i];
        b1[i]=b1[ib1-1-i];
        b1[ib1-1-i]=temp;
    }

    int max1=ia1,max2=ia2;
    if(ia1<ib1) max1=ib1;
    if(ia2<ib2) max2=ib2;
    int plus=0;
    for(int i=max2;i>=0;i--){
        c2[i]=(a2[i]+b2[i]+plus)%10;
        plus=(a2[i]+b2[i]+plus)/10;
    }
    for(int i=0;i<max1;i++){
        c1[i]=(a1[i]+b1[i]+plus)%10;
        plus=(a1[i]+b1[i]+plus)/10;
    }

    if(plus==1){
        c1[max1++]=1;
    }
    while(c2[max2-1]==0&&max2>0){
        max2--;
    }

    
    for(int i=max1-1;i>=0;i--){
        printf("%d",c1[i]);
    }
    printf(".");
    for(int i=0;i<max2;i++){
        printf("%d",c2[i]);
    }

}



int main()
{
    //freopen("add_of_float.txt","r",stdin);
    int n;
    scanf("%d",&n);
    getchar();
    char num[n][2][100];
    for(int i=0;i<n;i++){
        fgets(num[i][0],100,stdin);
        int len=strlen(num[i][0]);
        if(len>0&&num[i][0][len-1]=='\n'){
            num[i][0][len-1]='0';
        }

        fgets(num[i][1],100,stdin);
        len=strlen(num[i][1]);
        if(len>0&&num[i][1][len-1]=='\n'){
            num[i][1][len-1]='\0';
        }

        if(i!=n-1){
            char c;
            while((c=fgetc(stdin))!=EOF){
                if(c!='\n'&&c!=' '&&c!='\t'){
                    ungetc(c,stdin);
                    break;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        add(&num[i][0][0],&num[i][1][0]);
        printf("\n");
    }
    return 0;
}