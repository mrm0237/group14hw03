#!/bin/bash
# run_tests.sh builds the program, checks the data files, runs it

PROGRAM=./program
DATA_FILES="credit_card.txt people.txt products.txt"
ACTUAL=actual_output.txt

## Build from scratch
echo "Building..."
make clean > /dev/null 2>&1
if ! make; then
  echo "BUILD FAILED"
  exit 1
fi

for f in $DATA_FILES; do
  if [ ! -f "$f" ]; then
    echo "Missing data file: $f"
    exit 1
  fi
done

## Run the program and capture its output
echo "Running program..."
$PROGRAM > "$ACTUAL" 2>$1
status=$?
cat "$ACTUAL"

if [ $status -ne 0 ]; then
  echo "FAIL: program exited with code $status"
  exit 1
fi
echo "PASS: program ran successfully"
