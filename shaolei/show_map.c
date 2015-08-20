#include<stdlib.h>
#include"show_map.h"
#include "protocol.h"
//输出长度相等的不同字符
int print_number(int val)
{
	switch(val)
	{
		case 0:
			ZERO_SPACE();
			break;
		case 1:
		case 8:
			WORD_PURPLE(val);
			break;
		case 2:
		case 7:
			WORD_GREEN(val);
			break;
		case 3:
		case 6:
			WORD_YELLOW(val);
			break;
		case 4:
		case 5:
			WORD_RED(val);
			break;
		case FLAG:
			FLAG_SPACE();
			break;
		case UNKNOW:
			UNKNOW_SPACE();
			break;
		case MINE:
			MINE_SPACE();
			break;
	}
	return val;
}
int print_flick(int val)
{
	switch(val)
	{
		case 0:
			FLICKER_SPACE();
			break;
		case 1:
		case 8:
			FLICKER_BLUE(val);
			break;
		case 2:
		case 7:
			FLICKER_GREEN(val);
			break;
		case 3:
		case 6:
			FLICKER_YELLOW(val);
			break;
		case 4:
		case 5:
			FLICKER_RED(val);
			break;
		case FLAG:
			FLICKER_FLAG();
			break;
		case UNKNOW:
			FLICKER_UNKNOW();
			break;
		case MINE:
			FLICKER_MINE();

	}
}

void color_space(int val)
{

	switch(val)
	{
		case 0:
		case 1:
		case 8:
		case 2:
		case 7:
		case 3:
		case 6:
		case 4:
		case 5:
			ZERO_SPACE();
			break;
		case FLAG:
			RED_SPACE();
			break;
		case UNKNOW:
			UNKNOW_SPACE();
			break;
		case MINE:
			BLUE_SPACE();
			break;
	}
}

//控制台程序显示二维图
void c_show_map(int **map,int length, int x, int y)
{
	int row, col;	
	printf("show_map\n");
	for(row=0;row<length;row++)
	{
		//上划线
	//	self_def_undo_length(length);
		/*
		//中空
		for(col = 0; col < length; col++)
		{
			VERTICAL();
			color_space(*(*(map+raw)+col));
		}
		VERTICAL();
		putchar('\n');
		*/
		//输出数字
		for(col = 0; col < length; col++)
		{
			VERTICAL();
			if(row == x && col == y)
			{
				print_flick(*(*(map+row)+col));
			}
			else
			{
				print_number(*(*(map+row)+col));
			}
		}
		VERTICAL();
		putchar('\n');
		/*
		//中空
		for(col = 0; col < length; col++)
		{
			VERTICAL();
			color_space(*(*(map+row)+col));
		}
		VERTICAL();
		putchar('\n');
		//上划线
		*/
	}
//	self_def_undo_length(length);
}
//上划线个数
void self_def_undo_length(int length)
{
	for(; length > 0; length--)
	{
		ADD();
		self_def_undo_width(UNDO_WIDTH);
	}
	ADD();
	putchar('\n');
}
//上划线宽度
void self_def_undo_width(int size)
{
	for(; size > 0; size--)
	{
		SUB();
	}
}


