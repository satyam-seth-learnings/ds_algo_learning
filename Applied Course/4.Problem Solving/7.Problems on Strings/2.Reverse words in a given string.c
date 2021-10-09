
void reverse(char *b,char *e)
{
    char temp;
    while(b<e)
    {
        temp=*b;
        *b++=*e;
        *e--=temp;
    }
}
char * reverseWords(char * s){
    char *wordStart=s;
    char *temp=s;
    while(*temp)
    {
        temp++;
        if(*temp=='\0')
            reverse(wordStart,temp-1);
        else if(*temp==' ')
        {
            reverse(wordStart,temp-1);
            wordStart=temp+1;
        }
    }
    reverse(s,temp-1);
    return s;
}