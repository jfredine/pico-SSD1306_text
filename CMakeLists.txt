add_library(SSD1306_text INTERFACE)
target_sources(SSD1306_text INTERFACE SSD1306_text.cc)
target_include_directories(SSD1306_text INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(SSD1306_text INTERFACE pico_stdlib hardware_i2c)
