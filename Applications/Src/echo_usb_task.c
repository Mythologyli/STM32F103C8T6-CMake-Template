#include "main.h"
#include "usbd_cdc_if.h"

void StartEchoUsbTask(void *argument)
{
    for (;;)
    {
        Led0_Off; // Keep off when waiting for data.

        osDelay(1);
    }
}

void UsbReceiveCallback(uint8_t *data_buffer, uint32_t length)
{
    Led0_Toggle; // LED blinking.

    CDC_Transmit_FS(data_buffer, length);
}
