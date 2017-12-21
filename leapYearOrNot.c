
char * checkLeapYear(int n){

    char *ch;
    ch = (char *)malloc(sizeof(char)*50);
    if(n%100==0){
        if(n%400==0)
            ch = "Leap Year";

        else
            ch= "Not A Leap Year";

    }
    else{
        if(n%4==0)
         ch = "Leap Year";

        else
         ch= "Not A Leap Year";

    }


    return ch;
}

int main(){

    int n;
    label:
    scanf("%d",&n);

    if(n<1000 || n>10000){
        printf("Enter valid year - between 1000 and 10000\n");
        goto label;
    }

    puts(checkLeapYear(n));

}
