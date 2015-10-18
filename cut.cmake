# library : cut
# -- Version
set(cut_maj_ver 0)
set(cut_min_ver 0)
set(cut_pat_ver 1)

set(cut_lib_ver
    "${cut_maj_ver}.${cut_min_ver}.${cut_pat_ver}")

set(cut_lib_compat_ver
    "${cut_maj_ver}.${cut_min_ver}")

# -- Headers
# export
set(cut_exp_hdr
    include/cut/common/version.h;
    include/cut/common/inline.h;
    include/cut/common/likely.h;
    include/cut/common/allocator.h)

# internal
set(cut_int_hdr
    )

# -- Sources
set(cut_src
    src/cut/common/version.c;
    src/cut/common/allocator.c)

# -- Targets
# --- shared
add_lib(cut SHARED ${cut_src} ${cut_int_hdr} ${cut_exp_hdr})
add_lib_build_def(cut include/cut/common/exportsym.h CUT)
add_comp_def(cut CUT_MAJ=${cut_maj_ver})
add_comp_def(cut CUT_MIN=${cut_min_ver})
add_comp_def(cut CUT_PAT=${cut_pat_ver})
link_libs(cut )
set_tgt_ver(cut ${cut_lib_ver} ${cut_lib_compat_ver})

# --- static
add_lib(cut_s STATIC ${cut_src} ${cut_int_hdr} ${cut_exp_hdr})
add_lib_build_def(cut_s include/cut/common/exportsym.h CUT)
add_comp_def(cut_s CUT_MAJ=${cut_maj_ver})
add_comp_def(cut_s CUT_MIN=${cut_min_ver})
add_comp_def(cut_s CUT_PAT=${cut_pat_ver})
link_libs(cut_s )
set_tgt_ver(cut_s ${cut_lib_ver} ${cut_lib_compat_ver})

# -- Install!
install_hdr(${cut_exp_hdr})
install_tgt(cut)
install_tgt(cut_s)
