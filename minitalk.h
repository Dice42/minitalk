/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:17:15 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/29 17:19:22 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "./libft/libft.h"

typedef struct s_byte
{
	unsigned char	bit_1:1;
	unsigned char	bit_2:1;
	unsigned char	bit_3:1;
	unsigned char	bit_4:1;
	unsigned char	bit_5:1;
	unsigned char	bit_6:1;
	unsigned char	bit_7:1;
	unsigned char	bit_8:1;
}	t_byte;

#endif
