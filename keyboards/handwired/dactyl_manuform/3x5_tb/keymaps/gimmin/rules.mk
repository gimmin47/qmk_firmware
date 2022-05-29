# MCU name: Elite-C controller. Use dfu not avrdude for flashing.
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = qmk-dfu # For Elite-C

# Pointing Device (trackball sensor)
POINTING_DEVICE_DRIVER = pmw3389

RGB_MATRIX_ENABLE = no

LAYOUTS = split_3x5_tb

OLED_ENABLE = no

LTO_ENABLE = yes

TAP_DANCE_ENABLE = no

DYNAMIC_TAPPING_TERM_ENABLE = no
