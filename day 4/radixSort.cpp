#include <iostream>
#include <cstring>

#define MAX_SIZE 10

/***************************************************************************************************
 * PROTOTYPE
 **************************************************************************************************/

 /**
  * @brief [Find the greatest value of the given array]
  * 
  * @param arr [The array to analyze]
  * @param size [Size of the array]
  * 
  * @return [The greatest value of the array]
  */
int getMax(const int* arr, size_t size);

/**
 * @brief [Sort by digit at the given position]
 * 
 * @param arr [The main array to sort]
 * @param temp [The temporary array to store elements]
 * @param count [The auxiliary array to count frequencies]
 * @param size [Size of the main array]
 * @param exp [Number to calculate the considering digit]
 */
void countingSort(int* arr, int* temp, int* count, size_t size, int exp);

/**
 * @brief [Main sort function]
 * 
 * @param arr [Pointer to the main array]
 * @param size [Size of the main array]
 */
void radixSort(int* arr, size_t size);

/***************************************************************************************************
 * CODE
 **************************************************************************************************/
int main()
{
    //Initialize array
    int arr[MAX_SIZE] = {4, 1, 9, 7, 10, 3, 5, 2, 8, 6};
    //Call the sort function
    radixSort(arr, MAX_SIZE);
    //Show the sorted array
    for (int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

int getMax(const int* arr, size_t size)
{
    int max = arr[0];
    //Go sequentially
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int* arr, int* temp, int* count, size_t size, int exp)
{
    //Copy data to the temporary array
    memmove(temp, arr, size * sizeof(int));
    //Set all value of the count array to zero
    memset(count, 0, 10 * sizeof(int));

    //Calculate frequencies
    for (int i = 0; i < 10; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    //Transform to frequencies to the true position
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    //Build the sorted array
    for (size_t i = size; i-- > 0;)
    {
        arr[count[(temp[i] / exp) % 10] - 1] = temp[i];
        count[(temp[i] / exp) % 10]--;
    }
}

void radixSort(int* arr, size_t size)
{
    //Gets the maximum value
    int max = getMax(arr, size);
    //Create a temporary array for counting sort
    int* temp = new int[size];
    //Create a auxiliary array for counting sort
    int* count = new int[10];
    //Sort digit by digit
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, temp, count, size, exp);
    }
    //Release memories
    delete[] temp;
    temp = NULL;
    delete[] count;
    count = NULL;
}