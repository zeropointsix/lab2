#ifndef SHOWUPPER_TEST_H
#define SHOWUPPER_TEST_H
#include "shared.h"

extern "C" {
#include "common.h"
}


TEST(shownum_test, emptyfile) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output1.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output1.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output");
        FAIL();
    }
    else {
        fclose(outputFile);
        SUCCEED();
    }
}

#endif // SHOWUPPER_TEST_H
