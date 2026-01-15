#define ALLOCATION_ERROR() \
    do { \
        fprintf(stderr, "Allocation error at %s:%d: ", __FILE__, __LINE__); \
        perror(NULL); \
        exit(EXIT_FAILURE); \
    } while (0)

#define DEBUG // uncomment if you don't want debug inputs

#ifdef DEBUG
#define DEBUG_PRINTF(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINTF(...) ((void)0)
#endif