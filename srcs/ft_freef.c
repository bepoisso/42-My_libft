/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:16:07 by bepoisso          #+#    #+#             */
/*   Updated: 2025/03/28 14:38:40 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	free_null(void	**ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static void	free_str(char **s)
{
	free_null((void **)&s);
}

static void	check_format(char format, va_list ap)
{
	if (format == 's')
		free_str(va_arg(ap, char **));
	else if (format == 'p')
		free(va_arg(ap, void *));
	else if (format == 'd')
		free_2d(va_arg(ap, char ***));
	
}

/* 
*	ft_freef is for free multiple things in one line
	you can use like ft_printf()
	
	Args :
	str = arguments type you eante to free
		%s = string
		%p = pointer
		%d = double tab
	... = you need to put adress of your var

	Exemple :
		ft_freef("%s%d%p", &str, &tab, &ptr);

	You can add your struct with the lettre you want to use add a free_struct()
	to free it
 */
void	ft_freef(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			check_format(*(++str), ap);
		str++;
	}
	va_end(ap);
}