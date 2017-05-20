#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <algorithm>

template<typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end)
{
    for(RandomAccessIterator i = begin+1 ; i != end ; ++i)
    {
        RandomAccessIterator pos = i;
        while(pos != begin && *(pos) < *(pos-1) )
        {
            std::swap(*(pos-1), *pos);
            --pos;
        }
    }
}

template<typename RandomAccessIterator, typename StrictWeakOrdering>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end, StrictWeakOrdering comp)
{
    for(RandomAccessIterator i = begin+1 ; i != end ; ++i)
    {
        RandomAccessIterator pos = i;
        while(pos != begin && comp(*(pos) , *(pos-1)) )
        {
            std::swap(*(pos-1), *pos);
            --pos;
        }
    }
}

template<typename RandomAccessIterator, typename StrictWeakOrdering>
void shell_sort(RandomAccessIterator begin, RandomAccessIterator end, StrictWeakOrdering comp)
{
    for(int gap = (end-begin)>>1 ; gap ; gap >>= 1)
    {
        RandomAccessIterator gap_ptr = begin + gap;
        for(RandomAccessIterator i = begin ; i != gap_ptr ; ++i)
        {
            for(RandomAccessIterator j = i + gap ; j < end ; j += gap)
            {
                RandomAccessIterator pos = j;
                while(pos != i && comp(*(pos) , *(pos-gap)) )
                {
                    std::swap(*(pos-gap), *pos);
                    pos -= gap;
                }
            }
        }
    }
}

template<typename RandomAccessIterator>
void shell_sort(RandomAccessIterator begin, RandomAccessIterator end)
{
    for(int gap = (end-begin)>>1 ; gap ; gap >>= 1)
    {
        RandomAccessIterator gap_ptr = begin + gap;
        for(RandomAccessIterator i = begin ; i != gap_ptr ; ++i)
        {
            for(RandomAccessIterator j = i + gap ; j < end ; j += gap)
            {
                RandomAccessIterator pos = j;
                while(pos != i && *(pos) < *(pos-gap) )
                {
                    std::swap(*(pos-gap), *pos);
                    pos -= gap;
                }
            }
        }
    }
}

#endif
