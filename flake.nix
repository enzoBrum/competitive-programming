{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {inherit system;};
      in {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [ 
            gcc
            clang-tools
            lldb
            gdb
            (pkgs.python313.withPackages (python-pkgs: [
              python-pkgs.requests
              python-pkgs.lxml
            ]))
          ];
        };
      });
}
