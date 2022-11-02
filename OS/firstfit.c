#include<stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int i, j;
    int allocation[n];
    for(i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i+1);
        printf("%i\t\t\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}
int main()
{
    int m;    //no. my blks
      int n;  //no of prcs
	printf("Enter the  no. block size and no. of process ");
	scanf("%d %d",&m,&n);
	int blockSize[m];
    	int processSize[n];
	printf("Enter block sizes : ");
	for(int i=0; i<m; i++){
		scanf("%d",&blockSize[i]);
	}
	printf("Enter Process size : ");
        for(int i=0; i<n; i++){
                scanf("%d",&processSize[i]);
        }

    firstFit(blockSize, m, processSize, n);
    return 0 ;
}
