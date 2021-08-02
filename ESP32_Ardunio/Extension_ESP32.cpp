#include <Extension_ESP32.h>

void Extension_ESP32::printCurrentDetails() {
    uint64_t EFuseMACID = ESP.getEfuseMac();
    uint8_t EFuseMACIDSplit[6];
    EFuseMACIDSplit[0] = 0xFF & EFuseMACID;
    for (uint8_t i = 1; i < 6; i++) {
        EFuseMACIDSplit[i] = 0xFF & (EFuseMACID >> (8 * i));
    }

    uint8_t chipRevision    = ESP.getChipRevision();
    uint32_t cpuFrquencyMHz = ESP.getCpuFreqMHz();
    uint32_t cycleCount     = ESP.getCycleCount();
    const char *sdkVersion  = ESP.getSdkVersion();

    uint32_t flashChipSize    = ESP.getFlashChipSize();
    uint32_t flashChipSpeed   = ESP.getFlashChipSpeed();
    FlashMode_t flashChipMode = ESP.getFlashChipMode();

    uint32_t psramSize                   = ESP.getPsramSize();
    uint32_t freePSRAMSize               = ESP.getFreePsram();
    uint32_t minimumFreePSRAMSize        = ESP.getMinFreePsram();
    uint32_t maximumAllocatablePSRAMSize = ESP.getMaxAllocPsram();

    uint32_t heapSize                   = ESP.getHeapSize();
    uint32_t freeHeapSize               = ESP.getFreeHeap();
    uint32_t minimumFreeHeapSize        = ESP.getMinFreeHeap();
    uint32_t maximumAllocatableHeapSize = ESP.getMaxAllocHeap();

    uint32_t sketchSize      = ESP.getSketchSize();
    uint32_t freeSketchSpace = ESP.getFreeSketchSpace();
    String sketchMD5         = ESP.getSketchMD5();

    Serial.printf("\n============================================================\n");
    Serial.printf("EFuse MAC:\t%02X:%02X:%02X:%02X:%02X:%02X\n",
                  EFuseMACIDSplit[0], EFuseMACIDSplit[1],
                  EFuseMACIDSplit[2], EFuseMACIDSplit[3],
                  EFuseMACIDSplit[4], EFuseMACIDSplit[5]);

    Serial.printf("============================================================\n");
    Serial.printf("CHIP INFORMATION\n");
    Serial.printf("Chip Revision:\t%d\n", chipRevision);
    Serial.printf("CPU Frequency:\t%d MHz\n", cpuFrquencyMHz);
    Serial.printf("Cycle Count:\t%d\n", cycleCount);
    Serial.printf("SDK Version:\t%s\n", sdkVersion);

    Serial.printf("============================================================\n");
    Serial.printf("FLASH CHIP INFORMATION\n");
    Serial.printf("Flash Chip Size:\t\t%d bytes = %f MB\n", flashChipSize, (float(flashChipSize) / (1024.0 * 1024.0)));
    Serial.printf("Flash Chip Speed:\t%f MHz\n", (float(flashChipSpeed) / (1000 * 1000)));
    Serial.printf("Flash Chip Mode:\t\t%d\n", flashChipMode);

    Serial.printf("============================================================\n");
    Serial.printf("PSRAM INFORMATION\n");
    Serial.printf("PSRAM Size:\t\t\t%d bytes\n", psramSize);
    Serial.printf("Free PSRAM Size:\t\t\t%d bytes\n", freePSRAMSize);
    Serial.printf("Minimum Free PSRAM Size:\t\t%d bytes\n", minimumFreePSRAMSize);
    Serial.printf("Maximum Allocatable PSRAM Size:\t%d bytes\n", maximumAllocatablePSRAMSize);

    Serial.printf("============================================================\n");
    Serial.printf("HEAP INFORMATION\n");
    Serial.printf("Heap Size:\t\t\t%d bytes\n", heapSize);
    Serial.printf("Free Heap Size:\t\t\t%d bytes\n", freeHeapSize);
    Serial.printf("Minimum Free Heap Size:\t\t%d bytes\n", minimumFreeHeapSize);
    Serial.printf("Maximum Allocatable Heap Size:\t%d bytes\n", maximumAllocatableHeapSize);

    Serial.printf("============================================================\n");
    Serial.printf("SKETCH INFORMATION\n");
    Serial.printf("Sketch Size:\t\t%d bytes\t = %f MB\n", sketchSize, (float(sketchSize) / (1024.0 * 1024.0)));
    Serial.printf("Free Sketch Size:\t%d bytes\t = %f MB\n", freeSketchSpace, (float(freeSketchSpace) / (1024.0 * 1024.0)));
    Serial.printf("Sketch MD5:\t\t%s\n", sketchMD5.c_str());
}