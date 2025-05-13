# 🧬 DNA Sequence Matcher

### Description:
This C program reads two DNA sequence files and finds the longest common DNA subsequence shared between them. It's designed to work with simple .dna text files that contain DNA data consisting of the characters A, C, G, and T.

📁 Sample DNA files (e.g., sample1.dna, sample2.dna, sample3.dna, sample4.dna) are located in the same folder and can be used for testing.

## How It Works:
The user provides two DNA files as command-line arguments.
Each file is read character by character, ignoring anything that is not a valid DNA base.
The program compares the two sequences to find the longest shared subsequence of bases.
It prints the longest common subsequence to the terminal.

## How to Compile and Run
gcc -o dna dna.c
./dna dnafile1.dna dnafile2.dna

### Example:
./dna sample1.dna sample2.dna

Input
Two files with DNA sequences.
Each file may contain other characters or formatting (e.g., newlines) — only A, C, G, T are considered valid.

Output
The longest sequence of consecutive DNA bases that appears in both files in the same order.

### Notes
The program uses a custom function (Same) to scan the two sequences for matching substrings by comparing one sequence against all shifted versions of the other.

The matching is case-sensitive (A, not a).
Non-DNA characters are ignored.
The maximum matching substring is stored dynamically in memory.
