#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **arr, **jagged;
	int rows,cols, i, j, counter = 1;
	
	//2D ARRAY AREA
	printf("Rows: ");
	scanf("%d",&rows);
	printf("Columns: ");
	scanf("%d",&cols);
	
	arr = (int**)malloc(rows * sizeof(int*));
	for(i = 0; i < rows; i++){
		arr[i] = (int*)malloc(cols * sizeof(int));
		if(arr[i] == NULL){
			printf("NOT ENOUGH SPACE ON STACK!");
			exit(1);
		} 
		for(j = 0; j < cols; j++)
			arr[i][j] = counter++;
	}
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}
	
	for(i = 0; i < rows; i ++){
		printf("FREE: %p\n",arr[i]);
		free(arr[i]);
	}
	free(arr);
	
	//JAGGED ARRAY AREA
	printf("Rows: ");
	scanf("%d",&rows);
	jagged = (int**)malloc(rows*sizeof(int*));
	int jaggedcols[rows];
	for(i = 0; i < rows; i++){
		printf("Column %d: ",i+1);
		scanf("%d",&cols);
		jagged[i] = (int*)malloc(cols * sizeof(int));
		for(j = 0; j < cols; j++)
			jagged[i][j] = counter++;
		jaggedcols[i] = cols;
	}
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < jaggedcols[i]; j++)
			printf("%d\t",jagged[i][j]);
		printf("\n");
	}
	
	for(i = 0; i < rows; i++){
		printf("FREE: %p\n",jagged[i]);
		free(jagged[i]);
	}
	free(jagged);
}
