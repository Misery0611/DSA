//Misery
//Print all arrangements of k numbers derived from the sequence from 1 to n
#include <iostream>

bool* gUsed = NULL;
int* gResult = NULL;
int n, k;

/***********************************************************************************************************************
 *PROTOTYPE
 **********************************************************************************************************************/
/**
 * @brief      { Fill in the i-th position of the result array or print it }
 *
 * @param[int]  i     { Index number }
 */
void printArrange(int i);
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

    gUsed = new bool[n];
    gResult = new int[n];
    for (int i = 0; i < n; i++)
    {
        gUsed[i] = false;
    }
    printArrange(0);

    //Release memory
    delete[] gUsed;
    gUsed = NULL;
    delete[] gResult;
    gResult = NULL;
}

void printArrange(int i)
{
    if (i == k)
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
            printArrange(i + 1);
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