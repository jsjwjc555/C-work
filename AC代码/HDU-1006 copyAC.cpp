#include<stdio.h>

int main()
{
    int t;
    double n,sum,ft1,ft2,ft3,et1,et2,et3,max,min;
    double sm,sh,mh,tsm,tsh,tmh,fsm,fsh,fmh,esm,esh,emh;
    sm=10./59.;
    sh=120./719.;
    mh=120./11.;
    tsm=360*sm;
    tsh=360*sh;
    tmh=360*mh;
    while(scanf("%lf",&n))
    {
        if(n<0)
            break;
        sum=0;
        fsm=sm*n;
        fsh=sh*n;
        fmh=mh*n;
        esm=tsm-fsm;
        esh=tsh-fsh;
        emh=tmh-fmh;
        for(ft3=fmh,et3=emh;et3<=43200;et3+=tmh,ft3+=tmh)
        {
            for(ft2=fsh,et2=esh;et2<=43200;et2+=tsh,ft2+=tsh)
            {
                if(et2<ft3)
                    continue;
                if(ft2>et3)
                    break;
                for(t=0,ft1=fsm,et1=esm;et1<=43200;t=t+1,et1=esm+t*tsm,ft1=fsm+t*tsm)
                {
                    if(et1<ft3 || et1<ft2)
                        continue;
                    if(ft1>et3 || ft1>et2)
                        break;
                    max=ft1;
                    if(ft2>max)
                        max=ft2;
                    if(ft3>max)
                        max=ft3;
                    min=et1;
                    if(et2<min)
                        min=et2;
                    if(et3<min)
                        min=et3;
                    sum+=min-max;
                }
            }
        }
        sum/=432.;
        printf("%.3lf\n",sum);
    }
return 0;
}
