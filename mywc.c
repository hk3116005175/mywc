#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CharCounter();  //�ַ�ͳ�ƺ���
void WordCounter();  //����ͳ�ƺ���
void LineCounter();  //����ͳ�ƺ���
void Muiltipler();  //�ۺ�ͳ�ƺ���(�����У����У�ע����)

int main(int argc,char *argv[])
{
	
	if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "file.c") == 0))
     {
    	
        CharCounter();
     }
    
    if ((strcmp(argv[1], "-w") == 0) && (strcmp(argv[2], "file.c") == 0))
     {
    
        WordCounter();
     }
   if ((strcmp(argv[1], "-l") == 0) && (strcmp(argv[2], "file.c") == 0))
     {
    	
        LineCounter();
     }
   if ((strcmp(argv[1], "-a") == 0) && (strcmp(argv[2], "file.c") == 0))
     {
       
	    Muiltipler();
     }
     
        return 0;

}

void CharCounter() //�ַ�ͳ�ƺ���
{
    FILE *fp;
    int c = 0;
    char ch;
    
    if((fp = fopen("file.c","r")) == NULL)
    {
       
	    printf("Can't open file.");
    }
    ch = fgetc(fp);
    
    while(ch != EOF)
    {
    	
            c ++;
            ch = fgetc(fp);
    }
    printf("number of char is ��%d.\n",c);
    
    fclose(fp);
}

void WordCounter() //����ͳ�ƺ���
{
    FILE *fp;
    int w = 0;
    char ch;
    
    if((fp = fopen("file.c","r")) == NULL)
    {
        printf("Can't open file.");
    }
    
    ch = fgetc(fp);
    while(ch != EOF)
    {
        if ((ch >= 'a'&&ch <= 'z')||(ch >= 'A'&&ch <='Z')||(ch >= '0'&&ch <= '9'))
        {
            while ((ch >= 'a'&&ch <= 'z')||(ch >= 'A'&&ch <= 'Z')||(ch >= '0'&&ch <= '9')||ch == '_')
            {
                ch = fgetc(fp);
            }
            w ++;
            ch = fgetc(fp);    
        }
        else 
        {
            ch = fgetc(fp);
        }
    }
    printf("number of word is ��%d.\n",w);
    
    fclose(fp);

}

void LineCounter() //����ͳ�ƺ���
{
    FILE *fp;
    int l = 1;
    char ch;
    
    if((fp = fopen("file.c","r")) == NULL)
    {
        printf("Can't open file.");
    }
    
    ch = fgetc(fp);
    while(ch != EOF)
    {
        if (ch == '\n')
        {
            l ++;
            ch = fgetc(fp);
        }
        else
        {
            ch = fgetc(fp);
        }
    }
    printf("number of line is ��%d.\n",l);
    
    fclose(fp);
}

void Muiltipler()  //�ۺ�ͳ�ƺ��������������У����У�ע����
{
    FILE *fp;
    char ch;
    int c=0,e=0,n=0;
    
    if((fp = fopen("file.c","r")) == NULL)
    {
        printf("Can't open file.");
    }
    
    ch = fgetc(fp);
    
    while(ch != EOF)
    {
        if (ch == '{'||ch == '}')
        {
            e ++;
            ch = fgetc(fp);
        }
        else if (ch == '\n')
        {
            ch = fgetc(fp);
            while(ch == '\n')
            {
                e ++;
                ch = fgetc(fp);
            }
        }
        else if (ch == '/')
        {
            ch = fgetc(fp);
            if (ch == '/')
                while(ch != '\n')
                {
                    ch = fgetc(fp);
                }
                n ++;
                ch = fgetc(fp);
        }
        else
        {
            c ++;
            while (ch != '{'&&ch != '}'&&ch != '\n'&&ch != '/'&&ch != EOF)
            {
                ch = fgetc(fp);
            }
        }

    }
    printf("number of code line is ��%d.\n",c);
    printf("number of empt line is ��%d.\n",e);
    printf("number of note line is ��%d.\n",n);
    
    fclose(fp);
}
