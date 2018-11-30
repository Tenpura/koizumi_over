/*
 * hardware.h
 *
 *  Created on: 2015/06/14
 *      Author: Koizumi
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

#include "stm32f4xx.h"
#include "define.h"
#include "extern_c.h"
#include "user.h"
#include "ad_convert.h"
#include "parameter.h"
#include"run.h"
#include <array>
#include <cmath>

#if (MOUSE_NAME == KOIZUMI_FISH)
	const std::pair<GPIO_TypeDef* const, uint16_t> UI_INPUT = std::make_pair(GPIOB, GPIO_Pin_14);
	const PHOTO_TYPE MOD_SEL_SEN = right;			/* モード送りに使うフォトセンサ */
	const PHOTO_TYPE MOD_ACT_SEN = front;		/* 実行トリガになるフォトセンサ */

#elif (MOUSE_NAME == KOIZUMI_OVER)
	const std::pair<GPIO_TypeDef* const, uint16_t> UI_INPUT = std::make_pair(GPIOB, GPIO_Pin_12);
	const PHOTO_TYPE MOD_SEL_SEN = left;			/* モード送りに使うフォトセンサ */
	const PHOTO_TYPE MOD_ACT_SEN = front_right;		/* 実行トリガになるフォトセンサ */
#endif	/* MOUSE_NAME */



//自作7セグ関連

#if (MOUSE_NAME == KOIZUMI_FISH)
	#define UI_GPIO_N	(7U)	/*	User Interface に使うLEDの個数	*/
	#define UI_GPIO_AHB1Periph ( RCC_AHB1Periph_GPIOA )
	#define UI_GPIO_AHB1Periph ( RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOH )
	static const std::array< const std::pair<GPIO_TypeDef* const, uint16_t>, UI_GPIO_N> UI_GPIO = {
		std::make_pair(GPIOB, GPIO_Pin_4),
		std::make_pair(GPIOB, GPIO_Pin_12),
		std::make_pair(GPIOC, GPIO_Pin_2),
		std::make_pair(GPIOC, GPIO_Pin_14),
		std::make_pair(GPIOC, GPIO_Pin_15),
		std::make_pair(GPIOH, GPIO_Pin_0),
		std::make_pair(GPIOH, GPIO_Pin_1)
	};
#elif (MOUSE_NAME == KOIZUMI_OVER)
	enum {
		btm_left=0, btm_right, top_left, top_right, top_front, UI_LED_N
	}UI_LED_TYPE;
	#define UI_GPIO_N	(CAST_UI(UI_LED_N))	/*	User Interface に使うLEDの個数	*/
	#define UI_GPIO_AHB1Periph ( RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOD )
	static const std::array< const std::pair<GPIO_TypeDef* const, uint16_t>, UI_GPIO_N> UI_GPIO = {
		std::make_pair(GPIOA, GPIO_Pin_8),		/* bottom left */
		std::make_pair(GPIOD, GPIO_Pin_2),		/* bottom right */
		std::make_pair(GPIOA, GPIO_Pin_11),		/* top left */
		std::make_pair(GPIOA, GPIO_Pin_14),		/* top right */
		std::make_pair(GPIOB, GPIO_Pin_10)		/* top front */
	};
	static const std::array< const std::array<const uint16_t, UI_GPIO_N>, 9> UI_GPIO_LIGHT_PTN = {{
			/*	btm_l, btm_r, top_l, top_r, top_f	*/
			{	0,		0,		0,		0,		1	},		/*	0	*/
			{	0,		1,		0,		0,		0	},		/*	1	*/
			{	0,		0,		0,		1,		0	},		/*	2	*/
			{	0,		1,		0,		1,		0	},		/*	3	*/
			{	0,		0,		1,		0,		0	},		/*	4	*/
			{	0,		1,		1,		0,		0	},		/*	5	*/
			{	0,		0,		1,		1,		0	},		/*	6	*/
			{	0,		1,		1,		1,		0	},		/*	7	*/
			{	1,		0,		0,		0,		0	}		/*	8	*/
	}};	/* 1が点灯、0が消灯　*/

#endif

//XXX TBD 名前をUI_OUTPUT的な感じにしたい。ユーザーへの通知
class my7seg {
private:
public:
	enum DIRECTION {
		front, back, right, left
	};

	static void light(const my7seg::DIRECTION direction); //up,right,leftを指定すると上辺、右辺、左辺が光る
	static void light(const unsigned char number);		//つける
	static void turn_off();		//消す

	static void light_error();		//Eと光らせる

	//repeat_count回だけ点滅する。消えてる状態で終わる
	static void blink(const unsigned char number,
			const unsigned short blink_cycle_ms,
			const unsigned short repeat_count);

	//start_numberから0までカウントダウン
	static void count_down(const unsigned char start_number,
			const unsigned short cycle_ms);

	static void init();

};

//motor関連
const uint16_t MAX_PERIOD = (840 - 1); //PWMの周波数決めのための最大カウント		84MHzで100kHzになる

enum MOTOR_SIDE {
	m_left = 0, m_right = 1, motor_count
};
static const unsigned int MOTOR_N = CAST_UI(motor_count);
static const int PWM_IN_N = 2*MOTOR_N;

#if (MOUSE_NAME == KOIZUMI_FISH)
	#define SLEEP_GPIO_AHB1Periph ( RCC_AHB1Periph_GPIOA )
	static GPIO_TypeDef* const SLEEP_GPIO = GPIOA;
	static const uint16_t SLEEP_GPIO_PIN = GPIO_Pin_2;

	#define PWM_GPIO_AHB1Periph ( RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB )
	//順番　A1,A2,B1,B2
	static std::array<GPIO_TypeDef* const,PWM_IN_N> PWM_GPIO = {GPIOA,GPIOA,GPIOB,GPIOB};
	static const std::array<uint16_t,PWM_IN_N> PWM_GPIO_PIN = {GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_7,GPIO_Pin_6};
	static std::array<uint8_t,PWM_IN_N> PWM_GPIO_PIN_SOURCE = {GPIO_PinSource0,GPIO_PinSource1,GPIO_PinSource7,GPIO_PinSource6};
	static const std::array<uint8_t , PWM_IN_N> PWM_GPIO_AF = {GPIO_AF_TIM5, GPIO_AF_TIM5, GPIO_AF_TIM4, GPIO_AF_TIM4};

	#define PWM_TIM_AHB1Periph ( RCC_APB1Periph_TIM5 | RCC_APB1Periph_TIM4 )
	static std::array<TIM_TypeDef* const, MOTOR_N> PWM_TIM = {TIM5, TIM4};

#elif (MOUSE_NAME == KOIZUMI_OVER)

	#define SLEEP_GPIO_AHB1Periph ( RCC_AHB1Periph_GPIOB )
	static GPIO_TypeDef* const SLEEP_GPIO = GPIOB;
	static const uint16_t SLEEP_GPIO_PIN = GPIO_Pin_5;

	#define PWM_GPIO_AHB1Periph ( RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB )
	//順番　A1,A2,B1,B2
	static std::array<GPIO_TypeDef* const,PWM_IN_N> PWM_GPIO = {GPIOA,GPIOB,GPIOB,GPIOB};
	static const std::array<uint16_t,PWM_IN_N> PWM_GPIO_PIN = {GPIO_Pin_15,GPIO_Pin_3,GPIO_Pin_7,GPIO_Pin_6};
	static std::array<uint8_t,PWM_IN_N> PWM_GPIO_PIN_SOURCE = {GPIO_PinSource15,GPIO_PinSource3,GPIO_PinSource7,GPIO_PinSource6};
	static const std::array<uint8_t , PWM_IN_N> PWM_GPIO_AF = {GPIO_AF_TIM2, GPIO_AF_TIM2, GPIO_AF_TIM4, GPIO_AF_TIM4};

	#define PWM_TIM_AHB1Periph ( RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM4 )
	static std::array<TIM_TypeDef* const, MOTOR_N> PWM_TIM = {TIM2, TIM4};

#endif

class motor {
private:

	static signed char right_duty, left_duty;		//duty[％]

	static const char MAX_DUTY;	 	//Dutyの最大値［％］

	static bool motor_state;		//motorが起動していればTRUE。

	motor();

public:
	static signed short get_duty_left();	//左モーターのDuty取得
	static signed short get_duty_right();	//右モーターのDuty取得

	static void set_duty(const MOTOR_SIDE side, const float set_duty);//モーターのDuty決定

	static void sleep_motor();		//モータードライバをスリープ状態に
	static void stanby_motor();		//モータードライバをスタンバイ状態に

	static bool isEnable();		//motorが起動しているかどうか

	static void init_PWM();

	~motor();
};

//gyro関連
//時計回りが正
//センサータイプを表す列挙型
typedef enum {
	axis_x = 0, axis_y = 1, axis_z = 2, dim_num
} AXIS_t;
class mpu6000 {
private:
	//レジスター定義
	static const uint16_t GYRO_XOUT_H;
	static const uint16_t GYRO_XOUT_L;
	static const uint16_t GYRO_YOUT_H;
	static const uint16_t GYRO_YOUT_L;
	static const uint16_t GYRO_ZOUT_H;
	static const uint16_t GYRO_ZOUT_L;
	static const uint16_t ACCEL_XOUT_H;
	static const uint16_t ACCEL_XOUT_L;
	static const uint16_t ACCEL_YOUT_H;
	static const uint16_t ACCEL_YOUT_L;
	static const uint16_t ACCEL_ZOUT_H;
	static const uint16_t ACCEL_ZOUT_L;

	static SPI_TypeDef* use_SPI;	//使うSPIのタイプ
	static GPIO_TypeDef* cs_GPIOx;	//csをたたくIOピンのタイプ		ex)GPIOA
	const static uint16_t cs_GPIO_Pin;	//csをたたくIOピンの番号

protected:
	static uint16_t read_spi(uint16_t read_reg);		//SPI通信でregレジスタから読みだす
	static void write_spi(uint16_t reg, uint16_t data);	//SPI通信でregレジスタにdataを書き込む

public:
	static volatile int16_t get_mpu_val(SEN_TYPE sen, AXIS_t axis);	//senセンサーのaxis軸方向のデータを読む

	mpu6000();

public:
	static void init();

	~mpu6000();

};

class accelmeter: public mpu6000 {
public:
	//松井式速度推定法で用いるため
	static const uint8_t AVERAGE_COUNT;		//加速度計の平均取る回数[回]
	static const float ACCEL_PERIOD;		//加速度計の制御周期[s]
private:
	static const float REF_TIME;			//加速度計のリファレンスとる時間[s]

	static float accel_ad[AXIS_t::dim_num];		//加速度の生値
	static float accel_ref[AXIS_t::dim_num];
	static float accel[AXIS_t::dim_num];		//加速度 [m/ss]

	static float get_accel_ref(AXIS_t xyz);
	static float get_accel_ad(AXIS_t xyz);		//xyz方向の加速度[m/s]を返す

	accelmeter();

public:

	static void interrupt();
	static void set_accel_ref();
	static void set_accel_ref(AXIS_t xyz);
	static void cal_accel();	//生値を加速度に変換[m/ss]

	static float get_accel();		//進行方向の加速度[m/s]
	static float get_accel(AXIS_t xyz);		//m/sでXYZ方向の加速度を返す

};

class gyro: public mpu6000 {
private:
	static const float GYRO_PERIOD;			//ジャイロの制御周期[s]
	static const float REF_TIME;			//ジャイロのリファレンスとる時間[s]

	static int16_t gyro_value;
	static float default_angle;				//最小二乗法で補正をかけてない角度
	static float angle, gyro_ref;
	static float angular_velocity;

	static float get_gyro_ref();
	//static void set_least_square_slope();				//最小二乗法をまわして補正項を計算

	static void cal_angular_velocity();				//角速度計算[rad/s]
	static void cal_angle();				//角度計算[rad]

	gyro();

public:
	static float least_square_slope;				//補正項の傾き

	static void interrupt();		//割り込み内で呼ばれる
	static int16_t get_gyro();
	static void set_gyro_ref();
	static void set_angle(float set_rad);

	static void reset_angle();
	static float get_angle_radian();
	static float get_angular_velocity();

	~gyro();

};

//encoder
typedef enum {
	enc_right = 0, enc_left = 1, enc_count
} ENC_SIDE;
static const unsigned int ENC_N = CAST_UI(enc_count);
static const unsigned int ENC_GPIO_N = ENC_N * 2;		//1つのエンコーダにつき2チャンネル使用

#if (MOUSE_NAME == KOIZUMI_FISH)
	#define ENCODER_CONST	(1.534 * 0.001)			//encoderの分解能[rad/count]

	#define ENC_GPIO_AHB1Periph ( RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC )
	//順番　right_A,right_B,left_A,left_B
	static const std::array<GPIO_TypeDef*,ENC_GPIO_N> ENC_GPIO = {GPIOC, GPIOC, GPIOB, GPIOA};
	static const std::array<uint16_t,ENC_GPIO_N> ENC_GPIO_PIN = {GPIO_Pin_7, GPIO_Pin_6, GPIO_Pin_3, GPIO_Pin_15};
	static std::array<uint8_t,ENC_GPIO_N> ENC_GPIO_PIN_SOURCE = {GPIO_PinSource7,GPIO_PinSource6,GPIO_PinSource3,GPIO_PinSource15};
	static const std::array<uint8_t , ENC_GPIO_N> ENC_GPIO_AF = {GPIO_AF_TIM3, GPIO_AF_TIM3, GPIO_AF_TIM2, GPIO_AF_TIM2};

	#define ENC_TIM_AHB1Periph ( RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 )
	static const std::array<TIM_TypeDef* , ENC_N> ENC_TIM = {TIM3, TIM2};

#elif (MOUSE_NAME == KOIZUMI_OVER)
	#define ENCODER_CONST	(6.133 * 0.001)			//encoderの分解能[rad/count]

	#define ENC_GPIO_AHB1Periph ( RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOC)
	//順番　right_A,right_B,left_A,left_B
	static const std::array<GPIO_TypeDef*,ENC_GPIO_N> ENC_GPIO = {GPIOC, 			GPIOC,				GPIOA,				GPIOA};
	static const std::array<uint16_t,ENC_GPIO_N> ENC_GPIO_PIN = {GPIO_Pin_7,		GPIO_Pin_6,			GPIO_Pin_0,			GPIO_Pin_1};
	static std::array<uint8_t,ENC_GPIO_N> ENC_GPIO_PIN_SOURCE = {GPIO_PinSource7,	GPIO_PinSource6,	GPIO_PinSource0,	GPIO_PinSource1};
	static const std::array<uint8_t , ENC_GPIO_N> ENC_GPIO_AF = {GPIO_AF_TIM3,		GPIO_AF_TIM3,		GPIO_AF_TIM5,		GPIO_AF_TIM5};

	#define ENC_TIM_AHB1Periph ( RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM5 )
	static const std::array<TIM_TypeDef* , ENC_N> ENC_TIM = {TIM3, TIM5};
#endif

class encoder {
private:
	const static uint8_t MOVING_AVERAGE;	//移動平均をとる時間　単位は制御周期
	const static uint32_t MEDIAN;		//カウントの中央値
	static float correct[2][4097];	//補正用のテーブル
	static bool correct_flag[2];	//補正中か否か
	static uint32_t init_time[2];	//補正の開始時間
	static int16_t finish_time[2];	//補正終了時の時間

	static bool isCorrect[2];		//Y.I.式補正を行っているかどうかのフラグ

	encoder();

	static float raw_to_correct(ENC_SIDE enc_side, int16_t raw_delta);//補正テーブルで生値を補正する,返り値はコンバートした後の差分値

public:
	static float right_velocity, left_velocity, velocity;
	static int16_t raw_count[2];	//エンコーダ―の生値

	static void interrupt();		//モーターのEncoderの値計算
	static float get_velocity();	//左右の平均(重心速度)のEncoder取得[m/s]　 移動平均取ってることに注意！

	static volatile void yi_correct(ENC_SIDE enc_right);//片方ずつY.I.式補正法を行う。（補正テーブルの作成）
	static void yi_correct();		//Y.I.式補正法を行う。（補正テーブルの作成）

	static void draw_correct(bool right, bool left);		//Y.I.式補正テーブルを表示

	static void init();

	~encoder();
};

//光学センサー関連

static const uint8_t PHOTO_N = CAST_UI(PHOTO_TYPE::element_count);		//センサの個数　LEDとセンサが1:1の前提
#if (MOUSE_NAME == KOIZUMI_FISH)
	//発光側の設定
		#define LED_RCC_AHB1Periph (RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD)	//LEDとして使っているGPIO　|を使って複数指定
		//photo_typeの順番　right,  left, front_right, front_left, front
		static const std::array<GPIO_TypeDef*,PHOTO_N> LED_GPIO = {GPIOD,GPIOD,GPIOC,GPIOC,GPIOC};
		static const std::array<uint16_t,PHOTO_N> LED_GPIO_PIN = {GPIO_Pin_2,GPIO_Pin_2,GPIO_Pin_11,GPIO_Pin_10,GPIO_Pin_12};

	//受光側の設定
		#define SEN_RCC_AHB1Periph (RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC)	//センサーとして使っているGPIO　|を使って複数指定
		#define SEN_ADC_CMD (ADC1)			//センサーとして使っているADC　|を使って複数指定
		#define SEN_RCC_APB2Periph_ADC (RCC_APB2Periph_ADC1)	//センサーとして使っているADC　|を使って複数指定
		//photo_typeの順番　right,  left, front_right, front_left, front
		static const std::array<GPIO_TypeDef*,PHOTO_N> SEN_GPIO = {GPIOC,GPIOC,GPIOB,GPIOC,GPIOA};
		static const std::array<uint16_t,PHOTO_N> SEN_GPIO_PIN = {GPIO_Pin_5,GPIO_Pin_1,GPIO_Pin_0,GPIO_Pin_0,GPIO_Pin_3};
		static const std::array<ADC_TypeDef*,PHOTO_N> SEN_ADC = {ADC1,ADC1,ADC1,ADC1,ADC1};
		static const std::array<uint16_t,PHOTO_N> SEN_ADC_CH = {ADC_Channel_15,ADC_Channel_11,ADC_Channel_8,ADC_Channel_10,ADC_Channel_3};
#elif (MOUSE_NAME == KOIZUMI_OVER)
	// 発光側の設定
		#define LED_RCC_AHB1Periph (RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOH)	//LEDとして使っているGPIO　|を使って複数指定
		//photo_typeの順番　right,  left, front_right, front_left, front
		static const std::array<GPIO_TypeDef*,PHOTO_N> LED_GPIO = {GPIOC,		GPIOB,		GPIOC,		GPIOH,		GPIOC};
		static const std::array<uint16_t,PHOTO_N> LED_GPIO_PIN = {GPIO_Pin_14,GPIO_Pin_11,GPIO_Pin_13,GPIO_Pin_0,GPIO_Pin_11};

	//　受光側の設定
		#define SEN_RCC_AHB1Periph (RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOC)	//センサーとして使っているGPIO　|を使って複数指定
		#define SEN_ADC_CMD (ADC1)			//センサーとして使っているADC　|を使って複数指定
		#define SEN_RCC_APB2Periph_ADC (RCC_APB2Periph_ADC1)	//センサーとして使っているADC　|を使って複数指定
		//photo_typeの順番　right,  left, front_right, front_left, front
		static const std::array<GPIO_TypeDef*,PHOTO_N> SEN_GPIO = {GPIOC,GPIOC,GPIOC,GPIOB,GPIOC};
		static const std::array<uint16_t,PHOTO_N> SEN_GPIO_PIN = {GPIO_Pin_1,GPIO_Pin_5,GPIO_Pin_0,GPIO_Pin_0,GPIO_Pin_4};
		static const std::array<ADC_TypeDef*,PHOTO_N> SEN_ADC = {ADC1,ADC1,ADC1,ADC1,ADC1};
		static const std::array<uint16_t,PHOTO_N> SEN_ADC_CH = {ADC_Channel_11,ADC_Channel_15,ADC_Channel_10,ADC_Channel_8,ADC_Channel_3};
#endif

class photo {
private:
	static const int16_t PHOTO_AVERAGE_TIME = 30;	//XXX ad値のいくつの移動平均をとるか
	static const uint16_t GAP_AVE_COUNT = 10;		//XXX 壁の切れ目対策にいくつの平均をとるか

	static float ave_buf[static_cast<unsigned int>(PHOTO_TYPE::element_count)][GAP_AVE_COUNT];	//センサー値（平均取ったやつ）のバッファ　壁の切れ目チェックとかで使う
	//static float diff_buf[element_count][GAP_AVE_COUNT];	//今のセンサー値とave_bufの差　壁の切れ目チェックとかで使う
	//static uint8_t gap_buf[element_count][GAP_AVE_COUNT];		//count_wall_gapで数え上げた値を保存しておく

	static float right_ad, left_ad, front_right_ad, front_left_ad,
			front_ad;
	static float right_ref, left_ref, front_right_ref, front_left_ref,
			front_ref;
	static bool light_flag;		//赤外線LEDを光らせてセンサー値を読むかどうかのフラグ

	static void led_init();		//センサLEDの初期設定　GPIO
	static void sen_init();		//受光側の初期設定	GPIO,ADC

	static void switch_led(PHOTO_TYPE sensor_type, bool is_light);//LEDをつけたり消したり

	static int16_t get_ref(PHOTO_TYPE sensor_type);	//OFFのときのAD値を返す
	static void set_ref(PHOTO_TYPE sensor_type, int16_t set_value);	//refの値を代入

	photo();

public:
	//この値を越えたら壁キレ
	static const std::array<float, static_cast<unsigned int>(PHOTO_TYPE::element_count)> wall_edge_down;
	static const std::array<float, static_cast<unsigned int>(PHOTO_TYPE::element_count)> wall_edge_up;

	//壁キレを検知した距離　区画中心を0としてそこからどれだけ進んでいるか
	static const std::array<float, static_cast<unsigned int>(PHOTO_TYPE::element_count)> edge_distance;

	static void init();		//周辺機能の初期化

	static uint16_t get_ad(PHOTO_TYPE sensor_type);			//??_adの値を取得
	static void set_ad(PHOTO_TYPE _sensor_type, float set_value);	//??_adに値を代入

	static void light(PHOTO_TYPE sensor_type);
	static void turn_off(PHOTO_TYPE sensor_type);
	static void turn_off_all();		//すべて消す

	//割り込み内で行う処理
	static void interrupt(bool is_light);

	static float get_value(PHOTO_TYPE sensor_type);

	//センサ値から距離に変換し、区画中心からどれだけずれているのか[m]を返す。進行方向右側正
	static float get_displa_from_center_debag(PHOTO_TYPE type);
	static void get_displa_from_center_void(PHOTO_TYPE type, float val);
	static float get_displa_from_center(PHOTO_TYPE type);
	static float get_displa_from_center(PHOTO_TYPE type, float val);

	//static float get_displacement_from_center_debag(PHOTO_TYPE type);

	//TODO この関数はマウスclassにあるべきかも
	static bool check_wall(unsigned char muki);
	static bool check_wall(PHOTO_TYPE type);

	//static int8_t count_wall_gap(PHOTO_TYPE);	//diff_gapに保存されてる値の正負を数え上げて返す。
	//static bool check_wall_gap(PHOTO_TYPE type, float threshold);	//移動平均をとったやつでGAP_AVE_COUNT前と比較して絶対値がthreshold以上なら、壁の切れ目だからtrue
	static bool check_wall_edge(PHOTO_TYPE _type, bool _over_threshold);//壁キレが起こったか検知する　閾値をまたいだら壁キレ　over_threshold閾値のどっちにいるか

	~photo();

};

//それぞれのセンサから制御をかけるクラス

//PIDのゲインと偏差を管理する用の構造体
typedef struct {
	float P;
	float I;
	float D;
} PID;

class control {
private:

	static bool wall_control_flag;		//壁制御をかけてればtrue、切ってればfalse。
	static bool control_phase;		//姿勢制御をかけてるか否か。かけていればtrue
	static bool ignore_fail_safe;	//フェイルセーフを無視するか否か。無視するならtrue  エンコーダー補正時など

	//加速度はカスケード接続ではなく、速度とは独立に制御量を出し、それの積分を速度制御量に足す
	static float control_accel();		//加速度に関するPID制御(加速度センサのみ)。戻り値は[Duty/時間]？
	static float control_velocity();		//速度に関するPID制御(エンコーダーのみ)。戻り値はDuty？
	static float control_angular_velocity();//速度に関するPID制御(エンコーダーのみ)。戻り値はDuty？

	static float get_feedback(const signed char right_or_left);	//FBを掛けた後のDutyを返す。PID制御。
	static float get_feedforward(const signed char right_or_left);//FFを掛けた後のDutyを返す。

	static bool is_FF_CONTROL, is_FB_CONTROL;	//FFとFBの制御かけるかどうか。かけるならTrue

	control();

public:
	static PID gyro_delta, photo_delta, encoder_delta, accel_delta;	//各種Δ

	static volatile float cross_delta_gain(SEN_TYPE sensor);//P_GAIN*P_DELTA+・・・を行う

	static void cal_delta();	//割り込み関数内で、偏差を計算する

	static void posture_control();	//FF,FB制御をかける。set_dutyまで行う。

	static void start_wall_control();	//壁制御をかける
	static void stop_wall_control();	//壁制御を切る

	static void start_control();	//制御をかける
	static void stop_control();	//制御をとめる

	static bool get_control_phase();	//制御がかかっているかを取得。かかっていればtrue
	static bool get_wall_control_phase();	//制御がかかっているかを取得。かかっていればtrue

	static void reset_delta();
	static volatile void reset_delta(SEN_TYPE type);	//特定のセンサーの偏差だけ0にする

	static void fail_safe();	//Iゲインが一定以上いったらモーターを止める
	static void ignore_failsafe(bool ignore);		//フェイルセーフを無視するかどうか

	~control();
};

//カルマンフィルタを行う
//値と分散を管理する用の構造体
class kalman {
//変数名の名づけ方はWikiに従う
//https://ja.wikipedia.org/wiki/%E3%82%AB%E3%83%AB%E3%83%9E%E3%83%B3%E3%83%95%E3%82%A3%E3%83%AB%E3%82%BF%E3%83%BC
private:
	float x;		//現在の値
	float p;		//現在の分散
	float EstP, ObsP;	//推定値と観測値の分散

public:
	//カルマンフィルタによる補正を行う。
	void update(float EstimateU, float ObserveZ);//前回の値からどれだけ変化するかの推定値EstimateU,観測値ObserveZを入れると補正する。

	float get_value();				//現在の値を返す
	float get_dispersion();			//現在の分散を返す

	kalman();
	kalman(float EstimateP, float ObserveP);	//最初に推定値の分散と観測値の分散をパラメータとして入れる
	kalman(float initX, float initP, float EstimateP, float ObserveP);//さらに初期値も入れたいなら
	~kalman();
};

#endif /* HARDWARE_H_ */
