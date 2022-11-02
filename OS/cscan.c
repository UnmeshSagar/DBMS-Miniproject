#include<stdio.h>
#include<stdlib.h>
int main()
{
    int rq[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&rq[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    printf("Enter total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d",&move);

    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(rq[j]>rq[j+1])
            {
                int temp;
                temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<rq[i])
        {
            index=i;
            break;
        }
    }

    // towards high
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(rq[i]-initial);
            initial=rq[i];
        }
        // for max size
        TotalHeadMoment=TotalHeadMoment+abs(size-rq[i-1]-1);
        //max to min disk
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial=0;
        for( i=0;i<index;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(rq[i]-initial);
             initial=rq[i];
        }
    }
    // towards low
    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(rq[i]-initial);
            initial=rq[i];
        }
        //for min size
        TotalHeadMoment=TotalHeadMoment+abs(rq[i+1]-0);
        //min to max disk
        TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
        initial =size-1;
        for(i=n-1;i>=index;i--)
        {
             TotalHeadMoment=TotalHeadMoment+abs(rq[i]-initial);
             initial=rq[i];
        }
    }
    printf("Total head movement is %d",TotalHeadMoment);
    return 0;
}
