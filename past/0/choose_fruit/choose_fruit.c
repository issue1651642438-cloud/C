#include<stdio.h>
#include<string.h>
#include<ctype.h>
const char* friuts[]={
    "apples",
    "bananas",
    "peaches",
    "cherries",
    "pears",
    "oranges",
    "strawberries",NULL
};



int contains_word(const char* str,const char* word)
{
    int len_str=strlen(str);
    int len_word=strlen(word);
    if(len_word==0) return 0;

    const char* ptr=strstr(str,word);
    while(ptr!=NULL){
        int pos=ptr-str;
        int prev_ok=(pos==0)||(!isalpha((unsigned char)str[pos-1]));
        int next_ok=(pos+len_word>=len_str)||(!isalpha((unsigned char)str[pos+len_word]));

        if(prev_ok&&next_ok){
            return 1;
        }

        ptr=strstr(ptr+1,word);
    }
    return 0;
}

int main()
{
    freopen("choose_fruit.txt","r",stdin);
    
    char line[1024];
    while(fgets(line,sizeof(line),stdin)!=NULL)
    {
        int len=strlen(line);
        line[len-1]='\0';

        const char* found_word =NULL;
        for(int i=0;friuts[i]!=NULL;i++)
        {
            if(contains_word(line,friuts[i])){
                found_word=friuts[i];
                break;
            }
        }
        if(found_word!=NULL){
            const char* replace="Brussels sprouts";
            const char* ptr =strstr(line ,found_word);
            int start =ptr-line;
            int word_len=strlen(found_word);
            char new_line[2048];

            strncpy(new_line,line,start);
            new_line[start]='\0';
            strcat(new_line,replace);
            strcat(new_line,line+start+word_len);

            printf("%s\n",new_line);
        }else{
            printf("You must not enjoy fruit.\n");
        }
    }
    return 0;
}