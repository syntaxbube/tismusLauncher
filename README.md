# tismusLauncher

tismusLauncher is an independent fork of [Prism Launcher](https://github.com/PrismLauncher/PrismLauncher), a Minecraft launcher for managing separate game instances, mod loaders and modpacks. It adds a warm brown theme inspired by classic desktop software.

This project is not Prism Launcher and is not endorsed by or affiliated with the Prism Launcher project.

## Build

See the upstream [build instructions](https://prismlauncher.org/wiki/development/build-instructions). This fork uses the same CMake and Qt build system.

Microsoft sign-in, CurseForge API access and Imgur uploads require API keys owned by this fork. Their default values are empty in `CMakeLists.txt`.

## Accounts

Use **Manage Accounts → Add Session Token** to add an existing Minecraft Java access token. Add one token per Minecraft profile; repeat the action to add more accounts. The launcher validates the token with Minecraft's profile and entitlement services. Session tokens are stored without extra encryption in the local account data and must be entered again after they expire.

## License and credits

The launcher code is licensed under GPL-3.0-only. Copyright and license notices from Prism Launcher, PolyMC and MultiMC are retained with the source files. Any remaining Prism Launcher logos and icons retain their original CC BY-SA 4.0 notices.
