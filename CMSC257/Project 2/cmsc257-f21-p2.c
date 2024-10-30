#include <stdio.h>
#include <stdlib.h>
#include "p2-support.h"

int main(){
        struct Mailbox* ib;
        ib = (struct Mailbox*) malloc(sizeof(struct Mailbox));
        initialize(ib);
        display_inbox_menu(ib);
        free (ib);
        return 0;
}

