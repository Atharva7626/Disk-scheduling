#include<stdio.h>
#include<stdlib.h>

void main()
{

    int i,j,n,tm=0,inatial,size,move;

    printf("\n Enter the no of Requests : ");
    scanf("%d",&n);

    int rq[n];
    printf("Enter the requested cylinders : ");
    for (i=0;i<n;i++)
       scanf("%d",&rq[i]);

    printf("\n Enter the initial head position : ");
    scanf("%d",&inatial);   

    

    printf("\n Enter the total disk size : ");
    scanf("%d",&size);

    printf("\n Enter the move(left(0)/ right (1)) : ");
    scanf("%d",&move);



    // sort an requested array of cylinders ..

    for (i=0;i<n;i++)
    {
         for (j=0;j<n-i-1;j++)
         {
            if (rq[j] >rq[j+1] )
            {
                int temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
         }
    }

    printf("\n The sorted cylinders are : ");
    for(i=0;i<n;i++)
    {
        printf(" %d ",rq[i]);
    }


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

        printf("\n Requests are serviced :");
        for (i=index;i<n;i++)
           {

            printf(" %d->",rq[i]);
            tm=tm+abs(rq[i]-inatial);
            inatial=rq[i];
           }
           printf("\n %d",tm);

          /*
           tm=tm+abs(size-rq[i-1]-1);
            inatial=size-1;
            printf(" %d->",size-1);

            printf("\n %d",tm);
            */

        for (i=index-1;i>=0;i--)
           {
            printf(" %d->",rq[i]);
            tm=tm+abs(rq[i]-inatial);
            inatial=rq[i];
            printf("\n %d",tm);
            // printf(" \n %d",inatial);
           }    

    }
    else
    {

        printf("\n Requests are serviced :");
        for (i=index-1;i>=0;i--)
           {
            printf(" %d->",rq[i]);
            tm=tm+abs(inatial-rq[i]);
            inatial=rq[i];
           }

           /*

           tm=tm+abs(rq[i+1]-0);
            inatial=0;
            printf(" 0->");
         */
         for (i=index;i<n;i++)
         {
            printf(" %d->",rq[i]);
            tm=tm+abs(inatial-rq[i]);
            inatial=rq[i];

         }
    }


   printf("\n Total head movements are : %d ",tm);   





}
