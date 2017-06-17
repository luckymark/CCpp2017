#include <stdio.h>
float main()
{
    float rate;
    float dollar,RMB;
    scanf("%f%f%f",&rate,&dollar,&RMB);
    RMB=dollar*rate;
    printf("%fdollar=%fRMB",dollar,RMB);
    return 0;
}
