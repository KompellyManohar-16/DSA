#include<stdio.h>
int main()
{
    int a[3][3]={6,2,5,0,1,3,4,9,8};
    int *p;
    p=a[0];

    printf("\n &a[0][0] is : %u",&a[0][0]);
    printf("\n &a[0][1] is : %u",&a[0][1]);
    printf("\n &a[0][2] is : %u",&a[0][2]);

    printf("\n &a[1][0] is : %u",&a[1][0]);
    printf("\n &a[1][1] is : %u",&a[1][1]);
    printf("\n &a[1][2] is : %u",&a[1][2]);

    printf("\n &a[2][0] is : %u",&a[2][0]);
    printf("\n &a[2][1] is : %u",&a[2][1]);
    printf("\n &a[2][2] is : %u",&a[2][2]);

    printf("\n a[0] is : %u",a[0]);
    printf("\n a[1] is : %u",a[1]);
    printf("\n a[2] is : %u",a[2]);

    printf("\n &a[0] is : %u",&a[0]);
    printf("\n &a[1] is : %u",&a[1]);
    printf("\n &a[2] is : %u",&a[2]);

    printf("\n *a[0] is : %d",*a[0]);
    printf("\n *a[1] is : %d",*a[1]);
    printf("\n *a[2] is : %d",*a[2]);

    printf("\n p is : %u",p);
    printf("\n a is : %u",a);
    printf("\n &a[0][0] is : %u",&a[0][0]);
    printf("\n &a is : %u",&a);
    printf("\n *a is : %u",*a);
    printf("\n *p is : %d",*p);

    printf("\n a+1 is : %u",a+1);
    printf("\n a+2 is : %u",a+2);

    printf("\n *(a+1) is : %u",*(a+1));
    printf("\n *(a+2) is : %u",*(a+2));
    printf("\n *(a+1)+2 is : %u",*(a+1)+2);

     
    printf("\n *(*(a+0)+1) is :%u",*(*(a+0)+1));   //a[i][j]=*(*(a+i)+j)
    printf("\n *(*(a+0)+2) is : %d",*(*(a+0)+2));
     printf("\n *(*(a+1)+0) is %d",*(*(a+1)+0));  
    printf("\n *(*(a+1)+1) is : %d",*(*(a+1)+1));
    printf("\n *(*(a+2)+1) is : %d",*(*(a+2)+1));
    printf("\n *(*(a+2)+2) is : %d",*(*(a+2)+2));

    
     printf("\n *(a[0]+1) is : %d",*(a[0]+1)); //a[i]][j]=*(a[i]+j)
    printf("\n *(a[0]+2) is : %d",*(a[0]+2));
     printf("\n *(a[1]+0) is : %d",*(a[1]+0));
     printf("\n *(a[1]+1) is : %d",*(a[1]+1));
    printf("\n *(a[2]+1) is : %d",*(a[2]+1));
    printf("\n *(a[2]+2) is : %d",*(a[2]+2));

    printf("\n *(*a+1) is : %d",*(*a+1));
    printf("\n *(*a+3) is : %d",*(*a+3));

    printf("\n **a is : %d",**a);
    printf("\n *p is : %d",*p);

    printf("\n a is : %u",a);
    printf("\n a+1 is : %u",a+1);
    printf("\n &a is : %u",&a);
    printf("\n &a+1 is : %u",&a+1);

    printf("\n a[1]+1 is : %u",a[1]+1);
    printf("\n &a[1]+1 is : %u",&a[1]+1);

    return 0;
}