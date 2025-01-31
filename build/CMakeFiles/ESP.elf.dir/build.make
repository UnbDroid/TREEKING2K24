# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arthur/Projects/DROID/TREKKING-2024-2025

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arthur/Projects/DROID/TREKKING-2024-2025/build

# Include any dependencies generated for this target.
include CMakeFiles/ESP.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ESP.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ESP.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ESP.elf.dir/flags.make

project_elf_src_esp32.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/arthur/Projects/DROID/TREKKING-2024-2025/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating project_elf_src_esp32.c"
	/usr/bin/cmake -E touch /home/arthur/Projects/DROID/TREKKING-2024-2025/build/project_elf_src_esp32.c

CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.obj: CMakeFiles/ESP.elf.dir/flags.make
CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.obj: project_elf_src_esp32.c
CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.obj: CMakeFiles/ESP.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/arthur/Projects/DROID/TREKKING-2024-2025/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.obj"
	/home/arthur/.espressif/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.obj -MF CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.obj.d -o CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.obj -c /home/arthur/Projects/DROID/TREKKING-2024-2025/build/project_elf_src_esp32.c

CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.i"
	/home/arthur/.espressif/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/arthur/Projects/DROID/TREKKING-2024-2025/build/project_elf_src_esp32.c > CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.i

CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.s"
	/home/arthur/.espressif/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/arthur/Projects/DROID/TREKKING-2024-2025/build/project_elf_src_esp32.c -o CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.s

# Object files for target ESP.elf
ESP_elf_OBJECTS = \
"CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.obj"

# External object files for target ESP.elf
ESP_elf_EXTERNAL_OBJECTS =

ESP.elf: CMakeFiles/ESP.elf.dir/project_elf_src_esp32.c.obj
ESP.elf: CMakeFiles/ESP.elf.dir/build.make
ESP.elf: esp-idf/xtensa/libxtensa.a
ESP.elf: esp-idf/esp_driver_gpio/libesp_driver_gpio.a
ESP.elf: esp-idf/esp_pm/libesp_pm.a
ESP.elf: esp-idf/mbedtls/libmbedtls.a
ESP.elf: esp-idf/esp_app_format/libesp_app_format.a
ESP.elf: esp-idf/esp_bootloader_format/libesp_bootloader_format.a
ESP.elf: esp-idf/app_update/libapp_update.a
ESP.elf: esp-idf/esp_partition/libesp_partition.a
ESP.elf: esp-idf/efuse/libefuse.a
ESP.elf: esp-idf/bootloader_support/libbootloader_support.a
ESP.elf: esp-idf/esp_mm/libesp_mm.a
ESP.elf: esp-idf/spi_flash/libspi_flash.a
ESP.elf: esp-idf/esp_system/libesp_system.a
ESP.elf: esp-idf/esp_common/libesp_common.a
ESP.elf: esp-idf/esp_rom/libesp_rom.a
ESP.elf: esp-idf/hal/libhal.a
ESP.elf: esp-idf/log/liblog.a
ESP.elf: esp-idf/heap/libheap.a
ESP.elf: esp-idf/soc/libsoc.a
ESP.elf: esp-idf/esp_security/libesp_security.a
ESP.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ESP.elf: esp-idf/freertos/libfreertos.a
ESP.elf: esp-idf/newlib/libnewlib.a
ESP.elf: esp-idf/pthread/libpthread.a
ESP.elf: esp-idf/cxx/libcxx.a
ESP.elf: esp-idf/esp_timer/libesp_timer.a
ESP.elf: esp-idf/esp_driver_gptimer/libesp_driver_gptimer.a
ESP.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ESP.elf: esp-idf/esp_driver_uart/libesp_driver_uart.a
ESP.elf: esp-idf/app_trace/libapp_trace.a
ESP.elf: esp-idf/esp_event/libesp_event.a
ESP.elf: esp-idf/nvs_flash/libnvs_flash.a
ESP.elf: esp-idf/esp_phy/libesp_phy.a
ESP.elf: esp-idf/esp_vfs_console/libesp_vfs_console.a
ESP.elf: esp-idf/vfs/libvfs.a
ESP.elf: esp-idf/lwip/liblwip.a
ESP.elf: esp-idf/esp_netif/libesp_netif.a
ESP.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ESP.elf: esp-idf/esp_coex/libesp_coex.a
ESP.elf: esp-idf/esp_wifi/libesp_wifi.a
ESP.elf: esp-idf/unity/libunity.a
ESP.elf: esp-idf/cmock/libcmock.a
ESP.elf: esp-idf/console/libconsole.a
ESP.elf: esp-idf/esp_driver_pcnt/libesp_driver_pcnt.a
ESP.elf: esp-idf/esp_driver_spi/libesp_driver_spi.a
ESP.elf: esp-idf/esp_driver_mcpwm/libesp_driver_mcpwm.a
ESP.elf: esp-idf/esp_driver_i2s/libesp_driver_i2s.a
ESP.elf: esp-idf/sdmmc/libsdmmc.a
ESP.elf: esp-idf/esp_driver_sdmmc/libesp_driver_sdmmc.a
ESP.elf: esp-idf/esp_driver_sdspi/libesp_driver_sdspi.a
ESP.elf: esp-idf/esp_driver_sdio/libesp_driver_sdio.a
ESP.elf: esp-idf/esp_driver_dac/libesp_driver_dac.a
ESP.elf: esp-idf/esp_driver_rmt/libesp_driver_rmt.a
ESP.elf: esp-idf/esp_driver_sdm/libesp_driver_sdm.a
ESP.elf: esp-idf/esp_driver_i2c/libesp_driver_i2c.a
ESP.elf: esp-idf/esp_driver_ledc/libesp_driver_ledc.a
ESP.elf: esp-idf/driver/libdriver.a
ESP.elf: esp-idf/http_parser/libhttp_parser.a
ESP.elf: esp-idf/esp-tls/libesp-tls.a
ESP.elf: esp-idf/esp_adc/libesp_adc.a
ESP.elf: esp-idf/esp_driver_cam/libesp_driver_cam.a
ESP.elf: esp-idf/esp_driver_touch_sens/libesp_driver_touch_sens.a
ESP.elf: esp-idf/esp_eth/libesp_eth.a
ESP.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
ESP.elf: esp-idf/esp_hid/libesp_hid.a
ESP.elf: esp-idf/tcp_transport/libtcp_transport.a
ESP.elf: esp-idf/esp_http_client/libesp_http_client.a
ESP.elf: esp-idf/esp_http_server/libesp_http_server.a
ESP.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ESP.elf: esp-idf/esp_https_server/libesp_https_server.a
ESP.elf: esp-idf/esp_lcd/libesp_lcd.a
ESP.elf: esp-idf/protobuf-c/libprotobuf-c.a
ESP.elf: esp-idf/protocomm/libprotocomm.a
ESP.elf: esp-idf/esp_local_ctrl/libesp_local_ctrl.a
ESP.elf: esp-idf/espcoredump/libespcoredump.a
ESP.elf: esp-idf/wear_levelling/libwear_levelling.a
ESP.elf: esp-idf/fatfs/libfatfs.a
ESP.elf: esp-idf/json/libjson.a
ESP.elf: esp-idf/mqtt/libmqtt.a
ESP.elf: esp-idf/nvs_sec_provider/libnvs_sec_provider.a
ESP.elf: esp-idf/perfmon/libperfmon.a
ESP.elf: esp-idf/rt/librt.a
ESP.elf: esp-idf/spiffs/libspiffs.a
ESP.elf: esp-idf/wifi_provisioning/libwifi_provisioning.a
ESP.elf: esp-idf/main/libmain.a
ESP.elf: esp-idf/MotorDC/libMotorDC.a
ESP.elf: esp-idf/PinConfig/libPinConfig.a
ESP.elf: esp-idf/app_trace/libapp_trace.a
ESP.elf: esp-idf/app_trace/libapp_trace.a
ESP.elf: esp-idf/cmock/libcmock.a
ESP.elf: esp-idf/unity/libunity.a
ESP.elf: esp-idf/esp_driver_cam/libesp_driver_cam.a
ESP.elf: esp-idf/esp_driver_touch_sens/libesp_driver_touch_sens.a
ESP.elf: esp-idf/esp_eth/libesp_eth.a
ESP.elf: esp-idf/esp_hid/libesp_hid.a
ESP.elf: esp-idf/esp_lcd/libesp_lcd.a
ESP.elf: esp-idf/esp_local_ctrl/libesp_local_ctrl.a
ESP.elf: esp-idf/esp_https_server/libesp_https_server.a
ESP.elf: esp-idf/espcoredump/libespcoredump.a
ESP.elf: esp-idf/fatfs/libfatfs.a
ESP.elf: esp-idf/wear_levelling/libwear_levelling.a
ESP.elf: esp-idf/mqtt/libmqtt.a
ESP.elf: esp-idf/nvs_sec_provider/libnvs_sec_provider.a
ESP.elf: esp-idf/perfmon/libperfmon.a
ESP.elf: esp-idf/rt/librt.a
ESP.elf: esp-idf/spiffs/libspiffs.a
ESP.elf: esp-idf/wifi_provisioning/libwifi_provisioning.a
ESP.elf: esp-idf/protocomm/libprotocomm.a
ESP.elf: esp-idf/console/libconsole.a
ESP.elf: esp-idf/protobuf-c/libprotobuf-c.a
ESP.elf: esp-idf/json/libjson.a
ESP.elf: esp-idf/xtensa/libxtensa.a
ESP.elf: esp-idf/esp_driver_gpio/libesp_driver_gpio.a
ESP.elf: esp-idf/esp_pm/libesp_pm.a
ESP.elf: esp-idf/mbedtls/libmbedtls.a
ESP.elf: esp-idf/esp_app_format/libesp_app_format.a
ESP.elf: esp-idf/esp_bootloader_format/libesp_bootloader_format.a
ESP.elf: esp-idf/app_update/libapp_update.a
ESP.elf: esp-idf/esp_partition/libesp_partition.a
ESP.elf: esp-idf/efuse/libefuse.a
ESP.elf: esp-idf/bootloader_support/libbootloader_support.a
ESP.elf: esp-idf/esp_mm/libesp_mm.a
ESP.elf: esp-idf/spi_flash/libspi_flash.a
ESP.elf: esp-idf/esp_system/libesp_system.a
ESP.elf: esp-idf/esp_common/libesp_common.a
ESP.elf: esp-idf/esp_rom/libesp_rom.a
ESP.elf: esp-idf/hal/libhal.a
ESP.elf: esp-idf/log/liblog.a
ESP.elf: esp-idf/heap/libheap.a
ESP.elf: esp-idf/soc/libsoc.a
ESP.elf: esp-idf/esp_security/libesp_security.a
ESP.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ESP.elf: esp-idf/freertos/libfreertos.a
ESP.elf: esp-idf/newlib/libnewlib.a
ESP.elf: esp-idf/pthread/libpthread.a
ESP.elf: esp-idf/cxx/libcxx.a
ESP.elf: esp-idf/esp_timer/libesp_timer.a
ESP.elf: esp-idf/esp_driver_gptimer/libesp_driver_gptimer.a
ESP.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ESP.elf: esp-idf/esp_driver_uart/libesp_driver_uart.a
ESP.elf: esp-idf/esp_event/libesp_event.a
ESP.elf: esp-idf/nvs_flash/libnvs_flash.a
ESP.elf: esp-idf/esp_phy/libesp_phy.a
ESP.elf: esp-idf/esp_vfs_console/libesp_vfs_console.a
ESP.elf: esp-idf/vfs/libvfs.a
ESP.elf: esp-idf/lwip/liblwip.a
ESP.elf: esp-idf/esp_netif/libesp_netif.a
ESP.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ESP.elf: esp-idf/esp_coex/libesp_coex.a
ESP.elf: esp-idf/esp_wifi/libesp_wifi.a
ESP.elf: esp-idf/esp_driver_pcnt/libesp_driver_pcnt.a
ESP.elf: esp-idf/esp_driver_spi/libesp_driver_spi.a
ESP.elf: esp-idf/esp_driver_mcpwm/libesp_driver_mcpwm.a
ESP.elf: esp-idf/esp_driver_i2s/libesp_driver_i2s.a
ESP.elf: esp-idf/sdmmc/libsdmmc.a
ESP.elf: esp-idf/esp_driver_sdmmc/libesp_driver_sdmmc.a
ESP.elf: esp-idf/esp_driver_sdspi/libesp_driver_sdspi.a
ESP.elf: esp-idf/esp_driver_sdio/libesp_driver_sdio.a
ESP.elf: esp-idf/esp_driver_dac/libesp_driver_dac.a
ESP.elf: esp-idf/esp_driver_rmt/libesp_driver_rmt.a
ESP.elf: esp-idf/esp_driver_sdm/libesp_driver_sdm.a
ESP.elf: esp-idf/esp_driver_i2c/libesp_driver_i2c.a
ESP.elf: esp-idf/esp_driver_ledc/libesp_driver_ledc.a
ESP.elf: esp-idf/driver/libdriver.a
ESP.elf: esp-idf/http_parser/libhttp_parser.a
ESP.elf: esp-idf/esp-tls/libesp-tls.a
ESP.elf: esp-idf/esp_adc/libesp_adc.a
ESP.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
ESP.elf: esp-idf/tcp_transport/libtcp_transport.a
ESP.elf: esp-idf/esp_http_client/libesp_http_client.a
ESP.elf: esp-idf/esp_http_server/libesp_http_server.a
ESP.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
ESP.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
ESP.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
ESP.elf: esp-idf/xtensa/libxtensa.a
ESP.elf: esp-idf/esp_driver_gpio/libesp_driver_gpio.a
ESP.elf: esp-idf/esp_pm/libesp_pm.a
ESP.elf: esp-idf/mbedtls/libmbedtls.a
ESP.elf: esp-idf/esp_app_format/libesp_app_format.a
ESP.elf: esp-idf/esp_bootloader_format/libesp_bootloader_format.a
ESP.elf: esp-idf/app_update/libapp_update.a
ESP.elf: esp-idf/esp_partition/libesp_partition.a
ESP.elf: esp-idf/efuse/libefuse.a
ESP.elf: esp-idf/bootloader_support/libbootloader_support.a
ESP.elf: esp-idf/esp_mm/libesp_mm.a
ESP.elf: esp-idf/spi_flash/libspi_flash.a
ESP.elf: esp-idf/esp_system/libesp_system.a
ESP.elf: esp-idf/esp_common/libesp_common.a
ESP.elf: esp-idf/esp_rom/libesp_rom.a
ESP.elf: esp-idf/hal/libhal.a
ESP.elf: esp-idf/log/liblog.a
ESP.elf: esp-idf/heap/libheap.a
ESP.elf: esp-idf/soc/libsoc.a
ESP.elf: esp-idf/esp_security/libesp_security.a
ESP.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ESP.elf: esp-idf/freertos/libfreertos.a
ESP.elf: esp-idf/newlib/libnewlib.a
ESP.elf: esp-idf/pthread/libpthread.a
ESP.elf: esp-idf/cxx/libcxx.a
ESP.elf: esp-idf/esp_timer/libesp_timer.a
ESP.elf: esp-idf/esp_driver_gptimer/libesp_driver_gptimer.a
ESP.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ESP.elf: esp-idf/esp_driver_uart/libesp_driver_uart.a
ESP.elf: esp-idf/esp_event/libesp_event.a
ESP.elf: esp-idf/nvs_flash/libnvs_flash.a
ESP.elf: esp-idf/esp_phy/libesp_phy.a
ESP.elf: esp-idf/esp_vfs_console/libesp_vfs_console.a
ESP.elf: esp-idf/vfs/libvfs.a
ESP.elf: esp-idf/lwip/liblwip.a
ESP.elf: esp-idf/esp_netif/libesp_netif.a
ESP.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ESP.elf: esp-idf/esp_coex/libesp_coex.a
ESP.elf: esp-idf/esp_wifi/libesp_wifi.a
ESP.elf: esp-idf/esp_driver_pcnt/libesp_driver_pcnt.a
ESP.elf: esp-idf/esp_driver_spi/libesp_driver_spi.a
ESP.elf: esp-idf/esp_driver_mcpwm/libesp_driver_mcpwm.a
ESP.elf: esp-idf/esp_driver_i2s/libesp_driver_i2s.a
ESP.elf: esp-idf/sdmmc/libsdmmc.a
ESP.elf: esp-idf/esp_driver_sdmmc/libesp_driver_sdmmc.a
ESP.elf: esp-idf/esp_driver_sdspi/libesp_driver_sdspi.a
ESP.elf: esp-idf/esp_driver_sdio/libesp_driver_sdio.a
ESP.elf: esp-idf/esp_driver_dac/libesp_driver_dac.a
ESP.elf: esp-idf/esp_driver_rmt/libesp_driver_rmt.a
ESP.elf: esp-idf/esp_driver_sdm/libesp_driver_sdm.a
ESP.elf: esp-idf/esp_driver_i2c/libesp_driver_i2c.a
ESP.elf: esp-idf/esp_driver_ledc/libesp_driver_ledc.a
ESP.elf: esp-idf/driver/libdriver.a
ESP.elf: esp-idf/http_parser/libhttp_parser.a
ESP.elf: esp-idf/esp-tls/libesp-tls.a
ESP.elf: esp-idf/esp_adc/libesp_adc.a
ESP.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
ESP.elf: esp-idf/tcp_transport/libtcp_transport.a
ESP.elf: esp-idf/esp_http_client/libesp_http_client.a
ESP.elf: esp-idf/esp_http_server/libesp_http_server.a
ESP.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
ESP.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
ESP.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
ESP.elf: esp-idf/xtensa/libxtensa.a
ESP.elf: esp-idf/esp_driver_gpio/libesp_driver_gpio.a
ESP.elf: esp-idf/esp_pm/libesp_pm.a
ESP.elf: esp-idf/mbedtls/libmbedtls.a
ESP.elf: esp-idf/esp_app_format/libesp_app_format.a
ESP.elf: esp-idf/esp_bootloader_format/libesp_bootloader_format.a
ESP.elf: esp-idf/app_update/libapp_update.a
ESP.elf: esp-idf/esp_partition/libesp_partition.a
ESP.elf: esp-idf/efuse/libefuse.a
ESP.elf: esp-idf/bootloader_support/libbootloader_support.a
ESP.elf: esp-idf/esp_mm/libesp_mm.a
ESP.elf: esp-idf/spi_flash/libspi_flash.a
ESP.elf: esp-idf/esp_system/libesp_system.a
ESP.elf: esp-idf/esp_common/libesp_common.a
ESP.elf: esp-idf/esp_rom/libesp_rom.a
ESP.elf: esp-idf/hal/libhal.a
ESP.elf: esp-idf/log/liblog.a
ESP.elf: esp-idf/heap/libheap.a
ESP.elf: esp-idf/soc/libsoc.a
ESP.elf: esp-idf/esp_security/libesp_security.a
ESP.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ESP.elf: esp-idf/freertos/libfreertos.a
ESP.elf: esp-idf/newlib/libnewlib.a
ESP.elf: esp-idf/pthread/libpthread.a
ESP.elf: esp-idf/cxx/libcxx.a
ESP.elf: esp-idf/esp_timer/libesp_timer.a
ESP.elf: esp-idf/esp_driver_gptimer/libesp_driver_gptimer.a
ESP.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ESP.elf: esp-idf/esp_driver_uart/libesp_driver_uart.a
ESP.elf: esp-idf/esp_event/libesp_event.a
ESP.elf: esp-idf/nvs_flash/libnvs_flash.a
ESP.elf: esp-idf/esp_phy/libesp_phy.a
ESP.elf: esp-idf/esp_vfs_console/libesp_vfs_console.a
ESP.elf: esp-idf/vfs/libvfs.a
ESP.elf: esp-idf/lwip/liblwip.a
ESP.elf: esp-idf/esp_netif/libesp_netif.a
ESP.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ESP.elf: esp-idf/esp_coex/libesp_coex.a
ESP.elf: esp-idf/esp_wifi/libesp_wifi.a
ESP.elf: esp-idf/esp_driver_pcnt/libesp_driver_pcnt.a
ESP.elf: esp-idf/esp_driver_spi/libesp_driver_spi.a
ESP.elf: esp-idf/esp_driver_mcpwm/libesp_driver_mcpwm.a
ESP.elf: esp-idf/esp_driver_i2s/libesp_driver_i2s.a
ESP.elf: esp-idf/sdmmc/libsdmmc.a
ESP.elf: esp-idf/esp_driver_sdmmc/libesp_driver_sdmmc.a
ESP.elf: esp-idf/esp_driver_sdspi/libesp_driver_sdspi.a
ESP.elf: esp-idf/esp_driver_sdio/libesp_driver_sdio.a
ESP.elf: esp-idf/esp_driver_dac/libesp_driver_dac.a
ESP.elf: esp-idf/esp_driver_rmt/libesp_driver_rmt.a
ESP.elf: esp-idf/esp_driver_sdm/libesp_driver_sdm.a
ESP.elf: esp-idf/esp_driver_i2c/libesp_driver_i2c.a
ESP.elf: esp-idf/esp_driver_ledc/libesp_driver_ledc.a
ESP.elf: esp-idf/driver/libdriver.a
ESP.elf: esp-idf/http_parser/libhttp_parser.a
ESP.elf: esp-idf/esp-tls/libesp-tls.a
ESP.elf: esp-idf/esp_adc/libesp_adc.a
ESP.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
ESP.elf: esp-idf/tcp_transport/libtcp_transport.a
ESP.elf: esp-idf/esp_http_client/libesp_http_client.a
ESP.elf: esp-idf/esp_http_server/libesp_http_server.a
ESP.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
ESP.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
ESP.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
ESP.elf: esp-idf/xtensa/libxtensa.a
ESP.elf: esp-idf/esp_driver_gpio/libesp_driver_gpio.a
ESP.elf: esp-idf/esp_pm/libesp_pm.a
ESP.elf: esp-idf/mbedtls/libmbedtls.a
ESP.elf: esp-idf/esp_app_format/libesp_app_format.a
ESP.elf: esp-idf/esp_bootloader_format/libesp_bootloader_format.a
ESP.elf: esp-idf/app_update/libapp_update.a
ESP.elf: esp-idf/esp_partition/libesp_partition.a
ESP.elf: esp-idf/efuse/libefuse.a
ESP.elf: esp-idf/bootloader_support/libbootloader_support.a
ESP.elf: esp-idf/esp_mm/libesp_mm.a
ESP.elf: esp-idf/spi_flash/libspi_flash.a
ESP.elf: esp-idf/esp_system/libesp_system.a
ESP.elf: esp-idf/esp_common/libesp_common.a
ESP.elf: esp-idf/esp_rom/libesp_rom.a
ESP.elf: esp-idf/hal/libhal.a
ESP.elf: esp-idf/log/liblog.a
ESP.elf: esp-idf/heap/libheap.a
ESP.elf: esp-idf/soc/libsoc.a
ESP.elf: esp-idf/esp_security/libesp_security.a
ESP.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ESP.elf: esp-idf/freertos/libfreertos.a
ESP.elf: esp-idf/newlib/libnewlib.a
ESP.elf: esp-idf/pthread/libpthread.a
ESP.elf: esp-idf/cxx/libcxx.a
ESP.elf: esp-idf/esp_timer/libesp_timer.a
ESP.elf: esp-idf/esp_driver_gptimer/libesp_driver_gptimer.a
ESP.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ESP.elf: esp-idf/esp_driver_uart/libesp_driver_uart.a
ESP.elf: esp-idf/esp_event/libesp_event.a
ESP.elf: esp-idf/nvs_flash/libnvs_flash.a
ESP.elf: esp-idf/esp_phy/libesp_phy.a
ESP.elf: esp-idf/esp_vfs_console/libesp_vfs_console.a
ESP.elf: esp-idf/vfs/libvfs.a
ESP.elf: esp-idf/lwip/liblwip.a
ESP.elf: esp-idf/esp_netif/libesp_netif.a
ESP.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ESP.elf: esp-idf/esp_coex/libesp_coex.a
ESP.elf: esp-idf/esp_wifi/libesp_wifi.a
ESP.elf: esp-idf/esp_driver_pcnt/libesp_driver_pcnt.a
ESP.elf: esp-idf/esp_driver_spi/libesp_driver_spi.a
ESP.elf: esp-idf/esp_driver_mcpwm/libesp_driver_mcpwm.a
ESP.elf: esp-idf/esp_driver_i2s/libesp_driver_i2s.a
ESP.elf: esp-idf/sdmmc/libsdmmc.a
ESP.elf: esp-idf/esp_driver_sdmmc/libesp_driver_sdmmc.a
ESP.elf: esp-idf/esp_driver_sdspi/libesp_driver_sdspi.a
ESP.elf: esp-idf/esp_driver_sdio/libesp_driver_sdio.a
ESP.elf: esp-idf/esp_driver_dac/libesp_driver_dac.a
ESP.elf: esp-idf/esp_driver_rmt/libesp_driver_rmt.a
ESP.elf: esp-idf/esp_driver_sdm/libesp_driver_sdm.a
ESP.elf: esp-idf/esp_driver_i2c/libesp_driver_i2c.a
ESP.elf: esp-idf/esp_driver_ledc/libesp_driver_ledc.a
ESP.elf: esp-idf/driver/libdriver.a
ESP.elf: esp-idf/http_parser/libhttp_parser.a
ESP.elf: esp-idf/esp-tls/libesp-tls.a
ESP.elf: esp-idf/esp_adc/libesp_adc.a
ESP.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
ESP.elf: esp-idf/tcp_transport/libtcp_transport.a
ESP.elf: esp-idf/esp_http_client/libesp_http_client.a
ESP.elf: esp-idf/esp_http_server/libesp_http_server.a
ESP.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
ESP.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
ESP.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
ESP.elf: esp-idf/xtensa/libxtensa.a
ESP.elf: esp-idf/esp_driver_gpio/libesp_driver_gpio.a
ESP.elf: esp-idf/esp_pm/libesp_pm.a
ESP.elf: esp-idf/mbedtls/libmbedtls.a
ESP.elf: esp-idf/esp_app_format/libesp_app_format.a
ESP.elf: esp-idf/esp_bootloader_format/libesp_bootloader_format.a
ESP.elf: esp-idf/app_update/libapp_update.a
ESP.elf: esp-idf/esp_partition/libesp_partition.a
ESP.elf: esp-idf/efuse/libefuse.a
ESP.elf: esp-idf/bootloader_support/libbootloader_support.a
ESP.elf: esp-idf/esp_mm/libesp_mm.a
ESP.elf: esp-idf/spi_flash/libspi_flash.a
ESP.elf: esp-idf/esp_system/libesp_system.a
ESP.elf: esp-idf/esp_common/libesp_common.a
ESP.elf: esp-idf/esp_rom/libesp_rom.a
ESP.elf: esp-idf/hal/libhal.a
ESP.elf: esp-idf/log/liblog.a
ESP.elf: esp-idf/heap/libheap.a
ESP.elf: esp-idf/soc/libsoc.a
ESP.elf: esp-idf/esp_security/libesp_security.a
ESP.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ESP.elf: esp-idf/freertos/libfreertos.a
ESP.elf: esp-idf/newlib/libnewlib.a
ESP.elf: esp-idf/pthread/libpthread.a
ESP.elf: esp-idf/cxx/libcxx.a
ESP.elf: esp-idf/esp_timer/libesp_timer.a
ESP.elf: esp-idf/esp_driver_gptimer/libesp_driver_gptimer.a
ESP.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ESP.elf: esp-idf/esp_driver_uart/libesp_driver_uart.a
ESP.elf: esp-idf/esp_event/libesp_event.a
ESP.elf: esp-idf/nvs_flash/libnvs_flash.a
ESP.elf: esp-idf/esp_phy/libesp_phy.a
ESP.elf: esp-idf/esp_vfs_console/libesp_vfs_console.a
ESP.elf: esp-idf/vfs/libvfs.a
ESP.elf: esp-idf/lwip/liblwip.a
ESP.elf: esp-idf/esp_netif/libesp_netif.a
ESP.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ESP.elf: esp-idf/esp_coex/libesp_coex.a
ESP.elf: esp-idf/esp_wifi/libesp_wifi.a
ESP.elf: esp-idf/esp_driver_pcnt/libesp_driver_pcnt.a
ESP.elf: esp-idf/esp_driver_spi/libesp_driver_spi.a
ESP.elf: esp-idf/esp_driver_mcpwm/libesp_driver_mcpwm.a
ESP.elf: esp-idf/esp_driver_i2s/libesp_driver_i2s.a
ESP.elf: esp-idf/sdmmc/libsdmmc.a
ESP.elf: esp-idf/esp_driver_sdmmc/libesp_driver_sdmmc.a
ESP.elf: esp-idf/esp_driver_sdspi/libesp_driver_sdspi.a
ESP.elf: esp-idf/esp_driver_sdio/libesp_driver_sdio.a
ESP.elf: esp-idf/esp_driver_dac/libesp_driver_dac.a
ESP.elf: esp-idf/esp_driver_rmt/libesp_driver_rmt.a
ESP.elf: esp-idf/esp_driver_sdm/libesp_driver_sdm.a
ESP.elf: esp-idf/esp_driver_i2c/libesp_driver_i2c.a
ESP.elf: esp-idf/esp_driver_ledc/libesp_driver_ledc.a
ESP.elf: esp-idf/driver/libdriver.a
ESP.elf: esp-idf/http_parser/libhttp_parser.a
ESP.elf: esp-idf/esp-tls/libesp-tls.a
ESP.elf: esp-idf/esp_adc/libesp_adc.a
ESP.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
ESP.elf: esp-idf/tcp_transport/libtcp_transport.a
ESP.elf: esp-idf/esp_http_client/libesp_http_client.a
ESP.elf: esp-idf/esp_http_server/libesp_http_server.a
ESP.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
ESP.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
ESP.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
ESP.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
ESP.elf: /home/arthur/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
ESP.elf: /home/arthur/esp/esp-idf/components/xtensa/esp32/libxt_hal.a
ESP.elf: esp-idf/pthread/libpthread.a
ESP.elf: esp-idf/newlib/libnewlib.a
ESP.elf: esp-idf/cxx/libcxx.a
ESP.elf: esp-idf/esp_phy/libesp_phy.a
ESP.elf: esp-idf/esp_phy/libesp_phy.a
ESP.elf: esp-idf/esp_system/ld/memory.ld
ESP.elf: esp-idf/esp_system/ld/sections.ld
ESP.elf: /home/arthur/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.ld
ESP.elf: /home/arthur/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.api.ld
ESP.elf: /home/arthur/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.libgcc.ld
ESP.elf: /home/arthur/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.newlib-data.ld
ESP.elf: /home/arthur/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.syscalls.ld
ESP.elf: /home/arthur/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.libc-funcs.ld
ESP.elf: /home/arthur/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.newlib-reent-funcs.ld
ESP.elf: /home/arthur/esp/esp-idf/components/soc/esp32/ld/esp32.peripherals.ld
ESP.elf: CMakeFiles/ESP.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/arthur/Projects/DROID/TREKKING-2024-2025/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ESP.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ESP.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ESP.elf.dir/build: ESP.elf
.PHONY : CMakeFiles/ESP.elf.dir/build

CMakeFiles/ESP.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ESP.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ESP.elf.dir/clean

CMakeFiles/ESP.elf.dir/depend: project_elf_src_esp32.c
	cd /home/arthur/Projects/DROID/TREKKING-2024-2025/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arthur/Projects/DROID/TREKKING-2024-2025 /home/arthur/Projects/DROID/TREKKING-2024-2025 /home/arthur/Projects/DROID/TREKKING-2024-2025/build /home/arthur/Projects/DROID/TREKKING-2024-2025/build /home/arthur/Projects/DROID/TREKKING-2024-2025/build/CMakeFiles/ESP.elf.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ESP.elf.dir/depend

