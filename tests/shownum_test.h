#ifndef SHOWUPPER_TEST_H
#define SHOWUPPER_TEST_H
#include "shared.h"

extern "C" {
#include "common.h"
}

TEST(shownum_test, simpletest) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output1.txt", "wb") : outputFile = fopen("/tests/output/output1.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);
    
    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input1.txt", MAXLINE) : strncpy(inFile, "/tests/input/input1.txt", MAXLINE);
    load(txt, inFile);
    
    shownum(txt);
    
    returnStream(outputFile, oldstdOut);
    
    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected1.txt", "r") : expectedData = fopen("/tests/expected/expected1.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output1.txt", "r") : outputData = fopen("/tests/output/output1.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(shownum_test, emptyfile) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output2.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output2.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input2.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input2.txt", MAXLINE);
    load(txt, inFile);

    shownum(txt);

    returnStream(outputFile, oldstdOut);

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected2.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected2.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output2.txt", "r") : outputData = fopen("../../lab2/tests/output/output2.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(shownum_test, emptylines) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output3.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output3.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input3.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input3.txt", MAXLINE);
    load(txt, inFile);

    shownum(txt);

    returnStream(outputFile, oldstdOut);

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected3.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected3.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output3.txt", "r") : outputData = fopen("../../lab2/tests/output/output3.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(shownum_test, russiantext) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output4.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output4.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input4.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input4.txt", MAXLINE);
    load(txt, inFile);

    shownum(txt);

    returnStream(outputFile, oldstdOut);

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected4.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected4.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output4.txt", "r") : outputData = fopen("../../lab2/tests/output/output4.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(shownum_test, symbols) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output5.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output5.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input5.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input5.txt", MAXLINE);
    load(txt, inFile);

    shownum(txt);

    returnStream(outputFile, oldstdOut);

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected5.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected5.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output5.txt", "r") : outputData = fopen("../../lab2/tests/output/output5.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

TEST(shownum_test, first_line_removed) {
    FILE *outputFile;
    TRAVIS ? outputFile = fopen("tests/output/output6.txt", "wb") : outputFile = fopen("../../lab2/tests/output/output6.txt", "wb");
    if (outputFile == NULL) {
        printf("Cannot open file for output. ");
        FAIL();
    }
    int oldstdOut = changeStream(outputFile);

    text txt = create_text();
    char inFile[MAXLINE];
    TRAVIS ? strncpy(inFile, "tests/input/input6.txt", MAXLINE) : strncpy(inFile, "../../lab2/tests/input/input6.txt", MAXLINE);
    load(txt, inFile);

    rh(txt);
    shownum(txt);

    returnStream(outputFile, oldstdOut);

    FILE *expectedData;
    TRAVIS ? expectedData = fopen("tests/expected/expected6.txt", "r") : expectedData = fopen("../../lab2/tests/expected/expected6.txt", "r");
    FILE *outputData;
    TRAVIS ? outputData = fopen("tests/output/output6.txt", "r") : outputData = fopen("../../lab2/tests/output/output6.txt", "r");

    if (executeTest(expectedData, outputData) == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}

#endif // SHOWUPPER_TEST_H
