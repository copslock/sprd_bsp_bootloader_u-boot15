/* drivers/video/sprdfb/lcd_ssd2075_mipi.c
 *
 * Support for ssd2075 mipi LCD device
 *
 * Copyright (C) 2010 Spreadtrum
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
#include "../sprdfb_chip_common.h"
#include "../sprdfb.h"
#include "../sprdfb_panel.h"

#define printk printf

#ifdef DEBUG
#define  LCD_DEBUG
#endif
//#define THREE_LANE_SUPPORT

#define LCD_DEBUG
#ifdef LCD_DEBUG
#define LCD_PRINT printk
#else
#define LCD_PRINT(...)
#endif

#define MAX_DATA   80

typedef struct LCM_Init_Code_tag {
	unsigned int tag;
	unsigned char data[MAX_DATA];
}LCM_Init_Code;

typedef struct LCM_force_cmd_code_tag{
	unsigned int datatype;
	LCM_Init_Code real_cmd_code;
}LCM_Force_Cmd_Code;

#define LCM_TAG_SHIFT 24
#define LCM_TAG_MASK  ((1 << 24) -1)
#define LCM_SEND(len) ((1 << LCM_TAG_SHIFT)| len)
#define LCM_SLEEP(ms) ((2 << LCM_TAG_SHIFT)| ms)
//#define ARRAY_SIZE(array) ( sizeof(array) / sizeof(array[0]))

#define LCM_TAG_SEND  (1<< 0)
#define LCM_TAG_SLEEP (1 << 1)
static LCM_Init_Code init_data[] = {

{LCM_SEND(2),{0x00,0x00}},
{LCM_SEND(6),{4,0,0xFF,0x19,0x01,0x01}},//Enable command2
 
{LCM_SEND(2),{0x00,0x80}},
{LCM_SEND(5),{3,0,0xFF,0x19,0x01}},
 
{LCM_SEND(2),{0x00,0x00}},
{LCM_SEND(2),{0x1C,0x33}},//bypass mode
 
{LCM_SEND(2),{0x00,0xA0}},
{LCM_SEND(2),{0xC1,0xE8}},//Video mode sync
 
{LCM_SEND(2),{0x00,0xA7}},
{LCM_SEND(2),{0xC1,0x00}},
 
{LCM_SEND(2),{0x00,0x90}},
{LCM_SEND(9),{7,0,0xC0,0x00,0x2F,0x00,0x00,0x00,0x01}},
 
{LCM_SEND(2),{0x00,0xC0}},
{LCM_SEND(9),{7,0,0xC0,0x00,0x2F,0x00,0x00,0x00,0x01}},
 
{LCM_SEND(2),{0x00,0x9A}},
{LCM_SEND(2),{0xC0,0x1E}},
 
{LCM_SEND(2),{0x00,0xAC}},
{LCM_SEND(2),{0xC0,0x06}},
 
{LCM_SEND(2),{0x00,0xDC}},
{LCM_SEND(2),{0xC0,0x06}},
 
{LCM_SEND(2),{0x00,0x92}},
{LCM_SEND(2),{0xE9,0x00}},
 
{LCM_SEND(2),{0x00,0x90}},
{LCM_SEND(2),{0xF3,0x01}},
 
{LCM_SEND(2),{0x00,0x93}},
{LCM_SEND(2),{0xC5,0x1E}},//VGH=9V
 
{LCM_SEND(2),{0x00,0x95}},
{LCM_SEND(2),{0xC5,0x32}},//VGL=-9V
 
{LCM_SEND(2),{0x00,0x97}},
{LCM_SEND(2),{0xC5,0x19}},//VGHO=8.5V
 
{LCM_SEND(2),{0x00,0x99}},
{LCM_SEND(2),{0xC5,0x1E}},//VGLO=-7V
 
{LCM_SEND(2),{0x00,0x9B}},
{LCM_SEND(6),{4,0,0xC5,0x22,0x20,0x55}},//charge pump 1 line (default)
 
{LCM_SEND(2),{0x00,0x00}},
{LCM_SEND(5),{3,0,0xD9,0x00,0xAA}},//VCOM=-0.3V
 
{LCM_SEND(2),{0x00,0x00}},
{LCM_SEND(5),{3,0,0xD8,0x23,0x23}},//GVDDP/GVDDN=4.6V
 
{LCM_SEND(2),{0x00,0xB3}},
{LCM_SEND(2),{0xC0,0xCC}},
 
{LCM_SEND(2),{0x00,0xBC}},
{LCM_SEND(2),{0xC0,0x00}},//Pixel base column inversion
 
{LCM_SEND(2),{0x00,0x84}},
{LCM_SEND(2),{0xC4,0x22}},
 
{LCM_SEND(2),{0x00,0x80}},
{LCM_SEND(2),{0xC4,0x16}},//Source=HiZ at Vblanking

//Panel Timing
{LCM_SEND(2),{0x00,0x80}},
{LCM_SEND(17),{15,0,0xC0,0x00,0x7C,0x00,0x08,0x08,0x00,0x7C,0x08,0x08,0x00,0x7C,0x00,0x08,0x08}},

{LCM_SEND(2),{0x00,0xF0}},
{LCM_SEND(9),{7,0,0xC3,0x22,0x00,0x00,0x00,0x00,0x0C}},

{LCM_SEND(2),{0x00,0xA0}},
{LCM_SEND(10),{8,0,0xC0,0x00,0x00,0x1E,0x00,0x00,0x17,0x06}},
 
{LCM_SEND(2),{0x00,0xD0}},
{LCM_SEND(10),{8,0,0xC0,0x00,0x00,0x1E,0x00,0x00,0x17,0x06}},
 
{LCM_SEND(2),{0x00,0x90}},
{LCM_SEND(11),{9,0,0xC2,0x83,0x01,0x74,0x36,0x82,0x01,0x74,0x36}},

{LCM_SEND(2),{0x00,0xA0}},
{LCM_SEND(7),{5,0,0xC2,0x83,0x00,0x00,0xD0}},

{LCM_SEND(2),{0x00,0x80}},
{LCM_SEND(15),{13,0,0xC3,0x82,0x02,0x03,0x00,0x13,0x04,0x81,0x02,0x03,0x00,0x13,0x04}},

{LCM_SEND(2),{0x00,0x90}},
{LCM_SEND(15),{13,0,0xC3,0x80,0x02,0x03,0x00,0x13,0x04,0x01,0x02,0x03,0x00,0x13,0x04}},

{LCM_SEND(2),{0x00,0x80}},
{LCM_SEND(18),{16,0,0xCC,0x09,0x0A,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x0B,0x28,0x28,0x28,0x28}},

{LCM_SEND(2),{0x00,0x90}},
{LCM_SEND(18),{16,0,0xCC,0x0A,0x09,0x14,0x13,0x12,0x11,0x15,0x16,0x17,0x18,0x0B,0x28,0x28,0x28,0x28}}, 

{LCM_SEND(2),{0x00,0xA0}},
{LCM_SEND(18),{16,0,0xCC,0x1D,0x1E,0x1F,0x19,0x1A,0x1B,0x1C,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27}},

{LCM_SEND(2),{0x00,0xB0}},
{LCM_SEND(11),{9,0,0xCC,0x01,0x02,0x03,0x05,0x06,0x07,0x04,0x08}},

{LCM_SEND(2),{0x00,0xC0}},
{LCM_SEND(15),{13,0,0xCC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77}},

{LCM_SEND(2),{0x00,0xD0}},
{LCM_SEND(15),{13,0,0xCC,0xFF,0x0F,0x30,0x00,0x05,0x00,0x00,0x00,0x33,0x03,0x00,0x77}}, 

{LCM_SEND(2),{0x00,0x80}},
{LCM_SEND(18),{16,0,0xCB,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCF,0x00,0x00,0x00,0x00}}, 

{LCM_SEND(2),{0x00,0x90}},
{LCM_SEND(18),{16,0,0xCB,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{LCM_SEND(2),{0x00,0xA0}},
{LCM_SEND(18),{16,0,0xCB,0x15,0x15,0x15,0x15,0x15,0x15,0x00,0x00,0x00,0x00,0xEA,0x00,0x00,0x00,0x00}},

{LCM_SEND(2),{0x00,0xB0}},
{LCM_SEND(18),{16,0,0xCB,0x00,0x15,0xD5,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}, 

{LCM_SEND(2),{0x00,0xC0}},
{LCM_SEND(11),{9,0,0xCB,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x77}}, 

{LCM_SEND(2),{0x00,0xD0}},
{LCM_SEND(11),{9,0,0xCB,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x77}},

{LCM_SEND(2),{0x00,0xE0}},
{LCM_SEND(11),{9,0,0xCB,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x77}},

{LCM_SEND(2),{0x00,0xF0}},
{LCM_SEND(11),{9,0,0xCB,0x11,0x11,0x11,0x00,0x00,0x00,0x77,0x77}},

{LCM_SEND(2),{0x00,0x80}},
{LCM_SEND(18),{16,0,0xCD,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x06,0x04,0x0B,0x11,0x12,0x02}}, 

{LCM_SEND(2),{0x00,0x90}},
{LCM_SEND(14),{12,0,0xCD,0x3F,0x3F,0x3F,0x25,0x25,0x25,0x21,0x20,0x1F,0x25,0x25}},

{LCM_SEND(2),{0x00,0xA0}},
{LCM_SEND(18),{16,0,0xCD,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x05,0x03,0x0B,0x11,0x12,0x01}}, 

{LCM_SEND(2),{0x00,0xB0}},
{LCM_SEND(14),{12,0,0xCD,0x3F,0x3F,0x3F,0x25,0x25,0x25,0x21,0x20,0x1F,0x25,0x25}},

{LCM_SEND(2),{0x00,0x00}},
{LCM_SEND(27),{25,0,0xE1,0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}},
{LCM_SEND(2),{0x00,0x00}},
{LCM_SEND(27),{25,0,0xE2,0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}},

{LCM_SEND(2),{0x00,0x00}},
{LCM_SEND(27),{25,0,0xE3,0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}},
{LCM_SEND(2),{0x00,0x00}},
{LCM_SEND(27),{25,0,0xE4,0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}},

{LCM_SEND(2),{0x00,0x00}},
{LCM_SEND(27),{25,0,0xE5,0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}},
{LCM_SEND(2),{0x00,0x00}},
{LCM_SEND(27),{25,0,0xE6,0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}}, 

{LCM_SEND(2),{0x00,0xD4}},//LTPS Ground Period for Gate Precharge
{LCM_SEND(7),{5,0,0xC3,0x01,0x01,0x01,0x01}},
 
{LCM_SEND(2),{0x00,0xF7}},//LTPS CKH EQ Setting
{LCM_SEND(7),{5,0,0xC3,0x04,0x16,0x00,0x00}},
 
{LCM_SEND(2),{0x00,0xD0}},//AVDDR/AVEER regulatior Disable
{LCM_SEND(7),{5,0,0xF5,0x00,0x00,0x00,0x00}},

{LCM_SEND(2),{0x00,0x81}},
{LCM_SEND(2),{0xA5,0x06}},

{LCM_SEND(2),{0x00,0x82}},
{LCM_SEND(2),{0xC4,0xf0}},

{LCM_SEND(2),{0x00,0x84}},
{LCM_SEND(2),{0xC4,0x22}},

{LCM_SEND(2),{0x00,0x92}},
{LCM_SEND(2),{0xC5,0xc0}},

{LCM_SEND(2),{0x00,0x94}},
{LCM_SEND(2),{0xC5,0x90}},

//{LCM_SEND(2),{0x00,0xA0}},
//{LCM_SEND(12),{10,0,0xF6,0x8F,0x01,0x23,0x45,0x67,0x89,0xAB,0xcd,0xEF}},  //bist mode

//{LCM_SEND(2),{0x00,0xA9}},
//{LCM_SEND(2),{0xf6,0x5A}},  //bist mode

{LCM_SEND(2),{0x00,0xc1}},
{LCM_SEND(2),{0xC5,0x66}},

{LCM_SEND(2),{0x00,0x89}},
{LCM_SEND(2),{0xF3,0x5A}},

{LCM_SEND(2),{0x00,0x90}},
{LCM_SEND(2),{0xF3,0x01}},

{LCM_SEND(2),{0x00,0x82}},
{LCM_SEND(2),{0xA5,0x1F}},

{LCM_SEND(2),{0x00,0xC2}},  
{LCM_SEND(2),{0xC5,0x1E}},    

{LCM_SEND(2),{0x00,0xA8}},  
{LCM_SEND(2),{0xC4,0x12}},

{LCM_SEND(2),{0x00,0xA0}},  
{LCM_SEND(7),{5,0,0xC4,0x30,0x26,0x04,0x3A}},

{LCM_SEND(2),{0x00,0xA4}},  
{LCM_SEND(7),{5,0,0xC4,0x30,0x26,0x84,0x3A}},

{LCM_SEND(2),{0x00,0xE1}},  
{LCM_SEND(2),{0xF5,0x45}},

{LCM_SEND(2),{0x00,0xA8}},  
{LCM_SEND(2),{0xC4,0x12}},

{LCM_SEND(1),{0x11}},
{LCM_SLEEP(120)},
{LCM_SEND(1),{0x29}},
{LCM_SLEEP(50)},

};


static LCM_Force_Cmd_Code rd_prep_code[]={
//	{0x39, {LCM_SEND(8), {0x6, 0, 0xF0, 0x55, 0xAA, 0x52, 0x08, 0x01}}},
	{0x37, {LCM_SEND(2), {0x5, 0}}},
};

static int32_t otm1901_mipi_init(struct panel_spec *self)
{
	int32_t i = 0;
	LCM_Init_Code *init = init_data;
	unsigned int tag;

	mipi_set_cmd_mode_t mipi_set_cmd_mode = self->info.mipi->ops->mipi_set_cmd_mode;
	mipi_gen_write_t mipi_gen_write = self->info.mipi->ops->mipi_gen_write;

	LCD_PRINT("otm1901_mipi_init\n");

	mipi_set_cmd_mode();

	for(i = 0; i < ARRAY_SIZE(init_data); i++){
		tag = (init->tag >>24);
		if(tag & LCM_TAG_SEND){
			mipi_gen_write(init->data, (init->tag & LCM_TAG_MASK));
			udelay(20);
		}else if(tag & LCM_TAG_SLEEP){
			mdelay((init->tag & LCM_TAG_MASK));
		}
		init++;
	}
	return 0;
}

static uint32_t otm1901_readid(struct panel_spec *self)
{
	/*Jessica TODO: need read id*/
	int32_t i = 0;
	uint32_t j =0;
	LCM_Force_Cmd_Code * rd_prepare = rd_prep_code;
	uint8_t read_data[5] = {0};
	int32_t read_rtn = 0;
	unsigned int tag = 0;

	mipi_set_cmd_mode_t mipi_set_cmd_mode = self->info.mipi->ops->mipi_set_cmd_mode;
	mipi_force_write_t mipi_force_write = self->info.mipi->ops->mipi_force_write;
	mipi_force_read_t mipi_force_read = self->info.mipi->ops->mipi_force_read;
	mipi_eotp_set_t mipi_eotp_set = self->info.mipi->ops->mipi_eotp_set;

	LCD_PRINT("lcd_otm1901_mipi read id!\n");

	mipi_set_cmd_mode();
	mipi_eotp_set(1,0);

	for(j = 0; j < 4; j++){
		rd_prepare = rd_prep_code;
		for(i = 0; i < ARRAY_SIZE(rd_prep_code); i++){
			tag = (rd_prepare->real_cmd_code.tag >> 24);
			if(tag & LCM_TAG_SEND){
				mipi_force_write(rd_prepare->datatype, rd_prepare->real_cmd_code.data, (rd_prepare->real_cmd_code.tag & LCM_TAG_MASK));
			}else if(tag & LCM_TAG_SLEEP){
				mdelay((rd_prepare->real_cmd_code.tag & LCM_TAG_MASK));
			}
			rd_prepare++;
		}
		read_rtn = mipi_force_read(0xa1, 5,(uint8_t *)read_data);
		printk("lcd_otm1901_mipi read id 0xf4 value is 0x%x, 0x%x, 0x%x, 0x%x, 0x%x!\n", read_data[0], read_data[1], read_data[2], read_data[3], read_data[4]);

		if(0x19 == read_data[2]){
			printk("lcd_otm1901_mipi read id success!\n");
			mipi_eotp_set(1,1);
                     i2c_set_bus_num(3); //iwhale2 5
                     i2c_reg_write(0x3E, 0x00, 0x12);
                     i2c_reg_write(0x3E, 0x01, 0x10);
                     mdelay(50);			
			return 0x1901;
		}
	}
	mipi_eotp_set(1,1);
	return 0x0;
}

int32_t otm1901_reset(struct panel_spec *self)
{
	sprd_gpio_request(NULL, LCM_GPIO_AVDDEN);
	sprd_gpio_direction_output(NULL, LCM_GPIO_AVDDEN, 1);
	mdelay(10);

	sprd_gpio_request(NULL, LCM_GPIO_AVEEEN);
	sprd_gpio_direction_output(NULL, LCM_GPIO_AVEEEN, 1);
	mdelay(20);

	sprd_gpio_request(NULL, LCM_GPIO_RSTN);
	sprd_gpio_direction_output(NULL, LCM_GPIO_RSTN,1);
	mdelay(20);
	sprd_gpio_direction_output(NULL, LCM_GPIO_RSTN, 0);
	mdelay(20);
	sprd_gpio_direction_output(NULL, LCM_GPIO_RSTN, 1);
	mdelay(120);

	return 0;
}

static struct panel_operations lcd_otm1901_mipi_operations = {
	.panel_init = otm1901_mipi_init,
	.panel_readid = otm1901_readid,
	.panel_reset = otm1901_reset,
};

static struct timing_rgb lcd_otm1901_mipi_timing = {
	.hfp = 143,  /* unit: pixel */
	.hbp =37,//80
	.hsync = 20,//4//10
	.vfp = 50, /*unit: line*/
	.vbp = 26,//32
	.vsync =4,//4//4
};

static struct info_mipi lcd_otm1901_mipi_info = {
	.work_mode				= SPRDFB_MIPI_MODE_VIDEO,
	.video_bus_width		= 24, /*18,16*/
	.lan_number				= 4,
	.phy_feq				= 9798*100,
	.h_sync_pol				= SPRDFB_POLARITY_POS,
	.v_sync_pol				= SPRDFB_POLARITY_POS,
	.de_pol					= SPRDFB_POLARITY_POS,
	.te_pol					= SPRDFB_POLARITY_POS,
	.color_mode_pol			= SPRDFB_POLARITY_NEG,
	.shut_down_pol			= SPRDFB_POLARITY_NEG,
	.timing					= &lcd_otm1901_mipi_timing,
	.ops					= NULL,
};

struct panel_spec lcd_otm1901_mipi_spec = {
	.width					= 1080,
	.height					= 1920,
	.fps					= 60,
	.type					= LCD_MODE_DSI,
	.direction				= LCD_DIRECT_NORMAL,
	.info = {
		.mipi				= &lcd_otm1901_mipi_info
	},
	.ops					= &lcd_otm1901_mipi_operations,
};



