llvt
====

llvt stands for low-level vision toolbox. This toolbox factorizes some
routines which are both used in the server and client packages.

Setup
-----

To compile this package, it is recommended to create a separate build
directory:

    mkdir _build
    cd _build
    cmake [OPTIONS] ..
    make install

Please note that CMake produces a `CMakeCache.txt` file which should
be deleted to reconfigure a package from scratch.


### Dependencies

The package depends on several packages which have to be available on
your machine.

 - System tools:
   - [jrl-cmakemodules][jrl-cmakemodules]
   - CMake (>=2.6)
   - pkg-config
   - usual compilation tools (GCC/G++, make, etc.)


[jrl-cmakemodules] http://github.com/jrl-umi3218/jrl-cmakemodules
