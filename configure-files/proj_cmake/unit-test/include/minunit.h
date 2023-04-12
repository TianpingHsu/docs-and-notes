#ifndef __MINUNIT_H__
#define __MINUNIT_H__

/*
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
if (message) return message; } while (0)
extern int tests_run;
*/

#define RUN_TEST(test) do { \
    printf("%s -- %s -- %s -- %s:%d\n", test() ? "pass" : "\033[31mFAIL\033[0m", #test, __func__, __FILE__, __LINE__); \
} while (0)


#endif
