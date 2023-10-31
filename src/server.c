/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:18:39 by aeryilma          #+#    #+#             */
/*   Updated: 2023/10/10 23:35:20 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

unsigned char	g_size_msg = 0;

static void	handle_sign(int sig, siginfo_t *si, void *error)
{
	static int	bit = 0;

	usleep(500);
	if (bit == 0)
		g_size_msg = 0;
	g_size_msg = g_size_msg << 1;
	if (sig == SIGUSR2)
		g_size_msg += 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", g_size_msg);
		bit = 0;
		error = "ERROR";
	}
	kill(si->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	pid = getpid();
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handle_sign;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_printf("pid : %d\n", pid);
	while (1)
		;
}
