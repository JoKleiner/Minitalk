/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:28:36 by joklein           #+#    #+#             */
/*   Updated: 2024/11/20 10:09:42 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_count;

void	handler(int signum)
{
	int	cha;

	if (signum == SIGUSR1)
		cha = (cha << 1) | 0;
	else if (signum == SIGUSR2)
		cha = (cha << 1) | 1;
	g_count++;
	if (g_count == 8)
	{
		write(1, &cha, 1);
		cha = 0;
		g_count = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("Server started. PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

// signal		1
// sigemptyset
// sigaddset
// sigaction
// kill			1
// getpid		1
// pause		1
// sleep
// usleep		1
// exit