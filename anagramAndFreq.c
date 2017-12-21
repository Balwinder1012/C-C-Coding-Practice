#include<stdio.h>
int isAnagram(char word1[],char word2[]){

    static int letters[26];
    int i=0;
    while(word1[i]!='\0'){
        letters[word1[i]-'a']++;
        i++;
    }
    i=0;
    while(word2[i]!='\0'){
        letters[word2[i]-'a']--;
        i++;
    }

    for(int i=0;i<26;i++)
        if(letters[i]!=0)
            return 0;
    return 1;

}
void countFrequency(char ch[]){
     static int letters[26];
    int i=0;
    while(ch[i]!='\0'){
        letters[ch[i]-'a']++;
        i++;
    }

    for(int i=0;i<26;i++)
        if(letters[i]>0)
            printf("char %c appeared %d times \n",i+'a',letters[i]);

}
int main(){
    // ALL THE BEST
    char word1[50];
    char word2[50];
    gets(word1);
    gets(word2);
    if(isAnagram(word1,word2))
        printf("is anagram\n");
    else printf("not anagram\n");

    countFrequency(word1);
}
