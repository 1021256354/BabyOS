/**
 *!
 * \file        b_device.h
 * \version     v0.0.1
 * \date        2019/06/05
 * \author      Bean(notrynohigh@outlook.com)
 *******************************************************************************
 * @attention
 * 
 * Copyright (c) 2019 Bean
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *******************************************************************************
 */
#ifndef __B_DEVICE_H__
#define __B_DEVICE_H__

#ifdef __cplusplus
 extern "C" {
#endif

/*Includes ----------------------------------------------*/
#include "b_config.h"  
/** 
 * \addtogroup BABYOS
 * \{
 */

/** 
 * \addtogroup DEVICE
 * \{
 */

/** 
 * \defgroup DEVICE_Exported_TypesDefinitions
 * \{
 */

typedef struct
{
	uint32_t addr;
	uint32_t num;
}bCMD_Erase_t;


typedef struct
{
	uint8_t type;
	union
	{
		bCMD_Erase_t erase;
	}param;
}bCMD_Struct_t;
/**
 * \}
 */
   
/** 
 * \defgroup DEVICE_Exported_Defines
 * \{
 */

/** 
 * \defgroup DEVICE_CtlCMD_Defines
 * \{
 */

#define bCMD_ERASE			0


/**
 * \}
 */




/**
 * \}
 */
   
/** 
 * \defgroup DEVICE_Exported_Macros
 * \{
 */
   
/**
 * \}
 */
   
/** 
 * \defgroup DEVICE_Exported_Variables
 * \{
 */
   
/**
 * \}
 */
   
/** 
 * \defgroup DEVICE_Exported_Functions
 * \{
 */
 
/**
 * \}
 */
 
/**
 * \}
 */ 

/**
 * \}
 */



#ifdef __cplusplus
	}
#endif
 
#endif  

/************************ Copyright (c) 2019 Bean *****END OF FILE****/



