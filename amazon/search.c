/*-----------------------------------------------------------
 * search.c
 *     Search an array of sorted numbers. 
 *     
 *     This function finds the element in the array
 *     that best fits the search criteria. It returns
 *     the match type and the index of the matching item.
 *
 * Author : huww06@gmail.com
 * Date   : 2013-01-12
 * 
 * Version: 1.0
 *
 *-----------------------------------------------------------
 */
#include "search.h"

/* 
 * Search an array of sorted numbers.
 *
 * items    : an array of sorted ints, with no duplicates
 * n_items  : the size of the items array
 * ascending: non-zero if the array is sorted in ascending order
 * key      : the key to search for
 * type     : the type of match to find
 * index    : the index of the matched value
 *
 */
SearchResult
Search(const int * const items,
        const int n_items,
        const int ascending,
        const int key,
        const SearchType type,
        int* const index)
{
    SearchResult search = NotFound;
    
    int i;
    for (i = 0; i < n_items; i++) 
    {
        /* If the current element equals to the target key, we already
         * can determine the result based on ascending and type.
         */
        if (Equals(*(items + i), key))
        {
            /* If this is a equals search, match found. */
            if (IsEquals(type))
            {
                AssignResult(search, FoundExact, *index, i);
            }
            /* If this is a less than search, get the match for different order. */
            else if (IsExactLessThan(type))
            {
                if (NotEquals(ascending, 0))
                {
                    AssignResult(search, i > 0 ? FoundLess : NotFound, 
                                 *index, i - 1);
                }
                else
                {
                    AssignResult(search, i < n_items - 1 ? FoundLess : NotFound, 
                                 *index, i < n_items - 1 ? i + 1 : -1);
                }
            }
            /* If this is a greater than search, get the match for different order. */
            else if (IsExactGreaterThan(type)) 
            {
                if (NotEquals(ascending, 0))
                {                   
                    AssignResult(search, i < n_items - 1 ? FoundGreater : NotFound, 
                                 *index, i < n_items - 1 ? i + 1 : -1);
                }
                else
                {
                    AssignResult(search, i > 0 ? FoundGreater : NotFound, 
                                 *index, i > 0 ? i - 1 : -1);
                }
            }
            break;
        }
        /* The current element is greater than the target key. */
        else if (GreaterThan(*(items + i), key))
        {
            /* Note: We only need to consider the ascending order here. 
             * For ascending order list, here can be reached means that 
             * there is no exact match for the target value and thus we
             * can determine the result already. 
             * 
             * If it is a descending order list, if the current element
             * is the last one and the type is GreaterThan or 
             * GreaterThanEquals we return this, otherwise we wait
             * to find the exact match first. 
             */
            if (NotEquals(ascending, 0))
            {
                if (IsLessThan(type))
                {
                    AssignResult(search, i > 0 ? FoundLess : NotFound, 
                                 *index, i - 1);
                }
                else if (IsGreaterThan(type))
                {
                    AssignResult(search, FoundGreater, *index, i);
                }
                else
                    search = NotFound;
                break;
            }
            else 
            {
                if (Equals(i, n_items - 1) && IsGreaterThan(type))
                {
                    AssignResult(search, FoundGreater,
                                 *index, i);
                }
            }
        }
        /* The current element is less than the target key. */
        else 
        {
            /* Note: We only need to consider the descending order here.
             * For descending order list, here can be reached means that
             * there is no exact match for the target value and thus we 
             * can determine the result already. 
             *
             * If it is an ascending order list, if the current element
             * is the last one and the type is LessThan or LessThanEquals
             * we return this, otherwise we  wait to find the exact match 
             * first. 
             */
            if (Equals(ascending, 0))
            {
                if (IsGreaterThan(type))
                {
                    AssignResult(search, i > 0 ? FoundGreater : NotFound, 
                                 *index, i - 1);
                }
                else if (IsLessThan(type))
                {
                    AssignResult(search, FoundLess, *index, i);
                }
                else 
                    search = NotFound;
                break;
            }
            else 
            {
                if (Equals(i, n_items - 1) && IsLessThan(type))
                {
                    AssignResult(search, FoundLess,
                                 *index, i);
                }
            }
        }
    }

    return search;
}
