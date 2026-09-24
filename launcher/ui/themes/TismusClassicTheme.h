// SPDX-License-Identifier: GPL-3.0-only
#pragma once

#include "FusionTheme.h"

class TismusClassicTheme : public FusionTheme {
   public:
    QString id() override;
    QString name() override;
    QPalette colorScheme() override;
    QColor fadeColor() override;
    double fadeAmount() override;
    bool hasStyleSheet() override;
    QString appStyleSheet() override;
    QString tooltip() override;
};
