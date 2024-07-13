#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "SSD1306_text.h"

int main(int argc, char *argv[]) {

    bi_decl(bi_program_description("Drive SSD1306 based LCD"));
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));
    stdio_init_all();

    SSD1306_text display;

    display.clear();
    display.set_cursor(2, 0);
    display.write_string("Hello World!");
    while (1) {
    }

    return 0;
}
