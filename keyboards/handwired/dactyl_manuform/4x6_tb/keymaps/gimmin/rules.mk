# MCU name: Elite-C controller. Use dfu not avrdude for flashing.
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = qmk-dfu # For Elite-C

# Pointing Device (trackball sensor)
POINTING_DEVICE_DRIVER = pmw3389
PMW3389_CS_PIN = F7

RGB_MATRIX_ENABLE = no

LAYOUTS = split_4x6_tb

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

LTO_ENABLE = yes

TAP_DANCE_ENABLE = yes

DYNAMIC_TAPPING_TERM_ENABLE = no
