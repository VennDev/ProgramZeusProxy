#pragma once

#ifndef PROTOCOLS_H
#define PROTOCOLS_H

#include "../compat/packet.h"
#include "packet_keep_alive.h"
#include "packet_player_arm_animation.h"
#include "packet_player_break_block.h"
#include "packet_player_login.h"
#include "packet_player_logout.h"
#include "packet_player_place_block.h"
#include "packet_player_position.h"
#include "packet_play_in_change_mode.h"
#include "packet_play_in_close_window.h"
#include "packet_play_in_death.h"
#include "packet_play_in_held_item_slot.h"
#include "packet_play_in_rotation.h"
#include "packet_play_in_sneaking.h"
#include "packet_play_in_sprinting.h"
#include "packet_play_in_steer_vehicle.h"
#include "packet_play_in_transaction.h"
#include "packet_play_in_use_entity.h"
#include "packet_play_in_open_window.h"
#include "packet_play_out_blocks_down.h"
#include "packet_play_out_entity_effect.h"
#include "packet_play_out_entity_teleport.h"
#include "packet_play_out_explosion.h"
#include "packet_play_out_respawn.h"
#include "packet_play_out_transaction.h"

#include <nlohmann/json.hpp>

namespace protocols
{
    class protocol
    {
    public:
        int static const PACKET_PLAYER_LOGIN = 1;
        int static const PACKET_PLAYER_LOGOUT = 2;
        int static const PACKET_KEEP_ALIVE = 3;
        int static const PACKET_PLAYER_POSITION = 4;
        int static const PACKET_PLAYER_ARM_ANIMATION = 5;
        int static const PACKET_PLAYER_BREAK_BLOCK = 6;
        int static const PACKET_PLAYER_PLACE_BLOCK = 7;
        int static const PACKET_PLAY_IN_USE_ENTITY = 8;
        int static const PACKET_PLAY_IN_TRANSACTION = 9;
        int static const PACKET_PLAY_IN_ROTATION = 10;
        int static const PACKET_PLAY_IN_SNEAKING = 11;
        int static const PACKET_PLAY_IN_SPRINTING = 12;
        int static const PACKET_PLAY_OUT_RESPAWN = 13;
        int static const PACKET_PLAY_IN_DEATH = 14;
        int static const PACKET_PLAY_IN_HELD_ITEM_SLOT = 15;
        int static const PACKET_PLAY_IN_CHANGE_MODE = 16;
        int static const PACKET_PLAY_IN_STEER_VEHICLE = 17;
        int static const PACKET_PLAY_IN_CLOSE_WINDOW = 18;
        int static const PACKET_PLAY_IN_OPEN_WINDOW = 19;
        int static const PACKET_PLAY_OUT_EXPLOSION = 20;
        int static const PACKET_PLAY_OUT_ENTITY_TELEPORT = 21;
        int static const PACKET_PLAY_OUT_ENTITY_EFFECT = 22;
        int static const PACKET_PLAY_OUT_TRANSACTION = 23;
        int static const PACKET_PLAY_OUT_BLOCKS_DOWN = 24;

        static packet* process_data_packet(nlohmann::json data);
    };
}

#endif