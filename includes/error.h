/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:18:32 by mreinald          #+#    #+#             */
/*   Updated: 2025/01/14 23:21:29 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// Error messages
# define ERR_ARGS		"There was expecting exactly 2! e.g: \
						./bin/fdf */name_file.fdf"
# define ERR_MAP		"🗺️Invalid map format"
# define ERR_MLC		"Error to malloc"
# define ERR_MLX		"MLX initialization failed! 🚫"
# define ERR_MLX_H		"MLX hooks failed! 🚫"
# define ERR_OPEN		"📂 Can't open the file. Does it even exist?"
# define ERR_READ		"📖 Trouble reading the file. \
						What's going on over there?"
# define ERR_SPLIT		"✂️ Couldn't split the line. \
						What kind of mess is this data?"
# define ERR_LINE		"📏 Error! Each line must have the same number of elements.\
						Let's fix this!"
# define ERR_EMPTY		"📂 File is empty or poorly formatted. \
						What are you feeding me?"
# define ERR_MEM		"💾 Memory allocation failed. \
						Out of memory? Free some space!"

#endif
