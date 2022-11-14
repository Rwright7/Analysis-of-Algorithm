#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<errno.h>


#define SIZEOF_ARRAY(x) (sizeof(x)/sizeof(*(x)))


enum Choice {
	CHOICE_INVALID = -1,
	CHOICE_DONT_SORT,
	CHOICE_BUBBLE_SORT,
	CHOICE_QUICK_SORT,
	CHOICE_SELECTION_SORT,
	CHOICE_INSERTION_SORT,
	CHOICE_MERGE_SORT,
	CHOICE_HEAP_SORT,
};

void array_randomize(int len, int arr[len], int maxValue)
{
	for (int i = 0; i < len; ++i)
	{
		arr[i] = rand() % maxValue;
	}
}

void array_print(int len, const int arr[len])
{
	printf("%d: [", len);
	for (int i = 0; i < (len - 1); ++i)
	{
		printf("%d,", arr[i]);
	}
	printf("%d]\n", arr[len - 1]);
}

void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


time_t time_millisec(void)
{
	struct timespec time = {0};
	clock_gettime(CLOCK_MONOTONIC, &time);
	return (time.tv_sec. * 1000000ULL) + (time.tv_nsec / 1000ULL);
}


enum Choice menu(void);

void bubble_sort(int len, int arr[len]);
void quick_sort(int len, int arr[len]);
void selection_sort(int len, int arr[len]);
void insertion_Sort(int len, int arr[len]);
void merge_sort(int len, int arr[len]);
void heap_sort(int len, int arr[len]);


#define ARR_SIZE 10

int main(void)
{
	srand((unsigned)time(NULL));
	
	int testArray[ARR_SIZE] = { 0 };
	enum Choice choice = 0; 
	
	do {
		choice = menu ();
		system("clear");
		
		if (choice != CHOICE_INVALID && choice != CHOICE_DONT_SORT) {
           	 array_randomize(SIZEOF_ARRAY(testArray), testArray, 10000);
            	 printf("============ Unsorted array: ============\n");
            	 array_print(SIZEOF_ARRAY(testArray), testArray);
            	 printf("\n");
        }   

	switch (choice)
	{
	case CHOICE_BUBBLE_SORT:
            bubble_sort(SIZEOF_ARRAY(testArray), testArray);
            break;
        case CHOICE_QUICK_SORT:
            quick_sort(SIZEOF_ARRAY(testArray), testArray);
            break;
        case CHOICE_SELECTION_SORT:
            selection_sort(SIZEOF_ARRAY(testArray), testArray);
            break;
        case CHOICE_INSERTION_SORT:
            insertion_sort(SIZEOF_ARRAY(testArray), testArray);
            break;
        case CHOICE_MERGE_SORT:
            merge_sort(SIZEOF_ARRAY(testArray), testArray);
            break;
        case CHOICE_HEAP_SORT:
            heap_sort(SIZEOF_ARRAY(testArray), testArray);
            break;
        case CHOICE_DONT_SORT:
            break;

        case CHOICE_INVALID:
        default:
            printf("Invalid selection!\n\n");
        }
    } while (choice != CHOICE_DONT_SORT);

    printf("....goodbye!....\n\n");

    return 0;
}
		
enum Choice menu(void)
{
	printf("  ============ SORTING ALGORITHMS WITH RUNTIME ============\n");
	printf("Choose an option:\n");
	
	printf("%d. Exit\n", CHOICE_DONT_SORT);
	printf("%d. Bubble sort\n", CHOICE_BUBBLE_SORT);
	printf("%d. Quick sort\n", CHOICE_QUICK_SORT);
	printf("%d. Selection sort\n", CHOICE_SELECTION_SORT);
	printf("%d. Insertion sort\n", CHOICE_INSERTION_SORT);
	printf("%d. Merge sort\n", CHOICE_MERGE_SORT);
	printf("%d. Heap sort\n", CHOICE_HEAP_SORT);
	
	printf(" ============ SORTING ALGORITHMS WITH RUNTIME ============\n");
	printf(">>>> ");
	
	char buff[64] = { 0 };
	fgets(buff, sizeof (buff), stdin);
	
	char *endptr = 	NULL; 
	errno = 0; 
	int x = (int)strtol(buff, &endptr, 10);
	if (errno != 0 || endptr == buff){
		return CHOICE_INVALID;
	}
	return x; 
}
		
void Bubble_Sort(const int len, int arr[len])
{
	time_t begin = time_millisec();
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < (len - 1 - i); ++j)
		{
			if (arr[j] > arr[j + 1]){
				swap_int(&arr[j], &arr[j + 1]);
			}
		}
	}
	time_t end = time_millisec();
	
	 printf("============ Sorted array: ============\n");
         array_print(len, arr);
         printf("\n");

    	printf("On array of %d elements, Bubble Sort took %ld[ms].\n", len, end - begin);
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int part(int arr1[], int low, int high)
{
	int y;
	// selecting the upper bound
	int big = arr1[high];

	// variable to hold the greater element
	int x = (low - 1);

	// traversing array and comparing each element with big
	for (y = low; y < high; y++)
	{
		if (arr1[y] <= big)
		{
			//swapping element if it is smaller than big with the greater element held by x
			x++;
			//swapping element x with y
			swap(&arr1[x], &arr1[y]);
		}
	}
	//swap the big element with greater element at x
	swap(&arr1[x+1], &arr1[high]);
	return (x+1);
}

int part_two(int arr2[], int low, int high)
{
	int y;
	// selecting the upper bound
	int big = arr2[high];

	// variable to hold the greater element
	int x = (low - 1);

	// traversing array and comparing each element with big
	for (y = low; y < high; y++)
	{
		if (arr2[y] <= big)
		{
			//swapping element if it is smaller than big with the greater element held by x
			x++;
			//swapping element x with y
			swap(&arr2[x], &arr2[y]);
		}
	}
	swap(&arr2[x+1], &arr2[high]);
	return (x+1);
}

int part_three(int arr3[], int low, int high)
{
	int y;
	// selecting the upper bound
	int big = arr3[high];

	// variable to hold the greater element
	int x = (low - 1);

	// traversing array and comparing each element with big
	for (y = low; y < high; y++)
	{
		if (arr3[y] <= big)
		{
			//swapping element if it is smaller than big with the greater element held by x
			x++;
			//swapping element x with y
			swap(&arr3[x], &arr3[y]);
		}
	}
	swap(&arr3[x+1], &arr3[high]);
	return (x+1);
}
void qSort(int arr1, int low, int high)
{
	if (low < high)
	{
		int partition = part(&arr1, low, high);
		qSort(arr1, low, partition - 1);
		qSort(arr1, partition + 1, high);
	}
}

void qSort_two(int arr2, int low, int high)
{
	if (low < high)
	{
		int partition = part(&arr2, low, high);
		qSort(arr2, low, partition - 1);
		qSort(arr2, partition + 1, high);
	}
}

void qSort_three(int arr3, int low, int high)
{
	if (low < high)
	{
		int partition = part(&arr3, low, high);
		qSort(arr3, low, partition - 1);
		qSort(arr3, partition + 1, high);
	}
}

void Quick_Sort()
{
	void swap(int *a, int *b);
	int low, high;
	int arr1[15000];
	int arr2[65000];
	int arr3[150000];

	clock_t begin, end;
	double time1,time2, time3;
	int x, i, min, temp;

	//populating array with dataset 1
	printf("\n============ Unsorted array dataset ============ 1:\n");
	for(i = 0; i < 15000; i++)
	{
		//displaying unsorted array
		for(i = 0; i < 15000; i++)
		{
			//populating array with random numbers
			arr1[i] = rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
		}
		pauseConsole();

		//quick sort begins
		begin = clock();//variable to mark the starting time of sorting
		printf("\n\n============ Dataset 1 Clock started at: %f ============\n", (float)begin);

		//function to find partition position
		 part(&arr1, low, high);
		
	}
		qSort(&arr1,low,high);
	pauseConsole();

	end = clock();
	pauseConsole();
	printf("\n============ Dataset 1 Clock ended at: %f ============\n", (float)end);
	time1 = ((double)(end - begin))/CLOCKS_PER_SEC;
	printf("\n============ Total execution time for dataset 1 is:%f ============\n", time1);
	pauseConsole();

	//Sorted array
	printf("\n============ Sorted array dataset 1 is: ============\n");
	system("\npause");
	for(i = 0; i < 15000; ++i)
	{
		printf("\n============ Index %d::Element %d ============\n",i, arr1[i]);
	}	


	pauseConsole();

	//populating arrays with dataset 2
	printf("\n============ Unsorted array dataset 2 is: ============\n");
	pauseConsole();
	for(i = 0; i < 65000; i++)
	{
		//displaying unsorted array
		for(i = 0; i < 65000; i++)
		{
			//populating array with random numbers
			arr2[i] = rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
		}
		pauseConsole();

		//quick sort begins
		begin = clock();	//variable to mark the starting time of sorting
		printf("\n\n============ Dataset 2 Clock started at: %f ============\n", (float)begin);

		//function to find partition position
		 part_two(arr2,low, high);
		qSort_two(arr2,low,high);
		pauseConsole();

		//populating arrays with dataset 3
		printf("\n============ Unsorted array dataset 3 is: ============\n");
		pauseConsole();
		for(i = 0; i < 150000; i++)
		{
			//displaying unsorted array
			for(i = 0; i < 150000; i++)
			{
				//populating array with random numbers
				arr3[i] = rand();
				printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
				pauseConsole();

				//quick sort begins
				begin = clock();//variable to mark the starting time of sorting
				printf("\n\n============ Dataset 1 Clock started at: %f ============\n", (float)begin);

				//function to find partition position
				part_three(arr3, low, high);
			}
				qSort_three(arr3, low, high);
		}
		end = clock();
		pauseConsole();
		printf("\n============ Dataset 3 Clock ended at: %f ============\n", (float)end);
		time3 = ((double)(end - begin)) / CLOCKS_PER_SEC;
		printf("\n============ Total execution time for dataset 3 is: %f ============\n", time3);
		pauseConsole();

		//Sorted array
		printf("\n============ Sorted array dataset 3 is:: ============\n");
		pauseConsole();
		for(i = 0; i < 150000; i++)
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

	clock_t begin, end;
	double time1,time2, time3;
	int i, y=0, temp;  //min

	//populating arrays with datasets of 15000, 65000 and 150000
	printf("\n============ Unsorted array dataset ============ 1:\n");
	for(i = 0; i < 15000; i++)
	{
		//displaying unsorted array
		for(i = 0; i < 15000; i++)
		{
			//populating array with random numbers
			arr1[i] = rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
		}
		pauseConsole();

		//selection sort begins
		begin = clock(); //variable to mark the starting time of sorting
		printf("\n\n============ Dataset 1 Clock started at: %f ============\n", (float)begin);
		pauseConsole();	
		for(i = 0; i < 15000; i++)
		{
		//	min=i;
			for(y = i + 1; y < 15000; y++)
			{
				if(arr1[i] > arr1[y])
				{
					temp = arr1[i];
					arr1[i] = arr1[y];
					arr1[y] = temp;
				}

			}		
		}
		end = clock();
		pauseConsole();	
		printf("\n============ Dataset 1 Clock ended at: %f ============\n", (float)end);
		time1 = ((double)(end - begin)) / CLOCKS_PER_SEC;
		printf("\n============ Total execution time for dataset 1:%f ============\n", time1);
		pauseConsole();

		//Sorted array
		printf("\n============ Sorted array dataset 1: ============\n");
		pauseConsole();
		for(i = 0; i < y; i++)
		{
			printf("\n============ Index %d::Element %d ============\n",i, arr1[i]);
		}	
	}

	pauseConsole();

	//populating arrays with dataset
	printf("\n============ Unsorted array dataset 2 is: ============\n");
	pauseConsole();
	for(i = 0; i < 65000; i++)
	{
		//displaying unsorted array
		for(i = 0; i < 65000; i++)
		{
			//populating array with random numbers
			arr2[i] = rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr2[i]);
		}
		pauseConsole();

		//selection sort begins
		begin = clock();  //variable to mark the starting time of sorting
		printf("\n\n============ Dataset 2 Clock started at:%f =============\n", (float)begin);
		pauseConsole();

		for(i = 0; i < 65000; i++)
		{
		//	min=i;
			for(y = i + 1; y < 65000; y++)
			{
				if(arr2[i] > arr2[y])
				{
					temp = arr2[i];
					arr2[i] = arr2[y];
					arr2[y] = temp;
				}

			}	

		}
		end = clock();
		pauseConsole();	
		printf("\n============= Dataset 2 Clock ended at:%f ============\n", (float)end);
		time2 = ((double)(end - begin)) / CLOCKS_PER_SEC;
		printf("\n============ Total execution time for dataset 2:%f ============\n", time2);
		pauseConsole();

		//Sorted array
		printf("\n");
		printf("============ Sorted array dataset 2 is:: ============\n");
		pauseConsole();
		for(i = 0; i < y; i++)
		{
			printf("\n============ Index %d::Element %d ============\n",i, arr2[i]);
		}	
	}

	pauseConsole();

	//populating arrays with dataset
	printf("\n============ Unsorted array dataset 3 is: ============\n");
	pauseConsole();
	for(i = 0; i < 150000; i++)
	{
		//displaying unsorted array
		for(i = 0; i < 150000; i++)
		{
			//populating array with random numbers
			arr3[i] = rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr3[i]);
		}
		pauseConsole();

		//selection sort begins
		begin = clock();//variable to mark the starting time of sorting
		printf("\n============ Dataset 3 Clock started at:%f =============\n", (float)begin);
		for(i = 0; i < 150000; i++)
		{
		//	min=i;
			for(y = i + 1; y < 150000; y++)
			{
				if(arr3[i] > arr3[y])
				{
					temp = arr3[i];
					arr3[i] = arr3[y];
					arr3[y] = temp;
				}

			}
		}
		end = clock();
		pauseConsole();
		printf("\n============ Dataset 3 Clock ended at: %f ============\n", (float)end);
		time3 = ((double)(end - begin)) / CLOCKS_PER_SEC;
		printf("\n============ Total execution time for dataset 3 is:%f ============\n", time3);
		pauseConsole();

		//Sorted array
		printf("\n============ Sorted array dataset 3 is:: ============\n");
		pauseConsole();
		for(i = 0; i < y; i++)
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

	clock_t begin, end;
	double time1,time2, time3;
	int i, y=0, temp;

	//populating array with dataset 1
	printf("\n============ Unsorted array dataset ============ 1:\n");
	for(i = 0; i < 15000; i++)
	{
		//displaying unsorted array
		for(i = 0; i < 15000; i++)
		{
			//populating array with random numbers
			arr1[i] = rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr1[i]);
		}
		pauseConsole();
		//insertion sort begins
		begin = clock();//variable to mark the starting time of sorting
		printf("\n\n============ Dataset 1 Clock started at: %f ============\n", (float)begin);

		for(i = 1; i <= 15000 - 1; i++)
		{
			y = i;
			while(y > 0 && arr1[y] < arr1[y - 1])
			{
				temp = arr1[y];
				arr1[y] = arr1[y - 1];
				arr1[y - 1] = temp;
				y--;
			}

		}		

		end = clock();
		pauseConsole();	
		printf("\n============ Dataset 1 Clock ended at: %f ============\n", (float)end);
		time1 = ((double)(end - begin)) / CLOCKS_PER_SEC;
		printf("\n============ Total execution time for dataset 1 is:%f ============\n", time1);
		pauseConsole();

		//Sorted array
		printf("\n============ Sorted array dataset 1 is: ============\n");
		pauseConsole();
		for(i = 0; i <= 15000 - 1; i++)
		{
			printf("\n============ Index %d::Element %d ============\n",i, arr1[i]);
		}
	}

	pauseConsole();

	//populating arrays with dataset 2
	printf("\n============ Unsorted array dataset 2 is: ============\n");
	pauseConsole();
	for(i = 0; i < 65000; i++)
	{
		//displaying unsorted array
		for(i = 0; i < 65000; i++)
		{
			//populating array with random numbers
			arr2[i] = rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr2[i]);
		}
		pauseConsole();

		//bubble sort begins
		begin = clock();//variable to mark the starting time of sorting
		printf("\n\n============ Dataset 2 Clock started at:%f =============\n", (float)begin);
		pauseConsole();	
		for(i = 1; i <= 65000 - 1; i++)
		{
			y = i;
			while(y > 0 && arr2[y] < arr2[y - 1])
			{
				temp = arr2[y];
				arr2[y] = arr2[y - 1];
				arr2[y - 1] = temp;
				y--;
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
	for(i = 0; i <= 65000 - 1; i++)
	{
		printf("\n============ Index %d::Element %d ============\n",i, arr2[i]);
	}	

	pauseConsole();

	//populating arrays with dataset 3
	printf("\n============ Unsorted array dataset 3 is: ============\n");
	pauseConsole();
	for(i = 0; i < 150000; i++)
	{
		//displaying unsorted array
		for(i = 0; i < 150000; i++)
		{
			//populating array with random numbers
			arr3[i] = rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr3[i]);
		}
		pauseConsole();

		//bubble sort begins
		begin = clock();//variable to mark the starting time of sorting
		printf("\n============ Dataset 3 Clock started at:%f =============\n", (float)begin);
		for(i = 1; i <= 150000 - 1; i++)
		{
			y = i;
			while(y > 0 && arr3[y] < arr3[y - 1])
			{
				temp = arr3[y];
				arr3[y] = arr3[y-1];
				arr3[y - 1] = temp;
				y--;
			}

		}

		end = clock();
		pauseConsole();	
		printf("\n============ Dataset 3 Clock ended at: %f ============\n", (float)end);
		time3 = ((double)(end - begin)) / CLOCKS_PER_SEC;
		printf("\n============ Total execution time for dataset 3 is: %f ============\n", time3);
		pauseConsole();

		//Sorted array
		printf("\n============ Sorted array dataset 3 is:: ============\n");
		pauseConsole();
		for(i = 0; i < 150000; i++)
		{
			printf("\n============ Index %d::Element %d ============\n\n",i, arr3[i]);
		}
	}
}

void Merge(int *array, int left, int mid, int right)
{
	int i = 0, Temp_Array[right - left + 1 ];
	int position = 0, left_Pos = left, right_Pos = mid + 1;

	while (left_Pos <= mid && right_Pos <= right)
	{
		if (array[left_Pos] < array [right_Pos])
		{
			Temp_Array[position++] = array[left_Pos++];
		}
		else
		{
			Temp_Array[position++] = array[right_Pos++]; 
		}
	}

	while (left_Pos <= mid)
		Temp_Array[position++] = array[left_Pos++];
	while (right_Pos <= right)
		Temp_Array[position++] = array[right_Pos++]; 

	for (i = 0; i < position; i++)
		array[i + left] = Temp_Array[i]; 
	return ;
}

void Merge_Sort(int *array, int left, int right)
{
	clock_t begin, end;
	double time1, time2, time3;
	int y = 0, temp, i;
	int arr1[15000], arr2[65000], arr3[150000];
	int mid = (right + left) / 2;

	if (left < right)
	{
		Merge_Sort (array, left, mid);
		Merge_Sort (array, mid + 1, right);
		Merge (array, left, mid, right);
	}


	printf("=================== Unsorted array dataset ===================== 1: \n");
	for(i = 0; i < 15000; i++)
	{
		for (i = 0; i < 15000; i++ ) 
		{
			arr1[i] = rand(); 
			printf("\n=========================== Index %d:: Element %d ==================\n", i, arr1[i]); 
		}
		pauseConsole();
		begin = clock();
		printf("\n\n==============Dataset 1 Clock started at : %f ==================\n", (float)begin); 

		for (i = 0; i <= 15000 - 1; i++)
		{
			y = i;
			while (y > 0 && arr1[y] < arr1[y - 1])
			{
				temp = arr1[y];
				arr1[y] = arr1[y - 1];
				arr1[y - 1] = temp;
				y--;
			}
		}
		end = clock();
		pauseConsole();
		printf("\n====================== Dataset 1 Clock ended at: %f ===============\n", (float)end);
		time1 = ((double)(end - begin)) / CLOCKS_PER_SEC;
		printf("\n===================== Total execution time for dataset 1 is : %f =============\n", time1);
		pauseConsole();

		//Sorted Array
		printf("\n======================== Sorted array dataset 1 is: ================\n");
		pauseConsole();
		for(i = 0; i <= 15000 - 1; i++)
		{
			printf("\n===================== Index %d::Element %d ==============\n", i, arr1[i]);
		}
	}
	pauseConsole();

	//populating arrays with dataset 2
	printf("\n============ Unsorted array dataset 2 is: ============\n");
	pauseConsole();
	for(i = 0; i < 65000; i++)
	{
		for(i = 0; i < 65000; i++)
		{
			arr2[i] = rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr2[i]);
		}
		pauseConsole();
		begin = clock();//variable to mark the starting time of sorting
		printf("\n\n============ Dataset 2 Clock started at:%f =============\n", (float)begin);
		pauseConsole();
		for(i = 0; i < 65000; i++)
		{
			for(y = 0; y <= 65000 - 1 - i; y++)
			{
				if(arr2[y] > arr2[y+1])
				{
					temp = arr2[y];
					arr2[y] = arr2[y+1];
					arr2[y+1] = temp;
				}
			}
		}
		end = clock();
		printf("\n============= Dataset 2 Clock ended at:%f ============\n", (float)end);
		time2 = ((double)(end - begin)) / CLOCKS_PER_SEC;
		printf("\n============ Total execution time for dataset 2 is:%f ============\n", time2);
		pauseConsole();
		printf("\n");
		printf("============ Sorted array dataset 2 is:: ============\n");
		pauseConsole();
		for(i = 0; i < 65000; i++)
		{
			printf("\n============ Index %d::Element %d ============\n",i, arr2[i]);
		}
	}
	pauseConsole();
	printf("\n============ Unsorted array dataset 3 is: ============\n");
	pauseConsole();
	for(i = 0; i < 150000; i++)
	{
		for(i = 0; i < 150000; i++)
		{
			arr3[i] = rand();
			printf("\n============ Index %d::Element %d ============\n", i, arr3[i]);
		}
		pauseConsole();
		begin = clock();//variable to mark the starting time of sorting
		printf("\n============ Dataset 3 Clock started at:%f =============\n", (float)begin);
		for(i = 0; i < 150000; i++)
		{
			for(y = 0; y <= 150000 - 1 - i; y++)
			{
				if(arr3[y] > arr3[y+1])
				{
					temp = arr3[y];
					arr3[y] = arr3[y+1];
					arr3[y+1] = temp;
				}
			}
		}
		end = clock();
		pauseConsole();
		printf("\n============ Dataset 3 Clock ended at: %f ============\n", (float)end);
		time3 = ((double)(end - begin)) / CLOCKS_PER_SEC;
		printf("\n============ Total execution time for dataset 3 is: %f ============\n", time3);
		pauseConsole();
		printf("\n============ Sorted array dataset 3 is:: ============\n");
		pauseConsole();
		for(i = 0; i < 150000; i++)
		{
			printf("\n============ Index %d::Element %d ============\n\n",i, arr3[i]);
		}
	}
}
void Heap_Sort()
{



}
