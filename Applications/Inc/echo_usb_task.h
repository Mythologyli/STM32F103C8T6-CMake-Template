#ifndef STM32F103C8T6_CMAKE_TEMPLATE_ECHO_USB_TASK_H
#define STM32F103C8T6_CMAKE_TEMPLATE_ECHO_USB_TASK_H

void StartEchoUsbTask(void *argument);

void UsbReceiveCallback(uint8_t *data_buffer, uint32_t length);

#endif //STM32F103C8T6_CMAKE_TEMPLATE_ECHO_USB_TASK_H
