{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {inherit system;};
        init = pkgs.writeShellScriptBin "init" /* bash */
        ''
          cp ./template.cpp $1 && nvim $1
        '';
        run = pkgs.writeShellScriptBin "run" /* bash */
        ''
          [ "$(date -r $1 +%s)" -gt "$(date -r main +%s)" ] && g++ -std=c++20 -O0 -g $1 -o main
          ./main < input
        '';
      in {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [ 
            init
            run
            gcc
            clang-tools
            lldb
            gdb
            (pkgs.python312.withPackages (python-pkgs: [
              python-pkgs.requests
              python-pkgs.lxml
            ]))
          ];

          postShellHook = /* bash */
            ''
              source ${pkgs.just}/share/fish/vendor_completions.d/just.fish
            '';
        };
      });
}
