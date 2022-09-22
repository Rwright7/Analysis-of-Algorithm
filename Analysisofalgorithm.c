#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int menu();
void pauseConsole();
void Bubble_Sort();
void Quick_Sort();
void Selection_Sort();
void Heap_Sort();
void Insertion_Sort();
void Merge_Sort();

int main()
{
	int choice;
	
	system("clear");
	do
	{
		choice = menu();
	system("clear");
		switch(choice)
		{
			case 1:
					Bubble_Sort();
					break;
			case 2:
					Quick_Sort();
					break;
			case 3:
					Selection_Sort();
					break;
			case 4:
					Heap_Sort();
					break;
			case 5:
					Insertion_Sort();
					break;
			case 6:
					Merge_Sort();
					break;
			case 7:
				printf("\n\n....goodbye!....\n\n");
					exit(0);
			default:
					printf("Incorrect Selection!!");
		}
		
	} while(choice!=6);
	return 0;
}
	
	
int menu()
{
	int choice;
	printf(" ============ SORTING ALGORITHMS WITH RUNTIME ============\n");
	printf("Choose an Option: \n1. Bubble Sort \n2. Quick Sort \n3. Selection Sort \n4. Heap Sort \n5. Insertion Sort \n6. Merge Sort \n7. Exit \n");
	printf(" ============ SORTING ALGORITHMS WITH RUNTIME ============\n");
	scanf("%d", &choice);
	return choice;
	
}

void pauseConsole(void)
{
  fputs("Press <ENTER> to continue...", stdout);
  getchar();
}

void Bubble_Sort()
{
	int arr1[15000];
	int arr2[65000];
	int arr3[150000];
	
	clock_t begin, end;  //data type for calculating time
	double time1,time2, time3;  //variable for storing total time of execution for each dataset
	int x, i, y=0, min, temp;
	
	printf("\n============ Unsorted array dataset ============ 1:\n"); //populating array with dataset 1
	for(i=0;i<15000;i++)
	{
		
		for(i=0;i<15000;i++) //displaying unsorted array
		{
			
			arr1[i]=rand();  //populating array with random numbers
			printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
		}
		pauseConsole();
			//bubble sort begins
			begin = clock(); //variable to mark the starting time of sorting
			printf("\n\n============ Dataset 1 Clock started at: %f ============\n", (float)begin);
				
		for(i=0;i<=15000-2;i++)
		{
			for(y=0;y<=15000-1-i;y++)
			{
				if(arr1[y]>arr1[y+1])
				{
					temp=arr1[y];
					arr1[y]=arr1[y+1];
					arr1[y+1]=temp;	
				}
			
			}		
	}
	end = clock();
	pauseConsole();	
	printf("\n============ Dataset 1 Clock ended at: %f ============\n", (float)end);
	time1 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 1 is:%f ============\n", time1);
	pauseConsole();
		
	//Sorted array
	printf("\n============ Sorted array dataset 1 is: ============\n");
	pauseConsole();
	for(i=0; i<15000; i++)
	{
		printf("\n============ Index %d::Element %d ============\n",i, arr1[i]);
	}	
}

pauseConsole();
//populating arrays with dataset 2
	printf("\n============ Unsorted array dataset 2 is: ============\n");
	pauseConsole();
	for(i=0;i<65000;i++)
	{
		//displaying unsorted array
		for(i=0;i<65000;i++)
		{
			//populating array with random numbers
			arr2[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr2[i]);
		}
		pauseConsole();
			//bubble sort begins
			begin = clock();//variable to mark the starting time of sorting
			printf("\n\n============ Dataset 2 Clock started at:%f =============\n", (float)begin);
			pauseConsole();	
		for(i=0;i<65000;i++)
		{
			
			for(y=0;y<=65000-1-i;y++)
			{
					if(arr2[y]>arr2[y+1])
				{
					temp=arr2[y];
					arr2[y]=arr2[y+1];
					arr2[y+1]=temp;	
				}
			
			}		
		
	}
	end = clock();
	//system("\npause");	
	printf("\n============= Dataset 2 Clock ended at:%f ============\n", (float)end);
	time2 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 2 is:%f ============\n", time2);
	pauseConsole();
		
	//Sorted array
	printf("\n");
	printf("============ Sorted array dataset 2 is:: ============\n");
	pauseConsole();
	for(i=0; i<65000; i++)
	{
		printf("\n============ Index %d::Element %d ============\n",i, arr2[i]);
	}	
}
	pauseConsole();
	
	//populating arrays with dataset 3
	printf("\n============ Unsorted array dataset 3 is: ============\n");
	pauseConsole();
	for(i=0;i<150000;i++)
	{
		//displaying unsorted array
		for(i=0;i<150000;i++)
		{
			//populating array with random numbers
			arr3[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr3[i]);
		}
		pauseConsole();
			//bubble sort begins
			begin = clock();//variable to mark the starting time of sorting
			printf("\n============ Dataset 3 Clock started at:%f =============\n", (float)begin);	
		for(i=0;i<150000;i++)
		{
			//min=i;
			for(y=0;y<=150000-1-i;y++)
			{
					if(arr3[y]>arr3[y+1])
				{
					temp=arr3[y];
					arr3[y]=arr3[y+1];
					arr3[y+1]=temp;	
				}
			
			}		
		
	}
	end = clock();
	pauseConsole();	
	printf("\n============ Dataset 3 Clock ended at: %f ============\n", (float)end);
	time3 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 3 is: %f ============\n", time3);
	pauseConsole();
	//Sorted array
	printf("\n============ Sorted array dataset 3 is:: ============\n");
	pauseConsole();
	for(i=0; i<150000; i++)
	{
		printf("\n============ Index %d::Element %d ============\n\n",i, arr3[i]);
	}	
}

}
	
void Quick_Sort()
{
	void swap(int *a, int *b)
	{
		int temp = *a;
		*a=*b;
		*b=temp;
	}
	int arr1[15000];
	int arr2[65000];
	int arr3[150000];
	//data type for calculating time
	clock_t begin, end;
	//variable for storing total time of execution for each dataset
	double time1,time2, time3;
	//variables used in loops and algorithm
	int x, i, y, min, temp;
	//populating array with dataset 1
	printf("\n============ Unsorted array dataset ============ 1:\n");
	for(i=0;i<15000;i++)
	{
		//displaying unsorted array
		for(i=0;i<15000;i++)
		{
			//populating array with random numbers
			arr1[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
		}
		system("pause");
			
			//quick sort begins
			begin = clock();//variable to mark the starting time of sorting
			printf("\n\n============ Dataset 1 Clock started at: %f ============\n", (float)begin);
	
			//function to find partition position
			int part(int arr1[], int low, int high)
			{
				//selecting the upper bound
				int big = arr1[high];
				
				//variable to hold the greater element
				int x = (low-1);
				
				//traversing array and comparing
				//each element with big
				for(y=low; y<high; y++)
				{
					if(arr1[y]<= big)
					{
						//swapping element if it is smaller than big
						//with the greater element held by x
						x++;
						//swaaping element x with y
						swap(&arr1[x], &arr1[y]);
						
					}
				}
				//swap the big element with greater element at x
				swap(&arr1[x+1], &arr1[high]);
					return (x+1);
			}
		}
		void qSort(int arr1, int low, int high)
		{
			if(low<high)
			{
				//finding the big element placing elements smaller to the left
				//elements bigger to the right
				int partition=part(arr1, low, high);
				
				qSort(arr1, low, partition-1);
				
				qSort(arr1, partition+1, high);
			}
		}
		system("pause");				
	
	end = clock();
	system("\npause");	
	printf("\n============ Dataset 1 Clock ended at: %f ============\n", (float)end);
	time1 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 1 is:%f ============\n", time1);
	system("\npause");
	//Sorted array
	printf("\n============ Sorted array dataset 1 is: ============\n");
	system("\npause");
	for(i=0; i<15000; ++i)
	{
		printf("\n============ Index %d::Element %d ============\n",i, arr1[i]);
	}	


system("pause");
//populating arrays with dataset 2
	printf("\n============ Unsorted array dataset 2 is: ============\n");
	system("pause");
	for(i=0;i<65000;i++)
	{
		//displaying unsorted array
		for(i=0;i<65000;i++)
		{
			//populating array with random numbers
			arr2[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
		}
		system("pause");
			
		//quick sort begins
		begin = clock();//variable to mark the starting time of sorting
		printf("\n\n============ Dataset 1 Clock started at: %f ============\n", (float)begin);
	
		//function to find partition position
		int part(int arr2[], int low, int high)
			{
				//selecting the upper bound
				int big = arr2[high];
				
				//variable to hold the greater element
				int x = (low-1);
				
				//traversing array and comparing
				//each element with big
				for(y=low; y<high; y++)
				{
					if(arr2[y]<= big)
					{
						//swapping element if it is smaller than big
						//with the greater element held by x
						x++;
						//swaaping element x with y
						swap(&arr2[x], &arr2[y]);
						
					}
				}
				//swap the big element with greater element at x
				swap(&arr2[x+1], &arr2[high]);
					return (x+1);
			}
	
		void qSort(int arr2, int low, int high)
		{
			if(low<high)
			{
				//finding the big element placing elements smaller to the left
				//elements bigger to the right
				int partition=part(arr2, low, high);
				
				qSort(arr2, low, partition-1);
				
				qSort(arr2, partition+1, high);
			}
		}
	system("pause");
	
	//populating arrays with dataset 3
	printf("\n============ Unsorted array dataset 3 is: ============\n");
	system("pause");
	for(i=0;i<150000;i++)
	{
		//displaying unsorted array
		for(i=0;i<150000;i++)
		{
			//populating array with random numbers
			arr3[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
			system("pause");
			
			//quick sort begins
			begin = clock();//variable to mark the starting time of sorting
			printf("\n\n============ Dataset 1 Clock started at: %f ============\n", (float)begin);
	
			//function to find partition position
			int part(int arr3[], int low, int high)
			{
				//selecting the upper bound
				int big = arr3[high];
				
				//variable to hold the greater element
				int x = (low-1);
				
				//traversing array and comparing
				//each element with big
				for(y=low; y<high; y++)
				{
					if(arr3[y]<= big)
					{
						//swapping element if it is smaller than big
						//with the greater element held by x
						x++;
						//swaaping element x with y
						swap(&arr3[x], &arr3[y]);
						
					}
				}
				//swap the big element with greater element at x
				swap(&arr3[x+1], &arr3[high]);
					return (x+1);
			}
		}
		void qSort(int arr3, int low, int high)
		{
			if(low<high)
			{
				//finding the big element placing elements smaller to the left
				//elements bigger to the right
				int partition=part(arr3, low, high);
				
				qSort(arr3, low, partition-1);
				
				qSort(arr3, partition+1, high);
			}
		}
	}
	end = clock();
	system("pause");	
	printf("\n============ Dataset 3 Clock ended at: %f ============\n", (float)end);
	time3 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 3 is: %f ============\n", time3);
	system("pause");
	//Sorted array
	printf("\n============ Sorted array dataset 3 is:: ============\n");
	system("pause");
	for(i=0; i<150000; i++)
	{
		printf("\n============ Index %d::Element %d ============\n\n",i, arr3[i]);
	}	
}

	
}
void Selection_Sort()
{
	int arr1[15000];
	int arr2[65000];
	int arr3[150000];
	//data type for calculating time
	clock_t begin, end;
	//variable for storing total time of execution for each dataset
	double time1,time2, time3;
	//variables used in loops and algorithm
	int x, i, y=0, min, temp;
	//populating arrays with datasets of 15000, 65000 and 150000
	printf("\n============ Unsorted array dataset ============ 1:\n");
	for(i=0;i<15000;i++)
	{
		//displaying unsorted array
		for(i=0;i<15000;i++)
		{
			//populating array with random numbers
			arr1[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
		}
		system("pause");
			//selection sort begins
			begin = clock();//variable to mark the starting time of sorting
			printf("\n\n============ Dataset 1 Clock started at: %f ============\n", (float)begin);
			system("pause");	
		for(i=0;i<15000;i++)
		{
			min=i;
			for(y=i+1;y<15000;y++)
			{
				if(arr1[i]>arr1[y])
				{
					temp=arr1[i];
					arr1[i]=arr1[y];
					arr1[y]=temp;	
				}
			
			}		
	}
	end = clock();
	system("pause");	
	printf("\n============ Dataset 1 Clock ended at: %f ============\n", (float)end);
	time1 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 1:%f ============\n", time1);
	system("pause");
	//Sorted array
	printf("\n============ Sorted array dataset 1: ============\n");
	system("pause");
	for(i=0; i<y; i++)
	{
		printf("\n============ Index %d::Element %d ============\n",i, arr1[i]);
	}	
}

system("pause");

//populating arrays with dataset
	printf("\n============ Unsorted array dataset 2 is: ============\n");
	system("pause");
	for(i=0;i<65000;i++)
	{
		//displaying unsorted array
		for(i=0;i<65000;i++)
		{
			//populating array with random numbers
			arr2[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr2[i]);
		}
		system("pause");
			//selection sort begins
			begin = clock();//variable to mark the starting time of sorting
			printf("\n\n============ Dataset 2 Clock started at:%f =============\n", (float)begin);
			system("pause");	
		for(i=0;i<65000;i++)
		{
			min=i;
			for(y=i+1;y<65000;y++)
			{
				if(arr2[i]>arr2[y])
				{
					temp=arr2[i];
					arr2[i]=arr2[y];
					arr2[y]=temp;	
				}
			
			}	
		
	}
	end = clock();
	system("\npause");	
	printf("\n============= Dataset 2 Clock ended at:%f ============\n", (float)end);
	time2 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 2:%f ============\n", time2);
	system("pause");
	//Sorted array
	printf("\n");
	printf("============ Sorted array dataset 2 is:: ============\n");
	system("pause");
	for(i=0; i<y; i++)
	{
		printf("\n============ Index %d::Element %d ============\n",i, arr2[i]);
	}	
}

	system("pause");
	
	//populating arrays with dataset
	printf("\n============ Unsorted array dataset 3 is: ============\n");
	system("pause");
	for(i=0;i<150000;i++)
	{
		//displaying unsorted array
		for(i=0;i<150000;i++)
		{
			//populating array with random numbers
			arr3[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr3[i]);
		}
		system("pause");
			//selection sort begins
			begin = clock();//variable to mark the starting time of sorting
			printf("\n============ Dataset 3 Clock started at:%f =============\n", (float)begin);	
		for(i=0;i<150000;i++)
		{
			min=i;
			for(y=i+1;y<150000;y++)
			{
				if(arr3[i]>arr3[y])
				{
					temp=arr3[i];
					arr3[i]=arr3[y];
					arr3[y]=temp;	
				}
			
			}		
	}
	end = clock();
	system("\npause");	
	printf("\n============ Dataset 3 Clock ended at: %f ============\n", (float)end);
	time3 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 3 is:%f ============\n", time3);
	system("pause");
	//Sorted array
	printf("\n============ Sorted array dataset 3 is:: ============\n");
	system("pause");
	for(i=0; i<y; i++)
	{
		printf("\n============ Index %d::Element %d ============\n\n",i, arr3[i]);
	}	
}

}


void Insertion_Sort()
{
		int arr1[15000];
	int arr2[65000];
	int arr3[150000];
	//data type for calculating time
	clock_t begin, end;
	//variable for storing total time of execution for each dataset
	double time1,time2, time3;
	//variables used in loops and algorithm
	int x, i, y=0, min, temp;
	//populating array with dataset 1
	printf("\n============ Unsorted array dataset ============ 1:\n");
	for(i=0;i<15000;i++)
	{
		//displaying unsorted array
		for(i=0;i<15000;i++)
		{
			//populating array with random numbers
			arr1[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
		}
		system("pause");
			//insertion sort begins
			begin = clock();//variable to mark the starting time of sorting
			printf("\n\n============ Dataset 1 Clock started at: %f ============\n", (float)begin);
				
		for(i=1;i<=15000-1;i++)
		{
			y=i;
			while(y>0 && arr1[y]<arr1[y-1])
			{
				temp=arr1[y];
				arr1[y]=arr1[y-1];
				arr1[y-1]=temp;
				y--;
			}
			
			}		
	
	end = clock();
	system("\npause");	
	printf("\n============ Dataset 1 Clock ended at: %f ============\n", (float)end);
	time1 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 1 is:%f ============\n", time1);
	system("\npause");
	//Sorted array
	printf("\n============ Sorted array dataset 1 is: ============\n");
	system("\npause");
	for(i=0; i<=15000-1; i++)
	{
		printf("\n============ Index %d::Element %d ============\n",i, arr1[i]);
	}
}

system("pause");
//populating arrays with dataset 2
	printf("\n============ Unsorted array dataset 2 is: ============\n");
	system("pause");
	for(i=0;i<65000;i++)
	{
		//displaying unsorted array
		for(i=0;i<65000;i++)
		{
			//populating array with random numbers
			arr2[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr2[i]);
		}
		system("pause");
			//bubble sort begins
			begin = clock();//variable to mark the starting time of sorting
			printf("\n\n============ Dataset 2 Clock started at:%f =============\n", (float)begin);
			system("pause");	
	for(i=1;i<=65000-1;i++)
		{
			y=i;
			while(y>0 && arr2[y]<arr2[y-1])
			{
				temp=arr2[y];
				arr2[y]=arr2[y-1];
				arr2[y-1]=temp;
				y--;
			}
			
			}		
	}

	end = clock();
	//system("\npause");	
	printf("\n============= Dataset 2 Clock ended at:%f ============\n", (float)end);
	time2 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 2 is:%f ============\n", time2);
	system("pause");
	//Sorted array
	printf("\n");
	printf("============ Sorted array dataset 2 is:: ============\n");
	system("pause");
	for(i=0; i<=65000-1; i++)
	{
		printf("\n============ Index %d::Element %d ============\n",i, arr2[i]);
	}	

	system("pause");
	
	//populating arrays with dataset 3
	printf("\n============ Unsorted array dataset 3 is: ============\n");
	system("pause");
	for(i=0;i<150000;i++)
	{
		//displaying unsorted array
		for(i=0;i<150000;i++)
		{
			//populating array with random numbers
			arr3[i]=rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr3[i]);
		}
		system("pause");
			//bubble sort begins
			begin = clock();//variable to mark the starting time of sorting
			printf("\n============ Dataset 3 Clock started at:%f =============\n", (float)begin);	
		for(i=1;i<=150000-1;i++)
		{
			y=i;
			while(y>0 && arr3[y]<arr3[y-1])
			{
				temp=arr3[y];
				arr3[y]=arr3[y-1];
				arr3[y-1]=temp;
				y--;
			}
			
			}		
	
	end = clock();
	system("pause");	
	printf("\n============ Dataset 3 Clock ended at: %f ============\n", (float)end);
	time3 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 3 is: %f ============\n", time3);
	system("pause");
	//Sorted array
	printf("\n============ Sorted array dataset 3 is:: ============\n");
	system("pause");
	for(i=0; i<150000; i++)
	{
		printf("\n============ Index %d::Element %d ============\n\n",i, arr3[i]);
	}
}
}
	

void Merge_Sort()
{
	
}

void Heap_Sort()
{
	
}



