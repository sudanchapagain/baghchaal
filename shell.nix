{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.libX11
    pkgs.libxrandr
    pkgs.libxi
    pkgs.libxcursor
    pkgs.libxinerama
    pkgs.mesa
    pkgs.raylib
    pkgs.pkg-config
  ];
}
