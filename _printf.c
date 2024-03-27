#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - function that produce output according to a format 
 * @format: character string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	va_start(args, format);
	while (*format != '\0') 
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			if (*format == 'd' || * format == 'i')
			{ int num = va_arg(args, int);
				count += printf("%d", num);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				count += printf("%s", str);
			}
			else if (*format == 'c')
			{
				char ch = va_arg(args, int);
				putchar(ch);
				count++;
			}
			else if (*format == 'u')
			{
				unsigned int num = va_arg(args, unsigned int);
				count += printf("%u", num);
			}
			else if (*format == 'p')
			{
				void *ptr = va_arg(args, void *);
				count += printf("%p", ptr);
			}
			else if (*format == 'o')
			{
				unsigned int num = va_arg(args, unsigned int);
				count += printf("%o", num);
			}
			else if (*format == 'x')
			{
				unsigned int num = va_arg(args, unsigned int);
				count += printf("%x", num);
			}
			else if (*format == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);
				count += printf("%X", num);
			}
			else
			{
				putchar(*format);
				count += 1;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return count;
}
