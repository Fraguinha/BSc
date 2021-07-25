#!/bin/bash
# This is where id put a brief explanation of the script for the future
# if i had the patience to do that

# Variables

SOURCE_CODE=c.ml

FOLDER_TEST=examples
FOLDER_SOLUTIONS=solutions
FOLDER_RESULTS=test_results

FILE_RESULT=result

# Script

if [ -d $FOLDER_RESULTS ]; then
    rm -r $FOLDER_RESULTS
fi
mkdir $FOLDER_RESULTS

NUM_TESTS=$(ls $FOLDER_TEST | wc -l)

for i in $(seq 1 $NUM_TESTS); do
    FILE=$(ls $FOLDER_TEST | head -n $i | tail -n -1)
    OUTPUT=$(ls $FOLDER_SOLUTIONS | head -n $i | tail -n -1)
    RESULT="$FOLDER_RESULTS/$FILE_RESULT$i.txt"
    ocaml $SOURCE_CODE < "$FOLDER_TEST/$FILE" > $RESULT
    diff -q "$FOLDER_SOLUTIONS/$OUTPUT" $RESULT > /dev/null
    CHECK=$?
    if [ $CHECK -eq 0 ]; then
        echo "$FILE: PASSED"
    else
        echo "$FILE: FAILED"
    fi
done
