#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int d[1000],tot;
bool bo[1000];
int main(){
	memset(bo,0,sizeof(bo));
	for (int i=2;i<=1000;i++)
		{
			if (!bo[i])
				d[++tot]=i;
			for (int j=1;j<=tot;j++)
				{
					bo[i*d[j]]=1;
					if (i*d[j]>1000)
						break;
					if (i%d[j]==0)
						break;
				}
		}
	for (int i=1;i<=tot;i++)
		printf("%d\n",d[i]);
	return 0;
}