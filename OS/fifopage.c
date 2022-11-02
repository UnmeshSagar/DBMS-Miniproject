//Fifo Page.
#include<stdio.h>
int f,n,i, pf=0, ph=0, hit=0, found=0;
int Hit(int data, int frame[]){
	for(int j=0; j<f; j++){
		if(frame[j]==data){
			hit=1;
			break;
		}
	}
	return hit;
}
void start(int frame[]){
	for(int j=0; j<f; j++){
		frame[j]=-1;
	}
}
void disp(int frame[]){
	for(int j=0; j<f; j++){
		if(frame[i]!=-1){
			printf(" %d", frame[i]);
		}
	}
}
void main(){
	printf("Enter the length of string and Frame size : ");
	scanf("%d %d",&n,&f);
	int ref[n], frame[f];
	printf("Enter the page reference sequence : ");
	for(i=0; i<n; i++){
		scanf("%d",&ref[i]);
	}
	start(frame);
	for(i=0; i<n; i++){
		printf("\n %d | ", ref[i]);
		if(Hit(ref[i],frame)==0){
			int k;
			for(k=0; k<f-1; k++){
				frame[k]=frame[k+1];
			}
			frame[k]=ref[i];
			pf++;
			disp(frame);
		}
		else{
			printf("Hit ");
			ph++;
		}
	}
	printf("Page fault : %d \n Page Hit : %d ",pf,ph);
}
