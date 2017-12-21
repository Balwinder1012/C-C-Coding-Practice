#include<stdio.h>
int main(){

	char ch[1000000];
	int n;
	scanf("%d",&n);
	while(n-->0){


		scanf("%s",ch);
        int letters[2];
        letters[0] = letters[1] = 0;
		char prev;
		char st[100000];
		int top=-1;

		prev = '.';
		for(int i=0;ch[i]!='\0';i++){

            if(ch[i]=='.' && prev=='.')
                continue;

            if(top!=-1 && ch[i]==prev && ch[i]!='.'){

                while(st[top]!=prev){
                    if(prev=='A') letters[0]++;
                    else    letters[1]++;

                    top--;

                }
                if(prev=='A') letters[0]++;
                    else    letters[1]++;

                    top--;

            }
            if(top!=-1 && ch[i]!=prev && ch[i]!='.'){

                while(st[top]=='.')
                    top--;

                 if(prev=='A') letters[0]++;
                    else    letters[1]++;

                    top--;
            }

            st[++top] = ch[i];
            if(ch[i]!='.')
                prev = ch[i];


		}

    while(top!=-1){

        if(st[top]=='A') letters[0]++;
        else if(st[top]=='B') letters[1]++;

        top--;

    }

	printf("%d %d\n",letters[0],letters[1]);
	}


}
