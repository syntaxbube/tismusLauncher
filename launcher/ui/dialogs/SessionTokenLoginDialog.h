// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "minecraft/auth/MinecraftAccount.h"

class QWidget;

class SessionTokenLoginDialog {
   public:
    static MinecraftAccountPtr newAccount(QWidget* parent);
};
