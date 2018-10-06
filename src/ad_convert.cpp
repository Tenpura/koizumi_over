/*
 * ad_convert.cpp
 *
 *  Created on: 2016/09/17
 *      Author: Koizumi
 */

#include"ad_convert.h"



uint16_t ad_convert_batt() {
	ADC_ClearFlag(BATT_ADCx, ADC_FLAG_EOC);		//EndFlag���N���A����
	ADC_RegularChannelConfig(BATT_ADCx, BATT_ADC_CH, BATT_RANK,
			BATT_ADC_SAMPLE_TIME);		//ADC1_CH9��
	ADC_SoftwareStartConv(BATT_ADCx);	//ADC1���J�n
	while (ADC_GetFlagStatus(BATT_ADCx, ADC_FLAG_EOC) == RESET)
		;		//�I���܂ő҂�
	return (ADC_GetConversionValue(BATT_ADCx) >> 4);	//XXX �l���擾�@4�r�b�g�V�t�g�ł��܂������Ă�C������@�E�l�߂̂͂��Ȃ̂ɈӖ��킩���B

}

float get_battery() {

	float temp_battery = 0;
	static unsigned int ad_accurate = 4096;	//AD�ϊ��̐��x�i�[�p

	temp_battery = (float) LOGIK_V * ad_convert_batt()
			/ ad_accurate* V_BATT_RATIO;

	return temp_battery;
}

