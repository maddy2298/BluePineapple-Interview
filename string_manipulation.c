#include<stdio.h>

struct dictionary{
    char c;
    int freq;
}dictionary[100];

int pointer = 0;

int contains(char s)
{
    int i;
    for(i = 0; i < pointer; i++)
    {
        if(dictionary[i].c == s)return 1;
    }
    return 0;
}

int getPosition(char s)
{
    int i;
    for(i = 0; i < pointer; i++)
    {
        if(dictionary[i].c == s)return i;
    }
    return -1;
}

void add(char s)
{
    dictionary[pointer].c = s;
    dictionary[pointer].freq++;
    pointer++;
}

void main()
{
    char string[100];
    int traverse = 0;
    int position = -1;
    int max = -1;

    printf("Enter string -");
    gets(string);


    while(string[traverse] != '\0')
    {
        if( contains(string[traverse])  )
        {
            position = getPosition(string[traverse]);
            dictionary[position].freq++;
        }
        else 
        {
            add(string[traverse]);
        }
        traverse++;
    }

    for(traverse = 0; traverse < pointer; traverse++ )
    {
        if(dictionary[traverse].freq > max)
        {
            max = dictionary[traverse].freq;
        }
    }
    
    for(traverse = 0; traverse < pointer; traverse++ )
    {
        if(dictionary[traverse].freq == max)
        {
            printf("%c - %d \n", dictionary[traverse].c, dictionary[traverse].freq);
        }
    }
}
