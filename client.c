/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:56:23 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/14 17:06:00 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(char c, int bit_c, int pid)
{
	while (bit_c < 8)
	{
		if ((c & (1 << bit_c)) != 0)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		bit_c++;
		usleep(800);
	}
}

void	ft_check(int pid, char *msg)
{
	int	i;
	int	bit_c;

	i = 0;
	while (msg[i])
	{
		bit_c = 0;
		ft_send(msg[i], bit_c, pid);
		i++;
	}
}

void	ft_handling_signal(int i)
{
	(void)i;
	ft_printf("Message sent to the server\n");
}

int	main(int ac, char **av)
{
	pid_t	c;

	c = 0;
	if (ac != 3)
	{
		printf("Client Error\n");
		printf("\tcorrect format [%s SERVER_PID MESSAGE]\n", av[0]);
		exit(0);
	}
	c = ft_atoi(av[1]);
	signal(SIGUSR1, &ft_handling_signal);
	ft_check(c, av[2]);
	ft_send('\n', 0, c);
	ft_send('\n', 0, c);
}
