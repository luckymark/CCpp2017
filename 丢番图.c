#include<stdio.h>
void main() {
	int age, childhood, young, single, age_son;
	age_son =1000;			 //为age_son赋不可能的巨大值，以正确进入第一次循环
	for (age = 1; age_son != (age - 4) / 2; age++) {
	childhood = age / 6;
	young = age / 12;
	single = age / 7;
	age_son = childhood + young + single + 5;
}
	printf("丢番图的年纪是%d", age);
	getchar();
}