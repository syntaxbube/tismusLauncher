// SPDX-License-Identifier: GPL-3.0-only
#include "TismusClassicTheme.h"

#include <QObject>

QString TismusClassicTheme::id()
{
    return "tismus98";
}

QString TismusClassicTheme::name()
{
    return QObject::tr("Tismus 98");
}

QPalette TismusClassicTheme::colorScheme()
{
    QPalette palette;
    palette.setColor(QPalette::Window, QColor("#c2b69e"));
    palette.setColor(QPalette::WindowText, QColor("#281d12"));
    palette.setColor(QPalette::Base, QColor("#f2ead8"));
    palette.setColor(QPalette::AlternateBase, QColor("#e4d9c3"));
    palette.setColor(QPalette::ToolTipBase, QColor("#fff5dc"));
    palette.setColor(QPalette::ToolTipText, QColor("#281d12"));
    palette.setColor(QPalette::Text, QColor("#281d12"));
    palette.setColor(QPalette::Button, QColor("#c9bea8"));
    palette.setColor(QPalette::ButtonText, QColor("#281d12"));
    palette.setColor(QPalette::BrightText, QColor("#a00000"));
    palette.setColor(QPalette::Link, QColor("#73441e"));
    palette.setColor(QPalette::Highlight, QColor("#855c37"));
    palette.setColor(QPalette::HighlightedText, QColor("#fff7e9"));
    palette.setColor(QPalette::PlaceholderText, QColor("#756750"));
    palette.setColor(QPalette::Light, QColor("#fff9e9"));
    palette.setColor(QPalette::Midlight, QColor("#e2d5bc"));
    palette.setColor(QPalette::Mid, QColor("#a6987e"));
    palette.setColor(QPalette::Dark, QColor("#76664c"));
    palette.setColor(QPalette::Shadow, QColor("#443421"));
    return fadeInactive(palette, fadeAmount(), fadeColor());
}

QColor TismusClassicTheme::fadeColor()
{
    return QColor("#c2b69e");
}

double TismusClassicTheme::fadeAmount()
{
    return 0.45;
}

bool TismusClassicTheme::hasStyleSheet()
{
    return true;
}

QString TismusClassicTheme::appStyleSheet()
{
    return R"(
        * {
            border-radius: 0px;
            font-family: "MS Sans Serif", Tahoma, sans-serif;
            font-size: 9pt;
        }

        QMainWindow, QDialog, QWidget {
            color: #281d12;
        }

        QToolBar {
            background: #c2b69e;
            border: 0;
            spacing: 2px;
            padding: 3px;
        }

        QToolBar::handle {
            background: #a6987e;
            border-top: 1px solid #fff9e9;
            border-left: 1px solid #fff9e9;
            border-right: 1px solid #76664c;
            border-bottom: 1px solid #76664c;
        }

        QPushButton, QToolButton, QComboBox, QSpinBox, QDoubleSpinBox {
            background: #c9bea8;
            border-top: 1px solid #fff9e9;
            border-left: 1px solid #fff9e9;
            border-right: 1px solid #76664c;
            border-bottom: 1px solid #76664c;
            padding: 3px 7px;
            min-height: 18px;
        }

        QPushButton:hover, QToolButton:hover, QComboBox:hover {
            background: #d6c9b1;
        }

        QPushButton:pressed, QToolButton:pressed, QToolButton:checked {
            border-top: 1px solid #76664c;
            border-left: 1px solid #76664c;
            border-right: 1px solid #fff9e9;
            border-bottom: 1px solid #fff9e9;
            padding-top: 4px;
            padding-left: 8px;
        }

        QLineEdit, QPlainTextEdit, QTextEdit, QTreeView, QTableView, QListView {
            background: #f2ead8;
            border-top: 1px solid #76664c;
            border-left: 1px solid #76664c;
            border-right: 1px solid #fff9e9;
            border-bottom: 1px solid #fff9e9;
            selection-background-color: #855c37;
            selection-color: #fff7e9;
        }

        QHeaderView::section {
            background: #c9bea8;
            border-top: 1px solid #fff9e9;
            border-left: 1px solid #fff9e9;
            border-right: 1px solid #76664c;
            border-bottom: 1px solid #76664c;
            padding: 4px 6px;
        }

        QTabWidget::pane {
            border: 1px solid #76664c;
            background: #c2b69e;
        }

        QTabBar::tab {
            background: #c9bea8;
            border-top: 1px solid #fff9e9;
            border-left: 1px solid #fff9e9;
            border-right: 1px solid #76664c;
            border-bottom: 1px solid #76664c;
            padding: 4px 9px;
            margin-right: 2px;
        }

        QTabBar::tab:selected {
            background: #e4d9c3;
            border-bottom-color: #e4d9c3;
        }

        QMenu {
            background: #e4d9c3;
            border: 1px solid #51402b;
            padding: 2px;
        }

        QMenu::item {
            padding: 4px 24px 4px 24px;
        }

        QMenu::item:selected {
            background: #855c37;
            color: #fff7e9;
        }

        QProgressBar {
            background: #f2ead8;
            border-top: 1px solid #76664c;
            border-left: 1px solid #76664c;
            border-right: 1px solid #fff9e9;
            border-bottom: 1px solid #fff9e9;
            text-align: center;
        }

        QProgressBar::chunk {
            background: #855c37;
        }

        QToolTip {
            color: #281d12;
            background: #fff5dc;
            border: 1px solid #51402b;
            padding: 3px;
        }
    )";
}

QString TismusClassicTheme::tooltip()
{
    return QObject::tr("Warm brown, raised buttons and old desktop styling");
}
