
#
# Convert Apache's mime.types file to C++ declaration
#

BEGIN {
    printf "//\n// Generated from Apache's mime.types file by mimetypes.awk\n//\n\n\
const char* mimetypes[] = {\n";
}

NF > 1 && substr($0, 0, 1) != "#" {
    printf "    ";
    for (i = 2; i <= NF; i++)
	printf "\".%s\", ", $i;
    printf "\"%s\",\n", $1;
}


END {
    printf "    0,\n};\n";
}

