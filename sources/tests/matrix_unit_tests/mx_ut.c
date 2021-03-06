#include "mx.h"
#include "macros_ut.h"

TEST_START(1, "mx_create")
{
    mx_t *a = mx_create(0, 0);
    TEST_IF(a != NULL)
}
TEST_END

TEST_START(2, "mx_create")
{
    mx_t *a = mx_create(1, 0);
    TEST_IF(a != NULL)
}
TEST_END

TEST_START(3, "mx_create")
{
    mx_t *a = mx_create(0, 1);
    TEST_IF(a != NULL)
}
TEST_END

TEST_START(4, "mx_create")
{
    mx_t *a = mx_create(1, 1);
    TEST_IF(a == NULL)
    TEST_SIZE(a, 1, 1)
    mx_destroy(a);
}
TEST_END

TEST_START(5, "mx_mp")
{
    mx_t a = {.x = 2, .y = 3};
    MX_TYPE a_arr[] = { 2.0, 6.0,
                        9.0, 4.0,
                        5.0, 0.0};
    a.arr = a_arr;

    mx_t b = {.x = 3, .y = 2};
    MX_TYPE b_arr[] = { 3.0, 4.0, 7.0,
                        1.0, 9.0, 2.0};
    b.arr = b_arr;

    mx_t out = {.x = 3, .y = 3};
    MX_TYPE out_arr[9];
    out.arr = out_arr;

    mx_mp(a, b, &out, 0);

    MX_TYPE expected_arr[] = {12.0, 62.0, 26.0,
                            31.0, 72.0, 71.0,
                            15.0, 20.0, 35.0};
    MX_CMP(out, expected_arr)
}
TEST_END

TEST_START(6, "mx_mp")
{
    mx_t a = {.x = 2, .y = 3};
    MX_TYPE a_arr[] = { 2.0, 6.0,
                        9.0, 4.0,
                        5.0, 0.0};
    a.arr = a_arr;

    mx_t b = {.x = 2, .y = 3};
    MX_TYPE b_arr[] = { 3.0, 1.0, 
                        4.0, 9.0, 
                        7.0, 2.0};
    b.arr = b_arr;

    mx_t out = {.x = 3, .y = 3};
    MX_TYPE out_arr[9];
    out.arr = out_arr;

    mx_mp(a, b, &out, B);

    MX_TYPE expected_arr[] = {12.0, 62.0, 26.0,
                            31.0, 72.0, 71.0,
                            15.0, 20.0, 35.0};
    MX_CMP(out, expected_arr)
}
TEST_END

TEST_START(7, "mx_mp")
{
    mx_t a = {.x = 4, .y = 2};
    MX_TYPE a_arr[] = { 3.0, 4.0, 6.0, 3.0,
                        1.0, 5.0, 2.0, 7.0};
    a.arr = a_arr;

    mx_t b = {.x = 3, .y = 2};
    MX_TYPE b_arr[] = { 3.0, 4.0, 5.0,
                        2.0, 0.0, 1.0};
    b.arr = b_arr;

    mx_t out = {.x = 3, .y = 4};
    MX_TYPE out_arr[12];
    out.arr = out_arr;

    mx_mp(a, b, &out, A);

    MX_TYPE expected_arr[] ={   11, 12, 16,
                                22, 16, 25,
                                22, 24, 32,
                                23, 12, 22};
    MX_CMP(out, expected_arr)
}
TEST_END

TEST_START(8, "mx_mp")
{
    mx_t a = {.x = 4, .y = 2};
    MX_TYPE a_arr[] = { 3.0, 4.0, 6.0, 3.0,
                        1.0, 5.0, 2.0, 7.0};
    a.arr = a_arr;

    mx_t b = {.x = 2, .y = 3};
    MX_TYPE b_arr[] = { 3.0, 1.0, 
                        4.0, 9.0, 
                        7.0, 2.0};
    b.arr = b_arr;

    mx_t out = {.x = 3, .y = 4};
    MX_TYPE out_arr[12];
    out.arr = out_arr;

    mx_mp(a, b, &out, BOTH);

    MX_TYPE expected_arr[] ={   10, 21, 23,
                                17, 61, 38,
                                20, 42, 46,
                                16, 75, 35};
    MX_CMP(out, expected_arr)
}
TEST_END

TEST_START(9, "mx_mp")
{
    mx_t a = {.x = 2, .y = 3};
    MX_TYPE a_arr[] = { 3, 1,
                        0, 9,
                        7, 5};
    a.arr = a_arr;

    mx_t b = {.x = 3, .y = 1};
    MX_TYPE b_arr[] = {3 , 4, 1};
    b.arr = b_arr;

    mx_t out = {.x = 1, .y = 2};
    MX_TYPE out_arr[2];
    out.arr = out_arr;

    mx_mp(a, b, &out, BOTH);

    MX_TYPE expected_arr[] ={   16,
                                44};

    MX_CMP(out, expected_arr)
}
TEST_END

TEST_START(10, "mx_hadamard")
{
    mx_t a = {.x = 3, .y = 2, .size = 3 * 2};
    MX_TYPE a_arr[] = { 3, 5, 7,
                        4, 9, 8};
    a.arr = a_arr;

    mx_t b = {.x = 3, .y = 2};
    MX_TYPE b_arr[] = { 1, 6, 3,
                        0, 2, 9};
    b.arr = b_arr;

    mx_t out = {.x = 3, .y = 2, .size = 3 * 2};
    MX_TYPE out_arr[6];
    out.arr = out_arr;

    mx_hadamard(a, b, &out);

    MX_TYPE expected_arr[] ={3, 30, 21, 0, 18, 72};

    MX_CMP(out, expected_arr)
}
TEST_END

TEST_START(11, "mx_hadamard")
{
    mx_t a = {.x = 2, .y = 2, .size = 2 * 2};
    MX_TYPE a_arr[] = { 3, 5,
                        4, 9};
    a.arr = a_arr;

    mx_t b = {.x = 2, .y = 2, .size = 2 * 2};
    MX_TYPE b_arr[] = { 1, 6,
                        9, 0};
    b.arr = b_arr;

    mx_hadamard(a, b, &a);

    MX_TYPE expected_arr[] ={3, 30, 36, 0};

    MX_CMP(a, expected_arr)
}
TEST_END

TEST_START(12, "mx_sub")
{
    mx_t a = {.x = 3, .y = 2, .size = 3 * 2};
    MX_TYPE a_arr[] = { 3, 10, 6,
                        12, 7, 5};
    a.arr = a_arr;

    mx_t b = {.x = 3, .y = 2, .size = 3 * 2};
    MX_TYPE b_arr[] = { 3, 9, 2,
                        1, 3, 4};
    b.arr = b_arr;

    mx_t out = {.x = 3, .y = 2, .size = 3 * 2};
    MX_TYPE out_arr[6];
    out.arr = out_arr;

    mx_sub(a, b, &out);

    MX_TYPE expected_arr[] ={0, 1, 4, 11, 4, 1};
    MX_CMP(out, expected_arr)
}
TEST_END

TEST_START(13, "mx_mp_num")
{
    mx_t a = {.x = 3, .y = 2, .size = 3 * 2};
    MX_TYPE a_arr[] = { 3, 10, 6, 12, 7, 5};
    a.arr = a_arr;

    mx_mp_num(&a, 3);
    MX_TYPE expected_arr[] ={9, 30, 18, 36, 21, 15};
    MX_CMP(a, expected_arr)
}
TEST_END

MX_TYPE foo(MX_TYPE a) {return (a > 4) ? 0 : a;}

TEST_START(14, "mx_hadam_lambda")
{
    MX_TYPE a_arr[4] = {0, 1, 1, 6};
    mx_t a = {.arr = a_arr, .x = 4, .y = 1, .size = 4 * 1};

    MX_TYPE b_arr[4] = {3, 4, 8, 2};
    mx_t b = {.arr = b_arr, .x = 4, .y = 1, .size = 4 * 1};

    mx_hadam_lambda(&a, b, (&foo));

    MX_TYPE expected_arr[4] = {0, 4, 0, 12};
    MX_CMP(a, expected_arr)
}
TEST_END

int mx_ut(void) 
{ 
    int (*test_ptr_arr[])(void) = { test1, test2, test3, test4, test5,
    test6 , test7, test8, test9, test10, test11, test12, test13, test14};
    const int test_size = sizeof(test_ptr_arr)/sizeof(test_ptr_arr[0]);
    int failed = 0;

    puts("matrix unit tests\n");

    for(int i = 0; i < test_size; ++i) failed += (*test_ptr_arr[i])();
    
    printf("%i of %i tests failed\n", failed, test_size);
    return failed; 
}