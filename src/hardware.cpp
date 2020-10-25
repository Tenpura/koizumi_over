/*
 * hardware.cpp
 *
 *  Created on: 2015/06/13
 *      Author: Koizumi
 */

#include"hardware.h"

//自作7セグ関連
#if (MOUSE_NAME == KOIZUMI_FISH)
void my7seg::light(const my7seg::DIRECTION muki) {
	switch (muki) {
	case front:
		GPIO_ResetBits(GPIOH, GPIO_Pin_0);	//LED9
		break;

	case left:
		GPIO_ResetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_ResetBits(GPIOC, GPIO_Pin_15);	//LED6
		break;

	case right:
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_ResetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;

	default:
		break;
	}
}
#elif (MOUSE_NAME == KOIZUMI_OVER)
void my7seg::light(const my7seg::DIRECTION muki) {
	switch (muki) {
	case front:
		GPIO_ResetBits(UI_GPIO.at(CAST_UI(top_front)).first, UI_GPIO.at(CAST_UI(top_front)).second);
		break;

	case left:
		GPIO_ResetBits(UI_GPIO.at(CAST_UI(top_left)).first, UI_GPIO.at(CAST_UI(top_left)).second);
		GPIO_ResetBits(UI_GPIO.at(CAST_UI(btm_left)).first, UI_GPIO.at(CAST_UI(btm_left)).second);
		break;

	case right:
		GPIO_ResetBits(UI_GPIO.at(CAST_UI(top_right)).first, UI_GPIO.at(CAST_UI(top_right)).second);
		GPIO_ResetBits(UI_GPIO.at(CAST_UI(btm_right)).first, UI_GPIO.at(CAST_UI(btm_right)).second);
		break;

	default:
		break;
	}
}
#endif	/* MOUSE_NAME */

#if (MOUSE_NAME == KOIZUMI_FISH)
void my7seg::light(const unsigned char number) {
	//7セグで表示できるわけねえだろ！
	if (number > 9) {
		//error
		light_error();
		return;
	}
	switch (number) {

	case 0:
		GPIO_SetBits(GPIOB, GPIO_Pin_4);	//LED7
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_ResetBits(GPIOC, GPIO_Pin_2);	//LED8
		GPIO_ResetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_ResetBits(GPIOC, GPIO_Pin_15);	//LED6
		GPIO_ResetBits(GPIOH, GPIO_Pin_0);	//LED9
		GPIO_ResetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;
	case 1:
		GPIO_SetBits(GPIOB, GPIO_Pin_4);	//LED7
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_SetBits(GPIOC, GPIO_Pin_2);	//LED8
		GPIO_SetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_SetBits(GPIOC, GPIO_Pin_15);	//LED6
		GPIO_SetBits(GPIOH, GPIO_Pin_0);	//LED9
		GPIO_ResetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;
	case 2:
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);	//LED7
		GPIO_SetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_ResetBits(GPIOC, GPIO_Pin_2);	//LED8
		GPIO_ResetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_SetBits(GPIOC, GPIO_Pin_15);	//LED6
		GPIO_ResetBits(GPIOH, GPIO_Pin_0);	//LED9
		GPIO_ResetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;
	case 3:
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);	//LED7
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_ResetBits(GPIOC, GPIO_Pin_2);	//LED8
		GPIO_SetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_SetBits(GPIOC, GPIO_Pin_15);	//LED6
		GPIO_ResetBits(GPIOH, GPIO_Pin_0);	//LED9
		GPIO_ResetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;
	case 4:
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);	//LED7
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_SetBits(GPIOC, GPIO_Pin_2);	//LED8
		GPIO_SetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_ResetBits(GPIOC, GPIO_Pin_15);	//LED6
		GPIO_SetBits(GPIOH, GPIO_Pin_0);	//LED9
		GPIO_ResetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;
	case 5:
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);	//LED7
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_ResetBits(GPIOC, GPIO_Pin_2);	//LED8
		GPIO_SetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_ResetBits(GPIOC, GPIO_Pin_15);	//LED6
		GPIO_ResetBits(GPIOH, GPIO_Pin_0);	//LED9
		GPIO_SetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;
	case 6:
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);	//LED7
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_ResetBits(GPIOC, GPIO_Pin_2);	//LED8
		GPIO_ResetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_ResetBits(GPIOC, GPIO_Pin_15);	//LED6
		GPIO_ResetBits(GPIOH, GPIO_Pin_0);	//LED9
		GPIO_SetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;
	case 7:
		GPIO_SetBits(GPIOB, GPIO_Pin_4);	//LED7
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_SetBits(GPIOC, GPIO_Pin_2);	//LED8
		GPIO_SetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_ResetBits(GPIOC, GPIO_Pin_15);	//LED6
		GPIO_ResetBits(GPIOH, GPIO_Pin_0);	//LED9
		GPIO_ResetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;
	case 8:
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);	//LED7
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_ResetBits(GPIOC, GPIO_Pin_2);	//LED8
		GPIO_ResetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_ResetBits(GPIOC, GPIO_Pin_15);	//LED6
		GPIO_ResetBits(GPIOH, GPIO_Pin_0);	//LED9
		GPIO_ResetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;
	case 9:
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);	//LED7
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	//LED3
		GPIO_ResetBits(GPIOC, GPIO_Pin_2);	//LED8
		GPIO_SetBits(GPIOC, GPIO_Pin_14);	//LED5
		GPIO_ResetBits(GPIOC, GPIO_Pin_15);	//LED6
		GPIO_ResetBits(GPIOH, GPIO_Pin_0);	//LED9
		GPIO_ResetBits(GPIOH, GPIO_Pin_1);	//LED4
		break;
	}
	return;
}
#elif (MOUSE_NAME == KOIZUMI_OVER)
void my7seg::light(const unsigned char number) {
	//7セグで表示できるわけねえだろ！
	if (number >= UI_MODE_N) {
		//error
		light_error();
		return;
	} else {
		//XXX	TBD 将来は関数ポインタ＆Reset or SETを LED ON/OFFみたいに意味でラッピングする
		for(int i=0; i<UI_GPIO_N;i++){
			if( UI_GPIO_LIGHT_PTN.at(number).at(i) ==1 ){
				GPIO_ResetBits(UI_GPIO.at(i).first, UI_GPIO.at(i).second);		/* LED　ON */
			}else{
				GPIO_SetBits(UI_GPIO.at(i).first, UI_GPIO.at(i).second);		/* LED　OFF */
			}
		}
	}

}
#endif	/* MOUSE_NAME */

void my7seg::turn_off() {
	for(unsigned int i=0; i<UI_GPIO_N; i++){
		GPIO_SetBits(UI_GPIO.at(i).first, UI_GPIO.at(i).second);	/* LEDは消しとく */
	}
}
#if (MOUSE_NAME == KOIZUMI_FISH)
void my7seg::light_error() {
	GPIO_ResetBits(GPIOB, GPIO_Pin_4);	//LED7
	GPIO_SetBits(GPIOB, GPIO_Pin_12);	//LED3
	GPIO_ResetBits(GPIOC, GPIO_Pin_2);	//LED8
	GPIO_ResetBits(GPIOC, GPIO_Pin_14);	//LED5
	GPIO_ResetBits(GPIOC, GPIO_Pin_15);	//LED6
	GPIO_ResetBits(GPIOH, GPIO_Pin_0);	//LED9
	GPIO_SetBits(GPIOH, GPIO_Pin_1);	//LED4
}
#elif (MOUSE_NAME == KOIZUMI_OVER)
void my7seg::light_error() {
	for(unsigned int i=0; i<UI_GPIO_N; i++){
		GPIO_SetBits(UI_GPIO.at(i).first, UI_GPIO.at(i).second);	/* LEDは全点灯 */
	}
}
#endif	/* MOUSE_NAME */

void my7seg::blink(const unsigned char number,
		const unsigned short blink_cycle_ms,
		const unsigned short repeat_count) {
	for (int i = 0; i < repeat_count; i++) {
		light(number);
		wait::ms(blink_cycle_ms);
		turn_off();
		wait::ms(blink_cycle_ms);
	}
}

void my7seg::count_down(const unsigned char start_number,
		const unsigned short cycle_ms) {
	for (volatile int i = start_number; i > 0; i--) {
		light(i);
		wait::ms(cycle_ms);
	}
	light(0);
}

void my7seg::init(){
	RCC_AHB1PeriphClockCmd(UI_GPIO_AHB1Periph, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	for(unsigned int i=0; i<UI_GPIO_N; i++){
		GPIO_InitStructure.GPIO_Pin = UI_GPIO.at(i).second;
		GPIO_Init(UI_GPIO.at(i).first, &GPIO_InitStructure);

		GPIO_SetBits(UI_GPIO.at(i).first, UI_GPIO.at(i).second);	/* LEDは消しとく */
	}

}

//motor関連
signed char motor::right_duty = 0, motor::left_duty = 0;
const char motor::MAX_DUTY = 100;
bool motor::motor_state = false;

void motor::set_duty(const MOTOR_SIDE side, const float set_duty) {
	float duty = 0;		//一時的な保存

	//Dutyに絶対値をとる
	//上限を切る
	duty = MIN( ABS(set_duty), MAX_DUTY);

	static TIM_OCInitTypeDef TIM_OC_InitStructure;
	TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;		//モードはPWM1
	TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//たぶんいらない。This parameter is valid only for TIM1 and TIM8.
	TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;//たぶんいらない。This parameter is valid only for TIM1 and TIM8.

	TIM_OC_InitStructure.TIM_Pulse = static_cast<uint32_t>(MAX_PERIOD * duty
			* 0.01);	//dutyに応じてカウントを変更
	if (set_duty == 0) {					//0のときはstop
		TIM_OC_InitStructure.TIM_Pulse = 0;		//duty0の時は一応0を代入しておく
		TIM_OC1Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4のCH1
		TIM_OC2Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4のCH2

	} else if (set_duty > 0) {				//正のときは正転
		TIM_OC1Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4のCH1
		TIM_OC_InitStructure.TIM_Pulse = 0;		//電位差を作るため、片方は0に
		TIM_OC2Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4のCH2

	} else {									//負のときは逆転
		TIM_OC2Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4のCH2
		TIM_OC_InitStructure.TIM_Pulse = 0;		//電位差を作るため、片方は0に
		TIM_OC1Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4のCH1

	}

	if (side == MOTOR_SIDE::m_right) {
		right_duty = duty * SIGN(set_duty);
	}

	if (side == MOTOR_SIDE::m_left) {
		left_duty = duty * SIGN(set_duty);
	}

}

signed short motor::get_duty_left() {
	return left_duty;
}

signed short motor::get_duty_right() {
	return right_duty;
}

void motor::sleep_motor() {
	GPIO_ResetBits(SLEEP_GPIO, SLEEP_GPIO_PIN);	//モータードライバースリープ
	for( uint32_t side = 0; side < MOTOR_N; side++){
		TIM_Cmd(PWM_TIM.at(side), DISABLE);
		motor::set_duty(static_cast<MOTOR_SIDE>(side), 0);
	}
	motor_state = false;

}

void motor::stanby_motor() {
	GPIO_SetBits(SLEEP_GPIO, SLEEP_GPIO_PIN);	//モータードライバースタンバイ
	for( uint32_t side = 0; side < MOTOR_N; side++){
		TIM_Cmd(PWM_TIM.at(side), ENABLE);
	}
	motor_state = true;
}

bool motor::isEnable() {
	return motor_state;
}

void motor::init_PWM() {

	RCC_AHB1PeriphClockCmd(SLEEP_GPIO_AHB1Periph, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;

	//モータドライバスリープ設定
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = SLEEP_GPIO_PIN;
	GPIO_Init(SLEEP_GPIO, &GPIO_InitStructure);

	GPIO_ResetBits(SLEEP_GPIO, SLEEP_GPIO_PIN);		//モータードライバーをスリープモードに


	RCC_AHB1PeriphClockCmd(PWM_GPIO_AHB1Periph, ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	for(int i=0; i<PWM_IN_N; i++){
		GPIO_InitStructure.GPIO_Pin = PWM_GPIO_PIN.at(i);
		GPIO_Init(PWM_GPIO.at(i), &GPIO_InitStructure);	//設定
	}


	RCC_APB1PeriphClockCmd(PWM_TIM_AHB1Periph, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	TIM_InitStructure.TIM_Period = MAX_PERIOD;//カウンタクリア要因 100kHz ExcelファイルからTIMのクロックを確認
	TIM_InitStructure.TIM_Prescaler = 0;//プリスケーラ(カウンタがPrescaler回カウントされたタイミングで，TIMのカウンタが1加算される)
	TIM_InitStructure.TIM_ClockDivision = 0;	//デットタイム発生回路用の分周。通常0(分周しない)。
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;	//アップカウント
	TIM_InitStructure.TIM_RepetitionCounter = 0;
	for(uint32_t i=0; i<MOTOR_N; i++){
		TIM_TimeBaseInit(PWM_TIM.at(i), &TIM_InitStructure);
	}

	TIM_OCInitTypeDef TIM_OC_InitStructure;
	TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;		//モードはPWM1
	TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//たぶんいらない。This parameter is valid only for TIM1 and TIM8.
	TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;//たぶんいらない。This parameter is valid only for TIM1 and TIM8.
	TIM_OC_InitStructure.TIM_Pulse = 0;	//パルス幅。Duty比に関係。

	for(uint32_t i=0; i<MOTOR_N; i++){
		//PWM出力が4本必要なので各タイマ2つずつ
		TIM_OC1Init(PWM_TIM.at(i), &TIM_OC_InitStructure);		//TIM2のCH1
		TIM_OC1PreloadConfig(PWM_TIM.at(i), TIM_OCPreload_Enable);
		TIM_OC2Init(PWM_TIM.at(i), &TIM_OC_InitStructure);		//TIM2のCH2
		TIM_OC2PreloadConfig(PWM_TIM.at(i), TIM_OCPreload_Enable);
	}

	for(int i=0; i<PWM_IN_N; i++){
		GPIO_PinAFConfig(PWM_GPIO.at(i), PWM_GPIO_PIN_SOURCE.at(i), PWM_GPIO_AF.at(i));
	}


	//TIM起動
	for(uint32_t i=0; i<MOTOR_N; i++){
		TIM_ARRPreloadConfig(PWM_TIM.at(i), ENABLE);
		TIM_Cmd(PWM_TIM.at(i), ENABLE);
	}

}

motor::motor() {
}

motor::~motor() {

}

//gyro関連
SPI_TypeDef* mpu6000::use_SPI = SPI1;		//SPI1~3のどれ使ってるか
GPIO_TypeDef* mpu6000::cs_GPIOx = GPIOA;		//cs叩くピンの設定
const uint16_t mpu6000::cs_GPIO_Pin = GPIO_Pin_4;	//cs叩くピンの設定

//レジスター定義
const uint16_t mpu6000::GYRO_XOUT_H = 0x43;
const uint16_t mpu6000::GYRO_XOUT_L = 0x44;
const uint16_t mpu6000::GYRO_YOUT_H = 0x45;
const uint16_t mpu6000::GYRO_YOUT_L = 0x46;
const uint16_t mpu6000::GYRO_ZOUT_H = 0x47;
const uint16_t mpu6000::GYRO_ZOUT_L = 0x48;
const uint16_t mpu6000::ACCEL_XOUT_H = 0x3b;
const uint16_t mpu6000::ACCEL_XOUT_L = 0x3c;
const uint16_t mpu6000::ACCEL_YOUT_H = 0x3d;
const uint16_t mpu6000::ACCEL_YOUT_L = 0x3e;
const uint16_t mpu6000::ACCEL_ZOUT_H = 0x3f;
const uint16_t mpu6000::ACCEL_ZOUT_L = 0x40;

uint16_t mpu6000::read_spi(uint16_t read_reg) {
	uint16_t data = 0;
	uint16_t reg = (read_reg | 128);	//read時はレジスターの最上位Bitを1に

	GPIO_ResetBits(cs_GPIOx, cs_GPIO_Pin); // CSをセット

	//レジスタ指定
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		; // 送信可能になるまで待つ
	SPI_I2S_SendData(use_SPI, reg); // 送信
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_RXNE) == RESET)
		; // 受信可能になるまで待つ
	data = SPI_I2S_ReceiveData(use_SPI); // 空データを受信する

	//データの送受信
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		; // 送信可能になるまで待つ
	SPI_I2S_SendData(use_SPI, 0x00); // 送信
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_RXNE) == RESET)
		; // 受信可能になるまで待つ
	data = SPI_I2S_ReceiveData(use_SPI); // 受信する
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		;

	GPIO_SetBits(cs_GPIOx, cs_GPIO_Pin); //CSをリセット

	//連続して行ってもうまくいくように少しだけ待つ。
	for (int i = 0; i < 5; i++)
		;

	return data;
}

void mpu6000::write_spi(uint16_t reg, uint16_t data) {

	GPIO_ResetBits(cs_GPIOx, cs_GPIO_Pin); // CSをセット

	//レジスタ指定
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		; // 送信可能になるまで待つ
	SPI_I2S_SendData(use_SPI, reg); // 送信
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_RXNE) == RESET)
		; // 受信可能になるまで待つ
	SPI_I2S_ReceiveData(use_SPI); // 空データを受信する

	//データの送受信
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		; // 送信可能になるまで待つ
	SPI_I2S_SendData(use_SPI, data); // 送信
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_RXNE) == RESET)
		; // 受信可能になるまで待つ
	SPI_I2S_ReceiveData(use_SPI); // 受信する
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		;

	GPIO_SetBits(cs_GPIOx, cs_GPIO_Pin); //CSをリセット

	//連続して行ってもうまくいくように少しだけ待つ。
	for (int i = 0; i < 10; i++)
		;

}

volatile int16_t mpu6000::get_mpu_val(SEN_TYPE sen, AXIS_t axis) {
	int16_t data = 0;
	uint16_t reg_h = 0;	//highの値へのレジスタ
	uint16_t reg_l = 0;	//Lowの値へのレジスタ

	switch (sen) {
	case sen_gyro:
		switch (axis) {
		case axis_x:
			reg_h = GYRO_XOUT_H;
			reg_l = GYRO_XOUT_L;
			break;
		case axis_y:
			reg_h = GYRO_YOUT_H;
			reg_l = GYRO_YOUT_L;
			break;
		case axis_z:
			reg_h = GYRO_ZOUT_H;
			reg_l = GYRO_ZOUT_L;
			break;
		default:
			break;
		}
		break;

	case sen_accel:
		switch (axis) {
		case axis_x:
			reg_h = ACCEL_XOUT_H;
			reg_l = ACCEL_XOUT_L;
			break;
		case axis_y:
			reg_h = ACCEL_YOUT_H;
			reg_l = ACCEL_YOUT_L;
			break;
		case axis_z:
			reg_h = ACCEL_ZOUT_H;
			reg_l = ACCEL_ZOUT_L;
			break;
		default:
			break;
		}
		break;

	default:		//gyroと加速度以外は読めないので初期値を返して終了
		return data;
		break;
	}

	//Highの方は上位に8ビットずらしてLowと合わせて、目的のデータを得る。
	data = static_cast<int16_t>((read_spi(reg_h) << 8) + read_spi(reg_l));

	return data;
}

void mpu6000::init() {
	static const uint16_t SIGNAL_PATH_RESET = 0x68;
	static const uint16_t PWR_MGMT_1 = 0x6B;
	static const uint16_t PWR_MGMT_2 = 0x6c;
	static const uint16_t USER_CTRL = 0x6a;
	static const uint16_t DATA_CONFIG = 0x1a;
	static const uint16_t GYRO_CONFIG = 0x1b;
	static const uint16_t ACCEL_CONFIG = 0x1c;

	write_spi(PWR_MGMT_1, 0x00);		//サイクル1、SLEEP解除、温度センサは使わない
	write_spi(PWR_MGMT_2, 0xC6);		//ジャイロのZ軸方向以外は停止、加速度はXYZ軸方向全部許可
	write_spi(USER_CTRL, 16);			//I2CをDisable、SPIをEnable
	write_spi(SIGNAL_PATH_RESET, 0x06);	//ジャイロ、加速度リセット
	write_spi(DATA_CONFIG, 0x01);		//フィルターはかけない
	write_spi(GYRO_CONFIG, 0x18);		//ジャイロを±2000°/sに設定
	write_spi(ACCEL_CONFIG, 0x08);		//加速度を±4g/sに設定

	//確認用
	/*
	 myprintf("PWR_MGMT_1 0x%x\n\r",read_spi(PWR_MGMT_1));
	 myprintf("PWR_MGMT_2 0x%x\n\r",read_spi(PWR_MGMT_2));
	 myprintf("USER_CTRL 0d%d\n\r",read_spi(USER_CTRL));
	 myprintf("SIGNAL_PATH_RESET 0x%x\n\r",read_spi(SIGNAL_PATH_RESET));
	 myprintf("DATA_CONFIG 0x%x\n\r",read_spi(DATA_CONFIG));
	 myprintf("GYRO_CONFIG 0x%x\n\r",read_spi(GYRO_CONFIG));
	 myprintf("ACCEL_CONFIG 0x%x\n\r",read_spi(ACCEL_CONFIG));
	 */
}

mpu6000::mpu6000() {
}

mpu6000::~mpu6000() {

}

const float accelmeter::ACCEL_PERIOD = CONTORL_PERIOD;		//加速度計の制御周期[s]
const float accelmeter::REF_TIME = 1;			//加速度計のリファレンスとる時間[s]
#if (MOUSE_NAME == KOIZUMI_FISH)
const uint8_t accelmeter::AVERAGE_COUNT = 10;			//加速度計の平均回数[回]
#elif (MOUSE_NAME == KOIZUMI_OVER)
const uint8_t accelmeter::AVERAGE_COUNT = 10;			//加速度計の平均回数[回]
#endif	/* MOUSE_NAME */
float accelmeter::accel_ad[AXIS_t::dim_num] = { 0 },
		accelmeter::accel_ref[AXIS_t::dim_num] = { 0 };
float accelmeter::accel[AXIS_t::dim_num] = { 0 };

void accelmeter::interrupt() {
	static float buff[AXIS_t::dim_num][AVERAGE_COUNT] = { 0 };	//データを保存しておく配列
	float sum[AXIS_t::dim_num] = { 0 };

	for (int i = 0; (i + 1) < AVERAGE_COUNT; i++) {
		for (int j = 0; j < AXIS_t::dim_num; j++) {
			buff[j][i] = buff[j][i + 1];	//配列を1つずらす
			sum[j] += buff[j][i];			//ついでに加算する
		}
	}

	//FIXME 移動平均になってない！
	//配列の最後に入れる
	buff[AXIS_t::axis_x][(AVERAGE_COUNT - 1)] =
			static_cast<float>(mpu6000::get_mpu_val(sen_accel, axis_x));//加速度のx方向
	buff[AXIS_t::axis_y][(AVERAGE_COUNT - 1)] =
			static_cast<float>(mpu6000::get_mpu_val(sen_accel, axis_y));//加速度のy方向
	buff[AXIS_t::axis_z][(AVERAGE_COUNT - 1)] =
			static_cast<float>(mpu6000::get_mpu_val(sen_accel, axis_z));//加速度のz方向

	for (int j = 0; j < AXIS_t::dim_num; j++) {
		sum[j] += buff[j][(AVERAGE_COUNT - 1)];		//sumに最新の値を足す
		accel_ad[j] = sum[j] / AVERAGE_COUNT;		//平均をとって加速度の値とする
	}

	cal_accel();

}

float accelmeter::get_accel_ref(AXIS_t xyz) {
	float accel_sum = 0;
	int32_t i;
	for (i = 0; i < static_cast<int32_t>(REF_TIME / ACCEL_PERIOD); i++) {
		accel_sum += get_accel_ad(xyz);
		wait::ms(1);
	}
	return (accel_sum / (i + 1));
}

float accelmeter::get_accel_ad(AXIS_t xyz) {
	return accel_ad[xyz];
}

void accelmeter::set_accel_ref() {
	set_accel_ref(AXIS_t::axis_x);
	set_accel_ref(AXIS_t::axis_y);
	set_accel_ref(AXIS_t::axis_z);
}

void accelmeter::set_accel_ref(AXIS_t xyz) {
	accel_ref[xyz] = get_accel_ref(xyz);
}

void accelmeter::cal_accel() {
	for (int j = 0; j < AXIS_t::dim_num; j++)
		accel[j] = (accel_ad[j] - accel_ref[j]) / ACCEL_SENSITIVITY * 9.8;//加速度[g]を[m/ss]に直すため重力加速度をかける
}
#if (MOUSE_NAME == KOIZUMI_FISH)
float accelmeter::get_accel() {
	return accel[axis_y];		//進行方向の加速度
}

#elif (MOUSE_NAME == KOIZUMI_OVER)
float accelmeter::get_accel() {
	return accel[axis_x];		//進行方向の加速度
}

#endif

float accelmeter::get_accel(AXIS_t xyz) {
	return accel[xyz];
}

int16_t gyro::gyro_value;
float gyro::default_angle;
float gyro::angle, gyro::gyro_ref;
float gyro::angular_velocity;
float gyro::least_square_slope = 0;
const float gyro::GYRO_PERIOD = CONTORL_PERIOD;		//制御周期[s]
const float gyro::REF_TIME = 2;							//リファレンスとる時間[s]

void gyro::interrupt() {
	gyro_value = -mpu6000::get_mpu_val(sen_gyro, axis_z);	//Z方向のジャイロを見る。時計回り正
	gyro::cal_angular_velocity();	//gyroから角速度を計算[rad/s]
	gyro::cal_angle();				//gyroから角度を計算

}

int16_t gyro::get_gyro() {
	return gyro_value;
}

float gyro::get_gyro_ref() {
	int32_t gyro_sum = 0;
	int32_t i;
	for (i = 0; i < static_cast<int32_t>(REF_TIME / GYRO_PERIOD); i++) {
		gyro_sum += get_gyro();
		wait::ms(1);
	}

	return (gyro_sum / (i + 1));
}
/*
 void gyro::set_least_square_slope() {
 //x,yとかはWikiの最小二乗法と同じ。xは時間[ms],yは角度[°]
 float x_square_sum = 0, x_sum = 0, y_sum = 0, xy_sum = 0;
 float temp_count = 0;
 float temp_gyro;

 mouse::reset_count();

 while (mouse::get_count_ms() < LEAST_SQUARE_TIME) {
 temp_count = (float) mouse::get_count_ms();
 temp_gyro = gyro::get_angle_radian();

 y_sum += temp_gyro;
 x_sum += temp_count;
 x_square_sum += (temp_count * temp_count);
 xy_sum += (temp_count * temp_gyro);

 //1ms経つまで待機
 while (temp_count >= mouse::get_count_ms()) {
 }
 }

 if ((x_square_sum - x_sum * x_sum) == 0) {
 least_square_slope = 0;
 return;
 }
 least_square_slope += (float) ((LEAST_SQUARE_TIME * xy_sum - x_sum * y_sum)
 / (LEAST_SQUARE_TIME * x_square_sum - x_sum * x_sum));
 }
 */
void gyro::set_gyro_ref() {
	gyro_ref = get_gyro_ref();

	/*	ジャイロの補正に最小二乗法は使ってない
	 set_least_square_slope();	//最小二乗法による補正項導出
	 mouse::reset_count();
	 */
}

void gyro::set_angle(float set_rad) {
	angle = set_rad;
}

void gyro::reset_angle() {
	default_angle = 0;
	angle = 0;
}

void gyro::cal_angle() {
	angle += angular_velocity * GYRO_PERIOD;
	//XXX最小二乗法での補正はしてない
	//最小二乗法で補正する
	//angle = default_angle	- (least_square_slope * (float) mouse::get_count_ms());
}

float gyro::get_angle_radian() {
	return angle;
}

void gyro::cal_angular_velocity() {
	angular_velocity = radian((gyro_value - gyro_ref) / GYRO_SENSITIVITY);
}

float gyro::get_angular_velocity() {
	return angular_velocity;	//[rad/s]
}

gyro::gyro() {

}

gyro::~gyro() {

}

//encoder関連
const uint8_t encoder::MOVING_AVERAGE = 30;
const uint32_t encoder::MID_CNT = 32762;
float encoder::left_velocity, encoder::right_velocity, encoder::velocity;
int16_t encoder::raw_count[2] = { 0 };
float encoder::correct[2][ ENC_RES + 1 ] = { 0 };
bool encoder::correct_flag[2] = { false, false };
uint32_t encoder::init_time[2] = { 0 };
bool encoder::isCorrect[2] = { false, false };		//Y.I.式補正を行っているかどうかのフラグ

#if (MOUSE_NAME == KOIZUMI_FISH)
void encoder::interrupt() {
	static float data_r[MOVING_AVERAGE] = { 0 };	//データを保存しておく配列
	static unsigned int index_r=0;
	float sum_r = 0;
	static float data_l[MOVING_AVERAGE] = { 0 };	//データを保存しておく配列
	static unsigned int index_l=0;
	float sum_l = 0;
	float delta_value_r, delta_value_l;

	for (uint8_t i = 0; (i + 1) < MOVING_AVERAGE; i++) {
		data_r[i] = data_r[i + 1];	//配列を1つずらす
		sum_r += data_r[i];			//ついでに加算する
		data_l[i] = data_l[i + 1];	//配列を1つずらす
		sum_l += data_l[i];			//ついでに加算する
	}

	//エンコーダ―の値を取得
	delta_value_r = 32762 - static_cast<float>(ENC_TIM.at(enc_right)->CNT);
	ENC_TIM.at(enc_right)->CNT = 32762;
	delta_value_l = static_cast<float>(ENC_TIM.at(enc_left)->CNT) - 32762;
	ENC_TIM.at(enc_left)->CNT = 32762;

	//FIX_ME
	mouse::debag_val_enc_r = delta_value_r;
	mouse::debag_val_enc_l = delta_value_l;

	//Y.I.式補正テーブルが完成していたら、Y.I.式補正をする.してなかったら移動平均をとる
	if (isCorrect[enc_right]){
		//補正した差分を使って速度をとる
		right_velocity = raw_to_correct(enc_right, delta_value_r)
				* ENCODER_CONST / CONTROL_PERIOD * tire_R;//count*[rad/count]/[sec]*[m]
	}else {
		/* 移動平均をとる */
		//配列の最古の奴を取り出し（sumから引く）、最新の値で更新（sumに加算）
		sum_r -= data_r[index_r];
		data_r[index_r] = delta_value_r * ENCODER_CONST
				/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
		sum_r += data_r[index_r];
		// リングQみたいにする。　MAXまでいったら0に戻る
		if( index_r >= (MOVING_AVERAGE-1) ){
			index_r = 0;
		}else{
			index_r++;
		}
		right_velocity = sum_r / MOVING_AVERAGE;
	}
	if (isCorrect[enc_left])
		//補正した差分を使って速度をとる
		left_velocity = raw_to_correct(enc_left, delta_value_l) * ENCODER_CONST
				/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
	else {
		/* 移動平均をとる */
		//配列の最古の奴を取り出し（sumから引く）、最新の値で更新（sumに加算）
		sum_l -= data_l[index_l];
		data_l[index_l] = delta_value_l * ENCODER_CONST
						/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
		sum_l += data_l[index_l];
		// リングQみたいにする。　MAXまでいったら0に戻る
		if( index_l >= (MOVING_AVERAGE-1) ){
			index_l = 0;
		}else{
			index_l++;
		}
		//配列の最後に入れる
		left_velocity = sum_l / MOVING_AVERAGE;
	}

	velocity = (right_velocity + left_velocity) / 2;

	//補正用にデータを保存
	if (correct_flag[enc_right]) {
		raw_count[enc_right] += static_cast<int16_t>(delta_value_r);//正転で増えていく方向に
		if (raw_count[enc_right] < 0)
			raw_count[enc_right] += ENC_RES;
		else if (raw_count[enc_right] > ENC_RES) {
			raw_count[enc_right] -= ENC_RES;
			correct_flag[enc_right] = false;	//補正テーブル作成完了
			isCorrect[enc_right] = true;		//補正フラグを建てる
			//（厳密には補正テーブルはまだできていないが作成途中ではエンコーダーの値を参照しないのでこの時点で建てる）
		} else {
			//オーバーフローしないときは保存していく
			correct[enc_right][raw_count[enc_right]] =
					static_cast<float>(wait::get_count() - init_time[enc_right]);//時間を保存
		}
	}
	if (correct_flag[enc_left]) {
		raw_count[enc_left] += static_cast<int16_t>(delta_value_l);	//正転で増えていく方向に
		if (raw_count[enc_left] < 0)
			raw_count[enc_left] += ENC_RES;
		else if (raw_count[enc_left] > ENC_RES) {
			raw_count[enc_left] -= ENC_RES;
			correct_flag[enc_left] = false;
			isCorrect[enc_left] = true;		//補正を完了フラグを建てる
			//（厳密には補正テーブルはまだできていないが作成途中ではエンコーダーの値を参照しないのでこの時点で建てる）
		} else {
			//オーバーフローしないときは保存していく
			correct[enc_left][raw_count[enc_left]] =
					static_cast<float>(wait::get_count() - init_time[enc_left]);//時間を保存
		}
	}

}
#elif (MOUSE_NAME == KOIZUMI_OVER)
void encoder::interrupt() {
	static float data_r[MOVING_AVERAGE] = { 0 };	//データを保存しておく配列
	static unsigned int index_r=0;
	static float sum_r = 0;
	static float data_l[MOVING_AVERAGE] = { 0 };	//データを保存しておく配列
	static unsigned int index_l=0;
	static float sum_l = 0;
	int32_t r_cnt_delt, l_cnt_delt;
	uint32_t r_cnt_saved, l_cnt_saved;

	/*	エンコーダ―の値を保存 */
	r_cnt_saved = ENC_TIM.at(enc_right)->CNT;
	l_cnt_saved = ENC_TIM.at(enc_left)->CNT;
	ENC_TIM.at(enc_right)->CNT = MID_CNT;
	ENC_TIM.at(enc_left)->CNT = MID_CNT;

	/* 差分を計算 */
	r_cnt_delt = static_cast<int32_t>(MID_CNT) - r_cnt_saved;

	//Y.I.式補正テーブルが完成していたら、Y.I.式補正をする.してなかったら移動平均をとる
	if (isCorrect[enc_right]){
		//補正した差分を使って速度をとる
		right_velocity = raw_to_correct(enc_right, r_cnt_delt)
				* ENCODER_CONST / CONTROL_PERIOD * tire_R;//count*[rad/count]/[sec]*[m]
	}else {
		right_velocity = r_cnt_delt * ENCODER_CONST
				/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
	}
	/* 移動平均をとる */
	//配列の最古の奴を取り出し（sumから引く）、最新の値で更新（sumに加算）
	sum_r -= data_r[index_r];
	data_r[index_r] = right_velocity;
	sum_r += data_r[index_r];
	// リングQみたいにする。　MAXまでいったら0に戻る
	if( index_r >= (MOVING_AVERAGE-1) ){
		index_r = 0;
	}else{
		index_r++;
	}
	right_velocity = sum_r / MOVING_AVERAGE;


	l_cnt_delt = static_cast<int32_t>(MID_CNT) - l_cnt_saved;

	if (isCorrect[enc_left]) {
		//補正した差分を使って速度をとる
		left_velocity = raw_to_correct(enc_left, l_cnt_delt) * ENCODER_CONST
				/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
	} else {
		left_velocity = l_cnt_delt * ENCODER_CONST
						/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
	}
	/* 移動平均をとる */
	//配列の最古の奴を取り出し（sumから引く）、最新の値で更新（sumに加算）
	sum_l -= data_l[index_l];
	data_l[index_l] = left_velocity;		//count*[rad/count]/[sec]*[m]
	sum_l += data_l[index_l];
	// リングQみたいにする。　MAXまでいったら0に戻る
	if( index_l >= (MOVING_AVERAGE-1) ){
		index_l = 0;
	}else{
		index_l++;
	}
	left_velocity = sum_l / MOVING_AVERAGE;

	velocity = (right_velocity + left_velocity) / 2;

	//補正用にデータを保存
	if (correct_flag[enc_right]) {
		raw_count[enc_right] += static_cast<int16_t>(r_cnt_delt);//正転で増えていく方向に
		if (raw_count[enc_right] < 0)
			raw_count[enc_right] += ENC_RES;
		else if (raw_count[enc_right] > ENC_RES) {
			raw_count[enc_right] -= ENC_RES;
			correct_flag[enc_right] = false;	//補正テーブル作成完了
			isCorrect[enc_right] = true;		//補正フラグを建てる
			//（厳密には補正テーブルはまだできていないが作成途中ではエンコーダーの値を参照しないのでこの時点で建てる）
		} else {
			//オーバーフローしないときは保存していく
			correct[enc_right][raw_count[enc_right]] =
					static_cast<float>(wait::get_count() - init_time[enc_right]);//時間を保存
		}
	}
	if (correct_flag[enc_left]) {
		raw_count[enc_left] += static_cast<int16_t>(l_cnt_delt);	//正転で増えていく方向に
		if (raw_count[enc_left] < 0)
			raw_count[enc_left] += ENC_RES;
		else if (raw_count[enc_left] > ENC_RES) {
			raw_count[enc_left] -= ENC_RES;
			correct_flag[enc_left] = false;
			isCorrect[enc_left] = true;		//補正を完了フラグを建てる
			//（厳密には補正テーブルはまだできていないが作成途中ではエンコーダーの値を参照しないのでこの時点で建てる）
		} else {
			//オーバーフローしないときは保存していく
			correct[enc_left][raw_count[enc_left]] =
					static_cast<float>(wait::get_count() - init_time[enc_left]);//時間を保存
		}
	}

}
#endif	/* MOUSE_NAME */



float encoder::get_velocity() {
	return velocity;

	//松井さん方式　http://matsui-mouse.blogspot.jp/2014/03/blog-post_26.html
	//カルマンフィルタで加速度とセンサフュージョンしてるからコレしないでいい気がする
	/*
	 return (velocity
	 + accelmeter::get_accel(axis_y) * accelmeter::AVERAGE_COUNT
	 * accelmeter::ACCEL_PERIOD / 2);
	 */
}

float encoder::raw_to_correct(ENC_SIDE enc_side, int16_t raw_delta) {
	float temp_delta = 0;						//エンコーダーの前回との差分をとる
	static float correct_cnt[2] = { 0 };		//補正後の値を記録

	raw_count[enc_side] += raw_delta;
	if (raw_count[enc_side] > ENC_RES) {
		raw_count[enc_side] -= ENC_RES;
		temp_delta += ENC_RES;	//上方向のオーバーフローしたので差分値も先に補正しておく
	} else if (raw_count[enc_side] < 0) {
		raw_count[enc_side] += ENC_RES;
		temp_delta -= ENC_RES;	//下方向のオーバーフローしたので差分値も先に補正しておく
	}
	temp_delta += ( correct[ enc_side ][ raw_count[enc_side] ] - correct_cnt[enc_side] );	//YI式補正テーブルで補正し、前回との差分をとる
	correct_cnt[enc_side] = correct[enc_side][raw_count[enc_side]];	//値を更新
	//補正直後の1msだけエンコーダーの差分を求める式が初期値の問題でバグる。そんなすぐにはエンコーダー参照しないので問題ないはず

	return temp_delta;	//速度を求めるために補正した差分を使う
}

volatile void encoder::yi_correct(ENC_SIDE enc_side) {
	mouse::run_init(false, false);
	if (enc_side == enc_right) {
		motor::set_duty(MOTOR_SIDE::m_right, 40);
	} else {
		motor::set_duty(MOTOR_SIDE::m_left, 50);
	}

	//補正テーブルを全消去
	isCorrect[enc_side] = false;	//Y.I.式補正は中止
	for (int i = 0; i <= ENC_RES; i++) {
		correct[enc_side][i] = -1;
	}

	wait::ms(3000);	//回転が平衡状態に達するまで待機

	//初期値代入
	raw_count[enc_side] = 0;
	correct[enc_side][0] = 0;
	init_time[enc_side] = wait::get_count();
	correct_flag[enc_side] = true;
	while (correct_flag[enc_side])
		;	//一周分測定
	int16_t finish_val = raw_count[enc_side];	//ENC_RESを少し超えて終了するので、0より少し大きい値のはず
	uint32_t finish_time = (wait::get_count() - init_time[enc_side]);	//終了した時間を保存

	motor::sleep_motor();

	//とびとびで値が保存されているはずなので、補完する
	int16_t bigger_val = 0;		//線系補完するときの、大きいほうのエンコーダ―の生値
	uint32_t bigger_time = 0;		//線系補完するときの、大きいほうの時間
	if (correct[enc_side][ENC_RES] == -1) {	//ぴったりENC_RESで終わってなかったら
		bigger_val = ENC_RES + finish_val;
		bigger_time = finish_time;
	} else {								//ぴったり終わっていれば、最後の値をそのまま入れる
		bigger_val = ENC_RES;
		bigger_time = correct[enc_side][ENC_RES];
	}
	for (int i = ENC_RES; i >= 0; i--) {	/* おしりから値が入っていないところを探していく */
		if (correct[enc_side][i] != -1) {	/* 値が入っていたら */
			if (bigger_val - i <= 1) {	/* 値が入っているのが連続なら(ENC_RESに値が入っている場合のために不等号) */
				/* 線系補完はしない */
			} else {
				/* 間のやつらを線形補完する */
				float a = static_cast<float>(bigger_time - correct[enc_side][i])
						/ (bigger_val - i);	//傾き
				for (int j = MIN(bigger_val - 1, ENC_RES); j > i; j--) {//bigger_val ~ i までの間を線系補完
					correct[enc_side][j] = static_cast<float>(a * (j - i)
							+ correct[enc_side][i]);	//傾き×現在値＋切片　で線形補完
				}
			}
			//bigger を更新して次へ
			bigger_val = i;
			bigger_time = correct[enc_side][i];
		}
	}

	//ここまででcorrectに連続で値が入ったはず.なので次はcorrectを「correct[生値]=計測時間」から「correct[生値]=補正値」に直していく
	float slope = ENC_RES / correct[enc_side][ENC_RES];//生値/時間の傾き。観測量は曲線だが真の値は直線のはずなのでこれで補正値を求める
	//全て時間から補正値に変換
	for (int i = 0; i <=ENC_RES; i++)
		correct[enc_side][i] *= slope;

}

void encoder::yi_correct() {
	control::ignore_failsafe(true);		//補正中はフェイルセーフを切る

#if (MOUSE_NAME == KOIZUMI_FISH)
	//左右で補正を行う
	yi_correct(enc_right);
	yi_correct(enc_left);
#elif (MOUSE_NAME == KOIZUMI_OVER)
	// 左はエンコーダついてない
	yi_correct(enc_right);
	yi_correct(enc_left);
#endif	/* MOUSE_NAME */

	control::reset_delta(sen_encoder);

	control::ignore_failsafe(false);		//フェイルセーフを復活
}

void encoder::draw_correct(bool right, bool left) {
	if ( ( right == true ) || ( left == true ) ) {
		myprintf("Res");
		if ( left == true ) {
			myprintf(", Left");
		}
		if ( right == true ) {
			myprintf(", Right");
		}
		myprintf("\n\r");

		for (int i = 0; i <=ENC_RES; i++) {
			myprintf("%d", i);
			if ( left == true ) {
				myprintf(", %f", correct[enc_left][i]);
			}
			if ( right == true ) {
				myprintf(", %f", correct[enc_right][i]);
			}
			myprintf("\n\r");
		}
	}
}

void encoder::init(){
//クロック供給

	RCC_AHB1PeriphClockCmd(ENC_GPIO_AHB1Periph, ENABLE);
	RCC_APB1PeriphClockCmd(ENC_TIM_AHB1Periph, ENABLE);

	//Remap
	for(uint32_t i=0; i<ENC_GPIO_N; i++ ){
		GPIO_PinAFConfig(ENC_GPIO.at(i), ENC_GPIO_PIN_SOURCE.at(i), ENC_GPIO_AF.at(i));
	}

	//端子を位相係数ように設定
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	for(uint32_t i=0; i<ENC_GPIO_N; i++ ){
		GPIO_InitStructure.GPIO_Pin = ENC_GPIO_PIN.at(i);
		GPIO_Init(ENC_GPIO.at(i), &GPIO_InitStructure);
	}

	//TIMの設定
	for(uint32_t i=0; i < ENC_N; i++){
		TIM_ARRPreloadConfig(ENC_TIM.at(i), ENABLE);
	}

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = 65535;		//カウンタクリア要因
	TIM_TimeBaseStructure.TIM_Prescaler = 0;//分周(カウンタがPrescaler回カウントされたタイミングで，TIMのカウンタが1加算される)
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//デットタイム発生回路用の分周。通常0(分周しない)。
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//アップカウント
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	for(uint32_t i=0; i < ENC_N; i++){
		TIM_TimeBaseInit(ENC_TIM.at(i), &TIM_TimeBaseStructure);
		//エンコーダ―について設定
		TIM_EncoderInterfaceConfig(ENC_TIM.at(i), TIM_EncoderMode_TI12,
			TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//CH1とCH2の両方のエッジでカウント、CH1もCH2も立ち上がりを読む
		TIM_Cmd(ENC_TIM.at(i), ENABLE);		//タイマ起動
	}
}

encoder::encoder() {
}

encoder::~encoder() {

}

float photo::ave_buf[static_cast<unsigned int>(PHOTO_TYPE::element_count)][GAP_AVE_COUNT] =
		{ 0.0f };
//float photo::diff_buf[PHOTO_TYPE::element_count][GAP_AVE_COUNT] = { 0 };
//uint8_t photo::gap_buf[PHOTO_TYPE::element_count][GAP_AVE_COUNT] = { 0 };
float photo::right_ad, photo::left_ad, photo::front_right_ad,
		photo::front_left_ad, photo::front_ad;
float photo::right_ref, photo::left_ref, photo::front_right_ref,
		photo::front_left_ref, photo::front_ref;
bool photo::light_flag = false;
//right left front_right front_left front
const std::array<float, static_cast<unsigned int>(PHOTO_TYPE::element_count)> photo::wall_edge_down =
		{ -0.02, 0.02, 0, 0, 0 };	//この値を越えたら壁キレ
const std::array<float, static_cast<unsigned int>(PHOTO_TYPE::element_count)> photo::wall_edge_up =
		{ -0.02, 0.02, 0, 0, 0 };	//この値を越えたら壁キレ
const std::array<float, static_cast<unsigned int>(PHOTO_TYPE::element_count)> photo::edge_distance =
		{ 0.010, 0.007, 0, 0, 0 };	//壁キレを検知した距離　区画中心を0としてそこからどれだけ進んでいるか

void photo::led_init(){
	GPIO_InitTypeDef GPIO_InitStructure;	//初期設定のための構造体を宣言

	RCC_AHB1PeriphClockCmd(LED_RCC_AHB1Periph, ENABLE);	//クロック供給

	GPIO_StructInit(&GPIO_InitStructure);	//構造体を初期化
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//クロック
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;		//出力に設定
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//オープンドレインorプッシュプル
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	//プルアップかプルダウンか

	//photo_typeの順番　right,  left, front_right, front_left, front
	for(int i=0; i<PHOTO_N; i++){
		GPIO_InitStructure.GPIO_Pin = LED_GPIO_PIN.at(i);
		GPIO_Init(LED_GPIO.at(i), &GPIO_InitStructure);	//設定
	}
	for(int i=0; i<PHOTO_N; i++){
		GPIO_ResetBits(LED_GPIO.at(i), LED_GPIO_PIN.at(i));	//初期値はOｆｆに
	}

}

void photo::sen_init(){
//GPIO側でアナログモードに設定
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(SEN_RCC_AHB1Periph, ENABLE);
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	for(int i=0; i<PHOTO_N; i++){		//photo_typeの順番　right,  left, front_right, front_left, front
		GPIO_InitStructure.GPIO_Pin = SEN_GPIO_PIN.at(i);
		GPIO_Init(SEN_GPIO.at(i), &GPIO_InitStructure);	//設定
	}


//AD変換の設定
	ADC_InitTypeDef ADC_InitStructure;		//初期設定用の構造体定義
	ADC_CommonInitTypeDef ADC_CommonInitStructure;

	ADC_Cmd(SEN_ADC_CMD, DISABLE);		//ADC1をDisableに
	RCC_APB2PeriphClockCmd(SEN_RCC_APB2Periph_ADC, ENABLE);		//クロック供給
	ADC_DeInit();		//ADCの周辺レジスタをデフォルトの値にリセットする

	//AD変換の基本設定
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;	//PCLK/4 = 16/4 MHz?
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;	//DMAは使用しない
	ADC_CommonInitStructure.ADC_TwoSamplingDelay =
	ADC_TwoSamplingDelay_20Cycles;//連続スキャンとかで使用？　ADC_delay_between_2_sampling_phases
	ADC_CommonInit(&ADC_CommonInitStructure);

	//ADC1の設定
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;		//12bitのAD変換
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;		//シングルモードで動作
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;		//シングルモードで動作
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;	//AD変換の開始に外部トリガは使用しない
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//右詰め左詰め
	ADC_InitStructure.ADC_NbrOfConversion = 9;		//AD変換の入力は9チャンネル

	for(int i=0; i<PHOTO_N; i++){		//photo_typeの順番　right,  left, front_right, front_left, front
		ADC_Init(SEN_ADC.at(i), &ADC_InitStructure);		//front
	}

	ADC_Cmd(SEN_ADC_CMD, ENABLE);		//ADC1をEnableに
	ADC_DMACmd(SEN_ADC_CMD, DISABLE);	//DMAは使わない
}


void photo::switch_led(PHOTO_TYPE sensor_type, bool is_light) {
	uint32_t i = CAST_UI(sensor_type);		//操作するものが何番目か（PHOTO_TYPEのenumで）を管理
	//光らせる
	if (is_light)
		GPIO_SetBits(LED_GPIO.at(i), LED_GPIO_PIN.at(i));
	else
		GPIO_ResetBits(LED_GPIO.at(i), LED_GPIO_PIN.at(i));

}

void photo::init(){
	led_init();
	sen_init();
}


uint16_t photo::get_ad(PHOTO_TYPE sensor_type) {
	uint32_t i = CAST_UI(sensor_type);		//操作するものが何番目か（PHOTO_TYPEのenumで）を管理

	//ad変換
	ADC_ClearFlag(SEN_ADC.at(i), ADC_FLAG_EOC);		//EndFlagをクリアする
	ADC_RegularChannelConfig(SEN_ADC.at(i), SEN_ADC_CH.at(i), 1,
			ADC_SampleTime_3Cycles);		//ADCxのADC_CHを
	ADC_SoftwareStartConv(SEN_ADC.at(i));	//ADCを開始
	while (ADC_GetFlagStatus(SEN_ADC.at(i), ADC_FLAG_EOC) == RESET)
		;		//終わるまで待つ

	return (ADC_GetConversionValue(SEN_ADC.at(i)) >> 4);	//値を取得　4ビットシフトでうまくいってる気がする　右詰めのはずなのに意味わからん。

}

void photo::light(PHOTO_TYPE sensor_type) {
	switch_led(sensor_type, true);
}

void photo::turn_off(PHOTO_TYPE sensor_type) {
	switch_led(sensor_type, false);
}

void photo::turn_off_all() {
	turn_off(PHOTO_TYPE::right);
	turn_off(PHOTO_TYPE::left);
	turn_off(PHOTO_TYPE::front_right);
	turn_off(PHOTO_TYPE::front_left);
	turn_off(PHOTO_TYPE::front);

}

void photo::set_ad(PHOTO_TYPE _sensor_type, float set_value) {

	static float buf[static_cast<unsigned int>(PHOTO_TYPE::element_count)][PHOTO_AVERAGE_TIME] =
			{ 0 };

	uint8_t sen_type = static_cast<unsigned int>(_sensor_type);
	float sum = 0;
	float ave_sum = 0;

	for (uint8_t i = 0; (i + 1) < MAX(PHOTO_AVERAGE_TIME, GAP_AVE_COUNT); i++) {
		if ((i + 1) < PHOTO_AVERAGE_TIME) {		//配列の要素外にアクセスしないように
			buf[sen_type][i] = buf[sen_type][i + 1];	//配列を1つずらす
			sum += buf[sen_type][i];			//ついでに加算する
		}
		if ((i + 1) < GAP_AVE_COUNT) {		//配列の要素外にアクセスしないように
			ave_buf[sen_type][i] = ave_buf[sen_type][i + 1];	//配列を1つずらす
			//diff_buf[sensor_type][i] = diff_buf[sensor_type][i + 1];//配列を1つずらす
			//gap_buf[sensor_type][i] = gap_buf[sensor_type][i + 1];	//配列を1つずらす
			ave_sum += ave_buf[sen_type][i];			//ついでに加算する
		}
	}

	//配列の最後に入れる
	buf[sen_type][(PHOTO_AVERAGE_TIME - 1)] = set_value;//count*[rad/count]/[sec]*[m]
	sum += set_value;

	int16_t now_val = sum / PHOTO_AVERAGE_TIME; 	//見やすさのため名前を付ける
	switch (_sensor_type) {
	case PHOTO_TYPE::right:
		right_ad = now_val;
		break;

	case PHOTO_TYPE::left:
		left_ad = now_val;
		break;

	case PHOTO_TYPE::front_right:
		front_right_ad = now_val;
		break;

	case PHOTO_TYPE::front_left:
		front_left_ad = now_val;
		break;

	case PHOTO_TYPE::front:
		front_ad = now_val;
		break;

	default:
		break;
	}

	ave_buf[sen_type][(GAP_AVE_COUNT - 1)] = now_val;

	/*
	 ave_sum += get_displacement_from_center(sensor_type);
	 //移動平均をとったセンサ値と、それのさらに平均をとったものとの差分を記録
	 //この値は平均を2回取るので、平均区間の真ん中あたりが強調される＝少し前の真値のようなものと考えることができる
	 //その差分なので、おおよそノイズの影響を除去した傾きが分かると信じてる
	 diff_buf[sensor_type][(GAP_AVE_COUNT - 1)] = ave_sum / GAP_AVE_COUNT
	 - static_cast<float>(now_val);
	 gap_buf[sensor_type][(GAP_AVE_COUNT - 1)] = count_wall_gap(sensor_type);//使ってない
	 */
}

void photo::interrupt(bool is_light) {
	const static int wait_number = 1000;	//1000でだいたい100us弱	1500で120usくらい
	photo::turn_off_all();

	photo::set_ref(PHOTO_TYPE::right, get_ad(PHOTO_TYPE::right));//消えてる時をrefにする
	photo::set_ref(PHOTO_TYPE::left, get_ad(PHOTO_TYPE::left));	//消えてる時をrefにする
	photo::set_ref(PHOTO_TYPE::front_right, get_ad(PHOTO_TYPE::front_right));//消えてる時をrefにする
	photo::set_ref(PHOTO_TYPE::front_left, get_ad(PHOTO_TYPE::front_left));	//消えてる時をrefにする
	photo::set_ref(PHOTO_TYPE::front, get_ad(PHOTO_TYPE::front));//消えてる時をrefにする

	// 左右の発光は回路的に同時におこるので、同時に左右の値をとる@鯉住
	if (is_light) {
		photo::light(PHOTO_TYPE::right);
		photo::light(PHOTO_TYPE::left);
		for (volatile int i = 0; i < wait_number * 2; i++) {
		}
	}
	photo::set_ad(PHOTO_TYPE::right,
			static_cast<float>(get_ad(PHOTO_TYPE::right) - get_ref(PHOTO_TYPE::right)));	//差分を代入
	photo::set_ad(PHOTO_TYPE::left,
			static_cast<float>(get_ad(PHOTO_TYPE::left) - get_ref(PHOTO_TYPE::left)));		//差分を代入
	photo::turn_off(PHOTO_TYPE::right);
	photo::turn_off(PHOTO_TYPE::left);

	// おそらく独立と見なして良い
	if (is_light) {
		photo::light(PHOTO_TYPE::front_right);
		photo::light(PHOTO_TYPE::front_left);
		photo::light(PHOTO_TYPE::front);
		for (volatile int i = 0; i < wait_number; i++) {
		}
	}
	photo::set_ad(PHOTO_TYPE::front,
			static_cast<float>(get_ad(PHOTO_TYPE::front) - get_ref(PHOTO_TYPE::front)));	//差分を代入
	photo::turn_off(PHOTO_TYPE::front);
	photo::set_ad(PHOTO_TYPE::front_right,
			get_ad(PHOTO_TYPE::front_right) - get_ref(PHOTO_TYPE::front_right));//差分を代入
	photo::turn_off(PHOTO_TYPE::front_right);
	photo::set_ad(PHOTO_TYPE::front_left,
			get_ad(PHOTO_TYPE::front_left) - get_ref(PHOTO_TYPE::front_left));//差分を代入
	photo::turn_off(PHOTO_TYPE::front_left);

	photo::turn_off_all();
}

int16_t photo::get_ref(PHOTO_TYPE sensor_type) {
	switch (sensor_type) {
	case PHOTO_TYPE::right:
		return right_ref;
		break;

	case PHOTO_TYPE::left:
		return left_ref;
		break;

	case PHOTO_TYPE::front_right:
		return front_right_ref;
		break;

	case PHOTO_TYPE::front_left:
		return front_left_ref;
		break;

	case PHOTO_TYPE::front:
		return front_ref;
		break;

	default:
		break;
	}

	return 0;
}

void photo::set_ref(PHOTO_TYPE sensor_type, int16_t set_value) {
	switch (sensor_type) {
	case PHOTO_TYPE::right:
		right_ref = set_value;
		break;

	case PHOTO_TYPE::left:
		left_ref = set_value;
		break;

	case PHOTO_TYPE::front_right:
		front_right_ref = set_value;
		break;

	case PHOTO_TYPE::front_left:
		front_left_ref = set_value;
		break;

	case PHOTO_TYPE::front:
		front_ref = set_value;
		break;

	default:
		break;
	}
}

float photo::get_value(PHOTO_TYPE sensor_type) {
	static bool ReEntrant = false;
	if (ReEntrant)
		return 0;
	ReEntrant = true;

	int16_t ad = 0;
	switch (sensor_type) {
	case PHOTO_TYPE::right: {
		ad = right_ad;
		break;
	}
	case PHOTO_TYPE::left: {
		ad = left_ad;
		break;
	}
	case PHOTO_TYPE::front_right: {
		ad = front_right_ad;
		break;
	}
	case PHOTO_TYPE::front_left: {
		ad = front_left_ad;
		break;
	}
	case PHOTO_TYPE::front: {
		ad = front_ad;
		break;
	}
	default:
		break;
	}
	ReEntrant = false;
	return static_cast<float>(ad) * 4.0 / get_battery();	//電圧で値が減っている気がするので補正
}

#if (MOUSE_NAME == KOIZUMI_FISH)
float photo::get_displa_from_center(PHOTO_TYPE type) {
	return get_displa_from_center(type, (photo::get_value(type)));//現在のセンサ値に対して求める
}

float photo::get_displa_from_center(PHOTO_TYPE sensor_type, float val) {
	static bool reent = false;		//リエントラント性担保

	if (reent)		//実行中なので、適当な値返して抜ける
		return 0;
	reent = true;
	float a0, a1, a2, alog;	//小島近似の係数	x^0,x,x^2,logの係数
	float f = val;		//対称のセンサ値
	float f_c = (parameter::get_correct_photo(sensor_type));	//オフセット
	float ans = 0;

	if (f <= 0) {
		f = 0.1;
	} else if (f > 5000) {
		f = 5000;
	}

	switch (sensor_type) {
	case PHOTO_TYPE::right:

		a0 = -45.8514 + f_c;
		a1 = 0.0902958;
		a2 = -7.23724 * 0.00001;
		alog = 5.79814;
		break;

	case PHOTO_TYPE::left:

		a0 = 134.392 + f_c;
		a1 = 0.0503701;
		a2 = -3.30731 * 0.00001;
		alog = -25.5219;
		break;

	case PHOTO_TYPE::front_right:
		return 0;
		break;

	case PHOTO_TYPE::front_left:
		return 0;
		break;

	case PHOTO_TYPE::front: {
		a0 = -397 + f_c;
		a1 = -0.0085;
		a2 = 2.2 * 0.000001;
		alog = 51;
		break;
	}

	default:
		return 0;
		break;
	}

	ans = a2 * f + a1;
	ans = ans * f + a0 + alog * logf(f);

	reent = false;	//終了する前にリエントラントをオフに
	return ans * 0.001;
}

bool photo::check_wall(unsigned char muki) {

	switch (muki) {
	case MUKI_RIGHT:
		if (photo::get_value(PHOTO_TYPE::right)
				>= parameter::get_min_wall_photo(PHOTO_TYPE::right)) {
			return true;
		}
		return false;

	case MUKI_LEFT:
		if (photo::get_value(PHOTO_TYPE::left)
				>= parameter::get_min_wall_photo(PHOTO_TYPE::left)) {
			return true;
		}
		return false;

	case MUKI_UP:
		//TODO 暇があったら、前壁見るのは斜めセンサいらない？？
		//FIXME 3msくらいの多数決
		uint32_t counter = mouse::get_count_ms();
		int loop = 0;
		int check = 0;
		while(1){
			loop++;
			counter = mouse::get_count_ms();
			while(mouse::get_count_ms() == counter){
			}
			if (photo::get_value(PHOTO_TYPE::front)
							>= parameter::get_min_wall_photo(PHOTO_TYPE::front)){
				check++;
			}else{
				check--;
			}
			if(loop>=3) break;
		}
		if(check >= 0){
//		if (photo::get_value(PHOTO_TYPE::front)
//				>= parameter::get_min_wall_photo(PHOTO_TYPE::front)) {
			//if ((front_right_ad >= parameter::get_min_wall_photo(front_right))
			//		|| (front_left_ad >= parameter::get_min_wall_photo(front_left))) {
			return true;
		}
		return false;
	}

	return false;

}

bool photo::check_wall(PHOTO_TYPE type) {
	/*
	 float displa = photo::get_displa_from_center(type);
	 if (type == PHOTO_TYPE::left) {
	 displa *= -1;
	 }

	 if (displa > -0.01)
	 return true;
	 return false;
	 */
	if (photo::get_value(type) >= parameter::get_min_wall_photo(type))
		return true;
	else
		return false;

}

#elif (MOUSE_NAME == KOIZUMI_OVER)
float photo::get_displa_from_center(PHOTO_TYPE type) {
	float ans;
	if(type == front){	/* 越頭見には前センサは存在しないので斜めセンサの平均を使う */
		ans = get_displa_from_center(type, (photo::get_value(front_right)));
		ans += get_displa_from_center(type, (photo::get_value(front_left)));
		ans /= 2.0;
	}else{
		ans = get_displa_from_center(type, (photo::get_value(type)));//現在のセンサ値に対して求める
	}
	return ans;
}

float photo::get_displa_from_center(PHOTO_TYPE sensor_type, float val) {
	static bool reent = false;		/* リエントラント性担保 */

	if (reent){		/* 実行中なので、適当な値返して抜ける */
		return 0;
	}else{
		reent = true;
	}

	float f = val;		//対称のセンサ値
	float f_c;
	float ans = 0;

	/* 本来あり得ない値が来た場合は上限下限に張り付かせる */
	if (f <= 0) {
		f = 0.1;
	} else if (f > 5000) {
		f = 5000;
	}

	switch (sensor_type) {
	case PHOTO_TYPE::right:
	case PHOTO_TYPE::front_right:
	case PHOTO_TYPE::front_left:
		f_c = (parameter::get_correct_photo(sensor_type));
		ans = f/f_c - 1.0;	/* 区画中心での値との比率を求める。おそらく　f/f_c＝0.1~10のオーダー */
		break;

	case PHOTO_TYPE::left:	/* 左はセンサの大小関係と距離の大小関係が反対なので反転 */
		f_c = (parameter::get_correct_photo(sensor_type));
		ans = -f/f_c + 1.0;	/* 区画中心での値との比率を求める。おそらく　f/f_c＝0.1~10のオーダー */
		break;

	case PHOTO_TYPE::front: /* 越頭見には前センサは存在しないのでなにもしない*/
		return 0;
		break;

	default:
		return 0;
		break;
	}

	reent = false;	//終了する前にリエントラントをオフに
	return ans * 2 * 0.001;
}

bool photo::check_wall(unsigned char muki) {
	PHOTO_TYPE type;
	switch (muki) {
	case MUKI_RIGHT:
		type = right;
		break;

	case MUKI_LEFT:
		type = left;
		break;

	case MUKI_UP:
		type = front;
		break;

	default:
		return false;
		break;
	}

	return check_wall(type);

}

bool photo::check_wall(PHOTO_TYPE type) {
	if(type == PHOTO_TYPE::front){		/* 越頭見には前センサは存在しないので斜めセンサで代用 */
		/* 壁は無い方に誤認するとぶつかって死ぬので、安全側に倒す。どちらかが反応すればあり。 */
		if (photo::get_value(PHOTO_TYPE::front_right) >= parameter::get_min_wall_photo(PHOTO_TYPE::front_right)){
			return true;
		}else if (photo::get_value(PHOTO_TYPE::front_left) >= parameter::get_min_wall_photo(PHOTO_TYPE::front_left)){
			return true;
		}else{
			return false;
		}

	}else{
		if (photo::get_value(type) >= parameter::get_min_wall_photo(type))
			return true;
		else
			return false;
	}
	return false;
}

#endif	/* MOUSE_NAME */

/*
 int8_t photo::count_wall_gap(PHOTO_TYPE type) {
 int8_t count = 0;	//負（センサ値が下がってる）の数を数える
 for (uint8_t i = 0; i < GAP_AVE_COUNT; i++) {
 if (diff_buf[type][i] < 0)
 count--;
 else
 count++;
 }
 return count;
 }

 bool photo::check_wall_gap(PHOTO_TYPE type, float threshold) {
 //壁の切れ目ならtrue
 //急に壁が現れた時も制御を切る

 float before_val = get_side_from_center(type, ave_buf[type][0]);
 float now_val = get_side_from_center(type,
 ave_buf[type][GAP_AVE_COUNT - 1]);

 if (ABS(now_val-before_val) > ABS(threshold)) {		//壁の切れ目
 return true;
 }

 return false;

 }
 */
bool photo::check_wall_edge(PHOTO_TYPE _type, bool _over_threshold) {
	//壁キレ検知でtrue

	int sen_type = static_cast<int>(_type);
	float sign = -1;		//下から上に超えるか(-1)、上から下に超えるか(+1)
	float thre = wall_edge_up.at(sen_type);	//閾値
	if (_over_threshold) {
		sign = 1;
		thre = wall_edge_down.at(sen_type);	//閾値
	}

	//閾値を通り超えたら壁キレ
	photo::get_displa_from_center_debag(_type);
	if ((thre - 0) * sign >= 0) {
		my7seg::light(5);
		mouse::set_relative_go(edge_distance.at(sen_type));		//座標を補正
		my7seg::turn_off();
		return true;
	}
	my7seg::light(5);

	my7seg::turn_off();
	return false;

}

photo::photo() {
}

photo::~photo() {
}

//XXX 各種ゲイン
//control関連
#if (MOUSE_NAME == KOIZUMI_FISH)
const PID gyro_gain = { 15, 750, 0.015 };
PID photo_gain = /*{ 100,0,0.003};*/{ 200, 0, 0.005 };
const PID encoder_gain = { 200, 1000, 0 };	//カルマンフィルタでエンコーダーと加速度センサから求めた速度に対するフィルタ
const PID accel_gain = { 0, 0, 0 };	//{50, 0, 0 };

const float ff_gain_vel = 1.0;	// モータを定常回転させるために必要なFF項のゲイン
const float ff_gain_accel = 1.0;	// モータを加速させるために必要なFF項のゲイン
const float ff_gain_mu = 0.00035;	// 摩擦力 のFFゲイン

#elif (MOUSE_NAME == KOIZUMI_OVER)
const PID gyro_gain = { 10., 17.5, 0.0 };
PID photo_gain = { 200, 0, 0.005 };
const PID encoder_gain = { 200, 50, 0 };	//カルマンフィルタでエンコーダーと加速度センサから求めた速度に対するフィルタ
const PID accel_gain = { 0, 0, 0 };

const float ff_gain_vel = 1.0;	// モータを定常回転させるために必要なFF項のゲイン
const float ff_gain_accel = 1.0;	// モータを加速させるために必要なFF項のゲイン
const float ff_gain_mu = 0.00035;	// 摩擦力 のFFゲイン
#endif /* MOUSE_NAME */

PID control::gyro_delta, control::photo_delta, control::encoder_delta,
		control::accel_delta;
bool control::control_phase = false;
bool control::wall_control_flag = false;
bool control::ignore_fail_safe = false;
//XXX FF制御とFB制御やるかやらないか決める場所
bool control::is_FF_CONTROL = true;
bool control::is_FB_CONTROL = true;

volatile float control::cross_delta_gain(SEN_TYPE sensor) {
	switch (sensor) {
	case sen_gyro:
		return (gyro_delta.P * gyro_gain.P + gyro_delta.I * gyro_gain.I
				+ gyro_delta.D * gyro_gain.D);

	case sen_encoder:
		return (encoder_delta.P * encoder_gain.P
				+ encoder_delta.I * encoder_gain.I
				+ encoder_delta.D * encoder_gain.D);

	case sen_photo:
		return (photo_delta.P * photo_gain.P + photo_delta.I * photo_gain.I
				+ photo_delta.D * photo_gain.D);

	case sen_accel:
		return (accel_delta.P * accel_gain.P + accel_delta.I * accel_gain.I
				+ accel_delta.D * accel_gain.D);

	default:
		break;

	}
	return 0;
}

//XXX 偏差を計算してる場所
void control::cal_delta() {
	float before_p_delta;

	//エンコーダーのΔ計算
	before_p_delta = encoder_delta.P;	//積分用
	encoder_delta.P = (mouse::get_ideal_velocity() - mouse::get_velocity());
	encoder_delta.I += (encoder_delta.P * CONTORL_PERIOD);
	encoder_delta.D = (encoder_delta.P - before_p_delta) / CONTORL_PERIOD;

	//センサーのΔ計算

	float photo_right_delta = 0, photo_left_delta = 0;
	before_p_delta = photo_delta.P;
	if (control::get_wall_control_phase()) {
		switch (mouse::get_compas()) {
		//斜めじゃなければ何もしない
		case north:
		case south:
		case west:
		case east:
			if (photo::check_wall(PHOTO_TYPE::right)) {
				photo_right_delta = photo::get_displa_from_center(
						PHOTO_TYPE::right);	//中心からのずれてる距離[m]
			}
			if (photo::check_wall(PHOTO_TYPE::left)) {
				photo_left_delta = photo::get_displa_from_center(
						PHOTO_TYPE::left);	//中心からのずれてる距離[m]
			}

			//壁の切れ目ではじかれるので消去
//			if (photo_right_delta == 0)
//				photo_left_delta *= 2;
//			else if (photo_left_delta == 0)
//				photo_right_delta *= 2;

			//photo_correct = (photo_right_delta + photo_left_delta) / 2;		//センサ値から推定した値をカルマンフィルタの推定値とする
			photo_delta.P = (photo_right_delta + photo_left_delta) / 2;

			static const float half_section = 0.045 * MOUSE_MODE;	//1区間の半分の長さ
			//柱近傍はセンサ値を信用しない。 区画の中央部分
			if (ABS(mouse::get_relative_go() - 0.01 * MOUSE_MODE)
					< (half_section * 0.2)) {
				photo_delta.P = 0;//mouse::get_relative_side();		//センサを信用しない　= 推定値を突っ込んどく
			}
			//photo_delta.P = mouse::get_relative_side();

			//センサの推定値で補正
			//if(photo_delta.P != 0){
			//	mouse::set_relative_side(photo_delta.P);
			//}

			break;

			//斜めなら
		case north_east:
		case north_west:
		case south_east:
		case south_west:

			photo_delta.P = 0;
			photo_delta.I = 0;			//要検討

			//ぶつかりそうな時だけ避けるように
			if (photo::get_displa_from_center(PHOTO_TYPE::right) >= 0)
				photo_delta.P = photo::get_displa_from_center(
						PHOTO_TYPE::right);
			if (photo::get_displa_from_center(PHOTO_TYPE::left) <= 0)
				photo_delta.P = photo::get_displa_from_center(PHOTO_TYPE::left);

			photo_delta.P *= 0.8; //斜めの制御パラメータ

			break;

		default:
			mouse::error();		// ここに来るはずないので、エラー
			myprintf("Error! cal_delta()");
			break;

		}
		//photo_delta.P = mouse::get_relative_side();		//センサを信用しない　= 推定値を突っ込んどく

		//速度が低いと制御が効きすぎるので（相対的に制御が大きくなる）、切る
		if (mouse::get_ideal_velocity() < SEARCH_VELOCITY * 0.5) {
			photo_delta.P = 0;
		}
		photo_delta.I += (photo_delta.P * CONTORL_PERIOD);
		photo_delta.D = mouse::get_velocity() * mouse::get_relative_rad(); //Vθ オドメトリから求めたD項　Sinθ~θと近似

	} else {
		//壁制御かけないときは初期化し続ける。
		photo_delta.P = 0;
		photo_delta.I = 0;
		photo_delta.D = 0;
	}

	float wall_delta = cross_delta_gain(sen_photo);
	//if(wall_delta!=0)
	//	mouse::set_relative_rad(mouse::get_relative_rad()-0.1*wall_delta,true);

	//ジャイロのΔ計算
	before_p_delta = gyro_delta.P;	//積分用
	gyro_delta.P = (mouse::get_ideal_angular_velocity()
			- gyro::get_angular_velocity());
	// gyro_delta.P -= wall_delta;		//壁制御量を目標角速度に追加
	gyro_delta.I += (gyro_delta.P * CONTORL_PERIOD);
	gyro_delta.D = (gyro_delta.P - before_p_delta) / CONTROL_PERIOD;

}

float control::control_accel() {
	return cross_delta_gain(sen_accel);
}

float control::control_velocity() {
	return cross_delta_gain(sen_encoder);
}

float control::control_angular_velocity() {
	return cross_delta_gain(sen_gyro);
}

void control::start_wall_control() {
	wall_control_flag = true;
}

void control::stop_wall_control() {
	wall_control_flag = false;
}

void control::start_control() {
	control_phase = true;
}

void control::stop_control() {
	control_phase = false;
}

float control::get_feedback(signed char right_or_left) {
	if (right_or_left == MUKI_RIGHT) {			//右のモーターなら
		return (control_velocity() - control_angular_velocity());
	} else {										//左のモーターなら
		return (control_velocity() + control_angular_velocity());

	}
}

float control::get_feedforward(const signed char right_or_left) {
	float velocity;		//目標速度
	float accel;		//目標加速度

	if (right_or_left == MUKI_RIGHT) {			//右のモーターなら
		velocity = mouse::get_ideal_velocity()
				- (mouse::get_ideal_angular_velocity() * TREAD_W / 2);
		accel = mouse::get_ideal_accel()
				- (mouse::get_ideal_angular_accel() * TREAD_W / 2);

	} else {									//左のモーターなら
		velocity = mouse::get_ideal_velocity()
				+ (mouse::get_ideal_angular_velocity() * TREAD_W / 2);
		accel = mouse::get_ideal_accel()
				+ (mouse::get_ideal_angular_accel() * TREAD_W / 2);

	}

	float Vinv;		//motorが回転することによる逆気電圧
	float Vt;		//motorを回転させるために必要なトルクを生み出すための電圧

	// V = v[m/s]/2πr[m] * ギア比  / 電圧特性[回/s/V]
	Vinv = (velocity / (2 * PI() * tire_R) * SPAR / PINION / MOTOR_CONST) * ff_gain_vel;

	// V = 加速に必要な分
	Vt = ( (PI() * tire_R * MASS * MOTOR_ORM * MOTOR_CONST) * accel * ff_gain_accel ) * PINION / SPAR;

	// V = 摩擦力を打ち消す分	モータの回転方向（≠駆動方向）にかかる
	Vt += ( (2 * PI() * MOTOR_ORM * MOTOR_CONST * ff_gain_mu) )	* PINION / SPAR * SIGN(velocity);

	return ((Vinv + Vt) * M_SUM_ORM / MOTOR_ORM / get_battery()) * 100;
}

void control::posture_control() {
	if (get_control_phase()) {			//制御を掛けるなら
		if (is_FF_CONTROL || is_FB_CONTROL) {		//FFかFBのどちらかでも制御を掛けるとき

			float duty_r = 0, duty_l = 0;		//dutyを保存するよう

			if (is_FF_CONTROL) {			//FF制御を掛けるなら
				duty_r = get_feedforward(MUKI_RIGHT);
				duty_l = get_feedforward(MUKI_LEFT);
			}
			if (is_FB_CONTROL) {				//FB制御を掛けるなら
				duty_r += get_feedback(MUKI_RIGHT);
				duty_l += get_feedback(MUKI_LEFT);
			}

			motor::set_duty(m_right, duty_r);
			motor::set_duty(m_left, duty_l);
		}
	}
}

bool control::get_control_phase() {
	return control_phase;
}

bool control::get_wall_control_phase() {
	return wall_control_flag;
}

void control::reset_delta() {
	reset_delta(sen_gyro);
	reset_delta(sen_photo);
	reset_delta(sen_encoder);
	reset_delta(sen_accel);

}

volatile void control::reset_delta(SEN_TYPE type) {

	switch (type) {
	case sen_gyro:
		gyro_delta.P = 0;
		gyro_delta.I = 0;
		gyro_delta.D = 0;
		break;

	case sen_photo:
		photo_delta.P = 0;
		photo_delta.I = 0;
		photo_delta.D = 0;
		break;

	case sen_encoder:
		encoder_delta.P = 0;
		encoder_delta.I = 0;
		encoder_delta.D = 0;
		break;

	case sen_accel:
		accel_delta.P = 0;
		accel_delta.I = 0;
		accel_delta.D = 0;
		break;

	default:
		break;
	}
}

void control::fail_safe() {

	//フェイルセーフを無視するなら何もしない
	if (ignore_fail_safe)
		return;

	//閾値どのくらいかわからない。Gyroも参照すべき？
	if (ABS(encoder_delta.P) > 1.0) {
//		if (ABS(gyro_delta.P) > 1) {
		motor::sleep_motor();
		mouse::set_fail_flag(true);
//		}
	}
}

void control::ignore_failsafe(bool ignore) {
	ignore_fail_safe = ignore;
}

control::control() {
}

control::~control() {

}

void kalman::update(float EstimateU, float ObserveZ) {
	float esX = x + EstimateU;		//前回の値に推定分だけずれた値を推定値とする
	float esP = p + EstP;			//前回の分散に推定分だけ分散を増やす
	float delta = ObserveZ - esX;	//観測量と推定値の差分
	float K = esP / (ObsP + esP);	//カルマンゲイン

	x = esX + K * delta;	//カルマンフィルタで推定値を補正
	p = (1 - K) * esP;		//補正後の分散
}

float kalman::get_value() {
	return x;
}

float kalman::get_dispersion() {
	return p;
}

kalman::kalman() {
	x = 0;
	p = 0;
	EstP = 0;
	ObsP = 0;
}

kalman::kalman(float EstimateP, float ObserveP) {
	x = 0;
	p = 0;
	EstP = EstimateP;
	ObsP = ObserveP;
}

kalman::kalman(float initX, float initP, float EstimateP, float ObserveP) {
	x = initX;
	p = initP;
	EstP = EstimateP;
	ObsP = ObserveP;
}

kalman::~kalman() {
}
