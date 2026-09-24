#!/bin/bash

LAUNCHER_APPID="org.tismuslauncher.TismusLauncher"
LAUNCHER_BASENAME="tismuslauncher"

svg2png() {
    local input_file="$1"
    local output_file="$2"
    local width="$3"
    local height="$4"

    inkscape -w "$width" -h "$height" -o "$output_file" "$input_file"
}

if command -v inkscape >/dev/null && command -v icotool >/dev/null && command -v oxipng >/dev/null; then
    # Windows ICO
    d=$(mktemp -d)
    for size in 16 24 32 48 64 128 256; do
        svg2png "${LAUNCHER_APPID}.svg" "$d/${LAUNCHER_BASENAME}_${size}.png" "$size" "$size"
    done

    oxipng --opt max --strip all --alpha --interlace 0 "$d/${LAUNCHER_BASENAME}_"*".png"
    icotool -o "${LAUNCHER_BASENAME}.ico" -c \
        "$d/${LAUNCHER_BASENAME}_256.png" \
        "$d/${LAUNCHER_BASENAME}_128.png" \
        "$d/${LAUNCHER_BASENAME}_64.png" \
        "$d/${LAUNCHER_BASENAME}_48.png" \
        "$d/${LAUNCHER_BASENAME}_32.png" \
        "$d/${LAUNCHER_BASENAME}_24.png" \
        "$d/${LAUNCHER_BASENAME}_16.png"
    rm -rf "$d"
else
    echo "ERROR: Windows icons were NOT generated!" >&2
    echo "ERROR: requires inkscape, icotool and oxipng in PATH" >&2
fi

if command -v inkscape >/dev/null && command -v iconutil >/dev/null && command -v oxipng >/dev/null; then
    # macOS ICNS
    d=$(mktemp -d)
    iconset="$d/${LAUNCHER_BASENAME}.iconset"
    mkdir -p "$iconset"

    svg2png "${LAUNCHER_APPID}.bigsur.svg" "$iconset/icon_16x16.png" 16 16
    svg2png "${LAUNCHER_APPID}.bigsur.svg" "$iconset/icon_16x16@2x.png" 32 32
    svg2png "${LAUNCHER_APPID}.bigsur.svg" "$iconset/icon_32x32.png" 32 32
    svg2png "${LAUNCHER_APPID}.bigsur.svg" "$iconset/icon_32x32@2x.png" 64 64
    svg2png "${LAUNCHER_APPID}.bigsur.svg" "$iconset/icon_128x128.png" 128 128
    svg2png "${LAUNCHER_APPID}.bigsur.svg" "$iconset/icon_128x128@2x.png" 256 256
    svg2png "${LAUNCHER_APPID}.bigsur.svg" "$iconset/icon_256x256.png" 256 256
    svg2png "${LAUNCHER_APPID}.bigsur.svg" "$iconset/icon_256x256@2x.png" 512 512
    svg2png "${LAUNCHER_APPID}.bigsur.svg" "$iconset/icon_512x512.png" 512 512
    svg2png "${LAUNCHER_APPID}.bigsur.svg" "$iconset/icon_512x512@2x.png" 1024 1024

    oxipng --opt max --strip all --alpha --interlace 0 "$iconset/icon_"*".png"
    iconutil -c icns "$iconset"
    cp -v "$d/${LAUNCHER_BASENAME}.icns" .
    rm -rf "$d"
else
    echo "ERROR: macOS icons were NOT generated!" >&2
    echo "ERROR: requires inkscape, iconutil and oxipng in PATH" >&2
fi

cp -v "${LAUNCHER_APPID}.svg" "../launcher/resources/multimc/scalable/launcher.svg"
