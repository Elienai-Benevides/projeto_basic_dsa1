#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int main() {
	menu *m = create_Menu(2);
	executar(m);
	destroy_Menu(&m);
return 0;
}
