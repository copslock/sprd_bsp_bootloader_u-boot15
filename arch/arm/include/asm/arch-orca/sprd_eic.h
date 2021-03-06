#ifndef _SPRD_REG_EIC_H_
#define _SPRD_REG_EIC_H_

/* pmic eic */
#define SPRD_ADIE_EIC_START			160
#define SPRD_ADIE_EIC_END			167

#define EIC_CHG_INT				160
#define EIC_PBINT				161
#define EIC_PBINT2				162
#define EIC_BATDET				163
#define EIC_KEY2_7S_RST_EXT_RSTN_ACTIVE		164
#define EIC_EXT_XTL_EN0				165
#define EIC_AUDIO_INT_ALL			166
#define EIC_ENDURA_OPTION			167

/* d-die eic */
#define SPRD_DDIE_EIC_START			0
#define SPRD_DDIE_EIC_END			7
#define SPRD_DDIE_EIC1_START			8
#define SPRD_DDIE_EIC1_END			15

#define SPRD_DDIE_EIC_KEYIN0			2
#define SPRD_DDIE_EIC_EXTINT2			0
#define SPRD_DDIE_EIC_EXTINT3			3

#endif
