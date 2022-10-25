#include<stdio.h>

int main()
{
    int i,j,cnt,n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int a[n],f[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++)

    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        cnt=1;
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                cnt+=1;
                f[j]=0;
            }
        }
        if(f[i])
        {
            f[i]=cnt;
        }
    }
    printf("FREQUENCY\n");
    for(i=0;i<n;i++)
    {
        if(f[i])
        {
            printf("Frequency of %d is %d\n",a[i],f[i]);
        }
    }
return 0;
}
