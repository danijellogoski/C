// getaninteger.c - Using character-test macros to create an integer
// to cteate an integer input function

#include <stdio.h>
#include <ctype.h>

int get_int(void);

int main(int argc, char *argv[]){
	
	int x;
	x = get_int();
	
	printf("You entered %d.", x);
	
	return 0;
}

int get_int(void){
	int ch, i, sign = 1;
	
	// Skip over any leading whitespace
	
	while (isspace(ch = getchar()))
		;
	
	/* If the first character is nonnumeric, unget
	   the character and return 0. */
	
	if (ch != '-' && ch != '+' && !isdigit(ch) && ch != EOF){
		ungetc(ch, stdin);
		return 0;
	}
	
	/* If the first character is a minus sign set
	   sign accordingly */
	
	if (ch == '-')
		sign = -1;
	
	/* If the first character is a plus or minus sign,
	   get the next character */
	
	if (ch == '+' || ch == '-')
		ch = getchar();
	
	/* Read characters until a nondigit is input. Assign
	   values, multiplied by proper power of 10, to i. */
	   
	for (i = 0; isdigit(ch); ch = getchar())
		i = 10 * i + (ch - '0');
	
	// Make result negative if sign is negative
	
	i *= sign;
	
	/* If EOF was not encountered, a nondigit character
       must have been read in, so unget it. */
	   
	if (ch != EOF)
		ungetc(ch, stdin);
	
	// Return the input value
	
	return i;	
}