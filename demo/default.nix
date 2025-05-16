with import <nixpkgs> {}; stdenv.mkDerivation {

  name = "demo";

  src = ./src;
  includes = ./includes;

  nativeBuildInputs = with pkgs; [
    pkg-config
    sqlite
    libyaml
  ];

  buildPhase = ''
    mkdir -p "$out/bin"
    gcc -o $out/bin/demo $src/foo.c $src/main.c -I$includes `pkg-config --cflags yaml-0.1 sqlite3` -Wall -Wextra -pedantic -std=c18  -lyaml -lsqlite3
  '';

}
