#include <iostream>
#include <cstring>
#include <ctime>

#define MAX_SIZE 10

/***************************************************************************************************
 * PROTOTYPE
 **************************************************************************************************/

/**
 * @brief [An easy function to call]
 * 
 * @param arr [Pointer to the main array]
 * @param size [Size of the main array]
 */
void quickSort(int* arr, int size);

/**
 * @brief [A recursive function to sort]
 * 
 * @param arr [Pointer to the main array]
 * @param l [Index of the left most element]
 * @param r [Index of the right most element]
 */
void qSort(int* arr, int l, int r);

/**
 * @brief [Function to separate the array into two parts]
 * 
 * @param arr [Pointer to the main array]
 * @param l [Index of the left most element]
 * @param r [Index of the right most element]
 * @return [Index of the first item of the second part]
 */
int partition(int* arr, int l, int r);

/***************************************************************************************************
 * CODE
 **************************************************************************************************/
int main()
{
    //Initialize array
    int arr[MAX_SIZE] = {9, 6, 4, 10, 1, 3, 2, 5, 8, 7};
    quickSort(arr, MAX_SIZE);
    //Show the sorted array
    for (int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << arr[i] << ' ';
    }
}


void quickSort(int* arr, int size)
{
    //Set the random seed
    srand(time(NULL));
    //Call the main sort function
    qSort(arr, 0, size - 1);
}

void qSort(int* arr, int l, int r)
{
    //Only manipulate array with more than one item
    if (l < r)
    {
        //Gets the pivot point
        int pivot = partition(arr, l, r);
        //Sort the first part
        qSort(arr, l, pivot - 1);
        //Sort the second part
        qSort(arr, pivot, r);
    }
}

int partition(int* arr, int l, int r)
{
    //Gets random key
    int key = arr[rand() % (r - l + 1) + l];

    int i = l, j = r;
    while (i <= j)
    {
        //Keep moving until find element with greater or equal value
        while (arr[i] < key)
        {
            i++;
        }
        //Keep moving until find element with less or equal value
        while (arr[j] > key)
        {
            j--;
        }
        if (i <= j)
        {
            //Swap only when two element are distinct
            if (i < j)
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
            //Change the iterators' value
            i++;
            j--;
        }
    }
    return i;
}