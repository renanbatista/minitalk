/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:20:24 by r-afonso          #+#    #+#             */
/*   Updated: 2023/10/13 16:47:42 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int		g_runtime = 0;

static void	handle_sign(int sig)
{
	g_runtime = 0;
}

static void	handle_bits(int bits, char *msg, char **argv, int index)
{
	while (1)
	{
		if (g_runtime == 0)
		{
			bits--;
			if (msg[index] >> bits & 1)
				kill(ft_atoi(argv[1]), SIGUSR2);
			else
				kill(ft_atoi(argv[1]), SIGUSR1);
			g_runtime = 1;
			if (!bits)
				break ;
		}
	}
}

int	main(int argc, char **argv)
{
	int		index;
	int		bits;
	char	*msg;

	g_runtime = 0;
	msg = ft_strjoin(argv[2], "\n");
	index = -1;
	if (argc != 3)
		return (ft_printf("ERROR: Incorrect format, please try \n ./client \
	pid message\n"));
	signal(SIGUSR1, handle_sign);
	ft_printf("Message to send: %s\n", msg);
	while (++index, msg[index])
	{
		bits = 8;
		handle_bits(bits, msg, argv, index);
	}
	free(msg);
}
