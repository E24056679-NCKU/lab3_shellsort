#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionsort(int* begin, int* end)
{
    for(int* i = begin + 1 ; i != end ; ++i)
    {
        int* pos = i;
        while(pos != begin && *(pos-1) > *(pos))
        {
            swap(*(pos-1), *pos);
            --pos;
        }
    }
}

void shellsort(int* begin, int* end)
{
    int gap = (end-begin) >> 1;
    while(gap)
    {
        int* gap_ptr = begin + gap;
        for(int* i = begin ; i != gap_ptr ; ++i)
        {
            for(int* j = i + gap ; j < end ; j += gap)
            {
                int* pos = j;
                while(pos != i && *(pos-gap) > *(pos))
                {
                    swap(*(pos-gap), *pos);
                    pos -= gap;
                }
            }
        }
        gap >>= 1;
    }
}

int main()
{
    int N;
    cout << "input the size of random array : ";
    cin >> N;
    int* a = new int[N];
    int* a_begin = a;
    int* a_end   = a + N;
    for(int *i = a_begin ; i != a_end ; ++ i)
        *i = rand();
    int* b = new int[N];
    int* b_begin = b;
    int* b_end   = b + N;
    for(int i = 0 ; i < N ; ++ i)
        b[i] = a[i];
    
    clock_t start = clock();
    shellsort(a_begin, a_end);
    clock_t end = clock();
    cout << "shell sort : " << (double)(end-start) / CLOCKS_PER_SEC << endl;

    start = clock();
    insertionsort(b_begin, b_end);
    end = clock();
    cout << "insertion sort : " << (double)(end-start) / CLOCKS_PER_SEC << endl;

    return 0;
}
