/*
 * Copyright (C) 2012-2015, Focaltech Systems (R),All Rights Reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/************************************************************************
* File Name: DetailThreshold.c
*
* Author: Software Development Team, AE
*
* Created: 2015-07-14
*
* Abstract: Set Detail Threshold for all IC
*
************************************************************************/
#include <linux/kernel.h>
#include <linux/bug.h>
#include <linux/string.h>
#include "ini.h"
#include "DetailThreshold.h"
#include "test_lib.h"
#include "Global.h"
#include "tpd_custom_fts.h"

struct stCfg_MCap_DetailThreshold g_stCfg_MCap_DetailThreshold;
struct stCfg_SCap_DetailThreshold g_stCfg_SCap_DetailThreshold;

void set_max_channel_num(void)
{
	switch (g_ScreenSetParam.iSelectedIC >> 4) {
	case IC_FT5822 >> 4:
		g_ScreenSetParam.iUsedMaxTxNum = TX_NUM_MAX;
		g_ScreenSetParam.iUsedMaxRxNum = RX_NUM_MAX;
		break;
	default:
		g_ScreenSetParam.iUsedMaxTxNum = 30;
		g_ScreenSetParam.iUsedMaxRxNum = 30;
		break;
	}
}

void OnInit_SCap_DetailThreshold(char *strIniFile)
{
	OnGetTestItemParam("RawDataTest_Max", strIniFile, 12500);

	memcpy(g_stCfg_SCap_DetailThreshold.RawDataTest_Max,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	OnGetTestItemParam("RawDataTest_Min", strIniFile, 16500);

	memcpy(g_stCfg_SCap_DetailThreshold.RawDataTest_Min,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	OnGetTestItemParam("CiTest_Max", strIniFile, 5);

	memcpy(g_stCfg_SCap_DetailThreshold.CiTest_Max,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	OnGetTestItemParam("CiTest_Min", strIniFile, 250);

	memcpy(g_stCfg_SCap_DetailThreshold.CiTest_Min,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	OnGetTestItemParam("DeltaCiTest_Base", strIniFile, 0);

	memcpy(g_stCfg_SCap_DetailThreshold.DeltaCiTest_Base,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	OnGetTestItemParam("DeltaCiTest_AnotherBase1", strIniFile, 0);

	memcpy(g_stCfg_SCap_DetailThreshold.DeltaCiTest_AnotherBase1,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	OnGetTestItemParam("DeltaCiTest_AnotherBase2", strIniFile, 0);

	memcpy(g_stCfg_SCap_DetailThreshold.DeltaCiTest_AnotherBase2,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	OnGetTestItemParam("NoiseTest_Max", strIniFile, 20);

	memcpy(g_stCfg_SCap_DetailThreshold.NoiseTest_Max,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));
	/*OnGetTestItemParam("CiDeviation_Base", strIniFile); */
	OnGetTestItemParam("CiDeviation_Base", strIniFile, 0);

	memcpy(g_stCfg_SCap_DetailThreshold.CiDeviationTest_Base,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	OnGetTestItemParam("DeltaCxTest_Sort", strIniFile, 1);

	memcpy(g_stCfg_SCap_DetailThreshold.DeltaCxTest_Sort,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	OnGetTestItemParam("DeltaCxTest_Area", strIniFile, 1);

	memcpy(g_stCfg_SCap_DetailThreshold.DeltaCxTest_Area,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));
	/*6x36 */
	/*OnGetTestItemParam("CbTest_Max", strIniFile); */
	OnGetTestItemParam("CbTest_Max", strIniFile, 0);

	memcpy(g_stCfg_SCap_DetailThreshold.CbTest_Max,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	/*OnGetTestItemParam("CbTest_Min", strIniFile); */
	OnGetTestItemParam("CbTest_Min", strIniFile, 0);

	memcpy(g_stCfg_SCap_DetailThreshold.CbTest_Min,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	/*OnGetTestItemParam("DeltaCbTest_Base", strIniFile); */
	OnGetTestItemParam("DeltaCbTest_Base", strIniFile, 0);

	memcpy(g_stCfg_SCap_DetailThreshold.DeltaCbTest_Base,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	/*OnGetTestItemParam("DifferTest_Base", strIniFile); */
	OnGetTestItemParam("DifferTest_Base", strIniFile, 0);

	memcpy(g_stCfg_SCap_DetailThreshold.DifferTest_Base,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	/*OnGetTestItemParam("CBDeviation_Base", strIniFile); */
	OnGetTestItemParam("CBDeviation_Base", strIniFile, 0);

	memcpy(g_stCfg_SCap_DetailThreshold.CBDeviationTest_Base,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));

	/*OnGetTestItemParam("K1DifferTest_Base", strIniFile); */
	OnGetTestItemParam("K1DifferTest_Base", strIniFile, 0);

	memcpy(g_stCfg_SCap_DetailThreshold.K1DifferTest_Base,
	       g_stCfg_SCap_DetailThreshold.TempData,
	       MAX_CHANNEL_NUM * sizeof(int));
}

void OnGetTestItemParam(char *strItemName, char *strIniFile, int iDefautValue)
{
	char strValue[800];
	char str_tmp[128];
	int iValue = 0;
	int dividerPos = 0;
	int index = 0;
	int i = 0, j = 0, k = 0;

	memset(g_stCfg_SCap_DetailThreshold.TempData, 0,
	       ARRAY_SIZE(g_stCfg_SCap_DetailThreshold.TempData));

	snprintf(str_tmp, ARRAY_SIZE(str_tmp), "%d", iDefautValue);
	GetPrivateProfileString("Basic_Threshold", strItemName, str_tmp,
				strValue, strIniFile);
	iValue = atoi(strValue);

	for (i = 0; i < MAX_CHANNEL_NUM; i++)
		g_stCfg_SCap_DetailThreshold.TempData[i] = iValue;

	dividerPos =
	    GetPrivateProfileString("SpecialSet", strItemName, "", strValue,
				    strIniFile);

	if (dividerPos > 0) {
		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_SCap_DetailThreshold.TempData[k] =
				    (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}

		/*If (k+1) < MAX_CHANNEL_NUM, set Default Vaule to Other
		   for(i = k+1; i < MAX_CHANNEL_NUM; i++) {
		   g_stCfg_SCap_DetailThreshold.TempData[i] = iValue;
		   } */
	}
}

void OnInit_MCap_DetailThreshold(char *strIniFile)
{
	set_max_channel_num();	/*set used TxRx */

	OnInit_InvalidNode(strIniFile);
	OnInit_DThreshold_RawDataTest(strIniFile);
	OnInit_DThreshold_SCapRawDataTest(strIniFile);
	OnInit_DThreshold_SCapCbTest(strIniFile);
	OnInit_DThreshold_PanelDifferTest(strIniFile);
	OnInit_DThreshold_ForceTouch_SCapRawDataTest(strIniFile);
	OnInit_DThreshold_ForceTouch_SCapCbTest(strIniFile);
/* OnInit_DThreshold_RxCrosstalkTest(strIniFile); */
	OnInit_DThreshold_RxLinearityTest(strIniFile);
	OnInit_DThreshold_TxLinearityTest(strIniFile);
/*	OnInit_DThreshold_TxShortTest(strIniFile);
	OnInit_DThreshold_CMTest(strIniFile);
    OnInit_DThreshold_NoiseTest(strIniFile);
*/
	/*5422 SITO_RAWDATA_UNIFORMITY_TEST */
/*OnInit_DThreshold_SITORawdata_RxLinearityTest(strIniFile);
	OnInit_DThreshold_SITORawdata_TxLinearityTest(strIniFile);

	OnInit_DThreshold_SITO_RxLinearityTest(strIniFile);
	OnInit_DThreshold_SITO_TxLinearityTest(strIniFile);

	OnInit_DThreshold_UniformityRxLinearityTest(strIniFile);
	OnInit_DThreshold_UniformityTxLinearityTest(strIniFile);
*/
}

void OnInit_InvalidNode(char *strIniFile)
{
	char str[MAX_KEY_VALUE_LEN] = { 0 }, strTemp[MAX_KEY_VALUE_LEN] = { 0 };
	int i = 0, j = 0;

	/*memset(str , 0x00, ARRAY_SIZE(str));
	   memset(strTemp , 0x00, ARRAY_SIZE(strTemp)); */
	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			snprintf(strTemp, ARRAY_SIZE(strTemp),
				"InvalidNode[%d][%d]", (i + 1), (j + 1));

			GetPrivateProfileString("INVALID_NODE", strTemp, "1",
						str, strIniFile);
			if (atoi(str) == 0) {
				g_stCfg_MCap_DetailThreshold.InvalidNode[i][j] =
				    0;
			} else if (atoi(str) == 2) {
				g_stCfg_MCap_DetailThreshold.InvalidNode[i][j] =
				    2;
			} else
				g_stCfg_MCap_DetailThreshold.InvalidNode[i][j] =
				    1;
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			snprintf(strTemp, ARRAY_SIZE(strTemp),
				"InvalidNodeS[%d][%d]", (i + 1),
				(j + 1));
			GetPrivateProfileString("INVALID_NODES", strTemp, "1",
						str, strIniFile);

			if (atoi(str) == 0) {
				g_stCfg_MCap_DetailThreshold.InvalidNode_SC[i]
				    [j] = 0;
			} else if (atoi(str) == 2) {
				g_stCfg_MCap_DetailThreshold.InvalidNode_SC[i]
				    [j] = 2;
			} else
				g_stCfg_MCap_DetailThreshold.InvalidNode_SC[i]
				    [j] = 1;
		}
	}
}

void OnInit_DThreshold_PanelDifferTest(char *strIniFile)
{
	char str[MAX_KEY_VALUE_LEN], strTemp[MAX_KEY_VALUE_LEN], strValue[MAX_KEY_VALUE_LEN];
	int MaxValue, MinValue;
	int dividerPos = 0;
	char str_tmp[MAX_KEY_VALUE_LEN];
	int index = 0;
	int k = 0, i = 0, j = 0;

	/* RawData Test */
	GetPrivateProfileString("Basic_Threshold", "PanelDifferTest_Max",
				"1000", str, strIniFile);

	MaxValue = atoi(str);

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++)
			g_stCfg_MCap_DetailThreshold.PanelDifferTest_Max[i][j] =
			    MaxValue;
	}

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"Panel_Differ_Max_Tx%d", (i + 1));
		/* printk("%s\n", str); */
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "111", strTemp,
					    strIniFile);

		/*printk("GetPrivateProfileString =
		 *  %d\n", dividerPos); */
		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				PanelDifferTest_Max[i][k] =
				(short)(atoi(str_tmp));
				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;
				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	GetPrivateProfileString("Basic_Threshold", "PanelDifferTest_Min", "150",
				str, strIniFile);

	MinValue = atoi(str);

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++)
			g_stCfg_MCap_DetailThreshold.PanelDifferTest_Min[i][j] =
			    MinValue;
	}

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"Panel_Differ_Min_Tx%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				PanelDifferTest_Min[i][k] =
				(short)(atoi(str_tmp));
				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}
}

void OnInit_DThreshold_RawDataTest(char *strIniFile)
{
	char str[MAX_KEY_VALUE_LEN], strTemp[MAX_KEY_VALUE_LEN], strValue[MAX_KEY_VALUE_LEN];
	int MaxValue, MinValue;
	int dividerPos = 0;
	char str_tmp[MAX_KEY_VALUE_LEN];
	int index = 0;
	int k = 0, i = 0, j = 0;

	/*RawData Test */
	GetPrivateProfileString("Basic_Threshold", "RawDataTest_Max",
				"10000", str, strIniFile);

	MaxValue = atoi(str);
	/*printk("MaxValue = %d\n", MaxValue); */
	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.RawDataTest_Max[i][j] =
			    MaxValue;
		}
	}

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		snprintf(str, ARRAY_SIZE(str), "RawData_Max_Tx%d", (i + 1));
		/*printk("%s\n", str); */
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "111", strTemp,
					    strIniFile);
		/*printk("GetPrivateProfileString =
		 *  %d\n", dividerPos); */
		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.RawDataTest_Max[i]
				    [k] = (short)(atoi(str_tmp));
				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;
				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	GetPrivateProfileString("Basic_Threshold", "RawDataTest_Min", "7000",
				str, strIniFile);

	MinValue = atoi(str);

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.RawDataTest_Min[i][j] =
			    MinValue;
		}
	}

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		snprintf(str, ARRAY_SIZE(str), "RawData_Min_Tx%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.RawDataTest_Min[i]
				    [k] = (short)(atoi(str_tmp));
				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/*RawData Test Low */
	GetPrivateProfileString("Basic_Threshold", "RawDataTest_Low_Max",
				"15000", str, strIniFile);
	MaxValue = atoi(str);

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.RawDataTest_Low_Max[i][j] =
			    MaxValue;
		}
	}

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		snprintf(str, ARRAY_SIZE(str), "RawData_Max_Low_Tx%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);
		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.RawDataTest_Low_Max
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	GetPrivateProfileString("Basic_Threshold", "RawDataTest_Low_Min",
				"3000", str, strIniFile);
	MinValue = atoi(str);

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.RawDataTest_Low_Min[i][j] =
			    MinValue;
		}
	}

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		snprintf(str, ARRAY_SIZE(str), "RawData_Min_Low_Tx%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);
		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.RawDataTest_Low_Min
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/*RawData Test High */
	GetPrivateProfileString("Basic_Threshold", "RawDataTest_High_Max",
				"15000", str, strIniFile);
	MaxValue = atoi(str);
	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.RawDataTest_High_Max[i][j]
			    = MaxValue;
		}
	}

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"RawData_Max_High_Tx%d", (i + 1));

		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);
		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				RawDataTest_High_Max
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	GetPrivateProfileString("Basic_Threshold", "RawDataTest_High_Min",
				"3000", str, strIniFile);

	MinValue = atoi(str);
	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.RawDataTest_High_Min[i][j]
			    = MinValue;
		}
	}

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"RawData_Min_High_Tx%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				RawDataTest_High_Min
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/* TxShortAdvance Test */
/*
	for(i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++)
	{
		for(j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++)
		{
			g_stCfg_MCap_DetailThreshold.TxShortAdvance[i][j] = 0;
		}
	}
	for(i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++)
	{
		snprintf(str, ARRAY_SIZE(str),
			"TxShortAdvanceThreshold_Tx%d", (i + 1));
		dividerPos = GetPrivateProfileString( "SpecialSet",
		* str, "NULL",strTemp, strIniFile);
		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		if(0 == dividerPos) continue;
		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for(j=0; j<dividerPos; j++)
		{
			if(',' == strValue[j])
			{
				g_stCfg_MCap_DetailThreshold.
				* TxShortAdvance[i][k] = (short)(atoi(str_tmp));
				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			}
			else
			{
				if(' ' == strValue[j])
					continue;
				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}*/
}

void OnInit_DThreshold_SCapRawDataTest(char *strIniFile)
{
	char str[MAX_KEY_VALUE_LEN], strTemp[MAX_KEY_VALUE_LEN], strValue[MAX_KEY_VALUE_LEN];
	int MaxValue, MinValue;
	int dividerPos = 0;
	char str_tmp[MAX_KEY_VALUE_LEN];
	int index = 0;
	int k = 0, i = 0, j = 0;

	 /*OFF*/
	    GetPrivateProfileString("Basic_Threshold",
				    "SCapRawDataTest_OFF_Min", "150", str,
				    strIniFile);
	MinValue = atoi(str);

	GetPrivateProfileString("Basic_Threshold", "SCapRawDataTest_OFF_Max",
				"1000", str, strIniFile);
	MaxValue = atoi(str);

	/*Max */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.SCapRawDataTest_OFF_Max[i]
			    [j] = MaxValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ScapRawData_OFF_Max_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				SCapRawDataTest_OFF_Max
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}
	/*Min */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.SCapRawDataTest_OFF_Min[i]
			    [j] = MinValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ScapRawData_OFF_Min_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);
		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				SCapRawDataTest_OFF_Min
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/* Read threshold, without special settings,
	places Basic_Threshold alternative*/
/*
	for(int i = 0; i < 2; i++)
	{
		if(0 == i)iLenght = g_ScreenSetParam.iUsedMaxRxNum;
		if(1 == i)iLenght = g_ScreenSetParam.iUsedMaxTxNum;

		str.Format("ScapRawData_OFF_Max_%d", i + 1);
		GetPrivateProfileString( "SpecialSet", str, "NULL",
		* strTemp.GetBuffer(BUFFER_LENGTH),BUFFER_LENGTH, strIniFile);
		strValue.Format("%s",strTemp);
		dividerPos = strValue.Find(',',0);
		if(dividerPos > 0)
		{
			for(int j = 0; j < iLenght; j++)
			{
				AfxExtractSubString(SingleItem,
				* strValue, j ,  cDivider);
				if(!SingleItem.IsEmpty())
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapRawDataTest_OFF_Max[i][j] =
					* atoi(SingleItem);
				}
				else
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapRawDataTest_OFF_Max[i][j] =
					* iBasicMax;
				}
			}
		}
		else
		{
			for(int j = 0; j < iLenght; j++)
			{
				g_stCfg_MCap_DetailThreshold.
				* SCapRawDataTest_OFF_Max[i][j] = iBasicMax;
			}
		}
	}

	for(int i = 0; i < 2; i++)
	{
		if(0 == i)iLenght = g_ScreenSetParam.iUsedMaxRxNum;
		if(1 == i)iLenght = g_ScreenSetParam.iUsedMaxTxNum;

		str.Format("ScapRawData_OFF_Min_%d", i + 1);
		GetPrivateProfileString( "SpecialSet", str, "NULL",
		* strTemp.GetBuffer(BUFFER_LENGTH),BUFFER_LENGTH, strIniFile);
		strValue.Format("%s",strTemp);
		dividerPos = strValue.Find(',',0);
		if(dividerPos > 0)
		{
			for(int j = 0; j < iLenght; j++)
			{
				AfxExtractSubString(SingleItem,
				* strValue, j ,  cDivider);
				if(!SingleItem.IsEmpty())
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapRawDataTest_OFF_Min[i][j] =
					* atoi(SingleItem);
				}
				else
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapRawDataTest_OFF_Min[i][j] =
					* iBasicMin;
				}
			}
		}
		else
		{
			for(int j = 0; j < iLenght; j++)
			{
				g_stCfg_MCap_DetailThreshold.
				* SCapRawDataTest_OFF_Min[i][j] = iBasicMin;
			}
		}
	}
*/
	 /*ON*/
	    GetPrivateProfileString("Basic_Threshold", "SCapRawDataTest_ON_Min",
				    "150", str, strIniFile);
	MinValue = atoi(str);

	GetPrivateProfileString("Basic_Threshold", "SCapRawDataTest_ON_Max",
				"1000", str, strIniFile);
	MaxValue = atoi(str);

	/* Read threshold, without special settings,
	places Basic_Threshold alternative*/
	/*Max */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
			SCapRawDataTest_ON_Max[i]
			    [j] = MaxValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ScapRawData_ON_Max_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				SCapRawDataTest_ON_Max
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}
	/*Min */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
			SCapRawDataTest_ON_Min[i]
			    [j] = MinValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ScapRawData_ON_Min_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				SCapRawDataTest_ON_Min
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/*
	   for(int i = 0; i < 2; i++) {
		   if(0 == i)iLenght = g_ScreenSetParam.iUsedMaxRxNum;
		   if(1 == i)iLenght = g_ScreenSetParam.iUsedMaxTxNum;

		   str.Format("ScapRawData_ON_Max_%d", i + 1);
		   GetPrivateProfileString( "SpecialSet", str, "NULL",
		   * strTemp.GetBuffer(BUFFER_LENGTH),
		   * BUFFER_LENGTH, strIniFile);
		   strValue.Format("%s",strTemp);
		   dividerPos = strValue.Find(',',0);
		   if(dividerPos > 0) {
				for(int j = 0; j < iLenght; j++) {
				AfxExtractSubString(SingleItem,
				* strValue, j, cDivider);
				   if(!SingleItem.IsEmpty()) {
						g_stCfg_MCap_DetailThreshold.
						* SCapRawDataTest_ON_Max[i][j] =
						* atoi(SingleItem);
				   } else {
						g_stCfg_MCap_DetailThreshold.
						* SCapRawDataTest_ON_Max[i][j] =
						* iBasicMax;
				   }
		   }
		   } else {
			   for(int j = 0; j < iLenght; j++) {
					g_stCfg_MCap_DetailThreshold.
					* SCapRawDataTest_ON_Max[i][j] =
					* iBasicMax;
			   }
		   }
	   }

	   for(int i = 0; i < 2; i++) {
			if(0 == i)iLenght = g_ScreenSetParam.iUsedMaxRxNum;
			if(1 == i)iLenght = g_ScreenSetParam.iUsedMaxTxNum;

			str.Format("ScapRawData_ON_Min_%d", i + 1);
			GetPrivateProfileString( "SpecialSet", str, "NULL",
			* strTemp.GetBuffer(BUFFER_LENGTH),
			* BUFFER_LENGTH, strIniFile);
		   strValue.Format("%s",strTemp);
		   dividerPos = strValue.Find(',',0);
		   if(dividerPos > 0) {
			for(int j = 0; j < iLenght; j++) {
				AfxExtractSubString(SingleItem,
				* strValue, j, cDivider);
				   if(!SingleItem.IsEmpty()) {
					   g_stCfg_MCap_DetailThreshold.
					   * SCapRawDataTest_ON_Min[i][j] =
					   * atoi(SingleItem);
				   } else {
						g_stCfg_MCap_DetailThreshold.
						* SCapRawDataTest_ON_Min[i][j] =
						* iBasicMin;
				   }
			   }
			} else {
			   for(int j = 0; j < iLenght; j++) {
					g_stCfg_MCap_DetailThreshold.
					* SCapRawDataTest_ON_Min[i][j] =
					* iBasicMin;
			   }
		   }
	   }
	 */
}

void OnInit_DThreshold_SCapCbTest(char *strIniFile)
{
	char str[MAX_KEY_VALUE_LEN], strTemp[MAX_KEY_VALUE_LEN], strValue[MAX_KEY_VALUE_LEN];
	int MaxValue, MinValue;
	int dividerPos = 0;
	char str_tmp[MAX_KEY_VALUE_LEN];
	int index = 0;
	int k = 0, i = 0, j = 0;

	GetPrivateProfileString("Basic_Threshold", "SCapCbTest_ON_Min", "0",
				str, strIniFile);
	MinValue = atoi(str);

	GetPrivateProfileString("Basic_Threshold", "SCapCbTest_ON_Max", "240",
				str, strIniFile);
	MaxValue = atoi(str);
	/* Read threshold, without special settings,
	places Basic_Threshold alternative*/

	/*Max */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.SCapCbTest_ON_Max[i][j] =
			    MaxValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str), "ScapCB_ON_Max_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);
		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.SCapCbTest_ON_Max
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/*Min */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.SCapCbTest_ON_Min[i][j] =
			    MinValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str), "ScapCB_ON_Min_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				SCapCbTest_ON_Min
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	GetPrivateProfileString("Basic_Threshold",
	"SCapCbTest_OFF_Min", "0",
				str, strIniFile);

	MinValue = atoi(str);

	GetPrivateProfileString("Basic_Threshold",
	"SCapCbTest_OFF_Max", "240",
				str, strIniFile);

	MaxValue = atoi(str);

	/*Max */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
			SCapCbTest_OFF_Max[i][j] =
			    MaxValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str), "ScapCB_OFF_Max_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				SCapCbTest_OFF_Max
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/*Min */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.SCapCbTest_OFF_Min[i][j] =
			    MinValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str), "ScapCB_OFF_Min_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.SCapCbTest_OFF_Min
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/* Read threshold, without special settings,
	places Basic_Threshold alternative*/
/*
	int iLenght = 0;
	for(int i = 0; i < 2; i++)
	{
		if(0 == i)iLenght = g_ScreenSetParam.iUsedMaxRxNum;
		if(1 == i)iLenght = g_ScreenSetParam.iUsedMaxTxNum;

		str.Format("ScapCB_ON_Max_%d", i + 1);
		GetPrivateProfileString( "SpecialSet", str, "NULL",
		* strTemp.GetBuffer(BUFFER_LENGTH),BUFFER_LENGTH, strIniFile);
		strValue.Format("%s",strTemp);
		dividerPos = strValue.Find(',',0);
		if(dividerPos > 0)
		{
			for(int j = 0; j < iLenght; j++)
			{
				AfxExtractSubString(SingleItem,
				* strValue, j ,  cDivider);
				if(!SingleItem.IsEmpty())
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapCbTest_ON_Max[i][j] =
					* atoi(SingleItem);
				}
				else
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapCbTest_ON_Max[i][j] =
					* iBasicMax_on;
				}
			}
		}
		else
		{
			for(int j = 0; j < iLenght; j++)
			{
				g_stCfg_MCap_DetailThreshold.
				* SCapCbTest_ON_Max[i][j] = iBasicMax_on;
			}
		}
	}

	for(int i = 0; i < 2; i++)
	{
		if(0 == i)iLenght = g_ScreenSetParam.iUsedMaxRxNum;
		if(1 == i)iLenght = g_ScreenSetParam.iUsedMaxTxNum;

		str.Format("ScapCB_ON_Min_%d", i + 1);
		GetPrivateProfileString( "SpecialSet", str, "NULL",
		* strTemp.GetBuffer(BUFFER_LENGTH),BUFFER_LENGTH, strIniFile);
		strValue.Format("%s",strTemp);
		dividerPos = strValue.Find(',',0);
		if(dividerPos > 0)
		{
			for(int j = 0; j < iLenght; j++)
			{
				AfxExtractSubString(SingleItem,
				* strValue, j ,  cDivider);
				if(!SingleItem.IsEmpty())
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapCbTest_ON_Min[i][j] =
					* atoi(SingleItem);
				}
				else
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapCbTest_ON_Min[i][j] = i
					* BasicMin_on;
				}
			}
		}
		else
		{
			for(int j = 0; j < iLenght; j++)
			{
				g_stCfg_MCap_DetailThreshold.
				* SCapCbTest_ON_Min[i][j] = iBasicMin_on;
			}
		}
	}

	for(int i = 0; i < 2; i++)
	{
		if(0 == i)iLenght = g_ScreenSetParam.iUsedMaxRxNum;
		if(1 == i)iLenght = g_ScreenSetParam.iUsedMaxTxNum;

		str.Format("ScapCB_OFF_Max_%d", i + 1);
		GetPrivateProfileString( "SpecialSet", str,"NULL",
		* strTemp.GetBuffer(BUFFER_LENGTH),BUFFER_LENGTH, strIniFile);
		strValue.Format("%s",strTemp);
		dividerPos = strValue.Find(',',0);
		if(dividerPos > 0)
		{
			for(int j = 0; j < iLenght; j++)
			{
				AfxExtractSubString(SingleItem,
				* strValue, j ,  cDivider);
				if(!SingleItem.IsEmpty())
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapCbTest_OFF_Max[i][j] =
					* atoi(SingleItem);
				}
				else
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapCbTest_OFF_Max[i][j] =
					* iBasicMax_off;
				}
			}
		}
		else
		{
			for(int j = 0; j < iLenght; j++)
			{
				g_stCfg_MCap_DetailThreshold.
				* SCapCbTest_OFF_Max[i][j] = iBasicMax_off;
			}
		}
	}

	for(int i = 0; i < 2; i++)
	{
		if(0 == i)iLenght = g_ScreenSetParam.iUsedMaxRxNum;
		if(1 == i)iLenght = g_ScreenSetParam.iUsedMaxTxNum;

		str.Format("ScapCB_OFF_Min_%d", i + 1);
		GetPrivateProfileString( "SpecialSet", str,
		* "NULL",strTemp.GetBuffer(BUFFER_LENGTH),
		* BUFFER_LENGTH, strIniFile);
		strValue.Format("%s",strTemp);
		dividerPos = strValue.Find(',',0);
		if(dividerPos > 0)
		{
			for(int j = 0; j < iLenght; j++)
			{
				AfxExtractSubString(SingleItem,
				* strValue, j ,  cDivider);
				if(!SingleItem.IsEmpty())
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapCbTest_OFF_Min[i][j] =
					*  atoi(SingleItem);
				}
				else
				{
					g_stCfg_MCap_DetailThreshold.
					* SCapCbTest_OFF_Min[i][j] =
					*  iBasicMin_off;
				}
			}
		}
		else
		{
			for(int j = 0; j < iLenght; j++)
			{
				g_stCfg_MCap_DetailThreshold.
				* SCapCbTest_OFF_Min[i][j] = iBasicMin_off;
			}
		}
	}
*/
}

void OnInit_DThreshold_RxLinearityTest(char *strIniFile)
{
	char str[MAX_KEY_VALUE_LEN], strTemp[MAX_KEY_VALUE_LEN], strValue[MAX_KEY_VALUE_LEN];
	int MaxValue = 0;
	int dividerPos = 0;
	char str_tmp[MAX_KEY_VALUE_LEN];
	int index = 0;
	int k = 0, i = 0, j = 0;

	/*Rx_Linearity Test */
	GetPrivateProfileString("Basic_Threshold", "RxLinearityTest_Max",
				"50", str, strIniFile);

	MaxValue = atoi(str);

	/*printk("MaxValue=%d\n",MaxValue); */

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.RxLinearityTest_Max[i][j] =
			    MaxValue;
		}
	}

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"Rx_Linearity_Max_Tx%d", (i + 1));

		/*printk("%s\n", str); */
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "111", strTemp,
					    strIniFile);

		/*printk("GetPrivateProfileString=%d\n", dividerPos); */
		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.RxLinearityTest_Max
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}
}

void OnInit_DThreshold_TxLinearityTest(char *strIniFile)
{
	char str[MAX_KEY_VALUE_LEN], strTemp[MAX_KEY_VALUE_LEN], strValue[MAX_KEY_VALUE_LEN];
	int MaxValue = 0;
	int dividerPos = 0;
	char str_tmp[MAX_KEY_VALUE_LEN];
	int index = 0;
	int k = 0, i = 0, j = 0;

	/*Tx_Linearity Test */
	GetPrivateProfileString("Basic_Threshold", "TxLinearityTest_Max",
				"50", str, strIniFile);

	MaxValue = atoi(str);

	/*printk("MaxValue = %d\n", MaxValue); */

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.TxLinearityTest_Max[i][j] =
			    MaxValue;
		}
	}

	for (i = 0; i < g_ScreenSetParam.iUsedMaxTxNum; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"Tx_Linearity_Max_Tx%d", (i + 1));
		/*printk("%s\n", str); */
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "111", strTemp,
					    strIniFile);

		/*printk("GetPrivateProfileString = %d\n", dividerPos); */
		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.TxLinearityTest_Max
				    [i][k] = (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}
}

void OnInit_DThreshold_ForceTouch_SCapRawDataTest(char *strIniFile)
{
	char str[MAX_KEY_VALUE_LEN], strTemp[MAX_KEY_VALUE_LEN], strValue[MAX_KEY_VALUE_LEN];
	int MaxValue, MinValue;
	int dividerPos = 0;
	char str_tmp[MAX_KEY_VALUE_LEN];
	int index = 0;
	int k = 0, i = 0, j = 0;

	 /*OFF*/
	    GetPrivateProfileString("Basic_Threshold",
				    "ForceTouch_SCapRawDataTest_OFF_Min", "150",
				    str, strIniFile);

	MinValue = atoi(str);

	GetPrivateProfileString("Basic_Threshold",
				"ForceTouch_SCapRawDataTest_OFF_Max", "1000",
				str, strIniFile);

	MaxValue = atoi(str);

	/*Max */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
			ForceTouch_SCapRawDataTest_OFF_Max[i][j] = MaxValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ForceTouch_ScapRawData_OFF_Max_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				ForceTouch_SCapRawDataTest_OFF_Max[i][k]
					= (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/*Min */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
			ForceTouch_SCapRawDataTest_OFF_Min[i][j] = MinValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ForceTouch_ScapRawData_OFF_Min_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				ForceTouch_SCapRawDataTest_OFF_Min[i][k]
					= (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	 /*ON*/
	    GetPrivateProfileString("Basic_Threshold",
				    "ForceTouch_SCapRawDataTest_ON_Min", "150",
				    str, strIniFile);

	MinValue = atoi(str);

	GetPrivateProfileString("Basic_Threshold",
				"ForceTouch_SCapRawDataTest_ON_Max", "1000",
				str, strIniFile);

	MaxValue = atoi(str);

	/*printk("%d:%d\r\n",MinValue, MaxValue); */
	/* Read threshold, without special settings,
	places Basic_Threshold alternative*/

	/*Max */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
			ForceTouch_SCapRawDataTest_ON_Max[i][j] = MaxValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ForceTouch_ScapRawData_ON_Max_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		/*printk("%s:%s\r\n",str, strTemp); */
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				ForceTouch_SCapRawDataTest_ON_Max[i][k]
					= (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}

		}
	}

	/*Min */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
			ForceTouch_SCapRawDataTest_ON_Min[i][j] = MinValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ForceTouch_ScapRawData_ON_Min_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		/*printk("%s:%s\r\n",str, strTemp); */
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				ForceTouch_SCapRawDataTest_ON_Min[i][k]
					= (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}
}

void OnInit_DThreshold_ForceTouch_SCapCbTest(char *strIniFile)
{
	char str[MAX_KEY_VALUE_LEN], strTemp[MAX_KEY_VALUE_LEN], strValue[MAX_KEY_VALUE_LEN];
	int MaxValue, MinValue;
	int dividerPos = 0;
	char str_tmp[MAX_KEY_VALUE_LEN];
	int index = 0;
	int k = 0, i = 0, j = 0;

	GetPrivateProfileString("Basic_Threshold",
				"ForceTouch_SCapCbTest_ON_Min", "0", str,
				strIniFile);
	MinValue = atoi(str);

	GetPrivateProfileString("Basic_Threshold",
				"ForceTouch_SCapCbTest_ON_Max", "240", str,
				strIniFile);
	MaxValue = atoi(str);

	/*printk("%d:%d\r\n",MinValue, MaxValue); */
	/* Read threshold, without special settings,
	places Basic_Threshold alternative*/

	/*Max */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
			ForceTouch_SCapCbTest_ON_Max[i][j] = MaxValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ForceTouch_ScapCB_ON_Max_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		/*printk("%s:%s\r\n",str, strTemp); */
		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				ForceTouch_SCapCbTest_ON_Max[i][k]
					= (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/*Min */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
			ForceTouch_SCapCbTest_ON_Min[i][j] = MinValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ForceTouch_ScapCB_ON_Min_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);
		/*printk("%s:%s\r\n",str, strTemp); */
		if (0 == dividerPos)
			continue;

		index = 0;
		pr_info("%s\r\n", strTemp);

		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				ForceTouch_SCapCbTest_ON_Min[i][k]
					= (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	GetPrivateProfileString("Basic_Threshold",
				"ForceTouch_SCapCbTest_OFF_Min", "0", str,
				strIniFile);
	MinValue = atoi(str);

	GetPrivateProfileString("Basic_Threshold",
				"ForceTouch_SCapCbTest_OFF_Max", "240", str,
				strIniFile);
	MaxValue = atoi(str);

	/*Max */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
			ForceTouch_SCapCbTest_OFF_Max[i][j] = MaxValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ForceTouch_ScapCB_OFF_Max_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
				ForceTouch_SCapCbTest_OFF_Max[i][k]
					= (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}

	/*Min */
	for (i = 0; i < 2; i++) {
		for (j = 0; j < g_ScreenSetParam.iUsedMaxRxNum; j++) {
			g_stCfg_MCap_DetailThreshold.
				ForceTouch_SCapCbTest_OFF_Min[i][j] = MinValue;
		}
	}

	for (i = 0; i < 2; i++) {
		snprintf(str, ARRAY_SIZE(str),
			"ForceTouch_ScapCB_OFF_Min_%d", (i + 1));
		dividerPos =
		    GetPrivateProfileString("SpecialSet", str, "NULL", strTemp,
					    strIniFile);

		snprintf(strValue, ARRAY_SIZE(strValue), "%s", strTemp);

		if (0 == dividerPos)
			continue;

		index = 0;
		k = 0;
		memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));

		for (j = 0; j < dividerPos; j++) {
			if (',' == strValue[j]) {
				g_stCfg_MCap_DetailThreshold.
					ForceTouch_SCapCbTest_OFF_Min[i][k]
						= (short)(atoi(str_tmp));

				index = 0;
				memset(str_tmp, 0x00, ARRAY_SIZE(str_tmp));
				k++;
			} else {
				if (' ' == strValue[j])
					continue;

				str_tmp[index] = strValue[j];
				index++;
			}
		}
	}
}
