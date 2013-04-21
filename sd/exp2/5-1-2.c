#include <stdio.h>

//采用静态存储方式实现二叉树；
struct
{
    char data;
    int ls;
    int rs;
} space[1000];

int tot = 0;

int newNode(char ch, int lson, int rson)
{
    space[++tot].data = ch;
    space[tot].ls = lson;
    space[tot].rs = rson;
    return tot;
}

char* getList(int m, char list[], int len)
{
    list[++len] = '(';
    list[++len] = space[m].data;
    list[++len] = ' ';
    list[++len] = 0;

    if (space[m].ls)
    {
        char tmp[100];
        getList(space[m].ls, tmp, -1);
        strcat(list, tmp);
        len = strlen(list);
    }
    list[len] = ' ';
    list[++len] = 0;
    if (space[m].rs)
    {
        char tmp[100];
        getList(space[m].rs, tmp, -1);
        strcat(list, tmp);
        len = strlen(list);
    }
    list[len] = ')';
    list[++len] = 0;
    return list;
}

int createBT()
{
    char ch;
    scanf("%c", &ch);
    int T;
    if ( ch == '#' )
    {
        T = 0;
        return T;
    }
    else
    {
        T = ++tot;
        space[T].data = ch;
        space[T].ls = createBT ();
        space[T].rs = createBT();
        return T;
    }
}
int main(int argc, char *argv[])
{
    char list[100];
    int root = createBT();
    printf("%s\n", getList(root, list, -1));
    return 0;
}
