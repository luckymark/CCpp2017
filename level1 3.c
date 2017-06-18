#include <stdio.h>
#include <stdlib.h>
int main()
{
	for (float i = 0; i < 100; i++)
	{
		float as_child = i / 6;
		float as_tee = i / 12;
		float live_alone = i / 7;
		float get_son = 5;
		float son_live = i / 2;
		if (as_child + as_tee + live_alone + get_son + son_live + 4 == i)
			printf("%f", i);
	}
	system("pause");
    return 0;
}
