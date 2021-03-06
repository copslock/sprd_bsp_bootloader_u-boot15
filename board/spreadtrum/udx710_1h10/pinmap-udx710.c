/*Device: ROC1_UDS710
 *Version: UDS710_1_IRD_UDX710_SCH_V1.0.0_Pinmap_V1.0 20190110
 *Creat Time: 2019/01/31 18:49:38
 *Author: Yang.Ni
 */

/*
 * Copyright (C) 2012 Spreadtrum Communications Inc.
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


#include <asm/io.h>
#include <asm/arch/pinmap.h>
#include <power/sprd_pmic/sprd_2730_pinmap.h>

#define BIT_PIN_SLP_ALL           (BIT_PIN_SLP_AP|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_PSCP|BIT_PIN_SLP_AUDCP|BIT_PIN_SLP_V3_MODEM|BIT_PIN_SLP_CM4)
#define BIT_PIN_SLP_ALL_CP        (BIT_PIN_SLP_NRCP|BIT_PIN_SLP_PSCP|BIT_PIN_SLP_AUDCP|BIT_PIN_SLP_V3_MODEM|BIT_PIN_SLP_CM4)
#define BIT_PIN_SLP_ALL_NO_CM4    (BIT_PIN_SLP_AP|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_PSCP|BIT_PIN_SLP_AUDCP|BIT_PIN_SLP_V3_MODEM)




static pinmap_t pinmap[]={
{REG_PIN_CTRL_REG0,        0x00000000},//reserved;
{REG_PIN_CTRL_REG1,        0x00000000},//reserved;
{REG_PIN_CTRL_REG2,        0x00000000},//uart_usb_phy_sel -> normal uart1 path; DM/DP FS/LS driver is enabled;
{REG_PIN_CTRL_REG3,        0x00000000},//SP_EIC_DPAD source select
{REG_PIN_CTRL_REG4,        0x00000000},//SP_EIC_DPAD source select
{REG_PIN_CTRL_REG5,        0x00000000},//BAT_DET no connect, SIM0/1_det -> pscp;

//{REG_PIN_PWR_PAD_CTL_RESERVED,0x00000000},//
{REG_PIN_UART_MATRIX_MTX_CFG,       0x16A81C20},//uart0->ap_uart0; uart1->ps_cp_uart0; uart2->nr_cp_uart0; uart3->nr_cp_uart1; uart4->nr_cp_wci2_3; uart5->auddsp_uart0; uart6->cm4_uart;
{REG_PIN_IIS_MATRIX_MTX_CFG,        0x00229043},//iis0->audcp_iis0; iis1->v3_phy_iis0; iis2->v3_phy_iis1; iis3->audcp_iis2; iis4->audcp_iis1;
{REG_PIN_SIM_MATRIX_MTX_CFG,        0x00000005},//sim0->ps_cp_sim0; sim1->ps_cp_sim1; sim2->ap_sim0;
{REG_PIN_SPI_MATRIX_MTX_CFG,        0x00000000},//spi0->ap_spi0; spi1->ap_spi1; spi2->ap_spi2; spi3->ps_cp_spi;
{REG_PIN_IIC_MATRIX_MTX_CFG,        0x0000068D},//iic0->aon_iic0; iic1->ap_iic1; iic2->ap_iic2; iic3->ap_iic3; iic4->ap_iic0;



{REG_PIN_SPI0_CSN,                      BITS_PIN_AF(2)},
{REG_MISC_PIN_SPI0_CSN,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_SPI0_CSN (DebugBus)
{REG_PIN_SPI0_DO,                       BITS_PIN_AF(2)},
{REG_MISC_PIN_SPI0_DO,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_SPI0_DI (DebugBus)
{REG_PIN_SPI0_DI,                       BITS_PIN_AF(2)},
{REG_MISC_PIN_SPI0_DI,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_SPI0_DO (DebugBus)
{REG_PIN_SPI0_CLK,                      BITS_PIN_AF(2)},
{REG_MISC_PIN_SPI0_CLK,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_SPI0_CLK (DebugBus)
{REG_PIN_SPI2_CSN,                      BITS_PIN_AF(2)},
{REG_MISC_PIN_SPI2_CSN,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_SPI2_CSN (DebugBus)
{REG_PIN_SPI2_DO,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_SPI2_DO,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//CP_SPI2_DO (CP_USB1_SW)
{REG_PIN_SPI2_DI,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SPI2_DI,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SPI2_CLK,                      BITS_PIN_AF(2)},
{REG_MISC_PIN_SPI2_CLK,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_SPI2_CLK (DebugBus)
{REG_PIN_EMMC_RST,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_RST,                 BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//NC (For OP)
{REG_PIN_EMMC_CMD,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_CMD,                 BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC (For OP)
{REG_PIN_EMMC_D0,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_D0,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC (For OP)
{REG_PIN_EMMC_D3,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_D3,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC (For OP)
{REG_PIN_EMMC_D2,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_D2,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC (For OP)
{REG_PIN_EMMC_D5,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_D5,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC (For OP)
{REG_PIN_EMMC_CLK,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_CLK,                 BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC (For OP)
{REG_PIN_EMMC_DS,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_DS,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//NC (For OP)
{REG_PIN_EMMC_D1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_D1,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC (For OP)
{REG_PIN_EMMC_D4,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_D4,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC (For OP)
{REG_PIN_EMMC_D6,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_D6,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC (For OP)
{REG_PIN_EMMC_D7,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_D7,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC (For OP)
{REG_PIN_PCIE_CLKREQ,                   BITS_PIN_AF(0)},
{REG_MISC_PIN_PCIE_CLKREQ,              BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AP_CP_PCIE_CLKREQ(Master)
{REG_PIN_PCIE_RST,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_PCIE_RST,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//AP_CP_PCIE_RST(Slaver,IE)
{REG_PIN_PCIE_WAKE,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_PCIE_WAKE,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AP_CP_PCIE_WAKE(Master)
{REG_PIN_SD0_D_3,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D_3,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//AP_CP_SD2_D3
{REG_PIN_SD0_D_2,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D_2,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//AP_CP_SD2_D2
{REG_PIN_SD0_CMD,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_CMD,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//AP_CP_SD2_CMD
{REG_PIN_SD0_D_0,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D_0,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//AP_CP_SD2_D0
{REG_PIN_SD0_D_1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D_1,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//AP_CP_SD2_D1
{REG_PIN_SD0_CLK,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_CLK,                  BITS_PIN_DS(6)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AP_CP_SD2_CLK
{REG_PIN_SD0_D_4,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D_4,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//AP_CP_SD2_D4
{REG_PIN_SD0_DS,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_DS,                   BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//AP_CP_SD2_DS
{REG_PIN_SD0_D_5,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D_5,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//AP_CP_SD2_D5
{REG_PIN_SD0_D_6,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D_6,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//AP_CP_SD2_D6
{REG_PIN_SD0_D_7,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D_7,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//AP_CP_SD2_D7
{REG_PIN_RFSCK0_NR,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSCK0_NR,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSCK0_NR
{REG_PIN_RFSDA0_NR,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSDA0_NR,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSDA0_NR
{REG_PIN_RFSEN0_NR,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSEN0_NR,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSEN_NR
{REG_PIN_RFSDA2_NR,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSDA2_NR,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSDA2_NR
{REG_PIN_RFSDA1_NR,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSDA1_NR,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSDA1_NR
{REG_PIN_RFSDA3_NR,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSDA3_NR,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSDA3_NR
{REG_PIN_RFCTL_NR_0,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_0,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_0
{REG_PIN_RFCTL_NR_1,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_1,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_1
{REG_PIN_RFCTL_NR_2,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_2,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_2
{REG_PIN_RFCTL_NR_3,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_3,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_3
{REG_PIN_RFCTL_NR_4,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_4,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_RFCTL_NR_5,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_5,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_5
{REG_PIN_RFCTL_NR_6,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_6,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_6
{REG_PIN_RFCTL_NR_7,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_7,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_7
{REG_PIN_RFCTL_NR_8,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_8,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_8
{REG_PIN_RFCTL_NR_9,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_9,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_9
{REG_PIN_RFCTL_NR_10,                   BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_10,              BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_10
{REG_PIN_RFCTL_NR_11,                   BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_11,              BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NR_RFCTL_11
{REG_PIN_RFCTL_NR_12,                   BITS_PIN_AF(1)},
{REG_MISC_PIN_RFCTL_NR_12,              BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//SIM1_DET
{REG_PIN_RFCTL_NR_13,                   BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_13,              BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_RFCTL_NR_14,                   BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_14,              BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_RFCTL_NR_15,                   BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_NR_15,              BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_RFFE2_SCK_NR,                  BITS_PIN_AF(0)},
{REG_MISC_PIN_RFFE2_SCK_NR,             BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SCK2_NR
{REG_PIN_RFFE2_SDA_NR,                  BITS_PIN_AF(0)},
{REG_MISC_PIN_RFFE2_SDA_NR,             BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SDA2_NR
{REG_PIN_RFFE3_SCK_NR,                  BITS_PIN_AF(0)},
{REG_MISC_PIN_RFFE3_SCK_NR,             BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SCK3_NR
{REG_PIN_RFFE3_SDA_NR,                  BITS_PIN_AF(0)},
{REG_MISC_PIN_RFFE3_SDA_NR,             BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SDA3_NR
{REG_PIN_LVDS_ADDAC0_ON,                BITS_PIN_AF(0)},
{REG_MISC_PIN_LVDS_ADDAC0_ON,           BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_V3_MODEM|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//LVDS_ADDAC0_ON
{REG_PIN_LVDS_ADDAC1_ON,                BITS_PIN_AF(0)},
{REG_MISC_PIN_LVDS_ADDAC1_ON,           BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_V3_MODEM|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//LVDS_ADDAC1_ON
{REG_PIN_LVDS_ADDAC2_ON,                BITS_PIN_AF(0)},
{REG_MISC_PIN_LVDS_ADDAC2_ON,           BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_V3_MODEM|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//LVDS_ADDAC2_ON
{REG_PIN_NR_LVDS_ADDAC0_ON,             BITS_PIN_AF(0)},
{REG_MISC_PIN_NR_LVDS_ADDAC0_ON,        BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//LVDS_ADDAC0_ON_NR
{REG_PIN_NR_LVDS_ADDAC1_ON,             BITS_PIN_AF(0)},
{REG_MISC_PIN_NR_LVDS_ADDAC1_ON,        BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//LVDS_ADDAC1_ON_NR
{REG_PIN_NR_LVDS_ADDAC2_ON,             BITS_PIN_AF(0)},
{REG_MISC_PIN_NR_LVDS_ADDAC2_ON,        BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NRCP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//LVDS_ADDAC2_ON_NR
{REG_PIN_RFCTL_0,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_0
{REG_PIN_RFCTL_1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_1
{REG_PIN_RFCTL_2,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_2,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_2
{REG_PIN_RFCTL_3,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_3,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_3
{REG_PIN_RFCTL_4,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_4,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_4
{REG_PIN_RFCTL_5,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_5,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_5
{REG_PIN_RFCTL_6,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_6,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_6
{REG_PIN_RFCTL_7,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_7,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_7
{REG_PIN_RFCTL_8,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_8,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_8
{REG_PIN_RFCTL_9,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_9,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_9
{REG_PIN_RFCTL_10,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_10,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_10
{REG_PIN_RFCTL_11,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_11,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_11
{REG_PIN_RFCTL_12,                      BITS_PIN_AF(1)},
{REG_MISC_PIN_RFCTL_12,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//SIM0_DET
{REG_PIN_RFCTL_13,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_13,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_13
{REG_PIN_RFCTL_14,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_14,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFCTL_14
{REG_PIN_RFCTL_15,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL_15,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_GNSS_COEXIST
{REG_PIN_RFSCK0,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSCK0,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSCK
{REG_PIN_RFSDA0,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSDA0,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSDA0
{REG_PIN_RFSEN0,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSEN0,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSEN
{REG_PIN_RFSDA2,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSDA2,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSDA2
{REG_PIN_RFSDA1,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSDA1,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSDA1
{REG_PIN_RFSDA3,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSDA3,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFSDA3
{REG_PIN_RFFE0_SCK,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFFE0_SCK,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SCK0
{REG_PIN_RFFE0_SDA,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFFE0_SDA,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SDA0
{REG_PIN_RFFE1_SCK,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFFE1_SCK,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SCK1 (For OP)
{REG_PIN_RFFE1_SDA,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFFE1_SDA,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SCK2 (For OP)
{REG_PIN_IIS0DI,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_IIS0DI,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AUDCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//AP_I2S3_SDO
{REG_PIN_IIS0DO,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_IIS0DO,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AUDCP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AP_I2S3_SDI
{REG_PIN_IIS0CLK,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_IIS0CLK,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AUDCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//AP_I2S3_SCLK
{REG_PIN_IIS0LRCK,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_IIS0LRCK,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AUDCP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//AP_I2S3_LRCK
{REG_PIN_SCL0,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SCL0,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//CP_I2C0_SCL
{REG_PIN_SDA0,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SDA0,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//CP_I2C0_SDA
{REG_PIN_SDA1,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SDA1,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//CP_I2C1_SDA
{REG_PIN_SCL1,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SCL1,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//CP_I2C1_SCL
{REG_PIN_SCL2,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SCL2,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//CP_IC22_SCL
{REG_PIN_SDA2,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SDA2,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//CP_IC22_SDA
{REG_PIN_KEYOUT_0,                      BITS_PIN_AF(3)},
{REG_MISC_PIN_KEYOUT_0,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_KEYOUT_1,                      BITS_PIN_AF(2)},
{REG_MISC_PIN_KEYOUT_1,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC(CP_KEYOUT1)
{REG_PIN_KEYOUT_2,                      BITS_PIN_AF(2)},
{REG_MISC_PIN_KEYOUT_2,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC(CP_KEYOUT2)
{REG_PIN_KEYIN_0,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_KEYIN_0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN0(For Download) (For OP)
{REG_PIN_KEYIN_1,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_KEYIN_1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_KEYIN_2,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_KEYIN_2,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//CP_USB0_DET
{REG_PIN_DTDO,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_DTDO,                     BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_DSP_JTAG0_DTDO (For OP)
{REG_PIN_DTDI,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_DTDI,                     BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_DSP_JTAG0_DTDI (For OP)
{REG_PIN_DTMS,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_DTMS,                     BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_DSP_JTAG0_DTMS (For OP)
{REG_PIN_DTCK,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_DTCK,                     BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_DSP_JTAG0_DTCK (For OP)
{REG_PIN_DRTCK,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_DRTCK,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_DSP_JTAG0_RTCK (For OP)
{REG_PIN_MTCK_ARM,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_MTCK_ARM,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_MTCK
{REG_PIN_MTMS_ARM,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_MTMS_ARM,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_MTMS
{REG_PIN_DTDO_1,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_DTDO_1,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_DSP_JTAG1_DTDO (For OP)
{REG_PIN_DTDI_1,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_DTDI_1,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_DSP_JTAG1_DTDI (For OP)
{REG_PIN_DTMS_1,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_DTMS_1,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_DSP_JTAG1_DTMS (For OP)
{REG_PIN_DTCK_1,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_DTCK_1,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_DSP_JTAG1_DTCK (For OP)
{REG_PIN_DRTCK_1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_DRTCK_1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_DSP_JTAG1_RTCK (For OP)
{REG_PIN_U1TXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U1TXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_U1TXD
{REG_PIN_U1RXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U1RXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//CP_U1RXD
{REG_PIN_U2TXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U2TXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_U2TXD
{REG_PIN_U2RXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U2RXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//CP_U2RXD
{REG_PIN_U5TXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U5TXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_U5TXD
{REG_PIN_U5RXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U5RXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//CP_U5TXD
{REG_PIN_U0TXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U0TXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_U0TXD
{REG_PIN_U0RXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U0RXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//CP_U0RXD
{REG_PIN_U0CTS,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U0CTS,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//CP_UOCTS
{REG_PIN_U0RTS,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U0RTS,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//CP_U0RTS
{REG_PIN_U4TXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U4TXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_WCI_TXD
{REG_PIN_U4RXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U4RXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//CP_WCI_RXD
{REG_PIN_U3TXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U3TXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_U3TXD
{REG_PIN_U3RXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U3RXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//CP_U3RXD
{REG_PIN_PTEST,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_PTEST,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//GND
{REG_PIN_EXT_RST_B,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_EXT_RST_B,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//CP_EXT_RST_B
{REG_PIN_ADI_SCLK,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_ADI_SCLK,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_ADI_SCLK
{REG_PIN_CLK_32K,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_CLK_32K,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//CPPMIC_CP_32K
{REG_PIN_ANA_INT,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_ANA_INT,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//CP_ANA_INT
{REG_PIN_ADI_D,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_ADI_D,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//CP_ADI_D
{REG_PIN_AUD_SCLK,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_SCLK,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_XTL_EN_BB,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_XTL_EN_BB,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_XTL_EN_BB
{REG_PIN_XTL_EN_CM4,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_XTL_EN_CM4,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_XTL_EN_CM4
{REG_PIN_DCDC_ARM0_EN,                  BITS_PIN_AF(0)},
{REG_MISC_PIN_DCDC_ARM0_EN,             BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_VDDCPU0_EN
{REG_PIN_AUD_ADD0,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_ADD0,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NC
{REG_PIN_XTL_EN_V3,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_XTL_EN_V3,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_XTL_EN_V3
{REG_PIN_AUD_ADSYNC,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_ADSYNC,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NC
{REG_PIN_AUD_DAD0,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_DAD0,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_AUD_DAD0
{REG_PIN_XTL_EN_NR,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_XTL_EN_NR,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_XTL_EN_NR
{REG_PIN_AUD_DASYNC,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_DASYNC,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_AUD_DAD1,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_DAD1,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_AUD_DAD1
{REG_PIN_CHIP_SLEEP,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_CHIP_SLEEP,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CP_CHIP_SLEEP
{REG_PIN_CLK_AUX0,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_CLK_AUX0,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_SD1_CLK,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD1_CLK,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AP_CP_GPIO0
{REG_PIN_SD1_CMD,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD1_CMD,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AP_CP_GPIO1
{REG_PIN_SD1_D_0,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD1_D_0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AP_CP_GPIO2
{REG_PIN_SD1_D_1,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD1_D_1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//AP_CP_GPIO3
{REG_PIN_SD1_D_2,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD1_D_2,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//AP_CP_GPIO4
{REG_PIN_SD1_D_3,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD1_D_3,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//AP_CP_GPIO5
{REG_PIN_SD2_CMD,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD2_CMD,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D_0,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD2_D_0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D_1,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD2_D_1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_CLK,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD2_CLK,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D_2,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD2_D_2,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D_3,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SD2_D_3,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SIMCLK0,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMCLK0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_PSCP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM0_CLK
{REG_PIN_SIMDA0,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMDA0,                   BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_NUL|BIT_PIN_SLP_PSCP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//SIM0_DA
{REG_PIN_SIMRST0,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMRST0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_PSCP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM0_RST
{REG_PIN_SIMCLK1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMCLK1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_PSCP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM1_CLK
{REG_PIN_SIMDA1,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMDA1,                   BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_NUL|BIT_PIN_SLP_PSCP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//SIM1_DA
{REG_PIN_SIMRST1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMRST1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_PSCP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM1_RST
{REG_PIN_SIMCLK2,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SIMCLK2,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SIMDA2,                        BITS_PIN_AF(3)},
{REG_MISC_PIN_SIMDA2,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SIMRST2,                       BITS_PIN_AF(2)},
{REG_MISC_PIN_SIMRST2,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//CP_USB0_SW


};

/*here is the adie pinmap such as 2730*/
static pinmap_t adie_pinmap[]={
{REG_PIN_ANA_EXT_XTL_EN0,               BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//CP_XTL_EN_V3
{REG_PIN_ANA_EXT_XTL_EN1,               BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//CP_XTL_EN_NR
{REG_PIN_ANA_EXT_XTL_EN2,               BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//CP_XTL_EN_CM4
{REG_PIN_ANA_EXT_XTL_EN3,               BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//CP_XTL_EN_BB
{REG_PIN_ANA_PTESTO,                    BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BITS_ANA_PIN_AF(1)|BIT_ANA_PIN_SLP_IE},//NC
{REG_PIN_ANA_DCDC_GPU_EN,               BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BITS_ANA_PIN_AF(1)|BIT_ANA_PIN_SLP_IE},//NC
};



int  pin_init(void)
{
	int i;
	for (i = 0; i < sizeof(pinmap)/sizeof(pinmap[0]); i++) {
		__raw_writel(pinmap[i].val, CTL_PIN_BASE + pinmap[i].reg);
	}

	for (i = 0; i < sizeof(adie_pinmap)/sizeof(adie_pinmap[0]); i++) {
		sci_adi_set(CTL_ANA_PIN_BASE + adie_pinmap[i].reg, adie_pinmap[i].val);
	}

	pin_uart_port_cfg();

	return 0;
}
