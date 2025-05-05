Prime Square Mirror Sum

Description:
This program calculates the sum of all prime square numbers within a given range of natural numbers, where the mirrored version of the square is also a perfect square with a prime square root.

👉 For example: running ./mirror 1 1000 will find all such numbers between 1 and 1000 and return their sum.

Program Logic:
The user provides two numbers (low and high) as command-line arguments to define the range.

The program finds the square of every prime number within that range.

For each square:
It skips palindromes (numbers that are the same reversed).
It reverses the digits (mirrors it) and checks:
If the mirrored number is a perfect square.
If the square root of that number is also a prime.
If all conditions are met, the square is added to the final sum.

⚙️ How to Compile and Run:
gcc -o mirror mirror.c -lm
./mirror <low> <high>
Example:

./mirror 1 1000

low: lower bound (≥ 1)

high: upper bound (≤ 1,000,000,000,000,000)

The program checks:
That low < high
That both values are within valid limits

📤 Output
The sum of all valid prime square numbers that meet the mirror conditions.

