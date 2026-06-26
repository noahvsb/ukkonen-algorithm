#define ALLOCATION_ERROR() \
    do { \
        fprintf(stderr, "Allocation error at %s:%d: ", __FILE__, __LINE__); \
        perror(NULL); \
        exit(EXIT_FAILURE); \
    } while (0)

#define DEBUG // uncomment if you don't want debug outputs

#ifdef DEBUG
#define DEBUG_PRINTF(fmt, ...) \
    printf("\n[DEBUG] " fmt __VA_OPT__(,) __VA_ARGS__)
#else
#define DEBUG_PRINTF(...) ((void)0)
#endif
