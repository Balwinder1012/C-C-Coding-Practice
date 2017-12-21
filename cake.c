#include<stdlib.h>
#define rtog 5
#define gtor 3
int main(){
	char ch[100][100];

	int t,m,n;
	scanf("%d",&t);
	char a[100][100];
	char b[100][100];
	char look='G';
	for(int i=0;i<100;i++){

        for(int j=0;j<100;j++){
            a[i][j]=look;
            look = look=='G'?'R':'G';
        }
        look = look=='G'?'R':'G';
    }
    look='R';
	for(int i=0;i<100;i++){

        for(int j=0;j<100;j++){
            b[i][j]=look;
            look = look=='G'?'R':'G';
        }
        look = look=='G'?'R':'G';
    }


	while(t-->0){
		scanf("%d%d",&m,&n);
		int cost=0;
		int cost1=0;
		for(int i=0;i<m;i++)
			scanf("%s",ch[i]);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]!=ch[i][j]){
                    cost += ch[i][j]=='G' ? gtor : rtog;
                }
                if(b[i][j]!=ch[i][j]){
                    cost1 += ch[i][j]=='G' ? gtor : rtog;
                }
            }
        }

        printf("%d\n",cost>cost1?cost1:cost);

	}

}
