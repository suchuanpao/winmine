#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include"map.h"
#include"protocol.h"

int ** set_mine_counts(int** map, int length)
{
	int i, j;
	for(i = 0; i < length; i++)
	{
		for(j = 0; j < length; j++)
		{
			if(*(*(map+i)+j) != MINE)
			{
				*(*(map+i)+j) = how_many_mines(map,i,j,length);
			}
		}
	}
	return map;
}

int how_many_mines(int **map, int x, int y, int length)
{
	int i, j, counts = 0;
	for(i = -1; i <= 1; i++)
	{
		if((x+i) < 0 || (x+i) >= length)
		{
			continue;
		}
		for(j = -1; j <= 1; j++)
		{
			if(((y+j) < 0) || ((y+j) >= length) || (i == j && i == 0))
			{
				continue;
			}
			if(MINE == map[x+i][y+j])
			{
				counts++;
			}
		}
	}
	return counts;
}



int set_mines(int ** map, int length, int counts)
{
	int i;
	for(i = 0; i < counts; i++)
	{
		set_mine(map,length);
	}
}

int set_mine(int **map, int length)
{
	srand(time(NULL));
	//counts空位置数量,pos空单元格的位置,val新元素的大小
	int counts,pos,val;
	//存储counts个空单元格的位置
	int *array;

	counts=empty_unit_counts(map,length);
	if(counts == 0)
	{
		return 0;
	}
	array = (int*)malloc(counts*sizeof(int));
	if(array == NULL)
	{
		return 0;
	}
	empty_unit_pos_array(array,map,length);
	pos = rand() % counts;
	*(*(map+array[pos]/length)+array[pos]%length) = MINE;
	free(array);
	return 1;
}
int empty_unit_counts(int ** map,int length)
{
	int i,j,num=0;
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			if(*(*(map+i)+j)==0)
			{
				num++;
			}
		}
	}
	return num;
}
int * empty_unit_pos_array(int * array,int **map,int length)
{
	int i,j,num=0;
	for(i=0;i<length;i++)
	{
		for(j=0;j<length;j++)
		{
			if(*(*(map+i)+j)==0)
			{
				*(array+num)=i*length+j;
				num++;
			}
		}
	}
	return array;
}
int ** get_map(int length)
{
	int i;
	int ** map;
	map = (int**)malloc(length*sizeof(int*));
	if(map == NULL)
	{
		return NULL;
	}
	for(i = 0; i < length; i++)
	{
		*(map+i) = (int*)malloc(length*sizeof(int));
		if(*(map+i) == NULL)
		{
			return NULL;
		}
	}
	return map;
}


int ** copy_map(int ** new_map,int ** map,int length)
{
    int i,j;
    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++)
        {
            *(*(new_map+i)+j)=*(*(map+i)+j);
        }
    }
    return new_map;
}
int ** initial_map(int ** map, int length, int num)
{
	int i,j;
    for(i = 0;i < length; i++)
    {
        for(j = 0;j < length; j++)
        {
            *(*(map+i)+j) = num;
        }
    }
    return map;
}

void free_map(int **map, int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		free(*(map+i));
	}
	free(map);
	map = NULL;
}
void print_map(int ** map, int length)
{
	int i, j;
	for(i = 0; i < length; i++)
	{
		for(j = 0; j < length; j++)
		{
			printf("%5d", *(*(map+i)+j));
		}
		putchar('\n');
	}
}
int num_counts(int ** map, const int row, int col, int num)
{
	int i, j, counts = 0;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			if(num == *(*(map+i)+j))
				counts++;
		}
	}
	return counts;
}
