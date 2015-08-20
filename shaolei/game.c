#include <termios.h>
#include <stdlib.h>
#include<stdio.h>
#include"game.h"
#include"map.h"
#include"data_structure.h"
#include"protocol.h"

int control_usr_map(int** map, int real_num, int x, int y,char opt)
{
	switch(opt)
	{
		case OPEN:
			if(*(*(map+x)+y) == UNKNOW)
			{
				if(real_num != MINE)
				{
					*(*(map+x)+y) = real_num;
				}
				else
				{
					*(*(map+x)+y) = MINE;
				}
			}
			break;
		case INSERT_FLAG:
			if(*(*(map+x)+y) == UNKNOW)
			{
				*(*(map+x)+y) = FLAG;
			}
			else if(*(*(map+x)+y) == FLAG)
			{
				*(*(map+x)+y) = UNKNOW;
			}
			break;
	}
	return *(*(map+x)+y);
}

void open_all_ctn_unit(int **r_map, int** u_map, int x, int y, int length)
{
	struct Queue * tail;
	int i, j;
	//获得周边数值
	//*(*(r_map+x)+y)=1;
	for(i = -1; i <= 1; i++)
	{
		if((x+i) < 0 || (x+i) >= length)
		{
			continue;
		}
		for(j = -1; j <= 1; j++)
		{
			if( ((y+j) < 0) || ((y+j) >= length) || (i == j) || (i == -j))
			{
				continue;
			}
			else if( *(*(r_map+x+i)+y+j) == 0)
			{
				*(*(u_map+x+i)+y+j) = 0;
				tail = in_queue();
				tail->pos = (x+i)*length+(y+j);
				*(*(r_map+x+i)+y+j) = 9;
			}
			else
			{
				if(*(*(r_map+x+i)+y+j) < 9)
				{
					*(*(u_map+x+i)+y+j) = *(*(r_map+x+i)+y+j);
				}
			}
		}
	}
	int	pos = de_queue();
	if(pos != QUE_IS_EMPTY)
	{
		open_all_ctn_unit(r_map,u_map,pos/length,pos%length,length);
	}
}

char get_opt()
{
	char str[4];
	int i;
	//设置缓冲区大小一个字符,即时读取字符消息
	struct termios new_settings;
	struct termios old_settings;
	//获得终端的设置
	tcgetattr(0,&old_settings);
	//修改设置
	new_settings = old_settings;
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	//再次获得新的设置
	tcgetattr(0,&old_settings);
	//设置自定义的属性
	tcsetattr(0,TCSANOW,&new_settings);
	for(i = 0; i < 3; i++)
	{
		str[i] = getchar();
		if((str[i] != OPEN) && (str[i] != QUIT) && (str[i] != INSERT_FLAG))
		{
			if(str[0] == 27)
			{
				continue;
			}
			else
			{
				i = -1;
			}
		}
		else
		{
			//使用结束,设置回原来的属性
			tcsetattr(0,TCSANOW,&old_settings);
			return str[i];
		}
	}
	//使用结束，设置回原来的属性
	tcsetattr(0,TCSANOW,&old_settings);
	return screen_str(str);
}
char screen_str(char* str)
{
	if(str[0] == 27)
	{
		if(str[1] == 91)
		{
			switch(str[2])
			{
				case 65:
					return UP;
				case 66:
					return DOWN;
				case 67:
					return RIGHT;
				case 68:
					return LEFT;
			}
		}
	}
	return -1;
}

