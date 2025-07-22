/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:52:08 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/16 14:52:08 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int	g_client_connected = 0;

//Called at the end of the message to signal the client to shut down
void	ft_kill_client(pid_t client_pid)
{
	write(1, "\n", 1);
	kill(client_pid, SIGUSR1);
	g_client_connected = 0;
}

//Will act when server receives signal and decode the characters
//First SIGUSR1 received will be used to signal the client that it
//has connected to the right server. Rest of the signals is for interpreting
//the message
void	ft_advanced_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit_count;

	if (signal == SIGUSR1 && g_client_connected == 0)
	{
		kill(info->si_pid, SIGUSR1);
		g_client_connected = 1;
		return ;
	}
	if (signal == SIGUSR1)
		c = (c << 1) + 1;
	else
		c = c << 1;
	bit_count++;
	if (bit_count == 8 && context != NULL)
	{
		if (c == '\0')
			ft_kill_client(info->si_pid);
		else
			write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sigbit;

	sigemptyset(&sigbit.sa_mask);
	sigbit.sa_sigaction = ft_advanced_handler;
	sigbit.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sigbit, NULL);
	sigaction(SIGUSR2, &sigbit, NULL);
	while (1)
		;
}
