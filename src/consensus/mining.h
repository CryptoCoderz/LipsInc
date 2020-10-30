// Copyright (c) 2016-2020 The CryptoCoderz Team / LipsInc
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef LIPSINC_MINING_H
#define LIPSINC_MINING_H

#include "primitives/bignum.h"

/** Minimum nCoinAge required to stake PoS (v2) */
static const unsigned int nStakeMinAge = 1 * 60 * 60; // DEPRICATED, REMOVE IN FUTURE UPDATE
/** Minimum nCoinAge required to stake PoS (v3) */
static const int nStakeMinConfirmations = 10; // 5(minutes) × 10(confirms) ÷ 60(minutes) = ~0.9 hours
/** Time to elapse before new modifier is computed */
static const unsigned int nModifierInterval = 5 * 60;
/** Block spacing preferred */
static const int64_t BLOCK_SPACING = 5 * 60;
/** Block spacing minimum */
static const int64_t BLOCK_SPACING_MIN = 3.5 * 60;
/** Block spacing maximum */
static const int64_t BLOCK_SPACING_MAX = 7.5 * 60;
/** Genesis block subsidy */
static const int64_t nGenesisBlockReward = 1 * COIN;
/** Starting block subsidy */
static const int64_t nBlockReward = 50 * COIN;
/** Reserve Phase reward */
static const int64_t nReservePhaseAmount = 5000000 * COIN;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int nCoinbaseMaturity = 10;

#endif
