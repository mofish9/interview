/*-----------------------------------------------------------
 * main.c
 *     Test for the Search function. 
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
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "search.h"

/* 
 * Test cases for ascending array. 
 */
static void testAscending()
{
    int *items = (int *)malloc(sizeof(int) * 8);
    int i = 0;
    for (i = 0; i < 8; i++) 
        items[i] = 2 * i + 1;
    int index = -1;
    assert(Search(items, 8, 1, -1, Equals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 17, Equals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 1, Equals, &index) == FoundExact);
    assert(index == 0);

    index = -1;
    assert(Search(items, 8, 1, 0, LessThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 1, LessThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 2, LessThan, &index) == FoundLess);
    assert(index == 0);

    index = -1;
    assert(Search(items, 8, 1, 17, LessThan, &index) == FoundLess);
    assert(index == 7);

    index = -1;
    assert(Search(items, 8, 1, 0, LessThanEquals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 1, LessThanEquals, &index) == FoundExact);
    assert(index == 0);

    index = -1;
    assert(Search(items, 8, 1, 2, LessThanEquals, &index) == FoundLess);
    assert(index == 0);

    index = -1;
    assert(Search(items, 8, 1, 17, LessThanEquals, &index) == FoundLess);
    assert(index == 7);

    index = -1;
    assert(Search(items, 8, 1, 17, GreaterThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 15, GreaterThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 2, GreaterThan, &index) == FoundGreater);
    assert(index == 1);

    index = -1;
    assert(Search(items, 8, 1, 3, GreaterThan, &index) == FoundGreater);
    assert(index == 2);

    index = -1;
    assert(Search(items, 8, 1, 0, GreaterThan, &index) == FoundGreater);
    assert(index == 0);

    index = -1;
    assert(Search(items, 8, 1, 16, GreaterThanEquals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 11, GreaterThanEquals, &index) == FoundExact);
    assert(index == 5);

    index = -1;
    assert(Search(items, 8, 1, 10, GreaterThanEquals, &index) == FoundGreater);
    assert(index == 5);

    index = -1;
    assert(Search(items, 8, 1, 0, GreaterThanEquals, &index) == FoundGreater);
    assert(index == 0);

    free(items);

    printf("All tests for ascending array succeeded.\n");
}

/* 
 * Test cases for descending array. 
 */
static void testDescending()
{
    int *items = (int *)malloc(sizeof(int) * 8);
    int i = 0;
    for (i = 0; i < 8; i++) 
        items[i] = 2 * (8 - i) + 1;
    int index = -1;
    assert(Search(items, 8, 0, 18, Equals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 1, Equals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 3, Equals, &index) == FoundExact);
    assert(index == 7);

    index = -1;
    assert(Search(items, 8, 0, 0, LessThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 3, LessThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 15, LessThan, &index) == FoundLess);
    assert(index == 2);

    index = -1;
    assert(Search(items, 8, 0, 14, LessThan, &index) == FoundLess);
    assert(index == 2);

    index = -1;
    assert(Search(items, 8, 0, 18, LessThan, &index) == FoundLess);
    assert(index == 0);

    index = -1;
    assert(Search(items, 8, 0, 0, LessThanEquals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 3, LessThanEquals, &index) == FoundExact);
    assert(index == 7);

    index = -1;
    assert(Search(items, 8, 0, 4, LessThanEquals, &index) == FoundLess);
    assert(index == 7);

    index = -1;
    assert(Search(items, 8, 0, 18, GreaterThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 17, GreaterThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 2, GreaterThan, &index) == FoundGreater);
    assert(index == 7);

    index = -1;
    assert(Search(items, 8, 0, 3, GreaterThan, &index) == FoundGreater);
    assert(index == 6);

    index = -1;
    assert(Search(items, 8, 0, 18, GreaterThanEquals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 11, GreaterThanEquals, &index) == FoundExact);
    assert(index == 3);

    index = -1;
    assert(Search(items, 8, 0, 10, GreaterThanEquals, &index) == FoundGreater);
    assert(index == 3);

    index = -1;
    assert(Search(items, 8, 0, 2, GreaterThanEquals, &index) == FoundGreater);
    assert(index == 7);

    free(items);

    printf("All tests for descending array succeeded.\n");
}

/* 
 * Main entrance of the tests. 
 */
int main()
{
    testAscending();    
    testDescending();
    printf("All tests succeeded.\n");
    return 0;
}

