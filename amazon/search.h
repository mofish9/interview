/*-----------------------------------------------------------
 * search.h
 *     Search an array of sorted numbers. 
 *     
 *     This function finds the element in the array
 *     that best fits the search criteria. It returns
 *     the match type and the index of the matching item.
 *
 * LessThan
 * --------
 *  Finds the largest item which is less than the key.
 *  It returns FoundLess if a match is found, NotFound
 *  if no match is found.
 *
 * LessThanEquals
 * --------------
 *  Finds the item which is equal to the key, or the
 *  largest item which is less than the key. Returns
 *  FoundExact if an item that exactly matches the key
 *  is found, FoundLess if a non-exact match is found
 *  and NotFound if no match is found.
 *
 * Equals
 * ------
 *  Finds an item which is equal to the key. Returns
 *  FoundExact if an item if found, NotFound otherwise.
 *
 * GreaterThanEquals
 * -----------------
 *  Finds the item which is equal to the key, or the
 *  smallest item which is greater than the key. Returns
 *  FoundExact if an item that exactly matches the key
 *  is found, FoundGreater if a non-exact match is found
 *  and NotFound if no match is found.
 *
 * GreaterThan
 * -----------
 *  Finds the smallest item which is greater than the
 *  key. Returns FoundGreater if a match if found, NotFound
 *  if no match is found.
 *
 * Before you use this function, please ensure the following
 * assumptions of the input. 
 * -----------
 *  The items are sorted.
 *  Items will be non-NULL.
 *  There are no duplicate items.
 *  n_items will be > 0.
 *
 * Author : huww06@gmail.com
 * Date   : 2013-01-12
 * 
 * Version: 1.0
 *
 *-----------------------------------------------------------
 */
#ifndef SEARCH_H
#define SEARCH_H

/*---------------------
 * support macros
 *---------------------
 */
/*
 * IsEquals(type)
 *     True iff the type is an equals enum number.
 */
#define IsEquals(type) (type == LessThanEquals ||\
                        type == Equals ||\
                        type == GreaterThanEquals)
/*
 * IsExactEquals(type)
 *     True iff the type is exactly Equals.
 */
#define IsExactEquals(type) (type == Equals)
/*
 * IsLessThan(type)
 *     True iff the type is an less than enum number.
 */
#define IsLessThan(type) (type == LessThan ||\
                          type == LessThanEquals)
/*
 * IsExactLessThan(type)
 *     True iff the type is exactly LessThan.
 */
#define IsExactLessThan(type) (type == LessThan)
/*
 * IsGreaterThan(type)
 *     True iff the type is an greater than enum number.
 */
#define IsGreaterThan(type) (type == GreaterThan ||\
                             type == GreaterThanEquals)
/*
 * IsExactGreaterThan(type)
 *     True iff the type is exactly GreaterThan.
 */
#define IsExactGreaterThan(type) (type == GreaterThan)
/*
 * AssignResult(s, a, i, b)
 *     Assign a to s and assign b to i. This is commonly 
 *     used to set return SearchResult and index. 
 */
#define AssignResult(s, a, i, b) \
            (s) = (a); \
            (i) = (b)
/*
 * NotEquals(a, b)
 *     True iff a != b.
 */
#define NotEquals(a, b) (a != b)
/*
 * Equals(a, b)
 *     True iff a == b.
 */
#define Equals(a, b) (a == b)
/*
 * LessThan(a, b)
 *     True iff a < b.
 */
#define LessThan(a, b) (a < b)
/*
 * GreaterThan(a, b)
 *     True iff a > b.
 */
#define GreaterThan(a, b) (a > b)

/*
 * Enumeration specifying the type of searches. 
 */
typedef enum SearchType {
    LessThan = 0,             /* Less than search */
    LessThanEquals = 1,       /* Less than equals search */
    Equals = 2,               /* Equals search */
    GreaterThanEquals = 3,    /* Greater than equals search */
    GreaterThan = 4           /* Greater than search */
} SearchType;

/*
 * Enumeration specifying the result of searches. 
 */
typedef enum SearchResult {
    NotFound,                 /* Not found */
    FoundExact,               /* Found a exact value */
    FoundGreater,             /* Found a non-exact match greater value */
    FoundLess                 /* Found a non-exact match less value */
} SearchResult;

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
extern SearchResult Search(const int * const items,
                        const int n_items,
                        const int ascending,
                        const int key,
                        const SearchType type,
                        int* const index);

#endif /* SEARCH_H */
