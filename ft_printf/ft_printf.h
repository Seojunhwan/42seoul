/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:58:41 by junseo            #+#    #+#             */
/*   Updated: 2022/04/10 18:22:40 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int					ft_decimal_printer(va_list *ap);
int					ft_unsigned_decimal_printer(va_list *ap);
void				ft_put_unnbr(unsigned int number, int fd);

int					ft_hex_printer(va_list *ap, int uppercase);
void				ft_put_hex(unsigned int number, char *format, int fd);

int					ft_pointer_printer(va_list *ap);
void				ft_put_pointer(uintptr_t ptr);

int					ft_char_printer(va_list *ap);
int					ft_str_printer(va_list *ap);

int					ft_printf(const char *format, ...);
#endif
