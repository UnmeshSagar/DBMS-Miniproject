//sjf
#include<stdio.h>
#include<stdlib.h>
struct process{
	int pid, bt, ct, wt, tat;
};
struct process p[10];
int n,i,j,twt=0,ttat=0;
void print(){
	printf("Pid\t  \t Bt\t Ct\t Wt\t Tat\n");
	for(i=0; i<n; i++){
		p[i].tat=p[i].bt+p[i].wt;
                ttat+=p[i].tat;
		printf("%d\t %d\t %d\t %d\t %d\n",p[i].pid+1, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
	}
	printf("Avg Wt : %f \n Avg Tat : %f \n",(float)twt/n,(float)ttat/n);
}
void input(){
	printf("Enter the number of process : ");
	scanf("%d",&n);
	printf("Enter the Burst Time respectively \n");
	for(i=0; i<n; i++){
		p[i].pid=i;
		printf("P[%d] : ",i+1);
		scanf("%d%d",&p[i].bt);
	}
}
void sort()
{
	struct process temp;
	for(i=0; i<n; i++){
		for(j=i; j<n-1; j++){
			if(p[j].bt>p[j+1].bt){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}
void cal(){
	p[0].wt=0;
	for(int i=1; i<n; i++){
		p[i].wt=0;
		for(int j=0; j<i;j++){
			p[i].wt+=p[j].bt;
		}
		twt+=p[i].wt;
	}
}
void main(){
	input();
	sort();
	cal();
	print();
}
