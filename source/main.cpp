// codigo crudamente robado de uno de los ejemplos de devkitpro de graficos, lo unico que añadi fue el audio
#include <nds.h>
#include <stdio.h>
#include <unistd.h>
#include <maxmod9.h>
#include "pato.h"
#include "soundbank_bin.h"
#include "soundbank.h"

int main(void)
{
    // set the mode for 2 text layers and two extended background layers
	videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	consoleDemoInit();

	mmInitDefaultMem((mm_addr)soundbank_bin);
	mmLoadEffect( SFX_PATITO );

	int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0,0);

	dmaCopy(patoBitmap, bgGetGfxPtr(bg3), 256*256);
	dmaCopy(patoPal, BG_PALETTE, 256*2);
	mmEffect( SFX_PATITO );

	while(pmMainLoop()) {
		swiWaitForVBlank();
		scanKeys();
		sleep(8); // duerme por 8 segundos, duracion del audio, y luego apaga la consola o vuelve al twilight menu/flashcart
			break;
	}

	return 0;
}
