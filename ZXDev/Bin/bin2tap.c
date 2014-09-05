#define ADDRESS	32768
#define CLEAR	24575
#define RUN	32768
#define MAX_LEN	65535
#define VERSION	"bin2tap v.1.3"

#include <stdio.h>
#include <string.h>

int str2int (char *str, int *num) {
	int i=0;

	*num = 0;
	while (str[i] != 0) {
		if (str[i] <= '9' && str[i] >= '0') {
			*num *= 10;
			*num += str[i++] - '0';
		}
		else 
			return 1;
	}
	return 0;
}

void version (void) {
	printf(VERSION"\nCopyright (C) 2009 mike/zeroteam\n");
}

void usage (void) {
	version();
	printf("Usage: bin2tap [options] file.bin\n\nOptions:\n\
  -o output_file      output TAP file\n\
  -a address          start address of binary file [32768]\n\
  -b                  include BASIC loader\n\
  -c clear_address    CLEAR address in BASIC loader [24575]\n\
  -r run_address      address where to start bin. file for BASIC loader [32768]\n\
  -cb border_colour   border colour set by loader [0]\n\
  -cp paper_colour    paper colour set by loader [0]\n\
  -ci ink_colour      ink colour set by loader [7]\n\
  -d80                create D80 syntax loader\n\
  -append             append tap at end of file\n\
  -hp | --header-poke include POKE command for dissabling tape headers\n\
  -h  | --help        usage information\n\
  -v  | --version     version info\n\n");
}

void l_copy (char* tap, char* loader, int* tap_index, int* checksum, int len) {
	int i;
	for (i = 0; i < len; i++) {
/*		*(checksum) ^= *(tap+(*tap_index)) = *(loader++);
		*tap_index = *tap_index + 1; */
		*(checksum) ^= tap[(*tap_index)++] = *(loader++);
	}
}

int main (int argc, char *argv[]) {

	int	inputlen;		/* inputlen - input file lenght*/

	FILE	*foutput, *finput;	/* foutput - output file descriptor */
					/* finput - input file description */
	int	foutname_i = 0;		/* foutname_i - index to name in argv field */
	char	foutname[255];		/* foutname - output file name */
	int	finname_i = 0;		/* finname_i - index to name in argv field */

	int	checksum;		/* checksum - TAP checksum */
	int	i, in_name, no;		/* general purpose variables */

	int	address = ADDRESS;	/* address - start address of binary file */
	int	basic = 0;		/* basic - indicator of BASIC loader */
	int	clear = CLEAR;		/* clear - CLEAR value for BASIC loader */
	int	run = RUN;		/* run - address where to start binary file */
	int	cb = 0, cp = 0, ci = 7;	/* cb, cp, ci - colors for border, paper and ink*/
	int	d80 = 0;		/* d80 - indicate D80 loader */
	int	append = 0;		/* append - append result at EOF */
	int	hp = 0;			/* hp - add poke for header dissable */
	char	run_name[] = "run       "; /* run_name - alternative name of basic loader */

	char	loader_template[] = "\0\x0A\x16\0\xEAloader by bin2tap1.2\x0D\
\0\x14\x12\0\xE7\xB0\"\":\xDA\xB0\"\":\xD9\xB0\"\"\x0D\
\0\x1E\x0A\0\xFD\xB0\"\"\x0D\
\0\x28\x0F\0\xF4\xB0\"23739\",\xAF\"o\"\x0D\
\0\x32\x05\0\xEF\"\xAF\x0D\
\0\x3C\x0B\0\xF9\xC0\xB0\"\"\x0D";	/* loader - fiel for BASIC loader */

	char tap[49152+115], *loader;
	int tap_index = 0;

	loader = loader_template;
	for (i = 1; i<argc; i++) {
		if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
			usage();
			return 0;
		}
		if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version")) {
			version();
			return 0;
		}
		if (!strcmp(argv[i], "-o")) {
			foutname_i = ++i;
			continue;
		}
		if (!strcmp(argv[i], "-a")) {
			if (str2int(argv[++i], &address)) {
				fprintf(stderr, "After -a must follow decadic address !\n");
				return 1;
			}
			if (address > 65535) {
				fprintf(stderr, "Maximum number after -a is 65535!\n");
				return 1;
			}
			continue;
		}
		if (!strcmp(argv[i], "-b")) {
			basic = 1;
			continue;
		}
		if (!strcmp(argv[i], "-c")) {
			if (str2int(argv[++i], &clear)) {
				fprintf(stderr, "After -c must follow decadic address !\n");
				return 1;
			}
			if (clear > 65535) {
				fprintf(stderr, "Maximum number after -c is 65535!\n");
				return 1;
			}
			continue;
		}
		if (!strcmp(argv[i], "-r")) {
			if (str2int(argv[++i], &run)) {
				fprintf(stderr, "After -r must follow decadic address !\n");
				return 1;
			}
			if (run > 65535) {
				fprintf(stderr, "Maximum number after -r is 65535!\n");
				return 1;
			}
			continue;
		}
		if (!strcmp(argv[i], "-cb")) {
			if (str2int(argv[++i], &cb)) {
				fprintf(stderr, "After -cb must follow decadic address !\n");
				return 1;
			}
			if (cb > 7) {
				fprintf(stderr, "Maximum number after -cb is 7!\n");
				return 1;
			}
			continue;
		}
		if (!strcmp(argv[i], "-cp")) {
			if (str2int(argv[++i], &cp)) {
				fprintf(stderr, "After -cp must follow decadic address !\n");
				return 1;
			}
			if (cp > 65535) {
				fprintf(stderr, "Maximum number after -cp is 7!\n");
				return 1;
			}
			continue;
		}
		if (!strcmp(argv[i], "-ci")) {
			if (str2int(argv[++i], &ci)) {
				fprintf(stderr, "After -ci must follow decadic address !\n");
				return 1;
			}
			if (ci > 65535) {
				fprintf(stderr, "Maximum number after -ci is 7!\n");
				return 1;
			}
			continue;
		}
		if (!strcmp(argv[i], "-d80")) {
			d80 = 1;
			continue;
		}
		if (!strcmp(argv[i], "-append")) {
			append = 1;
			continue;
		}
		if (!strcmp(argv[i], "-hp") || !strcmp(argv[i], "--header-poke")) {
			hp = 1;
			continue;
		}
		if (!strcmp(argv[i], "-soaz") || !strcmp(argv[i], "--soaz")) {
			printf("Yebo!\n");
			return 1;
		}
		if (!finname_i)
			finname_i = i;
		else {
			fprintf(stderr, "Input only one bin. file!\n");
			return 1;
		}
	}

	if (!finname_i) {
		printf("Enter input filename!\nTry `bin2tap --help` for help.\n");
		return 1;
	}

	if (!foutname_i) {
		strncpy(foutname, argv[finname_i], 255-5);
		foutname[254-5] = '\0';
		i = strlen(foutname);
		no = 0;
		i--;
		while ((no < 4) && (i-no > 0)) {
			if (foutname[i-no] == '.') {
				foutname[i-no] = '\0';
				break;
			}
			++no;
		}
		strcat (foutname, ".tap");
	}
	else {
		strncpy(foutname, argv[foutname_i], 254);
		foutname[254] = '\0';
	}

	finput = fopen(argv[finname_i], "rb");
	if (!finput) {
		printf("Input file open failed!\n");
		return 1;
	}

	if (append)
		foutput = fopen(foutname, "ab+");
	else
		foutput = fopen(foutname, "wb+");
	if (!foutput) {
		printf("Output file open failed!\n");
		return 1;
	}

	if (basic) {
		tap_index = 110+d80;
		i = 0;
		while ((*(foutname+i) != '.' && *(foutname+i) != '\0') && i<10) {
			*(tap+tap_index+i) = *(foutname+i);
			i++;
		}
		*(tap+14) = (86+d80+i+19*hp) % 256;
		*(tap+15) = (86+d80+i+19*hp) / 256; 

		tap_index = 0;

		*(tap+tap_index++) = 19;		/* tap lenght */
		*(tap+tap_index++) = 0;
		checksum = *(tap+tap_index++) = 0;	/* 00 - header, FF - data*/
		checksum ^= *(tap+tap_index++) = 0;
		if (d80) {
			for (i = 0; i < 10; i++)
				checksum ^= *(tap+tap_index++) = *(run_name+i);
		}
		else {
			in_name = 1;
			for (i = 0; i < 10; ++i) {			/* filename  */
				if (in_name && (foutname[i] == '.' || foutname[i] == '\0'))
					in_name = 0;
				if (in_name)
					checksum ^= *(tap+tap_index++) = foutname[i];
				else
					checksum ^= *(tap+tap_index++) = ' ';
			}
		}
		checksum ^= *(tap+tap_index++);		/* lenght of data block */
		checksum ^= *(tap+tap_index++);
		checksum ^= *(tap+tap_index++) = 10;	/* param1 - autostart of BASIC */
		checksum ^= *(tap+tap_index++) = 0;
		checksum ^= *(tap+tap_index++) = *(tap+14);	/* param2 - start of variables */
		checksum ^= *(tap+tap_index++) = *(tap+15);
		*(tap+tap_index++) = checksum;

		i = *(tap+15)*256 + *(tap+14) + 2;
		*(tap+tap_index++) = i % 256;
		*(tap+tap_index++) = i / 256;
		checksum = *(tap+tap_index++) = 255;

		l_copy (tap, loader, &tap_index, &checksum, 33);
		loader += 33;
		checksum ^= *(tap+tap_index++) = '0' + cb;
		l_copy (tap, loader, &tap_index, &checksum, 5);
		loader += 5;
		checksum ^= *(tap+tap_index++) = '0' + cp;
		l_copy (tap, loader, &tap_index, &checksum, 5);
		loader += 5;
		checksum ^= *(tap+tap_index++) = '0' + ci;
		l_copy (tap, loader, &tap_index, &checksum, 9);
		loader += 9;
		checksum ^= *(tap+tap_index++) = '0' + clear/10000;
		clear -= 10000 * (clear/10000);
		checksum ^= *(tap+tap_index++) = '0' + clear/1000;
		clear -= 1000 * (clear/1000);
		checksum ^= *(tap+tap_index++) = '0' + clear/100;
		clear -= 100 * (clear/100);
		checksum ^= *(tap+tap_index++) = '0' + clear/10;
		clear -= 10 * (clear/10);
		checksum ^= *(tap+tap_index++) = '0' + clear;
		l_copy (tap, loader, &tap_index, &checksum, 2);
		loader += 2;
		if (hp)
			l_copy (tap, loader, &tap_index, &checksum, 19);
		loader += 19;
		l_copy (tap, loader, &tap_index, &checksum, 5);
		loader += 5;
		checksum ^= *(tap+tap_index-2);
		checksum ^= *(tap+tap_index-3);
		if (d80)
			checksum ^= *(tap+tap_index++) = '*';
		checksum ^= *(tap+tap_index++) = '\"';
		i = 0;
		while (((no = foutname[i]) != '.' && no != '\0') && i<10) {
			checksum ^= *(tap+tap_index++) = no;
			i++;
		}
		checksum ^= *(tap+tap_index-d80-i-4) = (i+d80+5) % 256;	/* dlzka riadku */
		checksum ^= *(tap+tap_index-d80-i-3) = (i+d80+5) / 256;
		l_copy (tap, loader, &tap_index, &checksum, 11);
		loader += 11;
		checksum ^= *(tap+tap_index++) = '0' + run/10000;
		run -= 10000 * (run/10000);
		checksum ^= *(tap+tap_index++) = '0' + run/1000;
		run -= 1000 * (run/1000);
		checksum ^= *(tap+tap_index++) = '0' + run/100;
		run -= 100 * (run/100);
		checksum ^= *(tap+tap_index++) = '0' + run/10;
		run -= 10 * (run/10);
		checksum ^= *(tap+tap_index++) = '0' + run;
		l_copy (tap, loader, &tap_index, &checksum, 2);
		loader += 2;
		*(tap+tap_index++) = checksum;
	}
	*(tap+tap_index++) = 19;	/* bytes header len */
	*(tap+tap_index++) = 0;
	*(tap+tap_index++) = 0;		/* header */
	checksum = *(tap+tap_index++) = 3;		/* bytes file */
	in_name = 1;
	for (i = 0; i < 10; ++i) {	/* filename  */
		if (in_name && (foutname[i] == '.' || foutname[i] == '\0'))
			in_name = 0;
		if (in_name)
			checksum ^= *(tap+tap_index++) = foutname[i];
		else
			checksum ^= *(tap+tap_index++) = ' ';
	}
	inputlen = fread (tap+tap_index+10, 1, 49152, finput);
	if (!feof(finput))
		printf("Warning: File exceed 49151 limit!\n");
	checksum ^= *(tap+tap_index++) = inputlen % 256;
	checksum ^= *(tap+tap_index++) = inputlen / 256;
	checksum ^= *(tap+tap_index++) = address % 256;
	checksum ^= *(tap+tap_index++) = address / 256;
	checksum ^= *(tap+tap_index++) = 0;
	checksum ^= *(tap+tap_index++) = 32768 / 256;
	*(tap+tap_index++) = checksum;

	*(tap+tap_index++) = (inputlen + 2) % 256;
	*(tap+tap_index++) = (inputlen + 2) / 256;
	checksum = *(tap+tap_index++) = 255;
	for (i = 0; i < inputlen; i++)
		checksum ^= *(tap+tap_index++);
	*(tap+tap_index++) = checksum;

	inputlen = fwrite(tap, 1, tap_index, foutput);
	if (ferror(foutput)) {
		printf("Error in save file!\n");
		return 1;
	}
	fclose(finput);
	fclose(foutput);
	return 0;
}
