#include<stdio.h>
void main() {
	int age, childhood, young, single, age_son;
	age_son =1000;			 //Ϊage_son�������ܵľ޴�ֵ������ȷ�����һ��ѭ��
	for (age = 1; age_son != (age - 4) / 2; age++) {
	childhood = age / 6;
	young = age / 12;
	single = age / 7;
	age_son = childhood + young + single + 5;
}
	printf("����ͼ�������%d", age);
	getchar();
}