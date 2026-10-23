## run_tests.sh that checks if the data files exist and runs the program

PROGRAM=./program
DATA_FILES="credit_card.txt people.txt products.txt"
ACTUALOTP=actual_output.txt
EXPECTEDOTP=expected_output.txt

## Build from scratch
echo "Building..."
make clean > /dev/null 2>&1
if !make; then
  echo "BUILD FAILED"
  exit 1
fi

for f in $DATA_FILES; do
  if [[ i -f "$f" ]]; then
    echo "Missing data file: $f"
    exit 1
  fi
done

## Run the program and capture its output
echo "Running tests..."
$PROGRAM > "$ACTUAL" 2>$1
status=$?
cat "$ACTUAL"

if [[ $status -ne 0 ]]; then
  echo "FAIL: program exited with code $status"
  exit 1
fi

## Compare the output to what we would expect
if [[-f "$EXPECTED" ]]; then
  if diff -u "$EXPECTED" "$ACTUAL"; then
    echo "PASS: output matches $EXPECTED"
  else
    echo "FAIL: output differs from $EXPECTED"
    exit 1
  fi 
else
  echo "No $EXPECTED found, skipping comparison."
fi
