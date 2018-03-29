//Misery
#include <iostream>

bool *gUsed = NULL;
int n;
int *temp = NULL;

void printPermutations(int i);
void printArr();

int main()
{
    std::cin >> n;

    gUsed = new bool[n];
    temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        gUsed[i] = false;
    }

    printPermutations(0);
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
            temp[i] = j + 1;
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
        std::cout << temp[i] << ' ';
    }
    std::cout << std::endl;
}