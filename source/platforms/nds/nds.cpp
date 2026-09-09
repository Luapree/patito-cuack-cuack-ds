#include "platforms.hpp"

#include <stdio.h>
#include <unistd.h>
#include <nds.h>
#include <maxmod9.h>
#include "pato.h"
#include "soundbank_bin.h"
#include "soundbank.h"

int platform_init() {

// set the mode for 2 text layers and two extended background layers
	videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	consoleDemoInit();

	mmInitDefaultMem((mm_addr)soundbank_bin);
	mmLoadEffect( SFX_PATITO_NDS );

	int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0,0);

	dmaCopy(patoBitmap, bgGetGfxPtr(bg3), 256*256);
	dmaCopy(patoPal, BG_PALETTE, 256*2);
	mmEffect( SFX_PATITO_NDS );
	return 0;
}

int platform_frame() {
	swiWaitForVBlank();
	sleep(8);
	return 0;
}