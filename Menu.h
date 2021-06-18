#pragma once

typedef enum{M_INT, M_TEXT, M_SUBMENU}MenuType;
typedef enum{E_DEFAULT, E_HIGHLIGHT, E_DISABLED}LabelType;
typedef struct Menu{
	MenuType type;
	struct{
		char text[64];
		Color color;
		uint size;
		LabelType type;
	}label;
	union{
		struct{
			uint numItem;
			struct Menu *item;
		};
		struct{
			Range range;
			int val;
		}mint;
		struct{
			char text[64];
		}mtext;
	};
}Menu;

Menu* menuLoadFile(const char *menuFile)
{
	char buf[256] = {0};
	sprintf(buf, "./Menu/%s", menuFile);
	// char* raw = fileReadText(buf);
	// const uint rawlen = strlen(raw);

	return NULL;
}
