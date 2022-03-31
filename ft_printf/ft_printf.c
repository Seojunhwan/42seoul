/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:35:16 by junseo            #+#    #+#             */
/*   Updated: 2022/03/19 20:59:26 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
	ft_printf("%     % %    d%    d", 123, 345);
	printf("%     % %    d%    d", 123, 345);
*/



void	ft_print_value(const char *format, va_list ap)
{
	if (*format == 'c')
		ft_putchar_fd(va_arg(ap, int), 0);
	if (*format == 's')
		ft_putstr_fd(va_arg(ap, char *), 0);
	if (*format == 'd')
		ft_putnbr_fd(va_arg(ap, int), 0);
	if (*format == '%')
		ft_putstr_fd("%", 0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*format_prt;

	va_start(ap, format);
	format_prt = format;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == ' ')
				ft_putchar_fd(' ', 0);
			while (*format == ' ')
				format++;
			ft_print_value(format, ap);
		}
		else
			ft_putchar_fd(*format, 0);
		format++;
	}
	va_end(ap);
	return (1);
}


int	main(void)
{
	char *str = "123456789";
	char *str_ptr;

	str_ptr = str;
	str++;
	str++;
	str++;
	str++;
	str++;
	printf("%s\n",str);
	printf("%s\n",str_ptr);
	printf("%s", str - (str - str_ptr));


	// ft_printf("%% adsfasdfasf");
	// ft_printf("\n");
	// printf("%% adsfasdfasf");
	// ft_printf("1%     % %    d%    d", 123, 345);
	// printf("1%     % %    d%    d", 123, 345);
	// ft_printf("\n");
	// ft_printf("\n this is new result\n");
	// ft_printf("%     % %    d%    d", 123, 345);
	// ft_printf("\n");
	// printf("%     % %    d%    d", 123, 345);

	return (0);
}

/* 
	! return
		success : 출력한 바이트 수 리턴
		fail : -1 리턴
	
	* logic
		1. 주어진 포멧을 while 문을 통해 끝이 나올 때까지 돌린다.
		2. 일반적인 글자면 출력, % 발견 시 다음 문자열을 확인한다.
			a. 해당 문자가 포멧 리스트에 있을 시 가변인자 리스트까지 검증 후 해당 값 출력한다.
			b. 해당 문자가 포멧 리스트에 없을 시 문제 발생한 것
			c. 해당 문자가 % 라면 % 그대로 출력
			d. 해당 문자가 공백이라면 초기 1회만
	
	


*/
