// SPDX-License-Identifier: GPL-3.0-only
#include "SessionTokenLoginDialog.h"

#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>

#include "ui/dialogs/ProgressDialog.h"

MinecraftAccountPtr SessionTokenLoginDialog::newAccount(QWidget* parent)
{
    bool accepted = false;
    const QString accessToken = QInputDialog::getText(
                                   parent, QObject::tr("Add session token"),
                                   QObject::tr("Enter one Minecraft Java access token. It is saved without extra encryption in this launcher's local account data. Add other accounts one at a time. Expired tokens must be entered again."),
                                   QLineEdit::Password, QString(), &accepted)
                                   .trimmed();
    if (!accepted || accessToken.isEmpty()) {
        return nullptr;
    }

    auto account = MinecraftAccount::createSessionToken(accessToken);
    auto authFlow = account->login();
    ProgressDialog progress(parent);
    if (progress.execWithTask(authFlow.get()) != QDialog::Accepted) {
        const QString reason = authFlow->failReason();
        if (!reason.isEmpty()) {
            QMessageBox::warning(parent, QObject::tr("Session token rejected"), reason);
        }
        return nullptr;
    }

    return account;
}
