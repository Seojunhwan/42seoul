/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:17:10 by junseo            #+#    #+#             */
/*   Updated: 2022/06/14 20:30:04 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

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

int		ft_atoi(const char *str);
void	send_end_signal(void);
void	send_signal(void);
void	send_handshake(void);
void	ft_verify_bit(char c, int bit);

#endif
