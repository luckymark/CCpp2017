//����ͼ��ͯ�꾭������һ��������֮һ�����꾭����ʮ����֮һ�������߷�֮һ��ʱ���ǵ�������
//����������˸����ӣ����ӱȸ����������꣬�꼶������һ�롣�ʶ�����ʱ����ͼ���
#include<stdio.h>
int main()
{
	int a;
	for(a = 60 ; a < 150 ; a++){
		if(a%6 == 0){
			if(a%12 == 0){
				if(a%7 == 0){
					printf("%d\n",a);
				}
			}
		}
	}
	return 0;
 } 