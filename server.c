/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:23:37 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/14 16:28:23 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signaction, siginfo_t *info, void *context)
{
	static int	bit_c = 0;
	static int	value = 0;

	(void)context;
	if (signaction == SIGUSR1)
		value += 1 << bit_c;
	bit_c++;
	if (bit_c == 8)
	{
		write (1, &value, 1);
		if (value == '\0')
			kill(info->si_pid, SIGUSR1);
		bit_c = 0;
		value = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	ft_printf("Starting server...\n");
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	act.sa_sigaction = &signal_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigemptyset(&act.sa_mask);
	while (1)
		pause();
}
