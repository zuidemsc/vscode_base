add_test( read_button.NoPress /home/scott/gvsu/stm/vscode_base/build/test-all [==[--gtest_filter=read_button.NoPress]==] --gtest_also_run_disabled_tests)
set_tests_properties( read_button.NoPress PROPERTIES WORKING_DIRECTORY /home/scott/gvsu/stm/vscode_base/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( test-all_TESTS read_button.NoPress)
