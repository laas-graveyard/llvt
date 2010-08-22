prefix=${CMAKE_INSTALL_PREFIX}
exec_prefix=${install_pkg_prefix}
libdir=${install_pkg_exec_prefix}/lib
includedir=${install_pkg_prefix}/include
datarootdir=${install_pkg_prefix}/share
docdir=${install_pkg_datarootdir}/doc/${PROJECT_NAME}

Name: ${PROJECT_NAME}
Description: Low Level Vision Toolbox
Version: ${PROJECT_VERSION}
Requires: ${PROJECT_REQUIREMENTS}
Cflags: -I${install_pkg_include_dir} 
