/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:17:10 by junseo            #+#    #+#             */
/*   Updated: 2022/06/15 13:06:44 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_request
{
	struct sigaction	handshake_action;
	struct sigaction	receive_action;
	unsigned char		*message;
	pid_t				current_client;
	int					index;
	int					is_done;
	int					bit;
}	t_request;

extern t_request	g_request;

void	receive_handler(int signo, siginfo_t *info, void *context);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

#endif
