#ifndef RH_TEST_H
#define RH_TEST_H
#include "shared.h"

TEST(rh_test, simpletest) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output7.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output7.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input7.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input7.txt", MAXLINE);
    load(txt, inFile);

    rh(txt);
    show(txt);

    returnStream(outputFile, oldstdOut);

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected7.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected7.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output7.txt", "r") : outputData = fopen("../../lab2/tests/output/output7.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(rh_test, emptyfile) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output8.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output8.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input8.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input8.txt", MAXLINE);
    load(txt, inFile);

    rh(txt);
    show(txt);

    returnStream(outputFile, oldstdOut);

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected8.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected8.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output8.txt", "r") : outputData = fopen("../../lab2/tests/output/output8.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(rh_test, just_one_line) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output9.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output9.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input9.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input9.txt", MAXLINE);
    load(txt, inFile);

    rh(txt);
    show(txt);

    returnStream(outputFile, oldstdOut);

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected9.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected9.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output9.txt", "r") : outputData = fopen("../../lab2/tests/output/output9.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

#endif // RH_TEST_H
