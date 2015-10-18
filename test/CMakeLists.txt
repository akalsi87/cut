# TEST: sub module

add_test_exe    (tCommonVersion tCommonVersion.c)
test_link_libs  (tCommonVersion cut_common)
create_test     (tCommonVersion)
