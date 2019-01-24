all:
	gcc -g -m32 -Wall count_word.c -DCOUNT_WORD_TEST -o count_word_test
	gcc -g -m32 -Wall word_segmentation.c -DWORD_SEGMENTATION_TEST -o word_segmentation_test
	gcc -g -m32 -Wall parse_token.c -DPARSE_TOKEN_TEST -o parse_token_test
	gcc -g -m32 -Wall ini_parser.c -DINI_PARSER_TEST -o ini_parser_test
	gcc -g -m32 -Wall xml_parser.c -DXML_PARSER_TEST -o xml_parser_test

clean:
	rm -f *test
