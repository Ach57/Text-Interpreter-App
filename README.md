Sorting Application in C
This C program (ssort) reads words from an input file, sorts them based on specified criteria, and optionally skips certain words.

Usage
The application takes the following command line arguments:
ssort <inputfile> <n> <wtype> <sorttype> [<skipword1> <skipword2> <skipword3> ...]
Arguments:
<inputfile>: Specifies the input file containing words to be sorted.
<n>: Specifies the number of words to read into the array. Must be a valid integer.
<wtype>: Specifies the type of words to process:
ALPHA: English words composed of [a-z] and [A-Z] only.
ALPHANUM: Words composed of alphanumeric characters.
ALL: All words separated by various whitespace characters and commas.
<sorttype> (Optional): Specifies the sorting order of words:
ASC: Sort words in ascending order (default if omitted).
DESC: Sort words in descending order.
<skipword1> <skipword2> ...: Optional list of words to skip during processing.

Functionality:
Input Validation:

Validates and reads command line arguments.
Checks for mandatory parameters <n> and <wtype>.
Handles errors and displays appropriate error messages if parameters are missing or invalid.
Word Reading and Processing:

Reads words from <inputfile> into an array based on specified <n>.
Filters words based on <wtype> criteria (ALPHA, ALPHANUM, ALL).
Sorting:

Sorts the array of words based on <sorttype> (ASC or DESC).
Skip Words:

Skips specified <skipword> from processing if found in the input file.
Output:

Prints the sorted array of words to the standard output (stdout).
Error Handling
Terminates with error code 1 if <n> is missing or invalid.
Terminates with error code 2 if <wtype> is missing.
Adjust the specifics of file handling and implementation details according to your actual C program structure and requirements. This README provides a structured overview to help users understand how to use and interact with your sorting application.
