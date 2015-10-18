# library : cut_installer
# -- Version
set(installer_maj_ver 0)
set(installer_min_ver 0)
set(installer_pat_ver 1)

set(installer_lib_ver
    "${installer_maj_ver}.${installer_min_ver}.${installer_pat_ver}")

set(installer_lib_compat_ver
    "${installer_maj_ver}.${installer_min_ver}")

# -- Headers
# export
set(installer_exp_hdr
    include/cut/installer/setup.h)

# internal
set(installer_int_hdr
    )

# -- Sources
set(installer_src
    src/cut/installer/setup.c)

# -- Targets

# The shared library is not installed, and not used outside this project.
# We therefore generate a static library that is not installed.

# # --- shared
# add_lib(cut_installer SHARED ${installer_src} ${installer_int_hdr} ${installer_exp_hdr})
# add_lib_build_def(cut_installer include/cut/installer/exportsym.h INSTALLER)
# add_comp_def(cut_installer INSTALLER_MAJ=${installer_maj_ver})
# add_comp_def(cut_installer INSTALLER_MIN=${installer_min_ver})
# add_comp_def(cut_installer INSTALLER_PAT=${installer_pat_ver})
# link_libs(cut_installer )
# set_tgt_ver(cut_installer ${installer_lib_ver} ${installer_lib_compat_ver})

# --- static
add_lib(cut_installer_s STATIC ${installer_src} ${installer_int_hdr} ${installer_exp_hdr})
add_lib_build_def(cut_installer_s include/cut/installer/exportsym.h INSTALLER)
add_comp_def(cut_installer_s INSTALLER_MAJ=${installer_maj_ver})
add_comp_def(cut_installer_s INSTALLER_MIN=${installer_min_ver})
add_comp_def(cut_installer_s INSTALLER_PAT=${installer_pat_ver})
link_libs(cut_installer_s )
set_tgt_ver(cut_installer_s ${installer_lib_ver} ${installer_lib_compat_ver})

# # -- Install!
# install_hdr(${installer_exp_hdr})
# install_tgt(cut_installer)
# install_tgt(cut_installer_s)
