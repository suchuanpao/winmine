#ifndef __SHOW_COLOR_TABLE_H__
#define __SHOW_COLOR_TABLE_H__

#include <stdio.h>

#define p1 " "
#define p2 "  "
#define p3 "   "
#define p4 "    "
#define p5 "     "
#define p6 "      "
#define p8 "        "
#define UNDO_WIDTH 2
#define VERTICAL()          printf("\033[31;1m|\033[0m")
#define ADD()				printf("\033[31;1m+\033[0m")
#define SUB()				printf("\033[31;1m-\033[0m")

#define ZERO_SPACE()		printf("%s",p2)
#define WORD_RED(val)		printf("\033[31;1m%2d\033[0m", val)
#define WORD_GREEN(val)		printf("\033[32;1m%2d\033[0m", val)
#define WORD_YELLOW(val)	printf("\033[33;1m%2d\033[0m", val)
#define WORD_BLUE(val)		printf("\033[34;1m%2d\033[0m", val)
#define WORD_PURPLE(val)	printf("\033[35;1m%2d\033[0m", val)
#define WORD_DEEPGREEN(val)	printf("\033[36;1m%2d\033[0m", val)

#define FLICKER_SPACE()			printf("\033[40;1m%s\033[0m",p2)
#define FLICKER_RED(val)		printf("\033[41;30;1m%2d\033[0m",val)
#define FLICKER_GREEN(val)		printf("\033[42;30;1m%2d\033[0m",val)
#define FLICKER_YELLOW(val)		printf("\033[43;30;1m%2d\033[0m",val)
#define FLICKER_BLUE(val)		printf("\033[44;30;1m%2d\033[0m",val)
#define FLICKER_PURPLE(val)		printf("\033[45;30;1m%2d\033[0m",val)
#define FLICKER_DEEPGREEN(val)	printf("\033[46;30;1m%2d\033[0m",val)
#define FLICKER_FLAG()			printf("\033[31;44;1m%2s\033[0m","F")
#define FLICKER_UNKNOW()		printf("\033[40;1m%2s\033[0m","  ")
#define FLICKER_MINE()			printf("\033[41;1m%2s\033[0m","*")

#define RED_SPACE()			printf("\033[31;42;1m%s\033[0m",p2)
#define GREEN_SPACE()		printf("\033[35;46;1m%s\033[0m",p2)
#define YELLOW_SPACE()		printf("\033[34;43;1m%s\033[0m",p2)
#define BLUE_SPACE()		printf("\033[33;44;1m%s\033[0m",p2)
#define PURPLE_SPACE()		printf("\033[35;45;1m%s\033[0m",p2)
#define DEEPGREEN_SPACE()	printf("\033[36;41;1m%s\033[0m",p2)

#define FLAG_SPACE()		printf("\033[31;41;1m%2s\033[0m","!F")
#define UNKNOW_SPACE()		printf("\033[31;44;1m%2s\033[0m","  ")
#define MINE_SPACE()		printf("\033[31;46;1m%2s\033[0m","#*")

//输出彩色数字
int print_number(int val);
//输出反彩的颜色
int print_flick(int val);
//控制台显示地图
void c_show_map(int **map,int length, int x, int y);
//上划线个数
void self_def_undo_length(int length);
//上划线宽度
void self_def_undo_width(int size);
//有颜色的空格
void color_space(int val);
#endif
