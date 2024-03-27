#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,j,n,tm=0,move,size,inatial;

    printf("\n Enter the no of requests arrived : ");
    scanf("%d",&n);

    int rq[n];
    printf("\n Enter the requested cylinders : ");
    for (i=0;i<n;i++)
        scanf("%d",&rq[i]);

    printf("\n Enter the inatial header position : ");
    scanf("%d",&inatial);


    printf("\n Enter the disk size :  ");
    scanf("%d",&size);

    printf("\n Enter the move left(0)/right (1) : ");
    scanf("%d",&move);

    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (rq[j] > rq[j+1])
            {
                int temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }    

    printf("\n Sorted Requests are :  ");
    for (i=0;i<n;i++)
        printf(" %d ",rq[i]);

    int index;
    for (i=0;i<n;i++)
    {
        if (inatial<rq[i])
        {
           index=i;
           break;
        }
    }


    if (move==1)
    {
        printf("\n The blocks are serviced  : ");
        for (i=index;i<n;i++)  // grater than of the cursor or head position
        {

            printf(" %d-> ",rq[i]);
            tm=tm+abs(inatial-rq[i]);
            inatial=rq[i];

        }

        printf("\n %d\n",tm);

       printf(" %d->",size-1);
        tm=tm+abs(size-0-1);
        inatial=0;
        printf(" 0->");

        for(i=0;i<=index;i++)
        {
            printf(" %d-> ",rq[i]);
            tm=tm+abs(inatial-rq[i]);
            inatial=rq[i];

        }
    }
    else 
    {
        printf("");

        printf("\n The blocks are serviced  : ");
        for (i=index-1;i>=0;i--)  // grater than of the cursor or head position
        {

            printf(" %d-> ",rq[i]);
            tm=tm+abs(inatial-rq[i]);
            inatial=rq[i];

        }

        printf("\n %d\n",tm);

        printf(" 0->");

       
        tm=tm+abs(size-0-1);
        inatial=0;
        printf(" %d->",size-1);
        

        for(i=n-1;i>=index;i--)
        {
            printf(" %d-> ",rq[i]);
            tm=tm+abs(inatial-rq[i]);
            inatial=rq[i];

        }

        //developing yet
    }

    printf("\n Total head movements : %d",tm);



}