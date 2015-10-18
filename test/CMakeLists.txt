# TEST: sub module

add_test_exe    (tCommonVersion tCommonVersion.c)
test_link_libs  (tCommonVersion cut)
create_test     (tCommonVersion)

add_test_exe    (tCommonAllocator tCommonAllocator.c)
test_link_libs  (tCommonAllocator cut)
create_test     (tCommonAllocator)
