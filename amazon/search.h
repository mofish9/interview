#ifndef SEARCH_H
#define SEARCH_H

typedef enum SearchType {
    LessThan = 0,
    LessThanEquals = 1,
    Equals = 2,
    GreaterThanEquals = 3,
    GreaterThan = 4
} SearchType;

typedef enum SearchResult {
    NotFound,
    FoundExact,
    FoundGreater,
    FoundLess
} SearchResult;

extern SearchResult Search(const int * const items,
                        const int n_items,
                        const int ascending,
                        const int key,
                        const SearchType type,
                        int* const index);

#endif /* SEARCH_H */
