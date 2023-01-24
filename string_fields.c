#include "main.h"

/**
 * get_precision - a funciton that gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int num = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		num = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			num = num * 10 + (*p++ - '0');
	}
	params->precision = num;
	return (p);
}
