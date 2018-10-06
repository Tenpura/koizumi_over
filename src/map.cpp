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

//target_wall縺ｮedit_number逶ｮ縺ｫset_number繧剃ｻ｣蜈･縺吶ｋ髢｢謨ｰ
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
	unsigned char maze_check = 0;		//蜈ェALSE

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

	//x蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//荳�逡ｪ蟾ｦ螢√�ｯ邂｡逅�縺励↑縺�
				return;
			} else {
				set_x = wall_x - 1;	//蠢�縺壼承螢√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (set_x < MAZE_SIZE) {
			set_maze_wall(&x_wall_exist[set_y], set_x, true);//x_maze_wall[y]縺ｮx逡ｪ逶ｮ縺ｮ蜿ｳ螢√↓1繧剃ｻ｣蜈･
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺з蠎ｧ讓吶↓螢√�ｮ蟄伜惠繧剃ｽ懊ｍ縺�縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("remember_exist髢｢謨ｰ蜀�\n\r");
		}

		//y蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//荳�逡ｪ荳句｣√�ｯ邂｡逅�縺励↑縺�
				return;
			} else {
				set_y = wall_y - 1;	//蠢�縺壻ｸ雁｣√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (set_y < MAZE_SIZE) {
			set_maze_wall(&y_wall_exist[set_x], set_y, true);//x_maze_wall[y]縺ｮx逡ｪ逶ｮ縺ｮ蜿ｳ螢√↓1繧剃ｻ｣蜈･
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺и蠎ｧ讓吶↓螢√�ｮ蟄伜惠繧剃ｽ懊ｍ縺�縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("remember_exist髢｢謨ｰ蜀�\n\r");
		}

	}

}
void map::forget_exist(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char set_x = wall_x, set_y = wall_y;

	//x蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//荳�逡ｪ蟾ｦ螢√�ｯ邂｡逅�縺励↑縺�
				return;
			} else {
				set_x = wall_x - 1;	//蠢�縺壼承螢√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (set_x < MAZE_SIZE) {
			set_maze_wall(&x_wall_exist[set_y], set_x, false);//x_maze_wall[y]縺ｮx逡ｪ逶ｮ縺ｮ蜿ｳ螢√↓false繧剃ｻ｣蜈･
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺з蠎ｧ讓吶�ｮ螢√�ｮ蟄伜惠繧呈ｶ医◎縺�縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("forget_exist髢｢謨ｰ蜀�\n\r");
		}

		//y蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//荳�逡ｪ荳句｣√�ｯ邂｡逅�縺励↑縺�
				return;
			} else {
				set_y = wall_y - 1;	//蠢�縺壻ｸ雁｣√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (set_y < MAZE_SIZE) {
			set_maze_wall(&y_wall_exist[set_x], set_y, false);//x_maze_wall[y]縺ｮx逡ｪ逶ｮ縺ｮ荳雁｣√↓1false莉｣蜈･
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺и蠎ｧ讓吶�ｮ螢√�ｮ蟄伜惠繧呈ｶ医◎縺�縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("forget_exist髢｢謨ｰ蜀�\n\r");
		}

	}

}
bool map::check_exist(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char target_x = wall_x, target_y = wall_y;

	//x蠎ｧ讓呎婿蜷代ｒ隕九ｋ縺吶ｋ縺ｨ縺�
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//荳�逡ｪ蟾ｦ螢√�ｯ邂｡逅�縺励↑縺�
				return true;
			} else {
				target_x = wall_x - 1;	//蠢�縺壼承螢√ｒ隕九ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (target_x < MAZE_SIZE) {
			return get_maze_wall(x_wall_exist[target_y], target_x);
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺з蠎ｧ讓吶�ｮ螢√�ｮ蟄伜惠繧定ｪｭ繧ゅ≧縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("check_exist髢｢謨ｰ蜀�\n\r");
			return false;
		}

		//y蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//荳�逡ｪ荳句｣√�ｯ蟶ｸ縺ｫ螢√′蟄伜惠
				return true;
			} else {
				target_y = wall_y - 1;	//蠢�縺壻ｸ雁｣√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (target_y < MAZE_SIZE) {
			return get_maze_wall(y_wall_exist[target_x], target_y);
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺и蠎ｧ讓吶�ｮ螢√�ｮ蟄伜惠繧定ｪｭ繧ゅ≧縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("check_exist髢｢謨ｰ蜀�\n\r");
			return false;
		}
	}

	return false;
}

bool map::check_exist(unsigned char wall_x, unsigned char wall_y, compas dir) {
	unsigned char target_x = wall_x, target_y = wall_y;

	//x蠎ｧ讓呎婿蜷代ｒ隕九ｋ縺吶ｋ縺ｨ縺�
	if ((dir == east) || (dir == west)) {
		if (dir == west) {
			if (wall_x == 0) {		//荳�逡ｪ隘ｿ螢√�ｯ邂｡逅�縺励↑縺�
				return true;
			} else {
				target_x = wall_x - 1;	//蠢�縺壽擲螢√ｒ隕九ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (target_x < MAZE_SIZE) {
			return get_maze_wall(x_wall_exist[target_y], target_x);
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺з蠎ｧ讓吶�ｮ螢√�ｮ蟄伜惠繧定ｪｭ繧ゅ≧縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("check_exist髢｢謨ｰ蜀�\n\r");
			return false;
		}

		//y蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	} else if ((dir == north) || (dir == south)) {
		if (dir == south) {
			if (wall_y == 0) {		//荳�逡ｪ蜊怜｣√�ｯ蟶ｸ縺ｫ螢√′蟄伜惠
				return true;
			} else {
				target_y = wall_y - 1;	//蠢�縺壼圏螢√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (target_y < MAZE_SIZE) {
			return get_maze_wall(y_wall_exist[target_x], target_y);
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺и蠎ｧ讓吶�ｮ螢√�ｮ蟄伜惠繧定ｪｭ繧ゅ≧縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("check_exist髢｢謨ｰ蜀�\n\r");
			return false;
		}
	}

	return false;
}

void map::create_wall(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char set_x = wall_x, set_y = wall_y;

	//x蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//荳�逡ｪ蟾ｦ螢√�ｯ邂｡逅�縺励↑縺�
				return;
			} else {
				set_x = wall_x - 1;	//蠢�縺壼承螢√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (set_x < MAZE_SIZE) {
			set_maze_wall(&x_maze_wall[set_y], set_x, true);//x_maze_wall[y]縺ｮx逡ｪ逶ｮ縺ｮ蜿ｳ螢√↓1繧剃ｻ｣蜈･
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺з蠎ｧ讓吶↓螢√ｒ菴懊ｍ縺�縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("create_wall髢｢謨ｰ蜀�\n\r");
		}

		//y蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//荳�逡ｪ荳句｣√�ｯ邂｡逅�縺励↑縺�
				return;
			} else {
				set_y = wall_y - 1;	//蠢�縺壻ｸ雁｣√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (set_y < MAZE_SIZE) {
			set_maze_wall(&y_maze_wall[set_x], set_y, true);//x_maze_wall[y]縺ｮx逡ｪ逶ｮ縺ｮ蜿ｳ螢√↓1繧剃ｻ｣蜈･
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺и蠎ｧ讓吶↓螢√ｒ菴懊ｍ縺�縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("create_wall髢｢謨ｰ蜀�\n\r");
		}

	}

}
void map::destroy_wall(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char set_x = wall_x, set_y = wall_y;

	//x蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//荳�逡ｪ蟾ｦ螢√�ｯ邂｡逅�縺励↑縺�
				return;
			} else {
				set_x = wall_x - 1;	//蠢�縺壼承螢√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (set_x < MAZE_SIZE) {
			set_maze_wall(&x_maze_wall[set_y], set_x, false);//x_maze_wall[y]縺ｮx逡ｪ逶ｮ縺ｮ蜿ｳ螢√↓false繧剃ｻ｣蜈･
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺з蠎ｧ讓吶�ｮ螢√ｒ螢翫◎縺�縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("destroy_wall髢｢謨ｰ蜀�\n\r");
		}

		//y蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//荳�逡ｪ荳句｣√�ｯ邂｡逅�縺励↑縺�
				return;
			} else {
				set_y = wall_y - 1;	//蠢�縺壻ｸ雁｣√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (set_y < MAZE_SIZE) {
			set_maze_wall(&y_maze_wall[set_x], set_y, false);//x_maze_wall[y]縺ｮx逡ｪ逶ｮ縺ｮ荳雁｣√↓1false莉｣蜈･
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺и蠎ｧ讓吶�ｮ螢√ｒ螢翫◎縺�縺ｨ縺励※縺�縺ｾ縺兔n\r");
			myprintf("destroy_wall髢｢謨ｰ蜀�\n\r");
		}

	}

}
bool map::get_wall(unsigned char wall_x, unsigned char wall_y,
		unsigned char muki) {
	unsigned char target_x = wall_x, target_y = wall_y;

	//x蠎ｧ讓呎婿蜷代ｒ隕九ｋ縺吶ｋ縺ｨ縺�
	if ((muki == MUKI_RIGHT) || (muki == MUKI_LEFT)) {
		if (muki == MUKI_RIGHT) {
		} else if (muki == MUKI_LEFT) {
			if (wall_x == 0) {		//荳�逡ｪ蟾ｦ螢√�ｯ邂｡逅�縺励↑縺�
				return true;
			} else {
				target_x = wall_x - 1;	//蠢�縺壼承螢√ｒ隕九ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (target_x < MAZE_SIZE) {
			return get_maze_wall(x_maze_wall[target_y], target_x);
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺з蠎ｧ讓吶�ｮ螢√ｒ隱ｭ繧ゅ≧縺ｨ縺励※縺�縺ｾ縺�->%d\n\r", target_x);
			myprintf("get_wall髢｢謨ｰ蜀�\n\r");
			return false;
		}

		//y蠎ｧ讓呎婿蜷代ｒ螟画峩縺吶ｋ縺ｨ縺�
	} else if ((muki == MUKI_UP) || (muki == MUKI_DOWN)) {
		if (muki == MUKI_UP) {
		} else if (muki == MUKI_DOWN) {
			if (wall_y == 0) {		//荳�逡ｪ荳句｣√�ｯ蟶ｸ縺ｫ螢√′蟄伜惠
				return true;
			} else {
				target_y = wall_y - 1;	//蠢�縺壻ｸ雁｣√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�
			}
		}
		if (target_y < MAZE_SIZE) {
			return get_maze_wall(y_maze_wall[target_x], target_y);
		} else {		//驕ｩ蛻�縺ｧ縺ｪ縺�蛟､縺悟�･縺｣縺ｦ繧�
			mouse::error();
			myprintf("\n\r!!!ERROR!!!\n\r");
			myprintf("蟄伜惠縺励↑縺и蠎ｧ讓吶�ｮ螢√ｒ隱ｭ繧ゅ≧縺ｨ縺励※縺�縺ｾ縺�->%d\n\r", target_y);
			myprintf("get_wall髢｢謨ｰ蜀�\n\r");
			return false;
		}
	}

	return false;
}

void map::reset_maze() {
	//螢√ｒ豸医☆
	for (int i = 0; i < MAZE_SIZE; i++) {
		x_maze_wall[i].all = 0;
		y_maze_wall[i].all = 0;
		x_wall_exist[i].all = 0;
		y_wall_exist[i].all = 0;
	}
	//螟門｣√�ｯ蜈･繧後ｋ
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
	//(0�ｼ�0)縺ｯ繧上°縺｣縺ｦ繧�
	create_wall(0, 0, MUKI_RIGHT);
	remember_exist(0, 0, MUKI_RIGHT);
	destroy_wall(0, 0, MUKI_UP);
	remember_exist(0, 0, MUKI_UP);
}

void map::draw_map(bool write_step) {
	signed char tekitou_x = 0, tekitou_y = MAZE_SIZE - 1;

	myprintf("\n-----start draw_map-------\n\r");

	//荳願ｾｺ
	for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++)
		myprintf("+---");
	myprintf("+\n\r");

	myprintf("|");	//蟾ｦ遶ｯ縺ｮ螢�
	for (tekitou_x = 0; tekitou_x < MAZE_SIZE - 1; tekitou_x++) {

		if (write_step)
			myprintf("%3d", step::get_step(tekitou_x, tekitou_y));
		else
			myprintf("   ");

		if ((get_wall(tekitou_x, tekitou_y, MUKI_RIGHT) == true)
				|| (get_wall(tekitou_x + 1, tekitou_y, MUKI_LEFT) == true)) {//莉頑嶌縺�縺溘�槭せ縺ｮ蜿ｳ縺ｮ螢√′縺ゅｌ縺ｰ螢√ｒ譖ｸ縺�
			myprintf("|");
		} else {
			myprintf(" ");	//縺ｪ縺代ｌ縺ｰ螢√�ｯ譖ｸ縺九↑縺�
		}
	}

	if (write_step)
		myprintf("%3d", step::get_step(tekitou_x, tekitou_y));
	else
		myprintf("   ");

	myprintf("|\n\r");	//蜿ｳ遶ｯ縺ｮ螢�

	for (tekitou_y = MAZE_SIZE - 2; tekitou_y >= 0; tekitou_y--) {
		//////////////////////////////////////////霑ｷ霍ｯ縺ｮ螢√�ｮ陦�
		for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++) {
			myprintf("+");	//譟ｱ
			if ((get_wall(tekitou_x, tekitou_y, MUKI_UP) == true)
					|| (get_wall(tekitou_x, tekitou_y + 1, MUKI_DOWN) == true)) {//螢√′縺ゅｋ縺ｪ繧�
				myprintf("---");
			} else {
				myprintf("   ");
			}
		}
		myprintf("+\n\r");

		/////////////////////////////////////////霑ｷ霍ｯ縺ｮ繝槭せ逶ｮ縺ｮ陦�
		myprintf("|");	//蟾ｦ遶ｯ縺ｮ螢�
		for (tekitou_x = 0; tekitou_x < MAZE_SIZE - 1; tekitou_x++) {

			if (write_step)
				myprintf("%3d", step::get_step(tekitou_x, tekitou_y));
			else
				myprintf("   ");

			if ((get_wall(tekitou_x, tekitou_y, MUKI_RIGHT) == true)
					|| (get_wall(tekitou_x + 1, tekitou_y, MUKI_LEFT) == true)) {//莉頑嶌縺�縺溘�槭せ縺ｮ蜿ｳ縺ｮ螢√′縺ゅｌ縺ｰ螢√ｒ譖ｸ縺�
				myprintf("|");
			} else {
				myprintf(" ");	//縺ｪ縺代ｌ縺ｰ螢√�ｯ譖ｸ縺九↑縺�
			}
		}
		if (write_step)
			myprintf("%3d", step::get_step(tekitou_x, tekitou_y));
		else
			myprintf("   ");

		myprintf("|\n\r");	//蜿ｳ遶ｯ縺ｮ螢�
	}

	//荳玖ｾｺ
	for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++)
		myprintf("+---");
	myprintf("+\n\r");

}

/*
 void map::convert_mapdata(unsigned char (*hiramatu_data)[16]){
 for(char x=0;x<16;x++){
 for(char y=0;y<16;y++){
 if((hiramatu_data[x][y] & 2) == 2){		//譚ｱ螢√′縺ゅｌ縺ｰ
 create_wall(x,y,MUKI_RIGHT);
 }else{
 destroy_wall(x,y,MUKI_RIGHT);
 }
 if((hiramatu_data[x][y] & 1) == 1){		//蜊怜｣√′縺ゅｌ縺ｰ
 create_wall(x,y,MUKI_UP);
 }else{
 destroy_wall(x,y,MUKI_UP);
 }
 }
 }
 }
 */

void map::input_map_data(const MAP_DATA *input_data) {
	//繝�繝ｼ繧ｿ蜈･蜉�
	for (int i = 0; i < MAZE_SIZE; i++) {
		x_maze_wall[i].all = input_data->x_wall[i].all;
		y_maze_wall[i].all = input_data->y_wall[i].all;
		x_wall_exist[i].all = input_data->x_known[i].all;
		y_wall_exist[i].all = input_data->y_known[i].all;
	}
}

void map::output_map_data(MAP_DATA* output_data) {
	//繝�繝ｼ繧ｿ蜃ｺ蜉�
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
 //蠎ｧ讓吶ｒ邂｡逅�縺吶ｋ縺溘ａ縺ｮ驟榊��
 unsigned char x_coordinate[965];
 unsigned char y_coordinate[965];

 //array[x]={0};縺｣縺ｦ繧�繧九→繝｡繝｢繝ｪ鬟溘≧繧峨＠縺�縺ｮ縺ｧFor縺ｧ蛻晄悄蛹�
 for (int16_t i = 0; i < 965; i++) {
 x_coordinate[i] = 0;
 y_coordinate[i] = 0;
 }

 unsigned char x_count = 0, y_count = 0;	//荳�譎ら噪縺ｫ蠎ｧ讓吶ｒ繧ゅ▲縺ｨ縺上ｈ縺�
 unsigned char head, tail;		//
 uint16_t now_step;

 step_reset();
 maze_step[target_x][target_y] = 0;

 //coordinate  [tail][][][] -> [][][head]

 head = 1;
 tail = 0;

 //Q縺ｮ譛�蛻昴↓縺ｯ逶ｮ讓吶�ｮ蠎ｧ讓吶ｒ蜈･繧後→縺�
 x_coordinate[tail] = target_x;
 y_coordinate[tail] = target_y;

 while (head != tail) {
 //蠎ｧ讓吶ｒ莉｣蜈･
 x_count = x_coordinate[tail];
 y_count = y_coordinate[tail];
 now_step = maze_step[x_count][y_count];

 tail++;

 //蟾ｦ繝槭せ
 if (set_step(x_count, y_count, MUKI_LEFT, now_step + 1, false)) {
 //縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
 x_coordinate[head] = (x_count - 1);
 y_coordinate[head] = y_count;
 head++;
 }

 //蜿ｳ繝槭せ
 if (set_step(x_count, y_count, MUKI_RIGHT, now_step + 1, false)) {
 //縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
 x_coordinate[head] = (x_count + 1);
 y_coordinate[head] = y_count;
 head++;
 }

 //荳九�槭せ
 if (set_step(x_count, y_count, MUKI_DOWN, now_step + 1, false)) {
 //縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
 x_coordinate[head] = x_count;
 y_coordinate[head] = y_count - 1;
 head++;
 }

 //荳翫�槭せ
 if (set_step(x_count, y_count, MUKI_UP, now_step + 1, false)) {
 //縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
 x_coordinate[head] = x_count;
 y_coordinate[head] = y_count + 1;
 head++;
 }

 if (head > 965) {		//驟榊�苓ｶ翫∴縺溘ｉ繧ｨ繝ｩ繝ｼ
 myprintf("繧ｨ繝ｩ繝ｼ!\n\radachi::set_step()蜀�\n\r");
 break;
 }

 }

 }


 void step::set_step_by_known(unsigned char target_x, unsigned char target_y) {
 //蠎ｧ讓吶ｒ邂｡逅�縺吶ｋ縺溘ａ縺ｮ驟榊��
 unsigned char x_coordinate[965];
 unsigned char y_coordinate[965];

 //array[x]={0};縺｣縺ｦ繧�繧九→繝｡繝｢繝ｪ鬟溘≧繧峨＠縺�縺ｮ縺ｧFor縺ｧ蛻晄悄蛹�
 for (int16_t i = 0; i < 965; i++) {
 x_coordinate[i] = 0;
 y_coordinate[i] = 0;
 }

 unsigned char x_count = 0, y_count = 0;	//荳�譎ら噪縺ｫ蠎ｧ讓吶ｒ繧ゅ▲縺ｨ縺上ｈ縺�
 unsigned char head, tail;		//

 step_reset();
 maze_step[target_x][target_y] = 0;

 //coordinate  [tail][][][] -> [][][head]

 head = 1;
 tail = 0;

 //Q縺ｮ譛�蛻昴↓縺ｯ逶ｮ讓吶�ｮ蠎ｧ讓吶ｒ蜈･繧後→縺�
 x_coordinate[tail] = target_x;
 y_coordinate[tail] = target_y;

 while (head != tail) {
 //蠎ｧ讓吶ｒ莉｣蜈･
 x_count = x_coordinate[tail];
 y_count = y_coordinate[tail];

 tail++;

 //蟾ｦ繝槭せ
 if ((x_count - 1) >= 0) {		//蠎ｧ讓吶′霑ｷ霍ｯ蜀�(x-1縺�0莉･荳�)縺ｫ縺ゅｊ
 if ((maze_step[x_count - 1][y_count] == STEP_INIT)) {//豁ｩ謨ｰ繧貞�･繧後※縺ｪ縺�ｼ亥�･縺｣縺ｦ繧区ｭｩ謨ｰ縺郡TEP_INIT�ｼ�
 if (map::get_wall(x_count, y_count, MUKI_LEFT) == false) {//蜈�縺ｮ繝槭せ縺ｮ蟾ｦ螢√′縺ｪ縺�縺ｪ繧�
 if (map::check_exist(x_count, y_count,
 MUKI_LEFT)) {		//蟾ｦ螢√ｒ隕九※縺�繧九↑繧�
 maze_step[x_count - 1][y_count] =
 maze_step[x_count][y_count] + 1;		//豁ｩ謨ｰ繧剃ｻ｣蜈･
 //縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
 x_coordinate[head] = (x_count - 1);
 y_coordinate[head] = y_count;
 head++;
 }
 }
 }
 }

 //蜿ｳ繝槭せ
 if ((x_count + 1) < MAZE_SIZE) {	//蠎ｧ讓吶′霑ｷ霍ｯ蜀�(x+1縺勲AZE_SIZE譛ｪ貅�)縺ｫ縺ゅｊ
 if ((maze_step[x_count + 1][y_count] == STEP_INIT)) {//豁ｩ謨ｰ繧貞�･繧後※縺ｪ縺�ｼ亥�･縺｣縺ｦ繧区ｭｩ謨ｰ縺郡TEP_INIT�ｼ�
 if (map::get_wall(x_count, y_count, MUKI_RIGHT) == false) {	//蜈�縺ｮ繝槭せ縺ｮ蜿ｳ螢√′縺ｪ縺�
 if (map::check_exist(x_count, y_count,
 MUKI_RIGHT)) {	//蜿ｳ螢√ｒ隕九※縺�繧九↑繧�
 maze_step[x_count + 1][y_count] =
 maze_step[x_count][y_count] + 1;	//豁ｩ謨ｰ繧剃ｻ｣蜈･
 //縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
 x_coordinate[head] = (x_count + 1);
 y_coordinate[head] = y_count;
 head++;
 }
 }
 }
 }

 //荳九�槭せ
 if ((y_count - 1) >= 0) {		//蠎ｧ讓吶′霑ｷ霍ｯ蜀�(y-1縺�0莉･荳�)縺ｫ縺ゅｊ
 if ((maze_step[x_count][y_count - 1] == STEP_INIT)) {//豁ｩ謨ｰ繧貞�･繧後※縺ｪ縺�ｼ亥�･縺｣縺ｦ繧区ｭｩ謨ｰ縺郡TEP_INIT�ｼ�
 if (map::get_wall(x_count, y_count, MUKI_DOWN) == false) {//蜈�縺ｮ繝槭せ縺ｮ荳句｣√′縺ｪ縺�
 if (map::check_exist(x_count, y_count,
 MUKI_DOWN)) {		//荳句｣√′譌｢遏･縺ｪ繧�
 maze_step[x_count][y_count - 1] =
 maze_step[x_count][y_count] + 1;	//豁ｩ謨ｰ繧剃ｻ｣蜈･
 //縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
 x_coordinate[head] = x_count;
 y_coordinate[head] = (y_count - 1);
 head++;
 }
 }
 }
 }

 //荳翫�槭せ
 if ((y_count + 1) < MAZE_SIZE) {	//x,y+1縺ｮ蠎ｧ讓吶′霑ｷ霍ｯ蜀�(MAZE_SIZE譛ｪ貅�)縺ｧ縺ゅｋ
 if ((maze_step[x_count][y_count + 1] == STEP_INIT)) {//豁ｩ謨ｰ繧貞�･繧後※縺ｪ縺�ｼ亥�･縺｣縺ｦ繧区ｭｩ謨ｰ縺郡TEP_INIT�ｼ�
 if (map::get_wall(x_count, y_count, MUKI_UP) == false) {//蜈�縺ｮ繝槭せ縺ｮ荳雁｣√′縺ｪ縺�
 if (map::check_exist(x_count, y_count,
 MUKI_UP)) {		//荳雁｣√′譌｢遏･縺ｪ繧�
 maze_step[x_count][y_count + 1] =
 maze_step[x_count][y_count] + 1;	//豁ｩ謨ｰ繧剃ｻ｣蜈･
 //縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
 x_coordinate[head] = x_count;
 y_coordinate[head] = (y_count + 1);
 head++;
 }
 }
 }
 }

 if (head > 965) {		//驟榊�苓ｶ翫∴縺溘ｉ繧ｨ繝ｩ繝ｼ
 myprintf("繧ｨ繝ｩ繝ｼ!\n\radachi::set_step()蜀�\n\r");
 break;
 }

 }

 }
 */
void step::spread_step(uint8_t tar_x, uint8_t tar_y, bool by_known) {
	uint8_t x, y;	//荳�譎ら噪縺ｫ蠎ｧ讓吶ｒ繧ゅ▲縺ｨ縺上ｈ縺�
	uint16_t now_step;
	loop = 0;

	//蠎ｧ讓吩ｿ晏ｭ倡畑Queue
	static my_queue x_que;
	static my_queue y_que;

	step_reset();

	maze_step[tar_x][tar_y] = 0;
	//Q縺ｮ譛�蛻昴↓縺ｯ逶ｮ讓吶�ｮ蠎ｧ讓吶ｒ蜈･繧後→縺�
	x_que.push(tar_x);
	y_que.push(tar_y);

	while (x_que.size() != 0) {		//x繧Ｚ繧ゅし繧､繧ｺ縺ｯ蜷後§縺ｪ縺ｮ縺ｧ莉｣陦ｨ縺励※x繧剃ｽｿ縺�
		loop++;
		//蠎ｧ讓吶ｒ莉｣蜈･
		x = x_que.front();
		y = y_que.front();
		x_que.pop();		//蜿悶ｊ蜃ｺ縺励◆縺ｮ縺ｧ豸亥悉
		y_que.pop();		//蜿悶ｊ蜃ｺ縺励◆縺ｮ縺ｧ豸亥悉
		now_step = maze_step[x][y];

		//蟾ｦ繝槭せ
		if (set_step(x, y, MUKI_LEFT, now_step + 1, by_known)) {	//譖ｸ縺崎ｾｼ繧√◆縺ｪ繧�
			x_que.push(x - 1);		//縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
			y_que.push(y);		//縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
		}
		//蜿ｳ繝槭せ
		if (set_step(x, y, MUKI_RIGHT, now_step + 1, by_known)) {	//譖ｸ縺崎ｾｼ繧√◆縺ｪ繧�
			x_que.push(x + 1);		//縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
			y_que.push(y);		//縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
		}
		//蛹励�槭せ
		if (set_step(x, y, MUKI_UP, now_step + 1, by_known)) {	//譖ｸ縺崎ｾｼ繧√◆縺ｪ繧�
			x_que.push(x);		//縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
			y_que.push(y + 1);		//縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
		}
		//蜊励�槭せ
		if (set_step(x, y, MUKI_DOWN, now_step + 1, by_known)) {	//譖ｸ縺崎ｾｼ繧√◆縺ｪ繧�
			x_que.push(x);		//縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
			y_que.push(y - 1);		//縺薙�ｮ蠎ｧ讓吶ｒ菫晄戟
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

//驟榊�怜､悶↓蜃ｺ繧九ヱ繧ｿ繝ｼ繝ｳ繧帝勁螟�
	if (static_cast<int16_t>(_x) + dx < 0)
		return false;
	if (static_cast<int16_t>(_x) + dx >= MAZE_SIZE)
		return false;
	if (static_cast<int16_t>(_y) + dy < 0)
		return false;
	if (static_cast<int16_t>(_y) + dy >= MAZE_SIZE)
		return false;

	if ((maze_step[_x + dx][_y + dy] > _set_step)) {	//蜈･縺｣縺ｦ繧区ｭｩ謨ｰ縺悟�･繧後ｈ縺�縺ｨ縺吶ｋ豁ｩ謨ｰ繧医ｊ螟ｧ縺阪＞
		if (!map::get_wall(_x, _y, _muki)) {	//螢√′縺ｪ縺�
			if (!_by_known || map::check_exist(_x, _y, _muki)) {	//蜿ｳ螢√ｒ隕九※縺�繧九↑繧�
				maze_step[_x + dx][_y + dy] = _set_step;	//豁ｩ謨ｰ繧剃ｻ｣蜈･
				return true;	//豁ｩ謨ｰ繧呈嶌縺崎ｾｼ繧√◆縺ｮ縺ｧtrue繧定ｿ斐☆
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
		unsigned char all;				//荳�諡ｬ
		struct {
			unsigned char count :4;		//		陦後￠縺ｪ縺�譁ｹ蜷代�ｮ蛟区焚
			unsigned char up :1;		//竊�	x=0,y=1縺ｮ譁ｹ蜷�
			unsigned char down :1;		//竊�	x=0,y=-1縺ｮ譁ｹ蜷�
			unsigned char left :1;		//竊�	x=-1,y=0縺ｮ譁ｹ蜷�
			unsigned char right :1;		//竊�	x=1,y=0縺ｮ譁ｹ蜷�
		} direction;
	} dead_end;

	dead_end.all = 0;	//蛻晄悄蛹�

//蟾ｦ繝槭せ
	if ((map::get_wall(target_x, target_y, MUKI_LEFT))) {	//蟾ｦ螢√′縺ゅｋ縺ｪ繧�
		dead_end.direction.left = 1;	//蟾ｦ繝輔Λ繧ｰ繧貞ｻｺ縺ｦ繧�
		dead_end.direction.count++;	//1雜ｳ縺�
	} else if ((target_x - 1) >= 0) {		//蠎ｧ讓吶′霑ｷ霍ｯ蜀�(x-1縺�0莉･荳�)縺ｫ縺ゅｊ
		if ((maze_step[target_x - 1][target_y] == STEP_INIT)
				|| (map::check_exist(target_x, target_y, MUKI_LEFT) == false)) {//蟾ｦ縺ｮ繝槭せ縺ｫ陦後￠縺ｪ縺�ｼ亥�･縺｣縺ｦ繧区ｭｩ謨ｰ縺�255 縺ｾ縺溘�ｯ �ｼ�
			dead_end.direction.left = 1;		//蟾ｦ繝輔Λ繧ｰ繧ｪ繝ｳ
			dead_end.direction.count++;		//1雜ｳ縺�
		}
	}

//蜿ｳ繝槭せ
	if ((map::get_wall(target_x, target_y, MUKI_RIGHT))) {		//蜿ｳ螢√′縺ゅｋ縺ｪ繧�
		dead_end.direction.right = 1;		//蜿ｳ繝輔Λ繧ｰ繧貞ｻｺ縺ｦ繧�
		dead_end.direction.count++;		//1雜ｳ縺�
	} else if ((target_x + 1) < MAZE_SIZE) {		//蠎ｧ讓吶′霑ｷ霍ｯ蜀�(x+1縺勲ax_x譛ｪ貅�)縺ｫ縺ゅｊ
		if ((maze_step[target_x + 1][target_y] == STEP_INIT)
				|| (map::check_exist(target_x, target_y, MUKI_RIGHT) == false)) {//蜿ｳ縺ｮ繝槭せ縺ｫ陦後￠縺ｪ縺�ｼ亥�･縺｣縺ｦ繧区ｭｩ謨ｰ縺�255 縺ｾ縺溘�ｯ 螢√′縺ゅｋ�ｼ�
			dead_end.direction.right = 1;		//蜿ｳ繝輔Λ繧ｰ繧貞ｻｺ縺ｦ繧�
			dead_end.direction.count++;		//1雜ｳ縺�
		}
	}

//荳九�槭せ
	if ((map::get_wall(target_x, target_y, MUKI_DOWN))) {		//荳句｣√′縺ゅｋ縺ｪ繧�
		dead_end.direction.down = 1;		//荳九ヵ繝ｩ繧ｰ繧貞ｻｺ縺ｦ繧�
		dead_end.direction.count++;		//1雜ｳ縺�
	} else if ((target_y - 1 >= 0)) {		//蠎ｧ讓吶′霑ｷ霍ｯ蜀�(y-1縺�0莉･荳�)縺ｫ縺ゅｊ
		if ((maze_step[target_x][target_y - 1] == STEP_INIT)
				|| (map::check_exist(target_x, target_y, MUKI_DOWN) == false)) {//荳九�ｮ繝槭せ縺ｫ陦後￠縺ｪ縺�ｼ亥�･縺｣縺ｦ繧区ｭｩ謨ｰ縺�255 縺ｾ縺溘�ｯ 螢√′縺ゅｋ�ｼ�
			dead_end.direction.down = 1;		//荳九ヵ繝ｩ繧ｰ繧貞ｻｺ縺ｦ繧�
			dead_end.direction.count++;		//1雜ｳ縺�
		}
	}

//荳翫�槭せ
	if ((map::get_wall(target_x, target_y, MUKI_UP))) {		//荳雁｣√′縺ゅｋ縺ｪ繧�
		dead_end.direction.up = 1;		//荳翫ヵ繝ｩ繧ｰ繧貞ｻｺ縺ｦ繧�
		dead_end.direction.count++;		//1雜ｳ縺�
	} else if ((target_y + 1 < MAZE_SIZE)) {		//x,y+1縺ｮ蠎ｧ讓吶′霑ｷ霍ｯ蜀�(MAX_y譛ｪ貅�)縺ｧ縺ゅｋ
		if ((maze_step[target_x][target_y + 1] == STEP_INIT)
				|| (map::check_exist(target_x, target_y, MUKI_UP) == false)) {//荳翫�ｮ繝槭せ縺ｫ陦後￠縺ｪ縺�ｼ亥�･縺｣縺ｦ繧区ｭｩ謨ｰ縺�255縲�縺ｾ縺溘�ｯ縲�螢√′縺ゅｋ�ｼ�
			dead_end.direction.up = 1;		//荳翫ヵ繝ｩ繧ｰ繧貞ｻｺ縺ｦ繧�
			dead_end.direction.count++;		//1雜ｳ縺�
		}
	}

//陲句ｰ剰ｷｯ繧偵�ｵ縺輔＄
	if (dead_end.direction.count >= 3) {		//陦後￠縺ｪ縺�譁ｹ蜷代′3莉･荳� = 陲句ｰ剰ｷｯ縺ｪ繧�
		if ((target_x == 0) && (target_y == 0)) {		//縺昴ｌ縺後せ繧ｿ繝ｼ繝医↑繧我ｽ輔ｂ縺励↑縺�
		} else if ((target_x == GOAL_x) && (target_y == GOAL_y)) {//縺昴ｌ縺後ざ繝ｼ繝ｫ縺ｧ繧ゆｽ輔ｂ縺励↑縺�
		} else {							//荳願ｨ倅ｻ･螟悶↑繧芽｢句ｰ剰ｷｯ繧呈ｽｰ縺�
			maze_step[target_x][target_y] = STEP_INIT;					//豁ｩ謨ｰ繧貞�晄悄蛹�
			//陲句ｰ剰ｷｯ縺ｮ縺ゅ＞縺ｦ繧区婿蜷代↓縺､縺�縺ｦ繧ゅ≧荳�蝗槫酔縺倥％縺ｨ繧定｡後≧
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

//set_step_by_known(target_x, target_y);		//譌｢遏･縺ｮ螢√□縺代〒豁ｩ謨ｰ繝槭ャ繝励ｒ菴懈��
	spread_step(target_x, target_y, true);					//譌｢遏･縺ｮ螢√□縺代〒豁ｩ謨ｰ繝槭ャ繝励ｒ菴懈��
	close_dead_end();					//陲句ｰ剰ｷｯ繧呈ｽｰ縺�
}

void path::displace_path(unsigned int path_number) {
//1蛟九★繧峨☆
	for (uint16_t number = path_number;
			path_memory[number].element.flag == TRUE; number++) {
		path_memory[number].all = path_memory[number + 1].all;
	}
}

void path::improve_path() {
	unsigned int count = 0;

	while (path_memory[count].element.flag == TRUE) {	//path縺檎ｵゅｏ繧後�ｰ邨ゆｺ�

		if (path_memory[count].element.distance >= 1) {	//90mm莉･荳顔峩騾ｲ縺吶ｋ縺ｪ繧�

			if (path_memory[count + 1].element.distance >= 1) {	//繧ｿ繝ｼ繝ｳ蠕後ｂ90mm莉･荳顔峩騾ｲ縺吶ｋ縺ｪ繧�	螟ｧ蝗槭ｊ縺ｮ繝√ぉ繝�繧ｯ繧定｡後≧
				path_memory[count].element.turn = 2;	//螟ｧ蝗槭ｊ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
				path_memory[count].element.distance -= 1;	//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
				path_memory[count + 1].element.distance -= 1;	//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�

			} else {								//繧ｿ繝ｼ繝ｳ蠕�90mm逶ｴ騾ｲ縺ｯ縺励↑縺�縺ｪ繧�

				if (path_memory[count].element.muki
						== path_memory[count + 1].element.muki) {//蜷後§譁ｹ蜷代↓譖ｲ縺後ｋ縺ｪ繧�(U繧ｿ繝ｼ繝ｳ)

					if (path_memory[count + 2].element.distance >= 1) {	//U繧ｿ繝ｼ繝ｳ蠕�90mm逶ｴ騾ｲ縺吶ｋ縺ｪ繧�
						path_memory[count].element.turn = 3;	//180ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
						path_memory[count].element.distance -= 1;//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
						path_memory[count + 2].element.distance -= 1;//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�

						//1蛟九★繧峨☆
						displace_path(count + 1);

					} else {							//U繧ｿ繝ｼ繝ｳ蠕後☆縺先峇縺後ｋ縺ｪ繧�

						if (path_memory[count + 2].element.flag == FALSE) {	//path縺檎ｵゅｏ縺｣縺ｦ縺ｪ縺�縺九メ繧ｧ繝�繧ｯ縲�邨ゅｏ縺｣縺ｦ縺ｪ縺代ｌ縺ｰ騾�譁ｹ蜷代↓繧ｿ繝ｼ繝ｳ縺ｮ縺ｯ縺�
							//繝翫リ繝｡縺ｮ蜃ｦ逅�縺ｪ縺ｮ縺ｧ菴輔ｂ縺励↑縺�
						}

					}

				} else {		//驕輔≧譁ｹ豕輔↓譖ｲ縺後ｋ縺ｪ繧�
					//繝翫リ繝｡縺ｮ蜃ｦ逅�縺ｪ縺ｮ縺ｧ菴輔ｂ縺励↑縺�
				}

			}

		}

		count++;
	}

}

void path::improve_advance_path() {
	unsigned int count = 0;
	unsigned char temp_distance = 0;	//荳�譎ら噪縺ｪ霍晞屬菫晏ｭ�
	unsigned char naname_flag = FALSE;	//迴ｾ蝨ｨ讖滉ｽ薙′譁懊ａ縺九ｒ蛻､譁ｭ	ON縺ｪ繧画万繧∬ｵｰ陦御ｸｭ

	while (path_memory[count].element.flag == TRUE) {	//path縺檎ｵゅｏ繧後�ｰ邨ゆｺ�

		if (naname_flag == TRUE) {	//譁懊ａ襍ｰ陦御ｸｭ縺ｪ繧�	遒ｺ螳溘↓逶ｴ騾ｲ霍晞屬(distance)縺�0縺ｮ縺ｯ縺�

			if (path_memory[count + 1].element.distance >= 1) {	//谺｡縺ｮ繧ｿ繝ｼ繝ｳ蠕�90mm莉･荳顔峩騾ｲ(譁懊ａ邨ゅｏ繧�)

				path_memory[count].element.turn = 5;	//邨ゅｏ繧�45ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
				path_memory[count + 1].element.distance -= 1;	//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
				naname_flag = FALSE;
				count++;	//驟榊�励ｒ谺｡縺ｸ

			} else if (path_memory[count + 2].element.distance >= 1) {//谺｡縺ｮ谺｡縺ｮ繧ｿ繝ｼ繝ｳ蠕�90mm莉･荳顔峩騾ｲ(譁懊ａ邨ゅｏ繧�)

				if (path_memory[count].element.muki
						== path_memory[count + 1].element.muki) {	//蜷後§譁ｹ蜷代�ｮ2蝗槭ち繝ｼ繝ｳ

					path_memory[count].element.turn = 7;	//邨ゅｏ繧�135ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
					displace_path(count + 1);	//荳�蛟九★繧峨☆
					path_memory[count + 1].element.distance -= 1;//繧ｿ繝ｼ繝ｳ蠕後�ｮ逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
					naname_flag = FALSE;
					count++;	//驟榊�励ｒ谺｡縺ｸ

				} else {								//莠､莠偵�ｮ繧ｿ繝ｼ繝ｳ(繧ｮ繧ｶ繧ｮ繧ｶ)

					path_memory[count].element.distance += 1;	//譁懊ａ縺ｮ逶ｴ邱夊ｷ晞屬繧�1蠅励ｄ縺�
					temp_distance = path_memory[count].element.distance;//霍晞屬繧剃ｸ�譎ら噪縺ｫ謖√▲縺ｦ縺翫￥
					displace_path(count);								//荳�蛟九★繧峨☆
					path_memory[count].element.distance = temp_distance;//霍晞屬繧貞�･繧後↑縺翫☆

				}

			} else {									//縺ｾ縺�縺ｾ縺�譁懊ａ縺ｯ邯壹￥縺ｪ繧�

				if (path_memory[count].element.muki
						== path_memory[count + 1].element.muki) {//蜷後§譁ｹ蜷代�ｮ2蝗槭ち繝ｼ繝ｳ	繧ｳ縺ｮ蟄�

					path_memory[count].element.turn = 8;		//譁懊ａ90ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
					displace_path(count + 1);							//荳�蛟九★繧峨☆
					count++;									//驟榊�励ｒ谺｡縺ｸ

				} else {							//驕輔≧譁ｹ蜷代�ｮ2蝗槭ち繝ｼ繝ｳ	繧ｮ繧ｶ繧ｮ繧ｶ

					path_memory[count].element.distance += 1;	//譁懊ａ縺ｮ逶ｴ邱夊ｷ晞屬繧�1蠅励ｄ縺�
					temp_distance = path_memory[count].element.distance;//霍晞屬繧剃ｸ�譎ら噪縺ｫ謖√▲縺ｦ縺翫￥
					displace_path(count);							//荳�蛟九★繧峨☆
					path_memory[count].element.distance = temp_distance;//霍晞屬繧貞�･繧後↑縺翫☆

				}
			}

		} else {										//譁懊ａ縺倥ｃ縺ｪ縺代ｌ縺ｰ

			if (path_memory[count + 1].element.distance >= 1) {	//繧ｿ繝ｼ繝ｳ蠕後ｂ90mm莉･荳顔峩騾ｲ縺吶ｋ縺ｪ繧�	螟ｧ蝗槭ｊ縺ｮ繝√ぉ繝�繧ｯ繧定｡後≧

				if ((count != 0) || (path_memory[0].element.distance > 1)) {//蛻昴▲遶ｯ縺ｮ繧ｿ繝ｼ繝ｳ縺倥ｃ縺ｪ縺代ｌ縺ｰ

					path_memory[count].element.turn = 2;	//螟ｧ蝗槭ｊ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
					path_memory[count].element.distance -= 1;	//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
					path_memory[count + 1].element.distance -= 1;//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�

				} else {
					//TODO 蛻昴▲遶ｯ螟ｧ蝗槭ｊ90繧ｿ繝ｼ繝ｳ縺ｮ蜃ｦ逅�
				}

			} else {								//繧ｿ繝ｼ繝ｳ蠕�90mm逶ｴ騾ｲ縺ｯ縺励↑縺�縺ｪ繧�

				if (path_memory[count].element.muki
						== path_memory[count + 1].element.muki) {//蜷後§譁ｹ蜷代↓譖ｲ縺後ｋ縺ｪ繧�(U繧ｿ繝ｼ繝ｳ)

					if (path_memory[count + 2].element.distance >= 1) {	//U繧ｿ繝ｼ繝ｳ蠕�90mm逶ｴ騾ｲ縺吶ｋ縺ｪ繧�

						path_memory[count].element.turn = 3;	//180ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
						path_memory[count].element.distance -= 1;//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
						path_memory[count + 2].element.distance -= 1;//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
						displace_path(count + 1);	//荳�蛟九★繧峨☆

					} else {							//U繧ｿ繝ｼ繝ｳ蠕後☆縺先峇縺後ｋ縺ｪ繧�

						if (path_memory[count + 2].all != 0) {//path縺檎ｵゅｏ縺｣縺ｦ縺ｪ縺�縺九メ繧ｧ繝�繧ｯ縲�邨ゅｏ縺｣縺ｦ縺ｪ縺代ｌ縺ｰ騾�譁ｹ蜷代↓繧ｿ繝ｼ繝ｳ縺ｮ縺ｯ縺�

							path_memory[count].element.turn = 6;	//135ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
							path_memory[count].element.distance -= 1;//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
							displace_path(count + 1);					//荳�蛟九★繧峨☆
							naname_flag = TRUE;

						}

					}

				} else {		//驕輔≧譁ｹ豕輔↓譖ｲ縺後ｋ縺ｪ繧�

					path_memory[count].element.turn = 4;		//45ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
					path_memory[count].element.distance -= 1;	//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
					naname_flag = TRUE;

				}

			}
			count++;		//驟榊�励ｒ谺｡縺ｸ
		}
	}

}

void path::create_path() {
	int8_t path_x, path_y;							//菴咲ｽｮ邂｡逅�逕ｨ
	int8_t path_direction_x, path_direction_y;							//譁ｹ蜷醍ｮ｡逅�逕ｨ
	bool straight_flag;							//逶ｴ邱壹〒縺阪ｋ縺九←縺�縺句愛蛻･逕ｨ繝輔Λ繧ｰ
	SAVE_DIRECTION save_direction;							//谺｡縺ｫ陦後￥繝槭せ縺ｮ譁ｹ蜷代ｒ菫晏ｭ�
	uint16_t count = 0;							//謨ｰ繧呈焚縺医ｋ縺�縺代�ｮ螟画焚

//set_step_for_shortest(GOAL_x,GOAL_y);

	spread_step(GOAL_x, GOAL_y, true);

	path_reset();

	path_direction_x = 0;							//譁ｹ蜷代ｒ蛻晄悄蛹�
	path_direction_y = 1;

	path_x = 0;							//菴咲ｽｮ繧貞�晄悄蛹�
	path_y = 0;

	straight_flag = false;							//繝輔Λ繧ｰ縺ｯ謚倥▲縺ｦ縺翫￥

	path_memory[count].element.distance += 1;					//譛�蛻昴�ｯ蠢�縺壼濠蛹ｺ逕ｻ逶ｴ騾ｲ縺吶ｋ
	path_memory[count].element.flag = TRUE;						//譛�蛻昴□縺礼ｶ夊｡後ヵ繝ｩ繧ｰ繧貞ｻｺ縺ｦ繧�

	while (1) {

		save_direction.all = 0;		//谺｡縺ｫ陦後￥譁ｹ蜷大�晄悄蛹�
		straight_flag = false;		//繝輔Λ繧ｰ縺ｯ謚倥▲縺ｦ縺翫￥

		path_x += path_direction_x;		//菴咲ｽｮ菫ｮ豁｣
		path_y += path_direction_y;

		//GOAL縺ｫ縺溘←繧顔捩縺�縺溘ｉ邨ゆｺ�
		if ((path_x == GOAL_x) && (path_y == GOAL_y)) {
			path_memory[count].element.distance += 1;	//90mm逶ｴ騾ｲ繧定ｿｽ蜉�	繧ｴ繝ｼ繝ｫ縺ｫ蜈･繧翫″繧九◆繧�
			path_memory[count + 1].element.flag = FALSE;		//邯夊｡後ヵ繝ｩ繧ｰ繧呈釜縺｣縺ｦ縺翫￥
			break;
		}

		//蟾ｦ
		if ((path_x - 1) >= 0) {	//path_x-1,path_y縺ｮ蠎ｧ讓吶′霑ｷ霍ｯ蜀�(0莉･荳�)縺ｧ縺ゅｋ
			if (get_step(path_x - 1, path_y) < get_step(path_x, path_y)) {//豁ｩ謨ｰ縺ｮ蟆上＆縺�縺ｻ縺�縺ｸ
				if ((map::get_wall(path_x, path_y, MUKI_LEFT) == false)) {//螢√′縺ｪ縺�縺ｪ繧�
					save_direction.element.left = 1;	//谺｡縺ｫ騾ｲ繧�譁ｹ蜷代�ｮ驕ｸ謚櫁い縺ｫ霑ｽ蜉�
					if ((path_direction_x == -1) && (path_direction_y == 0)) {//蟾ｦ繧貞髄縺�縺ｦ繧九→縺搾ｼ育峩騾ｲ縺ｧ縺阪ｋ縺ｨ縺搾ｼ�
						straight_flag = true;	//逶ｴ騾ｲ繝輔Λ繧ｰ繧偵◆縺ｦ繧�
					}
				}
			}

		}

		//蜿ｳ
		if ((path_x + 1) < MAZE_SIZE) {	//path_x+1,path_y縺ｮ蠎ｧ讓吶′霑ｷ霍ｯ蜀�縺ｧ縺ゅｋ
			if (get_step(path_x + 1, path_y) < get_step(path_x, path_y)) {//豁ｩ謨ｰ縺ｮ蟆上＆縺�縺ｻ縺�縺ｸ
				if ((map::get_wall(path_x, path_y, MUKI_RIGHT) == false)) {	//螢√′縺ｪ縺�縺ｪ繧�
					save_direction.element.right = 1;	//谺｡縺ｫ騾ｲ繧�譁ｹ蜷代�ｮ驕ｸ謚櫁い縺ｫ霑ｽ蜉�
					if ((path_direction_x == 1) && (path_direction_y == 0)) {//蜿ｳ繧貞髄縺�縺ｦ繧九→縺搾ｼ育峩騾ｲ縺ｧ縺阪ｋ縺ｨ縺搾ｼ�
						straight_flag = true;	//逶ｴ騾ｲ繝輔Λ繧ｰ繧偵◆縺ｦ繧�
					}
				}
			}
		}

		//荳�
		if ((path_y - 1) >= 0) {	//path_x,path_y-1縺ｮ蠎ｧ讓吶′霑ｷ霍ｯ蜀�(0莉･荳�)縺ｧ縺ゅｋ
			if (get_step(path_x, path_y - 1) < get_step(path_x, path_y)) {//豁ｩ謨ｰ縺ｮ蟆上＆縺�縺ｻ縺�縺ｸ
				if ((map::get_wall(path_x, path_y, MUKI_DOWN) == false)) {//螢√′縺ｪ縺�縺ｪ繧�
					save_direction.element.down = 1;	//谺｡縺ｫ騾ｲ繧�譁ｹ蜷代�ｮ驕ｸ謚櫁い縺ｫ霑ｽ蜉�
					if ((path_direction_x == 0) && (path_direction_y == -1)) {//荳九ｒ蜷代＞縺ｦ繧九→縺搾ｼ育峩騾ｲ縺ｧ縺阪ｋ縺ｨ縺搾ｼ�
						straight_flag = true;	//逶ｴ騾ｲ繝輔Λ繧ｰ繧偵◆縺ｦ繧�
					}
				}
			}
		}

		//荳�
		if ((path_y + 1) < MAZE_SIZE) {	//path_x,path_y+1縺ｮ蠎ｧ讓吶′霑ｷ霍ｯ蜀�(16莉･荳�)縺ｧ縺ゅｋ
			if (get_step(path_x, path_y + 1) < get_step(path_x, path_y)) {//豁ｩ謨ｰ縺ｮ蟆上＆縺�縺ｻ縺�縺ｸ
				if ((map::get_wall(path_x, path_y, MUKI_UP) == false)) {//螢√′縺ｪ縺�縺ｪ繧�
					save_direction.element.up = 1;	//谺｡縺ｫ騾ｲ繧�譁ｹ蜷代�ｮ驕ｸ謚櫁い縺ｫ霑ｽ蜉�
					if ((path_direction_x == 0) && (path_direction_y == 1)) {//荳翫ｒ蜷代＞縺ｦ繧九→縺搾ｼ育峩騾ｲ縺ｧ縺阪ｋ縺ｨ縺搾ｼ�
						straight_flag = true;	//逶ｴ騾ｲ繝輔Λ繧ｰ繧偵◆縺ｦ繧�
					}
				}
			}
		}

		if (straight_flag) {			//逶ｴ騾ｲ縺ｧ縺阪ｋ縺ｪ繧�
			path_memory[count].element.distance += 2;			//蜊雁玄髢鍋峩騾ｲ*2 繧定ｿｽ蜉�

		} else {								//繧ｿ繝ｼ繝ｳ縺吶ｋ縺ｪ繧�
			path_memory[count].element.turn = 1;						//蟆丞屓繧翫ち繝ｼ繝ｳ

			if (path_direction_x == 0) {				//荳翫°荳句髄縺阪�ｮ縺ｨ縺�
				//蜿ｳ縺ｫ陦後″縺溘＞
				if (save_direction.element.right == 1) {
					if (path_direction_y == 1) {	//荳翫ｒ蜷代＞縺ｦ繧�
						//蜿ｳ蜷代″繧ｿ繝ｼ繝ｳ
						path_memory[count].element.muki = MUKI_RIGHT;
					} else {					//荳九ｒ蜷代＞縺ｦ繧�
						//蟾ｦ蜷代″繧ｿ繝ｼ繝ｳ
						path_memory[count].element.muki = MUKI_LEFT;
					}
					//蟾ｦ縺ｫ陦後″縺溘＞
				} else {
					if (path_direction_y == -1) {	//荳九ｒ蜷代＞縺ｦ繧�
						//蜿ｳ蜷代″繧ｿ繝ｼ繝ｳ
						path_memory[count].element.muki = MUKI_RIGHT;
					} else {					//荳翫ｒ蜷代＞縺ｦ繧�
						//蟾ｦ蜷代″繧ｿ繝ｼ繝ｳ
						path_memory[count].element.muki = MUKI_LEFT;
					}
				}

			} else {										//蜿ｳ縺句ｷｦ蜷代″縺ｮ縺ｨ縺�
				//荳翫↓陦後″縺溘＞
				if (save_direction.element.up == 1) {
					if (path_direction_x == -1) {	//蟾ｦ繧貞髄縺�縺ｦ繧�
						//蜿ｳ蜷代″繧ｿ繝ｼ繝ｳ
						path_memory[count].element.muki = MUKI_RIGHT;
					} else {					//蜿ｳ繧貞髄縺�縺ｦ繧�
						//蟾ｦ蜷代″繧ｿ繝ｼ繝ｳ
						path_memory[count].element.muki = MUKI_LEFT;
					}
					//荳九↓陦後″縺溘＞
				} else {
					if (path_direction_x == 1) {	//蜿ｳ繧貞髄縺�縺ｦ繧�
						//蜿ｳ蜷代″繧ｿ繝ｼ繝ｳ
						path_memory[count].element.muki = MUKI_RIGHT;
					} else {					//蟾ｦ繧貞髄縺�縺ｦ繧�
						//蟾ｦ蜷代″繧ｿ繝ｼ繝ｳ
						path_memory[count].element.muki = MUKI_LEFT;
					}
				}
			}
			//繧ｿ繝ｼ繝ｳ縺ｫ繧医ｋ譁ｹ蜷台ｿｮ豁｣
			direction_turn(&path_direction_x, &path_direction_y,
					path_memory[count].element.muki);

			count++;
			path_memory[count].element.flag = TRUE;			//繝代せ縺檎ｶ壹￥縺ｮ縺ｪ繧臥ｶ夊｡後ヵ繝ｩ繧ｰ繧貞ｻｺ縺ｦ繧�

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
		//逶ｴ邱�
		myprintf("distance -> %2d *", path_memory[i].element.distance);
		if (MOUSE_MODE == 1)								//繝上�ｼ繝輔�ｯ蜊雁玄髢薙′45mm
			myprintf("45mm\n\r");
		else
			myprintf("90mm\n\r");

		//繧ｿ繝ｼ繝ｳ
		//myprintf("turn -> %2d ", path_memory[i].element.turn);	//譬ｼ邏阪＠縺ｦ縺�繧句�､繧定｡ｨ遉ｺ
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
//path縺後≠繧九↑繧液rue,縺ｪ縺�縺ｪ繧映alse繧定ｿ斐☆
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
	signed char temp_direction_x = (*direction_x);	//莉悶�ｮ蝣ｴ謇�縺ｫ菫晏ｭ倥＠縺ｪ縺�縺ｨ螟画鋤騾比ｸｭ縺ｧ蜿ら�ｧ縺吶ｋ鄒ｽ逶ｮ縺ｫ縺ｪ繧�
	signed char temp_direction_y = (*direction_y);
	if (direction_turn_muki == MUKI_LEFT) {
		*direction_x = (temp_direction_x) * 0 + (temp_direction_y) * (-1);//蝗櫁ｻ｢陦悟�励�ｮﾎｸ=90縺ｮ險育ｮ�
		*direction_y = (temp_direction_x) * 1 + (temp_direction_y) * 0;	//蝗櫁ｻ｢陦悟�励�ｮﾎｸ=90縺ｮ險育ｮ�
	} else {
		*direction_x = (temp_direction_x) * 0 + (temp_direction_y) * 1;	//蝗櫁ｻ｢陦悟�励�ｮﾎｸ=-90縺ｮ險育ｮ�
		*direction_y = (temp_direction_x) * (-1) + (temp_direction_y) * 0;//蝗櫁ｻ｢陦悟�励�ｮﾎｸ=-90縺ｮ險育ｮ�
	}

}

std::pair<int8_t, int8_t> compas_to_direction(compas tar) {
	//TODO 譁懊ａ
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
	}
	return ans;
}

compas direction_to_compas(std::pair<int8_t, int8_t> tar) {
	//TODO 譁懊ａ
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

//隕九※縺�縺ｪ縺�驛ｨ蛻�縺ｫ縺ｯ譖ｸ縺崎ｾｼ繧√↑縺�
	if (by_known) {
		if (!map::check_exist(double_x / 2, y, def_muki))
			return false;
	}

//驟榊�励�ｮ隕∫ｴ�螟悶↑繧我ｽ輔ｂ縺励↑縺�
	if (is_outside_array(double_x, y))
		return false;

//螢√′縺ゅｋ驛ｨ蛻�縺ｫ縺ｯ譖ｸ縺崎ｾｼ繧√↑縺�
	if (map::get_wall(double_x / 2, y, def_muki))
		return false;

//譖ｸ縺崎ｾｼ繧�豁ｩ謨ｰ繧医ｊ蟆上＆縺�蝣ｴ謇�縺ｫ縺ｯ譖ｸ縺崎ｾｼ繧√↑縺�
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
//莉｣蜈･逕ｨ縺ｮ螟画焚
	uint8_t step_x = x;
	uint8_t step_y = y;

	switch (muki) {
	//蜊怜髄縺阪→隘ｿ蜷代″縺ｫ螟画峩縺励※繧�繧翫↑縺翫＠
	case north:
		step_y++;	//y繧�1縺､蠅励ｄ縺励※蜊怜髄縺肴桶縺�縺ｫ
		step_x = 2 * x + 1;	//蜊怜髄縺阪□縺ｨ讓ｪ蜷代″縺ｮ螢√↑縺ｮ縺ｧ縲』譁ｹ蜷代′2x+1
		break;
	case south:
		step_x = 2 * x + 1;	//蜊怜髄縺阪□縺ｨ讓ｪ蜷代″縺ｮ螢√↑縺ｮ縺ｧ縲』譁ｹ蜷代′2x+1
		break;
	case east:
		step_x = 2 * (x + 1);	//x繧�1縺､蠅励ｄ縺励※縲∬･ｿ蜷代″謇ｱ縺�縲�邵ｦ蜷代″縺ｮ螢√↑縺ｮ縺ｧ縲』譁ｹ蜷代�ｯ2x
		break;
	case west:
		step_x = 2 * x;	//隘ｿ蜷代″縺�縺ｨ邵ｦ蜷代″縺ｮ螢√↑縺ｮ縺ｧ縲』譁ｹ蜷代�ｯ2x
		break;

	default:		//譁懊ａ縺ｯ髱槫ｯｾ蠢�
		return false;
	}

//譖ｸ縺崎ｾｼ繧√ｋ縺ｪ繧�
	if (able_set_step(step_x, step_y, muki, step_val, by_known)) {
		step[step_x][step_y] = step_val;	//驟榊�励↓豁ｩ謨ｰ莉｣蜈･
		return true;
	}

	return false;
}

bool node_step::set_step_double(uint8_t _double_x, uint8_t _double_y,
		uint16_t step_val, bool by_known) {
	//莉｣蜈･逕ｨ縺ｮ螟画焚
	uint8_t step_x = _double_x;
	uint8_t step_y = static_cast<uint8_t>(_double_y / 2);

	compas muki = south;
	if (step_x % 2 == 0)
		muki = west;

	//譖ｸ縺崎ｾｼ繧√ｋ縺ｪ繧�
	if (able_set_step(step_x, step_y, muki, step_val, by_known)) {
		step[step_x][step_y] = step_val;	//驟榊�励↓豁ｩ謨ｰ莉｣蜈･
		return true;
	}
	return false;

}

uint16_t node_step::get_step(uint8_t x, uint8_t y, compas muki) {
//莉｣蜈･逕ｨ縺ｮ螟画焚
	uint8_t step_x = x;
	uint8_t step_y = y;

	switch (muki) {
//蜊怜髄縺阪→隘ｿ蜷代″縺ｫ螟画峩縺励※繧�繧翫↑縺翫＠縺ｦ邨ゆｺ�
	case north:
		step_y++;	//1縺､蠅励ｄ縺励※蜊怜髄縺肴桶縺�縺ｫ縲�
		step_x = 2 * x + 1;	//蜊怜髄縺阪□縺ｨ讓ｪ蜷代″縺ｮ螢√↑縺ｮ縺ｧ縲』譁ｹ蜷代′2x+1
		break;
	case south:
		step_x = 2 * x + 1;	//蜊怜髄縺阪□縺ｨ讓ｪ蜷代″縺ｮ螢√↑縺ｮ縺ｧ縲』譁ｹ蜷代′2x+1
		break;
	case east:
		step_x = 2 * (x + 1);	//1縺､蠅励ｄ縺励※隘ｿ蜷代″謇ｱ縺�縺ｫ縲らｸｦ蜷代″縺ｮ螢√↑縺ｮ縺ｧ縲』譁ｹ蜷代�ｯ2x
		break;
	case west:
		step_x = 2 * x;	//隘ｿ蜷代″縺�縺ｨ邵ｦ蜷代″縺ｮ螢√↑縺ｮ縺ｧ縲』譁ｹ蜷代�ｯ2x
		break;
	default:	//譁懊ａ縺ｯ髱槫ｯｾ蠢�
		return init_step;
		break;
	}

//驟榊�励�ｮ隕∫ｴ�螟悶ｒ隱ｭ縺ｿ縺�縺吶→縺阪�ｯInit_step繧�
	if (is_outside_array(step_x, step_y))
		return init_step;

	return step[step_x][step_y];	//驟榊�励°繧画ｭｩ謨ｰ蜿ら�ｧ
}

uint16_t node_step::get_step_double(uint8_t double_x, uint8_t double_y) {
	//莉｣蜈･逕ｨ縺ｮ螟画焚
	uint8_t step_x = double_x;
	uint8_t step_y = double_y / 2;

	//驟榊�励�ｮ隕∫ｴ�螟悶ｒ隱ｭ縺ｿ縺�縺吶→縺阪�ｯInit_step繧�
	if (is_outside_array(step_x, step_y))
		return init_step;

	return step[step_x][step_y];	//驟榊�励°繧画ｭｩ謨ｰ蜿ら�ｧ

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
		//////////////////////////////////////////霑ｷ霍ｯ縺ｮ螢√�ｮ陦�
		for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++) {
			myprintf("+");	//譟ｱ
			if (get_wall(tekitou_x, tekitou_y, MUKI_UP)) {	//螢√′縺ゅｋ縺ｪ繧�
				myprintf("---");
			} else {
				if (get_step(tekitou_x, tekitou_y, north) == init_step)
					myprintf("   ");	//蛻晄悄蛟､縺ｪ繧臥ｩｺ逋ｽ縺ｫ
				else
					myprintf("%3d", get_step(tekitou_x, tekitou_y, north));	//縺ｪ縺代ｌ縺ｰ豁ｩ謨ｰ繧呈嶌縺�
			}
		}
		myprintf("+\n\r");

		/////////////////////////////////////////霑ｷ霍ｯ縺ｮ繝槭せ逶ｮ縺ｮ陦�
		myprintf("| ");	//蟾ｦ遶ｯ縺ｮ螢�
		for (tekitou_x = 0; tekitou_x < MAZE_SIZE; tekitou_x++) {
			myprintf(" ");		//蛹ｺ逕ｻ荳ｭ蠢�縺ｮ繧ｹ繝壹�ｼ繧ｹ
			if (get_wall(tekitou_x, tekitou_y, MUKI_RIGHT)) {//莉頑嶌縺�縺溘�槭せ縺ｮ蜿ｳ縺ｮ螢√′縺ゅｌ縺ｰ螢√ｒ譖ｸ縺�
				myprintf(" | ");
			} else {
				if (get_step(tekitou_x, tekitou_y, east) == init_step)
					myprintf("   ");	//蛻晄悄蛟､縺ｪ繧臥ｩｺ逋ｽ縺ｫ
				else
					myprintf("%3d", get_step(tekitou_x, tekitou_y, east));//縺ｪ縺代ｌ縺ｰ豁ｩ謨ｰ繧呈嶌縺�
			}
		}
		myprintf("\n\r");
	}

//荳玖ｾｺ	霑ｷ霍ｯ縺ｮ遶ｯ縺ｯ螢√＠縺九↑縺�縺ｯ縺�
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
	static const std::vector<uint8_t> temp_s { 21, 20, 19, 18, 17, 16, 9, 4 }; //逶ｴ騾ｲ譁ｹ蜷代�ｮ驥阪∩縺･縺�
	static const std::vector<uint8_t> temp_o { 15, 14, 13, 12, 11, 10, 9, 4 }; //譁懊ａ譁ｹ蜷代�ｮ驥阪∩縺･縺�
	static const std::vector<uint8_t> temp_c { 0, 10, 14 }; //繧ｫ繝ｼ繝悶↓髢｢縺吶ｋ驥阪∩縺･縺代��0ﾂｰ,45ﾂｰ,90ﾂｰ縺ｮ鬆�逡ｪ

	algo = weight;

	switch (get_weight_algo()) {
	case weight_algo::adachi:
		//譁懊ａ繧ら峩騾ｲ繧る㍾縺ｿ縺ｯ1
		std::vector<uint8_t>().swap(straight_w);
		straight_w.emplace_back(1);
		std::vector<uint8_t>().swap(oblique_w);
		oblique_w.emplace_back(1);
		curve_w = std::vector<uint8_t> { 0, 0, 0 };
		break;

	case weight_algo::based_distance:
		//譁懊ａ縺ｨ逶ｴ騾ｲ縺ｯ1:竏�2縺ｮ驥阪∩
		std::vector<uint8_t>().swap(straight_w);
		straight_w.emplace_back(7);
		std::vector<uint8_t>().swap(oblique_w);
		oblique_w.emplace_back(5);
		curve_w = std::vector<uint8_t> { 0, 0, 0 };
		break;

	case weight_algo::priority_straight:
		straight_w = (temp_s);	//staright_w縺ｫ莉｣蜈･
		oblique_w = (temp_o);	//oblique_w縺ｫ莉｣蜈･
		curve_w = std::vector<uint8_t> { 0, 0, 0 };
		break;

	case weight_algo::T_Wataru_method:		//譁懊ａ縺ｫ繧る㍾縺ｿ縺後≠繧�
		straight_w = (temp_s);		//staright_w縺ｫ莉｣蜈･
		oblique_w = (temp_o);		//oblique_w縺ｫ莉｣蜈･
		curve_w = temp_c;
		break;

	}

}

weight_algo node_search::get_weight_algo() {
	return algo;
}

void node_search::spread_step(std::vector<std::pair<uint8_t, uint8_t> > finish,
		bool by_known) {
	bool debranch = false;	//譫晏��縺吶ｋ縺句凄縺�

//蠎ｧ讓咏ｮ｡逅�縺ｯ豁ｩ謨ｰ縺ｮ驟榊��(X譁ｹ蜷代□縺大��)縺ｨ逡ｰ縺ｪ繧街,Y譁ｹ蜷台ｸ｡譁ｹ縺ｧ蛟阪↓縺吶ｋ縲�髫｣謗･蠎ｧ讓吶�ｮ蜿悶ｊ謇ｱ縺�縺梧･ｽ縺�縺九ｉ
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
	} dir;			//譁ｹ蜷醍ｮ｡逅�逕ｨ縲�int8_t縺ｧxy荳｡譁ｹ邂｡逅�縺励◆縺九▲縺�

	union _dir temp_dir;

	my_queue x_queue;		//蠎ｧ讓咏ｮ｡逅�逕ｨQueue
	my_queue y_queue;		//蠎ｧ讓咏ｮ｡逅�逕ｨQueue
	my_queue dir_queue;		//譁ｹ蜷醍ｮ｡逅�逕ｨQueue
	uint8_t x, y;		//2蛟榊ｺｧ讓�

	//繝槭え繧ｹ縺ｮ縺�繧句ｺｧ讓�
	uint8_t mouse_x = mouse::get_x_position();
	uint8_t mouse_y = mouse::get_y_position();
	uint16_t mouse_step = get_step(mouse_x, mouse_y,
			get_min_compas(mouse_x, mouse_y));

//豁ｩ謨ｰ繧偵Μ繧ｻ繝�繝�
	node_step::reset_step(init_step);

//逶ｮ讓吝ｺｧ讓吶ｒ譛�蛻昴↓繧ｭ繝･繝ｼ縺ｫ縺ｶ縺｡霎ｼ繧�
	for (uint16_t index = 0; index < finish.size(); index++) {
		for (int i = -1; i < 2; i += 2) {
			x = 2 * finish.at(index).first + 1;
			y = 2 * finish.at(index).second + 1;
			if (set_step_double(x + i, y, 0, by_known)) {
				x_queue.push(x + i);
				y_queue.push(y);
				dir.set(i, 0);
				dir_queue.push(dir.xy);
				//譁ｹ蜷代ｂ險倬鹸
			}
			if (set_step_double(x, y + i, 0, by_known)) {
				x_queue.push(x);
				y_queue.push(y + i);
				dir.set(0, i);
				dir_queue.push(dir.xy);
				//譁ｹ蜷代ｂ險倬鹸
			}
		}
	}

	uint16_t next_step = 0;	//谺｡縺ｮ豁ｩ謨ｰ
	int8_t dx, dy;	//谺｡縺ｫ陦後￥譁ｹ蜷�
	int8_t curve_index;	//繧ｿ繝ｼ繝ｳ縺ｮ遞ｮ鬘槭ｒ蛻､蛻･縺吶ｋ

//逶ｴ騾ｲ縺吶ｋ豁ｩ謨ｰ縺ｮ驥阪∩繧堤ｮ｡逅�
	uint8_t straight;
	loop = 0;
	while (x_queue.size() != 0) {
		loop++;

		//繧ｭ繝･繝ｼ縺九ｉ蠎ｧ讓吶ｒ蜿悶ｊ蜃ｺ縺�
		x = x_queue.pop();	//蜿悶ｊ蜃ｺ縺励※蜑企勁
		y = y_queue.pop();	//蜿悶ｊ蜃ｺ縺励※蜑企勁
		next_step = get_step_double(x, y);
		mouse_step = get_step(mouse_x, mouse_y,
				get_min_compas(mouse_x, mouse_y));

		//繧ｭ繝･繝ｼ縺九ｉ譁ｹ蜷代ｒ蜿悶ｊ蜃ｺ縺�
		dir.xy = dir_queue.pop();	//蜿悶ｊ蜃ｺ縺励※蜑企勁

		//迴ｾ蝨ｨ縺ｮ繝槭せ繧医ｊ豁ｩ謨ｰ縺悟､ｧ縺阪￥縺ｪ繧九↑繧画椌蛻�繧翫��by_known=true縺､縺ｾ繧翫ヱ繧ｹ逕滓�先凾縺ｫ縺ｯ陦後ｏ縺ｪ縺�縲�繝舌げ諤悶＞縺九ｉ
		if (debranch && (next_step > mouse_step)) {
			//菴輔ｂ縺励↑縺�
		} else {
			temp_dir.xy = dir.xy;
			for (int n = -1; n <= 1; n++) {
				next_step = get_step_double(x, y);
				//谺｡縺ｫ陦後￥譁ｹ蜷代�ｯ3繝代ち繝ｼ繝ｳ縺励°隕九↑縺�縲�蛹ｺ逕ｻ荳ｭ蠢�繧医ｊ莉翫�ｮ譁ｹ蜷大�ｴ縺ｫ縺ゅｋ3遞ｮ縲�ex.now(1,1)縺ｪ繧嬰x>0縺ｮ(1,1)(2,0)(-1,0)
				//縺､縺ｾ繧九→縺薙ｍ縲√％縺薙�ｮ豁ｩ謨ｰ縺ｫ縺溘←繧顔捩縺冗峩蜑阪〒蛟呵｣懊↓縺ゅ▲縺溘ｄ縺､繧峨�ｯ縲√◎縺ｮ譎ゅ↓陦後▲縺溘⊇縺�縺梧掠縺�縺ｫ豎ｺ縺ｾ縺｣縺ｦ繧九�ｮ縺ｧ辟｡隕�
				temp_dir = dir;
				if (!(x % 2)) {		//邵ｦ螢√�ｮ譎�
					dx = (2 - ABS(n)) * SIGN(dir.x);
					dy = n;
					curve_index = ABS(dir.y - dy);		//0縺檎峩騾ｲ縲�1縺�45ﾂｰ縲�2縺�90ﾂｰ
					temp_dir.y = n;
				} else {			//邵ｦ縺ｧ縺ｪ縺代ｌ縺ｰ讓ｪ�ｼ�y%2==0�ｼ峨＠縺九↑縺�
					dx = n;
					dy = (2 - ABS(n)) * SIGN(dir.y);
					curve_index = ABS(dir.x - dx);			//0縺檎峩騾ｲ縲�1縺�45ﾂｰ縲�2縺�90ﾂｰ
					temp_dir.x = n;
				}
				next_step += curve_w.at(curve_index);	//繧ｫ繝ｼ繝悶☆繧九％縺ｨ縺ｫ蟇ｾ縺吶ｋ驥阪∩繧定ｶｳ縺�

//縺昴�ｮ逶ｴ邱壽婿蜷代↓縲∵嶌縺崎ｾｼ繧√↑縺上↑繧九∪縺ｧ譖ｸ縺崎ｾｼ繧薙〒縺�縺�
				for (uint8_t i = 0;; i++) {
//逶ｴ邱壹′邯壹￥縺ｨ雜ｳ縺励※縺�縺乗ｭｩ謨ｰ縺ｯ蟆上＆縺上↑縺｣縺ｦ縺�縺�
					if (n == 0) {		//蛹ｺ逕ｻ繧呈ｨｪ蛻�繧九→縺�
						if (i < straight_w.size())
							straight = straight_w.at(i);//隕∫ｴ�螟悶↓蜃ｺ繧句�ｴ蜷医�ｯ蛟､繧呈峩譁ｰ縺励↑縺�ｼ晄怙蠕後�ｮ蛟､縺檎ｶ壹￥
					} else {			//譁懊ａ譁ｹ蜷代�ｮ逶ｴ騾ｲ縺ｮ縺ｨ縺�
						if (i < oblique_w.size())
							straight = oblique_w.at(i);	//隕∫ｴ�螟悶↓蜃ｺ繧句�ｴ蜷医�ｯ蛟､繧呈峩譁ｰ縺励↑縺�ｼ晄怙蠕後�ｮ蛟､縺檎ｶ壹￥
					}
//豁ｩ謨ｰ繧呈嶌縺崎ｾｼ繧√◆繧峨�∵嶌縺崎ｾｼ繧薙□蠎ｧ讓吶ｒQueue縺ｫ縺ｶ縺｣縺薙�
					if (set_step_double(x + dx * (i + 1), y + dy * (i + 1),
							(next_step + straight), by_known)) {
						next_step += straight;		//繧ｹ繝�繝�繝励ｒ譖ｴ譁ｰ
						x_queue.push(x + (i + 1) * dx);
						y_queue.push(y + (i + 1) * dy);
						dir_queue.push(temp_dir.xy);
					} else {
						break;	//譖ｸ縺崎ｾｼ繧√↑縺上↑縺｣縺溘ｉ繝ｫ繝ｼ繝励ｒ謚懊￠繧�
					}
//逶ｴ邱壹′邯壹￥縺薙→縺ｫ繧医ｋ驥阪∩縺ｮ貂帛ｰ代′縺ｪ縺�縺ｪ繧我ｸ�蝗槭□縺代〒謚懊￠繧�
					if (algo == adachi || algo == based_distance) {
						break;
					}
//譫晏��繧�
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
//豁ｩ謨ｰ繝槭ャ繝嶺ｽ懆｣ｽ
	node_step::reset_step(init_step);
	spread_step(finish, true);	//縺薙％縺ｯ譌｢遏･螢√□縺代〒豁ｩ謨ｰ繝槭ャ繝嶺ｽ懆｣ｽ
	return node_path::create_path(init, mouse_direction);	//豁ｩ謨ｰ繝槭ャ繝励↓蠕薙▲縺ｦ繝代せ菴懆｣ｽ

}

bool node_search::create_big_path(
		std::vector<std::pair<uint8_t, uint8_t> > finish,
		std::pair<uint8_t, uint8_t> init, compas mouse_direction) {
	if (create_small_path(finish, init, mouse_direction)) {	//蟆丞屓繧翫ヱ繧ｹ菴懆｣ｽ
		node_path::improve_path();	//蟆丞屓繧翫ｒ螟ｧ蝗槭ｊ繝代せ縺ｫ謾ｹ濶ｯ
		return true;
	}
	return false;
}

void node_search::reset_finish() {
//逶ｮ逧�蝨ｰ諠�蝣ｱ繧偵☆縺ｹ縺ｦ繝ｪ繧ｻ繝�繝�
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
		if (set_x == 0)		//荳�逡ｪ蟾ｦ縺ｯ蟶ｸ縺ｫ螟門｣√↑縺ｮ縺ｧ辟｡隕�
			return;
		else
			set_x--;		//蠢�縺壼承繧呈峩譁ｰ
	}
	if (dir == east || dir == west) {
		if (set_x < MAZE_SIZE)
			set_maze_wall(&x_finish[set_y], set_x, true);//x_finish[y]縺ｮx逡ｪ逶ｮ縺ｮ蜿ｳ蛹ｺ逕ｻ荳ｭ蠢�
		return;
	}

	if (dir == south) {
		if (set_y == 0) 		//荳�逡ｪ荳句｣√�ｯ邂｡逅�縺励↑縺�
			return;
		else
			set_y--;	//蠢�縺壻ｸ雁｣√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�

	}
	if (dir == south || dir == north) {
		if (set_y < MAZE_SIZE)
			set_maze_wall(&y_finish[set_x], set_y, true);//x_maze_wall[y]縺ｮx逡ｪ逶ｮ縺ｮ蜿ｳ螢√↓1繧剃ｻ｣蜈･
		return;
	}

}

bool node_search::get_finish(uint8_t _x, uint8_t _y, compas dir) {
	uint8_t get_x = _x;
	uint8_t get_y = _y;

	if (dir == east) {
		if (get_x == 0)		//荳�逡ｪ蟾ｦ縺ｯ蟶ｸ縺ｫ螟門｣√↑縺ｮ縺ｧ辟｡隕�
			return false;	//螢√↑縺ｮ縺ｧ繧ｴ繝ｼ繝ｫ蠎ｧ讓吶→縺励※縺ｯ荳埼←
		else
			get_x--;		//蠢�縺壼承繧呈峩譁ｰ
	}
	if (dir == east || dir == west) {
		if (get_x < MAZE_SIZE)
			return get_maze_wall(x_finish[get_y], get_x);//x_finish[y]縺ｮx逡ｪ逶ｮ縺ｮ蜿ｳ蛹ｺ逕ｻ荳ｭ蠢�
	}

	if (dir == south) {
		if (get_y == 0) 		//荳�逡ｪ荳句｣√�ｯ邂｡逅�縺励↑縺�
			return false;
		else
			get_y--;	//蠢�縺壻ｸ雁｣√ｒ譖ｴ譁ｰ縺吶ｋ繧医≧縺ｫ縲∝ｺｧ讓吶ｒ螟峨∴繧�

	}
	if (dir == south || dir == north) {
		if (get_y < MAZE_SIZE)
			return get_maze_wall(y_finish[get_x], get_y);//x_maze_wall[y]縺ｮx逡ｪ逶ｮ縺ｮ蜿ｳ螢√↓1繧剃ｻ｣蜈･
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
	}

	return ans;

}

bool node_path::is_right_turn(compas now, compas next) {
	switch (now) {
	case north:
		if (next == east)
			return true;
		else
			return false;
		break;

	case south:
		if (next == west)
			return true;
		else
			return false;
		break;

	case east:
		if (next == south)
			return true;
		else
			return false;
		break;

	case west:
		if (next == north)
			return true;
		else
			return false;
		break;
	}
	return false;
}

void node_path::format() {
	//distance=0, sla_type=none, is_right=true縲�繧�1縺､縺�縺醍畑諢上＠縲√◎繧後〒path繧貞�晄悄蛹�
	std::vector<path_element>().swap(path);
	path_element init = { 0, none, true };
	path.emplace_back(init);
}

void node_path::push_straight(int half) {
	(path.back()).distance += half;	//逶ｴ邱壹ｒ蠅励ｄ縺�
}

void node_path::push_small_turn(bool is_right) {
	(path.back()).turn = small;		//遞ｮ鬘槭�ｯ蟆丞屓繧�
	(path.back()).is_right = is_right;		//蜿ｳ蜷代″

	path_element temp = { 0, none, true };
	path.emplace_back(temp);		//谺｡縺ｮ隕∫ｴ�繧剃ｽ懊▲縺ｦ縺翫￥

}

bool node_path::create_path(std::pair<uint8_t, uint8_t> init,
		compas mouse_direction) {
	node_path::format();				//繝代せ繧貞�晄悄蛹�
	node_path::push_straight(1);				//蛹ｺ逕ｻ荳ｭ蠢�縺ｫ縺�繧区Φ螳壹↑縺ｮ縺ｧ蜊雁玄髢灘燕騾ｲ

//蜷代°縺｣縺ｦ縺�繧区婿蜷代�ｮ豁ｩ謨ｰ縺悟�晄悄蛟､縺ｪ繧峨��驕薙′髢峨§縺ｦ縺�繧九�ｮ縺ｧ邨ゆｺ�
	uint16_t now_step = get_step(init.first, init.second, mouse_direction);
	if (now_step >= init_step)
		return false;

//豁ｩ謨ｰ縺ｮ菴弱＞譁ｹ縺ｸ荳九▲縺ｦ縺�縺�
	compas now_compas = mouse_direction;
	uint8_t now_x = init.first;
	uint8_t now_y = init.second;
	int8_t dx, dy;
	uint16_t next_step = now_step;
	compas next_compas = now_compas;
	while (now_step != 0) {

		//谺｡縺ｮ譁ｹ隗偵∈繝槭せ繧堤ｧｻ蜍輔��窶ｻ蛹ｺ逕ｻ螟悶↓蜃ｺ繧九→縺九�ｯ縲∵ｭｩ謨ｰ繝槭ャ繝嶺ｽ懈�先凾縺ｫ縺ｯ縺倥°繧後※繧九�ｯ縺壹→菫｡縺倥※縺�繧�
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
		default:	//譁懊ａ縺ｯ莠域悄縺帙〓繧ｨ繝ｩ繝ｼ
			return false;
			break;
		}
		now_x += dx;		//X蠎ｧ讓呎峩譁ｰ
		now_y += dy;		//Y蠎ｧ讓呎峩譁ｰ

		next_compas = get_min_compas(now_x, now_y);		//谺｡縺ｫ陦後￥譁ｹ隗偵ｒ豎ｺ繧√ｋ
		next_step = get_step(now_x, now_y, next_compas);		//谺｡縺ｫ陦後￥蝣ｴ謇�縺ｮ豁ｩ謨ｰ繧ょ叙蠕�

		if (now_step <= next_step)
			return false;	//莉翫�ｮ豁ｩ謨ｰ縺梧ｬ｡陦後￥縺ｹ縺肴ｭｩ謨ｰ縺ｨ蜷後§縺九◎繧御ｻ･荳九→縺�縺�縺薙→縺ｯ縺ゅｊ蠕励↑縺�縺ｯ縺壹↑縺ｮ縺ｧ縲√→繧翫≠縺医★螟ｱ謨励＠縺ｨ縺�

		//繝代せ繧定ｿｽ蜉�
		if (now_compas == next_compas)
			node_path::push_straight(2);		//莉翫�ｮ蜷代″縺ｨ蜷後§譁ｹ蜷代↓騾ｲ繧�縺ｪ繧臥峩騾ｲ
		else
			node_path::push_small_turn(is_right_turn(now_compas, next_compas));	//繧ｿ繝ｼ繝ｳ莉･螟悶�ｮ驕ｸ謚櫁い縺ｯ縺ｪ縺�縺ｯ縺�

		now_step = next_step;		//豁ｩ謨ｰ繧呈峩譁ｰ
		now_compas = next_compas;		//譁ｹ隗偵ｒ譖ｴ譁ｰ

	}

//谺｡縺ｮ譁ｹ隗偵�ｮ螟牙喧譁ｹ蜷代ｒ蜿門ｾ�
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
	default:	//譁懊ａ縺ｫ縺ｪ繧九�ｮ縺ｯ莠域悄縺帙〓蝣ｴ蜷医□縺�
		return false;
		break;
	}

//隍�謨ｰ繝槭せ繧ｴ繝ｼ繝ｫ縺ｮ蝣ｴ蜷育畑縺ｫ縲�0縺ｮ邯壹￥髯舌ｊ逶ｴ騾ｲ
	while (1) {
		now_x += dx;		//X蠎ｧ讓呎峩譁ｰ
		now_y += dy;		//Y蠎ｧ讓呎峩譁ｰ

		if (get_step(now_x, now_y, next_compas) != 0) {	//繧ｴ繝ｼ繝ｫ螟悶↓蜃ｺ縺溘ｉ
			break;
		} else {									//繧ｴ繝ｼ繝ｫ蛹ｺ逕ｻ縺後∪縺�邯壹￥縺ｪ繧�
			node_path::push_straight(2);
		}

	}
	node_path::push_straight(1);		//蛹ｺ逕ｻ縺ｫ蜈･繧翫″繧九◆繧√↓蜊雁玄逕ｻ逶ｴ騾ｲ縺励※邨ゆｺ�

	mouse::set_position(now_x, now_y);

	return true;

}

void node_path::improve_path() {

	uint16_t count = 0;
	uint8_t temp_distance = 0;	//荳�譎ら噪縺ｪ霍晞屬菫晏ｭ�
	bool naname_flag = false;	//迴ｾ蝨ｨ讖滉ｽ薙′譁懊ａ縺九ｒ蛻､譁ｭ	ON縺ｪ繧画万繧∬ｵｰ陦御ｸｭ
	uint16_t size = path.size();

	path.at(size - 1).distance -= 1;//譛�蠕後�ｮ蛹ｺ逕ｻ縺ｮ荳ｭ蠢�縺ｾ縺ｧ蜈･繧願ｾｼ繧�縺溘ａ縺ｮ蜊雁玄髢鍋峩騾ｲ繧呈ｶ医☆縲ゅ��縺薙≧縺励※縺翫°縺ｪ縺�縺ｨ譛�蠕後′螟ｧ蝗槭ｊ縺ｫ荳ｸ繧∬ｾｼ縺ｾ繧後※貂幃�溘〒縺阪↑縺上↑繧句庄閭ｽ諤ｧ縺後≠繧九°繧�

	while (count < path.size()) {		//path縺檎ｵゅｏ繧後�ｰ邨ゆｺ�
		if (naname_flag) {		//譁懊ａ襍ｰ陦御ｸｭ縺ｪ繧�	遒ｺ螳溘↓逶ｴ騾ｲ霍晞屬(distance)縺�0縺ｮ縺ｯ縺�

			if (get_path(count + 1).element.distance >= 1) {//谺｡縺ｮ繧ｿ繝ｼ繝ｳ蠕�90mm莉･荳顔峩騾ｲ(譁懊ａ邨ゅｏ繧�)
				path.at(count).turn = end_45;		//45ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
				path.at(count + 1).distance -= 1;		//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
				naname_flag = false;
				count++;		//驟榊�励ｒ谺｡縺ｸ

			} else if (get_path(count + 2).element.distance >= 1) {	//谺｡縺ｮ谺｡縺ｮ繧ｿ繝ｼ繝ｳ蠕�90mm莉･荳顔峩騾ｲ(譁懊ａ邨ゅｏ繧�)

				if (path.at(count).is_right == path.at(count + 1).is_right) {//蜷後§譁ｹ蜷代�ｮ2蝗槭ち繝ｼ繝ｳ
					path.at(count).turn = end_135;	//135ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
					path.erase(path.begin() + count + 1);	//荳�蛟九★繧峨☆
					path.at(count + 1).distance -= 1;	//繧ｿ繝ｼ繝ｳ蠕後�ｮ逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
					naname_flag = false;
					count++;	//驟榊�励ｒ谺｡縺ｸ

				} else {								//莠､莠偵�ｮ繧ｿ繝ｼ繝ｳ(繧ｮ繧ｶ繧ｮ繧ｶ)
					path.at(count).distance += 1;				//譁懊ａ縺ｮ逶ｴ邱夊ｷ晞屬繧�1蠅励ｄ縺�
					temp_distance = path.at(count).distance;	//霍晞屬繧剃ｸ�譎ら噪縺ｫ謖√▲縺ｦ縺翫￥
					path.erase(path.begin() + count);					//荳�蛟九★繧峨☆
					path.at(count).distance = temp_distance;		//霍晞屬繧貞�･繧後↑縺翫☆

				}

			} else {									//縺ｾ縺�縺ｾ縺�譁懊ａ縺ｯ邯壹￥縺ｪ繧�
				if (count + 1 < size) {		//谺｡縺ｮ繝代せ縺悟ｭ伜惠縺吶ｋ
					if (path.at(count + 1).turn == none) {
						//譁懊ａ縺ｮ螟ｧ蝗槭ｊ縺ｧ邨ゅｏ繧九ヱ繧ｿ繝ｼ繝ｳ
						temp_distance = path.at(count).distance;//霍晞屬繧剃ｸ�譎ら噪縺ｫ謖√▲縺ｦ縺翫￥
						path.erase(path.begin() + count);		//荳�蛟九★繧峨☆
						path.at(count).distance = temp_distance;//霍晞屬繧貞�･繧後↑縺翫☆						count++;
						naname_flag = false;
					} else {
						if (path.at(count).is_right
								== path.at(count + 1).is_right) {//蜷後§譁ｹ蜷代�ｮ2蝗槭ち繝ｼ繝ｳ	繧ｳ縺ｮ蟄�
							path.at(count).turn = oblique_90;	//譁懊ａ90ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
							path.erase(path.begin() + count + 1);		//荳�蛟九★繧峨☆
							count++;		//驟榊�励ｒ谺｡縺ｸ
						} else {					//驕輔≧譁ｹ蜷代�ｮ2蝗槭ち繝ｼ繝ｳ	繧ｮ繧ｶ繧ｮ繧ｶ
							path.at(count).distance += 1;		//譁懊ａ縺ｮ逶ｴ邱夊ｷ晞屬繧�1蠅励ｄ縺�
							temp_distance = path.at(count).distance;//霍晞屬繧剃ｸ�譎ら噪縺ｫ謖√▲縺ｦ縺翫￥
							path.erase(path.begin() + count);			//荳�蛟九★繧峨☆
							path.at(count).distance = temp_distance;//霍晞屬繧貞�･繧後↑縺翫☆

						}
					}
				} else {			//TODO 譁懊ａ縺ｮ縺ｾ縺ｾ繝代せ縺檎ｵゆｺ�縺吶ｋ縲�縺ｨ繧翫≠縺医★蜈･繧翫″繧峨★縺ｫ邨ゆｺ�縺吶ｋ
//FIX_ME 譁懊ａ縺ｮ縺ｾ縺ｾ邨ゆｺ�縺吶ｋ縺ｨ縺阪�ｮ蜃ｦ逅�
					path.at(count).distance += 1;				//譁懊ａ縺ｮ逶ｴ邱夊ｷ晞屬繧�1蠅励ｄ縺�
					path.at(count).turn = none;
					count = size;							//邨ゆｺ�
				}
			}

		} else {										//譁懊ａ縺倥ｃ縺ｪ縺代ｌ縺ｰ

			if (count + 1 < size) {	//count+1縺ｧ繧ゅヱ繧ｹ縺檎ｵゅｏ繧峨↑縺�縺ｪ繧�

				if (path.at(count + 1).distance >= 1) {	//繧ｿ繝ｼ繝ｳ蠕後ｂ90mm莉･荳顔峩騾ｲ縺吶ｋ縺ｪ繧�	螟ｧ蝗槭ｊ縺ｮ繝√ぉ繝�繧ｯ繧定｡後≧
					path.at(count).turn = big_90;	//螟ｧ蝗槭ｊ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
					path.at(count).distance -= 1;	//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
					path.at(count + 1).distance -= 1;	//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�

				} else {							//繧ｿ繝ｼ繝ｳ蠕�90mm逶ｴ騾ｲ縺ｯ縺励↑縺�縺ｪ繧�

					if (path.at(count).is_right
							== path.at(count + 1).is_right) {//蜷後§譁ｹ蜷代↓譖ｲ縺後ｋ縺ｪ繧�(U繧ｿ繝ｼ繝ｳ)
						if (count + 2 < size) {		//2縺､蜈医∪縺ｧ繝代せ縺悟ｭ伜惠縺吶ｋ縺ｪ繧�
							if (path.at(count + 2).distance >= 1) {	//U繧ｿ繝ｼ繝ｳ蠕�90mm逶ｴ騾ｲ縺吶ｋ縺ｪ繧�
								path.at(count).turn = big_180;	//180ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
								path.at(count).distance -= 1;	//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
								path.at(count + 2).distance -= 1;//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
								path.erase(path.begin() + count + 1);	//荳�蛟九★繧峨☆

							} else {					//U繧ｿ繝ｼ繝ｳ蠕後☆縺先峇縺後ｋ縺ｪ繧�
								path.at(count).turn = begin_135;	//135ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
								path.at(count).distance -= 1;	//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
								path.erase(path.begin() + count + 1);	//荳�蛟九★繧峨☆
								naname_flag = true;

							}

						}
					} else {		//驕輔≧譁ｹ豕輔↓譖ｲ縺後ｋ縺ｪ繧�
						path.at(count).turn = begin_45;		//45ﾂｰ繧ｿ繝ｼ繝ｳ縺ｫ螟画峩
						path.at(count).distance -= 1;		//逶ｴ邱夊ｷ晞屬繧�90mm貂帙ｉ縺�
						naname_flag = true;

					}

				}
			}
			count++;		//驟榊�励ｒ谺｡縺ｸ
		}

		size = path.size();		//size繧呈峩譁ｰ

	}

//譛�蛻昴↓1縺､蜑翫▲縺溘°繧牙ｿ倥ｌ縺夊ｶｳ縺励※縺翫￥
	if (naname_flag)
		path.at(size - 1).distance -= 1;
	else
		path.at(size - 1).distance += 1;

}

PATH node_path::get_path(uint16_t index) {
	if (index >= path.size()) {		//隕∫ｴ�螟悶い繧ｯ繧ｻ繧ｹ遖∵ｭ｢
		path_element temp = { 0, none, true };
		PATH ans = to_PATH(temp);
		ans.element.flag = FALSE;
		return ans;
	}
	path_element tar = path.at(index);
	if ((tar.distance == 0) && (tar.turn == none)) {
//path.erase(path.begin() + index);		//逶ｴ騾ｲ縺ｪ縺励°縺､繧ｿ繝ｼ繝ｳ縺ｪ縺励�ｮ蝣ｴ蜷茨ｼ郁ｵｷ縺薙ｊ縺�繧九�ｮ縺ｯ譛ｫ蟆ｾ縺�縺代�ｮ縺ｯ縺夲ｼ峨＞繧峨↑縺�縺ｮ縺ｧ蜑企勁
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
