/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:51:58 by akonstan          #+#    #+#             */
/*   Updated: 2025/07/16 14:51:59 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int	g_server_connected = 0;

//We will be signaling bits to the server using the SIGUSR1 and SIGUSR2 signals
//and it should decode bit by bit to create the chars and print them
void	ft_send_char(pid_t server_pid, unsigned char c)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		if ((c >> bits) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(80);
		bits--;
	}
}

//Function that sends the characters one by one
void	ft_send_message(pid_t server_pid, char *message)
{
	while (*message)
	{
		ft_send_char(server_pid, (unsigned char)(*message));
		message++;
	}
	ft_printf("MESSAGE SENT\n");
	ft_send_char(server_pid, '\0');
}

//The sigaction handler that will be called every time a signal is received
//Used to check connection to server and get confirmation that the message 
//has been fully received from the server
void	ft_receive_handler(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGUSR1 && g_server_connected == 0)
	{
		ft_printf("CONNECTED TO SERVER\n");
		g_server_connected = 1;
		return ;
	}
	if (signal == SIGUSR1 && info != NULL && context != NULL
		&& g_server_connected == 1)
	{
		ft_printf("SERVER RECEIVED YOUR MESSAGE\n");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	receive;
	pid_t				server_pid;
	char				*message;

	if (argc != 3)
	{
		ft_printf("INVALID ARGUMENTS\n");
		return (-1);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);
	message = argv[2];
	sigemptyset(&receive.sa_mask);
	receive.sa_sigaction = ft_receive_handler;
	receive.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &receive, NULL);
	kill(server_pid, SIGUSR1);
	usleep(100);
	if (g_server_connected == 0)
	{
		ft_printf("WRONG SEVRER PID\n");
		exit (-1);
	}
	ft_send_message(server_pid, message);
	while (1)
		pause();
}
