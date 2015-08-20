#ifndef _MAP_H_
#define _MAP_H_




//功能：遍历所有非地雷元素,将周围地雷个数赋值给它
int ** set_mine_counts(int** map, int length);
//功能：判断周围相连的元素有多少地雷
int how_many_mines(int** map, int x, int y, int length);

//功能：生成大量的地雷
int set_mines(int ** map, int length, int counts);
//功能：游戏所使用的map生成新地雷
int set_mine(int ** map, int length);

//功能：找出图中为空的元素的个数
int empty_unit_counts(int ** map,int length);
//功能：将数组中的为空的元素的地址存到数组中
int *empty_unit_pos_array(int * array, int ** map, int length);

//功能：申请一个长度为length的二维数组
int ** get_map(int length);
//功能：将二维数组的内容复制到新的二维数组中，并返回新数组的指针
int ** copy_map(int ** new_map,int ** map,int length);
//功能：初始化地图全部都是num
int ** initial_map(int ** map, int length, int num);
//功能：游戏结束时调用，释放申请的二维数组空间
void free_map(int **map,int length);
//功能：输出二位数组地图
void print_map(int ** map, int length);
//功能：获得map中某个数的存在的数量
int num_counts(int ** map, int row, int col, int num);

#endif
