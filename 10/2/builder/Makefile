all:
	gcc -g -m32 -Wall -DXML_BUILDER_DUMP_TEST xml_builder_dump.c -o xml_builder_dump_test
	gcc -g -m32 -Wall -DXML_PARSER_TEST xml_parser.c xml_builder_dump.c xml_builder_tree.c xml_tree.c xml_parser_test.c -o xml_parser_test
	gcc -g -m32 -Wall -DXML_TREE_TEST xml_tree.c xml_builder_dump.c -o xml_tree_test
	gcc -g -m32 -Wall -DXML_BUILDER_TREE_TEST xml_builder_tree.c xml_tree.c xml_builder_dump.c -o xml_builder_tree_test
clean:
	rm -f *test
