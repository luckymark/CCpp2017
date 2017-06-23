#include <stdio.h>
#include <malloc.h>

int main()
{
    int n=0;
    printf("n是:");
    scanf("%d",&n);
    int* p;
    int i=0;
    int m=0;
    p=(int*)malloc(n*sizeof(int));
    printf("输入数据:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        *(p+i)=m;
    }
    
	int tmp;
    i=0;
    m=n-1;
    while(i<=m)
    {
        tmp=*(p+i);
        *(p+i)=*(p+m);
        *(p+m)=tmp;
        i++;
        m--;
    }
    
    i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ",*(p+i));
    }
    free(p);
    return 0;
}
