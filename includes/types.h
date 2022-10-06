#ifndef TYPES_H
# define TYPES_H

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*ptr;
	int		*buff;

}				t_img;

typedef struct s_fractol
{
	void		*mlx;
	char		*title;
}				t_fractol;

#endif