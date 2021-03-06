/*
 * parameter.h
 *
 *  Created on: 2016/10/23
 *      Author: Koizumi
 */

#ifndef PARAMETER_H_
#define PARAMETER_H_

#include"define.h"


#define LEAST_SQUARE_TIME	20		//ジャイロの最小二乗法を何ms出かけるか

#define LOG_COUNT 2000	//LOGをいくつとるか。最低1、0にはしないこと
#define INT_LOG_COUNT	1	//Int型のLogをいくつとるか　最低1


#define MOUSE_MODE	1	//1がハーフ,2がクラシック



#define SEARCH_VELOCITY	0.3	//探索の速度[m/s]



#include"user.h"
#include"serial.h"
#include<array>

#define RUN_MODE_NUMBER	6	//走行モードを何種類用意するか

class parameter {
private:
	static float correct_photo[2][5];			//ideal_photo[クラシックorハーフ][光学センサの向き]
	static int16_t min_wall_photo[2][5];			//壁がある時の最小値[クラシックorハーフ][光学センサの向き]
	const static TRAPEZOID straight_run[RUN_MODE_NUMBER];

public:
	static float get_correct_photo(PHOTO_TYPE _type);
	static void set_correct_photo(float val, PHOTO_TYPE _type);		//補正の修正等でcorrect_photoを書き換える　使用注意
	static int16_t get_min_wall_photo(PHOTO_TYPE _type);
	static void set_min_wall_photo(float val, PHOTO_TYPE _type);		//補正の修正等でmin_photoを書き換える　使用注意

	static float get_run_acceleration(uint8_t _select_mode);
	static float get_run_max_velocity(uint8_t _select_mode);
	static float get_run_de_acceleration(uint8_t _select_mode);
	static const TRAPEZOID* const get_run(uint8_t _select_mode);

	static float get_slalom(SLALOM_TYPE slalom_type, SLALOM_ELEMENT slalom_element,
				signed char right_or_left, unsigned char select_mode);
	static const INIT_SLALOM* const get_slalom_para(SLALOM_TYPE _type, bool is_right, uint8_t select_mode);

};



#endif /* PARAMETER_H_ */
