#include<stdio.h>
#include<string.h>
void worstFit(int blockSize[], int m, int processSize[],
												int n)
{
	int allocation[n];
	memset(allocation, -1, sizeof(allocation));
	for (int i=0; i<n; i++)
	{
		int wstIdx = -1;
		for (int j=0; j<m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (wstIdx == -1)
					wstIdx = j;
				else if (blockSize[wstIdx] < blockSize[j])
					wstIdx = j;
			}
		}
		if (wstIdx != -1)
		{
			allocation[i] = wstIdx;
			blockSize[wstIdx] -= processSize[i];
		}
	}

	printf(" \nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %d \t\t %d\t\t", i+1, processSize[i]);
		if (allocation[i] != -1)
			printf(" %d \n", allocation[i] + 1);
		else
			printf(" Not Allocated\t");
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

    worstFit(blockSize, m, processSize, n);
    return 0 ;
}

