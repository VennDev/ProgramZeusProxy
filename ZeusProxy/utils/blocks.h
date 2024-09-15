#pragma once

#ifndef BLOCKS_H
#define BLOCKS_H
#include <vector>

namespace utils
{
    class blocks
    {
    public:
        static constexpr int air = 0;
        static constexpr int ice = 79;
        static constexpr int packed_ice = 174;
        static constexpr int blue_ice = 266;
        static constexpr int frosted_ice = 207;
        static constexpr int water = 8;
        static constexpr int flowing_water = 9;
        static constexpr int lava = 10;
        static constexpr int flowing_lava = 11;
        static constexpr int cobweb = 30;
        static constexpr int torch = 50;
        static constexpr int slime_block = 165;
        static constexpr int vine = 106;
        static constexpr int ladder = 65;
        static constexpr int scaffolding = 420;
        static constexpr int acacia_stairs = 163;
        static constexpr int birch_stairs = 135;
        static constexpr int brick_stairs = 108;
        static constexpr int cobblestone_stairs = 67;
        static constexpr int dark_oak_stairs = 164;
        static constexpr int jungle_stairs = 136;
        static constexpr int nether_brick_stairs = 114;
        static constexpr int oak_stairs = 53;
        static constexpr int quartz_stairs = 156;
        static constexpr int red_sandstone_stairs = 180;
        static constexpr int sandstone_stairs = 128;
        static constexpr int spruce_stairs = 134;
        static constexpr int stone_brick_stairs = 109;
        static constexpr int wooden_stairs = 54;
        static constexpr int soul_sand = 88;
        static constexpr int grass_path = 198;
        static constexpr int carrot_block = 141;
        static constexpr int potato_block = 142;
        static constexpr int wheat_block = 59;
        static constexpr int tall_grass = 31;
        static constexpr int sugar_cane_block = 83;
        static constexpr int bamboo_block = 415;
        static constexpr int pumpkin_stem = 104;
        static constexpr int melon_stem = 105;
        static constexpr int nether_wart_block = 115;
        static constexpr int cocoa_block = 127;
        static constexpr int chorus_plant = 199;
        static constexpr int dead_bush = 32;
        static constexpr int sweet_berry_bush = 462;
        static constexpr int sapling = 6;
        static constexpr int sea_grass = 385;
        static constexpr int red_flower = 38;
        static constexpr int chorus_flower = 200;
        static constexpr int double_plant = 175;
        static constexpr int flower_pot_block = 140;
        static constexpr int honey_block = 421;

        static std::vector<int> get_stairs();

        static std::vector<int> get_slippery();

        static std::vector<int> get_liquid();

        static std::vector<int> get_adhesive();

        static std::vector<int> get_elastomers();

        static std::vector<int> get_web();

        static std::vector<int> get_plants();
        
    };
}

#endif