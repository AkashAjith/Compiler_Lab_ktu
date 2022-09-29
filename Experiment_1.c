#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
    FILE *_input,*_output;
    _input=fopen("input.txt", "r");
    _output=fopen("output.txt", "w");
    char characters[10],_keyword[10][10]= {"int","main","if","else","do","while","return","printf","char"},ch;
    int flag,i,_lineno=1,_tokenno=1;
    fprintf(_output,"Line no. \t Token no. \t Token \t\t Lexeme\n\n");
    do 
    {
        ch = fgetc(_input);
        if(ch=='/')
        {
            ch = fgetc(_input);
            if(ch=='/')
            {
                while(ch!='\n' && ch!=EOF)
                    ch=fgetc(_input);

            }
        }
        if(ch=='"')
        {
            ch=fgetc(_input);
            while(ch!='"' && ch!=EOF)
                ch=fgetc(_input);

        }

        if(isalpha(ch))
        {
            characters[0]=0;
            i=0;
            do
                characters[i++]=ch;
            while(isalnum(ch=fgetc(_input)));
            characters[i++]='\0';
            flag=0;
            for(int i=0;i<=10;i++)
                if(strcmp(characters,_keyword[i])==0)
                {
                    flag=1;
                    break;
                }
            if(flag==0)
                fprintf(_output,"%d \t\t %d \t\t Identifier \t %s\n",_lineno,_tokenno++,characters);
            else
                fprintf(_output,"%d \t\t %d \t\t Keyword \t %s\n",_lineno,_tokenno++,characters);
        }
        if(isdigit(ch))
        {
            characters[0]=0;
            i=0;
            do
                characters[i++]=ch;
            while(isdigit(ch=fgetc(_input)));
            characters[i++]='\0';
            fprintf(_output,"%d \t\t %d \t\t Digit \t\t %s\n",_lineno,_tokenno++,characters);
        }
        if(ch=='+' || ch=='­' || ch=='*' || ch=='/')
            fprintf(_output,"%d \t\t %d \t\t Operator \t %c\n",_lineno,_tokenno++,ch);
        else if(ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' || ch=='@' || ch=='!' || ch=='%')
            fprintf(_output,"%d \t\t %d \t\t Special \t %c\n",_lineno,_tokenno++,ch);
        else if(ch=='\n')
            _lineno++;
    }
    while (ch != EOF);
    fclose(_input);
    fclose(_output);
}