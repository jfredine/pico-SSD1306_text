#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

class SSD1306_text {
 public:
    SSD1306_text(uint height=64, uint width=128,
                 uint i2c_addr=0x3c, i2c_inst_t *i2c=i2c_default,
                 uint sda=PICO_DEFAULT_I2C_SDA_PIN,
                 uint scl=PICO_DEFAULT_I2C_SCL_PIN,
                 uint i2c_frequency=400000);

    void clear(void);
    void clear_line(uint row);
    void position(uint row, uint col);
    void write_string(const char *str);
    void update(void);
 private:
    void write_cmds(const uint8_t *cmds, uint len);
    void write_data(const uint8_t *data, uint len);

    typedef struct cursor_pos_s {
        uint row;
        uint col;
    } cursor_pos_t;
    cursor_pos_t cursor_pos_;

    static const uint8_t font_[][8];
    uint height_;
    uint width_;
    uint i2c_addr_;
    i2c_inst_t *i2c_;
    uint8_t *buffer_;
    uint buffer_size_;

    enum SSD1306_commands {
        // Fundamentals
        SET_CONTRAST    = 0x81,
        DISP_ON_USE_RAM = 0xA4,
        DISP_ON_NO_RAM  = 0xA5,
        DISP_NORMAL     = 0xA6,
        DISP_INVERT     = 0xA7,
        DISP_SLEEP      = 0xAE,
        DISP_WAKE       = 0xAF,

        // Scrolling
        CONT_H_SCROLL_R   = 0x26,
        CONT_H_SCROLL_L   = 0x27,
        CONT_HV_SCROLL_R  = 0x29,
        CONT_HV_SCROLL_L  = 0x2A,
        DISABLE_SCROLL    = 0x2E,
        ENABLE_SCROLL     = 0x2F,
        SET_V_SCROLL_AREA = 0xA3,

        // Addressing
        SET_LO_COL_ADDR     = 0x00,  // Low nibble defines low
        SET_HI_COL_ADDR     = 0x10,  // Low nibble defines high
        SET_MEM_MODE        = 0x20,
        SET_LO_HI_COL_ADDR  = 0x21,
        SET_LO_HI_PAGE_ADDR = 0x22,
        SET_PAGE_ADDR       = 0xB0,  // Low nibble defines page

        // Hardware configuration
        SET_DISP_START       = 0x40,  // Low six bits define start
        SET_SEG_MAP_NORMAL   = 0xA0,
        SET_SEG_MAP_REVERSE  = 0xA1,
        SET_MUX_RATIO        = 0xA8,
        SET_COM_SCAN_NORMAL  = 0xC0,
        SET_COM_SCAN_REVERSE = 0xC8,
        SET_DISP_OFFSET      = 0xD3,
        SET_COM_HW_CFG       = 0xDA,
        SET_CHARGE_PUMP      = 0x8D,

        // Timing and driving
        SET_CLK   = 0xD5,
        SET_PRE   = 0xD9,
        SET_VCOMH = 0xDB,

        NOP       = 0xE3
    };
};
