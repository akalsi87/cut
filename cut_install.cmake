# executable : install
# -- Version
set(install_maj_ver 0)
set(install_min_ver 0)
set(install_pat_ver 1)

set(install_lib_ver
    "${install_maj_ver}.${install_min_ver}.${install_pat_ver}")

set(install_lib_compat_ver
    "${install_maj_ver}.${install_min_ver}")

# -- Headers
# internal
set(install_int_hdr
    )

# -- Sources
set(install_src
    src/cut/install/main.c)

# -- Targets
# --- executable
add_exe(cut_install ${install_src} ${install_int_hdr})
add_comp_def(cut_install INSTALL_MAJ=${install_maj_ver})
add_comp_def(cut_install INSTALL_MIN=${install_min_ver})
add_comp_def(cut_install INSTALL_PAT=${install_pat_ver})
link_libs(cut_install cut_installer_s)
set_tgt_ver(cut_install ${install_lib_ver} ${install_lib_compat_ver})

# -- Install!
install_tgt(cut_install)
