{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    nixpkgs-stable.url = "github:NixOS/nixpkgs/nixos-24.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, nixpkgs-stable, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {inherit system;};
        pkgs-stable = import nixpkgs-stable {inherit system;};
        run = pkgs.writeScriptBin "run" /* bash */
        ''
        if [ "$TERM" = "xterm-256color" ]; then
          EDITOR="code -r"
        else
          EDITOR="nvim"
        fi
        cp template.cpp ''${2:-kattis}/"$1".cpp
        $EDITOR ''${2:-kattis}/"$1".cpp
        '';
      in {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [ 
            pkgs-stable.chntpw
            gcc
            clang-tools
            lldb
            gdb
            run
            (pkgs.python313.withPackages (python-pkgs: [
              python-pkgs.requests
              python-pkgs.lxml
            ]))
          ];
        };
      });
}
