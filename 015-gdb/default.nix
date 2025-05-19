with import <nixpkgs> {}; stdenv.mkDerivation {

  name = "demo";

  src = ./.;

  nativeBuildInputs = with pkgs; [
    pkg-config
    sqlite
    libyaml
  ];

  buildPhase = ''
    mkdir -p "$out/bin"
    make bin/$name
  '';

  installPhase = ''
    cp bin/* $out/bin/
  '';

}
