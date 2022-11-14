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

// function to find partition position
int part(int arr[], int low, int high)
{
    // selecting the upper bound
    const int big = arr[high];
····
    // variable to hold the greater element
    int greaterInd = low - 1;
····
    // traversing array and comparing
    // each element with big
    for (int i = low; i < high; ++i)
    {   
        if (arr[i] <= big) {
            ++greaterInd;
            swap_int(&arr[greaterInd], &arr[i]);
        }   
    }   
····
    // swap the big element with greater element at x
    swap_int(&arr[greaterInd + 1], &arr[high]);
    return greaterInd + 1;
}

void qSort(int arr[], int low, int high)
{
    if (low < high) {
        // finding the big element placing elements smaller to the left
        // elements bigger to the right
        int partition = part(arr, low, high);
········
        qSort(arr, low, partition - 1); 
        qSort(arr, partition + 1, high);
    }   
}
	
void quick_sort(int len, int arr[len])
{
    time_t begin = time_millisec();
    qSort(arr, 0, len-1);
    time_t end = time_millisec();
····
    printf("============ Sorted array: ============\n");
    array_print(len, arr);
    printf("\n");
····
    printf("On array of %d elements, Quick Sort took %ld[ms].\n", len, end - begin);
}


void selection_sort(int len, int arr[len])
{
    time_t begin = time_millisec();
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[i] > arr[j]) {
                swap_int(&arr[i], &arr[j]);
            }
        }
    }
    time_t end = time_millisec();
····
    printf("============ Sorted array: ============\n");
    array_print(len, arr);
    printf("\n");
····
    printf("On array of %d elements, Selection Sort took %ld[ms].\n", len, end - begin);
}

void insertion_sort(int len, int arr[len])
{
    time_t begin = time_millisec();
    for (int i = 1; i < len; ++i)
    {
        for (int y = i; y > 0 && arr[y] < arr[y - 1]; --y)
        {
            swap_int(&arr[y], &arr[y-1]);
        }
    }
    time_t end = time_millisec();
····
    printf("============ Sorted array: ============\n");
    array_print(len, arr);
    printf("\n");
····
    printf("On array of %d elements, Insertion Sort took %ld[ms].\n", len, end - begin);
}

