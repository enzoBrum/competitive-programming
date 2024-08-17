with import <nixpkgs> {}; {
  qpidEnv = stdenvNoCC.mkDerivation {
    name = "my-gcc8-environment";
    buildInputs = [
        gcc12
        go
        gdb
        swig
        # libev
        #...
    ];
  };
}
