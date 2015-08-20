#include<stdio.h>
#include<stdlib.h>
#include"protocol.h"
#include"show_map.h"
#include"game.h"
#include"map.h"

int main()
{
	//1.获得地图的大小以及地雷的个数
	printf("Please input map's size(size*size):__\b\b");
	int length;
	scanf("%d",&length);
	printf("Please input mine's counts:__\b\b");
	int mine_counts;
	scanf("%d",&mine_counts);
	if(length*length < mine_counts)
	{
		printf("can you go to dead, I have no much time to play with you!\nbyebye!\n");
		exit(0);
	}
	//2.申请后台的地图和用户使用的地图,用户地图初始化为未知状态,真实地图初始化为0
	int **user_map = get_map(length);
	int **real_map = get_map(length);
	int **tmp_map = get_map(length);
	initial_map(real_map,length,0);
	initial_map(user_map,length,UNKNOW);
	//3.对后台地图进行设置地雷
	set_mines(real_map,length,mine_counts);
	//4.填充数字
	set_mine_counts(real_map,length);
	//定义光标变量x,y,并设初始值为0,定义一个方向dir,定义打开地图时的返回值,定义一个控制棋子数量的flag_counts和开关变量ok
	int x = 0, y = 0, ret, flag_counts = 0;
	char dir, ok = 0;
	system("clear");
	c_show_map(user_map,length,x,y);
	//接收键盘消息,并作出反应(windows程序的运行机制)
	while((dir = get_opt()) && (dir != QUIT))
	{
		//上下左右,插旗,打开
		switch(dir)
		{
			case UP:
				if(x <= 0)
				{
					x = 0;
				}
				else
				{
					x--;
				}
				break;
			case DOWN :
				if(x >= length-1)
				{
					x = length-1;
				}
				else
				{
					x++;
				}
				break;
			case LEFT:
				if( y <= 0)
				{
					y = 0;
				}
				else
				{
					y--;
				}
				break;
			case RIGHT:
				if(y >= length-1)
				{
					y = length-1;
				}
				else
				{
					y++;
				}
				break;
			case OPEN:
			//这个不封装了,这是主线思路
			//判断地图是否是UNKNOW的状态
			if(*(*(user_map+x)+y) == UNKNOW)
			{
				//将后台地图的值赋值给用户地图
				*(*(user_map+x)+y) = *(*(real_map+x)+y);
				//打开开关
				ok = 1;
			}
			break;
		case INSERT_FLAG:
			//判断地图是否已经插旗,插旗变成未知,未知变成插期
			if(*(*(user_map+x)+y) == UNKNOW)
			{
				if(flag_counts < mine_counts)
				{
					*(*(user_map+x)+y) = FLAG;
					flag_counts++;
				}
			}
			else if(*(*(user_map+x)+y) == FLAG)
			{
				*(*(user_map+x)+y) = UNKNOW;
				flag_counts--;
			}
			break;
		}
		//开关这段代码可以做成函数,也可以不做,做成函数主函数思路就不清晰了
/****************************************************可封装减少主函数代码量********************************/
		//只对翻开地图的操作打开开关
		if(ok == 1)
		{
			printf("x = %d, y = %d\n",x,y);
			//翻开0,遍历周围的所有单元,将为空的地图全部打开
			if(*(*(user_map+x)+y) == 0)
			{
				copy_map(tmp_map,real_map,length);
				open_all_ctn_unit(tmp_map,user_map,x,y,length);
			}
			else if(*(*(user_map+x)+y) == MINE)
			{		
				//打开地雷直接游戏结束
				printf("You failed! Game Over\n");
				break;
			}
			//如果打开的是普通数字,判断地雷数和没有打开的数量是否相等,相等则说明赢了
			if(mine_counts == (num_counts(user_map,length,length,UNKNOW)+num_counts(user_map,length,length,FLAG)))
			{
				system("clear");
				printf("You Win! Game Over\n");
				break;
			}
			//关闭开关
			ok = 0;
		}
/****************************************************可封装减少主函数代码量********************************/
		system("clear");
		c_show_map(user_map,length,x,y);
	}	
	c_show_map(real_map,length,x,y);
	free_map(real_map,length);
	free_map(user_map,length);
	free_map(tmp_map,length);
}
