
    AUTHORS: Aidan Hoagland
    PURPOSE OF SOFTWARE: create a program in 32-bit NASM that takes hex addresses and converts them into ascii
    HW11Hoagland.asm: submission for the NASM file for homework 11
    BUILD INSTRUCTIONS: nasm -f elf32 -g -F dwarf -o HW11Hoagland.o HW11Hoagland.asm
    TESTING METHODOLOGY: create an if-else statement to determine how to convert the first character in the hex address to ascii, then loop this statement for all hex addresses, then add a second if-else inside the loop for the second character, and print the results
    ADDITIONAL INFORMATION: compared to the expected result in blackboard, this one lacks spaces, but with the way my code was written I would have to change a lot to get that to work so I didn't

