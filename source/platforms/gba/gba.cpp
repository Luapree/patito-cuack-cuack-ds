#include "platforms.hpp"

#include "bn_core.h"
#include <bn_regular_bg_ptr.h>
#include "bn_sound_items.h"
#include "bn_sound.h"
#include "bn_regular_bg_items_pato.h"

int platform_init() {
	bn::core::init();
    bn::sound::play(bn::sound_items::patito_gba);
	bn::regular_bg_ptr regular_bg = bn::regular_bg_items::pato.create_bg(0, 0);

return 0;
}

int platform_frame() {
	bn::core::update();
	return 0;
}