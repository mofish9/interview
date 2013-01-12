#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "search.h"

static void testAscending()
{
    int *items = (int *)malloc(sizeof(int) * 8);
    int i = 0;
    for (i = 0; i < 8; i++) 
        items[i] = 2 * i + 1;
    int index = -1;
    assert(Search(items, 8, 1, 7, Equals, &index) == FoundExact);
    assert(index == 3);

    index = -1;
    assert(Search(items, 8, 1, 8, Equals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 7, LessThan, &index) == FoundLess);
    assert(index == 2);

    index = -1;
    assert(Search(items, 8, 1, 8, LessThan, &index) == FoundLess);
    assert(index == 3);

    index = -1;
    assert(Search(items, 8, 1, 0, LessThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 7, LessThanEquals, &index) == FoundExact);
    assert(index == 3);

    index = -1;
    assert(Search(items, 8, 1, 8, LessThanEquals, &index) == FoundLess);
    assert(index == 3);

    index = -1;
    assert(Search(items, 8, 1, 0, LessThanEquals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 7, GreaterThan, &index) == FoundGreater);
    assert(index == 4);

    index = -1;
    assert(Search(items, 8, 1, 6, GreaterThan, &index) == FoundGreater);
    assert(index == 3);

    index = -1;
    assert(Search(items, 8, 1, 17, GreaterThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 1, 7, GreaterThanEquals, &index) == FoundExact);
    assert(index == 3);

    index = -1;
    assert(Search(items, 8, 1, 8, GreaterThanEquals, &index) == FoundGreater);
    assert(index == 4);

    index = -1;
    assert(Search(items, 8, 1, 17, GreaterThanEquals, &index) == NotFound);
    assert(index == -1);

    printf("All tests for ascending list succeeded.\n");
}

static void testDescending()
{
    int *items = (int *)malloc(sizeof(int) * 8);
    int i = 0;
    for (i = 0; i < 8; i++) 
        items[i] = 2 * (8 - i) + 1;
    int index = -1;
    assert(Search(items, 8, 0, 7, Equals, &index) == FoundExact);
    assert(index == 5);

    index = -1;
    assert(Search(items, 8, 0, 8, Equals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 7, LessThan, &index) == FoundLess);
    assert(index == 6);

    index = -1;
    assert(Search(items, 8, 0, 8, LessThan, &index) == FoundLess);
    assert(index == 5);

    index = -1;
    assert(Search(items, 8, 0, 0, LessThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 7, LessThanEquals, &index) == FoundExact);
    assert(index == 5);

    index = -1;
    assert(Search(items, 8, 0, 8, LessThanEquals, &index) == FoundLess);
    assert(index == 5);

    index = -1;
    assert(Search(items, 8, 0, 0, LessThanEquals, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 7, GreaterThan, &index) == FoundGreater);
    assert(index == 4);

    index = -1;
    assert(Search(items, 8, 0, 6, GreaterThan, &index) == FoundGreater);
    assert(index == 5);

    index = -1;
    assert(Search(items, 8, 0, 17, GreaterThan, &index) == NotFound);
    assert(index == -1);

    index = -1;
    assert(Search(items, 8, 0, 7, GreaterThanEquals, &index) == FoundExact);
    assert(index == 5);

    index = -1;
    assert(Search(items, 8, 0, 8, GreaterThanEquals, &index) == FoundGreater);
    assert(index == 4);

    index = -1;
    assert(Search(items, 8, 0, 18, GreaterThanEquals, &index) == NotFound);
    assert(index == -1);

    printf("All tests for descending list succeeded.\n");
}

int main()
{
    testAscending();    
    testDescending();
    printf("All tests succeeded.\n");
    return 0;
}

