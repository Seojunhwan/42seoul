/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:17:10 by junseo            #+#    #+#             */
/*   Updated: 2022/06/14 17:31:35 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_request
{
	struct sigaction	handshake_action;
	struct sigaction	receive_action;
	pid_t				server_pid;
	char				*message;
}	t_request;

extern t_request	g_request;

size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

#endif
