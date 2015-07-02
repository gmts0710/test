/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2015, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __SAMA5D2_XPLAINED_H__
#define __SAMA5D2_XPLAINED_H__

/*
 * PMC Settings
 */
#define BOARD_MAINOSC		12000000

/* PCK: 498MHz, MCK: 166MHz */
#define BOARD_PLLA_MULA		82

#define BOARD_PCK		((unsigned long)((BOARD_MAINOSC * (BOARD_PLLA_MULA + 1)) / 2))
#define BOARD_MCK		((unsigned long)((BOARD_MAINOSC * (BOARD_PLLA_MULA + 1)) / 2 / 3))

#define BOARD_CKGR_PLLA		(AT91C_CKGR_SRCA | AT91C_CKGR_OUTA_0)
#define BOARD_PLLACOUNT		(0x3F << 8)
#define BOARD_MULA		((AT91C_CKGR_MULA << 2) & (BOARD_PLLA_MULA << 18))
#define BOARD_DIVA		(AT91C_CKGR_DIVA & 1)

#define BOARD_PRESCALER_MAIN_CLOCK	(AT91C_PMC_PLLADIV2_2 \
					| AT91C_PMC_MDIV_3 \
					| AT91C_PMC_CSS_MAIN_CLK)

#define BOARD_PRESCALER_PLLA		(AT91C_PMC_H32MXDIV_H32MXDIV2 \
					| AT91C_PMC_PLLADIV2_2 \
					| AT91C_PMC_MDIV_3 \
					| AT91C_PMC_CSS_PLLA_CLK)

#define MASTER_CLOCK		166000000

#define PLLA_SETTINGS		(BOARD_CKGR_PLLA | \
				BOARD_PLLACOUNT | \
				BOARD_MULA | \
				BOARD_DIVA)

/*
 * DBGU Settings
 */
#define	USART_BASE	AT91C_BASE_UART1

/*
 * DataFlash Settings
 */
#define CONFIG_SYS_SPI_CLOCK	AT91C_SPI_CLK
#define CONFIG_SYS_SPI_BUS	0
#define CONFIG_SYS_SPI_MODE	SPI_MODE3

#define CONFIG_SYS_BASE_SPI	AT91C_BASE_SPI0
#define CONFIG_SYS_SPI_PCS	AT91C_PIN_PA(17)

/*
 * SDHC Settings
 */
#ifdef CONFIG_SDHC0
#define CONFIG_SYS_BASE_SDHC	AT91C_BASE_SDHC0
#define CONFIG_SYS_ID_SDHC	AT91C_ID_SDMMC0
#endif

#ifdef CONFIG_SDHC1
#define CONFIG_SYS_BASE_SDHC	AT91C_BASE_SDHC1
#define CONFIG_SYS_ID_SDHC	AT91C_ID_SDMMC1
#endif

#endif
