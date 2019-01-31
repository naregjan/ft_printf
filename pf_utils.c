/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:11:19 by ikourkji          #+#    #+#             */
/*   Updated: 2019/01/31 00:49:55 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_placechar(t_vars *v, char c)
{
	v->buf[v->buf_i] = c;
	v->buf_i++;
	if (v->buf_i == v->buf_len)
	{
		if (!(v->buf = ft_rememalloc(v->buf, v->buf_len, v->buf_len * 2)))
			return ;
		else
			v->buf_len *= 2;
	}
}
/*
char	*pf_itoa_base(intmax_t n, int base, int up)
{
	char	*ret;
	char	*tmp;

	ret = 0;
	tmp = 0;
	if (n < 0)
	{
		if (!(ret = ft_strnew(1)))
			return (0);
		ret[0] = '-';
		if (!(tmp = pf_uitoa_base((uintmax_t)(n * -1), base, up)))
			return (0);
		ret = ft_strjoindel(ret, tmp);
		free(tmp);
	}
	else
		ret = pf_uitoa_base((uintmax_t)(n * -1), base, up);
	return (ret);
}
*/
char	*pf_uitoa_base(uintmax_t n, int base, int up)
{
	char		*ret;
	int			len;
	uintmax_t	tmp;
	char		*b;

	tmp = n;
	len = 1;
	b = (up ? "0123456789ABCDEF" : "0123456789abcdef");
	printf("num: %jd\n", n); //printf here!
	while (tmp >= base && len++)
		tmp /= base;
	if (!(ret = ft_strnew(len)))
		return (0);
	len--;
	while (len > -1)
	{
		ret[len--] = b[n % base];
		n /= base;
	}
	return (ret);
}