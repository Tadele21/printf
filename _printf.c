#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int result = 0;
	va_list var;
	char *p, *begin;
	params_t params = PARAMS_INIT;

	va_start(var, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, var);
		if (*p != '%')
		{
			result += _putchar(*p);
			continue;
		}
		begin = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, var);
		p = get_precision(p, &params, var);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			result += print_from_to(begin, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			result += get_print_func(p, var, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(var);
	return (result);
}
