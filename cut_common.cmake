# library : cut_common
# -- Version
set(cut_common_maj_ver 0)
set(cut_common_min_ver 0)
set(cut_common_pat_ver 1)

set(cut_common_lib_ver
    "${cut_common_maj_ver}.${cut_common_min_ver}.${cut_common_pat_ver}")

set(cut_common_lib_compat_ver
    "${cut_common_maj_ver}.${cut_common_min_ver}")

# -- Headers
# export
set(cut_common_exp_hdr
    include/cut/common/version.h;
    include/cut/common/allocator.h)

# internal
set(cut_common_int_hdr
    )

# -- Sources
set(cut_common_src
    src/cut/common/version.c;
    src/cut/common/allocator.c)

# -- Targets
# --- shared
add_lib(cut_common SHARED ${cut_common_src} ${cut_common_int_hdr} ${cut_common_exp_hdr})
add_lib_build_def(cut_common include/cut/common/exportsym.h CUT_COMMON)
add_comp_def(cut_common CUT_COMMON_MAJ=${cut_common_maj_ver})
add_comp_def(cut_common CUT_COMMON_MIN=${cut_common_min_ver})
add_comp_def(cut_common CUT_COMMON_PAT=${cut_common_pat_ver})
link_libs(cut_common )
set_tgt_ver(cut_common ${cut_common_lib_ver} ${cut_common_lib_compat_ver})

# --- static
add_lib(cut_common_s STATIC ${cut_common_src} ${cut_common_int_hdr} ${cut_common_exp_hdr})
add_lib_build_def(cut_common_s include/cut/cut_common/exportsym.h CUT_COMMON)
add_comp_def(cut_common_s CUT_COMMON_MAJ=${cut_common_maj_ver})
add_comp_def(cut_common_s CUT_COMMON_MIN=${cut_common_min_ver})
add_comp_def(cut_common_s CUT_COMMON_PAT=${cut_common_pat_ver})
link_libs(cut_common_s )
set_tgt_ver(cut_common_s ${cut_common_lib_ver} ${cut_common_lib_compat_ver})

# -- Install!
install_hdr(${cut_common_exp_hdr})
install_tgt(cut_common)
install_tgt(cut_common_s)
