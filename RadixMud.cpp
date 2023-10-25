#include <iostream>
#include <vector>
#include <bitset> // For binary representation

int findMax(std::vector<int> &arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(std::vector<int> &arr, int exp)
{
    const int n = arr.size();
    std::vector<int> output(n);
    int count[2] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(arr[i] >> exp) & 1]++;
    }

    for (int i = 1; i < 2; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] >> exp) & 1] - 1] = arr[i];
        count[(arr[i] >> exp) & 1]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void binaryRadixSort(std::vector<int> &arr)
{
    int max = findMax(arr);

    for (int exp = 0; (max >> exp) > 0; exp++)
    {
        countingSort(arr, exp);

        // Print the current pass in both binary and decimal
        std::cout << "Pass " << exp + 1 << " (Binary): ";
        for (int num : arr)
        {
            std::cout << std::bitset<32>(num) << " ";
        }
        std::cout << "\nPass " << exp + 1 << " (Decimal): ";
        for (int num : arr)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array (Binary): ";
    for (int num : arr)
    {
        std::cout << std::bitset<32>(num) << " ";
    }
    std::cout << "\nOriginal array (Decimal): ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    binaryRadixSort(arr);

    std::cout << "Sorted array (Binary): ";
    for (int num : arr)
    {
        std::cout << std::bitset<32>(num) << " ";
    }
    std::cout << "\nSorted array (Decimal): ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
