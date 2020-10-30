// Copyright (c) 2016-2020 The CryptoCoderz Team / LipsInc
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef LIPSINC_FORK_H
#define LIPSINC_FORK_H

#include "primitives/bignum.h"

/** Genesis Block Height */
static const int64_t nGenesisHeight = 0;
/** PoS Phase start block */
static const int64_t nPoSPhaseStart = 0; // PoS reward starts on block 0
/** Velocity toggle block */
static const int64_t VELOCITY_TOGGLE = 100; // Implementation of the Velocity system into the chain.
/** Velocity retarget toggle block */
static const int64_t VELOCITY_TDIFF = 0; // Use Velocity's retargetting method.
/** Proof-of-Stake Version 3.0 implementation fork */
inline bool IsProtocolV3(int64_t nTime) { return TestNet() || nTime > 0; } // ON (TOGGLED)

#endif
