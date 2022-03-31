/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:35:16 by junseo            #+#    #+#             */
/*   Updated: 2022/03/31 20:49:18 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_printer(va_list *ap)
{
	ft_putchar_fd(va_arg(*ap, int), 1);
	return (1);
}

int	ft_str_printer(va_list *ap)
{
	int		len;
	char	*str;

	len = 0;
	str = (char *)va_arg(*ap, char *);
	if (str == NULL)
	{
		ft_putchar_fd("(null)", 1);
		len = 6;5
	}
	else
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	return (len);
}

// ----------------------------------------CHAR & STR ----------------------------------------------------


int ft_decimal_printer(va_list *ap)
{
	int number;
	int	len;

	number = va_arg(*ap, int);
	ft_putnbr_fd(number, 1);
	len = 0;
	if (number == 0)
		ret += 1;
	else if (number < 0)
	{
		number *= -1;
		len += 1;
	}
	while (number)
	{
		number /= 10;
		len += 1;
	}
	return (len)
}

int	ft_unsigned_decimal_printer(va_list *ap)
{
	unsigned int number;
	int	len;

	number = (unsigned int)va_arg(*ap, int);
	if (number == 0)
		len = write(1, "0", 1);
	else
		ft_put_unnbr(number, 1);
	len = 0;
	if (number == 0)
		ret += 1;
	while (number)
	{
		number /= 10;
		len += 1;
	}
	return (len)
}

void	ft_put_unnbr(unsigned int number, int fd)
{
	if (number >= 10)
	{
		ft_put_unnbr(number / 10, fd)
		ft_putchar_fd((number % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd(number + '0', fd);
	}
}


// ----------------------------------------- INT, UNSIGNED INT ------------------------------------------




int	ft_flag_checker(const char *format, va_list *ap)
{
	int	len;

	if (*format == 'c')
		len = ft_char_printer(&ap);
	if (*format == 's')
		len = ft_str_printer(&ap);
	if (*format == 'p')
		ft_putstr_fd(va_arg(ap, char *), 0);
	if (*format == 'd' || *format == 'i')
		len = ft_decimal_printer(&ap);
	if (*format == 'u')
		len = ft_unsigned_decimal_printer(&ap);
	if (*format == 'x')
		ft_putnbr_fd(va_arg(ap, int), 0);
	if (*format == 'X')
		ft_putnbr_fd(va_arg(ap, int), 0);
	if (*format == '%')
	{
		ft_putchar_fd("%", 0);
		len = 1;
	}
	else 
		len = 0;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			len += ft_flag_checker(format, &ap);
		}
		else
			len = write(0, *format, 1);
		format++;
	}
	va_end(ap);
	return (len);
}

/* 
	* flags
		c, d, i = va_arg(ap, int); 0 ~ 21억
		u, x, X = va_arg(ap, unsigned int); 0 ~ 42억
		s, p = va_arg(ap, void *); 0 ~ 엄청 큰 값

		c 단일 문자
		s 문자열
		p void * 형식의 포인터 인자 16진수로 출력
		d 10진수 숫자 출력
		i 10진수 정수 출력
		u 부호 없는 10진수 숫자 출력
		x 소문자를 사용하여 숫자를 16진수로 출력
		X 대문자를 사용하여 숫자를 16진수로 출력
		% 퍼센트 기호 출력
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


#include <stdio.h>
int	main(void)
{
	char *str = "123456789";
	char *str_ptr;
	printf("%     % %    d%    d", 123, 345);

	return (0);
}