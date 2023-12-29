# Sorting Algorithms with Runtime Analysis

This command-line program implements various sorting algorithms and provides a runtime analysis of their performance. The implemented sorting algorithms include Bubble Sort, Quick Sort, Selection Sort, Insertion Sort, Merge Sort, and Heap Sort.

## Compilation and Execution

To compile the program, ensure that you have a C compiler installed on your system. Use the following commands:

```bash
gcc -o sorting_program sorting_program.c
```

To run the program, use:

```bash
./sorting_program
```

## Usage

1. The program will display a menu with sorting algorithm options.
2. Enter the corresponding number to choose a sorting algorithm.
3. The program will generate a random array, display the unsorted array, and then apply the selected sorting algorithm.
4. The sorted array will be displayed along with the runtime of the sorting process.

## Sorting Algorithms

### Bubble Sort

Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

### Quick Sort

Quick Sort is a divide-and-conquer algorithm that works by selecting a pivot element and partitioning the other elements around it.

### Selection Sort

Selection Sort sorts an array by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning.

### Insertion Sort

Insertion Sort builds the final sorted array one item at a time, iterating through the input elements and inserting each into its correct position.

### Merge Sort

Merge Sort is an efficient, stable, and comparison-based sorting algorithm that divides the unsorted list into n sub-lists.

### Heap Sort

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure to build a max-heap and sorts the array in-place.

## Note

This project is a demonstration of sorting algorithms and their runtime. Feel free to explore and modify the code for educational purposes or practical applications.

**Disclaimer:** This project is not optimized for large-scale production use. It is intended for educational purposes and may not cover all edge cases or provide the most efficient implementations of sorting algorithms.
