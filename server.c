/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:28:36 by joklein           #+#    #+#             */
/*   Updated: 2024/11/20 11:50:28 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bits_to_char(int sig_bit)
{
	int			cha;
	static int	bit_count;

	if (sig_bit == SIGUSR1)
		cha = (cha << 1) | 0;
	else if (sig_bit == SIGUSR2)
		cha = (cha << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (write(1, &cha, 1) == -1)
			exit(1);
		cha = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, bits_to_char);
	signal(SIGUSR2, bits_to_char);
	if (ft_printf("Server started. PID: %d\n", getpid()) == -1)
		exit(1);
	while (1)
		pause();
	return (0);
}
