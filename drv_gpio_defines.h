/*********************************************************************************************************************
 *                                                      COMECA
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \author		tedie.cedric
 *  \date		13 avr. 2018
 *  \addtogroup DRIVERS
 *  \{
 *  \addtogroup DRV_GPIO_DEFINES
 *  \{
 ********************************************************************************************************************/
/**
 *********************************************************************************************************************
 *  \file		drv_gpio_defines.h
 *  
 *  \brief		This module defines some useful macro to use the GPIO API
 *
 *  \details	
 *
 ********************************************************************************************************************/
#ifndef GPIO_DEFINES_H_
#define GPIO_DEFINES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes --------------------------------------------------------------------------------------------------------*/

/* Public Macro definition -----------------------------------------------------------------------------------------*/

/** \name GPIO Pin defines
 *  \{
 */

#define GPIO_0          0U
#define GPIO_1          1U
#define GPIO_2          2U
#define GPIO_3          3U
#define GPIO_4          4U
#define GPIO_5          5U
#define GPIO_6          6U
#define GPIO_7          7U
#define GPIO_8          8U
#define GPIO_9          9U
#define GPIO_10         10U
#define GPIO_11         11U
#define GPIO_12         12U
#define GPIO_13         13U
#define GPIO_14         14U
#define GPIO_15         15U
#define GPIO_16         16U
#define GPIO_17         17U
#define GPIO_18         18U
#define GPIO_19         19U
#define GPIO_20         20U
#define GPIO_21         21U
#define GPIO_22         22U
#define GPIO_23         23U
#define GPIO_24         24U
#define GPIO_25         25U
#define GPIO_26         26U
#define GPIO_27         27U
#define GPIO_28         28U
#define GPIO_29         29U
#define GPIO_30         30U
#define GPIO_31         31U
#define GPIO_32         32U
#define GPIO_33         33U
#define GPIO_34         34U
#define GPIO_35         35U
#define GPIO_36         36U
#define GPIO_37         37U
#define GPIO_38         38U
#define GPIO_39         39U
#define GPIO_40         40U
#define GPIO_41         41U
#define GPIO_42         42U
#define GPIO_43         43U
#define GPIO_44         44U
#define GPIO_45         45U
#define GPIO_46         46U
#define GPIO_47         47U
#define GPIO_48         48U
#define GPIO_49         49U
#define GPIO_50         50U
#define GPIO_51         51U
#define GPIO_52         52U
#define GPIO_53         53U
#define GPIO_54         54U
#define GPIO_55         55U
#define GPIO_56         56U
#define GPIO_57         57U
#define GPIO_58         58U
#define GPIO_59         59U
#define GPIO_60         60U
#define GPIO_61         61U
#define GPIO_62         62U
#define GPIO_63         63U
#define GPIO_64         64U
#define GPIO_65         65U
#define GPIO_66         66U
#define GPIO_67         67U
#define GPIO_68         68U
#define GPIO_69         69U
#define GPIO_70         70U
#define GPIO_71         71U
#define GPIO_72         72U
#define GPIO_73         73U
#define GPIO_74         74U
#define GPIO_75         75U
#define GPIO_76         76U
#define GPIO_77         77U
#define GPIO_78         78U
#define GPIO_79         79U
#define GPIO_80         80U
#define GPIO_81         81U
#define GPIO_82         82U
#define GPIO_83         83U
#define GPIO_84         84U
#define GPIO_85         85U
#define GPIO_86         86U
#define GPIO_87         87U
#define GPIO_88         88U
#define GPIO_89         89U
#define GPIO_90         90U
#define GPIO_91         91U
#define GPIO_92         92U
#define GPIO_93         93U
#define GPIO_94         94U
#define GPIO_95         95U
#define GPIO_96         96U
#define GPIO_97         97U
#define GPIO_98         98U
#define GPIO_99         99U
#define GPIO_100        100U
#define GPIO_101        101U
#define GPIO_102        102U
#define GPIO_103        103U
#define GPIO_104        104U
#define GPIO_105        105U
#define GPIO_106        106U
#define GPIO_107        107U
#define GPIO_108        108U
#define GPIO_109        109U
#define GPIO_110        110U
#define GPIO_111        111U
#define GPIO_112        112U
#define GPIO_113        113U
#define GPIO_114        114U
#define GPIO_115        115U
#define GPIO_116        116U
#define GPIO_117        117U
#define GPIO_118        118U
#define GPIO_119        119U
#define GPIO_120        120U
#define GPIO_121        121U
#define GPIO_122        122U
#define GPIO_123        123U
#define GPIO_124        124U
#define GPIO_125        125U
#define GPIO_126        126U
#define GPIO_127        127U
#define GPIO_128        128U
#define GPIO_129        129U
#define GPIO_130        130U
#define GPIO_131        131U
#define GPIO_132        132U
#define GPIO_133        133U
#define GPIO_134        134U
#define GPIO_135        135U
#define GPIO_136        136U
#define GPIO_137        137U
#define GPIO_138        138U
#define GPIO_139        139U
#define GPIO_140        140U
#define GPIO_141        141U
#define GPIO_142        142U
#define GPIO_143        143U
#define GPIO_144        144U
#define GPIO_145        145U
#define GPIO_146        146U
#define GPIO_147        147U
#define GPIO_148        148U
#define GPIO_149        149U
#define GPIO_150        150U
#define GPIO_151        151U
#define GPIO_152        152U
#define GPIO_153        153U
#define GPIO_154        154U
#define GPIO_155        155U
#define GPIO_156        156U
#define GPIO_157        157U
#define GPIO_158        158U
#define GPIO_159        159U
#define GPIO_160        160U
#define GPIO_161        161U
#define GPIO_162        162U
#define GPIO_163        163U
#define GPIO_164        164U
#define GPIO_165        165U
#define GPIO_166        166U
#define GPIO_167        167U
#define GPIO_168        168U

/** \} */

/** \name GPIO0 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO0_GPIO             0
#define DRV_GPIO_MUX_GPIO0_EPWM1A           1
#define DRV_GPIO_MUX_GPIO0_I2CASDA          6

/** \} */


/** \name GPIO1 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO1_GPIO             0
#define DRV_GPIO_MUX_GPIO1_EPWM1B           1
#define DRV_GPIO_MUX_GPIO1_MCBSPBFSR        3
#define DRV_GPIO_MUX_GPIO1_I2CASCL          6

/** \} */


/** \name GPIO2 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO2_GPIO             0
#define DRV_GPIO_MUX_GPIO2_EPWM2A           1
#define DRV_GPIO_MUX_GPIO2_OUTXBAR1         5
#define DRV_GPIO_MUX_GPIO2_I2CBSDA          6

/** \} */


/** \name GPIO3 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO3_GPIO             0
#define DRV_GPIO_MUX_GPIO3_EMPW2B           1
#define DRV_GPIO_MUX_GPIO3_OUTXBAR2         2
#define DRV_GPIO_MUX_GPIO3_MCBSPBCLKR       3
//#define DRV_GPIO_MUX_GPIO3_OUTXBAR2         5 //The same as 2
#define DRV_GPIO_MUX_GPIO3_I2CBSCL          6

/** \} */


/** \name GPIO4 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO4_GPIO             0
#define DRV_GPIO_MUX_GPIO4_EPWM3A           1
#define DRV_GPIO_MUX_GPIO4_                 0
#define DRV_GPIO_MUX_GPIO4_                 0
#define DRV_GPIO_MUX_GPIO4_                 0
#define DRV_GPIO_MUX_GPIO4_                 0
#define DRV_GPIO_MUX_GPIO4_                 0
#define DRV_GPIO_MUX_GPIO4_                 0

/** \} */


/** \name GPIO5 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO5_GPIO             0
#define DRV_GPIO_MUX_GPIO5_EPWM3B           1
#define DRV_GPIO_MUX_GPIO5_                 0
#define DRV_GPIO_MUX_GPIO5_                 0
#define DRV_GPIO_MUX_GPIO5_                 0
#define DRV_GPIO_MUX_GPIO5_                 0
#define DRV_GPIO_MUX_GPIO5_                 0
#define DRV_GPIO_MUX_GPIO5_                 0

/** \} */


/** \name GPIO6 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO6_GPIO             0
#define DRV_GPIO_MUX_GPIO6_EPWM4A           1
#define DRV_GPIO_MUX_GPIO6_                 0
#define DRV_GPIO_MUX_GPIO6_                 0
#define DRV_GPIO_MUX_GPIO6_                 0
#define DRV_GPIO_MUX_GPIO6_                 0
#define DRV_GPIO_MUX_GPIO6_                 0
#define DRV_GPIO_MUX_GPIO6_                 0

/** \} */


/** \name GPIO7 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO7_GPIO             0
#define DRV_GPIO_MUX_GPIO7_EPWM4B           1
#define DRV_GPIO_MUX_GPIO7_                 0
#define DRV_GPIO_MUX_GPIO7_                 0
#define DRV_GPIO_MUX_GPIO7_                 0
#define DRV_GPIO_MUX_GPIO7_                 0
#define DRV_GPIO_MUX_GPIO7_                 0
#define DRV_GPIO_MUX_GPIO7_                 0

/** \} */


/** \name GPIO8 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO8_GPIO             0
#define DRV_GPIO_MUX_GPIO8_EPWM5A           1
#define DRV_GPIO_MUX_GPIO8_                 0
#define DRV_GPIO_MUX_GPIO8_                 0
#define DRV_GPIO_MUX_GPIO8_                 0
#define DRV_GPIO_MUX_GPIO8_                 0
#define DRV_GPIO_MUX_GPIO8_                 0
#define DRV_GPIO_MUX_GPIO8_                 0

/** \} */


/** \name GPIO9 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO9_GPIO             0
#define DRV_GPIO_MUX_GPIO9_EPWM5B           1
#define DRV_GPIO_MUX_GPIO9_                 0
#define DRV_GPIO_MUX_GPIO9_                 0
#define DRV_GPIO_MUX_GPIO9_                 0
#define DRV_GPIO_MUX_GPIO9_                 0
#define DRV_GPIO_MUX_GPIO9_                 0
#define DRV_GPIO_MUX_GPIO9_                 0

/** \} */


/** \name GPIO10 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO10_GPIO            0
#define DRV_GPIO_MUX_GPIO10_EPWM6A          1
#define DRV_GPIO_MUX_GPIO10_                0
#define DRV_GPIO_MUX_GPIO10_                0
#define DRV_GPIO_MUX_GPIO10_                0
#define DRV_GPIO_MUX_GPIO10_                0
#define DRV_GPIO_MUX_GPIO10_                0
#define DRV_GPIO_MUX_GPIO10_                0

/** \} */


/** \name GPIO11 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO11_GPIO            0
#define DRV_GPIO_MUX_GPIO11_EPWM6B          1
#define DRV_GPIO_MUX_GPIO11_                0
#define DRV_GPIO_MUX_GPIO11_                0
#define DRV_GPIO_MUX_GPIO11_                0
#define DRV_GPIO_MUX_GPIO11_                0
#define DRV_GPIO_MUX_GPIO11_                0
#define DRV_GPIO_MUX_GPIO11_                0

/** \} */


/** \name GPIO12 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO12_GPIO            0
#define DRV_GPIO_MUX_GPIO12_EPWM7A          1
#define DRV_GPIO_MUX_GPIO12_                0
#define DRV_GPIO_MUX_GPIO12_                0
#define DRV_GPIO_MUX_GPIO12_                0
#define DRV_GPIO_MUX_GPIO12_                0
#define DRV_GPIO_MUX_GPIO12_                0
#define DRV_GPIO_MUX_GPIO12_                0

/** \} */


/** \name GPIO13 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO13_GPIO            0
#define DRV_GPIO_MUX_GPIO13_EPWM7B          1
#define DRV_GPIO_MUX_GPIO13_                0
#define DRV_GPIO_MUX_GPIO13_                0
#define DRV_GPIO_MUX_GPIO13_                0
#define DRV_GPIO_MUX_GPIO13_                0
#define DRV_GPIO_MUX_GPIO13_                0
#define DRV_GPIO_MUX_GPIO13_                0

/** \} */


/** \name GPIO14 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO14_GPIO            0
#define DRV_GPIO_MUX_GPIO14_EPWM8A          1
#define DRV_GPIO_MUX_GPIO14_                0
#define DRV_GPIO_MUX_GPIO14_                0
#define DRV_GPIO_MUX_GPIO14_                0
#define DRV_GPIO_MUX_GPIO14_                0
#define DRV_GPIO_MUX_GPIO14_                0
#define DRV_GPIO_MUX_GPIO14_                0

/** \} */


/** \name GPIO15 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO15_GPIO            0
#define DRV_GPIO_MUX_GPIO15_EPWM8B          1
#define DRV_GPIO_MUX_GPIO15_                0
#define DRV_GPIO_MUX_GPIO15_                0
#define DRV_GPIO_MUX_GPIO15_                0
#define DRV_GPIO_MUX_GPIO15_                0
#define DRV_GPIO_MUX_GPIO15_                0
#define DRV_GPIO_MUX_GPIO15_                0

/** \} */


/** \name GPIO16 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO16_GPIO            0
#define DRV_GPIO_MUX_GPIO16_                0
#define DRV_GPIO_MUX_GPIO16_                0
#define DRV_GPIO_MUX_GPIO16_                0
#define DRV_GPIO_MUX_GPIO16_                0
#define DRV_GPIO_MUX_GPIO16_                0
#define DRV_GPIO_MUX_GPIO16_                0
#define DRV_GPIO_MUX_GPIO16_                0

/** \} */


/** \name GPIO17 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO17_GPIO            0
#define DRV_GPIO_MUX_GPIO17_                0
#define DRV_GPIO_MUX_GPIO17_                0
#define DRV_GPIO_MUX_GPIO17_                0
#define DRV_GPIO_MUX_GPIO17_                0
#define DRV_GPIO_MUX_GPIO17_                0
#define DRV_GPIO_MUX_GPIO17_                0
#define DRV_GPIO_MUX_GPIO17_                0

/** \} */


/** \name GPIO18 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO18_GPIO            0
#define DRV_GPIO_MUX_GPIO18_                0
#define DRV_GPIO_MUX_GPIO18_                0
#define DRV_GPIO_MUX_GPIO18_                0
#define DRV_GPIO_MUX_GPIO18_                0
#define DRV_GPIO_MUX_GPIO18_                0
#define DRV_GPIO_MUX_GPIO18_                0
#define DRV_GPIO_MUX_GPIO18_                0

/** \} */


/** \name GPIO19 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO19_GPIO            0
#define DRV_GPIO_MUX_GPIO19_                0
#define DRV_GPIO_MUX_GPIO19_                0
#define DRV_GPIO_MUX_GPIO19_                0
#define DRV_GPIO_MUX_GPIO19_                0
#define DRV_GPIO_MUX_GPIO19_                0
#define DRV_GPIO_MUX_GPIO19_                0
#define DRV_GPIO_MUX_GPIO19_                0

/** \} */


/** \name GPIO20 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO20_GPIO            0
#define DRV_GPIO_MUX_GPIO20_                0
#define DRV_GPIO_MUX_GPIO20_                0
#define DRV_GPIO_MUX_GPIO20_                0
#define DRV_GPIO_MUX_GPIO20_                0
#define DRV_GPIO_MUX_GPIO20_                0
#define DRV_GPIO_MUX_GPIO20_                0
#define DRV_GPIO_MUX_GPIO20_                0

/** \} */


/** \name GPIO21 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO21_GPIO            0
#define DRV_GPIO_MUX_GPIO21_                0
#define DRV_GPIO_MUX_GPIO21_                0
#define DRV_GPIO_MUX_GPIO21_                0
#define DRV_GPIO_MUX_GPIO21_                0
#define DRV_GPIO_MUX_GPIO21_                0
#define DRV_GPIO_MUX_GPIO21_                0
#define DRV_GPIO_MUX_GPIO21_                0

/** \} */


/** \name GPIO22 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO22_GPIO            0
#define DRV_GPIO_MUX_GPIO22_                0
#define DRV_GPIO_MUX_GPIO22_                0
#define DRV_GPIO_MUX_GPIO22_                0
#define DRV_GPIO_MUX_GPIO22_                0
#define DRV_GPIO_MUX_GPIO22_                0
#define DRV_GPIO_MUX_GPIO22_                0
#define DRV_GPIO_MUX_GPIO22_                0

/** \} */


/** \name GPIO23 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO23_GPIO            0
#define DRV_GPIO_MUX_GPIO23_                0
#define DRV_GPIO_MUX_GPIO23_                0
#define DRV_GPIO_MUX_GPIO23_                0
#define DRV_GPIO_MUX_GPIO23_                0
#define DRV_GPIO_MUX_GPIO23_                0
#define DRV_GPIO_MUX_GPIO23_                0
#define DRV_GPIO_MUX_GPIO23_                0

/** \} */


/** \name GPIO24 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO24_GPIO            0
#define DRV_GPIO_MUX_GPIO24_                0
#define DRV_GPIO_MUX_GPIO24_                0
#define DRV_GPIO_MUX_GPIO24_                0
#define DRV_GPIO_MUX_GPIO24_                0
#define DRV_GPIO_MUX_GPIO24_                0
#define DRV_GPIO_MUX_GPIO24_                0
#define DRV_GPIO_MUX_GPIO24_                0

/** \} */


/** \name GPIO25 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO25_GPIO            0
#define DRV_GPIO_MUX_GPIO25_                0
#define DRV_GPIO_MUX_GPIO25_                0
#define DRV_GPIO_MUX_GPIO25_                0
#define DRV_GPIO_MUX_GPIO25_                0
#define DRV_GPIO_MUX_GPIO25_                0
#define DRV_GPIO_MUX_GPIO25_                0
#define DRV_GPIO_MUX_GPIO25_                0

/** \} */


/** \name GPIO26 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO26_GPIO            0
#define DRV_GPIO_MUX_GPIO26_                0
#define DRV_GPIO_MUX_GPIO26_                0
#define DRV_GPIO_MUX_GPIO26_                0
#define DRV_GPIO_MUX_GPIO26_                0
#define DRV_GPIO_MUX_GPIO26_                0
#define DRV_GPIO_MUX_GPIO26_                0
#define DRV_GPIO_MUX_GPIO26_                0

/** \} */


/** \name GPIO27 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO27_GPIO            0
#define DRV_GPIO_MUX_GPIO27_                0
#define DRV_GPIO_MUX_GPIO27_                0
#define DRV_GPIO_MUX_GPIO27_                0
#define DRV_GPIO_MUX_GPIO27_                0
#define DRV_GPIO_MUX_GPIO27_                0
#define DRV_GPIO_MUX_GPIO27_                0
#define DRV_GPIO_MUX_GPIO27_                0

/** \} */


/** \name GPIO28 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO28_GPIO            0
#define DRV_GPIO_MUX_GPIO28_                0
#define DRV_GPIO_MUX_GPIO28_                0
#define DRV_GPIO_MUX_GPIO28_                0
#define DRV_GPIO_MUX_GPIO28_                0
#define DRV_GPIO_MUX_GPIO28_                0
#define DRV_GPIO_MUX_GPIO28_                0
#define DRV_GPIO_MUX_GPIO28_                0

/** \} */


/** \name GPIO29 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO29_GPIO            0
#define DRV_GPIO_MUX_GPIO29_                0
#define DRV_GPIO_MUX_GPIO29_                0
#define DRV_GPIO_MUX_GPIO29_                0
#define DRV_GPIO_MUX_GPIO29_                0
#define DRV_GPIO_MUX_GPIO29_                0
#define DRV_GPIO_MUX_GPIO29_                0
#define DRV_GPIO_MUX_GPIO29_                0

/** \} */


/** \name GPIO30 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO30_GPIO            0
#define DRV_GPIO_MUX_GPIO30_                0
#define DRV_GPIO_MUX_GPIO30_                0
#define DRV_GPIO_MUX_GPIO30_                0
#define DRV_GPIO_MUX_GPIO30_                0
#define DRV_GPIO_MUX_GPIO30_                0
#define DRV_GPIO_MUX_GPIO30_                0
#define DRV_GPIO_MUX_GPIO30_                0

/** \} */


/** \name GPIO31 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO31_GPIO            0
#define DRV_GPIO_MUX_GPIO31_                0
#define DRV_GPIO_MUX_GPIO31_                0
#define DRV_GPIO_MUX_GPIO31_                0
#define DRV_GPIO_MUX_GPIO31_                0
#define DRV_GPIO_MUX_GPIO31_                0
#define DRV_GPIO_MUX_GPIO31_                0
#define DRV_GPIO_MUX_GPIO31_                0

/** \} */


/** \name GPIO32 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO32_GPIO            0
#define DRV_GPIO_MUX_GPIO32_                0
#define DRV_GPIO_MUX_GPIO32_                0
#define DRV_GPIO_MUX_GPIO32_                0
#define DRV_GPIO_MUX_GPIO32_                0
#define DRV_GPIO_MUX_GPIO32_                0
#define DRV_GPIO_MUX_GPIO32_                0
#define DRV_GPIO_MUX_GPIO32_                0

/** \} */


/** \name GPIO33 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO33_GPIO            0
#define DRV_GPIO_MUX_GPIO33_                0
#define DRV_GPIO_MUX_GPIO33_                0
#define DRV_GPIO_MUX_GPIO33_                0
#define DRV_GPIO_MUX_GPIO33_                0
#define DRV_GPIO_MUX_GPIO33_                0
#define DRV_GPIO_MUX_GPIO33_                0
#define DRV_GPIO_MUX_GPIO33_                0

/** \} */


/** \name GPIO34 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO34_GPIO            0
#define DRV_GPIO_MUX_GPIO34_                0
#define DRV_GPIO_MUX_GPIO34_                0
#define DRV_GPIO_MUX_GPIO34_                0
#define DRV_GPIO_MUX_GPIO34_                0
#define DRV_GPIO_MUX_GPIO34_                0
#define DRV_GPIO_MUX_GPIO34_                0
#define DRV_GPIO_MUX_GPIO34_                0

/** \} */


/** \name GPIO35 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO35_GPIO            0
#define DRV_GPIO_MUX_GPIO35_                0
#define DRV_GPIO_MUX_GPIO35_                0
#define DRV_GPIO_MUX_GPIO35_                0
#define DRV_GPIO_MUX_GPIO35_                0
#define DRV_GPIO_MUX_GPIO35_                0
#define DRV_GPIO_MUX_GPIO35_                0
#define DRV_GPIO_MUX_GPIO35_                0

/** \} */


/** \name GPIO36 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO36_GPIO            0
#define DRV_GPIO_MUX_GPIO36_                0
#define DRV_GPIO_MUX_GPIO36_                0
#define DRV_GPIO_MUX_GPIO36_                0
#define DRV_GPIO_MUX_GPIO36_                0
#define DRV_GPIO_MUX_GPIO36_                0
#define DRV_GPIO_MUX_GPIO36_                0
#define DRV_GPIO_MUX_GPIO36_                0

/** \} */


/** \name GPIO37 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO37_GPIO            0
#define DRV_GPIO_MUX_GPIO37_                0
#define DRV_GPIO_MUX_GPIO37_                0
#define DRV_GPIO_MUX_GPIO37_                0
#define DRV_GPIO_MUX_GPIO37_                0
#define DRV_GPIO_MUX_GPIO37_                0
#define DRV_GPIO_MUX_GPIO37_                0
#define DRV_GPIO_MUX_GPIO37_                0

/** \} */


/** \name GPIO38 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO38_GPIO            0
#define DRV_GPIO_MUX_GPIO38_                0
#define DRV_GPIO_MUX_GPIO38_                0
#define DRV_GPIO_MUX_GPIO38_                0
#define DRV_GPIO_MUX_GPIO38_                0
#define DRV_GPIO_MUX_GPIO38_                0
#define DRV_GPIO_MUX_GPIO38_                0
#define DRV_GPIO_MUX_GPIO38_                0

/** \} */


/** \name GPIO39 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO39_GPIO            0
#define DRV_GPIO_MUX_GPIO39_                0
#define DRV_GPIO_MUX_GPIO39_                0
#define DRV_GPIO_MUX_GPIO39_                0
#define DRV_GPIO_MUX_GPIO39_                0
#define DRV_GPIO_MUX_GPIO39_                0
#define DRV_GPIO_MUX_GPIO39_                0
#define DRV_GPIO_MUX_GPIO39_                0

/** \} */


/** \name GPIO40 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO40_GPIO            0
#define DRV_GPIO_MUX_GPIO40_                0
#define DRV_GPIO_MUX_GPIO40_                0
#define DRV_GPIO_MUX_GPIO40_                0
#define DRV_GPIO_MUX_GPIO40_                0
#define DRV_GPIO_MUX_GPIO40_                0
#define DRV_GPIO_MUX_GPIO40_                0
#define DRV_GPIO_MUX_GPIO40_                0

/** \} */


/** \name GPIO41 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO41_GPIO            0
#define DRV_GPIO_MUX_GPIO41_                0
#define DRV_GPIO_MUX_GPIO41_                0
#define DRV_GPIO_MUX_GPIO41_                0
#define DRV_GPIO_MUX_GPIO41_                0
#define DRV_GPIO_MUX_GPIO41_                0
#define DRV_GPIO_MUX_GPIO41_                0
#define DRV_GPIO_MUX_GPIO41_                0

/** \} */


/** \name GPIO42 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO42_GPIO            0
#define DRV_GPIO_MUX_GPIO42_                0
#define DRV_GPIO_MUX_GPIO42_                0
#define DRV_GPIO_MUX_GPIO42_                0
#define DRV_GPIO_MUX_GPIO42_                0
#define DRV_GPIO_MUX_GPIO42_                0
#define DRV_GPIO_MUX_GPIO42_                0
#define DRV_GPIO_MUX_GPIO42_                0

/** \} */


/** \name GPIO43 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO43_GPIO            0
#define DRV_GPIO_MUX_GPIO43_                0
#define DRV_GPIO_MUX_GPIO43_                0
#define DRV_GPIO_MUX_GPIO43_                0
#define DRV_GPIO_MUX_GPIO43_                0
#define DRV_GPIO_MUX_GPIO43_                0
#define DRV_GPIO_MUX_GPIO43_                0
#define DRV_GPIO_MUX_GPIO43_                0

/** \} */


/** \name GPIO44 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO44_GPIO            0
#define DRV_GPIO_MUX_GPIO44_                0
#define DRV_GPIO_MUX_GPIO44_                0
#define DRV_GPIO_MUX_GPIO44_                0
#define DRV_GPIO_MUX_GPIO44_                0
#define DRV_GPIO_MUX_GPIO44_                0
#define DRV_GPIO_MUX_GPIO44_                0
#define DRV_GPIO_MUX_GPIO44_                0

/** \} */


/** \name GPIO45 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO45_GPIO            0
#define DRV_GPIO_MUX_GPIO45_                0
#define DRV_GPIO_MUX_GPIO45_                0
#define DRV_GPIO_MUX_GPIO45_                0
#define DRV_GPIO_MUX_GPIO45_                0
#define DRV_GPIO_MUX_GPIO45_                0
#define DRV_GPIO_MUX_GPIO45_                0
#define DRV_GPIO_MUX_GPIO45_                0

/** \} */


/** \name GPIO46 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO46_GPIO            0
#define DRV_GPIO_MUX_GPIO46_                0
#define DRV_GPIO_MUX_GPIO46_                0
#define DRV_GPIO_MUX_GPIO46_                0
#define DRV_GPIO_MUX_GPIO46_                0
#define DRV_GPIO_MUX_GPIO46_                0
#define DRV_GPIO_MUX_GPIO46_                0
#define DRV_GPIO_MUX_GPIO46_                0

/** \} */


/** \name GPIO47 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO47_GPIO            0
#define DRV_GPIO_MUX_GPIO47_                0
#define DRV_GPIO_MUX_GPIO47_                0
#define DRV_GPIO_MUX_GPIO47_                0
#define DRV_GPIO_MUX_GPIO47_                0
#define DRV_GPIO_MUX_GPIO47_                0
#define DRV_GPIO_MUX_GPIO47_                0
#define DRV_GPIO_MUX_GPIO47_                0

/** \} */


/** \name GPIO48 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO48_GPIO            0
#define DRV_GPIO_MUX_GPIO48_                0
#define DRV_GPIO_MUX_GPIO48_                0
#define DRV_GPIO_MUX_GPIO48_                0
#define DRV_GPIO_MUX_GPIO48_                0
#define DRV_GPIO_MUX_GPIO48_                0
#define DRV_GPIO_MUX_GPIO48_                0
#define DRV_GPIO_MUX_GPIO48_                0

/** \} */


/** \name GPIO49 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO49_GPIO            0
#define DRV_GPIO_MUX_GPIO49_                0
#define DRV_GPIO_MUX_GPIO49_                0
#define DRV_GPIO_MUX_GPIO49_                0
#define DRV_GPIO_MUX_GPIO49_                0
#define DRV_GPIO_MUX_GPIO49_                0
#define DRV_GPIO_MUX_GPIO49_                0
#define DRV_GPIO_MUX_GPIO49_                0

/** \} */


/** \name GPIO50 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO50_GPIO            0
#define DRV_GPIO_MUX_GPIO50_                0
#define DRV_GPIO_MUX_GPIO50_                0
#define DRV_GPIO_MUX_GPIO50_                0
#define DRV_GPIO_MUX_GPIO50_                0
#define DRV_GPIO_MUX_GPIO50_                0
#define DRV_GPIO_MUX_GPIO50_                0
#define DRV_GPIO_MUX_GPIO50_                0

/** \} */


/** \name GPIO51 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO51_GPIO            0
#define DRV_GPIO_MUX_GPIO51_                0
#define DRV_GPIO_MUX_GPIO51_                0
#define DRV_GPIO_MUX_GPIO51_                0
#define DRV_GPIO_MUX_GPIO51_                0
#define DRV_GPIO_MUX_GPIO51_                0
#define DRV_GPIO_MUX_GPIO51_                0
#define DRV_GPIO_MUX_GPIO51_                0

/** \} */


/** \name GPIO52 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO52_GPIO            0
#define DRV_GPIO_MUX_GPIO52_                0
#define DRV_GPIO_MUX_GPIO52_                0
#define DRV_GPIO_MUX_GPIO52_                0
#define DRV_GPIO_MUX_GPIO52_                0
#define DRV_GPIO_MUX_GPIO52_                0
#define DRV_GPIO_MUX_GPIO52_                0
#define DRV_GPIO_MUX_GPIO52_                0

/** \} */


/** \name GPIO53 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO53_GPIO            0
#define DRV_GPIO_MUX_GPIO53_                0
#define DRV_GPIO_MUX_GPIO53_                0
#define DRV_GPIO_MUX_GPIO53_                0
#define DRV_GPIO_MUX_GPIO53_                0
#define DRV_GPIO_MUX_GPIO53_                0
#define DRV_GPIO_MUX_GPIO53_                0
#define DRV_GPIO_MUX_GPIO53_                0

/** \} */


/** \name GPIO54 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO54_GPIO            0
#define DRV_GPIO_MUX_GPIO54_                0
#define DRV_GPIO_MUX_GPIO54_                0
#define DRV_GPIO_MUX_GPIO54_                0
#define DRV_GPIO_MUX_GPIO54_                0
#define DRV_GPIO_MUX_GPIO54_                0
#define DRV_GPIO_MUX_GPIO54_                0
#define DRV_GPIO_MUX_GPIO54_                0

/** \} */


/** \name GPIO55 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO55_GPIO            0
#define DRV_GPIO_MUX_GPIO55_                0
#define DRV_GPIO_MUX_GPIO55_                0
#define DRV_GPIO_MUX_GPIO55_                0
#define DRV_GPIO_MUX_GPIO55_                0
#define DRV_GPIO_MUX_GPIO55_                0
#define DRV_GPIO_MUX_GPIO55_                0
#define DRV_GPIO_MUX_GPIO55_                0

/** \} */


/** \name GPIO56 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO56_GPIO            0
#define DRV_GPIO_MUX_GPIO56_                0
#define DRV_GPIO_MUX_GPIO56_                0
#define DRV_GPIO_MUX_GPIO56_                0
#define DRV_GPIO_MUX_GPIO56_                0
#define DRV_GPIO_MUX_GPIO56_                0
#define DRV_GPIO_MUX_GPIO56_                0
#define DRV_GPIO_MUX_GPIO56_                0

/** \} */


/** \name GPIO57 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO57_GPIO            0
#define DRV_GPIO_MUX_GPIO57_                0
#define DRV_GPIO_MUX_GPIO57_                0
#define DRV_GPIO_MUX_GPIO57_                0
#define DRV_GPIO_MUX_GPIO57_                0
#define DRV_GPIO_MUX_GPIO57_                0
#define DRV_GPIO_MUX_GPIO57_                0
#define DRV_GPIO_MUX_GPIO57_                0

/** \} */


/** \name GPIO58 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO58_GPIO            0
#define DRV_GPIO_MUX_GPIO58_MCLKRA          1
#define DRV_GPIO_MUX_GPIO58_EM1D26          2
#define DRV_GPIO_MUX_GPIO58_EM2D10          3
#define DRV_GPIO_MUX_GPIO58_OUTPUTXBAR1     5
#define DRV_GPIO_MUX_GPIO58_SPICLKB         6
#define DRV_GPIO_MUX_GPIO58_SD2_D2          7
#define DRV_GPIO_MUX_GPIO58_SPISIMOA        15

/** \} */


/** \name GPIO59 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO59_GPIO            0
#define DRV_GPIO_MUX_GPIO59_MFSRA           1
#define DRV_GPIO_MUX_GPIO59_EM1D25          2
#define DRV_GPIO_MUX_GPIO59_EM2D9           3
#define DRV_GPIO_MUX_GPIO59_OUTPUTXBAR2     5
#define DRV_GPIO_MUX_GPIO59_SPISTEB         6
#define DRV_GPIO_MUX_GPIO59_SD2_C2          7
#define DRV_GPIO_MUX_GPIO59_SPISOMIA        15

/** \} */


/** \name GPIO60 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO60_GPIO            0
#define DRV_GPIO_MUX_GPIO60_MCLKRB          1
#define DRV_GPIO_MUX_GPIO60_EM1D24          2
#define DRV_GPIO_MUX_GPIO60_EM2D8           3
#define DRV_GPIO_MUX_GPIO60_OUTPUTXBAR3     5
#define DRV_GPIO_MUX_GPIO60_SPISIMOB        6
#define DRV_GPIO_MUX_GPIO60_SD2_D3          7
#define DRV_GPIO_MUX_GPIO60_SPICLKA         15

/** \} */


/** \name GPIO61 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO61_GPIO            0
#define DRV_GPIO_MUX_GPIO61_MFSRB           1
#define DRV_GPIO_MUX_GPIO61_EM1D23          2
#define DRV_GPIO_MUX_GPIO61_EM2D7           3
#define DRV_GPIO_MUX_GPIO61_OUTPUTXBAR4     5
#define DRV_GPIO_MUX_GPIO61_SPISOMIB        6
#define DRV_GPIO_MUX_GPIO61_SD2_C3          7
#define DRV_GPIO_MUX_GPIO61_SPISTEA         15

/** \} */


/** \name GPIO62 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO62_GPIO            0
#define DRV_GPIO_MUX_GPIO62_                0
#define DRV_GPIO_MUX_GPIO62_                0
#define DRV_GPIO_MUX_GPIO62_                0
#define DRV_GPIO_MUX_GPIO62_                0
#define DRV_GPIO_MUX_GPIO62_                0
#define DRV_GPIO_MUX_GPIO62_                0
#define DRV_GPIO_MUX_GPIO62_                0

/** \} */


/** \name GPIO63 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO63_GPIO            0
#define DRV_GPIO_MUX_GPIO63_SCItXDC         1
#define DRV_GPIO_MUX_GPIO63_EM1D21          2
#define DRV_GPIO_MUX_GPIO63_EM2D5           3
#define DRV_GPIO_MUX_GPIO63_EQEP3B          5
#define DRV_GPIO_MUX_GPIO63_CANTXA          6
#define DRV_GPIO_MUX_GPIO63_SD2_C4          7
#define DRV_GPIO_MUX_GPIO63_SPISIMOB        15

/** \} */


/** \name GPIO64 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO64_GPIO            0
#define DRV_GPIO_MUX_GPIO64_EM1D20          2
#define DRV_GPIO_MUX_GPIO64_EM2D4           3
#define DRV_GPIO_MUX_GPIO64_EQEP3S          5
#define DRV_GPIO_MUX_GPIO64_SCIRXDA         6
#define DRV_GPIO_MUX_GPIO64_SPISOMIB        15

/** \} */


/** \name GPIO65 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO65_GPIO            0
#define DRV_GPIO_MUX_GPIO65_EM1D19          2
#define DRV_GPIO_MUX_GPIO65_EM2D3           3
#define DRV_GPIO_MUX_GPIO65_EQEP3I          5
#define DRV_GPIO_MUX_GPIO65_SCITXDA         6
#define DRV_GPIO_MUX_GPIO65_SPICLKB         15

/** \} */


/** \name GPIO66 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO66_GPIO            0
#define DRV_GPIO_MUX_GPIO66_EM1D18          2
#define DRV_GPIO_MUX_GPIO66_EM2D2           3
#define DRV_GPIO_MUX_GPIO66_I2CSDAB         6
#define DRV_GPIO_MUX_GPIO66_SPISTEB         15

/** \} */


/** \name GPIO67 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO67_GPIO            0
#define DRV_GPIO_MUX_GPIO67_                0
#define DRV_GPIO_MUX_GPIO67_                0
#define DRV_GPIO_MUX_GPIO67_                0
#define DRV_GPIO_MUX_GPIO67_                0
#define DRV_GPIO_MUX_GPIO67_                0
#define DRV_GPIO_MUX_GPIO67_                0
#define DRV_GPIO_MUX_GPIO67_                0

/** \} */


/** \name GPIO68 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO68_GPIO            0
#define DRV_GPIO_MUX_GPIO68_                0
#define DRV_GPIO_MUX_GPIO68_                0
#define DRV_GPIO_MUX_GPIO68_                0
#define DRV_GPIO_MUX_GPIO68_                0
#define DRV_GPIO_MUX_GPIO68_                0
#define DRV_GPIO_MUX_GPIO68_                0
#define DRV_GPIO_MUX_GPIO68_                0

/** \} */


/** \name GPIO69 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO69_GPIO            0
#define DRV_GPIO_MUX_GPIO69_                0
#define DRV_GPIO_MUX_GPIO69_                0
#define DRV_GPIO_MUX_GPIO69_                0
#define DRV_GPIO_MUX_GPIO69_                0
#define DRV_GPIO_MUX_GPIO69_                0
#define DRV_GPIO_MUX_GPIO69_                0
#define DRV_GPIO_MUX_GPIO69_                0

/** \} */


/** \name GPIO70 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO70_GPIO            0
#define DRV_GPIO_MUX_GPIO70_                0
#define DRV_GPIO_MUX_GPIO70_                0
#define DRV_GPIO_MUX_GPIO70_                0
#define DRV_GPIO_MUX_GPIO70_                0
#define DRV_GPIO_MUX_GPIO70_                0
#define DRV_GPIO_MUX_GPIO70_                0
#define DRV_GPIO_MUX_GPIO70_                0

/** \} */


/** \name GPIO71 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO71_GPIO            0
#define DRV_GPIO_MUX_GPIO71_                0
#define DRV_GPIO_MUX_GPIO71_                0
#define DRV_GPIO_MUX_GPIO71_                0
#define DRV_GPIO_MUX_GPIO71_                0
#define DRV_GPIO_MUX_GPIO71_                0
#define DRV_GPIO_MUX_GPIO71_                0
#define DRV_GPIO_MUX_GPIO71_                0

/** \} */


/** \name GPIO72 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO72_GPIO            0
#define DRV_GPIO_MUX_GPIO72_                0
#define DRV_GPIO_MUX_GPIO72_                0
#define DRV_GPIO_MUX_GPIO72_                0
#define DRV_GPIO_MUX_GPIO72_                0
#define DRV_GPIO_MUX_GPIO72_                0
#define DRV_GPIO_MUX_GPIO72_                0
#define DRV_GPIO_MUX_GPIO72_                0

/** \} */


/** \name GPIO73 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO73_GPIO            0
#define DRV_GPIO_MUX_GPIO73_                0
#define DRV_GPIO_MUX_GPIO73_                0
#define DRV_GPIO_MUX_GPIO73_                0
#define DRV_GPIO_MUX_GPIO73_                0
#define DRV_GPIO_MUX_GPIO73_                0
#define DRV_GPIO_MUX_GPIO73_                0
#define DRV_GPIO_MUX_GPIO73_                0

/** \} */


/** \name GPIO74 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO74_GPIO            0
#define DRV_GPIO_MUX_GPIO74_                0
#define DRV_GPIO_MUX_GPIO74_                0
#define DRV_GPIO_MUX_GPIO74_                0
#define DRV_GPIO_MUX_GPIO74_                0
#define DRV_GPIO_MUX_GPIO74_                0
#define DRV_GPIO_MUX_GPIO74_                0
#define DRV_GPIO_MUX_GPIO74_                0

/** \} */


/** \name GPIO75 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO75_GPIO            0
#define DRV_GPIO_MUX_GPIO75_                0
#define DRV_GPIO_MUX_GPIO75_                0
#define DRV_GPIO_MUX_GPIO75_                0
#define DRV_GPIO_MUX_GPIO75_                0
#define DRV_GPIO_MUX_GPIO75_                0
#define DRV_GPIO_MUX_GPIO75_                0
#define DRV_GPIO_MUX_GPIO75_                0

/** \} */


/** \name GPIO76 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO76_GPIO            0
#define DRV_GPIO_MUX_GPIO76_                0
#define DRV_GPIO_MUX_GPIO76_                0
#define DRV_GPIO_MUX_GPIO76_                0
#define DRV_GPIO_MUX_GPIO76_                0
#define DRV_GPIO_MUX_GPIO76_                0
#define DRV_GPIO_MUX_GPIO76_                0
#define DRV_GPIO_MUX_GPIO76_                0

/** \} */


/** \name GPIO77 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO77_GPIO            0
#define DRV_GPIO_MUX_GPIO77_                0
#define DRV_GPIO_MUX_GPIO77_                0
#define DRV_GPIO_MUX_GPIO77_                0
#define DRV_GPIO_MUX_GPIO77_                0
#define DRV_GPIO_MUX_GPIO77_                0
#define DRV_GPIO_MUX_GPIO77_                0
#define DRV_GPIO_MUX_GPIO77_                0

/** \} */


/** \name GPIO78 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO78_GPIO            0
#define DRV_GPIO_MUX_GPIO78_                0
#define DRV_GPIO_MUX_GPIO78_                0
#define DRV_GPIO_MUX_GPIO78_                0
#define DRV_GPIO_MUX_GPIO78_                0
#define DRV_GPIO_MUX_GPIO78_                0
#define DRV_GPIO_MUX_GPIO78_                0
#define DRV_GPIO_MUX_GPIO78_                0

/** \} */


/** \name GPIO79 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO79_GPIO            0
#define DRV_GPIO_MUX_GPIO79_                0
#define DRV_GPIO_MUX_GPIO79_                0
#define DRV_GPIO_MUX_GPIO79_                0
#define DRV_GPIO_MUX_GPIO79_                0
#define DRV_GPIO_MUX_GPIO79_                0
#define DRV_GPIO_MUX_GPIO79_                0
#define DRV_GPIO_MUX_GPIO79_                0

/** \} */


/** \name GPIO80 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO80_GPIO            0
#define DRV_GPIO_MUX_GPIO80_                0
#define DRV_GPIO_MUX_GPIO80_                0
#define DRV_GPIO_MUX_GPIO80_                0
#define DRV_GPIO_MUX_GPIO80_                0
#define DRV_GPIO_MUX_GPIO80_                0
#define DRV_GPIO_MUX_GPIO80_                0
#define DRV_GPIO_MUX_GPIO80_                0

/** \} */


/** \name GPIO81 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO81_GPIO            0
#define DRV_GPIO_MUX_GPIO81_                0
#define DRV_GPIO_MUX_GPIO81_                0
#define DRV_GPIO_MUX_GPIO81_                0
#define DRV_GPIO_MUX_GPIO81_                0
#define DRV_GPIO_MUX_GPIO81_                0
#define DRV_GPIO_MUX_GPIO81_                0
#define DRV_GPIO_MUX_GPIO81_                0

/** \} */


/** \name GPIO82 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO82_GPIO            0
#define DRV_GPIO_MUX_GPIO82_                0
#define DRV_GPIO_MUX_GPIO82_                0
#define DRV_GPIO_MUX_GPIO82_                0
#define DRV_GPIO_MUX_GPIO82_                0
#define DRV_GPIO_MUX_GPIO82_                0
#define DRV_GPIO_MUX_GPIO82_                0
#define DRV_GPIO_MUX_GPIO82_                0

/** \} */


/** \name GPIO83 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO83_GPIO            0
#define DRV_GPIO_MUX_GPIO83_                0
#define DRV_GPIO_MUX_GPIO83_                0
#define DRV_GPIO_MUX_GPIO83_                0
#define DRV_GPIO_MUX_GPIO83_                0
#define DRV_GPIO_MUX_GPIO83_                0
#define DRV_GPIO_MUX_GPIO83_                0
#define DRV_GPIO_MUX_GPIO83_                0

/** \} */


/** \name GPIO84 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO84_GPIO            0
#define DRV_GPIO_MUX_GPIO84_                0
#define DRV_GPIO_MUX_GPIO84_                0
#define DRV_GPIO_MUX_GPIO84_                0
#define DRV_GPIO_MUX_GPIO84_                0
#define DRV_GPIO_MUX_GPIO84_                0
#define DRV_GPIO_MUX_GPIO84_                0
#define DRV_GPIO_MUX_GPIO84_                0

/** \} */


/** \name GPIO85 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO85_GPIO            0
#define DRV_GPIO_MUX_GPIO85_                0
#define DRV_GPIO_MUX_GPIO85_                0
#define DRV_GPIO_MUX_GPIO85_                0
#define DRV_GPIO_MUX_GPIO85_                0
#define DRV_GPIO_MUX_GPIO85_                0
#define DRV_GPIO_MUX_GPIO85_                0
#define DRV_GPIO_MUX_GPIO85_                0

/** \} */


/** \name GPIO86 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO86_GPIO            0
#define DRV_GPIO_MUX_GPIO86_                0
#define DRV_GPIO_MUX_GPIO86_                0
#define DRV_GPIO_MUX_GPIO86_                0
#define DRV_GPIO_MUX_GPIO86_                0
#define DRV_GPIO_MUX_GPIO86_                0
#define DRV_GPIO_MUX_GPIO86_                0
#define DRV_GPIO_MUX_GPIO86_                0

/** \} */


/** \name GPIO87 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO87_GPIO            0
#define DRV_GPIO_MUX_GPIO87_                0
#define DRV_GPIO_MUX_GPIO87_                0
#define DRV_GPIO_MUX_GPIO87_                0
#define DRV_GPIO_MUX_GPIO87_                0
#define DRV_GPIO_MUX_GPIO87_                0
#define DRV_GPIO_MUX_GPIO87_                0
#define DRV_GPIO_MUX_GPIO87_                0

/** \} */


/** \name GPIO88 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO88_GPIO            0
#define DRV_GPIO_MUX_GPIO88_                0
#define DRV_GPIO_MUX_GPIO88_                0
#define DRV_GPIO_MUX_GPIO88_                0
#define DRV_GPIO_MUX_GPIO88_                0
#define DRV_GPIO_MUX_GPIO88_                0
#define DRV_GPIO_MUX_GPIO88_                0
#define DRV_GPIO_MUX_GPIO88_                0

/** \} */


/** \name GPIO89 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO89_GPIO            0
#define DRV_GPIO_MUX_GPIO89_                0
#define DRV_GPIO_MUX_GPIO89_                0
#define DRV_GPIO_MUX_GPIO89_                0
#define DRV_GPIO_MUX_GPIO89_                0
#define DRV_GPIO_MUX_GPIO89_                0
#define DRV_GPIO_MUX_GPIO89_                0
#define DRV_GPIO_MUX_GPIO89_                0

/** \} */


/** \name GPIO90 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO90_GPIO            0
#define DRV_GPIO_MUX_GPIO90_                0
#define DRV_GPIO_MUX_GPIO90_                0
#define DRV_GPIO_MUX_GPIO90_                0
#define DRV_GPIO_MUX_GPIO90_                0
#define DRV_GPIO_MUX_GPIO90_                0
#define DRV_GPIO_MUX_GPIO90_                0
#define DRV_GPIO_MUX_GPIO90_                0

/** \} */


/** \name GPIO91 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO91_GPIO            0
#define DRV_GPIO_MUX_GPIO91_                0
#define DRV_GPIO_MUX_GPIO91_                0
#define DRV_GPIO_MUX_GPIO91_                0
#define DRV_GPIO_MUX_GPIO91_                0
#define DRV_GPIO_MUX_GPIO91_                0
#define DRV_GPIO_MUX_GPIO91_                0
#define DRV_GPIO_MUX_GPIO91_                0

/** \} */


/** \name GPIO92 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO92_GPIO            0
#define DRV_GPIO_MUX_GPIO92_                0
#define DRV_GPIO_MUX_GPIO92_                0
#define DRV_GPIO_MUX_GPIO92_                0
#define DRV_GPIO_MUX_GPIO92_                0
#define DRV_GPIO_MUX_GPIO92_                0
#define DRV_GPIO_MUX_GPIO92_                0
#define DRV_GPIO_MUX_GPIO92_                0

/** \} */


/** \name GPIO93 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO93_GPIO            0
#define DRV_GPIO_MUX_GPIO93_                0
#define DRV_GPIO_MUX_GPIO93_                0
#define DRV_GPIO_MUX_GPIO93_                0
#define DRV_GPIO_MUX_GPIO93_                0
#define DRV_GPIO_MUX_GPIO93_                0
#define DRV_GPIO_MUX_GPIO93_                0
#define DRV_GPIO_MUX_GPIO93_                0

/** \} */


/** \name GPIO94 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO94_GPIO            0
#define DRV_GPIO_MUX_GPIO94_                0
#define DRV_GPIO_MUX_GPIO94_                0
#define DRV_GPIO_MUX_GPIO94_                0
#define DRV_GPIO_MUX_GPIO94_                0
#define DRV_GPIO_MUX_GPIO94_                0
#define DRV_GPIO_MUX_GPIO94_                0
#define DRV_GPIO_MUX_GPIO94_                0

/** \} */


/** \name GPIO95 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO95_GPIO            0
#define DRV_GPIO_MUX_GPIO95_                0
#define DRV_GPIO_MUX_GPIO95_                0
#define DRV_GPIO_MUX_GPIO95_                0
#define DRV_GPIO_MUX_GPIO95_                0
#define DRV_GPIO_MUX_GPIO95_                0
#define DRV_GPIO_MUX_GPIO95_                0
#define DRV_GPIO_MUX_GPIO95_                0

/** \} */


/** \name GPIO96 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO96_GPIO            0
#define DRV_GPIO_MUX_GPIO96_                0
#define DRV_GPIO_MUX_GPIO96_                0
#define DRV_GPIO_MUX_GPIO96_                0
#define DRV_GPIO_MUX_GPIO96_                0
#define DRV_GPIO_MUX_GPIO96_                0
#define DRV_GPIO_MUX_GPIO96_                0
#define DRV_GPIO_MUX_GPIO96_                0

/** \} */


/** \name GPIO97 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO97_GPIO            0
#define DRV_GPIO_MUX_GPIO97_                0
#define DRV_GPIO_MUX_GPIO97_                0
#define DRV_GPIO_MUX_GPIO97_                0
#define DRV_GPIO_MUX_GPIO97_                0
#define DRV_GPIO_MUX_GPIO97_                0
#define DRV_GPIO_MUX_GPIO97_                0
#define DRV_GPIO_MUX_GPIO97_                0

/** \} */


/** \name GPIO98 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO98_GPIO            0
#define DRV_GPIO_MUX_GPIO98_                0
#define DRV_GPIO_MUX_GPIO98_                0
#define DRV_GPIO_MUX_GPIO98_                0
#define DRV_GPIO_MUX_GPIO98_                0
#define DRV_GPIO_MUX_GPIO98_                0
#define DRV_GPIO_MUX_GPIO98_                0
#define DRV_GPIO_MUX_GPIO98_                0

/** \} */


/** \name GPIO99 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO99_GPIO            0
#define DRV_GPIO_MUX_GPIO99_                0
#define DRV_GPIO_MUX_GPIO99_                0
#define DRV_GPIO_MUX_GPIO99_                0
#define DRV_GPIO_MUX_GPIO99_                0
#define DRV_GPIO_MUX_GPIO99_                0
#define DRV_GPIO_MUX_GPIO99_                0
#define DRV_GPIO_MUX_GPIO99_                0

/** \} */


/** \name GPIO100 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO100_GPIO           0
#define DRV_GPIO_MUX_GPIO100_               0
#define DRV_GPIO_MUX_GPIO100_               0
#define DRV_GPIO_MUX_GPIO100_               0
#define DRV_GPIO_MUX_GPIO100_               0
#define DRV_GPIO_MUX_GPIO100_               0
#define DRV_GPIO_MUX_GPIO100_               0
#define DRV_GPIO_MUX_GPIO100_               0

/** \} */


/** \name GPIO101 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO101_GPIO           0
#define DRV_GPIO_MUX_GPIO101_               0
#define DRV_GPIO_MUX_GPIO101_               0
#define DRV_GPIO_MUX_GPIO101_               0
#define DRV_GPIO_MUX_GPIO101_               0
#define DRV_GPIO_MUX_GPIO101_               0
#define DRV_GPIO_MUX_GPIO101_               0
#define DRV_GPIO_MUX_GPIO101_               0

/** \} */


/** \name GPIO102 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO102_GPIO           0
#define DRV_GPIO_MUX_GPIO102_               0
#define DRV_GPIO_MUX_GPIO102_               0
#define DRV_GPIO_MUX_GPIO102_               0
#define DRV_GPIO_MUX_GPIO102_               0
#define DRV_GPIO_MUX_GPIO102_               0
#define DRV_GPIO_MUX_GPIO102_               0
#define DRV_GPIO_MUX_GPIO102_               0

/** \} */


/** \name GPIO103 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO103_GPIO           0
#define DRV_GPIO_MUX_GPIO103_               0
#define DRV_GPIO_MUX_GPIO103_               0
#define DRV_GPIO_MUX_GPIO103_               0
#define DRV_GPIO_MUX_GPIO103_               0
#define DRV_GPIO_MUX_GPIO103_               0
#define DRV_GPIO_MUX_GPIO103_               0
#define DRV_GPIO_MUX_GPIO103_               0

/** \} */


/** \name GPIO104 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO104_GPIO           0
#define DRV_GPIO_MUX_GPIO104_               0
#define DRV_GPIO_MUX_GPIO104_               0
#define DRV_GPIO_MUX_GPIO104_               0
#define DRV_GPIO_MUX_GPIO104_               0
#define DRV_GPIO_MUX_GPIO104_               0
#define DRV_GPIO_MUX_GPIO104_               0
#define DRV_GPIO_MUX_GPIO104_               0

/** \} */


/** \name GPIO105 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO105_GPIO           0
#define DRV_GPIO_MUX_GPIO105_               0
#define DRV_GPIO_MUX_GPIO105_               0
#define DRV_GPIO_MUX_GPIO105_               0
#define DRV_GPIO_MUX_GPIO105_               0
#define DRV_GPIO_MUX_GPIO105_               0
#define DRV_GPIO_MUX_GPIO105_               0
#define DRV_GPIO_MUX_GPIO105_               0

/** \} */


/** \name GPIO106 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO106_GPIO           0
#define DRV_GPIO_MUX_GPIO106_               0
#define DRV_GPIO_MUX_GPIO106_               0
#define DRV_GPIO_MUX_GPIO106_               0
#define DRV_GPIO_MUX_GPIO106_               0
#define DRV_GPIO_MUX_GPIO106_               0
#define DRV_GPIO_MUX_GPIO106_               0
#define DRV_GPIO_MUX_GPIO106_               0

/** \} */


/** \name GPIO107 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO107_GPIO           0
#define DRV_GPIO_MUX_GPIO107_               0
#define DRV_GPIO_MUX_GPIO107_               0
#define DRV_GPIO_MUX_GPIO107_               0
#define DRV_GPIO_MUX_GPIO107_               0
#define DRV_GPIO_MUX_GPIO107_               0
#define DRV_GPIO_MUX_GPIO107_               0
#define DRV_GPIO_MUX_GPIO107_               0

/** \} */


/** \name GPIO108 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO108_GPIO           0
#define DRV_GPIO_MUX_GPIO108_               0
#define DRV_GPIO_MUX_GPIO108_               0
#define DRV_GPIO_MUX_GPIO108_               0
#define DRV_GPIO_MUX_GPIO108_               0
#define DRV_GPIO_MUX_GPIO108_               0
#define DRV_GPIO_MUX_GPIO108_               0
#define DRV_GPIO_MUX_GPIO108_               0

/** \} */


/** \name GPIO109 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO109_GPIO           0
#define DRV_GPIO_MUX_GPIO109_               0
#define DRV_GPIO_MUX_GPIO109_               0
#define DRV_GPIO_MUX_GPIO109_               0
#define DRV_GPIO_MUX_GPIO109_               0
#define DRV_GPIO_MUX_GPIO109_               0
#define DRV_GPIO_MUX_GPIO109_               0
#define DRV_GPIO_MUX_GPIO109_               0

/** \} */


/** \name GPIO110 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO110_GPIO           0
#define DRV_GPIO_MUX_GPIO110_               0
#define DRV_GPIO_MUX_GPIO110_               0
#define DRV_GPIO_MUX_GPIO110_               0
#define DRV_GPIO_MUX_GPIO110_               0
#define DRV_GPIO_MUX_GPIO110_               0
#define DRV_GPIO_MUX_GPIO110_               0
#define DRV_GPIO_MUX_GPIO110_               0

/** \} */


/** \name GPIO111 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO111_GPIO           0
#define DRV_GPIO_MUX_GPIO111_               0
#define DRV_GPIO_MUX_GPIO111_               0
#define DRV_GPIO_MUX_GPIO111_               0
#define DRV_GPIO_MUX_GPIO111_               0
#define DRV_GPIO_MUX_GPIO111_               0
#define DRV_GPIO_MUX_GPIO111_               0
#define DRV_GPIO_MUX_GPIO111_               0

/** \} */


/** \name GPIO112 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO112_GPIO           0
#define DRV_GPIO_MUX_GPIO112_               0
#define DRV_GPIO_MUX_GPIO112_               0
#define DRV_GPIO_MUX_GPIO112_               0
#define DRV_GPIO_MUX_GPIO112_               0
#define DRV_GPIO_MUX_GPIO112_               0
#define DRV_GPIO_MUX_GPIO112_               0
#define DRV_GPIO_MUX_GPIO112_               0

/** \} */


/** \name GPIO113 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO113_GPIO           0
#define DRV_GPIO_MUX_GPIO113_               0
#define DRV_GPIO_MUX_GPIO113_               0
#define DRV_GPIO_MUX_GPIO113_               0
#define DRV_GPIO_MUX_GPIO113_               0
#define DRV_GPIO_MUX_GPIO113_               0
#define DRV_GPIO_MUX_GPIO113_               0
#define DRV_GPIO_MUX_GPIO113_               0

/** \} */


/** \name GPIO114 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO114_GPIO           0
#define DRV_GPIO_MUX_GPIO114_               0
#define DRV_GPIO_MUX_GPIO114_               0
#define DRV_GPIO_MUX_GPIO114_               0
#define DRV_GPIO_MUX_GPIO114_               0
#define DRV_GPIO_MUX_GPIO114_               0
#define DRV_GPIO_MUX_GPIO114_               0
#define DRV_GPIO_MUX_GPIO114_               0

/** \} */


/** \name GPIO115 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO115_GPIO           0
#define DRV_GPIO_MUX_GPIO115_               0
#define DRV_GPIO_MUX_GPIO115_               0
#define DRV_GPIO_MUX_GPIO115_               0
#define DRV_GPIO_MUX_GPIO115_               0
#define DRV_GPIO_MUX_GPIO115_               0
#define DRV_GPIO_MUX_GPIO115_               0
#define DRV_GPIO_MUX_GPIO115_               0

/** \} */


/** \name GPIO116 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO116_GPIO           0
#define DRV_GPIO_MUX_GPIO116_               0
#define DRV_GPIO_MUX_GPIO116_               0
#define DRV_GPIO_MUX_GPIO116_               0
#define DRV_GPIO_MUX_GPIO116_               0
#define DRV_GPIO_MUX_GPIO116_               0
#define DRV_GPIO_MUX_GPIO116_               0
#define DRV_GPIO_MUX_GPIO116_               0

/** \} */


/** \name GPIO117 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO117_GPIO           0
#define DRV_GPIO_MUX_GPIO117_               0
#define DRV_GPIO_MUX_GPIO117_               0
#define DRV_GPIO_MUX_GPIO117_               0
#define DRV_GPIO_MUX_GPIO117_               0
#define DRV_GPIO_MUX_GPIO117_               0
#define DRV_GPIO_MUX_GPIO117_               0
#define DRV_GPIO_MUX_GPIO117_               0

/** \} */


/** \name GPIO118 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO118_GPIO           0
#define DRV_GPIO_MUX_GPIO118_               0
#define DRV_GPIO_MUX_GPIO118_               0
#define DRV_GPIO_MUX_GPIO118_               0
#define DRV_GPIO_MUX_GPIO118_               0
#define DRV_GPIO_MUX_GPIO118_               0
#define DRV_GPIO_MUX_GPIO118_               0
#define DRV_GPIO_MUX_GPIO118_               0

/** \} */


/** \name GPIO119 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO119_GPIO           0
#define DRV_GPIO_MUX_GPIO119_               0
#define DRV_GPIO_MUX_GPIO119_               0
#define DRV_GPIO_MUX_GPIO119_               0
#define DRV_GPIO_MUX_GPIO119_               0
#define DRV_GPIO_MUX_GPIO119_               0
#define DRV_GPIO_MUX_GPIO119_               0
#define DRV_GPIO_MUX_GPIO119_               0

/** \} */


/** \name GPIO120 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO120_GPIO           0
#define DRV_GPIO_MUX_GPIO120_               0
#define DRV_GPIO_MUX_GPIO120_               0
#define DRV_GPIO_MUX_GPIO120_               0
#define DRV_GPIO_MUX_GPIO120_               0
#define DRV_GPIO_MUX_GPIO120_               0
#define DRV_GPIO_MUX_GPIO120_               0
#define DRV_GPIO_MUX_GPIO120_               0

/** \} */


/** \name GPIO121 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO121_GPIO           0
#define DRV_GPIO_MUX_GPIO121_               0
#define DRV_GPIO_MUX_GPIO121_               0
#define DRV_GPIO_MUX_GPIO121_               0
#define DRV_GPIO_MUX_GPIO121_               0
#define DRV_GPIO_MUX_GPIO121_               0
#define DRV_GPIO_MUX_GPIO121_               0
#define DRV_GPIO_MUX_GPIO121_               0

/** \} */


/** \name GPIO122 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO122_GPIO           0
#define DRV_GPIO_MUX_GPIO122_               0
#define DRV_GPIO_MUX_GPIO122_               0
#define DRV_GPIO_MUX_GPIO122_               0
#define DRV_GPIO_MUX_GPIO122_               0
#define DRV_GPIO_MUX_GPIO122_               0
#define DRV_GPIO_MUX_GPIO122_               0
#define DRV_GPIO_MUX_GPIO122_               0

/** \} */


/** \name GPIO123 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO123_GPIO           0
#define DRV_GPIO_MUX_GPIO123_               0
#define DRV_GPIO_MUX_GPIO123_               0
#define DRV_GPIO_MUX_GPIO123_               0
#define DRV_GPIO_MUX_GPIO123_               0
#define DRV_GPIO_MUX_GPIO123_               0
#define DRV_GPIO_MUX_GPIO123_               0
#define DRV_GPIO_MUX_GPIO123_               0

/** \} */


/** \name GPIO124 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO124_GPIO           0
#define DRV_GPIO_MUX_GPIO124_               0
#define DRV_GPIO_MUX_GPIO124_               0
#define DRV_GPIO_MUX_GPIO124_               0
#define DRV_GPIO_MUX_GPIO124_               0
#define DRV_GPIO_MUX_GPIO124_               0
#define DRV_GPIO_MUX_GPIO124_               0
#define DRV_GPIO_MUX_GPIO124_               0

/** \} */


/** \name GPIO125 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO125_GPIO           0
#define DRV_GPIO_MUX_GPIO125_               0
#define DRV_GPIO_MUX_GPIO125_               0
#define DRV_GPIO_MUX_GPIO125_               0
#define DRV_GPIO_MUX_GPIO125_               0
#define DRV_GPIO_MUX_GPIO125_               0
#define DRV_GPIO_MUX_GPIO125_               0
#define DRV_GPIO_MUX_GPIO125_               0

/** \} */


/** \name GPIO126 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO126_GPIO           0
#define DRV_GPIO_MUX_GPIO126_               0
#define DRV_GPIO_MUX_GPIO126_               0
#define DRV_GPIO_MUX_GPIO126_               0
#define DRV_GPIO_MUX_GPIO126_               0
#define DRV_GPIO_MUX_GPIO126_               0
#define DRV_GPIO_MUX_GPIO126_               0
#define DRV_GPIO_MUX_GPIO126_               0

/** \} */


/** \name GPIO127 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO127_GPIO           0
#define DRV_GPIO_MUX_GPIO127_               0
#define DRV_GPIO_MUX_GPIO127_               0
#define DRV_GPIO_MUX_GPIO127_               0
#define DRV_GPIO_MUX_GPIO127_               0
#define DRV_GPIO_MUX_GPIO127_               0
#define DRV_GPIO_MUX_GPIO127_               0
#define DRV_GPIO_MUX_GPIO127_               0

/** \} */


/** \name GPIO128 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO128_GPIO           0
#define DRV_GPIO_MUX_GPIO128_               0
#define DRV_GPIO_MUX_GPIO128_               0
#define DRV_GPIO_MUX_GPIO128_               0
#define DRV_GPIO_MUX_GPIO128_               0
#define DRV_GPIO_MUX_GPIO128_               0
#define DRV_GPIO_MUX_GPIO128_               0
#define DRV_GPIO_MUX_GPIO128_               0

/** \} */


/** \name GPIO129 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO129_GPIO           0
#define DRV_GPIO_MUX_GPIO129_               0
#define DRV_GPIO_MUX_GPIO129_               0
#define DRV_GPIO_MUX_GPIO129_               0
#define DRV_GPIO_MUX_GPIO129_               0
#define DRV_GPIO_MUX_GPIO129_               0
#define DRV_GPIO_MUX_GPIO129_               0
#define DRV_GPIO_MUX_GPIO129_               0

/** \} */


/** \name GPIO130 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO130_GPIO           0
#define DRV_GPIO_MUX_GPIO130_               0
#define DRV_GPIO_MUX_GPIO130_               0
#define DRV_GPIO_MUX_GPIO130_               0
#define DRV_GPIO_MUX_GPIO130_               0
#define DRV_GPIO_MUX_GPIO130_               0
#define DRV_GPIO_MUX_GPIO130_               0
#define DRV_GPIO_MUX_GPIO130_               0

/** \} */


/** \name GPIO131 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO131_GPIO           0
#define DRV_GPIO_MUX_GPIO131_               0
#define DRV_GPIO_MUX_GPIO131_               0
#define DRV_GPIO_MUX_GPIO131_               0
#define DRV_GPIO_MUX_GPIO131_               0
#define DRV_GPIO_MUX_GPIO131_               0
#define DRV_GPIO_MUX_GPIO131_               0
#define DRV_GPIO_MUX_GPIO131_               0

/** \} */


/** \name GPIO132 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO132_GPIO           0
#define DRV_GPIO_MUX_GPIO132_               0
#define DRV_GPIO_MUX_GPIO132_               0
#define DRV_GPIO_MUX_GPIO132_               0
#define DRV_GPIO_MUX_GPIO132_               0
#define DRV_GPIO_MUX_GPIO132_               0
#define DRV_GPIO_MUX_GPIO132_               0
#define DRV_GPIO_MUX_GPIO132_               0

/** \} */


/** \name GPIO133 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO133_GPIO           0
#define DRV_GPIO_MUX_GPIO133_               0
#define DRV_GPIO_MUX_GPIO133_               0
#define DRV_GPIO_MUX_GPIO133_               0
#define DRV_GPIO_MUX_GPIO133_               0
#define DRV_GPIO_MUX_GPIO133_               0
#define DRV_GPIO_MUX_GPIO133_               0
#define DRV_GPIO_MUX_GPIO133_               0

/** \} */


/** \name GPIO134 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO134_GPIO           0
#define DRV_GPIO_MUX_GPIO134_               0
#define DRV_GPIO_MUX_GPIO134_               0
#define DRV_GPIO_MUX_GPIO134_               0
#define DRV_GPIO_MUX_GPIO134_               0
#define DRV_GPIO_MUX_GPIO134_               0
#define DRV_GPIO_MUX_GPIO134_               0
#define DRV_GPIO_MUX_GPIO134_               0

/** \} */


/** \name GPIO135 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO135_GPIO           0
#define DRV_GPIO_MUX_GPIO135_               0
#define DRV_GPIO_MUX_GPIO135_               0
#define DRV_GPIO_MUX_GPIO135_               0
#define DRV_GPIO_MUX_GPIO135_               0
#define DRV_GPIO_MUX_GPIO135_               0
#define DRV_GPIO_MUX_GPIO135_               0
#define DRV_GPIO_MUX_GPIO135_               0

/** \} */


/** \name GPIO136 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO136_GPIO           0
#define DRV_GPIO_MUX_GPIO136_               0
#define DRV_GPIO_MUX_GPIO136_               0
#define DRV_GPIO_MUX_GPIO136_               0
#define DRV_GPIO_MUX_GPIO136_               0
#define DRV_GPIO_MUX_GPIO136_               0
#define DRV_GPIO_MUX_GPIO136_               0
#define DRV_GPIO_MUX_GPIO136_               0

/** \} */


/** \name GPIO137 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO137_GPIO           0
#define DRV_GPIO_MUX_GPIO137_               0
#define DRV_GPIO_MUX_GPIO137_               0
#define DRV_GPIO_MUX_GPIO137_               0
#define DRV_GPIO_MUX_GPIO137_               0
#define DRV_GPIO_MUX_GPIO137_               0
#define DRV_GPIO_MUX_GPIO137_               0
#define DRV_GPIO_MUX_GPIO137_               0

/** \} */


/** \name GPIO138 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO138_GPIO           0
#define DRV_GPIO_MUX_GPIO138_               0
#define DRV_GPIO_MUX_GPIO138_               0
#define DRV_GPIO_MUX_GPIO138_               0
#define DRV_GPIO_MUX_GPIO138_               0
#define DRV_GPIO_MUX_GPIO138_               0
#define DRV_GPIO_MUX_GPIO138_               0
#define DRV_GPIO_MUX_GPIO138_               0

/** \} */


/** \name GPIO139 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO139_GPIO           0
#define DRV_GPIO_MUX_GPIO139_               0
#define DRV_GPIO_MUX_GPIO139_               0
#define DRV_GPIO_MUX_GPIO139_               0
#define DRV_GPIO_MUX_GPIO139_               0
#define DRV_GPIO_MUX_GPIO139_               0
#define DRV_GPIO_MUX_GPIO139_               0
#define DRV_GPIO_MUX_GPIO139_               0

/** \} */


/** \name GPIO140 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO140_GPIO           0
#define DRV_GPIO_MUX_GPIO140_               0
#define DRV_GPIO_MUX_GPIO140_               0
#define DRV_GPIO_MUX_GPIO140_               0
#define DRV_GPIO_MUX_GPIO140_               0
#define DRV_GPIO_MUX_GPIO140_               0
#define DRV_GPIO_MUX_GPIO140_               0
#define DRV_GPIO_MUX_GPIO140_               0

/** \} */


/** \name GPIO141 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO141_GPIO           0
#define DRV_GPIO_MUX_GPIO141_               0
#define DRV_GPIO_MUX_GPIO141_               0
#define DRV_GPIO_MUX_GPIO141_               0
#define DRV_GPIO_MUX_GPIO141_               0
#define DRV_GPIO_MUX_GPIO141_               0
#define DRV_GPIO_MUX_GPIO141_               0
#define DRV_GPIO_MUX_GPIO141_               0

/** \} */


/** \name GPIO142 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO142_GPIO           0
#define DRV_GPIO_MUX_GPIO142_               0
#define DRV_GPIO_MUX_GPIO142_               0
#define DRV_GPIO_MUX_GPIO142_               0
#define DRV_GPIO_MUX_GPIO142_               0
#define DRV_GPIO_MUX_GPIO142_               0
#define DRV_GPIO_MUX_GPIO142_               0
#define DRV_GPIO_MUX_GPIO142_               0

/** \} */


/** \name GPIO143 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO143_GPIO           0
#define DRV_GPIO_MUX_GPIO143_               0
#define DRV_GPIO_MUX_GPIO143_               0
#define DRV_GPIO_MUX_GPIO143_               0
#define DRV_GPIO_MUX_GPIO143_               0
#define DRV_GPIO_MUX_GPIO143_               0
#define DRV_GPIO_MUX_GPIO143_               0
#define DRV_GPIO_MUX_GPIO143_               0

/** \} */


/** \name GPIO144 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO144_GPIO           0
#define DRV_GPIO_MUX_GPIO144_               0
#define DRV_GPIO_MUX_GPIO144_               0
#define DRV_GPIO_MUX_GPIO144_               0
#define DRV_GPIO_MUX_GPIO144_               0
#define DRV_GPIO_MUX_GPIO144_               0
#define DRV_GPIO_MUX_GPIO144_               0
#define DRV_GPIO_MUX_GPIO144_               0

/** \} */


/** \name GPIO145 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO145_GPIO           0
#define DRV_GPIO_MUX_GPIO145_               0
#define DRV_GPIO_MUX_GPIO145_               0
#define DRV_GPIO_MUX_GPIO145_               0
#define DRV_GPIO_MUX_GPIO145_               0
#define DRV_GPIO_MUX_GPIO145_               0
#define DRV_GPIO_MUX_GPIO145_               0
#define DRV_GPIO_MUX_GPIO145_               0

/** \} */


/** \name GPIO146 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO146_GPIO           0
#define DRV_GPIO_MUX_GPIO146_               0
#define DRV_GPIO_MUX_GPIO146_               0
#define DRV_GPIO_MUX_GPIO146_               0
#define DRV_GPIO_MUX_GPIO146_               0
#define DRV_GPIO_MUX_GPIO146_               0
#define DRV_GPIO_MUX_GPIO146_               0
#define DRV_GPIO_MUX_GPIO146_               0

/** \} */


/** \name GPIO147 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO147_GPIO           0
#define DRV_GPIO_MUX_GPIO147_               0
#define DRV_GPIO_MUX_GPIO147_               0
#define DRV_GPIO_MUX_GPIO147_               0
#define DRV_GPIO_MUX_GPIO147_               0
#define DRV_GPIO_MUX_GPIO147_               0
#define DRV_GPIO_MUX_GPIO147_               0
#define DRV_GPIO_MUX_GPIO147_               0

/** \} */


/** \name GPIO148 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO148_GPIO           0
#define DRV_GPIO_MUX_GPIO148_               0
#define DRV_GPIO_MUX_GPIO148_               0
#define DRV_GPIO_MUX_GPIO148_               0
#define DRV_GPIO_MUX_GPIO148_               0
#define DRV_GPIO_MUX_GPIO148_               0
#define DRV_GPIO_MUX_GPIO148_               0
#define DRV_GPIO_MUX_GPIO148_               0

/** \} */


/** \name GPIO149 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO149_GPIO           0
#define DRV_GPIO_MUX_GPIO149_               0
#define DRV_GPIO_MUX_GPIO149_               0
#define DRV_GPIO_MUX_GPIO149_               0
#define DRV_GPIO_MUX_GPIO149_               0
#define DRV_GPIO_MUX_GPIO149_               0
#define DRV_GPIO_MUX_GPIO149_               0
#define DRV_GPIO_MUX_GPIO149_               0

/** \} */


/** \name GPIO150 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO150_GPIO           0
#define DRV_GPIO_MUX_GPIO150_               0
#define DRV_GPIO_MUX_GPIO150_               0
#define DRV_GPIO_MUX_GPIO150_               0
#define DRV_GPIO_MUX_GPIO150_               0
#define DRV_GPIO_MUX_GPIO150_               0
#define DRV_GPIO_MUX_GPIO150_               0
#define DRV_GPIO_MUX_GPIO150_               0

/** \} */


/** \name GPIO151 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO151_GPIO           0
#define DRV_GPIO_MUX_GPIO151_               0
#define DRV_GPIO_MUX_GPIO151_               0
#define DRV_GPIO_MUX_GPIO151_               0
#define DRV_GPIO_MUX_GPIO151_               0
#define DRV_GPIO_MUX_GPIO151_               0
#define DRV_GPIO_MUX_GPIO151_               0
#define DRV_GPIO_MUX_GPIO151_               0

/** \} */


/** \name GPIO152 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO152_GPIO           0
#define DRV_GPIO_MUX_GPIO152_               0
#define DRV_GPIO_MUX_GPIO152_               0
#define DRV_GPIO_MUX_GPIO152_               0
#define DRV_GPIO_MUX_GPIO152_               0
#define DRV_GPIO_MUX_GPIO152_               0
#define DRV_GPIO_MUX_GPIO152_               0
#define DRV_GPIO_MUX_GPIO152_               0

/** \} */


/** \name GPIO153 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO153_GPIO           0
#define DRV_GPIO_MUX_GPIO153_               0
#define DRV_GPIO_MUX_GPIO153_               0
#define DRV_GPIO_MUX_GPIO153_               0
#define DRV_GPIO_MUX_GPIO153_               0
#define DRV_GPIO_MUX_GPIO153_               0
#define DRV_GPIO_MUX_GPIO153_               0
#define DRV_GPIO_MUX_GPIO153_               0

/** \} */


/** \name GPIO154 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO154_GPIO           0
#define DRV_GPIO_MUX_GPIO154_               0
#define DRV_GPIO_MUX_GPIO154_               0
#define DRV_GPIO_MUX_GPIO154_               0
#define DRV_GPIO_MUX_GPIO154_               0
#define DRV_GPIO_MUX_GPIO154_               0
#define DRV_GPIO_MUX_GPIO154_               0
#define DRV_GPIO_MUX_GPIO154_               0

/** \} */


/** \name GPIO155 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO155_GPIO           0
#define DRV_GPIO_MUX_GPIO155_               0
#define DRV_GPIO_MUX_GPIO155_               0
#define DRV_GPIO_MUX_GPIO155_               0
#define DRV_GPIO_MUX_GPIO155_               0
#define DRV_GPIO_MUX_GPIO155_               0
#define DRV_GPIO_MUX_GPIO155_               0
#define DRV_GPIO_MUX_GPIO155_               0

/** \} */


/** \name GPIO156 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO156_GPIO           0
#define DRV_GPIO_MUX_GPIO156_               0
#define DRV_GPIO_MUX_GPIO156_               0
#define DRV_GPIO_MUX_GPIO156_               0
#define DRV_GPIO_MUX_GPIO156_               0
#define DRV_GPIO_MUX_GPIO156_               0
#define DRV_GPIO_MUX_GPIO156_               0
#define DRV_GPIO_MUX_GPIO156_               0

/** \} */


/** \name GPIO157 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO157_GPIO           0
#define DRV_GPIO_MUX_GPIO157_               0
#define DRV_GPIO_MUX_GPIO157_               0
#define DRV_GPIO_MUX_GPIO157_               0
#define DRV_GPIO_MUX_GPIO157_               0
#define DRV_GPIO_MUX_GPIO157_               0
#define DRV_GPIO_MUX_GPIO157_               0
#define DRV_GPIO_MUX_GPIO157_               0

/** \} */


/** \name GPIO158 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO158_GPIO           0
#define DRV_GPIO_MUX_GPIO158_               0
#define DRV_GPIO_MUX_GPIO158_               0
#define DRV_GPIO_MUX_GPIO158_               0
#define DRV_GPIO_MUX_GPIO158_               0
#define DRV_GPIO_MUX_GPIO158_               0
#define DRV_GPIO_MUX_GPIO158_               0
#define DRV_GPIO_MUX_GPIO158_               0

/** \} */


/** \name GPIO159 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO159_GPIO           0
#define DRV_GPIO_MUX_GPIO159_               0
#define DRV_GPIO_MUX_GPIO159_               0
#define DRV_GPIO_MUX_GPIO159_               0
#define DRV_GPIO_MUX_GPIO159_               0
#define DRV_GPIO_MUX_GPIO159_               0
#define DRV_GPIO_MUX_GPIO159_               0
#define DRV_GPIO_MUX_GPIO159_               0

/** \} */


/** \name GPIO160 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO160_GPIO           0
#define DRV_GPIO_MUX_GPIO160_               0
#define DRV_GPIO_MUX_GPIO160_               0
#define DRV_GPIO_MUX_GPIO160_               0
#define DRV_GPIO_MUX_GPIO160_               0
#define DRV_GPIO_MUX_GPIO160_               0
#define DRV_GPIO_MUX_GPIO160_               0
#define DRV_GPIO_MUX_GPIO160_               0

/** \} */


/** \name GPIO161 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO161_GPIO           0
#define DRV_GPIO_MUX_GPIO161_               0
#define DRV_GPIO_MUX_GPIO161_               0
#define DRV_GPIO_MUX_GPIO161_               0
#define DRV_GPIO_MUX_GPIO161_               0
#define DRV_GPIO_MUX_GPIO161_               0
#define DRV_GPIO_MUX_GPIO161_               0
#define DRV_GPIO_MUX_GPIO161_               0

/** \} */


/** \name GPIO162 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO162_GPIO           0
#define DRV_GPIO_MUX_GPIO162_               0
#define DRV_GPIO_MUX_GPIO162_               0
#define DRV_GPIO_MUX_GPIO162_               0
#define DRV_GPIO_MUX_GPIO162_               0
#define DRV_GPIO_MUX_GPIO162_               0
#define DRV_GPIO_MUX_GPIO162_               0
#define DRV_GPIO_MUX_GPIO162_               0

/** \} */


/** \name GPIO163 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO163_GPIO           0
#define DRV_GPIO_MUX_GPIO163_               0
#define DRV_GPIO_MUX_GPIO163_               0
#define DRV_GPIO_MUX_GPIO163_               0
#define DRV_GPIO_MUX_GPIO163_               0
#define DRV_GPIO_MUX_GPIO163_               0
#define DRV_GPIO_MUX_GPIO163_               0
#define DRV_GPIO_MUX_GPIO163_               0

/** \} */


/** \name GPIO164 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO164_GPIO           0
#define DRV_GPIO_MUX_GPIO164_               0
#define DRV_GPIO_MUX_GPIO164_               0
#define DRV_GPIO_MUX_GPIO164_               0
#define DRV_GPIO_MUX_GPIO164_               0
#define DRV_GPIO_MUX_GPIO164_               0
#define DRV_GPIO_MUX_GPIO164_               0
#define DRV_GPIO_MUX_GPIO164_               0

/** \} */


/** \name GPIO165 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO165_GPIO           0
#define DRV_GPIO_MUX_GPIO165_               0
#define DRV_GPIO_MUX_GPIO165_               0
#define DRV_GPIO_MUX_GPIO165_               0
#define DRV_GPIO_MUX_GPIO165_               0
#define DRV_GPIO_MUX_GPIO165_               0
#define DRV_GPIO_MUX_GPIO165_               0
#define DRV_GPIO_MUX_GPIO165_               0

/** \} */


/** \name GPIO166 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO166_GPIO           0
#define DRV_GPIO_MUX_GPIO166_               0
#define DRV_GPIO_MUX_GPIO166_               0
#define DRV_GPIO_MUX_GPIO166_               0
#define DRV_GPIO_MUX_GPIO166_               0
#define DRV_GPIO_MUX_GPIO166_               0
#define DRV_GPIO_MUX_GPIO166_               0
#define DRV_GPIO_MUX_GPIO166_               0

/** \} */


/** \name GPIO167 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO167_GPIO           0
#define DRV_GPIO_MUX_GPIO167_               0
#define DRV_GPIO_MUX_GPIO167_               0
#define DRV_GPIO_MUX_GPIO167_               0
#define DRV_GPIO_MUX_GPIO167_               0
#define DRV_GPIO_MUX_GPIO167_               0
#define DRV_GPIO_MUX_GPIO167_               0
#define DRV_GPIO_MUX_GPIO167_               0

/** \} */


/** \name GPIO168 MUX values
 *  \{
 */

#define DRV_GPIO_MUX_GPIO168_GPIO           0
#define DRV_GPIO_MUX_GPIO168_               0
#define DRV_GPIO_MUX_GPIO168_               0
#define DRV_GPIO_MUX_GPIO168_               0
#define DRV_GPIO_MUX_GPIO168_               0
#define DRV_GPIO_MUX_GPIO168_               0
#define DRV_GPIO_MUX_GPIO168_               0
#define DRV_GPIO_MUX_GPIO168_               0

/** \} */

/* Public Constant definition --------------------------------------------------------------------------------------*/
/* Public Type definition  -----------------------------------------------------------------------------------------*/
/* Public variables ------------------------------------------------------------------------------------------------*/
/* Public functions ------------------------------------------------------------------------------------------------*/

#endif /* GPIO_DEFINES_H_ */

#ifdef __cplusplus
}
#endif

/** \} */
/** \} */
/******************************************************** EOF *******************************************************/
