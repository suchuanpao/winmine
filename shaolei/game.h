#ifndef _GAME_H_
#define _GAME_H_


/****************************宏定义*********************************/
/*
//光标移动操作
#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'
//对元素插期了翻开操作
#define OPEN 'o'
#define INSERT_FLAG 'f'
#define QUIT 'q'
//用户地图的状态
#define UNKNOW 123
#define FLAG 456
#define SPACE 789
*/
/****************************接口声明*********************************/


//功能：操作用户地图
int control_usr_map(int** map, int real_num, int x, int y, char opt);
//功能：将光标周围所有连续的未知状态但实际内容为空的单元全部放到数组中并返回
void open_all_ctn_unit(int** r_map, int** u_map, int x, int y, int length);


char get_opt();
char screen_str(char *str);
#endif
