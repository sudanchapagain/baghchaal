with import <nixpkgs> { };

mkShell {
    buildInputs = [
        raylib
        pkg-config
    ];
}
