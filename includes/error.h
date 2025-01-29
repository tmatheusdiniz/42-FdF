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
# define ERR_ARGS		"🚫 Use just 2 arguments! e.g: ./bin/fdf */name_file.fdf"
# define ERR_MAP		"🗺️  Invalid ending for map name. Use : name_file.fdf"
# define ERR_MLC		"💾 Memory allocation failed."
# define ERR_MLX		"🚫 MLX initialization failed!"
# define ERR_MLX_H		"🚫 MLX hooks failed!"
# define ERR_OPEN		"📂 Can't open the file. Does it even exist?"
# define ERR_READ		"📖 Trouble reading the file."
# define ERR_SPLIT		"✂️  Couldn't split the line."
# define ERR_LINE		"📏 Each line must have the same number of elements!"

#endif
