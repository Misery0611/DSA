//Misery
//Print all permutations of sequence from 1 to n (a number user enter)
#include <iostream>

bool *gUsed = NULL;
int n;
int *gResult = NULL;
/***********************************************************************************************************************
 *PROTOTYPE
 *
 **********************************************************************************************************************/
/**
 * {void} printPermutations(int i)
 * @brief      { Fill in the given index or print result array }
 *
 * @param[int]  i     { Index number }
 */
void printPermutations(int i);
/**
 * @brief      { Print result array }
 */
void printArr();
/***********************************************************************************************************************
 *CODE
 **********************************************************************************************************************/
int main()
{
    //Gets data
    std::cin >> n;

    gUsed = new bool[n];
    gResult = new int[n];
    //Initialize value
    for (int i = 0; i < n; i++)
    {
        gUsed[i] = false;
    }
    printPermutations(0);

    //Release memory
    delete[] gUsed;
    gUsed = NULL;
    delete[] gResult;
    gResult = NULL;
}

void printPermutations(int i)
{
    if (i >= n)
    {
        printArr();
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (gUsed[j] == false)
        {
            gResult[i] = j + 1;
            gUsed[j] = true;
            printPermutations(i + 1);
            gUsed[j] = false;
        }
    }
}

void printArr()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << gResult[i] << ' ';
    }
    std::cout << std::endl;
}