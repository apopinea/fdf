/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fdf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:19:12 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/30 10:19:15 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIB_FDF_H
# define __LIB_FDF_H
# define MULT_X 20
# define MULT_Y 20
# define MULT_Z 5
# define MAX_WIN 1350
# define MENU_T_L 410
# define MENU_T_H 600
# define MENU_L 340
# define MENU_H 610

# define COLOR_M_T 0x002F2FB6
# define COLOR_M_F 0x00A5A8BC
# define COLOR_M_F_2 0x00F6E497
# define COLOR_B 0
# define COLOR_RED 0x00B9121B
# define COLOR_GREEN 0x00357B00

# define STR_ROT "Rotation :"
# define STR_ROT_GRAD "+-"
# define STR_ROT_X "theta      :  flêche haut, bas"
# define STR_ROT_Y "phi        :  flêche gauche, droite"
# define STR_ROT_Z "psi        :  Q, E"
# define STR_ROT_T "type rot   :  %, switch Euler, Cardan"
# define KEY_ROT_ZP 14
# define KEY_ROT_ZN 12
# define KEY_ROT_XP 126
# define KEY_ROT_XN 125
# define KEY_ROT_YP 124
# define KEY_ROT_YN 123
# define KEY_ROT_TYPE 23

# define STR_TRANS "Translation :"
# define STR_TRANS_H "horizontal :  A, D"
# define STR_TRANS_V "vertical   :  W, S"
# define KEY_TRANS_DROITE 2
# define KEY_TRANS_GAUCHE 0
# define KEY_TRANS_HAUT 13
# define KEY_TRANS_BAS 1

# define STR_MULT "Multiplicateur distance :"
# define STR_MULT_X "sur x      :  4, 1"
# define STR_MULT_Y "sur y      :  5, 2"
# define STR_MULT_Z "sur z      :  6, 3"
# define STR_MULT_G "global     :  +, -"
# define KEY_X_MULT_P 86
# define KEY_X_MULT_N 83
# define KEY_Y_MULT_P 87
# define KEY_Y_MULT_N 84
# define KEY_Z_MULT_P 88
# define KEY_Z_MULT_N 85
# define KEY_XYZ_MULT_P 69
# define KEY_XYZ_MULT_N 78

# define STR_OUTIL "Outil :"
# define STR_TRANSP "transparence  :  #, active, desctive"
# define STR_CENTRE "type centrage :  $, centre map ou image"
# define STR_ESC "quiter        :  ecs"
# define STR_LZOOM "deformation   :  !, @ perspective"
# define KEY_ESC 53
# define KEY_LZOOM_P 18
# define KEY_LZOOM_N 19
# define KEY_TRAN 20
# define KEY_CENTRE 21
# define KEY_A_MENU_T 22
# define KEY_A_MENU 26

# define STR_CAM "Deplacement cam:"
# define STR_CAMX "sur x      :  I, K"
# define STR_CAMY "sur y      :  J, L"
# define STR_CAMZ "sur z      :  U, O"
# define T1 34
# define T2 40
# define T3 38
# define T4 37
# define T5 32
# define T6 31

# define STR_ROT2 "Rotation en (rad):"
# define T_ROT_X "theta      ="
# define T_ROT_Y "phi        ="
# define T_ROT_Z "psi        ="
# define T_ROT_T "type rot   :"
# define T_TRANH "horizontal :"
# define T_TRANV "vertical   :"
# define T_MULTX "sur X      :"
# define T_MULTY "sur Y      :"
# define T_MULTZ "sur Z      :"
# define T_CAM_X "selon x    :"
# define T_CAM_Y "selon y    :"
# define T_CAM_Z "selon z    :"
# define T_TRANSP "opacite    :"
# define T_CENTRE "centrage   :"
# define T_LZOOM "deformation:"
# define T_RE_INIT "Reinitiallise :"

typedef struct		s_pixel
{
	int				x;
	int				y;
	int				color;
}					t_pixel;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_point;

typedef struct		s_losange
{
	int				**losa;
	int				z;
	int				color;
}					t_losange;

typedef struct		s_menu_t
{
	void			*mlx;
	void			*win;
	int				win_h;
	int				win_l;
	void			*img;
	int				*pixel_img;
	int				bpp;
	int				s_line;
	int				ed;
}					t_menu_t;

typedef struct		s_menu
{
	void			*mlx;
	void			*win;
	int				win_h;
	int				win_l;
	void			*img;
	int				*pixel_img;
	int				bpp;
	int				s_line;
	int				ed;
	void			*img2;
	int				*pixel_img2;
	int				bpp2;
	int				s_line2;
	int				ed2;
	void			*img3;
	int				*pixel_img3;
	int				bpp3;
	int				s_line3;
	int				ed3;
	void			*img4;
	int				*pixel_img4;
	int				bpp4;
	int				s_line4;
	int				ed4;
	void			*img5;
	int				*pixel_img5;
	int				bpp5;
	int				s_line5;
	int				ed5;
	void			*tab;
}					t_menu;

/*
**	mlx			:	pointeur sur init_mlx;
**	win			:	pointeur sur fenêtre;
**	win_h		:	hauteur fenetre;
**	win_l		:	longeur fenetre;
**	ecran 		:	map en pixel X, Y, color;
**	grid		:	map en x, y, z, color;
**	l 			:	longeur grid;
**	h 			:	hauteur grid;
** 	extrem		:	z min et max; pour taille fenetre
**	img 		: 	pointeur sur image;
**	pixel_img 	:	pointeur sur chaine image;
**	bpp			:	bit par pixel;
**	s_line		:	bit pour une ligne;
**	ed 			:	taille variable couleur pixel;
**	col 		:	tableau[nb_col][2] couleur z;
**	p_col 		:	tableau[nbz][2] pourcentage de la droite, couleur;
**	col_spe		:	si couleur specifié;
**	nb_col		:	nb de couleur;
**	rot_x,y,z 	: 	matrice de rotation x,y,z;
**	rot_zoom	:	matrice de zoom;
**	final 		:	matrice final;
**	l_zoom		:	type de projection;
**	mult 		:	multiplicateur de distance pour x, y et z;
**	rot 		:	rotation pour x, y et z;
**	trans 		: 	translation de l'image projeté
**	center 		:	position camera;
**	horizon 	: 	enregistre les 4 coin de la map a z = 0, pour line horizon;
**	centrage 	:	type de centrage;
**	extrem2		:	extrem pixel en x et y pour recentrage;
**	losange		:	composante de ecran;
**	los_max		:	max et min de losange (xmax, xmin, ymax, ymin, longeur
**						losange, hauteur losange);
**	transparence:	active ou desactive transparence;
**	nbz 		:	nombre de z differents;
**	rot_type 	:	euler ou cardan;
**	menut 		:	variable info pour le menu qui affiche les commandes;
**	menu 		: 	variable info pour le menu qui affiche les var du prog;
**	f_principal	:	fenetre principal ouverte ?;
**	menut_a 	:	fenetre keyboards ouverte ?;
**	menu_a 		:	fenetre menu ouvert ?;
**	grad 		:	tab -> les graduation pour changer les valeurs du prog;
*/

typedef struct		s_info
{
	void			*mlx;
	void			*win;
	int				win_h;
	int				win_l;
	t_pixel			**ecran;
	t_point			**grid;
	int				l;
	int				h;
	double			extrem[2];
	void			*img;
	int				*pixel_img;
	int				bpp;
	int				s_line;
	int				ed;
	int				**col;
	double			**p_col;
	char			col_spe;
	int				nb_col;
	t_matrix		*rot_x;
	t_matrix		*rot_y;
	t_matrix		*rot_z;
	t_matrix		*rot_zoom;
	t_matrix		*final;
	double			l_zoom;
	double			mult[3];
	double			rot[3];
	int				trans[2];
	double			center[3];
	t_point			horizon[8];
	int				centrage;
	int				extrem2[4];
	int				**losange;
	int				los_max[6];
	int				transparence;
	int				nbz;
	int				*t_nbz;
	int				rot_type;
	t_menu_t		*menut;
	t_menu			*menu;
	int				f_principal;
	int				menut_a;
	int				menu_a;
	double			grad[6];
}					t_info;

typedef struct		s_pt_ft
{
	void			(*pt)(t_info*);
	int				key;
}					t_pt_ft;

t_list				*ft_register_map(char *file, t_info *info);
void				ft_convert_map(t_list *map0, t_info *fo);
t_list				*get_file_param(char *file);
void				init_param(t_list *beg, t_info *fo);
int					init_param_2(t_list *beg, t_info *fo);
t_list				*init_lx(t_list *beg, t_info *fo);
t_list				*init_ly(t_list *beg, t_info *fo);
t_list				*init_lz(t_list *beg, t_info *fo);
t_list				*init_rx(t_list *beg, t_info *fo);
t_list				*init_ry(t_list *beg, t_info *fo);
t_list				*init_rz(t_list *beg, t_info *fo);
t_list				*init_win_size(t_list *beg, t_info *fo);
t_list				*init_centrage(t_list *beg, t_info *fo);
t_list				*init_l_zoom(t_list *beg, t_info *fo);
void				ft_block_prepa_map(char *file, t_info *fo, t_list *beg_p);
void				draw_map(t_info *fo);
void				record_pixel_3(t_info *fo);
void				ft_pixel_extrem(t_info *fo);
void				ft_recentre(t_info *fo);
void				ft_horizon_cal(t_info *fo);
void				ft_init_horizon(t_info *fo);
t_list				*init_transparence(t_list *beg, t_info *fo);
int					key_hook(int keycode, t_info *fo);
void				draw_reload(t_info *fo);
t_list				*init_rot_type(t_list *beg, t_info *fo);
void				ft_mixt_matrice_2(t_info *fo);
t_list				*init_color(t_list *beg, t_info *fo);
void				ft_trace_map_4(t_info *fo);
void				ft_trace_losange(t_info *fo, int x, int y, int *t);
void				ft_del_losange(t_info *fo);
void				ft_fusion_losange(t_info *fo);
void				ft_trace_d(t_info *fo, t_pixel *p1, t_pixel *p2);
void				ft_init_grid_losange(t_info *fo);
int					ft_verif_losange_in_win(t_info *fo, int x, int y, int *t);
void				ft_put_color(t_info *fo, t_pixel *p1, t_pixel *p2);
void				ft_init_p_col(t_info *fo);
void				ft_affiche_nbz(t_info *fo);
void				ft_extrem_map(t_info *fo);
void				ft_print_grid(t_info *fo, int i);
void				ft_trace_map(t_info *fo);
void				ft_menu_touche(t_info *fo);
int					ft_init_menut(t_info *fo);
void				put_menut(t_menu_t *tt);
int					ft_init_menu(t_info *fo);
void				ft_menu(t_info *fo);
void				put_menu(t_info *fo);
void				key_hook_menu(int keycode, t_info *fo);
void				menu_rot_x(t_info *fo);
void				menu_rot_y(t_info *fo);
void				menu_rot_z(t_info *fo);
void				key_hook_mlt(int keycode, t_info *fo);
void				menu_rot_type(t_info *fo);
void				init_tab_f_menu_2(t_menu *tt);
void				menu_tran_h(t_info *fo);
void				menu_tran_v(t_info *fo);
void				menu_mult_x(t_info *fo);
void				menu_mult_y(t_info *fo);
void				menu_mult_z(t_info *fo);
void				menu_cam_x(t_info *fo);
void				menu_cam_y(t_info *fo);
void				menu_cam_z(t_info *fo);
void				menu_centrage(t_info *fo);
void				menu_transparence(t_info *fo);
void				menu_lzoom(t_info *fo);
void				menu_mult_g(t_info *fo);
void				ft_exit_fdf(t_info *fo);
void				fdf_free_ecran(t_info *fo);
void				fdf_free_grid(t_info *fo);
void				fdf_free_col(t_info *fo);
void				fdf_free_p_col(t_info *fo);
void				fdf_free_matrix(t_info *fo);
void				ft_affiche_menut(t_info *fo);
void				ft_affiche_menu(t_info *fo);
void				put_menut_2(t_menu_t *tt);
int					mouse_hook(t_info *fo);
int					mouse_hook_2(t_info *fo);
int					mouse_hook_3(t_info *fo);
int					expose_hook(t_info *fo);
int					expose_hook_2(t_info *fo);
int					expose_hook_3(t_info *fo);
void				draw_menut(t_menu_t *tt);
void				draw_init_menu(t_menu *tt);
int					mouse_hook_4(int but, int x, int y, t_info *fo);
void				draw_init_menu_2(t_menu *tt);
void				put_menu_3(t_info *fo);
void				ft_init_menu_2(t_menu *tt);
void				menu_grad_rot(t_info *fo);
void				init_tab_f_menu_4(t_menu *tt);
void				mouse_hook_5(int but, int x, int y, t_info *fo);
void				menu_grad_trans(t_info *fo);
void				menu_grad_mult(t_info *fo);
void				menu_grad_multg(t_info *fo);
void				menu_grad_cam(t_info *fo);

#endif
