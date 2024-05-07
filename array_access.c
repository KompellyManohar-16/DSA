#include<stdio.h>
int main()
{
    int a[5]={43,20,30,40,50};
    int *p;
    p=a;
    printf("\n a is : %u",a);
    printf("\n &a is : %u",&a);
    printf("\n *a is : %d",*a);

    printf("\n p is : %u",p);
    printf("\n &p is : %u",&p);
    printf("\n *p is : %d",*p);

    printf("\n a[2] is : %d ",a[2]);
    printf("\n a[4] is : %d ",a[4]);

    printf("\n a[3] is : %d",a[3]);
    printf("\n &a[3] is : %u",&a[3]);
    printf("\n (a+3) is : %u",(a+3));
    printf("\n *(a+3) is : %d",*(a+3));
    
    printf("\n a[4] is : %d",a[4]);
    printf("\n &a[4] is : %u",&a[4]);
    printf("\n (a+4) is : %u",(a+4));
    printf("\n *(a+4) is : %d",*(a+4));

    printf("\n (a+2) is : %u",(a+2));
    printf("\n (2+a) is : %u",(2+a));
    printf("\n (a+3) is : %u",(a+3));
    printf("\n (3+a) is : %u",(3+a));

    printf("\n *(a+2) is : %d",*(a+2));
    printf("\n *(2+a) is : %d",*(2+a));
    printf("\n *(a+3) is : %d",*(a+3));
    printf("\n *(3+a) is : %d",*(3+a));

    printf("\n a[2] is : %d and 2[a] is : %d",a[2],2[a]);
    printf("\n a[3] is : %d and 3[a] is : %d",a[3],3[a]);
    printf("\n p[2] is : %d and 2[p] is : %d",p[2],2[p]);
    printf("\n p[3] is : %d and 3[p] is : %d",p[3],3[p]);




    printf("\n &a is : %u",&a);
    printf("\n &a+1 is : %u",&a+1);
    printf("\n &a[0]+1 is : %u",&a[0]+1);
    printf("\n &a[2]+1 is : %u",&a[2]+1);

    printf("\n *a is : %d",*a);
    printf("\n *(a+1) is : %d",*(a+1));
    printf("\n *a+1 is : %d",*a+1);
    return 0;
}
    
