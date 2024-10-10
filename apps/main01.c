#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int main() {
	menu *m = create_Menu();
	executar(m);
	destroy_Menu(&m);
return 0;
}
