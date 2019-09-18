/*
 * map.cpp
 *
 *  Created on: 2016/10/29
 *      Author: Koizumi
 */

#include"map.h"

//map_wall(x,y,RIGHT)->1or0
MAZE_WALL map::x_maze_wall[MAZE_SIZE], map::y_maze_wall[MAZE_SIZE];
MAZE_WALL map::x_wall_exist[MAZE_SIZE], map::y_wall_exist[MAZE_SIZE];

//target_wallのedit_number目にset_numberを代入する関数
void map::set_maze_wall(MAZE_WALL* const maze_wall, unsigned char edit_number,
		bool is_wall) {
	int8_t set_number;
	if (is_wall)
		set_number = 1;
	else
		set_number = 0;

	switch (edit_number) {
	case 0:
		maze_wall->bit.B0 = set_number;
		break;
	case 1:
		maze_wall->bit.B1 = set_number;
		break;
	case 2:
		maze_wall->bit.B2 = set_number;
		break;
	case 3:
		maze_wall->bit.B3 = set_number;
		break;
	case 4:
		maze_wall->bit.B4 = set_number;
		break;
	case 5:
		maze_wall->bit.B5 = set_number;
		break;
	case 6:
		maze_wall->bit.B6 = set_number;
		break;
	case 7:
		maze_wall->bit.B7 = set_number;
		break;
	case 8:
		maze_wall->bit.B8 = set_number;
		break;
	case 9:
		maze_wall->bit.B9 = set_number;
		break;
	case 10:
		maze_wall->bit.B10 = set_number;
		break;
	case 11:
		maze_wall->bit.B11 = set_number;
		break;
	case 12:
		maze_wall->bit.B12 = set_number;
		break;
	case 13:
		maze_wall->bit.B13 = set_number;
		break;
	case 14:
		maze_wall->bit.B14 = set_number;
		break;
	case 15:
		maze_wall->bit.B15 = set_number;
		break;
	case 16:
		maze_wall->bit.B16 = set_number;
		break;
	case 17:
		maze_wall->bit.B17 = set_number;
		break;
	case 18:
		maze_wall->bit.B18 = set_number;
		break;
	case 19:
		maze_wall->bit.B19 = set_number;
		break;
	case 20:
		maze_wall->bit.B20 = set_number;
		break;
	case 21:
		maze_wall->bit.B21 = set_number;
		break;
	case 22:
		maze_wall->bit.B22 = set_number;
		break;
	case 23:
		maze_wall->bit.B23 = set_number;
		break;
	case 24:
		maze_wall->bit.B24 = set_number;
		break;
	case 25:
		maze_wall->bit.B25 = set_number;
		break;
	case 26:
		maze_wall->bit.B26 = set_number;
		break;
	case 27:
		maze_wall->bit.B27 = set_number;
		break;
	case 28:
		maze_wall->bit.B28 = set_number;
		break;
	case 29:
		maze_wall->bit.B29 = set_number;
		break;
	case 30:
		maze_wall->bit.B30 = set_number;
		break;
	case 31:
		maze_wall->bit.B31 = set_number;
		break;

	}
}
bool map::get_maze_wall(MAZE_WALL maze_wall, unsigned char edit_number) {
	unsigned char maze_check = 0;		//元FALSE

	switch (edit_number) {
	case 0:
		maze_check = maze_wall.bit.B0;
		break;
	case 1:
		maze_check = maze_wall.bit.B1;
		break;
	case 2:
		maze_check = maze_wall.bit.B2;
		break;
	case 3:
		maze_check = maze_wall.bit.B3;
		break;
	case 4:
		maze_check = maze_wall.bit.B4;
		break;
	case 5:
		maze_check = maze_wall.bit.B5;
		break;
	case 6:
		maze_check = maze_wall.bit.B6;
		break;
	case 7:
		maze_check = maze_wall.bit.B7;
		break;
	case 8:
		maze_check = maze_wall.bit.B8;
		break;
	case 9:
		maze_check = maze_wall.bit.B9;
		break;
	case 10:
		maze_check = maze_wall.bit.B10;
		break;
	case 11:
		maze_check = maze_wall.bit.B11;
		break;
	case 12:
		maze_check = maze_wall.bit.B12;
		break;
	case 13:
		maze_check = maze_wall.bit.B13;
		break;
	case 14:
		maze_check = maze_wall.bit.B14;
		break;
	case 15:
		maze_check = maze_wall.bit.B15;
		break;
	case 16:
		maze_check = maze_wall.bit.B16;
		break;
	case 17:
		maze_check = maze_wall.bit.B17;
		break;
	case 18:
		maze_check = maze_wall.bit.B18;
		break;
	case 19:
		maze_check = maze_wall.bit.B19;
		break;
	case 20:
		maze_check = maze_wall.bit.B20;
		break;
	case 21:
		maze_check = maze_wall.bit.B21;
		break;
	case 22:
		maze_check = maze_wall.bit.B22;
		break;
	case 23:
		maze_check = maze_wall.bit.B23;
		break;
	case 24:
		maze_check = maze_wall.bit.B24;
		break;
	case 25:
		maze_check = maze_wall.bit.B25;
		break;
	case 26:
		maze_check = maze_wall.bit.B26;
		break;
	case 27:
		maze_check = maze_wall.bit.B27;
		break;
	case 28:
		maze_check = maze_wall.bit.B28;
		break;
	case 29:
		maze_check = maze_wall.bit.B29;
		break;
	case 30:
		maze_check = maze_wall.bit.B30;
		break;
	case 31:
		maze_check = maze_wall.bit.B31;
		break;
	}

	if (maze_check == 0)
		return false;
	else
		return true;
}

void map::remember_exist(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char set_x = wall_x, set_y = wall_y;

	//x座標方向を変更すると�?
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//�?番左壁�?�管�?しな�?
				return;
			} else {
				set_x = wall_x - 1;	//�?ず右壁を更新するように、座標を変え�?
			}
		}
		if (set_x < MAZE_SIZE) {
			set_maze_wall(&x_wall_exist[set_y], set_x, true);//x_maze_wall[y]のx番目の右壁に1を代入
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないx座標に壁�?�存在を作ろ�?として�?ます\n\r");
			myprintf("remember_exist関数�?\n\r");
		}

		//y座標方向を変更すると�?
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//�?番下壁�?�管�?しな�?
				return;
			} else {
				set_y = wall_y - 1;	//�?ず上壁を更新するように、座標を変え�?
			}
		}
		if (set_y < MAZE_SIZE) {
			set_maze_wall(&y_wall_exist[set_x], set_y, true);//x_maze_wall[y]のx番目の右壁に1を代入
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないy座標に壁�?�存在を作ろ�?として�?ます\n\r");
			myprintf("remember_exist関数�?\n\r");
		}

	}

}
void map::forget_exist(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char set_x = wall_x, set_y = wall_y;

	//x座標方向を変更すると�?
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//�?番左壁�?�管�?しな�?
				return;
			} else {
				set_x = wall_x - 1;	//�?ず右壁を更新するように、座標を変え�?
			}
		}
		if (set_x < MAZE_SIZE) {
			set_maze_wall(&x_wall_exist[set_y], set_x, false);//x_maze_wall[y]のx番目の右壁にfalseを代入
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないx座標�?�壁�?�存在を消そ�?として�?ます\n\r");
			myprintf("forget_exist関数�?\n\r");
		}

		//y座標方向を変更すると�?
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//�?番下壁�?�管�?しな�?
				return;
			} else {
				set_y = wall_y - 1;	//�?ず上壁を更新するように、座標を変え�?
			}
		}
		if (set_y < MAZE_SIZE) {
			set_maze_wall(&y_wall_exist[set_x], set_y, false);//x_maze_wall[y]のx番目の上壁に1false代入
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないy座標�?�壁�?�存在を消そ�?として�?ます\n\r");
			myprintf("forget_exist関数�?\n\r");
		}

	}

}
bool map::check_exist(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char target_x = wall_x, target_y = wall_y;

	//x座標方向を見るすると�?
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//�?番左壁�?�管�?しな�?
				return true;
			} else {
				target_x = wall_x - 1;	//�?ず右壁を見るように、座標を変え�?
			}
		}
		if (target_x < MAZE_SIZE) {
			return get_maze_wall(x_wall_exist[target_y], target_x);
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないx座標�?�壁�?�存在を読もうとして�?ます\n\r");
			myprintf("check_exist関数�?\n\r");
			return false;
		}

		//y座標方向を変更すると�?
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//�?番下壁�?�常に壁が存在
				return true;
			} else {
				target_y = wall_y - 1;	//�?ず上壁を更新するように、座標を変え�?
			}
		}
		if (target_y < MAZE_SIZE) {
			return get_maze_wall(y_wall_exist[target_x], target_y);
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないy座標�?�壁�?�存在を読もうとして�?ます\n\r");
			myprintf("check_exist関数�?\n\r");
			return false;
		}
	}

	return false;
}

bool map::check_exist(unsigned char wall_x, unsigned char wall_y, compas dir) {
	unsigned char target_x = wall_x, target_y = wall_y;

	//x座標方向を見るすると�?
	if ((dir == east) || (dir == west)) {
		if (dir == west) {
			if (wall_x == 0) {		//�?番西壁�?�管�?しな�?
				return true;
			} else {
				target_x = wall_x - 1;	//�?ず東壁を見るように、座標を変え�?
			}
		}
		if (target_x < MAZE_SIZE) {
			return get_maze_wall(x_wall_exist[target_y], target_x);
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないx座標�?�壁�?�存在を読もうとして�?ます\n\r");
			myprintf("check_exist関数�?\n\r");
			return false;
		}

		//y座標方向を変更すると�?
	} else if ((dir == north) || (dir == south)) {
		if (dir == south) {
			if (wall_y == 0) {		//�?番南壁�?�常に壁が存在
				return true;
			} else {
				target_y = wall_y - 1;	//�?ず北壁を更新するように、座標を変え�?
			}
		}
		if (target_y < MAZE_SIZE) {
			return get_maze_wall(y_wall_exist[target_x], target_y);
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないy座標�?�壁�?�存在を読もうとして�?ます\n\r");
			myprintf("check_exist関数�?\n\r");
			return false;
		}
	}

	return false;
}

void map::create_wall(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char set_x = wall_x, set_y = wall_y;

	//x座標方向を変更すると�?
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//�?番左壁�?�管�?しな�?
				return;
			} else {
				set_x = wall_x - 1;	//�?ず右壁を更新するように、座標を変え�?
			}
		}
		if (set_x < MAZE_SIZE) {
			set_maze_wall(&x_maze_wall[set_y], set_x, true);//x_maze_wall[y]のx番目の右壁に1を代入
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないx座標に壁を作ろ�?として�?ます\n\r");
			myprintf("create_wall関数�?\n\r");
		}

		//y座標方向を変更すると�?
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//�?番下壁�?�管�?しな�?
				return;
			} else {
				set_y = wall_y - 1;	//�?ず上壁を更新するように、座標を変え�?
			}
		}
		if (set_y < MAZE_SIZE) {
			set_maze_wall(&y_maze_wall[set_x], set_y, true);//x_maze_wall[y]のx番目の右壁に1を代入
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないy座標に壁を作ろ�?として�?ます\n\r");
			myprintf("create_wall関数�?\n\r");
		}

	}

}
void map::destroy_wall(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char set_x = wall_x, set_y = wall_y;

	//x座標方向を変更すると�?
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//�?番左壁�?�管�?しな�?
				return;
			} else {
				set_x = wall_x - 1;	//�?ず右壁を更新するように、座標を変え�?
			}
		}
		if (set_x < MAZE_SIZE) {
			set_maze_wall(&x_maze_wall[set_y], set_x, false);//x_maze_wall[y]のx番目の右壁にfalseを代入
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないx座標�?�壁を壊そ�?として�?ます\n\r");
			myprintf("destroy_wall関数�?\n\r");
		}

		//y座標方向を変更すると�?
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//�?番下壁�?�管�?しな�?
				return;
			} else {
				set_y = wall_y - 1;	//�?ず上壁を更新するように、座標を変え�?
			}
		}
		if (set_y < MAZE_SIZE) {
			set_maze_wall(&y_maze_wall[set_x], set_y, false);//x_maze_wall[y]のx番目の上壁に1false代入
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないy座標�?�壁を壊そ�?として�?ます\n\r");
			myprintf("destroy_wall関数�?\n\r");
		}

	}

}
bool map::get_wall(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char target_x = wall_x, target_y = wall_y;

	//x座標方向を見るすると�?
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//�?番左壁�?�管�?しな�?
				return true;
			} else {
				target_x = wall_x - 1;	//�?ず右壁を見るように、座標を変え�?
			}
		}
		if (target_x < MAZE_SIZE) {
			return get_maze_wall(x_maze_wall[target_y], target_x);
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないx座標�?�壁を読もうとして�?ま�?->%d\n\r", target_x);
			myprintf("get_wall関数�?\n\r");
			return false;
		}

		//y座標方向を変更すると�?
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//�?番下壁�?�常に壁が存在
				return true;
			} else {
				target_y = wall_y - 1;	//�?ず上壁を更新するように、座標を変え�?
			}
		}
		if (target_y < MAZE_SIZE) {
			return get_maze_wall(y_maze_wall[target_x], target_y);
		} else {		//適�?でな�?値が�?�って�?
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("存在しないy座標�?�壁を読もうとして�?ま�?->%d\n\r", target_y);
			myprintf("get_wall関数�?\n\r");
			return false;
		}
	}

	return false;
}

void map::reset_maze() {
	//壁を消す
	for (int i = 0; i < MAZE_SIZE; i++) {
		x_maze_wall[i].all = 0;
		y_maze_wall[i].all = 0;
		x_wall_exist[i].all = 0;
		y_wall_exist[i].all = 0;
	}
	//外壁�?�入れる
	for (int i = 0; i < MAZE_SIZE; i++) {
		create_wall(0, i, MUKI_LEFT);
		remember_exist(0, i, MUKI_LEFT);
		create_wall(MAZE_SIZE - 1, i, MUKI_RIGHT);
		remember_exist(MAZE_SIZE - 1, i, MUKI_RIGHT);
		create_wall(i, 0, MUKI_DOWN);
		remember_exist(i, 0, MUKI_DOWN);
		create_wall(i, MAZE_SIZE - 1, MUKI_UP);
		remember_exist(i, MAZE_SIZE - 1, MUKI_UP);
	}
	//(0?�?0)はわかって�?
	create_wall(0, 0, MUKI_RIGHT);
	remember_exist(0, 0, MUKI_RIGHT);
	destroy_wall(0, 0, MUKI_UP);
	remember_exist(0, 0, MUKI_UP);
}

void map::draw_map(bool write_step) {
	signed char tekitou_x = 0, tekitou_y = MAZE_SIZE - 1;

	myprintf("\n-----start draw_map-------\n\r");

	//上辺
	for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++)
		myprintf("+---");
	myprintf("+\n\r");

	myprintf("|");	//左端の�?
	for (tekitou_x = 0; tekitou_x < MAZE_SIZE - 1; tekitou_x++) {

		if (write_step)
			myprintf("%3d", step::get_step(tekitou_x, tekitou_y));
		else
			myprintf("   ");

		if ((get_wall(tekitou_x, tekitou_y, MUKI_RIGHT) == true)
				|| (get_wall(tekitou_x + 1, tekitou_y, MUKI_LEFT) == true)) {//今書�?た�?�スの右の壁があれば壁を書�?
			myprintf("|");
		} else {
			myprintf(" ");	//なければ壁�?�書かな�?
		}
	}

	if (write_step)
		myprintf("%3d", step::get_step(tekitou_x, tekitou_y));
	else
		myprintf("   ");

	myprintf("|\n\r");	//右端の�?

	for (tekitou_y = MAZE_SIZE - 2; tekitou_y >= 0; tekitou_y--) {
		//////////////////////////////////////////迷路の壁�?��?
		for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++) {
			myprintf("+");	//柱
			if ((get_wall(tekitou_x, tekitou_y, MUKI_UP) == true)
					|| (get_wall(tekitou_x, tekitou_y + 1, MUKI_DOWN) == true)) {//壁があるな�?
				myprintf("---");
			} else {
				myprintf("   ");
			}
		}
		myprintf("+\n\r");

		/////////////////////////////////////////迷路のマス目の�?
		myprintf("|");	//左端の�?
		for (tekitou_x = 0; tekitou_x < MAZE_SIZE - 1; tekitou_x++) {

			if (write_step)
				myprintf("%3d", step::get_step(tekitou_x, tekitou_y));
			else
				myprintf("   ");

			if ((get_wall(tekitou_x, tekitou_y, MUKI_RIGHT) == true)
					|| (get_wall(tekitou_x + 1, tekitou_y, MUKI_LEFT) == true)) {//今書�?た�?�スの右の壁があれば壁を書�?
				myprintf("|");
			} else {
				myprintf(" ");	//なければ壁�?�書かな�?
			}
		}
		if (write_step)
			myprintf("%3d", step::get_step(tekitou_x, tekitou_y));
		else
			myprintf("   ");

		myprintf("|\n\r");	//右端の�?
	}

	//下辺
	for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++)
		myprintf("+---");
	myprintf("+\n\r");

}

/*
 void map::convert_mapdata(unsigned char (*hiramatu_data)[16]){
 for(char x=0;x<16;x++){
 for(char y=0;y<16;y++){
 if((hiramatu_data[x][y] & 2) == 2){		//東壁があれば
 create_wall(x,y,MUKI_RIGHT);
 }else{
 destroy_wall(x,y,MUKI_RIGHT);
 }
 if((hiramatu_data[x][y] & 1) == 1){		//南壁があれば
 create_wall(x,y,MUKI_UP);
 }else{
 destroy_wall(x,y,MUKI_UP);
 }
 }
 }
 }
 */

void map::input_map_data(const MAP_DATA *input_data) {
	//�?ータ入�?
	for (int i = 0; i < MAZE_SIZE; i++) {
		x_maze_wall[i].all = input_data->x_wall[i].all;
		y_maze_wall[i].all = input_data->y_wall[i].all;
		x_wall_exist[i].all = input_data->x_known[i].all;
		y_wall_exist[i].all = input_data->y_known[i].all;
	}
}

void map::output_map_data(MAP_DATA* output_data) {
	//�?ータ出�?
	for (int i = 0; i < MAZE_SIZE; i++) {
		output_data->x_wall[i].all = x_maze_wall[i].all;
		output_data->y_wall[i].all = y_maze_wall[i].all;
		output_data->x_known[i].all = x_wall_exist[i].all;
		output_data->y_known[i].all = y_wall_exist[i].all;
	}
}

map::map() {
	reset_maze();
}

map::~map() {

}

DIRECTION step::save_direction;
unsigned short step::maze_step[MAZE_SIZE][MAZE_SIZE];

void step::step_reset() {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			maze_step[i][j] = STEP_INIT;
		}
	}
}
/*
 void step::set_step(unsigned char target_x, unsigned char target_y) {
 //座標を管�?するための配�??
 unsigned char x_coordinate[965];
 unsigned char y_coordinate[965];

 //array[x]={0};って�?るとメモリ食うらし�?のでForで初期�?
 for (int16_t i = 0; i < 965; i++) {
 x_coordinate[i] = 0;
 y_coordinate[i] = 0;
 }

 unsigned char x_count = 0, y_count = 0;	//�?時的に座標をもっとくよ�?
 unsigned char head, tail;		//
 uint16_t now_step;

 step_reset();
 maze_step[target_x][target_y] = 0;

 //coordinate  [tail][][][] -> [][][head]

 head = 1;
 tail = 0;

 //Qの�?初には目標�?�座標を入れと�?
 x_coordinate[tail] = target_x;
 y_coordinate[tail] = target_y;

 while (head != tail) {
 //座標を代入
 x_count = x_coordinate[tail];
 y_count = y_coordinate[tail];
 now_step = maze_step[x_count][y_count];

 tail++;

 //左マス
 if (set_step(x_count, y_count, MUKI_LEFT, now_step + 1, false)) {
 //こ�?�座標を保持
 x_coordinate[head] = (x_count - 1);
 y_coordinate[head] = y_count;
 head++;
 }

 //右マス
 if (set_step(x_count, y_count, MUKI_RIGHT, now_step + 1, false)) {
 //こ�?�座標を保持
 x_coordinate[head] = (x_count + 1);
 y_coordinate[head] = y_count;
 head++;
 }

 //下�?�ス
 if (set_step(x_count, y_count, MUKI_DOWN, now_step + 1, false)) {
 //こ�?�座標を保持
 x_coordinate[head] = x_count;
 y_coordinate[head] = y_count - 1;
 head++;
 }

 //上�?�ス
 if (set_step(x_count, y_count, MUKI_UP, now_step + 1, false)) {
 //こ�?�座標を保持
 x_coordinate[head] = x_count;
 y_coordinate[head] = y_count + 1;
 head++;
 }

 if (head > 965) {		//配�?�越えたらエラー
 myprintf("エラー!\n\radachi::set_step()�?\n\r");
 break;
 }

 }

 }


 void step::set_step_by_known(unsigned char target_x, unsigned char target_y) {
 //座標を管�?するための配�??
 unsigned char x_coordinate[965];
 unsigned char y_coordinate[965];

 //array[x]={0};って�?るとメモリ食うらし�?のでForで初期�?
 for (int16_t i = 0; i < 965; i++) {
 x_coordinate[i] = 0;
 y_coordinate[i] = 0;
 }

 unsigned char x_count = 0, y_count = 0;	//�?時的に座標をもっとくよ�?
 unsigned char head, tail;		//

 step_reset();
 maze_step[target_x][target_y] = 0;

 //coordinate  [tail][][][] -> [][][head]

 head = 1;
 tail = 0;

 //Qの�?初には目標�?�座標を入れと�?
 x_coordinate[tail] = target_x;
 y_coordinate[tail] = target_y;

 while (head != tail) {
 //座標を代入
 x_count = x_coordinate[tail];
 y_count = y_coordinate[tail];

 tail++;

 //左マス
 if ((x_count - 1) >= 0) {		//座標が迷路�?(x-1�?0以�?)にあり
 if ((maze_step[x_count - 1][y_count] == STEP_INIT)) {//歩数を�?�れてな�?���?�ってる歩数がSTEP_INIT?�?
 if (map::get_wall(x_count, y_count, MUKI_LEFT) == false) {//�?のマスの左壁がな�?な�?
 if (map::check_exist(x_count, y_count,
 MUKI_LEFT)) {		//左壁を見て�?るな�?
 maze_step[x_count - 1][y_count] =
 maze_step[x_count][y_count] + 1;		//歩数を代入
 //こ�?�座標を保持
 x_coordinate[head] = (x_count - 1);
 y_coordinate[head] = y_count;
 head++;
 }
 }
 }
 }

 //右マス
 if ((x_count + 1) < MAZE_SIZE) {	//座標が迷路�?(x+1がMAZE_SIZE未�?)にあり
 if ((maze_step[x_count + 1][y_count] == STEP_INIT)) {//歩数を�?�れてな�?���?�ってる歩数がSTEP_INIT?�?
 if (map::get_wall(x_count, y_count, MUKI_RIGHT) == false) {	//�?のマスの右壁がな�?
 if (map::check_exist(x_count, y_count,
 MUKI_RIGHT)) {	//右壁を見て�?るな�?
 maze_step[x_count + 1][y_count] =
 maze_step[x_count][y_count] + 1;	//歩数を代入
 //こ�?�座標を保持
 x_coordinate[head] = (x_count + 1);
 y_coordinate[head] = y_count;
 head++;
 }
 }
 }
 }

 //下�?�ス
 if ((y_count - 1) >= 0) {		//座標が迷路�?(y-1�?0以�?)にあり
 if ((maze_step[x_count][y_count - 1] == STEP_INIT)) {//歩数を�?�れてな�?���?�ってる歩数がSTEP_INIT?�?
 if (map::get_wall(x_count, y_count, MUKI_DOWN) == false) {//�?のマスの下壁がな�?
 if (map::check_exist(x_count, y_count,
 MUKI_DOWN)) {		//下壁が既知な�?
 maze_step[x_count][y_count - 1] =
 maze_step[x_count][y_count] + 1;	//歩数を代入
 //こ�?�座標を保持
 x_coordinate[head] = x_count;
 y_coordinate[head] = (y_count - 1);
 head++;
 }
 }
 }
 }

 //上�?�ス
 if ((y_count + 1) < MAZE_SIZE) {	//x,y+1の座標が迷路�?(MAZE_SIZE未�?)である
 if ((maze_step[x_count][y_count + 1] == STEP_INIT)) {//歩数を�?�れてな�?���?�ってる歩数がSTEP_INIT?�?
 if (map::get_wall(x_count, y_count, MUKI_UP) == false) {//�?のマスの上壁がな�?
 if (map::check_exist(x_count, y_count,
 MUKI_UP)) {		//上壁が既知な�?
 maze_step[x_count][y_count + 1] =
 maze_step[x_count][y_count] + 1;	//歩数を代入
 //こ�?�座標を保持
 x_coordinate[head] = x_count;
 y_coordinate[head] = (y_count + 1);
 head++;
 }
 }
 }
 }

 if (head > 965) {		//配�?�越えたらエラー
 myprintf("エラー!\n\radachi::set_step()�?\n\r");
 break;
 }

 }

 }
 */
void step::spread_step(uint8_t tar_x, uint8_t tar_y, bool by_known) {
	uint8_t x, y;	//�?時的に座標をもっとくよ�?
	uint16_t now_step;
	loop = 0;

	//座標保存用Queue
	static my_queue x_que;
	static my_queue y_que;

	step_reset();

	maze_step[tar_x][tar_y] = 0;
	//Qの�?初には目標�?�座標を入れと�?
	x_que.push(tar_x);
	y_que.push(tar_y);

	while (x_que.size() != 0) {		//xもyもサイズは同じなので代表してxを使�?
		loop++;
		//座標を代入
		x = x_que.front();
		y = y_que.front();
		x_que.pop();		//取り出したので消去
		y_que.pop();		//取り出したので消去
		now_step = maze_step[x][y];

		//左マス
		if (set_step(x, y, MUKI_LEFT, now_step + 1, by_known)) {	//書き込めたな�?
			x_que.push(x - 1);		//こ�?�座標を保持
			y_que.push(y);		//こ�?�座標を保持
		}
		//右マス
		if (set_step(x, y, MUKI_RIGHT, now_step + 1, by_known)) {	//書き込めたな�?
			x_que.push(x + 1);		//こ�?�座標を保持
			y_que.push(y);		//こ�?�座標を保持
		}
		//北�?�ス
		if (set_step(x, y, MUKI_UP, now_step + 1, by_known)) {	//書き込めたな�?
			x_que.push(x);		//こ�?�座標を保持
			y_que.push(y + 1);		//こ�?�座標を保持
		}
		//南�?�ス
		if (set_step(x, y, MUKI_DOWN, now_step + 1, by_known)) {	//書き込めたな�?
			x_que.push(x);		//こ�?�座標を保持
			y_que.push(y - 1);		//こ�?�座標を保持
		}
	}

}

bool step::set_step(uint8_t _x, uint8_t _y, uint8_t _muki, uint8_t _set_step,
		bool _by_known) {

	int8_t dx, dy;
	switch (_muki) {
	case MUKI_UP:
		dx = 0;
		dy = 1;
		break;
	case MUKI_DOWN:
		dx = 0;
		dy = -1;
		break;
	case MUKI_LEFT:
		dx = -1;
		dy = 0;
		break;
	case MUKI_RIGHT:
		dx = 1;
		dy = 0;
		break;
	}

//配�?�外に出るパターンを除�?
	if (static_cast<int16_t>(_x) + dx < 0)
		return false;
	if (static_cast<int16_t>(_x) + dx >= MAZE_SIZE)
		return false;
	if (static_cast<int16_t>(_y) + dy < 0)
		return false;
	if (static_cast<int16_t>(_y) + dy >= MAZE_SIZE)
		return false;

	if ((maze_step[_x + dx][_y + dy] > _set_step)) {	//入ってる歩数が�?�れよ�?とする歩数より大きい
		if (!map::get_wall(_x, _y, _muki)) {	//壁がな�?
			if (!_by_known || map::check_exist(_x, _y, _muki)) {	//右壁を見て�?るな�?
				maze_step[_x + dx][_y + dy] = _set_step;	//歩数を代入
				return true;	//歩数を書き込めたのでtrueを返す
			}
		}
	}
	return false;

}

unsigned int step::get_step(unsigned char target_x, unsigned char target_y) {
	return maze_step[target_x][target_y];
}

void step::close_one_dead_end(unsigned char target_x, unsigned char target_y) {
	union {
		unsigned char all;				//�?括
		struct {
			unsigned char count :4;		//		行けな�?方向�?�個数
			unsigned char up :1;		//�?	x=0,y=1の方�?
			unsigned char down :1;		//�?	x=0,y=-1の方�?
			unsigned char left :1;		//�?	x=-1,y=0の方�?
			unsigned char right :1;		//�?	x=1,y=0の方�?
		} direction;
	} dead_end;

	dead_end.all = 0;	//初期�?

//左マス
	if ((map::get_wall(target_x, target_y, MUKI_LEFT))) {	//左壁があるな�?
		dead_end.direction.left = 1;	//左フラグを建て�?
		dead_end.direction.count++;	//1足�?
	} else if ((target_x - 1) >= 0) {		//座標が迷路�?(x-1�?0以�?)にあり
		if ((maze_step[target_x - 1][target_y] == STEP_INIT)
				|| (map::check_exist(target_x, target_y, MUKI_LEFT) == false)) {//左のマスに行けな�?���?�ってる歩数�?255 また�?� ?�?
			dead_end.direction.left = 1;		//左フラグオン
			dead_end.direction.count++;		//1足�?
		}
	}

//右マス
	if ((map::get_wall(target_x, target_y, MUKI_RIGHT))) {		//右壁があるな�?
		dead_end.direction.right = 1;		//右フラグを建て�?
		dead_end.direction.count++;		//1足�?
	} else if ((target_x + 1) < MAZE_SIZE) {		//座標が迷路�?(x+1がMax_x未�?)にあり
		if ((maze_step[target_x + 1][target_y] == STEP_INIT)
				|| (map::check_exist(target_x, target_y, MUKI_RIGHT) == false)) {//右のマスに行けな�?���?�ってる歩数�?255 また�?� 壁がある?�?
			dead_end.direction.right = 1;		//右フラグを建て�?
			dead_end.direction.count++;		//1足�?
		}
	}

//下�?�ス
	if ((map::get_wall(target_x, target_y, MUKI_DOWN))) {		//下壁があるな�?
		dead_end.direction.down = 1;		//下フラグを建て�?
		dead_end.direction.count++;		//1足�?
	} else if ((target_y - 1 >= 0)) {		//座標が迷路�?(y-1�?0以�?)にあり
		if ((maze_step[target_x][target_y - 1] == STEP_INIT)
				|| (map::check_exist(target_x, target_y, MUKI_DOWN) == false)) {//下�?�マスに行けな�?���?�ってる歩数�?255 また�?� 壁がある?�?
			dead_end.direction.down = 1;		//下フラグを建て�?
			dead_end.direction.count++;		//1足�?
		}
	}

//上�?�ス
	if ((map::get_wall(target_x, target_y, MUKI_UP))) {		//上壁があるな�?
		dead_end.direction.up = 1;		//上フラグを建て�?
		dead_end.direction.count++;		//1足�?
	} else if ((target_y + 1 < MAZE_SIZE)) {		//x,y+1の座標が迷路�?(MAX_y未�?)である
		if ((maze_step[target_x][target_y + 1] == STEP_INIT)
				|| (map::check_exist(target_x, target_y, MUKI_UP) == false)) {//上�?�マスに行けな�?���?�ってる歩数�?255�?また�?��?壁がある?�?
			dead_end.direction.up = 1;		//上フラグを建て�?
			dead_end.direction.count++;		//1足�?
		}
	}

//袋小路を�?�さぐ
	if (dead_end.direction.count >= 3) {		//行けな�?方向が3以�? = 袋小路な�?
		if ((target_x == 0) && (target_y == 0)) {		//それがスタートなら何もしな�?
		} else if ((target_x == GOAL_x) && (target_y == GOAL_y)) {//それがゴールでも何もしな�?
		} else {							//上記以外なら袋小路を潰�?
			maze_step[target_x][target_y] = STEP_INIT;					//歩数を�?�期�?
			//袋小路のあいてる方向につ�?てもう�?回同じことを行う
			if (dead_end.direction.left == 0) {
				map::create_wall(target_x, target_y, MUKI_LEFT);
				map::remember_exist(target_x, target_y, MUKI_LEFT);
				close_one_dead_end(target_x - 1, target_y);

			}
			if (dead_end.direction.right == 0) {
				map::create_wall(target_x, target_y, MUKI_RIGHT);
				map::remember_exist(target_x, target_y, MUKI_RIGHT);
				close_one_dead_end(target_x + 1, target_y);
			}
			if (dead_end.direction.down == 0) {
				map::create_wall(target_x, target_y, MUKI_DOWN);
				map::remember_exist(target_x, target_y, MUKI_DOWN);
				close_one_dead_end(target_x, target_y - 1);
			}
			if (dead_end.direction.up == 0) {
				map::create_wall(target_x, target_y, MUKI_UP);
				map::remember_exist(target_x, target_y, MUKI_UP);
				close_one_dead_end(target_x, target_y + 1);
			}
		}
	}
}

void step::close_dead_end() {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			close_one_dead_end(i, j);
		}
	}
}

step::step() {
	map::reset_maze();
	step_reset();

}

step::step(const MAP_DATA* input_data) {
	map::input_map_data(input_data);
}

step::~step() {

}
PATH path::path_memory[PATH_MAX];

void path::set_step_for_shortest(unsigned char target_x,
		unsigned char target_y) {

//set_step_by_known(target_x, target_y);		//既知の壁だけで歩数マップを作�??
	spread_step(target_x, target_y, true);					//既知の壁だけで歩数マップを作�??
	close_dead_end();					//袋小路を潰�?
}

void path::displace_path(unsigned int path_number) {
//1個ずらす
	for (uint16_t number = path_number;
			path_memory[number].element.flag == TRUE; number++) {
		path_memory[number].all = path_memory[number + 1].all;
	}
}

void path::improve_path() {
	unsigned int count = 0;

	while (path_memory[count].element.flag == TRUE) {	//pathが終われ�?�終�?

		if (path_memory[count].element.distance >= 1) {	//90mm以上直進するな�?

			if (path_memory[count + 1].element.distance >= 1) {	//ターン後も90mm以上直進するな�?	大回りのチェ�?クを行う
				path_memory[count].element.turn = 2;	//大回りターンに変更
				path_memory[count].element.distance -= 1;	//直線距離�?90mm減ら�?
				path_memory[count + 1].element.distance -= 1;	//直線距離�?90mm減ら�?

			} else {								//ターン�?90mm直進はしな�?な�?

				if (path_memory[count].element.muki
						== path_memory[count + 1].element.muki) {//同じ方向に曲がるな�?(Uターン)

					if (path_memory[count + 2].element.distance >= 1) {	//Uターン�?90mm直進するな�?
						path_memory[count].element.turn = 3;	//180°ターンに変更
						path_memory[count].element.distance -= 1;//直線距離�?90mm減ら�?
						path_memory[count + 2].element.distance -= 1;//直線距離�?90mm減ら�?

						//1個ずらす
						displace_path(count + 1);

					} else {							//Uターン後すぐ曲がるな�?

						if (path_memory[count + 2].element.flag == FALSE) {	//pathが終わってな�?かチェ�?ク�?終わってなければ�?方向にターンのは�?
							//ナナメの処�?なので何もしな�?
						}

					}

				} else {		//違う方法に曲がるな�?
					//ナナメの処�?なので何もしな�?
				}

			}

		}

		count++;
	}

}

void path::improve_advance_path() {
	unsigned int count = 0;
	unsigned char temp_distance = 0;	//�?時的な距離保�?
	unsigned char naname_flag = FALSE;	//現在機体が斜めかを判断	ONなら斜め走行中

	while (path_memory[count].element.flag == TRUE) {	//pathが終われ�?�終�?

		if (naname_flag == TRUE) {	//斜め走行中な�?	確実に直進距離(distance)�?0のは�?

			if (path_memory[count + 1].element.distance >= 1) {	//次のターン�?90mm以上直進(斜め終わ�?)

				path_memory[count].element.turn = 5;	//終わ�?45°ターンに変更
				path_memory[count + 1].element.distance -= 1;	//直線距離�?90mm減ら�?
				naname_flag = FALSE;
				count++;	//配�?�を次へ

			} else if (path_memory[count + 2].element.distance >= 1) {//次の次のターン�?90mm以上直進(斜め終わ�?)

				if (path_memory[count].element.muki
						== path_memory[count + 1].element.muki) {	//同じ方向�?�2回ターン

					path_memory[count].element.turn = 7;	//終わ�?135°ターンに変更
					displace_path(count + 1);	//�?個ずらす
					path_memory[count + 1].element.distance -= 1;//ターン後�?�直線距離�?90mm減ら�?
					naname_flag = FALSE;
					count++;	//配�?�を次へ

				} else {								//交互�?�ターン(ギザギザ)

					path_memory[count].element.distance += 1;	//斜めの直線距離�?1増や�?
					temp_distance = path_memory[count].element.distance;//距離を�?時的に持っておく
					displace_path(count);								//�?個ずらす
					path_memory[count].element.distance = temp_distance;//距離を�?�れなおす

				}

			} else {									//ま�?ま�?斜めは続くな�?

				if (path_memory[count].element.muki
						== path_memory[count + 1].element.muki) {//同じ方向�?�2回ターン	コの�?

					path_memory[count].element.turn = 8;		//斜め90°ターンに変更
					displace_path(count + 1);							//�?個ずらす
					count++;									//配�?�を次へ

				} else {							//違う方向�?�2回ターン	ギザギザ

					path_memory[count].element.distance += 1;	//斜めの直線距離�?1増や�?
					temp_distance = path_memory[count].element.distance;//距離を�?時的に持っておく
					displace_path(count);							//�?個ずらす
					path_memory[count].element.distance = temp_distance;//距離を�?�れなおす

				}
			}

		} else {										//斜めじゃなければ

			if (path_memory[count + 1].element.distance >= 1) {	//ターン後も90mm以上直進するな�?	大回りのチェ�?クを行う

				if ((count != 0) || (path_memory[0].element.distance > 1)) {//初っ端のターンじゃなければ

					path_memory[count].element.turn = 2;	//大回りターンに変更
					path_memory[count].element.distance -= 1;	//直線距離�?90mm減ら�?
					path_memory[count + 1].element.distance -= 1;//直線距離�?90mm減ら�?

				} else {
					//TODO 初っ端大回り90ターンの処�?
				}

			} else {								//ターン�?90mm直進はしな�?な�?

				if (path_memory[count].element.muki
						== path_memory[count + 1].element.muki) {//同じ方向に曲がるな�?(Uターン)

					if (path_memory[count + 2].element.distance >= 1) {	//Uターン�?90mm直進するな�?

						path_memory[count].element.turn = 3;	//180°ターンに変更
						path_memory[count].element.distance -= 1;//直線距離�?90mm減ら�?
						path_memory[count + 2].element.distance -= 1;//直線距離�?90mm減ら�?
						displace_path(count + 1);	//�?個ずらす

					} else {							//Uターン後すぐ曲がるな�?

						if (path_memory[count + 2].all != 0) {//pathが終わってな�?かチェ�?ク�?終わってなければ�?方向にターンのは�?

							path_memory[count].element.turn = 6;	//135°ターンに変更
							path_memory[count].element.distance -= 1;//直線距離�?90mm減ら�?
							displace_path(count + 1);					//�?個ずらす
							naname_flag = TRUE;

						}

					}

				} else {		//違う方法に曲がるな�?

					path_memory[count].element.turn = 4;		//45°ターンに変更
					path_memory[count].element.distance -= 1;	//直線距離�?90mm減ら�?
					naname_flag = TRUE;

				}

			}
			count++;		//配�?�を次へ
		}
	}

}

void path::create_path() {
	int8_t path_x, path_y;							//位置管�?用
	int8_t path_direction_x, path_direction_y;							//方向管�?用
	bool straight_flag;							//直線できるかど�?か判別用フラグ
	SAVE_DIRECTION save_direction;							//次に行くマスの方向を保�?
	uint16_t count = 0;							//数を数える�?け�?�変数

//set_step_for_shortest(GOAL_x,GOAL_y);

	spread_step(GOAL_x, GOAL_y, true);

	path_reset();

	path_direction_x = 0;							//方向を初期�?
	path_direction_y = 1;

	path_x = 0;							//位置を�?�期�?
	path_y = 0;

	straight_flag = false;							//フラグは折っておく

	path_memory[count].element.distance += 1;					//�?初�?��?ず半区画直進する
	path_memory[count].element.flag = TRUE;						//�?初だし続行フラグを建て�?

	while (1) {

		save_direction.all = 0;		//次に行く方向�?�期�?
		straight_flag = false;		//フラグは折っておく

		path_x += path_direction_x;		//位置修正
		path_y += path_direction_y;

		//GOALにたどり着�?たら終�?
		if ((path_x == GOAL_x) && (path_y == GOAL_y)) {
			path_memory[count].element.distance += 1;	//90mm直進を追�?	ゴールに入りきるた�?
			path_memory[count + 1].element.flag = FALSE;		//続行フラグを折っておく
			break;
		}

		//左
		if ((path_x - 1) >= 0) {	//path_x-1,path_yの座標が迷路�?(0以�?)である
			if (get_step(path_x - 1, path_y) < get_step(path_x, path_y)) {//歩数の小さ�?ほ�?へ
				if ((map::get_wall(path_x, path_y, MUKI_LEFT) == false)) {//壁がな�?な�?
					save_direction.element.left = 1;	//次に進�?方向�?�選択肢に追�?
					if ((path_direction_x == -1) && (path_direction_y == 0)) {//左を向�?てるとき（直進できるとき�?
						straight_flag = true;	//直進フラグをたて�?
					}
				}
			}

		}

		//右
		if ((path_x + 1) < MAZE_SIZE) {	//path_x+1,path_yの座標が迷路�?である
			if (get_step(path_x + 1, path_y) < get_step(path_x, path_y)) {//歩数の小さ�?ほ�?へ
				if ((map::get_wall(path_x, path_y, MUKI_RIGHT) == false)) {	//壁がな�?な�?
					save_direction.element.right = 1;	//次に進�?方向�?�選択肢に追�?
					if ((path_direction_x == 1) && (path_direction_y == 0)) {//右を向�?てるとき（直進できるとき�?
						straight_flag = true;	//直進フラグをたて�?
					}
				}
			}
		}

		//�?
		if ((path_y - 1) >= 0) {	//path_x,path_y-1の座標が迷路�?(0以�?)である
			if (get_step(path_x, path_y - 1) < get_step(path_x, path_y)) {//歩数の小さ�?ほ�?へ
				if ((map::get_wall(path_x, path_y, MUKI_DOWN) == false)) {//壁がな�?な�?
					save_direction.element.down = 1;	//次に進�?方向�?�選択肢に追�?
					if ((path_direction_x == 0) && (path_direction_y == -1)) {//下を向いてるとき（直進できるとき�?
						straight_flag = true;	//直進フラグをたて�?
					}
				}
			}
		}

		//�?
		if ((path_y + 1) < MAZE_SIZE) {	//path_x,path_y+1の座標が迷路�?(16以�?)である
			if (get_step(path_x, path_y + 1) < get_step(path_x, path_y)) {//歩数の小さ�?ほ�?へ
				if ((map::get_wall(path_x, path_y, MUKI_UP) == false)) {//壁がな�?な�?
					save_direction.element.up = 1;	//次に進�?方向�?�選択肢に追�?
					if ((path_direction_x == 0) && (path_direction_y == 1)) {//上を向いてるとき（直進できるとき�?
						straight_flag = true;	//直進フラグをたて�?
					}
				}
			}
		}

		if (straight_flag) {			//直進できるな�?
			path_memory[count].element.distance += 2;			//半区間直進*2 を追�?

		} else {								//ターンするな�?
			path_memory[count].element.turn = 1;						//小回りターン

			if (path_direction_x == 0) {				//上か下向き�?�と�?
				//右に行きたい
				if (save_direction.element.right == 1) {
					if (path_direction_y == 1) {	//上を向いて�?
						//右向きターン
						path_memory[count].element.muki = MUKI_RIGHT;
					} else {					//下を向いて�?
						//左向きターン
						path_memory[count].element.muki = MUKI_LEFT;
					}
					//左に行きたい
				} else {
					if (path_direction_y == -1) {	//下を向いて�?
						//右向きターン
						path_memory[count].element.muki = MUKI_RIGHT;
					} else {					//上を向いて�?
						//左向きターン
						path_memory[count].element.muki = MUKI_LEFT;
					}
				}

			} else {										//右か左向きのと�?
				//上に行きたい
				if (save_direction.element.up == 1) {
					if (path_direction_x == -1) {	//左を向�?て�?
						//右向きターン
						path_memory[count].element.muki = MUKI_RIGHT;
					} else {					//右を向�?て�?
						//左向きターン
						path_memory[count].element.muki = MUKI_LEFT;
					}
					//下に行きたい
				} else {
					if (path_direction_x == 1) {	//右を向�?て�?
						//右向きターン
						path_memory[count].element.muki = MUKI_RIGHT;
					} else {					//左を向�?て�?
						//左向きターン
						path_memory[count].element.muki = MUKI_LEFT;
					}
				}
			}
			//ターンによる方向修正
			direction_turn(&path_direction_x, &path_direction_y,
					path_memory[count].element.muki);

			count++;
			path_memory[count].element.flag = TRUE;			//パスが続くのなら続行フラグを建て�?

		}

	}

}

void path::create_path_advance() {
	create_path();
	improve_path();
}

void path::create_path_naname() {
	create_path();
	improve_advance_path();
}

void path::draw_path() {
	myprintf("path-start \n\r");

	for (int i = 0; path_memory[i].element.flag == TRUE; i++) {
		//直�?
		myprintf("distance -> %2d *", path_memory[i].element.distance);
		if (MOUSE_MODE == 1)								//ハ�?�フ�?�半区間が45mm
			myprintf("45mm\n\r");
		else
			myprintf("90mm\n\r");

		//ターン
		//myprintf("turn -> %2d ", path_memory[i].element.turn);	//格納して�?る�?�を表示
		myprintf("turn -> ");
		switch (path::get_path_turn_type(i)) {
		case none:
			myprintf("none");
			break;
		case small:
			myprintf("small");
			break;
		case big_90:
			myprintf("big_90");
			break;
		case big_180:
			myprintf("big_180");
			break;
		case begin_45:
			myprintf("begin_45");
			break;
		case end_45:
			myprintf("end_45");
			break;
		case begin_135:
			myprintf("begin_135");
			break;
		case end_135:
			myprintf("end_135");
			break;
		case oblique_90:
			myprintf("oblique_90");
			break;
		case spin_turn:
			myprintf("spin_turn");
			break;
		default:
			myprintf("error!! %d", path_memory[i].element.turn);
			break;
		}

		if (path_memory[i].element.muki == MUKI_RIGHT) {
			myprintf(" Right\n\r");
		} else if (path_memory[i].element.muki == MUKI_LEFT) {
			myprintf(" Left\n\r");
		}
	}
	myprintf("path-end \n\r");

}

void path::path_reset() {
	unsigned int reset_count;
	for (reset_count = 0; reset_count < PATH_MAX; reset_count++) {
		path_memory[reset_count].all = 0;
	}
}

bool path::get_path_flag(signed int index_number) {
//pathがあるならtrue,な�?ならfalseを返す
	if (path_memory[index_number].element.flag == TRUE) {
		return true;
	} else {
		return false;
	}

}

float path::get_path_straight(unsigned int index_number) {
	return (0.045 * MOUSE_MODE
			* (float) path_memory[index_number].element.distance);
}

SLALOM_TYPE path::get_path_turn_type(unsigned int index_number) {
	switch (path_memory[index_number].element.turn) {
	case 0:
		return none;
		break;

	case 1:
		return small;
		break;

	case 2:
		return big_90;
		break;

	case 3:
		return big_180;
		break;

	case 4:
		return begin_45;
		break;

	case 5:
		return end_45;
		break;

	case 6:
		return begin_135;
		break;

	case 7:
		return end_135;
		break;

	case 8:
		return oblique_90;
		break;
	}

	return spin_turn;
}

unsigned char path::get_path_turn_muki(unsigned int index_number) {
	return path_memory[index_number].element.muki;
}

bool path::set_path(uint16_t _index, PATH _path) {
	if (_index >= PATH_MAX)
		return false;

	path_memory[_index] = _path;
	return true;
}

void direction_turn(signed char *direction_x, signed char *direction_y,
		unsigned char direction_turn_muki) {
	signed char temp_direction_x = (*direction_x);	//他�?�場�?に保存しな�?と変換途中で参�?�する羽目にな�?
	signed char temp_direction_y = (*direction_y);
	if (direction_turn_muki == MUKI_LEFT) {
		*direction_x = (temp_direction_x) * 0 + (temp_direction_y) * (-1);//回転行�?��?�θ=90の計�?
		*direction_y = (temp_direction_x) * 1 + (temp_direction_y) * 0;	//回転行�?��?�θ=90の計�?
	} else {
		*direction_x = (temp_direction_x) * 0 + (temp_direction_y) * 1;	//回転行�?��?�θ=-90の計�?
		*direction_y = (temp_direction_x) * (-1) + (temp_direction_y) * 0;//回転行�?��?�θ=-90の計�?
	}

}

std::pair<int8_t, int8_t> compas_to_direction(compas tar) {
	//TODO 斜め
	std::pair<int8_t, int8_t> ans(0, 0);
	switch (tar) {
	case north:
		ans.second = 1;
		break;
	case south:
		ans.second = -1;
		break;
	case east:
		ans.first = 1;
		break;
	case west:
		ans.first = -1;
		break;
	default:
		mouse::error();
		myprintf(" Error! Not expected turn type at std::pair<int8_t, int8_t>compas_to_direction() \n\r");
		myprintf(" tar direction is [%d] \n\r", tar);
		ans.first = 0;
		ans.second = 0;
		break;
	}
	return ans;
}

compas direction_to_compas(std::pair<int8_t, int8_t> tar) {
	//TODO 斜め
	compas ans = north;
	switch (tar.first) {
	case 0:
		switch (tar.second) {
		case 0:
			ans = center;
			break;
		case 1:
			ans = north;
			break;
		case -1:
			ans = south;
			break;
		}
		break;
	case 1:
		ans = east;
		break;
	case -1:
		ans = west;
		break;
	}
	return ans;
}

uint16_t node_step::step[x_size][y_size];

bool node_step::able_set_step(uint8_t double_x, uint8_t y, compas muki,
		uint16_t step_val, bool by_known) {
	uint8_t def_muki = compas_to_muki(muki);

//見て�?な�?部�?には書き込めな�?
	if (by_known) {
		if (!map::check_exist(double_x / 2, y, def_muki))
			return false;
	}

//配�?��?�要�?外なら何もしな�?
	if (is_outside_array(double_x, y))
		return false;

//壁がある部�?には書き込めな�?
	if (map::get_wall(double_x / 2, y, def_muki))
		return false;

//書き込�?歩数より小さ�?場�?には書き込めな�?
	if (step[double_x][y] <= step_val)
		return false;

	return true;
}

bool node_step::is_outside_array(uint8_t x_index, uint8_t y_index) {
	if (x_index >= x_size)
		return true;
	if (x_index < 0)
		return true;
	if (y_index >= y_size)
		return true;
	if (y_index < 0)
		return true;

	return false;
}

bool node_step::set_step(uint8_t x, uint8_t y, compas muki, uint16_t step_val,
		bool by_known) {
//代入用の変数
	uint8_t step_x = x;
	uint8_t step_y = y;

	switch (muki) {
	//南向きと西向きに変更して�?りなおし
	case north:
		step_y++;	//y�?1つ増やして南向き扱�?に
		step_x = 2 * x + 1;	//南向きだと横向きの壁なので、x方向が2x+1
		break;
	case south:
		step_x = 2 * x + 1;	//南向きだと横向きの壁なので、x方向が2x+1
		break;
	case east:
		step_x = 2 * (x + 1);	//x�?1つ増やして、西向き扱�?�?縦向きの壁なので、x方向�?�2x
		break;
	case west:
		step_x = 2 * x;	//西向き�?と縦向きの壁なので、x方向�?�2x
		break;

	default:		//斜めは非対�?
		return false;
	}

//書き込めるな�?
	if (able_set_step(step_x, step_y, muki, step_val, by_known)) {
		step[step_x][step_y] = step_val;	//配�?�に歩数代入
		return true;
	}

	return false;
}

bool node_step::set_step_double(uint8_t _double_x, uint8_t _double_y,
		uint16_t step_val, bool by_known) {
	//代入用の変数
	uint8_t step_x = _double_x;
	uint8_t step_y = static_cast<uint8_t>(_double_y / 2);

	compas muki = south;
	if (step_x % 2 == 0)
		muki = west;

	//書き込めるな�?
	if (able_set_step(step_x, step_y, muki, step_val, by_known)) {
		step[step_x][step_y] = step_val;	//配�?�に歩数代入
		return true;
	}
	return false;

}

uint16_t node_step::get_step(uint8_t x, uint8_t y, compas muki) {
//代入用の変数
	uint8_t step_x = x;
	uint8_t step_y = y;

	switch (muki) {
//南向きと西向きに変更して�?りなおして終�?
	case north:
		step_y++;	//1つ増やして南向き扱�?に�?
		step_x = 2 * x + 1;	//南向きだと横向きの壁なので、x方向が2x+1
		break;
	case south:
		step_x = 2 * x + 1;	//南向きだと横向きの壁なので、x方向が2x+1
		break;
	case east:
		step_x = 2 * (x + 1);	//1つ増やして西向き扱�?に。縦向きの壁なので、x方向�?�2x
		break;
	case west:
		step_x = 2 * x;	//西向き�?と縦向きの壁なので、x方向�?�2x
		break;
	default:	//斜めは非対�?
		return init_step;
		break;
	}

//配�?��?�要�?外を読み�?すとき�?�Init_step�?
	if (is_outside_array(step_x, step_y))
		return init_step;

	return step[step_x][step_y];	//配�?�から歩数参�?�
}

uint16_t node_step::get_step_double(uint8_t double_x, uint8_t double_y) {
	//代入用の変数
	uint8_t step_x = double_x;
	uint8_t step_y = double_y / 2;

	//配�?��?�要�?外を読み�?すとき�?�Init_step�?
	if (is_outside_array(step_x, step_y))
		return init_step;

	return step[step_x][step_y];	//配�?�から歩数参�?�

}

compas node_step::get_min_compas(uint8_t x, uint8_t y) {
	compas ans;

	if (get_step(x, y, north) < get_step(x, y, south))
		ans = north;
	else
		ans = south;
	if (get_step(x, y, east) < get_step(x, y, ans))
		ans = east;
	if (get_step(x, y, west) < get_step(x, y, ans))
		ans = west;

	return ans;
}

void node_step::reset_step(uint16_t reset_val) {
	for (int x = 0; x < x_size; x++) {
		for (int y = 0; y < y_size; y++) {
			step[x][y] = reset_val;
		}
	}

}

void node_step::draw_step() {
	signed char tekitou_x = 0, tekitou_y = MAZE_SIZE - 1;

	myprintf("\n-----start draw_step-------\n\r");

	for (tekitou_y = MAZE_SIZE - 1; tekitou_y >= 0; tekitou_y--) {
		//////////////////////////////////////////迷路の壁�?��?
		for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++) {
			myprintf("+");	//柱
			if (get_wall(tekitou_x, tekitou_y, MUKI_UP)) {	//壁があるな�?
				myprintf("---");
			} else {
				if (get_step(tekitou_x, tekitou_y, north) == init_step)
					myprintf("   ");	//初期値なら空白に
				else
					myprintf("%3d", get_step(tekitou_x, tekitou_y, north));	//なければ歩数を書�?
			}
		}
		myprintf("+\n\r");

		/////////////////////////////////////////迷路のマス目の�?
		myprintf("| ");	//左端の�?
		for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++) {
			myprintf(" ");		//区画中�?のスペ�?�ス
			if (get_wall(tekitou_x, tekitou_y, MUKI_RIGHT)) {//今書�?た�?�スの右の壁があれば壁を書�?
				myprintf(" | ");
			} else {
				if (get_step(tekitou_x, tekitou_y, east) == init_step)
					myprintf("   ");	//初期値なら空白に
				else
					myprintf("%3d", get_step(tekitou_x, tekitou_y, east));//なければ歩数を書�?
			}
		}
		myprintf("\n\r");
	}

//下辺	迷路の端は壁しかな�?は�?
	for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++)
		myprintf("+---");
	myprintf("+\n\r");

}

node_step::node_step() {
	reset_step(init_step);
}

node_step::node_step(uint16_t reset_val) {
	reset_step(reset_val);
}

node_step::~node_step() {

}

void node_search::set_weight_algo(weight_algo weight) {
	static const std::vector<uint8_t> temp_s { 21, 20, 19, 18, 17, 16, 9, 4 }; //直進方向�?�重みづ�?
	static const std::vector<uint8_t> temp_o { 15, 14, 13, 12, 11, 10, 9, 4 }; //斜め方向�?�重みづ�?
	static const std::vector<uint8_t> temp_c { 0, 10, 14 }; //カーブに関する重みづけ�??0°,45°,90°の�?番

	algo = weight;

	switch (get_weight_algo()) {
	case weight_algo::adachi:
		//斜めも直進も重みは1
		std::vector<uint8_t>().swap(straight_w);
		straight_w.emplace_back(1);
		std::vector<uint8_t>().swap(oblique_w);
		oblique_w.emplace_back(1);
		curve_w = std::vector<uint8_t> { 0, 0, 0 };
		break;

	case weight_algo::based_distance:
		//斜めと直進は1:�?2の重み
		std::vector<uint8_t>().swap(straight_w);
		straight_w.emplace_back(7);
		std::vector<uint8_t>().swap(oblique_w);
		oblique_w.emplace_back(5);
		curve_w = std::vector<uint8_t> { 0, 0, 0 };
		break;

	case weight_algo::priority_straight:
		straight_w = (temp_s);	//staright_wに代入
		oblique_w = (temp_o);	//oblique_wに代入
		curve_w = std::vector<uint8_t> { 0, 0, 0 };
		break;

	case weight_algo::T_Wataru_method:		//斜めにも重みがあ�?
		straight_w = (temp_s);		//staright_wに代入
		oblique_w = (temp_o);		//oblique_wに代入
		curve_w = temp_c;
		break;

	}

}

weight_algo node_search::get_weight_algo() {
	return algo;
}

void node_search::spread_step(std::vector<std::pair<uint8_t, uint8_t> > finish,
		bool by_known) {
	bool debranch = false;	//枝�??するか否�?

//座標管�?は歩数の配�??(X方向だけ�??)と異なりX,Y方向両方で倍にする�?隣接座標�?�取り扱�?が楽�?から
	union _dir {
		int8_t xy;
		struct {
			int8_t x :4;
			int8_t y :4;
		};

		void set(int8_t _x, int8_t _y) {
			x = _x;
			y = _y;
		}
	} dir;			//方向管�?用�?int8_tでxy両方管�?したかっ�?

	union _dir temp_dir;

	my_queue x_queue;		//座標管�?用Queue
	my_queue y_queue;		//座標管�?用Queue
	my_queue dir_queue;		//方向管�?用Queue
	uint8_t x, y;		//2倍座�?

	//マウスの�?る座�?
	uint8_t mouse_x = mouse::get_x_position();
	uint8_t mouse_y = mouse::get_y_position();
	uint16_t mouse_step = get_step(mouse_x, mouse_y,
			get_min_compas(mouse_x, mouse_y));

//歩数をリセ�?�?
	node_step::reset_step(init_step);

//目標座標を�?初にキューにぶち込�?
	for (uint16_t index = 0; index < finish.size(); index++) {
		for (int i = -1; i < 2; i += 2) {
			x = 2 * finish.at(index).first + 1;
			y = 2 * finish.at(index).second + 1;
			if (set_step_double(x + i, y, 0, by_known)) {
				x_queue.push(x + i);
				y_queue.push(y);
				dir.set(i, 0);
				dir_queue.push(dir.xy);
				//方向も記録
			}
			if (set_step_double(x, y + i, 0, by_known)) {
				x_queue.push(x);
				y_queue.push(y + i);
				dir.set(0, i);
				dir_queue.push(dir.xy);
				//方向も記録
			}
		}
	}

	uint16_t next_step = 0;	//次の歩数
	int8_t dx, dy;	//次に行く方�?
	int8_t curve_index;	//ターンの種類を判別する

//直進する歩数の重みを管�?
	uint8_t straight;
	loop = 0;
	while (x_queue.size() != 0) {
		loop++;

		//キューから座標を取り出�?
		x = x_queue.pop();	//取り出して削除
		y = y_queue.pop();	//取り出して削除
		next_step = get_step_double(x, y);
		mouse_step = get_step(mouse_x, mouse_y,
				get_min_compas(mouse_x, mouse_y));

		//キューから方向を取り出�?
		dir.xy = dir_queue.pop();	//取り出して削除

		//現在のマスより歩数が大きくなるなら枝�?り�??by_known=trueつまりパス生�?�時には行わな�?�?バグ怖いから
		if (debranch && (next_step > mouse_step)) {
			//何もしな�?
		} else {
			temp_dir.xy = dir.xy;
			for (int n = -1; n <= 1; n++) {
				next_step = get_step_double(x, y);
				//次に行く方向�?�3パターンしか見な�?�?区画中�?より今�?�方向�?�にある3種�?ex.now(1,1)ならdx>0の(1,1)(2,0)(-1,0)
				//つまるところ、ここ�?�歩数にたどり着く直前で候補にあったやつら�?�、その時に行ったほ�?が早�?に決まってる�?�で無�?
				temp_dir = dir;
				if (!(x % 2)) {		//縦壁�?��?
					dx = (2 - ABS(n)) * SIGN(dir.x);
					dy = n;
					curve_index = ABS(dir.y - dy);		//0が直進�?1�?45°�?2�?90°
					temp_dir.y = n;
				} else {			//縦でなければ横?�?y%2==0?��しかな�?
					dx = n;
					dy = (2 - ABS(n)) * SIGN(dir.y);
					curve_index = ABS(dir.x - dx);			//0が直進�?1�?45°�?2�?90°
					temp_dir.x = n;
				}
				next_step += curve_w.at(curve_index);	//カーブすることに対する重みを足�?

//そ�?�直線方向に、書き込めなくなるまで書き込んで�?�?
				for (uint8_t i = 0;; i++) {
//直線が続くと足して�?く歩数は小さくなって�?�?
					if (n == 0) {		//区画を横�?ると�?
						if (i < straight_w.size())
							straight = straight_w.at(i);//要�?外に出る�?�合�?�値を更新しな�?��最後�?�値が続く
					} else {			//斜め方向�?�直進のと�?
						if (i < oblique_w.size())
							straight = oblique_w.at(i);	//要�?外に出る�?�合�?�値を更新しな�?��最後�?�値が続く
					}
//歩数を書き込めたら�?�書き込んだ座標をQueueにぶっこ�?
					if (set_step_double(x + dx * (i + 1), y + dy * (i + 1),
							(next_step + straight), by_known)) {
						next_step += straight;		//ス�?�?プを更新
						x_queue.push(x + (i + 1) * dx);
						y_queue.push(y + (i + 1) * dy);
						dir_queue.push(temp_dir.xy);
					} else {
						break;	//書き込めなくなったらループを抜け�?
					}
//直線が続くことによる重みの減少がな�?なら�?回だけで抜け�?
					if (algo == adachi || algo == based_distance) {
						break;
					}
//枝�??�?
					if (debranch && (next_step > mouse_step)) {
						break;
					}
				}

			}
		}
	}

}

bool node_search::create_small_path(
		std::vector<std::pair<uint8_t, uint8_t> > finish,
		std::pair<uint8_t, uint8_t> init, compas mouse_direction) {
//歩数マップ作製
	node_step::reset_step(init_step);
	spread_step(finish, true);	//ここは既知壁だけで歩数マップ作製
	return node_path::create_path(init, mouse_direction);	//歩数マップに従ってパス作製

}

bool node_search::create_big_path(
		std::vector<std::pair<uint8_t, uint8_t> > finish,
		std::pair<uint8_t, uint8_t> init, compas mouse_direction) {
	if (create_small_path(finish, init, mouse_direction)) {	//小回りパス作製
		node_path::improve_path();	//小回りを大回りパスに改良
		return true;
	}
	return false;
}

void node_search::reset_finish() {
//目�?地�?報をすべてリセ�?�?
	for (int i = 0; i < MAZE_SIZE; i++) {
		x_finish[i].all = 0;
		y_finish[i].all = 0;
	}
}

void node_search::set_finish_cell(uint8_t _x, uint8_t _y) {
	set_finish(_x, _y, north);
	set_finish(_x, _y, south);
	set_finish(_x, _y, east);
	set_finish(_x, _y, west);
}

void node_search::set_finish(uint8_t _x, uint8_t _y, compas dir) {
	uint8_t set_x = _x;
	uint8_t set_y = _y;

	if (dir == east) {
		if (set_x == 0)		//�?番左は常に外壁なので無�?
			return;
		else
			set_x--;		//�?ず右を更新
	}
	if (dir == east || dir == west) {
		if (set_x < MAZE_SIZE)
			set_maze_wall(&x_finish[set_y], set_x, true);//x_finish[y]のx番目の右区画中�?
		return;
	}

	if (dir == south) {
		if (set_y == 0) 		//�?番下壁�?�管�?しな�?
			return;
		else
			set_y--;	//�?ず上壁を更新するように、座標を変え�?

	}
	if (dir == south || dir == north) {
		if (set_y < MAZE_SIZE)
			set_maze_wall(&y_finish[set_x], set_y, true);//x_maze_wall[y]のx番目の右壁に1を代入
		return;
	}

}

bool node_search::get_finish(uint8_t _x, uint8_t _y, compas dir) {
	uint8_t get_x = _x;
	uint8_t get_y = _y;

	if (dir == east) {
		if (get_x == 0)		//�?番左は常に外壁なので無�?
			return false;	//壁なのでゴール座標としては不適
		else
			get_x--;		//�?ず右を更新
	}
	if (dir == east || dir == west) {
		if (get_x < MAZE_SIZE)
			return get_maze_wall(x_finish[get_y], get_x);//x_finish[y]のx番目の右区画中�?
	}

	if (dir == south) {
		if (get_y == 0) 		//�?番下壁�?�管�?しな�?
			return false;
		else
			get_y--;	//�?ず上壁を更新するように、座標を変え�?

	}
	if (dir == south || dir == north) {
		if (get_y < MAZE_SIZE)
			return get_maze_wall(y_finish[get_x], get_y);//x_maze_wall[y]のx番目の右壁に1を代入
	}

	return false;

}

node_search::node_search() {
	set_weight_algo(weight_algo::adachi);
	reset_finish();

}

node_search::node_search(uint16_t init_step) {
	node_step::reset_step(init_step);
	set_weight_algo(weight_algo::adachi);
	reset_finish();
}

node_search::~node_search() {
}

std::vector<path_element> node_path::path;

PATH node_path::to_PATH(path_element from) {
	PATH ans;

	ans.element.flag = TRUE;
	ans.element.distance = from.distance;

	if (from.is_right)
		ans.element.muki = MUKI_RIGHT;
	else
		ans.element.muki = MUKI_LEFT;

	switch (from.turn) {
	case none:
		ans.element.turn = from.turn;
		break;

	case small:
	case big_90:
	case big_180:
		ans.element.turn = from.turn;
		break;

	case begin_45:
	case end_45:
		ans.element.turn = 4;
		break;

	case begin_135:
	case end_135:
		ans.element.turn = 5;
		break;

	case oblique_90:
		ans.element.turn = 6;
		break;

	default:
		mouse::error();
		myprintf(" Error! Not expected turn type at to_PATH() \n\r");
		myprintf(" turn type is [%d] \n\r", from.turn);
		break;
	}

	return ans;

}

bool node_path::is_right_turn(compas now, compas next) {
	bool ans;

	switch ( now ) {
	case north:
		if ( next == east ){
			ans = true;
		} else {
			ans = false;
		}
		break;

	case south:
		if (next == west){
			ans = true;
		} else {
			ans = false;
		}
		break;

	case east:
		if (next == south){
			ans = true;
		} else {
			ans = false;
		}
		break;

	case west:
		if (next == north){
			ans = true;
		} else {
			ans = false;
		}
		break;

	default:
		ans = false;
		mouse::error();
		myprintf(" Error! Not expected turn type at is_right_turn() \n\r");
		myprintf(" now direction is [%d] \n\r", now);
		break;
	}
	return ans;
}

void node_path::format() {
	//distance=0, sla_type=none, is_right=true�?�?1つ�?け用意し、それでpathを�?�期�?
	std::vector<path_element>().swap(path);
	path_element init = { 0, none, true };
	path.emplace_back(init);
}

void node_path::push_straight(int half) {
	(path.back()).distance += half;	//直線を増や�?
}

void node_path::push_small_turn(bool is_right) {
	(path.back()).turn = small;		//種類�?�小回�?
	(path.back()).is_right = is_right;		//右向き

	path_element temp = { 0, none, true };
	path.emplace_back(temp);		//次の要�?を作っておく

}

bool node_path::create_path(std::pair<uint8_t, uint8_t> init,
		compas mouse_direction) {
	node_path::format();				//パスを�?�期�?
	node_path::push_straight(1);				//区画中�?に�?る想定なので半区間前進

//向かって�?る方向�?�歩数が�?�期値なら�??道が閉じて�?る�?�で終�?
	uint16_t now_step = get_step(init.first, init.second, mouse_direction);
	if (now_step >= init_step)
		return false;

//歩数の低い方へ下って�?�?
	compas now_compas = mouse_direction;
	uint8_t now_x = init.first;
	uint8_t now_y = init.second;
	int8_t dx, dy;
	uint16_t next_step = now_step;
	compas next_compas = now_compas;
	while (now_step != 0) {

		//次の方角へマスを移動�??※区画外に出るとか�?�、歩数マップ作�?�時にはじかれてる�?�ずと信じて�?�?
		switch (next_compas) {
		case north:
			//now_y += 1;
			dx = 0;
			dy = 1;
			break;
		case south:
			//now_y -= 1;
			dx = 0;
			dy = -1;
			break;
		case east:
			//now_x += 1;
			dx = 1;
			dy = 0;
			break;
		case west:
			//now_x -= 1;
			dx = -1;
			dy = 0;
			break;
		default:	//斜めは予期せぬエラー
			return false;
			break;
		}
		now_x += dx;		//X座標更新
		now_y += dy;		//Y座標更新

		next_compas = get_min_compas(now_x, now_y);		//次に行く方角を決める
		next_step = get_step(now_x, now_y, next_compas);		//次に行く場�?の歩数も取�?

		if (now_step <= next_step)
			return false;	//今�?�歩数が次行くべき歩数と同じかそれ以下と�?�?ことはあり得な�?はずなので、とりあえず失敗しと�?

		//パスを追�?
		if (now_compas == next_compas)
			node_path::push_straight(2);		//今�?�向きと同じ方向に進�?なら直進
		else
			node_path::push_small_turn(is_right_turn(now_compas, next_compas));	//ターン以外�?�選択肢はな�?は�?

		now_step = next_step;		//歩数を更新
		now_compas = next_compas;		//方角を更新

	}

//次の方角�?�変化方向を取�?
	switch (next_compas) {
	case north:
		//now_y += 1;
		dx = 0;
		dy = 1;
		break;
	case south:
		//now_y -= 1;
		dx = 0;
		dy = -1;
		break;
	case east:
		//now_x += 1;
		dx = 1;
		dy = 0;
		break;
	case west:
		//now_x -= 1;
		dx = -1;
		dy = 0;
		break;
	default:	//斜めになる�?�は予期せぬ場合だ�?
		return false;
		break;
	}

//�?数マスゴールの場合用に�?0の続く限り直進
	while (1) {
		now_x += dx;		//X座標更新
		now_y += dy;		//Y座標更新

		if (get_step(now_x, now_y, next_compas) != 0) {	//ゴール外に出たら
			break;
		} else {									//ゴール区画がま�?続くな�?
			node_path::push_straight(2);
		}

	}
	node_path::push_straight(1);		//区画に入りきるために半区画直進して終�?

	mouse::set_position(now_x, now_y);

	return true;

}

void node_path::improve_path() {

	uint16_t count = 0;
	uint8_t temp_distance = 0;	//�?時的な距離保�?
	bool naname_flag = false;	//現在機体が斜めかを判断	ONなら斜め走行中
	uint16_t size = path.size();

	path.at(size - 1).distance -= 1;//�?後�?�区画の中�?まで入り込�?ための半区間直進を消す。�??こうしておかな�?と�?後が大回りに丸め込まれて減�?�できなくなる可能性があるか�?

	while (count < path.size()) {		//pathが終われ�?�終�?
		if (naname_flag) {		//斜め走行中な�?	確実に直進距離(distance)�?0のは�?

			if (get_path(count + 1).element.distance >= 1) {//次のターン�?90mm以上直進(斜め終わ�?)
				path.at(count).turn = end_45;		//45°ターンに変更
				path.at(count + 1).distance -= 1;		//直線距離�?90mm減ら�?
				naname_flag = false;
				count++;		//配�?�を次へ

			} else if (get_path(count + 2).element.distance >= 1) {	//次の次のターン�?90mm以上直進(斜め終わ�?)

				if (path.at(count).is_right == path.at(count + 1).is_right) {//同じ方向�?�2回ターン
					path.at(count).turn = end_135;	//135°ターンに変更
					path.erase(path.begin() + count + 1);	//�?個ずらす
					path.at(count + 1).distance -= 1;	//ターン後�?�直線距離�?90mm減ら�?
					naname_flag = false;
					count++;	//配�?�を次へ

				} else {								//交互�?�ターン(ギザギザ)
					path.at(count).distance += 1;				//斜めの直線距離�?1増や�?
					temp_distance = path.at(count).distance;	//距離を�?時的に持っておく
					path.erase(path.begin() + count);					//�?個ずらす
					path.at(count).distance = temp_distance;		//距離を�?�れなおす

				}

			} else {									//ま�?ま�?斜めは続くな�?
				if (count + 1 < size) {		//次のパスが存在する
					if (path.at(count + 1).turn == none) {
						//斜めの大回りで終わるパターン
						temp_distance = path.at(count).distance;//距離を�?時的に持っておく
						path.erase(path.begin() + count);		//�?個ずらす
						path.at(count).distance = temp_distance;//距離を�?�れなおす						count++;
						naname_flag = false;
					} else {
						if (path.at(count).is_right
								== path.at(count + 1).is_right) {//同じ方向�?�2回ターン	コの�?
							path.at(count).turn = oblique_90;	//斜め90°ターンに変更
							path.erase(path.begin() + count + 1);		//�?個ずらす
							count++;		//配�?�を次へ
						} else {					//違う方向�?�2回ターン	ギザギザ
							path.at(count).distance += 1;		//斜めの直線距離�?1増や�?
							temp_distance = path.at(count).distance;//距離を�?時的に持っておく
							path.erase(path.begin() + count);			//�?個ずらす
							path.at(count).distance = temp_distance;//距離を�?�れなおす

						}
					}
				} else {			//TODO 斜めのままパスが終�?する�?とりあえず入りきらずに終�?する
//FIX_ME 斜めのまま終�?するとき�?�処�?
					path.at(count).distance += 1;				//斜めの直線距離�?1増や�?
					path.at(count).turn = none;
					count = size;							//終�?
				}
			}

		} else {										//斜めじゃなければ

			if (count + 1 < size) {	//count+1でもパスが終わらな�?な�?

				if (path.at(count + 1).distance >= 1) {	//ターン後も90mm以上直進するな�?	大回りのチェ�?クを行う
					path.at(count).turn = big_90;	//大回りターンに変更
					path.at(count).distance -= 1;	//直線距離�?90mm減ら�?
					path.at(count + 1).distance -= 1;	//直線距離�?90mm減ら�?

				} else {							//ターン�?90mm直進はしな�?な�?

					if (path.at(count).is_right
							== path.at(count + 1).is_right) {//同じ方向に曲がるな�?(Uターン)
						if (count + 2 < size) {		//2つ先までパスが存在するな�?
							if (path.at(count + 2).distance >= 1) {	//Uターン�?90mm直進するな�?
								path.at(count).turn = big_180;	//180°ターンに変更
								path.at(count).distance -= 1;	//直線距離�?90mm減ら�?
								path.at(count + 2).distance -= 1;//直線距離�?90mm減ら�?
								path.erase(path.begin() + count + 1);	//�?個ずらす

							} else {					//Uターン後すぐ曲がるな�?
								path.at(count).turn = begin_135;	//135°ターンに変更
								path.at(count).distance -= 1;	//直線距離�?90mm減ら�?
								path.erase(path.begin() + count + 1);	//�?個ずらす
								naname_flag = true;

							}

						}
					} else {		//違う方法に曲がるな�?
						path.at(count).turn = begin_45;		//45°ターンに変更
						path.at(count).distance -= 1;		//直線距離�?90mm減ら�?
						naname_flag = true;

					}

				}
			}
			count++;		//配�?�を次へ
		}

		size = path.size();		//sizeを更新

	}

//�?初に1つ削ったから忘れず足しておく
	if (naname_flag)
		path.at(size - 1).distance -= 1;
	else
		path.at(size - 1).distance += 1;

}

PATH node_path::get_path(uint16_t index) {
	if (index >= path.size()) {		//要�?外アクセス禁止
		path_element temp = { 0, none, true };
		PATH ans = to_PATH(temp);
		ans.element.flag = FALSE;
		return ans;
	}
	path_element tar = path.at(index);
	if ((tar.distance == 0) && (tar.turn == none)) {
//path.erase(path.begin() + index);		//直進なしかつターンなし�?�場合（起こり�?る�?�は末尾�?け�?�はず）いらな�?ので削除
		return get_path(index + 1);
	}
	return to_PATH(tar);

}

node_path::node_path() {
	format();
}

node_path::~node_path() {

}

void node_path::convert_path() {
	path::path_reset();
	for (int i = 0; i < PATH_MAX; i++) {
		path::set_path(i, get_path(i));
	}

}
