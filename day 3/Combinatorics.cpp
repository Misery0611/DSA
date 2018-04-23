//Misery
//Print all ways to choose k numbers derived from sequence from 1 to n (does not care about order)
#include <iostream>

bool* gUsed = NULL;
int* gResult = NULL;
int n, k, curMax = 0;
/***********************************************************************************************************************
 *PROTOTYPE
 **********************************************************************************************************************/
/**
 * @brief      { Fill in the i-th position of the result array or print it }
 *
 * @param[int]  i     { Index number }
 */
void printComb(int i);
/**
 * @brief      { Print the result array }
 */
void printArr();
/***********************************************************************************************************************
 *CODE
 **********************************************************************************************************************/
int main()
{
    //Gets data
    std::cin >> n >> k;

    gResult = new int[n];
    gUsed = new bool[n];
    //Initialize value
    for (int i = 0; i < n; i++)
    {
        gUsed[i] = false;
    }
    printComb(0);

    //Release memory
    delete[] gUsed;
    gUsed = NULL;
    delete gResult;
    gResult = NULL;
}

void printComb(int i)
{
    if (i >= k)
    {
        printArr();
        return;
    }

    //Only check value greater than previous value
    for (int j = curMax; j < n; j++)
    {
        if (gUsed[j] == false)
        {
            gResult[i] = j + 1;
            curMax = j + 1;
            gUsed[j] = true;
            printComb(i + 1);
            if (i > 0)
            {
                curMax = gResult[i - 1];
            }
            else
            {
                curMax = 0;
            }
            gUsed[j] = false;
        }
    }
}

void printArr()
{
    for (int i = 0; i < k; i++)
    {
        std::cout << gResult[i] << ' ';
    }
    std::cout << std::endl;
}