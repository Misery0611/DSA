#include <iostream>
#include <cstring>

#define MAX_SIZE 10

/***************************************************************************************************
 * PROTOTYPE
 **************************************************************************************************/

/**
 * @brief [An easy-calling function]
 * 
 * @param arr [Pointer to the main array]
 * @param size [Size of the main array]
 */
void mergeSort(int* arr, size_t size);

/**
 * @brief [Recursive function to sort]
 * 
 * @param arr [Pointer to the main array]
 * @param l [The index of the left most item]
 * @param r [The index of the right most item]
 */
void merge_Sort(int* arr, size_t l, size_t r);

/**
 * @brief [Merge two merged parts of the main array]
 * 
 * @param arr [Pointer to the main array]
 * @param l [The index of the left most item]
 * @param m [The index of the middle item]
 * @param r [The index of the right most item]
 */
void merge(int* arr, size_t l, size_t m, size_t r);

/***************************************************************************************************
 * CODE
 **************************************************************************************************/
int main()
{
    int arr[MAX_SIZE] = {10, 4, 5, 8, 2, 3, 7, 9, 1, 6};
    mergeSort(arr, MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

void mergeSort(int* arr, size_t size)
{
    //Call the recursive function
    merge_Sort(arr, 0, size - 1);
}

void merge_Sort(int* arr, size_t l, size_t r)
{
    //Only manipulate array with more than one element
    if (l < r)
    {
        size_t m = l + (r - l) / 2;
        //Handle the half first part
        merge_Sort(arr, l, m);
        //Handle the second part
        merge_Sort(arr, m + 1, r);
        //Merge the whole array
        merge(arr, l, m, r);
    }
}

void merge(int* arr, size_t l, size_t m, size_t r)
{
    //Initialize two new pointers to store the two half parts
    int* leftArr = new int[m - l + 1];
    int* rightArr = new int[r - m];
    //Copy value from the main array
    memmove(leftArr, arr + l, (m - l + 1) * sizeof(int));
    memmove(rightArr, arr + m + 1, (r - m) * sizeof(int));

    int j = 0, k = 0, i = l;
    //Choose smaller items first
    while (j < m - l + 1 && k < r - m)
    {
        if (leftArr[j] < rightArr[k])
        {
            arr[i++] = leftArr[j++];
        }
        else
        {
            arr[i++] = rightArr[k++];
        }
    }
    //Copy the rest element of the half first array if exists
    while (j < m - l + 1)
    {
        arr[i++] = leftArr[j++];
    }
    //Copy the rest element of the second array if exists
    while (k < r - m)
    {
        arr[i++] = rightArr[k++];
    }
    //Release memories
    delete[] leftArr;
    leftArr = NULL;
    delete[] rightArr;
    rightArr = NULL;
}