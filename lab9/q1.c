#include <stdio.h>

int nh;
int np;

void firstfit(int hole_sizes[], int process_mem_req[], int process_allocated[]) {
	int hole_current_sizes[nh];
	for(int i=0; i<nh; i++) hole_current_sizes[i] = hole_sizes[i];
	for( int i = 0; i < np; i++) {
		for (int j = 0; j < nh; j++) {
			if( process_mem_req[i] <= hole_current_sizes[j]) {
				hole_current_sizes[j] = hole_current_sizes[j] - process_mem_req[i];
				process_allocated[i] = j; // process i allocated to hole j
				printf("\nProcess %d allocated to Hole %d\n", i, j);
				break;
			}
		}
	}

	printf("\nDetails: \n");
	for(int j=0; j<nh; j++)
	{
		printf("Hole %d\t\t", j);
		printf("Memory allocated to processes: %d\tAvailable Memory- %d\n", hole_sizes[j] - hole_current_sizes[j], hole_current_sizes[j]);
	}
	for(int i=0;i<np;i++)
		if(process_allocated[i]==-1)
			printf("\nProcess %d is not allocated any holes!\n", i);
}

int main() {
	printf("Enter no of holes : ");
	scanf("%d", &nh);

	printf("\nEnter hole sizes:\n");
	int hole_sizes[nh];

	for(int i=0; i<nh; i++) {
		printf("Hole %d : ", i);
		scanf("%d", &hole_sizes[i]);
		printf("\n");
	}


	printf("Enter no of processes : ");
	scanf("%d", &np);

	printf("\nEnter processes memory requirements:\n");
	int process_mem_req[np], process_allocated[nh];

	for(int i=0; i<np; i++) {
		printf("Process %d : ", i);
		scanf("%d", &process_mem_req[i]);
		process_allocated[i]=-1;
		printf("\n");
	}

	printf("Dynamically allocated first fit: \n");
	firstfit(hole_sizes,process_mem_req,process_allocated);
}
