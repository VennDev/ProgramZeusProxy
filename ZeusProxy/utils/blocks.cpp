#include "blocks.h"

namespace utils
{
    std::vector<int> blocks::get_stairs()
    {
        return std::vector<int> {
            acacia_stairs,
            birch_stairs,
            brick_stairs,
            cobblestone_stairs,
            dark_oak_stairs,
            jungle_stairs,
            nether_brick_stairs,
            oak_stairs,
            quartz_stairs,
            red_sandstone_stairs,
            sandstone_stairs,
            spruce_stairs,
            stone_brick_stairs,
            wooden_stairs
        };
    }

    std::vector<int> blocks::get_slippery()
    {
        return std::vector<int> {
            ice,
            packed_ice,
            blue_ice,
            frosted_ice
        };
    }

    std::vector<int> blocks::get_liquid()
    {
        return std::vector<int> {
            water,
            flowing_water,
            lava,
            flowing_lava
        };
    }

    std::vector<int> blocks::get_adhesive()
    {
        return std::vector<int> {
            vine,
            ladder,
            scaffolding
        };
    }

    std::vector<int> blocks::get_elastomers()
    {
        return std::vector<int> {
            cobweb,
            slime_block,
            honey_block
        };
    }

    std::vector<int> blocks::get_web()
    {
        return std::vector<int> {
            cobweb
        };
    }

    std::vector<int> blocks::get_plants()
    {
        return std::vector<int> {
            carrot_block,
            potato_block,
            wheat_block,
            tall_grass,
            sugar_cane_block,
            bamboo_block,
            pumpkin_stem,
            melon_stem,
            nether_wart_block,
            cocoa_block,
            chorus_plant,
            dead_bush,
            sweet_berry_bush,
            sapling,
            sea_grass,
            red_flower,
            chorus_flower,
            double_plant,
            flower_pot_block
        };
    }

}