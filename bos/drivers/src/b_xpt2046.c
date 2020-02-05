/**
 *!
 * \file        b_xpt2046.c
 * \version     v0.0.1
 * \date        2020/02/05
 * \author      Bean(notrynohigh@outlook.com)
 *******************************************************************************
 * @attention
 * 
 * Copyright (c) 2020 Bean
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
   
/*Includes ----------------------------------------------*/
#include "b_xpt2046.h"
#include "b_hal.h"
#include "b_utils.h"
#include <string.h>
/** 
 * \addtogroup B_DRIVER
 * \{
 */

/** 
 * \addtogroup XPT2046
 * \{
 */

/** 
 * \defgroup XPT2046_Private_TypesDefinitions
 * \{
 */
 

/**
 * \}
 */
   
/** 
 * \defgroup XPT2046_Private_Defines
 * \{
 */
#define	XPT2046_I       0x80
#define	XPT2046_X       0xD0
#define	XPT2046_Y       0x90   
/**
 * \}
 */
   
/** 
 * \defgroup XPT2046_Private_Macros
 * \{
 */
   
/**
 * \}
 */
   
/** 
 * \defgroup XPT2046_Private_Variables
 * \{
 */

extern SPI_HandleTypeDef hspi3;

bXPT2046_Driver_t bXPT2046_Driver = 
{
        .init = bXPT2046_Init,
};



/**
 * \}
 */
   
/** 
 * \defgroup XPT2046_Private_FunctionPrototypes
 * \{
 */

/**
 * \}
 */
   
/** 
 * \defgroup XPT2046_Private_Functions
 * \{
 */
static uint8_t _bXPT2046TxRx(uint8_t dat)
{
    uint8_t tmp;
	HAL_SPI_TransmitReceive(&hspi3, &dat, &tmp, 1, 0xfff);
    return tmp;
}


static uint16_t _bXPT2046ReadVal(uint8_t r)
{
    uint16_t l, h;
	TP_CS_RESET();
	_bXPT2046TxRx(r);
	h = _bXPT2046TxRx(0x00);
	l = _bXPT2046TxRx(0x00);
	TP_CS_SET();
	return ((h << 8) | (l)) >> 3;
}

static int _bXPT2046Read(uint32_t addr, uint8_t *pbuf, uint16_t len)
{
    uint16_t *pxy = (uint16_t *)pbuf;
    if(len < 4 || pbuf == NULL)
    {
        return -1;
    }
    pxy[0] = _bXPT2046ReadVal(XPT2046_X);
    pxy[1] = _bXPT2046ReadVal(XPT2046_Y);
    return 0;
}

static int _bXPT2046Close()
{
    _bXPT2046ReadVal(XPT2046_I);
    return 0;
}

static int _bXPT2046Open()
{
    return 0;
}

static int _bXPT2046Write(uint32_t addr, uint8_t *pbuf, uint16_t len)
{
    return 0;
}

static int _bXPT2046Ctl(uint8_t cmd, void * param)
{
    return 0;
}

/**
 * \}
 */
   
/** 
 * \addtogroup XPT2046_Exported_Functions
 * \{
 */
int bXPT2046_Init()
{  
    _bXPT2046ReadVal(XPT2046_I);
    bXPT2046_Driver.close = _bXPT2046Close;
    bXPT2046_Driver.read = _bXPT2046Read;
    bXPT2046_Driver.ctl = _bXPT2046Ctl;
    bXPT2046_Driver.open = _bXPT2046Open;
    bXPT2046_Driver.write = _bXPT2046Write;
    return 0;
}






/**
 * \}
 */

/**
 * \}
 */

/**
 * \}
 */

/************************ Copyright (c) 2019 Bean *****END OF FILE****/

