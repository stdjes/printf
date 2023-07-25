#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - Struct containing flags to "turn on"
 * when a flag specifier is passed to _printf().
 * @plus: Flag for the '+' character.
 * @space: Flag for the ' ' (space) character.
 * @hash: Flag for the '#' character.
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - Struct to choose the right function depending
 *                        on the format specifier passed to _printf().
 * @c: Format specifier character.
 * @f: Pointer to the correct printing function.
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} pr_handler;

/* _printf.c */
int _printf(const char *format, ...);

/* _putchar.c */
int _putchar(char c);

/* _puts.c */
int _puts(char *str);

/* set_print.c */
int (*set_print(char s))(va_list, flags_t *);

/* call_flag.c */
int call_flag(char s, flags_t *f);

/* print_str.c */
int print_str(va_list l, flags_t *f);

/* print_char.c */
int print_char(va_list l, flags_t *f);

/* print_digits.c */
int print_digits(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* print_hex.c */
int print_hex(va_list l, flags_t *f);

/* print_HEX_.c */
int print_HEX(va_list l, flags_t *f);

/* print_bin.c */
int print_bin(va_list l, flags_t *f);

/* print_oct.c */
int print_oct(va_list l, flags_t *f);

/* convert.c */
char *convert(unsigned long int num, int base, int lowercase);

/* encode_rot13.c */
int encode_rot13(va_list l, flags_t *f);

/* print_rev.c */
int print_rev(va_list l, flags_t *f);

/* print_non_printable.c */
int print_non_printable(va_list l, flags_t *f);

/* print_addr.c */
int print_addr(va_list l, flags_t *f);

/* print_percent.c */
int print_percent(va_list l, flags_t *f);

#endif /* MAIN_H */
