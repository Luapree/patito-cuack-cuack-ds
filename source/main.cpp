#include "bn_core.h"
#include <bn_regular_bg_ptr.h>
#include "bn_sound_items.h"
#include "bn_sound.h"
#include "bn_regular_bg_items_pato.h"

int main(void)
{
    bn::core::init();
    bn::sound::play(bn::sound_items::patito);

    {
    bn::regular_bg_ptr pato = bn::regular_bg_items::pato.create_bg();
    while(1) {
        bn::core::update();
    }
    }
    return 0;
}
