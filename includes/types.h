#ifndef TYPES_H
# define TYPES_H

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_image
{
	void	*ptr;
	int		*buff;
	int		endian;
	int		line_length;
	int		bits_per_pixel;

}				t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*window;
	t_image		*img;
	char		*title;
	int			set;
	t_complex	c;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	double		zoom;
	int			color;
	t_complex	julia;
}				t_fractol;

#endif