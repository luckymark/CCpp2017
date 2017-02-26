#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int d[1000],tot;
bool bo[1000];
bool get[1000];
int main(){
	memset(bo,0,sizeof(bo));
	for (int i=2;i<=100;i++)
		{
			if (!bo[i])
				d[++tot]=i;
			for (int j=1;j<=tot;j++)
				{
					bo[i*d[j]]=1;
					if (i*d[j]>100)
						break;
					if (i%d[j]==0)
						break;
				}
		}
	memset(get,0,sizeof(get));
	for (int i=1;i<=tot;i++)
		for (int j=i;j<=tot;j++)
			get[d[i]+d[j]]=1;
	for (int i=4;i<=100;i++)
		if (i%2==0)
			if (!get[i])
				{
					puts("False");
					return 0;
				}
	puts("True");
	return 0;
}