#ifndef CATS_FW_RF4463_H
#define CATS_FW_RF4463_H

#include "config.h"
#ifdef USE_RF4463
#include <stdint.h>
#include <stddef.h>

#define RF4463_CTS_REPLY					  0xff
// Waiting time for a valid FFh CTS reading
// the typical time is 20us
#define RF4463_CTS_TIMEOUT 					  2500
// Waiting time for packet send interrupt
// this time is depended on tx length and data rate of wireless
#define RF4463_TX_TIMEOUT 					  500
// Frequency channel
#define RF4463_FREQ_CHANNEL					  0
#define RF4463_ADC_CONV_TEMP                  16
#define RF4463_ADC_SPEED                      10
#define RF4463_ADC_CONV_VOLTS                 8

//Commands
#define RF4463_CMD_NOP                        0x00
#define RF4463_CMD_PART_INFO                  0x01
#define RF4463_CMD_POWER_UP                   0x02
#define RF4463_CMD_PATCH_IMAGE                0x04
#define RF4463_CMD_FUNC_INFO                  0x10
#define RF4463_CMD_SET_PROPERTY               0x11
#define RF4463_CMD_GET_PROPERTY               0x12
#define RF4463_CMD_GPIO_PIN_CFG               0x13
#define RF4463_CMD_GET_ADC_READING            0x14
#define RF4463_CMD_FIFO_INFO                  0x15
#define RF4463_CMD_PACKET_INFO                0x16
#define RF4463_CMD_IRCAL                      0x17
#define RF4463_CMD_PROTOCOL_CFG               0x18
#define RF4463_CMD_GET_INT_STATUS             0x20
#define RF4463_CMD_GET_PH_STATUS              0x21
#define RF4463_CMD_GET_MODEM_STATUS           0x22
#define RF4463_CMD_GET_CHIP_STATUS            0x23
#define RF4463_CMD_START_TX                   0x31
#define RF4463_CMD_START_RX                   0x32
#define RF4463_CMD_REQUEST_DEVICE_STATE       0x33
#define RF4463_CMD_CHANGE_STATE               0x34
#define RF4463_CMD_START_MFSK                 0x35 
#define RF4463_CMD_RX_HOP                     0x36
#define RF4463_CMD_READ_BUF                   0x44
#define RF4463_CMD_FAST_RESPONSE_A            0x50
#define RF4463_CMD_FAST_RESPONSE_B            0x51
#define RF4463_CMD_FAST_RESPONSE_C            0x53
#define RF4463_CMD_FAST_RESPONSE_D            0x57
#define RF4463_CMD_TX_FIFO_WRITE              0x66
#define RF4463_CMD_RX_FIFO_READ               0x77

// Properties
//#define RF4463_CMD_SET_PROPERTY               0x11
//#define RF4463_CMD_GET_PROPERTY               0x12
#define RF4463_PROPERTY_GLOBAL_XO_TUNE                   0x0000
#define RF4463_PROPERTY_GLOBAL_CLK_CFG                   0x0001
#define RF4463_PROPERTY_GLOBAL_LOW_BATT_THRESH           0x0002
#define RF4463_PROPERTY_GLOBAL_CONFIG                    0x0003
#define RF4463_PROPERTY_GLOBAL_WUT_CONFIG                0x0004
#define RF4463_PROPERTY_GLOBAL_WUT_M_15_8                0x0005
#define RF4463_PROPERTY_GLOBAL_WUT_M_7_0                 0x0006
#define RF4463_PROPERTY_GLOBAL_WUT_R                     0x0007
#define RF4463_PROPERTY_GLOBAL_WUT_LDC                   0x0008
#define RF4463_PROPERTY_INT_CTL_ENABLE                   0x0100
#define RF4463_PROPERTY_INT_CTL_PH_ENABLE                0x0101
#define RF4463_PROPERTY_INT_CTL_MODEM_ENABLE             0x0102
#define RF4463_PROPERTY_INT_CTL_CHIP_ENABLE              0x0103
#define RF4463_PROPERTY_FRR_CTL_A_MODE                   0x0200
#define RF4463_PROPERTY_FRR_CTL_B_MODE                   0x0201
#define RF4463_PROPERTY_FRR_CTL_C_MODE                   0x0202
#define RF4463_PROPERTY_FRR_CTL_D_MODE                   0x0203
#define RF4463_PROPERTY_PREAMBLE_TX_LENGTH               0x1000
#define RF4463_PROPERTY_PREAMBLE_CONFIG_STD_1            0x1001
#define RF4463_PROPERTY_PREAMBLE_CONFIG_NSTD             0x1002
#define RF4463_PROPERTY_PREAMBLE_CONFIG_STD_2            0x1003
#define RF4463_PROPERTY_PREAMBLE_CONFIG                  0x1004
#define RF4463_PROPERTY_PREAMBLE_PATTERN_31_24           0x1005
#define RF4463_PROPERTY_PREAMBLE_PATTERN_23_16           0x1006
#define RF4463_PROPERTY_PREAMBLE_PATTERN_15_8            0x1007
#define RF4463_PROPERTY_PREAMBLE_PATTERN_7_0             0x1008
#define RF4463_PROPERTY_SYNC_CONFIG                      0x1100
#define RF4463_PROPERTY_SYNC_BITS_31_24                  0x1101
#define RF4463_PROPERTY_SYNC_BITS_23_16                  0x1102
#define RF4463_PROPERTY_SYNC_BITS_15_8                   0x1103
#define RF4463_PROPERTY_SYNC_BITS_7_0                    0x1104
#define RF4463_PROPERTY_PKT_CRC_CONFIG                   0x1200
#define RF4463_PROPERTY_PKT_CONFIG1                      0x1206
#define RF4463_PROPERTY_PKT_LEN                          0x1208
#define RF4463_PROPERTY_PKT_LEN_FIELD_SOURCE             0x1209
#define RF4463_PROPERTY_PKT_LEN_ADJUST                   0x120a
#define RF4463_PROPERTY_PKT_TX_THRESHOLD                 0x120b
#define RF4463_PROPERTY_PKT_RX_THRESHOLD                 0x120c
#define RF4463_PROPERTY_PKT_FIELD_1_LENGTH_12_8          0x120d
#define RF4463_PROPERTY_PKT_FIELD_1_LENGTH_7_0           0x120e
#define RF4463_PROPERTY_PKT_FIELD_1_CONFIG               0x120f
#define RF4463_PROPERTY_PKT_FIELD_1_CRC_CONFIG           0x1210
#define RF4463_PROPERTY_PKT_FIELD_2_LENGTH_12_8          0x1211
#define RF4463_PROPERTY_PKT_FIELD_2_LENGTH_7_0           0x1212
#define RF4463_PROPERTY_PKT_FIELD_2_CONFIG               0x1213
#define RF4463_PROPERTY_PKT_FIELD_2_CRC_CONFIG           0x1214
#define RF4463_PROPERTY_PKT_FIELD_3_LENGTH_12_8          0x1215
#define RF4463_PROPERTY_PKT_FIELD_3_LENGTH_7_0           0x1216
#define RF4463_PROPERTY_PKT_FIELD_3_CONFIG               0x1217
#define RF4463_PROPERTY_PKT_FIELD_3_CRC_CONFIG           0x1218
#define RF4463_PROPERTY_PKT_FIELD_4_LENGTH_12_8          0x1219
#define RF4463_PROPERTY_PKT_FIELD_4_LENGTH_7_0           0x121a
#define RF4463_PROPERTY_PKT_FIELD_4_CONFIG               0x121b
#define RF4463_PROPERTY_PKT_FIELD_4_CRC_CONFIG           0x121c
#define RF4463_PROPERTY_PKT_FIELD_5_LENGTH_12_8          0x121d
#define RF4463_PROPERTY_PKT_FIELD_5_LENGTH_7_0           0x121e
#define RF4463_PROPERTY_PKT_FIELD_5_CONFIG               0x121f
#define RF4463_PROPERTY_PKT_FIELD_5_CRC_CONFIG           0x1220
#define RF4463_PROPERTY_PKT_RX_FIELD_1_LENGTH_12_8       0x1221
#define RF4463_PROPERTY_PKT_RX_FIELD_1_LENGTH_7_0        0x1222
#define RF4463_PROPERTY_PKT_RX_FIELD_1_CONFIG            0x1223
#define RF4463_PROPERTY_PKT_RX_FIELD_1_CRC_CONFIG        0x1224
#define RF4463_PROPERTY_PKT_RX_FIELD_2_LENGTH_12_8       0x1225
#define RF4463_PROPERTY_PKT_RX_FIELD_2_LENGTH_7_0        0x1226
#define RF4463_PROPERTY_PKT_RX_FIELD_2_CONFIG            0x1227
#define RF4463_PROPERTY_PKT_RX_FIELD_2_CRC_CONFIG        0x1228
#define RF4463_PROPERTY_PKT_RX_FIELD_3_LENGTH_12_8       0x1229
#define RF4463_PROPERTY_PKT_RX_FIELD_3_LENGTH_7_0        0x122a
#define RF4463_PROPERTY_PKT_RX_FIELD_3_CONFIG            0x122b
#define RF4463_PROPERTY_PKT_RX_FIELD_3_CRC_CONFIG        0x122c
#define RF4463_PROPERTY_PKT_RX_FIELD_4_LENGTH_12_8       0x122d
#define RF4463_PROPERTY_PKT_RX_FIELD_4_LENGTH_7_0        0x122e
#define RF4463_PROPERTY_PKT_RX_FIELD_4_CONFIG            0x122f
#define RF4463_PROPERTY_PKT_RX_FIELD_4_CRC_CONFIG        0x1230
#define RF4463_PROPERTY_PKT_RX_FIELD_5_LENGTH_12_8       0x1231
#define RF4463_PROPERTY_PKT_RX_FIELD_5_LENGTH_7_0        0x1232
#define RF4463_PROPERTY_PKT_RX_FIELD_5_CONFIG            0x1233
#define RF4463_PROPERTY_PKT_RX_FIELD_5_CRC_CONFIG        0x1234
#define RF4463_PROPERTY_MODEM_MOD_TYPE                   0x2000
#define RF4463_PROPERTY_MODEM_MAP_CONTROL                0x2001
#define RF4463_PROPERTY_MODEM_DSM_CTRL                   0x2002
#define RF4463_PROPERTY_MODEM_DATA_RATE_2                0x2003
#define RF4463_PROPERTY_MODEM_DATA_RATE_1                0x2004
#define RF4463_PROPERTY_MODEM_DATA_RATE_0                0x2005
#define RF4463_PROPERTY_MODEM_TX_NCO_MODE_3              0x2006
#define RF4463_PROPERTY_MODEM_TX_NCO_MODE_2              0x2007
#define RF4463_PROPERTY_MODEM_TX_NCO_MODE_1              0x2008
#define RF4463_PROPERTY_MODEM_TX_NCO_MODE_0              0x2009
#define RF4463_PROPERTY_MODEM_FREQ_DEV_2                 0x200a
#define RF4463_PROPERTY_MODEM_FREQ_DEV_1                 0x200b
#define RF4463_PROPERTY_MODEM_FREQ_DEV_0                 0x200c
#define RF4463_PROPERTY_MODEM_TX_RAMP_DELAY              0x2018
#define RF4463_PROPERTY_MODEM_MDM_CTRL                   0x2019
#define RF4463_PROPERTY_MODEM_IF_CONTROL                 0x201a
#define RF4463_PROPERTY_MODEM_IF_FREQ_2                  0x201b
#define RF4463_PROPERTY_MODEM_IF_FREQ_1                  0x201c
#define RF4463_PROPERTY_MODEM_IF_FREQ_0                  0x201d
#define RF4463_PROPERTY_MODEM_DECIMATION_CFG1            0x201e
#define RF4463_PROPERTY_MODEM_DECIMATION_CFG0            0x201f
#define RF4463_PROPERTY_MODEM_BCR_OSR_1                  0x2022
#define RF4463_PROPERTY_MODEM_BCR_OSR_0                  0x2023
#define RF4463_PROPERTY_MODEM_BCR_NCO_OFFSET_2           0x2024
#define RF4463_PROPERTY_MODEM_BCR_NCO_OFFSET_1           0x2025
#define RF4463_PROPERTY_MODEM_BCR_NCO_OFFSET_0           0x2026
#define RF4463_PROPERTY_MODEM_BCR_GAIN_1                 0x2027
#define RF4463_PROPERTY_MODEM_BCR_GAIN_0                 0x2028
#define RF4463_PROPERTY_MODEM_BCR_GEAR                   0x2029
#define RF4463_PROPERTY_MODEM_BCR_MISC1                  0x202a
#define RF4463_PROPERTY_MODEM_AFC_GEAR                   0x202c
#define RF4463_PROPERTY_MODEM_AFC_WAIT                   0x202d
#define RF4463_PROPERTY_MODEM_AFC_GAIN_1                 0x202e
#define RF4463_PROPERTY_MODEM_AFC_GAIN_0                 0x202f
#define RF4463_PROPERTY_MODEM_AFC_LIMITER_1              0x2030
#define RF4463_PROPERTY_MODEM_AFC_LIMITER_0              0x2031
#define RF4463_PROPERTY_MODEM_AFC_MISC                   0x2032
#define RF4463_PROPERTY_MODEM_AGC_CONTROL                0x2035
#define RF4463_PROPERTY_MODEM_AGC_WINDOW_SIZE            0x2038
#define RF4463_PROPERTY_MODEM_AGC_RFPD_DECAY             0x2039
#define RF4463_PROPERTY_MODEM_AGC_IFPD_DECAY             0x203a
#define RF4463_PROPERTY_MODEM_FSK4_GAIN1                 0x203b
#define RF4463_PROPERTY_MODEM_FSK4_GAIN0                 0x203c
#define RF4463_PROPERTY_MODEM_FSK4_TH1                   0x203d
#define RF4463_PROPERTY_MODEM_FSK4_TH0                   0x203e
#define RF4463_PROPERTY_MODEM_FSK4_MAP                   0x203f
#define RF4463_PROPERTY_MODEM_OOK_PDTC                   0x2040
#define RF4463_PROPERTY_MODEM_OOK_CNT1                   0x2042
#define RF4463_PROPERTY_MODEM_OOK_MISC                   0x2043
#define RF4463_PROPERTY_MODEM_RAW_SEARCH                 0x2044
#define RF4463_PROPERTY_MODEM_RAW_CONTROL                0x2045
#define RF4463_PROPERTY_MODEM_RAW_EYE_1                  0x2046
#define RF4463_PROPERTY_MODEM_RAW_EYE_0                  0x2047
#define RF4463_PROPERTY_MODEM_ANT_DIV_MODE               0x2048
#define RF4463_PROPERTY_MODEM_ANT_DIV_CONTROL            0x2049
#define RF4463_PROPERTY_MODEM_RSSI_THRESH                0x204a
#define RF4463_PROPERTY_MODEM_RSSI_JUMP_THRESH           0x204b
#define RF4463_PROPERTY_MODEM_RSSI_CONTROL               0x204c
#define RF4463_PROPERTY_MODEM_RSSI_CONTROL2              0x204d
#define RF4463_PROPERTY_MODEM_RSSI_COMP                  0x204e
#define RF4463_PROPERTY_MODEM_ANT_DIV_CONT               0x2049
#define RF4463_PROPERTY_MODEM_CLKGEN_BAND                0x2051
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE13_7_0  0x2100
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE12_7_0  0x2101
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE11_7_0  0x2102
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE10_7_0  0x2103
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE9_7_0   0x2104
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE8_7_0   0x2105
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE7_7_0   0x2106
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE6_7_0   0x2107
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE5_7_0   0x2108
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE4_7_0   0x2109
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE3_7_0   0x210a
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE2_7_0   0x210b
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE1_7_0   0x210c
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COE0_7_0   0x210d
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COEM0      0x210e
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COEM1      0x210f
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COEM2      0x2110
#define RF4463_PROPERTY_MODEM_CHFLT_RX1_CHFLT_COEM3      0x2111
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE13_7_0  0x2112
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE12_7_0  0x2113
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE11_7_0  0x2114
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE10_7_0  0x2115
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE9_7_0   0x2116
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE8_7_0   0x2117
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE7_7_0   0x2118
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE6_7_0   0x2119
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE5_7_0   0x211a
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE4_7_0   0x211b
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE3_7_0   0x211c
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE2_7_0   0x211d
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE1_7_0   0x211e
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COE0_7_0   0x211f
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COEM0      0x2120
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COEM1      0x2121
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COEM2      0x2122
#define RF4463_PROPERTY_MODEM_CHFLT_RX2_CHFLT_COEM3      0x2123
#define RF4463_PROPERTY_PA_MODE                          0x2200
#define RF4463_PROPERTY_PA_PWR_LVL                       0x2201
#define RF4463_PROPERTY_PA_BIAS_CLKDUTY                  0x2202
#define RF4463_PROPERTY_PA_TC                            0x2203
#define RF4463_PROPERTY_SYNTH_PFDCP_CPFF                 0x2300
#define RF4463_PROPERTY_SYNTH_PFDCP_CPINT                0x2301
#define RF4463_PROPERTY_SYNTH_VCO_KV                     0x2302
#define RF4463_PROPERTY_SYNTH_LPFILT3                    0x2303
#define RF4463_PROPERTY_SYNTH_LPFILT2                    0x2304
#define RF4463_PROPERTY_SYNTH_LPFILT1                    0x2305
#define RF4463_PROPERTY_SYNTH_LPFILT0                    0x2306
#define RF4463_PROPERTY_MATCH_VALUE_1                    0x3000
#define RF4463_PROPERTY_MATCH_MASK_1                     0x3001
#define RF4463_PROPERTY_MATCH_CTRL_1                     0x3002
#define RF4463_PROPERTY_MATCH_VALUE_2                    0x3003
#define RF4463_PROPERTY_MATCH_MASK_2                     0x3004
#define RF4463_PROPERTY_MATCH_CTRL_2                     0x3005
#define RF4463_PROPERTY_MATCH_VALUE_3                    0x3006
#define RF4463_PROPERTY_MATCH_MASK_3                     0x3007
#define RF4463_PROPERTY_MATCH_CTRL_3                     0x3008
#define RF4463_PROPERTY_MATCH_VALUE_4                    0x3009
#define RF4463_PROPERTY_MATCH_MASK_4                     0x300a
#define RF4463_PROPERTY_MATCH_CTRL_4                     0x300b
#define RF4463_PROPERTY_FREQ_CONTROL_INTE                0x4000
#define RF4463_PROPERTY_FREQ_CONTROL_FRAC_2              0x4001
#define RF4463_PROPERTY_FREQ_CONTROL_FRAC_1              0x4002
#define RF4463_PROPERTY_FREQ_CONTROL_FRAC_0              0x4003
#define RF4463_PROPERTY_FREQ_CONTROL_CHANNEL_STEP_SIZE_1 0x4004
#define RF4463_PROPERTY_FREQ_CONTROL_CHANNEL_STEP_SIZE_0 0x4005
#define RF4463_PROPERTY_FREQ_CONTROL_VCOCNT_RX_ADJ       0x4007
#define RF4463_PROPERTY_RX_HOP_CONTROL                   0x5000
#define RF4463_PROPERTY_RX_HOP_TABLE_SIZE                0x5001
#define RF4463_PROPERTY_RX_HOP_TABLE_ENTRY_0             0x5002

//#define RF4463_CMD_GPIO_PIN_CFG               0x13
#define RF4463_GPIO_NO_CHANGE                   0
#define RF4463_GPIO_DISABLED                    1
#define RF4463_GPIO_LOW                         2
#define RF4463_GPIO_HIGH                        3
#define RF4463_GPIO_INPUT                       4
#define RF4463_GPIO_32_KHZ_CLOCK                5
#define RF4463_GPIO_BOOT_CLOCK                  6
#define RF4463_GPIO_DIVIDED_MCU_CLOCK           7
#define RF4463_GPIO_CTS                         8
#define RF4463_GPIO_INV_CTS                     9
#define RF4463_GPIO_HIGH_ON_CMD_OVERLAP         10
#define RF4463_GPIO_SPI_DATA_OUT                11
#define RF4463_GPIO_HIGH_AFTER_RESET            12
#define RF4463_GPIO_HIGH_AFTER_CALIBRATION      13
#define RF4463_GPIO_HIGH_AFTER_WUT              14
#define RF4463_GPIO_UNUSED_0                    15
#define RF4463_GPIO_TX_DATA_CLOCK               16
#define RF4463_GPIO_RX_DATA_CLOCK               17
#define RF4463_GPIO_UNUSED_1                    18
#define RF4463_GPIO_TX_DATA                     19
#define RF4463_GPIO_RX_DATA                     20
#define RF4463_GPIO_RX_RAW_DATA                 21
#define RF4463_GPIO_ANTENNA_1_SWITCH            22
#define RF4463_GPIO_ANTENNA_2_SWITCH            23
#define RF4463_GPIO_VALID_PREAMBLE              24
#define RF4463_GPIO_INVALID_PREAMBLE            25
#define RF4463_GPIO_SYNC_DETECTED               26
#define RF4463_GPIO_RSSI_ABOVE_CAT              27
#define RF4463_GPIO_TX_STATE                    32
#define RF4463_GPIO_RX_STATE                    33
#define RF4463_GPIO_RX_FIFO_ALMOST_FULL         34
#define RF4463_GPIO_TX_FIFO_ALMOST_EMPTY        35
#define RF4463_GPIO_BATT_LOW                    36
#define RF4463_GPIO_RSSI_ABOVE_CAT_LOW          37
#define RF4463_GPIO_HOP                         38
#define RF4463_GPIO_HOP_TABLE_WRAPPED           39
#define RF4463_NIRQ_INTERRUPT_SIGNAL			39

// #define RF4463_CMD_GET_INT_STATUS             0x20
#define RF4463_INT_STATUS_CHIP_INT_STATUS                0x04
#define RF4463_INT_STATUS_MODEM_INT_STATUS               0x02
#define RF4463_INT_STATUS_PH_INT_STATUS                  0x01
#define RF4463_INT_STATUS_FILTER_MATCH                   0x80
#define RF4463_INT_STATUS_FILTER_MISS                    0x40
#define RF4463_INT_STATUS_PACKET_SENT                    0x20
#define RF4463_INT_STATUS_PACKET_RX                      0x10
#define RF4463_INT_STATUS_CRC_ERROR                      0x08
#define RF4463_INT_STATUS_TX_FIFO_ALMOST_EMPTY           0x02
#define RF4463_INT_STATUS_RX_FIFO_ALMOST_FULL            0x01
#define RF4463_INT_STATUS_INVALID_SYNC                   0x20
#define RF4463_INT_STATUS_RSSI_JUMP                      0x10
#define RF4463_INT_STATUS_RSSI                           0x08
#define RF4463_INT_STATUS_INVALID_PREAMBLE               0x04
#define RF4463_INT_STATUS_PREAMBLE_DETECT                0x02
#define RF4463_INT_STATUS_SYNC_DETECT                    0x01
#define RF4463_INT_STATUS_CAL                            0x40
#define RF4463_INT_STATUS_FIFO_UNDERFLOW_OVERFLOW_ERROR  0x20
#define RF4463_INT_STATUS_STATE_CHANGE                   0x10
#define RF4463_INT_STATUS_CMD_ERROR                      0x08
#define RF4463_INT_STATUS_CHIP_READY                     0x04
#define RF4463_INT_STATUS_LOW_BATT                       0x02
#define RF4463_INT_STATUS_WUT                            0x01

//#define RF4463_PROPERTY_INT_CTL_ENABLE                   0x0100
#define RF4463_CHIP_INT_STATUS_EN                        0x04
#define RF4463_MODEM_INT_STATUS_EN                       0x02
#define RF4463_PH_INT_STATUS_EN                          0x01

//#define RF4463_PROPERTY_FRR_CTL_A_MODE                   0x0200
//#define RF4463_PROPERTY_FRR_CTL_B_MODE                   0x0201
//#define RF4463_PROPERTY_FRR_CTL_C_MODE                   0x0202
//#define RF4463_PROPERTY_FRR_CTL_D_MODE                   0x0203
#define RF4463_FRR_MODE_DISABLED                         0
#define RF4463_FRR_MODE_GLOBAL_STATUS                    1
#define RF4463_FRR_MODE_GLOBAL_INTERRUPT_PENDING         2
#define RF4463_FRR_MODE_PACKET_HANDLER_STATUS            3
#define RF4463_FRR_MODE_PACKET_HANDLER_INTERRUPT_PENDING 4
#define RF4463_FRR_MODE_MODEM_STATUS                     5
#define RF4463_FRR_MODE_MODEM_INTERRUPT_PENDING          6
#define RF4463_FRR_MODE_CHIP_STATUS                      7
#define RF4463_FRR_MODE_CHIP_INTERRUPT_PENDING           8
#define RF4463_FRR_MODE_CURRENT_STATE                    9
#define RF4463_FRR_MODE_LATCHED_RSSI                     10

//#define RF4463_PROPERTY_PREAMBLE_CONFIG                  0x1004
#define RF4463_PREAMBLE_STANDARD_PREAM                   0x00
#define RF4463_PREAMBLE_DSA_ONLY                         0x80
#define RF4463_PREAMBLE_FIRST_1                          0x20
#define RF4463_PREAMBLE_FIRST_0                          0x00
#define RF4463_PREAMBLE_LENGTH_NIBBLES                   0x00
#define RF4463_PREAMBLE_LENGTH_BYTES                     0x10
#define RF4463_PREAMBLE_MAN_CONST                        0x08
#define RF4463_PREAMBLE_MAN_ENABLE                       0x02
#define RF4463_PREAMBLE_NON_STANDARD                     0x00
#define RF4463_PREAMBLE_STANDARD_1010                    0x01
#define RF4463_PREAMBLE_STANDARD_0101                    0x02

//#define RF4463_PROPERTY_SYNC_CONFIG                      0x1100
#define RF4463_SYNC_CONFIG_SKIP_TX                       0x80
#define RF4463_SYNC_CONFIG_RX_ERRORS_MASK                0x70
#define RF4463_SYNC_CONFIG_4FSK                          0x08
#define RF4463_SYNC_CONFIG_MANCH                         0x04
#define RF4463_SYNC_CONFIG_LENGTH_MASK                   0x03

//#define RF4463_PROPERTY_PKT_CRC_CONFIG                   0x1200
#define RF4463_CRC_SEED_ALL_0S                           0x00
#define RF4463_CRC_SEED_ALL_1S                           0x80
#define RF4463_CRC_MASK                                  0x0f
#define RF4463_CRC_NONE                                  0x00
#define RF4463_CRC_ITU_T                                 0x01
#define RF4463_CRC_IEC_16                                0x02
#define RF4463_CRC_BIACHEVA                              0x03
#define RF4463_CRC_16_IBM                                0x04
#define RF4463_CRC_CCITT                                 0x05
#define RF4463_CRC_KOOPMAN                               0x06
#define RF4463_CRC_IEEE_802_3                            0x07
#define RF4463_CRC_CASTAGNOLI                            0x08

//#define RF4463_PROPERTY_PKT_CONFIG1                      0x1206
#define RF4463_PH_FIELD_SPLIT                            0x80
#define RF4463_PH_RX_DISABLE                             0x40
#define RF4463_4FSK_EN                                   0x20
#define RF4463_RX_MULTI_PKT                              0x10
#define RF4463_MANCH_POL                                 0x08
#define RF4463_CRC_INVERT                                0x04
#define RF4463_CRC_ENDIAN                                0x02
#define RF4463_BIT_ORDER                                 0x01

//#define RF4463_PROPERTY_PKT_LEN                          0x1208
#define RF4463_INFINITE_LEN  							0x40
#define RF4463_ENDIAN_LITTLE  							0x00
#define RF4463_ENDIAN_BIG  								0x20
#define RF4463_SIZE_ENUM_0 								0x00
#define RF4463_SIZE_ENUM_1 								0x01
#define RF4463_IN_FIFO 									0x08
#define RF4463_DST_FIELD_ENUM_0 						0x00
#define RF4463_DST_FIELD_ENUM_1 						0x01
#define RF4463_DST_FIELD_ENUM_2 						0x02
#define RF4463_DST_FIELD_ENUM_3 						0x03
#define RF4463_DST_FIELD_ENUM_4 						0x04
#define RF4463_DST_FIELD_ENUM_5 						0x05
#define RF4463_DST_FIELD_ENUM_6 						0x06
#define RF4463_DST_FIELD_ENUM_7 						0x07

//#define RF4463_PROPERTY_PKT_LEN_FIELD_SOURCE             0x1209
#define RF4463_SRC_FIELD_ENUM_0 						0x00
#define RF4463_SRC_FIELD_ENUM_1 						0x01
#define RF4463_SRC_FIELD_ENUM_2 						0x02
#define RF4463_SRC_FIELD_ENUM_3 						0x03
#define RF4463_SRC_FIELD_ENUM_4 						0x04
#define RF4463_SRC_FIELD_ENUM_5 						0x05

//#define RF4463_PROPERTY_PKT_FIELD_1_CONFIG               0x120f
//#define RF4463_PROPERTY_PKT_FIELD_2_CONFIG               0x1213
//#define RF4463_PROPERTY_PKT_FIELD_3_CONFIG               0x1217
//#define RF4463_PROPERTY_PKT_FIELD_4_CONFIG               0x121b
//#define RF4463_PROPERTY_PKT_FIELD_5_CONFIG               0x121f
#define RF4463_FIELD_CONFIG_4FSK                         0x10
#define RF4463_FIELD_CONFIG_PN_START                     0x04
#define RF4463_FIELD_CONFIG_WHITEN                       0x02
#define RF4463_FIELD_CONFIG_MANCH                        0x01

//#define RF4463_PROPERTY_PKT_RX_FIELD_1_CRC_CONFIG        0x1210
//#define RF4463_PROPERTY_PKT_RX_FIELD_2_CRC_CONFIG        0x1214
//#define RF4463_PROPERTY_PKT_RX_FIELD_3_CRC_CONFIG        0x1218
//#define RF4463_PROPERTY_PKT_RX_FIELD_4_CRC_CONFIG        0x121c
//#define RF4463_PROPERTY_PKT_RX_FIELD_5_CRC_CONFIG        0x1220
#define RF4463_FIELD_CONFIG_CRC_START                     0x80
#define RF4463_FIELD_CONFIG_ALT_CRC_START                 0x40
#define RF4463_FIELD_CONFIG_SEND_CRC                      0x20
#define RF4463_FIELD_CONFIG_SEND_ALT_CRC                  0x10
#define RF4463_FIELD_CONFIG_CHECK_CRC                     0x08
#define RF4463_FIELD_CONFIG_CHECK_ALT_CRC                 0x04
#define RF4463_FIELD_CONFIG_CRC_ENABLE                    0x02
#define RF4463_FIELD_CONFIG_ALT_CRC_ENABLE                0x01

//#define RF4463_PROPERTY_MODEM_MOD_TYPE                   0x2000
#define RF4463_TX_DIRECT_MODE_TYPE_SYNCHRONOUS           0x00
#define RF4463_TX_DIRECT_MODE_TYPE_ASYNCHRONOUS          0x80
#define RF4463_TX_DIRECT_MODE_GPIO0                      0x00
#define RF4463_TX_DIRECT_MODE_GPIO1                      0x20
#define RF4463_TX_DIRECT_MODE_GPIO2                      0x40
#define RF4463_TX_DIRECT_MODE_GPIO3                      0x60
#define RF4463_MOD_SOURCE_PACKET_HANDLER                 0x00
#define RF4463_MOD_SOURCE_DIRECT_MODE                    0x08
#define RF4463_MOD_SOURCE_RANDOM_GENERATOR               0x10
#define RF4463_MOD_TYPE_CW                               0x00
#define RF4463_MOD_TYPE_OOK                              0x01
#define RF4463_MOD_TYPE_2FSK                             0x02
#define RF4463_MOD_TYPE_2GFSK                            0x03
#define RF4463_MOD_TYPE_4FSK                             0x04
#define RF4463_MOD_TYPE_4GFSK                            0x05

//#define  RF4463_PROPERTY_PA_MODE                          0x2200
#define RF4463_PA_MODE_1_GROUP                           0x04
#define RF4463_PA_MODE_2_GROUPS                          0x08
#define RF4463_PA_MODE_CLASS_E                           0x00
#define RF4463_PA_MODE_SWITCH_CURRENT                    0x01

typedef enum state {
    RF4463_STATE_NO,
    RF4463_STATE_SLEEP,
    RF4463_STATE_SPI_ACTIVE,
    RF4463_STATE_READY,
    RF4463_STATE_READY2,
    RF4463_STATE_TUNE_TX,
    RF4463_STATE_TUNE_RX,
    RF4463_STATE_TX,
    RF4463_STATE_RX
} rf4463_state_t;

int si_set_property(uint16_t property, uint8_t* data, uint8_t len);
int si_send_command(uint8_t* cmd, int len);
int si_read_command(uint8_t* cmd, uint8_t len, uint8_t* out_data, uint8_t out_len);
int si_get_state();

void si_load_config(const uint8_t* config, int len);
void si_poweron();
int si_rx_fifo_len();
int si_tx_fifo_space();
int si_packet_sent_pending();
int si_packet_rx_pending();
int si_fifo_underflow_pending();
uint16_t si_get_adc(uint8_t en, uint8_t cfg, size_t part);
uint8_t si_read_frr(size_t part);

int si_cli();
int si_irq();
int si_cts();
int si_check();

#include "radio_config.h"
const uint8_t radio_config[] = RADIO_CONFIGURATION_DATA_ARRAY;

// CATS CONFIG
// 9600bd 2FSK
const uint8_t cats_config[644] = { 
    0x7, 0x2, 0x1, 0x0, 0x1, 0xC9, 0xC3, 0x80,
    0x8, 0x13, 0x0, 0x20, 0x21, 0x20, 0x27, 0x0, 0x0,
    0x5, 0x11, 0x0, 0x1, 0x0, 0x62,
    0x5, 0x11, 0x0, 0x1, 0x3, 0x30,
    0x5, 0x11, 0x10, 0x1, 0x4, 0x21, 
    0x10, 0x11, 0x20, 0xC, 0x0, 0x3, 0x0, 0x7, 0x2, 0x71, 0x0, 0x5, 0xC9, 0xC3, 0x80, 0x0, 0x0,
    0x5, 0x11, 0x20, 0x1, 0xC, 0x46,
    0x10, 0x11, 0x20, 0xC, 0x18, 0x1, 0x0, 0x8, 0x3, 0x80, 0x0, 0xB0, 0x10, 0xC, 0xE8, 0x0, 0x4E,
    0x10, 0x11, 0x20, 0xC, 0x24, 0x6, 0x8D, 0xB9, 0x0, 0x0, 0x2, 0xC0, 0x8, 0x0, 0x12, 0x0, 0x23,
    0x7, 0x11, 0x20, 0x3, 0x30, 0x1, 0x5C, 0xA0,
    0x5, 0x11, 0x20, 0x1, 0x35, 0xE0,
    0x10, 0x11, 0x20, 0xC, 0x38, 0x11, 0x11, 0x11, 0x80, 0x1A, 0x20, 0x0, 0x0, 0x28, 0xC, 0xA4, 0x23,
    0x9, 0x11, 0x20, 0x5, 0x45, 0x3, 0x0, 0x85, 0x1, 0x0,
    0x8, 0x11, 0x20, 0x4, 0x4B, 0x6, 0x9, 0x10, 0x40,
    0x6, 0x11, 0x20, 0x2, 0x50, 0x94, 0xA,
    0x6, 0x11, 0x20, 0x2, 0x54, 0x3, 0x7,
    0x5, 0x11, 0x20, 0x1, 0x57, 0x0,
    0x9, 0x11, 0x20, 0x5, 0x5B, 0x40, 0x4, 0x4, 0x78, 0x20,
    0x10, 0x11, 0x21, 0xC, 0x0, 0x7E, 0x64, 0x1B, 0xBA, 0x58, 0xB, 0xDD, 0xCE, 0xD6, 0xE6, 0xF6, 0x0,
    0x10, 0x11, 0x21, 0xC, 0xC, 0x3, 0x3, 0x15, 0xF0, 0x3F, 0x0, 0x7E, 0x64, 0x1B, 0xBA, 0x58, 0xB, 
    0x10, 0x11, 0x21, 0xC, 0x18, 0xDD, 0xCE, 0xD6, 0xE6, 0xF6, 0x0, 0x3, 0x3, 0x15, 0xF0, 0x3F, 0x0,
    0x5, 0x11, 0x22, 0x1, 0x3, 0x1D,
    0xB, 0x11, 0x23, 0x7, 0x0, 0x2C, 0xE, 0xB, 0x4, 0xC, 0x73, 0x3,
    //0xC, 0x11, 0x40, 0x8, 0x0, 0x37, 0x9, 0x0, 0x0, 0x6, 0xD4, 0x20, 0xFE, //
    0x8, 0x32, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x5, 0x17, 0x56, 0x10, 0xCA, 0xF0,
    0x5, 0x17, 0x13, 0x10, 0xCA, 0xF0,
    0x5, 0x11, 0x0, 0x1, 0x1, 0x0,
    0x6, 0x11, 0x1, 0x2, 0x0, 0x1, 0x33,
    0x8, 0x11, 0x2, 0x4, 0x0, 0xA, 0x0, 0x0, 0x0,
    0xD, 0x11, 0x10, 0x9, 0x0, 0x8, 0x14, 0x0, 0xF, 0x12, 0x0, 0x0, 0x0, 0x0,
    0xA, 0x11, 0x11, 0x6, 0x0, 0x23, 0xD5, 0xB3, 0xF7, 0x48, 0x0,
    0x10, 0x11, 0x12, 0xC, 0x0, 0x0, 0x0, 0x30, 0xFF, 0xFF, 0x20, 0x12, 0x0, 0x12, 0x1, 0x0, 0x30,
    0x10, 0x11, 0x12, 0xC, 0xC, 0x30, 0x0, 0x2, 0x4, 0x0, 0x1F, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x10, 0x11, 0x12, 0xC, 0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
    0x10, 0x11, 0x12, 0xC, 0x24, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x9, 0x11, 0x12, 0x5, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x8, 0x11, 0x12, 0x4, 0x36, 0x0, 0x0, 0x0, 0x0, 
    0x10, 0x11, 0x20, 0xC, 0x0, 0x2, 0x0, 0x7, 0x1, 0x77, 0x0, 0x1, 0xC9, 0xC3, 0x80, 0x0, 0x1,
    0x5, 0x11, 0x20, 0x1, 0xC, 0x50,
    0x10, 0x11, 0x20, 0xC, 0x18, 0x1, 0x0, 0x8, 0x3, 0x80, 0x0, 0x70, 0x20, 0x0, 0xE8, 0x0, 0x62,
    0x10, 0x11, 0x20, 0xC, 0x24, 0x5, 0x3E, 0x2D, 0x5, 0x39, 0x2, 0x0, 0x0, 0x0, 0x12, 0x80, 0x54,
    0x7, 0x11, 0x20, 0x3, 0x30, 0x2, 0x9C, 0xA0,
    0x5, 0x11, 0x20, 0x1, 0x35, 0xE0,
    0x10, 0x11, 0x20, 0xC, 0x38, 0x11, 0x15, 0x15, 0x80, 0x2, 0x40, 0x0, 0x0, 0x28, 0xC, 0xA4, 0x23,
    0xE, 0x11, 0x20, 0xA, 0x45, 0x3, 0x1, 0x47, 0x1, 0x0, 0xFF, 0x6, 0x2, 0x18, 0x40,
    0x6, 0x11, 0x20, 0x2, 0x50, 0x84, 0xA,
    0x6, 0x11, 0x20, 0x2, 0x54, 0x4, 0x7,
    0x5, 0x11, 0x20, 0x1, 0x57, 0x0,
    0x9, 0x11, 0x20, 0x5, 0x5B, 0x40, 0x4, 0xB, 0x78, 0x20,
    0x10, 0x11, 0x21, 0xC, 0x0, 0xFF, 0xBA, 0xF, 0x51, 0xCF, 0xA9, 0xC9, 0xFC, 0x1B, 0x1E, 0xF, 0x1,
    0x10, 0x11, 0x21, 0xC, 0xC, 0xFC, 0xFD, 0x15, 0xFF, 0x0, 0xF, 0xFF, 0xBA, 0xF, 0x51, 0xCF, 0xA9,
    0x10, 0x11, 0x21, 0xC, 0x18, 0xC9, 0xFC, 0x1B, 0x1E, 0xF, 0x1, 0xFC, 0xFD, 0x15, 0xFF, 0x0, 0xF,
    0x8, 0x11, 0x22, 0x4, 0x0, 0x8, 0x7F, 0x0, 0x1D,
    0xB, 0x11, 0x23, 0x7, 0x0, 0x2C, 0xE, 0xB, 0x4, 0xC, 0x73, 0x3,
    0x10, 0x11, 0x30, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    //0xC, 0x11, 0x40, 0x8, 0x0, 0x38, 0xA, 0xAA, 0xAA, 0x6, 0xD4, 0x20, 0xFE
};

#endif // USE_RF4463
#endif // CATS_FW_RF4463_H