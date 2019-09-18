/*
 * hardware.cpp
 *
 *  Created on: 2015/06/13
 *      Author: Koizumi
 */

#include"hardware.h"

//����7�Z�O�֘A
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
	//7�Z�O�ŕ\���ł���킯�˂�����I
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
	//7�Z�O�ŕ\���ł���킯�˂�����I
	if (number >= UI_MODE_N) {
		//error
		light_error();
		return;
	} else {
		//XXX	TBD �����͊֐��|�C���^��Reset or SET�� LED ON/OFF�݂����ɈӖ��Ń��b�s���O����
		for(int i=0; i<UI_GPIO_N;i++){
			if( UI_GPIO_LIGHT_PTN.at(number).at(i) ==1 ){
				GPIO_ResetBits(UI_GPIO.at(i).first, UI_GPIO.at(i).second);		/* LED�@ON */
			}else{
				GPIO_SetBits(UI_GPIO.at(i).first, UI_GPIO.at(i).second);		/* LED�@OFF */
			}
		}
	}

}
#endif	/* MOUSE_NAME */

void my7seg::turn_off() {
	for(unsigned int i=0; i<UI_GPIO_N; i++){
		GPIO_SetBits(UI_GPIO.at(i).first, UI_GPIO.at(i).second);	/* LED�͏����Ƃ� */
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
		GPIO_SetBits(UI_GPIO.at(i).first, UI_GPIO.at(i).second);	/* LED�͑S�_�� */
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

		GPIO_SetBits(UI_GPIO.at(i).first, UI_GPIO.at(i).second);	/* LED�͏����Ƃ� */
	}

}

//motor�֘A
signed char motor::right_duty = 0, motor::left_duty = 0;
const char motor::MAX_DUTY = 100;
bool motor::motor_state = false;

void motor::set_duty(const MOTOR_SIDE side, const float set_duty) {
	float duty = 0;		//�ꎞ�I�ȕۑ�

	//Duty�ɐ�Βl���Ƃ�
	//�����؂�
	duty = MIN( ABS(set_duty), MAX_DUTY);

	static TIM_OCInitTypeDef TIM_OC_InitStructure;
	TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;		//���[�h��PWM1
	TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//���Ԃ񂢂�Ȃ��BThis parameter is valid only for TIM1 and TIM8.
	TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;//���Ԃ񂢂�Ȃ��BThis parameter is valid only for TIM1 and TIM8.

	TIM_OC_InitStructure.TIM_Pulse = static_cast<uint32_t>(MAX_PERIOD * duty
			* 0.01);	//duty�ɉ����ăJ�E���g��ύX
	if (set_duty == 0) {					//0�̂Ƃ���stop
		TIM_OC_InitStructure.TIM_Pulse = 0;		//duty0�̎��͈ꉞ0�������Ă���
		TIM_OC1Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4��CH1
		TIM_OC2Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4��CH2

	} else if (set_duty > 0) {				//���̂Ƃ��͐��]
		TIM_OC1Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4��CH1
		TIM_OC_InitStructure.TIM_Pulse = 0;		//�d�ʍ�����邽�߁A�Е���0��
		TIM_OC2Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4��CH2

	} else {									//���̂Ƃ��͋t�]
		TIM_OC2Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4��CH2
		TIM_OC_InitStructure.TIM_Pulse = 0;		//�d�ʍ�����邽�߁A�Е���0��
		TIM_OC1Init(PWM_TIM.at(CAST_UI(side)), &TIM_OC_InitStructure);		//TIM4��CH1

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
	GPIO_ResetBits(SLEEP_GPIO, SLEEP_GPIO_PIN);	//���[�^�[�h���C�o�[�X���[�v
	for( uint32_t side = 0; side < MOTOR_N; side++){
		TIM_Cmd(PWM_TIM.at(side), DISABLE);
		motor::set_duty(static_cast<MOTOR_SIDE>(side), 0);
	}
	motor_state = false;

}

void motor::stanby_motor() {
	GPIO_SetBits(SLEEP_GPIO, SLEEP_GPIO_PIN);	//���[�^�[�h���C�o�[�X�^���o�C
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

	//���[�^�h���C�o�X���[�v�ݒ�
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = SLEEP_GPIO_PIN;
	GPIO_Init(SLEEP_GPIO, &GPIO_InitStructure);

	GPIO_ResetBits(SLEEP_GPIO, SLEEP_GPIO_PIN);		//���[�^�[�h���C�o�[���X���[�v���[�h��


	RCC_AHB1PeriphClockCmd(PWM_GPIO_AHB1Periph, ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	for(int i=0; i<PWM_IN_N; i++){
		GPIO_InitStructure.GPIO_Pin = PWM_GPIO_PIN.at(i);
		GPIO_Init(PWM_GPIO.at(i), &GPIO_InitStructure);	//�ݒ�
	}


	RCC_APB1PeriphClockCmd(PWM_TIM_AHB1Periph, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	TIM_InitStructure.TIM_Period = MAX_PERIOD;//�J�E���^�N���A�v�� 100kHz Excel�t�@�C������TIM�̃N���b�N���m�F
	TIM_InitStructure.TIM_Prescaler = 0;//�v���X�P�[��(�J�E���^��Prescaler��J�E���g���ꂽ�^�C�~���O�ŁCTIM�̃J�E���^��1���Z�����)
	TIM_InitStructure.TIM_ClockDivision = 0;	//�f�b�g�^�C��������H�p�̕����B�ʏ�0(�������Ȃ�)�B
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;	//�A�b�v�J�E���g
	TIM_InitStructure.TIM_RepetitionCounter = 0;
	for(uint32_t i=0; i<MOTOR_N; i++){
		TIM_TimeBaseInit(PWM_TIM.at(i), &TIM_InitStructure);
	}

	TIM_OCInitTypeDef TIM_OC_InitStructure;
	TIM_OC_InitStructure.TIM_OCMode = TIM_OCMode_PWM1;		//���[�h��PWM1
	TIM_OC_InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//���Ԃ񂢂�Ȃ��BThis parameter is valid only for TIM1 and TIM8.
	TIM_OC_InitStructure.TIM_OutputState = TIM_OutputState_Enable;//���Ԃ񂢂�Ȃ��BThis parameter is valid only for TIM1 and TIM8.
	TIM_OC_InitStructure.TIM_Pulse = 0;	//�p���X���BDuty��Ɋ֌W�B

	for(uint32_t i=0; i<MOTOR_N; i++){
		//PWM�o�͂�4�{�K�v�Ȃ̂Ŋe�^�C�}2����
		TIM_OC1Init(PWM_TIM.at(i), &TIM_OC_InitStructure);		//TIM2��CH1
		TIM_OC1PreloadConfig(PWM_TIM.at(i), TIM_OCPreload_Enable);
		TIM_OC2Init(PWM_TIM.at(i), &TIM_OC_InitStructure);		//TIM2��CH2
		TIM_OC2PreloadConfig(PWM_TIM.at(i), TIM_OCPreload_Enable);
	}

	for(int i=0; i<PWM_IN_N; i++){
		GPIO_PinAFConfig(PWM_GPIO.at(i), PWM_GPIO_PIN_SOURCE.at(i), PWM_GPIO_AF.at(i));
	}


	//TIM�N��
	for(uint32_t i=0; i<MOTOR_N; i++){
		TIM_ARRPreloadConfig(PWM_TIM.at(i), ENABLE);
		TIM_Cmd(PWM_TIM.at(i), ENABLE);
	}

}

motor::motor() {
}

motor::~motor() {

}

//gyro�֘A
SPI_TypeDef* mpu6000::use_SPI = SPI1;		//SPI1~3�̂ǂ�g���Ă邩
GPIO_TypeDef* mpu6000::cs_GPIOx = GPIOA;		//cs�@���s���̐ݒ�
const uint16_t mpu6000::cs_GPIO_Pin = GPIO_Pin_4;	//cs�@���s���̐ݒ�

//���W�X�^�[��`
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
	uint16_t reg = (read_reg | 128);	//read���̓��W�X�^�[�̍ŏ��Bit��1��

	GPIO_ResetBits(cs_GPIOx, cs_GPIO_Pin); // CS���Z�b�g

	//���W�X�^�w��
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		; // ���M�\�ɂȂ�܂ő҂�
	SPI_I2S_SendData(use_SPI, reg); // ���M
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_RXNE) == RESET)
		; // ��M�\�ɂȂ�܂ő҂�
	data = SPI_I2S_ReceiveData(use_SPI); // ��f�[�^����M����

	//�f�[�^�̑���M
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		; // ���M�\�ɂȂ�܂ő҂�
	SPI_I2S_SendData(use_SPI, 0x00); // ���M
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_RXNE) == RESET)
		; // ��M�\�ɂȂ�܂ő҂�
	data = SPI_I2S_ReceiveData(use_SPI); // ��M����
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		;

	GPIO_SetBits(cs_GPIOx, cs_GPIO_Pin); //CS�����Z�b�g

	//�A�����čs���Ă����܂������悤�ɏ��������҂B
	for (int i = 0; i < 5; i++)
		;

	return data;
}

void mpu6000::write_spi(uint16_t reg, uint16_t data) {

	GPIO_ResetBits(cs_GPIOx, cs_GPIO_Pin); // CS���Z�b�g

	//���W�X�^�w��
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		; // ���M�\�ɂȂ�܂ő҂�
	SPI_I2S_SendData(use_SPI, reg); // ���M
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_RXNE) == RESET)
		; // ��M�\�ɂȂ�܂ő҂�
	SPI_I2S_ReceiveData(use_SPI); // ��f�[�^����M����

	//�f�[�^�̑���M
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		; // ���M�\�ɂȂ�܂ő҂�
	SPI_I2S_SendData(use_SPI, data); // ���M
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_RXNE) == RESET)
		; // ��M�\�ɂȂ�܂ő҂�
	SPI_I2S_ReceiveData(use_SPI); // ��M����
	while (SPI_I2S_GetFlagStatus(use_SPI, SPI_I2S_FLAG_TXE) == RESET)
		;

	GPIO_SetBits(cs_GPIOx, cs_GPIO_Pin); //CS�����Z�b�g

	//�A�����čs���Ă����܂������悤�ɏ��������҂B
	for (int i = 0; i < 10; i++)
		;

}

volatile int16_t mpu6000::get_mpu_val(SEN_TYPE sen, AXIS_t axis) {
	int16_t data = 0;
	uint16_t reg_h = 0;	//high�̒l�ւ̃��W�X�^
	uint16_t reg_l = 0;	//Low�̒l�ւ̃��W�X�^

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

	default:		//gyro�Ɖ����x�ȊO�͓ǂ߂Ȃ��̂ŏ����l��Ԃ��ďI��
		return data;
		break;
	}

	//High�̕��͏�ʂ�8�r�b�g���炵��Low�ƍ��킹�āA�ړI�̃f�[�^�𓾂�B
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

	write_spi(PWR_MGMT_1, 0x00);		//�T�C�N��1�ASLEEP�����A���x�Z���T�͎g��Ȃ�
	write_spi(PWR_MGMT_2, 0xC6);		//�W���C����Z�������ȊO�͒�~�A�����x��XYZ�������S������
	write_spi(USER_CTRL, 16);			//I2C��Disable�ASPI��Enable
	write_spi(SIGNAL_PATH_RESET, 0x06);	//�W���C���A�����x���Z�b�g
	write_spi(DATA_CONFIG, 0x01);		//�t�B���^�[�͂����Ȃ�
	write_spi(GYRO_CONFIG, 0x18);		//�W���C�����}2000��/s�ɐݒ�
	write_spi(ACCEL_CONFIG, 0x08);		//�����x���}4g/s�ɐݒ�

	//�m�F�p
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

const float accelmeter::ACCEL_PERIOD = CONTORL_PERIOD;		//�����x�v�̐������[s]
const float accelmeter::REF_TIME = 1;			//�����x�v�̃��t�@�����X�Ƃ鎞��[s]
#if (MOUSE_NAME == KOIZUMI_FISH)
const uint8_t accelmeter::AVERAGE_COUNT = 10;			//�����x�v�̕��ω�[��]
#elif (MOUSE_NAME == KOIZUMI_OVER)
const uint8_t accelmeter::AVERAGE_COUNT = 10;			//�����x�v�̕��ω�[��]
#endif	/* MOUSE_NAME */
float accelmeter::accel_ad[AXIS_t::dim_num] = { 0 },
		accelmeter::accel_ref[AXIS_t::dim_num] = { 0 };
float accelmeter::accel[AXIS_t::dim_num] = { 0 };

void accelmeter::interrupt() {
	static float buff[AXIS_t::dim_num][AVERAGE_COUNT] = { 0 };	//�f�[�^��ۑ����Ă����z��
	float sum[AXIS_t::dim_num] = { 0 };

	for (int i = 0; (i + 1) < AVERAGE_COUNT; i++) {
		for (int j = 0; j < AXIS_t::dim_num; j++) {
			buff[j][i] = buff[j][i + 1];	//�z���1���炷
			sum[j] += buff[j][i];			//���łɉ��Z����
		}
	}

	//FIXME �ړ����ςɂȂ��ĂȂ��I
	//�z��̍Ō�ɓ����
	buff[AXIS_t::axis_x][(AVERAGE_COUNT - 1)] =
			static_cast<float>(mpu6000::get_mpu_val(sen_accel, axis_x));//�����x��x����
	buff[AXIS_t::axis_y][(AVERAGE_COUNT - 1)] =
			static_cast<float>(mpu6000::get_mpu_val(sen_accel, axis_y));//�����x��y����
	buff[AXIS_t::axis_z][(AVERAGE_COUNT - 1)] =
			static_cast<float>(mpu6000::get_mpu_val(sen_accel, axis_z));//�����x��z����

	for (int j = 0; j < AXIS_t::dim_num; j++) {
		sum[j] += buff[j][(AVERAGE_COUNT - 1)];		//sum�ɍŐV�̒l�𑫂�
		accel_ad[j] = sum[j] / AVERAGE_COUNT;		//���ς��Ƃ��ĉ����x�̒l�Ƃ���
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
		accel[j] = (accel_ad[j] - accel_ref[j]) / ACCEL_SENSITIVITY * 9.8;//�����x[g]��[m/ss]�ɒ������ߏd�͉����x��������
}
#if (MOUSE_NAME == KOIZUMI_FISH)
float accelmeter::get_accel() {
	return accel[axis_y];		//�i�s�����̉����x
}

#elif (MOUSE_NAME == KOIZUMI_OVER)
float accelmeter::get_accel() {
	return accel[axis_x];		//�i�s�����̉����x
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
const float gyro::GYRO_PERIOD = CONTORL_PERIOD;		//�������[s]
const float gyro::REF_TIME = 2;							//���t�@�����X�Ƃ鎞��[s]

void gyro::interrupt() {
	gyro_value = -mpu6000::get_mpu_val(sen_gyro, axis_z);	//Z�����̃W���C��������B���v��萳
	gyro::cal_angular_velocity();	//gyro����p���x���v�Z[rad/s]
	gyro::cal_angle();				//gyro����p�x���v�Z

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
 //x,y�Ƃ���Wiki�̍ŏ����@�Ɠ����Bx�͎���[ms],y�͊p�x[��]
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

 //1ms�o�܂őҋ@
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

	/*	�W���C���̕␳�ɍŏ����@�͎g���ĂȂ�
	 set_least_square_slope();	//�ŏ����@�ɂ��␳�����o
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
	//XXX�ŏ����@�ł̕␳�͂��ĂȂ�
	//�ŏ����@�ŕ␳����
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

//encoder�֘A
const uint8_t encoder::MOVING_AVERAGE = 30;
const uint32_t encoder::MEDIAN = 32762;
float encoder::left_velocity, encoder::right_velocity, encoder::velocity;
int16_t encoder::raw_count[2] = { 0 };
int16_t encoder::raw_cnt_watch[2] = { 0 };
float encoder::correct[2][ ENC_RES + 1 ] = { 0 };
bool encoder::correct_flag[2] = { false, false };
uint32_t encoder::init_time[2] = { 0 };
bool encoder::isCorrect[2] = { false, false };		//Y.I.���␳���s���Ă��邩�ǂ����̃t���O

#if (MOUSE_NAME == KOIZUMI_FISH)
void encoder::interrupt() {
	static float data_r[MOVING_AVERAGE] = { 0 };	//�f�[�^��ۑ����Ă����z��
	static unsigned int index_r=0;
	float sum_r = 0;
	static float data_l[MOVING_AVERAGE] = { 0 };	//�f�[�^��ۑ����Ă����z��
	static unsigned int index_l=0;
	float sum_l = 0;
	float delta_value_r, delta_value_l;

	for (uint8_t i = 0; (i + 1) < MOVING_AVERAGE; i++) {
		data_r[i] = data_r[i + 1];	//�z���1���炷
		sum_r += data_r[i];			//���łɉ��Z����
		data_l[i] = data_l[i + 1];	//�z���1���炷
		sum_l += data_l[i];			//���łɉ��Z����
	}

	//�G���R�[�_�\�̒l���擾
	delta_value_r = 32762 - static_cast<float>(ENC_TIM.at(enc_right)->CNT);
	ENC_TIM.at(enc_right)->CNT = 32762;
	delta_value_l = static_cast<float>(ENC_TIM.at(enc_left)->CNT) - 32762;
	ENC_TIM.at(enc_left)->CNT = 32762;

	//FIX_ME
	mouse::debag_val_enc_r = delta_value_r;
	mouse::debag_val_enc_l = delta_value_l;

	//Y.I.���␳�e�[�u�����������Ă�����AY.I.���␳������.���ĂȂ�������ړ����ς��Ƃ�
	if (isCorrect[enc_right]){
		//�␳�����������g���đ��x���Ƃ�
		right_velocity = raw_to_correct(enc_right, delta_value_r)
				* ENCODER_CONST / CONTROL_PERIOD * tire_R;//count*[rad/count]/[sec]*[m]
	}else {
		/* �ړ����ς��Ƃ� */
		//�z��̍ŌÂ̓z�����o���isum��������j�A�ŐV�̒l�ōX�V�isum�ɉ��Z�j
		sum_r -= data_r[index_r];
		data_r[index_r] = delta_value_r * ENCODER_CONST
				/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
		sum_r += data_r[index_r];
		// �����OQ�݂����ɂ���B�@MAX�܂ł�������0�ɖ߂�
		if( index_r >= (MOVING_AVERAGE-1) ){
			index_r = 0;
		}else{
			index_r++;
		}
		right_velocity = sum_r / MOVING_AVERAGE;
	}
	if (isCorrect[enc_left])
		//�␳�����������g���đ��x���Ƃ�
		left_velocity = raw_to_correct(enc_left, delta_value_l) * ENCODER_CONST
				/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
	else {
		/* �ړ����ς��Ƃ� */
		//�z��̍ŌÂ̓z�����o���isum��������j�A�ŐV�̒l�ōX�V�isum�ɉ��Z�j
		sum_l -= data_l[index_l];
		data_l[index_l] = delta_value_l * ENCODER_CONST
						/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
		sum_l += data_l[index_l];
		// �����OQ�݂����ɂ���B�@MAX�܂ł�������0�ɖ߂�
		if( index_l >= (MOVING_AVERAGE-1) ){
			index_l = 0;
		}else{
			index_l++;
		}
		//�z��̍Ō�ɓ����
		left_velocity = sum_l / MOVING_AVERAGE;
	}

	velocity = (right_velocity + left_velocity) / 2;

	//�␳�p�Ƀf�[�^��ۑ�
	if (correct_flag[enc_right]) {
		raw_count[enc_right] += static_cast<int16_t>(delta_value_r);//���]�ő����Ă���������
		if (raw_count[enc_right] < 0)
			raw_count[enc_right] += ENC_RES;
		else if (raw_count[enc_right] > ENC_RES) {
			raw_count[enc_right] -= ENC_RES;
			correct_flag[enc_right] = false;	//�␳�e�[�u���쐬����
			isCorrect[enc_right] = true;		//�␳�t���O�����Ă�
			//�i�����ɂ͕␳�e�[�u���͂܂��ł��Ă��Ȃ����쐬�r���ł̓G���R�[�_�[�̒l���Q�Ƃ��Ȃ��̂ł��̎��_�Ō��Ă�j
		} else {
			//�I�[�o�[�t���[���Ȃ��Ƃ��͕ۑ����Ă���
			correct[enc_right][raw_count[enc_right]] =
					static_cast<float>(wait::get_count() - init_time[enc_right]);//���Ԃ�ۑ�
		}
	}
	if (correct_flag[enc_left]) {
		raw_count[enc_left] += static_cast<int16_t>(delta_value_l);	//���]�ő����Ă���������
		if (raw_count[enc_left] < 0)
			raw_count[enc_left] += ENC_RES;
		else if (raw_count[enc_left] > ENC_RES) {
			raw_count[enc_left] -= ENC_RES;
			correct_flag[enc_left] = false;
			isCorrect[enc_left] = true;		//�␳�������t���O�����Ă�
			//�i�����ɂ͕␳�e�[�u���͂܂��ł��Ă��Ȃ����쐬�r���ł̓G���R�[�_�[�̒l���Q�Ƃ��Ȃ��̂ł��̎��_�Ō��Ă�j
		} else {
			//�I�[�o�[�t���[���Ȃ��Ƃ��͕ۑ����Ă���
			correct[enc_left][raw_count[enc_left]] =
					static_cast<float>(wait::get_count() - init_time[enc_left]);//���Ԃ�ۑ�
		}
	}

}
#elif (MOUSE_NAME == KOIZUMI_OVER)
void encoder::interrupt() {
	static float data_r[MOVING_AVERAGE] = { 0 };	//�f�[�^��ۑ����Ă����z��
	static unsigned int index_r=0;
	static float sum_r = 0;
	static float data_l[MOVING_AVERAGE] = { 0 };	//�f�[�^��ۑ����Ă����z��
	static unsigned int index_l=0;
	static float sum_l = 0;
	float delta_value_r, delta_value_l;

//	//�G���R�[�_�\�̒l���擾
	delta_value_r = 32762 - static_cast<float>(ENC_TIM.at(enc_right)->CNT);
	ENC_TIM.at(enc_right)->CNT = 32762;
	raw_cnt_watch[enc_right] = delta_value_r;

	//Y.I.���␳�e�[�u�����������Ă�����AY.I.���␳������.���ĂȂ�������ړ����ς��Ƃ�
	if (isCorrect[enc_right]){
		//�␳�����������g���đ��x���Ƃ�
		right_velocity = raw_to_correct(enc_right, delta_value_r)
				* ENCODER_CONST / CONTROL_PERIOD * tire_R;//count*[rad/count]/[sec]*[m]
	}else {
		right_velocity = delta_value_r * ENCODER_CONST
				/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
	}
	/* �ړ����ς��Ƃ� */
	//�z��̍ŌÂ̓z�����o���isum��������j�A�ŐV�̒l�ōX�V�isum�ɉ��Z�j
	sum_r -= data_r[index_r];
	data_r[index_r] = right_velocity;
	sum_r += data_r[index_r];
	// �����OQ�݂����ɂ���B�@MAX�܂ł�������0�ɖ߂�
	if( index_r >= (MOVING_AVERAGE-1) ){
		index_r = 0;
	}else{
		index_r++;
	}
	right_velocity = sum_r / MOVING_AVERAGE;


	delta_value_l = 32762 - static_cast<float>(ENC_TIM.at(enc_left)->CNT);
	ENC_TIM.at(enc_left)->CNT = 32762;
	raw_cnt_watch[enc_left] = delta_value_l;

	if (isCorrect[enc_left])
		//�␳�����������g���đ��x���Ƃ�
		left_velocity = raw_to_correct(enc_left, delta_value_l) * ENCODER_CONST
				/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
	else {
		left_velocity = delta_value_l * ENCODER_CONST
						/ CONTROL_PERIOD * tire_R;		//count*[rad/count]/[sec]*[m]
	}
	/* �ړ����ς��Ƃ� */
	//�z��̍ŌÂ̓z�����o���isum��������j�A�ŐV�̒l�ōX�V�isum�ɉ��Z�j
	sum_l -= data_l[index_l];
	data_l[index_l] = left_velocity;		//count*[rad/count]/[sec]*[m]
	sum_l += data_l[index_l];
	// �����OQ�݂����ɂ���B�@MAX�܂ł�������0�ɖ߂�
	if( index_l >= (MOVING_AVERAGE-1) ){
		index_l = 0;
	}else{
		index_l++;
	}
	left_velocity = sum_l / MOVING_AVERAGE;

	velocity = (right_velocity + left_velocity) / 2;

	//�␳�p�Ƀf�[�^��ۑ�
	if (correct_flag[enc_right]) {
		raw_count[enc_right] += static_cast<int16_t>(delta_value_r);//���]�ő����Ă���������
		if (raw_count[enc_right] < 0)
			raw_count[enc_right] += ENC_RES;
		else if (raw_count[enc_right] > ENC_RES) {
			raw_count[enc_right] -= ENC_RES;
			correct_flag[enc_right] = false;	//�␳�e�[�u���쐬����
			isCorrect[enc_right] = true;		//�␳�t���O�����Ă�
			//�i�����ɂ͕␳�e�[�u���͂܂��ł��Ă��Ȃ����쐬�r���ł̓G���R�[�_�[�̒l���Q�Ƃ��Ȃ��̂ł��̎��_�Ō��Ă�j
		} else {
			//�I�[�o�[�t���[���Ȃ��Ƃ��͕ۑ����Ă���
			correct[enc_right][raw_count[enc_right]] =
					static_cast<float>(wait::get_count() - init_time[enc_right]);//���Ԃ�ۑ�
		}
	}
	if (correct_flag[enc_left]) {
		raw_count[enc_left] += static_cast<int16_t>(delta_value_l);	//���]�ő����Ă���������
		if (raw_count[enc_left] < 0)
			raw_count[enc_left] += ENC_RES;
		else if (raw_count[enc_left] > ENC_RES) {
			raw_count[enc_left] -= ENC_RES;
			correct_flag[enc_left] = false;
			isCorrect[enc_left] = true;		//�␳�������t���O�����Ă�
			//�i�����ɂ͕␳�e�[�u���͂܂��ł��Ă��Ȃ����쐬�r���ł̓G���R�[�_�[�̒l���Q�Ƃ��Ȃ��̂ł��̎��_�Ō��Ă�j
		} else {
			//�I�[�o�[�t���[���Ȃ��Ƃ��͕ۑ����Ă���
			correct[enc_left][raw_count[enc_left]] =
					static_cast<float>(wait::get_count() - init_time[enc_left]);//���Ԃ�ۑ�
		}
	}

}
#endif	/* MOUSE_NAME */



float encoder::get_velocity() {
	return velocity;

	//���䂳������@http://matsui-mouse.blogspot.jp/2014/03/blog-post_26.html
	//�J���}���t�B���^�ŉ����x�ƃZ���T�t���[�W�������Ă邩��R�����Ȃ��ł����C������
	/*
	 return (velocity
	 + accelmeter::get_accel(axis_y) * accelmeter::AVERAGE_COUNT
	 * accelmeter::ACCEL_PERIOD / 2);
	 */
}

float encoder::raw_to_correct(ENC_SIDE enc_side, int16_t raw_delta) {
	float temp_delta = 0;						//�G���R�[�_�[�̑O��Ƃ̍������Ƃ�
	static float correct_cnt[2] = { 0 };		//�␳��̒l���L�^

	raw_count[enc_side] += raw_delta;
	if (raw_count[enc_side] > ENC_RES) {
		raw_count[enc_side] -= ENC_RES;
		temp_delta += ENC_RES;	//������̃I�[�o�[�t���[�����̂ō����l����ɕ␳���Ă���
	} else if (raw_count[enc_side] < 0) {
		raw_count[enc_side] += ENC_RES;
		temp_delta -= ENC_RES;	//�������̃I�[�o�[�t���[�����̂ō����l����ɕ␳���Ă���
	}
	temp_delta += ( correct[ enc_side ][ raw_count[enc_side] ] - correct_cnt[enc_side] );	//YI���␳�e�[�u���ŕ␳���A�O��Ƃ̍������Ƃ�
	correct_cnt[enc_side] = correct[enc_side][raw_count[enc_side]];	//�l���X�V
	//�␳�����1ms�����G���R�[�_�[�̍��������߂鎮�������l�̖��Ńo�O��B����Ȃ����ɂ̓G���R�[�_�[�Q�Ƃ��Ȃ��̂Ŗ��Ȃ��͂�

	return temp_delta;	//���x�����߂邽�߂ɕ␳�����������g��
}

volatile void encoder::yi_correct(ENC_SIDE enc_side) {
	mouse::run_init(false, false);
	if (enc_side == enc_right)
		motor::set_duty(MOTOR_SIDE::m_right, 40);
	else
		motor::set_duty(MOTOR_SIDE::m_left, 50);

	//�␳�e�[�u����S����
	isCorrect[enc_side] = false;	//Y.I.���␳�͒��~
	for (int i = 0; i <= ENC_RES; i++) {
		correct[enc_side][i] = -1;
	}

	wait::ms(3000);	//��]�����t��ԂɒB����܂őҋ@

	correct_flag[enc_side] = true;
	//�����l���
	raw_count[enc_side] = 0;
	correct[enc_side][0] = 0;
	init_time[enc_side] = wait::get_count();
	while (correct_flag[enc_side])
		;	//���������
	int16_t finish_val = raw_count[enc_side];	//ENC_RES�����������ďI������̂ŁA0��菭���傫���l�̂͂�
	float finish_time = static_cast<float>(wait::get_count()
			- init_time[enc_side]);	//�I���������Ԃ�ۑ�

	motor::sleep_motor();

	//�ƂтƂтŒl���ۑ�����Ă���͂��Ȃ̂ŁA�⊮����
	int16_t bigger_val = 0;		//���n�⊮����Ƃ��́A�傫���ق��̃G���R�[�_�\�̐��l
	float bigger_time = 0;		//���n�⊮����Ƃ��́A�傫���ق��̎���
	if (correct[enc_side][ENC_RES] == -1) {	//�҂�����ENC_RES�ŏI����ĂȂ�������
		bigger_val = ENC_RES + finish_val;
		bigger_time = finish_time;
	} else {								//�҂�����I����Ă���΁A�Ō�̒l�����̂܂ܓ����
		bigger_val = ENC_RES;
		bigger_time = correct[enc_side][ENC_RES];
	}
	for (int i = ENC_RES; i >= 0; i--) {	//�����肩��l�������Ă��Ȃ��Ƃ����T���Ă���
		if (correct[enc_side][i] != -1) {		//�l�������Ă�����
			if (bigger_val - i <= 1) {
			}
			//�l�������Ă���̂��A���Ȃ���n�⊮�͂��Ȃ�(ENC_RES�ɒl�������Ă���ꍇ�̂��߂ɕs����)
			else {
				//�Ԃ̂�����`�⊮����
				float a = (bigger_time - correct[enc_side][i])
						/ static_cast<float>(bigger_val - i);	//�X��
				for (int j = MIN(bigger_val - 1, ENC_RES); j > i; j--) {//bigger_val ~ i �܂ł̊Ԃ���n�⊮
					correct[enc_side][j] = static_cast<float>(a * (j - i)
							+ correct[enc_side][i]);	//�X���~���ݒl�{�ؕЁ@�Ő��`�⊮
				}
			}
			//bigger ���X�V���Ď���
			bigger_val = i;
			bigger_time = correct[enc_side][i];
		}
	}

	//�����܂ł�correct�ɘA���Œl���������͂�.�Ȃ̂Ŏ���correct���ucorrect[���l]=�v�����ԁv����ucorrect[���l]=�␳�l�v�ɒ����Ă���
	float slope = ENC_RES / correct[enc_side][ENC_RES];//���l/���Ԃ̌X���B�ϑ��ʂ͋Ȑ������^�̒l�͒����̂͂��Ȃ̂ł���ŕ␳�l�����߂�
	//�S�Ď��Ԃ���␳�l�ɕϊ�
	for (int i = 0; i <=ENC_RES; i++)
		correct[enc_side][i] *= slope;

}

void encoder::yi_correct() {
	control::ignore_failsafe(true);		//�␳���̓t�F�C���Z�[�t��؂�

#if (MOUSE_NAME == KOIZUMI_FISH)
	//���E�ŕ␳���s��
	yi_correct(enc_right);
	yi_correct(enc_left);
#elif (MOUSE_NAME == KOIZUMI_OVER)
	// ���̓G���R�[�_���ĂȂ�
//	yi_correct(enc_right);
	yi_correct(enc_left);
#endif	/* MOUSE_NAME */

	control::reset_delta(sen_encoder);

	control::ignore_failsafe(false);		//�t�F�C���Z�[�t�𕜊�
}

void encoder::draw_correct(bool right, bool left) {
	if (!right)
		if (!left)
			return;
	for (int i = 0; i <=ENC_RES; i++) {
		myprintf("%d", i);
		if ( right == true )
			myprintf(", %f", correct[enc_right][i]);
		if ( left == true )
			myprintf(", %f", correct[enc_left][i]);
		myprintf("\n\r");
	}
}

void encoder::init(){
//�N���b�N����

	RCC_AHB1PeriphClockCmd(ENC_GPIO_AHB1Periph, ENABLE);
	RCC_APB1PeriphClockCmd(ENC_TIM_AHB1Periph, ENABLE);

	//Remap
	for(uint32_t i=0; i<ENC_GPIO_N; i++ ){
		GPIO_PinAFConfig(ENC_GPIO.at(i), ENC_GPIO_PIN_SOURCE.at(i), ENC_GPIO_AF.at(i));
	}

	//�[�q���ʑ��W���悤�ɐݒ�
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

	//TIM�̐ݒ�
	for(uint32_t i=0; i < ENC_N; i++){
		TIM_ARRPreloadConfig(ENC_TIM.at(i), ENABLE);
	}

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = 65535;		//�J�E���^�N���A�v��
	TIM_TimeBaseStructure.TIM_Prescaler = 0;//����(�J�E���^��Prescaler��J�E���g���ꂽ�^�C�~���O�ŁCTIM�̃J�E���^��1���Z�����)
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	//�f�b�g�^�C��������H�p�̕����B�ʏ�0(�������Ȃ�)�B
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	//�A�b�v�J�E���g
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	for(uint32_t i=0; i < ENC_N; i++){
		TIM_TimeBaseInit(ENC_TIM.at(i), &TIM_TimeBaseStructure);
		//�G���R�[�_�\�ɂ��Đݒ�
		TIM_EncoderInterfaceConfig(ENC_TIM.at(i), TIM_EncoderMode_TI12,
			TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//CH1��CH2�̗����̃G�b�W�ŃJ�E���g�ACH1��CH2�������オ���ǂ�
		TIM_Cmd(ENC_TIM.at(i), ENABLE);		//�^�C�}�N��
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
		{ -0.02, 0.02, 0, 0, 0 };	//���̒l���z������ǃL��
const std::array<float, static_cast<unsigned int>(PHOTO_TYPE::element_count)> photo::wall_edge_up =
		{ -0.02, 0.02, 0, 0, 0 };	//���̒l���z������ǃL��
const std::array<float, static_cast<unsigned int>(PHOTO_TYPE::element_count)> photo::edge_distance =
		{ 0.010, 0.007, 0, 0, 0 };	//�ǃL�������m���������@��撆�S��0�Ƃ��Ă�������ǂꂾ���i��ł��邩

void photo::led_init(){
	GPIO_InitTypeDef GPIO_InitStructure;	//�����ݒ�̂��߂̍\���̂�錾

	RCC_AHB1PeriphClockCmd(LED_RCC_AHB1Periph, ENABLE);	//�N���b�N����

	GPIO_StructInit(&GPIO_InitStructure);	//�\���̂�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//�N���b�N
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;		//�o�͂ɐݒ�
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//�I�[�v���h���C��or�v�b�V���v��
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	//�v���A�b�v���v���_�E����

	//photo_type�̏��ԁ@right,  left, front_right, front_left, front
	for(int i=0; i<PHOTO_N; i++){
		GPIO_InitStructure.GPIO_Pin = LED_GPIO_PIN.at(i);
		GPIO_Init(LED_GPIO.at(i), &GPIO_InitStructure);	//�ݒ�
	}
	for(int i=0; i<PHOTO_N; i++){
		GPIO_ResetBits(LED_GPIO.at(i), LED_GPIO_PIN.at(i));	//�����l��O������
	}

}

void photo::sen_init(){
//GPIO���ŃA�i���O���[�h�ɐݒ�
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(SEN_RCC_AHB1Periph, ENABLE);
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	for(int i=0; i<PHOTO_N; i++){		//photo_type�̏��ԁ@right,  left, front_right, front_left, front
		GPIO_InitStructure.GPIO_Pin = SEN_GPIO_PIN.at(i);
		GPIO_Init(SEN_GPIO.at(i), &GPIO_InitStructure);	//�ݒ�
	}


//AD�ϊ��̐ݒ�
	ADC_InitTypeDef ADC_InitStructure;		//�����ݒ�p�̍\���̒�`
	ADC_CommonInitTypeDef ADC_CommonInitStructure;

	ADC_Cmd(SEN_ADC_CMD, DISABLE);		//ADC1��Disable��
	RCC_APB2PeriphClockCmd(SEN_RCC_APB2Periph_ADC, ENABLE);		//�N���b�N����
	ADC_DeInit();		//ADC�̎��Ӄ��W�X�^���f�t�H���g�̒l�Ƀ��Z�b�g����

	//AD�ϊ��̊�{�ݒ�
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;	//PCLK/4 = 16/4 MHz?
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;	//DMA�͎g�p���Ȃ�
	ADC_CommonInitStructure.ADC_TwoSamplingDelay =
	ADC_TwoSamplingDelay_20Cycles;//�A���X�L�����Ƃ��Ŏg�p�H�@ADC_delay_between_2_sampling_phases
	ADC_CommonInit(&ADC_CommonInitStructure);

	//ADC1�̐ݒ�
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;		//12bit��AD�ϊ�
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;		//�V���O�����[�h�œ���
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;		//�V���O�����[�h�œ���
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;	//AD�ϊ��̊J�n�ɊO���g���K�͎g�p���Ȃ�
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//�E�l�ߍ��l��
	ADC_InitStructure.ADC_NbrOfConversion = 9;		//AD�ϊ��̓��͂�9�`�����l��

	for(int i=0; i<PHOTO_N; i++){		//photo_type�̏��ԁ@right,  left, front_right, front_left, front
		ADC_Init(SEN_ADC.at(i), &ADC_InitStructure);		//front
	}

	ADC_Cmd(SEN_ADC_CMD, ENABLE);		//ADC1��Enable��
	ADC_DMACmd(SEN_ADC_CMD, DISABLE);	//DMA�͎g��Ȃ�
}


void photo::switch_led(PHOTO_TYPE sensor_type, bool is_light) {
	uint32_t i = CAST_UI(sensor_type);		//���삷����̂����Ԗڂ��iPHOTO_TYPE��enum�Łj���Ǘ�
	//���点��
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
	uint32_t i = CAST_UI(sensor_type);		//���삷����̂����Ԗڂ��iPHOTO_TYPE��enum�Łj���Ǘ�

	//ad�ϊ�
	ADC_ClearFlag(SEN_ADC.at(i), ADC_FLAG_EOC);		//EndFlag���N���A����
	ADC_RegularChannelConfig(SEN_ADC.at(i), SEN_ADC_CH.at(i), 1,
			ADC_SampleTime_3Cycles);		//ADCx��ADC_CH��
	ADC_SoftwareStartConv(SEN_ADC.at(i));	//ADC���J�n
	while (ADC_GetFlagStatus(SEN_ADC.at(i), ADC_FLAG_EOC) == RESET)
		;		//�I���܂ő҂�

	return (ADC_GetConversionValue(SEN_ADC.at(i)) >> 4);	//�l���擾�@4�r�b�g�V�t�g�ł��܂������Ă�C������@�E�l�߂̂͂��Ȃ̂ɈӖ��킩���B

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
		if ((i + 1) < PHOTO_AVERAGE_TIME) {		//�z��̗v�f�O�ɃA�N�Z�X���Ȃ��悤��
			buf[sen_type][i] = buf[sen_type][i + 1];	//�z���1���炷
			sum += buf[sen_type][i];			//���łɉ��Z����
		}
		if ((i + 1) < GAP_AVE_COUNT) {		//�z��̗v�f�O�ɃA�N�Z�X���Ȃ��悤��
			ave_buf[sen_type][i] = ave_buf[sen_type][i + 1];	//�z���1���炷
			//diff_buf[sensor_type][i] = diff_buf[sensor_type][i + 1];//�z���1���炷
			//gap_buf[sensor_type][i] = gap_buf[sensor_type][i + 1];	//�z���1���炷
			ave_sum += ave_buf[sen_type][i];			//���łɉ��Z����
		}
	}

	//�z��̍Ō�ɓ����
	buf[sen_type][(PHOTO_AVERAGE_TIME - 1)] = set_value;//count*[rad/count]/[sec]*[m]
	sum += set_value;

	int16_t now_val = sum / PHOTO_AVERAGE_TIME; 	//���₷���̂��ߖ��O��t����
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
	 //�ړ����ς��Ƃ����Z���T�l�ƁA����̂���ɕ��ς��Ƃ������̂Ƃ̍������L�^
	 //���̒l�͕��ς�2����̂ŁA���ϋ�Ԃ̐^�񒆂����肪��������遁�����O�̐^�l�̂悤�Ȃ��̂ƍl���邱�Ƃ��ł���
	 //���̍����Ȃ̂ŁA�����悻�m�C�Y�̉e�������������X����������ƐM���Ă�
	 diff_buf[sensor_type][(GAP_AVE_COUNT - 1)] = ave_sum / GAP_AVE_COUNT
	 - static_cast<float>(now_val);
	 gap_buf[sensor_type][(GAP_AVE_COUNT - 1)] = count_wall_gap(sensor_type);//�g���ĂȂ�
	 */
}

void photo::interrupt(bool is_light) {
	const static int wait_number = 1000;	//1000�ł�������100us��	1500��120us���炢
	photo::turn_off_all();

	photo::set_ref(PHOTO_TYPE::right, get_ad(PHOTO_TYPE::right));//�����Ă鎞��ref�ɂ���
	photo::set_ref(PHOTO_TYPE::left, get_ad(PHOTO_TYPE::left));	//�����Ă鎞��ref�ɂ���
	photo::set_ref(PHOTO_TYPE::front_right, get_ad(PHOTO_TYPE::front_right));//�����Ă鎞��ref�ɂ���
	photo::set_ref(PHOTO_TYPE::front_left, get_ad(PHOTO_TYPE::front_left));	//�����Ă鎞��ref�ɂ���
	photo::set_ref(PHOTO_TYPE::front, get_ad(PHOTO_TYPE::front));//�����Ă鎞��ref�ɂ���

	// ���E�̔����͉�H�I�ɓ����ɂ�����̂ŁA�����ɍ��E�̒l���Ƃ�@��Z
	if (is_light) {
		photo::light(PHOTO_TYPE::right);
		photo::light(PHOTO_TYPE::left);
		for (volatile int i = 0; i < wait_number * 2; i++) {
		}
	}
	photo::set_ad(PHOTO_TYPE::right,
			static_cast<float>(get_ad(PHOTO_TYPE::right) - get_ref(PHOTO_TYPE::right)));	//��������
	photo::set_ad(PHOTO_TYPE::left,
			static_cast<float>(get_ad(PHOTO_TYPE::left) - get_ref(PHOTO_TYPE::left)));		//��������
	photo::turn_off(PHOTO_TYPE::right);
	photo::turn_off(PHOTO_TYPE::left);

	// �����炭�Ɨ��ƌ��Ȃ��ėǂ�
	if (is_light) {
		photo::light(PHOTO_TYPE::front_right);
		photo::light(PHOTO_TYPE::front_left);
		photo::light(PHOTO_TYPE::front);
		for (volatile int i = 0; i < wait_number; i++) {
		}
	}
	photo::set_ad(PHOTO_TYPE::front,
			static_cast<float>(get_ad(PHOTO_TYPE::front) - get_ref(PHOTO_TYPE::front)));	//��������
	photo::turn_off(PHOTO_TYPE::front);
	photo::set_ad(PHOTO_TYPE::front_right,
			get_ad(PHOTO_TYPE::front_right) - get_ref(PHOTO_TYPE::front_right));//��������
	photo::turn_off(PHOTO_TYPE::front_right);
	photo::set_ad(PHOTO_TYPE::front_left,
			get_ad(PHOTO_TYPE::front_left) - get_ref(PHOTO_TYPE::front_left));//��������
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
	return static_cast<float>(ad) * 4.0 / get_battery();	//�d���Œl�������Ă���C������̂ŕ␳
}

#if (MOUSE_NAME == KOIZUMI_FISH)
float photo::get_displa_from_center(PHOTO_TYPE type) {
	return get_displa_from_center(type, (photo::get_value(type)));//���݂̃Z���T�l�ɑ΂��ċ��߂�
}

float photo::get_displa_from_center(PHOTO_TYPE sensor_type, float val) {
	static bool reent = false;		//���G���g�����g���S��

	if (reent)		//���s���Ȃ̂ŁA�K���Ȓl�Ԃ��Ĕ�����
		return 0;
	reent = true;
	float a0, a1, a2, alog;	//�����ߎ��̌W��	x^0,x,x^2,log�̌W��
	float f = val;		//�Ώ̂̃Z���T�l
	float f_c = (parameter::get_correct_photo(sensor_type));	//�I�t�Z�b�g
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

	reent = false;	//�I������O�Ƀ��G���g�����g���I�t��
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
		//TODO �ɂ���������A�O�ǌ���͎̂΂߃Z���T����Ȃ��H�H
		//FIXME 3ms���炢�̑�����
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
	if(type == front){	/* �z�����ɂ͑O�Z���T�͑��݂��Ȃ��̂Ŏ΂߃Z���T�̕��ς��g�� */
		ans = get_displa_from_center(type, (photo::get_value(front_right)));
		ans += get_displa_from_center(type, (photo::get_value(front_left)));
		ans /= 2.0;
	}else{
		ans = get_displa_from_center(type, (photo::get_value(type)));//���݂̃Z���T�l�ɑ΂��ċ��߂�
	}
	return ans;
}

float photo::get_displa_from_center(PHOTO_TYPE sensor_type, float val) {
	static bool reent = false;		/* ���G���g�����g���S�� */

	if (reent){		/* ���s���Ȃ̂ŁA�K���Ȓl�Ԃ��Ĕ����� */
		return 0;
	}else{
		reent = true;
	}

	float f = val;		//�Ώ̂̃Z���T�l
	float f_c;
	float ans = 0;

	/* �{�����蓾�Ȃ��l�������ꍇ�͏�������ɒ���t������ */
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
		ans = f/f_c - 1.0;	/* ��撆�S�ł̒l�Ƃ̔䗦�����߂�B�����炭�@f/f_c��0.1~10�̃I�[�_�[ */
		break;

	case PHOTO_TYPE::left:	/* ���̓Z���T�̑召�֌W�Ƌ����̑召�֌W�����΂Ȃ̂Ŕ��] */
		f_c = (parameter::get_correct_photo(sensor_type));
		ans = -f/f_c + 1.0;	/* ��撆�S�ł̒l�Ƃ̔䗦�����߂�B�����炭�@f/f_c��0.1~10�̃I�[�_�[ */
		break;

	case PHOTO_TYPE::front: /* �z�����ɂ͑O�Z���T�͑��݂��Ȃ��̂łȂɂ����Ȃ�*/
		return 0;
		break;

	default:
		return 0;
		break;
	}

	reent = false;	//�I������O�Ƀ��G���g�����g���I�t��
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
	if(type == PHOTO_TYPE::front){		/* �z�����ɂ͑O�Z���T�͑��݂��Ȃ��̂Ŏ΂߃Z���T�ő�p */
		/* �ǂ͖������Ɍ�F����ƂԂ����Ď��ʂ̂ŁA���S���ɓ|���B�ǂ��炩����������΂���B */
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
 int8_t count = 0;	//���i�Z���T�l���������Ă�j�̐��𐔂���
 for (uint8_t i = 0; i < GAP_AVE_COUNT; i++) {
 if (diff_buf[type][i] < 0)
 count--;
 else
 count++;
 }
 return count;
 }

 bool photo::check_wall_gap(PHOTO_TYPE type, float threshold) {
 //�ǂ̐؂�ڂȂ�true
 //�}�ɕǂ����ꂽ���������؂�

 float before_val = get_side_from_center(type, ave_buf[type][0]);
 float now_val = get_side_from_center(type,
 ave_buf[type][GAP_AVE_COUNT - 1]);

 if (ABS(now_val-before_val) > ABS(threshold)) {		//�ǂ̐؂��
 return true;
 }

 return false;

 }
 */
bool photo::check_wall_edge(PHOTO_TYPE _type, bool _over_threshold) {
	//�ǃL�����m��true

	int sen_type = static_cast<int>(_type);
	float sign = -1;		//�������ɒ����邩(-1)�A�ォ�牺�ɒ����邩(+1)
	float thre = wall_edge_up.at(sen_type);	//臒l
	if (_over_threshold) {
		sign = 1;
		thre = wall_edge_down.at(sen_type);	//臒l
	}

	//臒l��ʂ蒴������ǃL��
	photo::get_displa_from_center_debag(_type);
	if ((thre - 0) * sign >= 0) {
		my7seg::light(5);
		mouse::set_relative_go(edge_distance.at(sen_type));		//���W��␳
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

//XXX �e��Q�C��
//control�֘A
#if (MOUSE_NAME == KOIZUMI_FISH)
const PID gyro_gain = { 15, 750, 0.015 };
PID photo_gain = /*{ 100,0,0.003};*/{ 200, 0, 0.005 };
const PID encoder_gain = { 200, 1000, 0 };	//�J���}���t�B���^�ŃG���R�[�_�[�Ɖ����x�Z���T���狁�߂����x�ɑ΂���t�B���^
const PID accel_gain = { 0, 0, 0 };	//{50, 0, 0 };

const float ff_gain_vel = 1.0;	// ���[�^�����]�����邽�߂ɕK�v��FF���̃Q�C��
const float ff_gain_accel = 1.0;	// ���[�^�����������邽�߂ɕK�v��FF���̃Q�C��
const float ff_gain_mu = 0.00035;	// ���C�� ��FF�Q�C��

#elif (MOUSE_NAME == KOIZUMI_OVER)
const PID gyro_gain = { 15, 750, 0.015 };
PID photo_gain = { 200, 0, 0.005 };
const PID encoder_gain = { 450, 400, 0 };	//�J���}���t�B���^�ŃG���R�[�_�[�Ɖ����x�Z���T���狁�߂����x�ɑ΂���t�B���^
const PID accel_gain = { 0, 0, 0 };

const float ff_gain_vel = 1.0;	// ���[�^�����]�����邽�߂ɕK�v��FF���̃Q�C��
const float ff_gain_accel = 3.0;	// ���[�^�����������邽�߂ɕK�v��FF���̃Q�C��
const float ff_gain_mu = 0.00035;	// ���C�� ��FF�Q�C��
#endif /* MOUSE_NAME */

PID control::gyro_delta, control::photo_delta, control::encoder_delta,
		control::accel_delta;
bool control::control_phase = false;
bool control::wall_control_flag = false;
bool control::ignore_fail_safe = false;
//XXX FF�����FB�����邩���Ȃ������߂�ꏊ
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

//XXX �΍����v�Z���Ă�ꏊ
void control::cal_delta() {
	float before_p_delta;

	//�G���R�[�_�[�̃��v�Z
	before_p_delta = encoder_delta.P;	//�ϕ��p
	encoder_delta.P = (mouse::get_ideal_velocity() - mouse::get_velocity());
	encoder_delta.I += (encoder_delta.P * CONTORL_PERIOD);
	encoder_delta.D = (encoder_delta.P - before_p_delta) / CONTORL_PERIOD;

	//�Z���T�[�̃��v�Z

	float photo_right_delta = 0, photo_left_delta = 0;
	before_p_delta = photo_delta.P;
	if (control::get_wall_control_phase()) {
		switch (mouse::get_compas()) {
		//�΂߂���Ȃ���Ή������Ȃ�
		case north:
		case south:
		case west:
		case east:
			if (photo::check_wall(PHOTO_TYPE::right)) {
				photo_right_delta = photo::get_displa_from_center(
						PHOTO_TYPE::right);	//���S����̂���Ă鋗��[m]
			}
			if (photo::check_wall(PHOTO_TYPE::left)) {
				photo_left_delta = photo::get_displa_from_center(
						PHOTO_TYPE::left);	//���S����̂���Ă鋗��[m]
			}

			//�ǂ̐؂�ڂł͂������̂ŏ���
//			if (photo_right_delta == 0)
//				photo_left_delta *= 2;
//			else if (photo_left_delta == 0)
//				photo_right_delta *= 2;

			//photo_correct = (photo_right_delta + photo_left_delta) / 2;		//�Z���T�l���琄�肵���l���J���}���t�B���^�̐���l�Ƃ���
			photo_delta.P = (photo_right_delta + photo_left_delta) / 2;

			static const float half_section = 0.045 * MOUSE_MODE;	//1��Ԃ̔����̒���
			//���ߖT�̓Z���T�l��M�p���Ȃ��B ���̒�������
			if (ABS(mouse::get_relative_go() - 0.01 * MOUSE_MODE)
					< (half_section * 0.2)) {
				photo_delta.P = 0;//mouse::get_relative_side();		//�Z���T��M�p���Ȃ��@= ����l��˂�����ǂ�
			}
			//photo_delta.P = mouse::get_relative_side();

			//�Z���T�̐���l�ŕ␳
			//if(photo_delta.P != 0){
			//	mouse::set_relative_side(photo_delta.P);
			//}

			break;

			//�΂߂Ȃ�
		case north_east:
		case north_west:
		case south_east:
		case south_west:

			photo_delta.P = 0;
			photo_delta.I = 0;			//�v����

			//�Ԃ��肻���Ȏ�����������悤��
			if (photo::get_displa_from_center(PHOTO_TYPE::right) >= 0)
				photo_delta.P = photo::get_displa_from_center(
						PHOTO_TYPE::right);
			if (photo::get_displa_from_center(PHOTO_TYPE::left) <= 0)
				photo_delta.P = photo::get_displa_from_center(PHOTO_TYPE::left);

			photo_delta.P *= 0.8; //�΂߂̐���p�����[�^

			break;

		default:
			mouse::error();		// �����ɗ���͂��Ȃ��̂ŁA�G���[
			myprintf("Error! cal_delta()");
			break;

		}
		//photo_delta.P = mouse::get_relative_side();		//�Z���T��M�p���Ȃ��@= ����l��˂�����ǂ�

		//���x���Ⴂ�Ɛ��䂪����������̂Łi���ΓI�ɐ��䂪�傫���Ȃ�j�A�؂�
		if (mouse::get_ideal_velocity() < SEARCH_VELOCITY * 0.5) {
			photo_delta.P = 0;
		}
		photo_delta.I += (photo_delta.P * CONTORL_PERIOD);
		photo_delta.D = mouse::get_velocity() * mouse::get_relative_rad(); //V�� �I�h���g�����狁�߂�D���@Sin��~�ƂƋߎ�

	} else {
		//�ǐ��䂩���Ȃ��Ƃ��͏�������������B
		photo_delta.P = 0;
		photo_delta.I = 0;
		photo_delta.D = 0;
	}

	float wall_delta = cross_delta_gain(sen_photo);
	//if(wall_delta!=0)
	//	mouse::set_relative_rad(mouse::get_relative_rad()-0.1*wall_delta,true);

	//�W���C���̃��v�Z
	before_p_delta = gyro_delta.P;	//�ϕ��p
	gyro_delta.P = (mouse::get_ideal_angular_velocity()
			- gyro::get_angular_velocity());
	gyro_delta.P -= wall_delta;		//�ǐ���ʂ�ڕW�p���x�ɒǉ�
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
	if (right_or_left == MUKI_RIGHT) {			//�E�̃��[�^�[�Ȃ�
		return (control_velocity() - control_angular_velocity());
	} else {										//���̃��[�^�[�Ȃ�
		return (control_velocity() + control_angular_velocity());

	}
}

float control::get_feedforward(const signed char right_or_left) {
	float velocity;		//�ڕW���x
	float accel;		//�ڕW�����x

	if (right_or_left == MUKI_RIGHT) {			//�E�̃��[�^�[�Ȃ�
		velocity = mouse::get_ideal_velocity()
				- (mouse::get_ideal_angular_velocity() * TREAD_W / 2);
		accel = mouse::get_ideal_accel()
				- (mouse::get_ideal_angular_accel() * TREAD_W / 2);

	} else {									//���̃��[�^�[�Ȃ�
		velocity = mouse::get_ideal_velocity()
				+ (mouse::get_ideal_angular_velocity() * TREAD_W / 2);
		accel = mouse::get_ideal_accel()
				+ (mouse::get_ideal_angular_accel() * TREAD_W / 2);

	}

	float Vinv;		//motor����]���邱�Ƃɂ��t�C�d��
	float Vt;		//motor����]�����邽�߂ɕK�v�ȃg���N�𐶂ݏo�����߂̓d��

	// V = v[m/s]/2��r[m] * �M�A��  / �d������[��/s/V]
	Vinv = (velocity / (2 * PI() * tire_R) * SPAR / PINION / MOTOR_CONST) * ff_gain_vel;

	// V = �����ɕK�v�ȕ�
	Vt = ( (PI() * tire_R * MASS * MOTOR_ORM * MOTOR_CONST) * accel * ff_gain_accel ) * PINION / SPAR;

	// V = ���C�͂�ł�������	���[�^�̉�]�����i���쓮�����j�ɂ�����
	Vt += ( (2 * PI() * MOTOR_ORM * MOTOR_CONST * ff_gain_mu) )	* PINION / SPAR * SIGN(velocity);

	return ((Vinv + Vt) * M_SUM_ORM / MOTOR_ORM / get_battery()) * 100;
}

void control::posture_control() {
	if (get_control_phase()) {			//������|����Ȃ�
		if (is_FF_CONTROL || is_FB_CONTROL) {		//FF��FB�̂ǂ��炩�ł�������|����Ƃ�

			float duty_r = 0, duty_l = 0;		//duty��ۑ�����悤

			if (is_FF_CONTROL) {			//FF������|����Ȃ�
				duty_r = get_feedforward(MUKI_RIGHT);
				duty_l = get_feedforward(MUKI_LEFT);
			}
			if (is_FB_CONTROL) {				//FB������|����Ȃ�
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

	//�t�F�C���Z�[�t�𖳎�����Ȃ牽�����Ȃ�
	if (ignore_fail_safe)
		return;

	//臒l�ǂ̂��炢���킩��Ȃ��BGyro���Q�Ƃ��ׂ��H
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
	float esX = x + EstimateU;		//�O��̒l�ɐ��蕪�������ꂽ�l�𐄒�l�Ƃ���
	float esP = p + EstP;			//�O��̕��U�ɐ��蕪�������U�𑝂₷
	float delta = ObserveZ - esX;	//�ϑ��ʂƐ���l�̍���
	float K = esP / (ObsP + esP);	//�J���}���Q�C��

	x = esX + K * delta;	//�J���}���t�B���^�Ő���l��␳
	p = (1 - K) * esP;		//�␳��̕��U
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
