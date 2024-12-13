#include <cassert>
#include "add.h"

int main() {
    assert(add(1, 2) == 3);
    assert(add(2, 3) != 3);

    return 0;
}
