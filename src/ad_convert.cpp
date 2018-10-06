/*
 * ad_convert.cpp
 *
 *  Created on: 2016/09/17
 *      Author: Koizumi
 */

#include"ad_convert.h"



uint16_t ad_convert_batt() {
	ADC_ClearFlag(BATT_ADCx, ADC_FLAG_EOC);		//EndFlagをクリアする
	ADC_RegularChannelConfig(BATT_ADCx, BATT_ADC_CH, BATT_RANK,
			BATT_ADC_SAMPLE_TIME);		//ADC1_CH9を
	ADC_SoftwareStartConv(BATT_ADCx);	//ADC1を開始
	while (ADC_GetFlagStatus(BATT_ADCx, ADC_FLAG_EOC) == RESET)
		;		//終わるまで待つ
	return (ADC_GetConversionValue(BATT_ADCx) >> 4);	//XXX 値を取得　4ビットシフトでうまくいってる気がする　右詰めのはずなのに意味わからん。

}

float get_battery() {

	float temp_battery = 0;
	static unsigned int ad_accurate = 4096;	//AD変換の精度格納用

	temp_battery = (float) LOGIK_V * ad_convert_batt()
			/ ad_accurate* V_BATT_RATIO;

	return temp_battery;
}

